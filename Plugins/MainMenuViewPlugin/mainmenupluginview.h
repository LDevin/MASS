#ifndef MAINMENUPLUGINVIEW_H
#define MAINMENUPLUGINVIEW_H

#include <QLayout>
#include <QObject>
#include <QDebug>

#include "../MainMenuModelPlugin/imainmenumodule.h"
#include "mainform.h"

//! \defgroup MainMenuPluginView
//!     \ingroup MainMenuPlugin_rel_v
//! \defgroup MainMenuPluginView_imp Implementation
//!     \ingroup MainMenuPluginView

//! \addtogroup MainMenuPluginView_imp
//! \{
class MainMenuPluginView : public QObject, IViewPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "TimeKeeper.Module.Test" FILE "PluginMeta.json")
    Q_INTERFACES(IViewPlugin)

private:    
    IMainMenuPluginModel *myModel;
    MainForm *mainForm;
    IMainMenuPluginModel::MenuItem *rootMenuItem;

public:
    MainMenuPluginView();
    ~MainMenuPluginView();

    void OnAllSetup() override;
    QString GetLastError() override;

    void AddModel(QObject *model) override;
    bool Open(IModelPlugin* model, QWidget* parent) override;
    bool Close() override;

private slots:
    void OpenChildPlugin(IMainMenuPluginModel::MenuItem *menuItem, MetaInfo *viewMeta);
    void CloseMainMenu();

signals:
    void OnClose(IViewPlugin *pointer);
    void OnClose();
};
//! \}
#endif // MAINMENUPLUGINVIEW_H
