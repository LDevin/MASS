#ifndef GRIDMAINMENUVIEW_H
#define GRIDMAINMENUVIEW_H

#include <QWidget>
#include <QDebug>
#include <QString>
#include <QLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <QScroller>

#include "../../PluginsInterfaces/iuimanager.h"
#include "../../PluginsCommon/plugin_base.h"

#include "uniquepushbutton.h"
#include "aspectawaregridlayout.h"

//! addtogroup GridMainMenuView_imp
//! {
class GridMainMenuView : public PluginBase
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "TimeKeeper.Module.Test" FILE "PluginMeta.json")
    Q_INTERFACES(
        IPlugin
    )

public:
    explicit GridMainMenuView();
    virtual ~GridMainMenuView() override;

private:
    //    QQuickView *quickView;
    //    QWidget *container;

    IUIManager *m_uiManager;

    QLayout *layout;
    QMap<int, QWeakPointer<IUIManager::IUIElement>> m_uiElements;
    int m_uniqueIdCounter;
    QVector<UniquePushButton *> m_uniqueButtons;
    UniquePushButton *m_exitItem;

private slots:
    void UniqueButtonPressed(UniquePushButton *button);
    QString FormatMenuItemName(QString name);

private:
    int getUniqueId();

signals:
    void OnOpen(QWidget *);

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event) override;

    // PluginBase interface
protected:
    virtual void onAllReferencesSetStateChanged() override;

    // IPlugin interface
public:
    virtual bool open(const IPlugin *openedByPlugin) override;
};
//! }
#endif // GRIDMAINMENUVIEW_H
