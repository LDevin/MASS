#include "extendabletreeitemmodel.h"

ExtendableTreeItemModel::ExtendableTreeItemModel(QString tableName,
                                     IExtendableDataBaseManagerPlugin* dataManager,
                                     QObject *parent)
{
    this->tableName = tableName;
    this->dataManager = dataManager;
    coreRelationName = "tree";
    rootItem = NULL;
}

ExtendableTreeItemModel::~ExtendableTreeItemModel()
{
    delete rootItem;
}

void ExtendableTreeItemModel::LoadData()
{
    qDebug() << "Load data";
    if(rootItem)
        return;

    QMap<QString, QVariant::Type> newRelationStruct = {
        {"parent",      QVariant::Int},
        {"position",    QVariant::Int}
    };
    QVector<QVariant> defaultData;
    defaultData << 0 << 0;
    dataManager->SetRelation(tableName, coreRelationName, newRelationStruct, defaultData);

    QStringList relationFields = newRelationStruct.keys();
    parentIndex = relationFields.indexOf("parent");
    positionIndex = relationFields.indexOf("position");

    QList<ManagerItemInfo> managerList = dataManager->GetDataList(tableName);
    // Item Id -> Item children.
    QMap<int, QMap<int, Item*>> internalTree;

    // Convert data manager list to internal list.
    QList<QString> chunksNames;
    if(managerList.count() > 0) chunksNames = managerList.first().dataChunks.keys();
    for(int i = 0; i < managerList.count(); i++)
    {
        Item *treeItem = new Item();
        ManagerItemInfo *managerItemInfo = &managerList[i];

        treeItem->SetId(managerItemInfo->id);
        for(int chunksIter = 0; chunksIter < chunksNames.count(); ++chunksIter)
        {
            if(chunksNames[chunksIter] == coreRelationName)
            {
                QVector<QVariant> *dataChunk = &(managerItemInfo->dataChunks[coreRelationName]);
                if(dataChunk->at(parentIndex).toInt() == -1)
                    rootItem = treeItem;
                else
                    internalTree[dataChunk->at(parentIndex).toInt()].insertMulti(dataChunk->at(positionIndex).toInt(), treeItem);
            }
            else
            {
                treeItem->SetChunkData(chunksNames[chunksIter], managerItemInfo->dataChunks[chunksNames[chunksIter]]);
            }
        }
        internalList.insert(managerItemInfo->id, treeItem);
    }

    // Create root if not exists
    if(!rootItem)
    {
        rootItem = AddItem(0, NULL, NULL);
        internalList.insert(rootItem->GetId(), rootItem);
    }

    // Link list to tree
    QList<int> keys = internalTree.keys();
    for(int i = 0; i < keys.count(); i++)
    {
        Item* parent = internalList[keys[i]];
        if(!parent) parent = rootItem;
        QList<Item*> childItemsList = internalTree[keys[i]].values();
        for(int j = 0; j < childItemsList.count(); j++)
           childItemsList[j]->parentItem = parent;
        parent->SetChilds(childItemsList);
    }
}

bool ExtendableTreeItemModel::AttachRelation(QMap<QString, QVariant::Type> relationStruct, QString relationName, QVector<QVariant> defaultData)
{
    dataManager->SetRelation(tableName, relationName, relationStruct, defaultData);
    defaultTask.SetChunkData(relationName, defaultData);
}

void ExtendableTreeItemModel::SetActiveRelation(QString relationName)
{
    qDebug() << "===SetActiveRelation===" << relationName;
    QList<Item*> keys = internalList.values();
    for(int i = 0; i < keys.count(); ++i)
        keys[i]->SetActiveChunkName(relationName);
    currentActiveChunkName = relationName;
}

QVariant ExtendableTreeItemModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    Item *item = static_cast<Item*>(index.internalPointer());
    switch (role) {
    case Qt::DisplayRole:
        return item->GetChunkDataElement(index.column());
        break;
    case Qt::EditRole:
        return item->GetChunkDataElement(index.column());
        break;
    default:
        return QVariant();
        break;
    }
}

Qt::ItemFlags ExtendableTreeItemModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags | Qt::ItemIsDropEnabled;

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled;
}

QVariant ExtendableTreeItemModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    switch (role) {
    case Qt::DisplayRole:
        return rootItem->GetChunkDataElement(section);
        break;
    case Qt::ToolTipRole:
        return rootItem->GetId();
        break;
    case Qt::EditRole:
        return rootItem->GetChunkDataElement(section);
        break;
    default:
        return QVariant();
        break;
    }

    return QVariant();
}

QModelIndex ExtendableTreeItemModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
    {
        qDebug() << "No Index for" << row << column << parent;
        return QModelIndex();
    }

    Item *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<Item*>(parent.internalPointer());

    Item *childItem = parentItem->GetChildAt(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex ExtendableTreeItemModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    Item *childItem = static_cast<Item*>(index.internalPointer());
    Item *parentItem = childItem->parentItem;

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->GetRow(), 0, parentItem);
}

int ExtendableTreeItemModel::rowCount(const QModelIndex &parent) const
{
    Item *parentItem;
    parentItem = (!parent.isValid()) ? rootItem : static_cast<Item*>(parent.internalPointer());
    return parentItem->ChildCount();
}

int ExtendableTreeItemModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return static_cast<Item*>(parent.internalPointer())->ColumnCount();
    else
        return rootItem->ColumnCount();
}

bool ExtendableTreeItemModel::insertRows(int row, int count, const QModelIndex &parent)
{
    Item *parentItem;
    parentItem = (!parent.isValid()) ? rootItem : static_cast<Item*>(parent.internalPointer());

    if(row == -1 || row >= parentItem->ChildCount()) row = parentItem->ChildCount();
    beginInsertRows(parent, row, row+count);
    Item *childItem = AddItem(row, parentItem);
    endInsertRows();
}

bool ExtendableTreeItemModel::insertColumns(int column, int count, const QModelIndex &parent)
{

}

bool ExtendableTreeItemModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row+count);
    Item *parentItem;
    parentItem = (!parent.isValid()) ? rootItem : static_cast<Item*>(parent.internalPointer());

    Item *item = parentItem->GetChildAt(row);
    if(item)
        DeleteItem(item);
    endRemoveRows();
}

bool ExtendableTreeItemModel::moveRows(const QModelIndex &sourceParent, int sourceRow, int count, const QModelIndex &destinationParent, int destinationChild)
{
    qDebug() << "moveRows" << sourceParent << sourceRow << count << destinationParent << destinationChild;
    int sourceLast = sourceRow+count;

    Item *sourceParentItem = (!sourceParent.isValid()) ? rootItem : static_cast<Item*>(sourceParent.internalPointer());
    Item *destinationParentItem = (!destinationParent.isValid()) ? rootItem : static_cast<Item*>(destinationParent.internalPointer());
    Item *destinationChildItem = destinationParentItem->GetChildAt(destinationChild);
    qDebug() << sourceParentItem << destinationChildItem << destinationParentItem->ChildCount() << sourceParentItem->ChildCount();
    QList<Item*> movingItems;

    if(!beginMoveRows(sourceParent, sourceRow, sourceLast, destinationParent, destinationChild))
    {
        qDebug() << "Wrong move";
        return false;
    }

    for(int i = sourceLast; i >= sourceRow; --i)
    {
        movingItems.append(sourceParentItem->GetChildAt(i));
        qDebug() << movingItems.last()->GetRow() << movingItems.last()->GetChunkDataElement(0) << i;
        movingItems.last()->parentItem = destinationParentItem;
        sourceParentItem->RemoveChildAt(i);
    }

    destinationChild = destinationChildItem ? destinationChildItem->GetRow() : destinationChild;

    for(int i = 0; i < movingItems.count(); ++i)
    {
        qDebug() << destinationParentItem->ChildCount() << destinationChild+i << movingItems.count()-1-i;
        destinationParentItem->AddChild(destinationChild+i, movingItems[movingItems.count()-1-i]);
    }

    endMoveRows();
}

bool ExtendableTreeItemModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    qDebug() << "setData" << index.row() << index.column() << index.data() << value;
    Item *item = (!index.isValid()) ? rootItem : static_cast<Item*>(index.internalPointer());
    switch (role) {
    case Qt::EditRole:
        qDebug() << "!!!" << item->GetId() << index.column() << value;
        EditItem(item, index.column(), value);
        emit dataChanged(index, index);
        break;
    default:
        break;
    }

    return true;
}

QStringList ExtendableTreeItemModel::mimeTypes() const
{
    QStringList types;
    types << "application/vnd.text.list";
    return types;
}

QMimeData *ExtendableTreeItemModel::mimeData(const QModelIndexList &indexes) const
{
    qDebug() << "mimeData" << indexes.count();
    QMimeData *mimeData = new QMimeData();
    QByteArray encodedData;

    QDataStream stream(&encodedData, QIODevice::WriteOnly);
    foreach (const QModelIndex &index, indexes) {
        if (index.isValid()) {
            int row = index.row();
            int column = index.column();
            quintptr indexPtr = (quintptr)index.internalPointer();
            quintptr parentPtr = (quintptr)index.parent().internalPointer();

            qDebug() << row << column << indexPtr << parentPtr;
            stream << row << column << indexPtr << parentPtr;
        }
    }
    mimeData->setData("application/vnd.text.list", encodedData);
    return mimeData;
}

bool ExtendableTreeItemModel::dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
    qDebug() << "dropMimeData" << row << column << parent;
    if (action == Qt::IgnoreAction)
        return true;

    if (!data->hasFormat("application/vnd.text.list"))
        return false;

    if (column > 0)
        return false;
    int beginRow;

    if (row != -1)
        beginRow = row;
    else if (parent.isValid())
        beginRow = parent.row();
    else
        beginRow = rowCount(QModelIndex());

    QByteArray encodedData = data->data("application/vnd.text.list");
    QDataStream stream(&encodedData, QIODevice::ReadOnly);
    QMap<quintptr, QMap<int, quintptr>> newItems;
    int rows = 0;

    while (!stream.atEnd()) {
        int row;
        int column;
        quintptr idxPtr;
        quintptr parentPtr;
        stream >> row;
        stream >> column;
        stream >> idxPtr;
        stream >> parentPtr;

        qDebug() << row << column << idxPtr << parentPtr;
        newItems[parentPtr][row] = idxPtr;
        qDebug() << newItems.count();
        ++rows;
    }

    QModelIndex bufIdx;
    QModelIndex blockFirstIdx;
    QModelIndex parentIdx;
    Item *blockFirstItem;
    if(!parent.isValid())
    {
        parentIdx = createIndex(-1, -1, newItems.begin().key());
        qDebug() << "That's it!";
    }
    else
        parentIdx = parent;

    QMap<quintptr, QMap<int, quintptr>>::Iterator parentI = newItems.begin();
    while(parentI != newItems.end())
    {
        qDebug() << "parentI" << parentI.key();
        QMap<int, quintptr> rows = parentI.value();
        QMap<int, quintptr>::Iterator rowsI = rows.begin();
        QMap<int, quintptr>::Iterator lastRowI = --rows.end();
        int itemsBlock = 0;
        int prevRow = -1;
        blockFirstItem = NULL;
        while(rowsI != rows.end())
        {
            qDebug() << "rowsI" << rowsI.key();
            bufIdx = createIndex(rowsI.key(), 0, rowsI.value());
            if(itemsBlock == 0) blockFirstIdx = bufIdx;

            if( prevRow != -1 && (prevRow != rowsI.key()-1) )
            {
                qDebug() << "Second";
                Item *treeItem = (Item*)blockFirstIdx.internalPointer();
                moveRows(blockFirstIdx.parent(), treeItem->GetRow(), itemsBlock-1, parentIdx, beginRow);
                blockFirstIdx = bufIdx;
                itemsBlock = 0;
            }
            if(rowsI == lastRowI)
            {
                qDebug() << "First";
                Item *treeItem = (Item*)blockFirstIdx.internalPointer();
                moveRows(blockFirstIdx.parent(), treeItem->GetRow(), itemsBlock, parentIdx, beginRow);
                itemsBlock = 0;
            }

            prevRow = rowsI.key();
            ++itemsBlock;
            ++rowsI;
        }
        UpdateItemsPosition((Item*)parentI.key(), rows.begin().key());
        ++parentI;
    }
    UpdateItemsPosition((Item*)parent.internalPointer(), (row == -1) ? 0 : row);
    return true;
}

Item *ExtendableTreeItemModel::AddItem(int row, Item *taskParent, Item* taskData)
{
    if(!dataManager)
    {
        qDebug() << "Data manager not set!";
        return false;
    }
    if(!taskParent) taskParent = rootItem;
    if(!taskData) taskData = &defaultTask;

    qDebug() << "Add task";
    Item *newTask = new Item(taskParent, taskData);
    if(taskParent) taskParent->AddChild(row, newTask);

    ManagerItemInfo managerTask = ConvertToManagerItem(newTask);
    int newTaskId = dataManager->AddItem(tableName, managerTask);
    newTask->SetId(newTaskId);
    newTask->SetActiveChunkName(currentActiveChunkName);
    return newTask;
}

bool ExtendableTreeItemModel::EditItem(Item *task, int column, QVariant dataField)
{
    qDebug() << "EditTask";
    if(!dataManager){
        qDebug() << "Data manager not set!";
        return false;
    }

    task->SetActiveChunkName(currentActiveChunkName);
    task->SetChunkDataElement(column, dataField);
    ManagerItemInfo managerTask = ConvertToManagerItem(task);
    dataManager->EditItem(tableName, managerTask);
}

bool ExtendableTreeItemModel::UpdateItemsPosition(Item *parent, int from)
{
    if(!dataManager)
    {
        qDebug() << "Data manager not set!";
        return false;
    }

    if(!parent) parent = rootItem;
    int to = parent->ChildCount();
    qDebug() << "UpdateTaskPositions" << parent << parent->GetChunkDataElement(0) << from;

    for(int i = from; i < to; ++i)
    {
        qDebug() << parent->ChildCount() << to;
        qDebug() << parent->ChildCount() << parent->GetChildAt(i);
        dataManager->EditItem(tableName, ConvertToManagerItem(parent->GetChildAt(i)));
    }
}

bool ExtendableTreeItemModel::DeleteItem(Item *task)
{
    qDebug() << "DeleteTask";
    if(!dataManager)
    {
        qDebug() << "Data manager not set!";
        return false;
    }
    if(!task)
        return false;
    if(task->parentItem)
        task->parentItem->RemoveChild(task);
    DeleteFromManagerRecursive(task);
}

IExtendableDataBaseManagerPlugin::ManagerItemInfo ExtendableTreeItemModel::ConvertToManagerItem(Item* item)
{
    ManagerItemInfo managerStruct;
    //Set id
    managerStruct.id = item->GetId();
    QStringList list = item->GetChunksNames();
    for(int i = 0; i < list.count(); ++i)
        managerStruct.dataChunks[list[i]] = item->GetChunkData(list[i]);

    // Set parent
    managerStruct.dataChunks[coreRelationName].append(item->parentItem ? item->parentItem->GetId() : -1);
    // Set position
    managerStruct.dataChunks[coreRelationName].append((item->parentItem) ? item->parentItem->GetChildPosition(item) : 0);
    return managerStruct;
}

void ExtendableTreeItemModel::DeleteFromManagerRecursive(Item *task)
{
    if(task->ChildCount() != 0)
        for(int i = 0; i < task->ChildCount(); i++)
            DeleteFromManagerRecursive(task->GetChildAt(i));

    internalList.remove(task->GetId());
    dataManager->DeleteItem(tableName, task->GetId());
}
