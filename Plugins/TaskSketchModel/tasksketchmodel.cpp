#include "tasksketchmodel.h"

TaskSketchModel::TaskSketchModel()
{
    tableName = "itasksketchmodel";
    coreRelationName = "itasksketchmodel";
    activeViewId = -1;
    myModel = NULL;
    dataManager = NULL;
}

TaskSketchModel::~TaskSketchModel()
{
}

void TaskSketchModel::SetPluginInfo(PluginInfo *pluginInfo)
{
    this->pluginInfo = pluginInfo;
}

void TaskSketchModel::OnAllSetup()
{
    if(dataManager == NULL) return;
    QMap<QString, QVariant::Type> newRelationStruct = {
        {"sketch",  QVariant::ByteArray},
    };
    QVector<QVariant> defaultData;
    defaultData << QByteArray();
    dataManager->SetRelation(tableName, coreRelationName, newRelationStruct, defaultData);
    if(myModel != NULL)
        dataManager->SetRelation(myModel->GetDataName(), coreRelationName, newRelationStruct, defaultData);
}

QString TaskSketchModel::GetLastError()
{
    return "";
}

void TaskSketchModel::AddReferencePlugin(PluginInfo *pluginInfo)
{
    switch(pluginInfo->Meta->Type){
        case PLUGINVIEW:{
            viewPlugins.append(pluginInfo);
            qDebug() << "IPluginView succesfully set.";
            connect(pluginInfo->Instance, SIGNAL(OnClose(PluginInfo*)), SLOT(ReferencePluginClosed(PluginInfo*)));
        }break;

        case DATAMANAGER:{
            this->dataManager = qobject_cast<IExtendableDataBaseManager*>(pluginInfo->Instance);
            if(!this->dataManager)
            {
                qDebug() << pluginInfo->Meta->Name << "is not IExtendableDataBaseManagerPlugin.";
                return;
            }
            qDebug() << "IExtendableDataBaseManagerPlugin succesfully set.";
        }break;

        case PLUGINMODEL:{
            myModel = qobject_cast<ITaskTreeModel*>(pluginInfo->Instance);
            if(!myModel){
                qDebug() << pluginInfo->Meta->Name << "is not IExtendableDataBaseManagerPlugin.";
                return;
            }
            qDebug() << "IExtendableDataBaseManagerPlugin succesfully set.";
        }break;

        case ROOTMODEL:{
            pluginInfo->Plugin.model->AddReferencePlugin(this->pluginInfo);
        }break;
    }
}

void TaskSketchModel::ReferencePluginClosed(PluginInfo *pluginInfo)
{
    Close();
}

bool TaskSketchModel::Open(IModelPlugin *parent)
{
    qDebug() << "TaskListModel runs";
    if(viewPlugins.count() == 0){
        qDebug() << "I dont have any views!";
        return false;
    }
    activeViewId = 0;
    SetupModel();
    qDebug() << viewPlugins[activeViewId]->Meta->Name;
    if(!viewPlugins[activeViewId]->Plugin.view->Open(this)){
        qDebug() << "Can't open first view!";
        return false;
    }
    return true;
}

void TaskSketchModel::Close()
{
    activeViewId = -1;
    emit OnClose(pluginInfo);
    emit OnClose();
}

QAbstractItemModel *TaskSketchModel::GetModel()
{
    return taskModel;
}

QAbstractItemModel *TaskSketchModel::GetInternalModel()
{
    return sketchItemModel;
}

void TaskSketchModel::ConvertSketchToTask(int sketchId)
{
    QModelIndex modelIndex;
    QMap<int, QVariant> map;

    modelIndex = sketchItemModel->index(sketchId, 0);
    map = sketchItemModel->itemData(modelIndex);
    qDebug() << map[0];

    taskModel->insertRows(taskModel->rowCount(), 1);
    modelIndex = taskModel->index(taskModel->rowCount()-1, 0);
    dataManager->SetActiveRelation(tableName, coreRelationName);
    taskModel->setData(modelIndex, map[1]);
    qDebug() << map[0];

    //emit ConvertTaskToSketch(map[0].toInt());
}

void TaskSketchModel::SetupModel()
{
    if(!dataManager) return;
    sketchItemModel = dataManager->GetDataModel(tableName);
    if(!myModel) return;
    taskModel = dataManager->GetDataModel(myModel->GetDataName());
}
