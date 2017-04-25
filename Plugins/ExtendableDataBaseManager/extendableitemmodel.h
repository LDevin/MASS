#ifndef EXTENDABLEITEMMODEL_H
#define EXTENDABLEITEMMODEL_H

#include <QAbstractItemModel>
#include <QVariant>
#include <QVector>
#include <QDebug>
#include <QMimeData>
#include <QDataStream>
#include <QMap>

#include "iextendabledatabasemanagerplugin.h"
#include "item.h"

class ExtendableItemModel : public QAbstractItemModel
{
    typedef IExtendableDataBaseManagerPlugin::ManagerDataItem ManagerItemInfo;
public:
    QString tableName;
    QString coreRelationName;
    IExtendableDataBaseManagerPlugin* dataManager;

    ExtendableItemModel(QString tableName, IExtendableDataBaseManagerPlugin* dataManager, QObject *parent = 0);
    ~ExtendableItemModel();
    void LoadData();
    bool AttachRelation(QString relationName, QVector<QVariant> defaultData);
    void SetActiveRelation(QString relationName);

    virtual QVariant data(const QModelIndex &index, int role) const;
    QMap<int, QVariant> itemData(const QModelIndex &index) const override;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    virtual QModelIndex parent(const QModelIndex &index) const;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
    virtual bool insertRows(int row, int count, const QModelIndex &parent);
    virtual bool insertColumns(int column, int count, const QModelIndex &parent);
    virtual bool removeRows(int row, int count, const QModelIndex &parent);
    virtual bool moveRows(const QModelIndex &sourceParent, int sourceRow, int count, const QModelIndex &destinationParent, int destinationChild);
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role);
    virtual QStringList mimeTypes() const;
    virtual QMimeData *mimeData(const QModelIndexList &indexes) const;
    virtual bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);

private:
    int nameIndex;
    int parentIndex;
    int positionIndex;

    QHash<int, Item*> internalList;
    QString currentActiveChunkName;
    Item defaultTask;
    Item *rootItem;

    Item *AddItem(int row, Item *taskParent, Item *taskData = NULL);
    bool EditItem(Item *task, int column, QVariant dataField);
    bool UpdateItemsPosition(Item *parent, int from);
    bool DeleteItem(Item *task);
    void DeleteFromManagerRecursive(Item *task);
    ManagerItemInfo ConvertToManagerItem(Item* item);
};

#endif // EXTENDABLEITEMMODEL_H
