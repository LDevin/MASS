#ifndef POMODOROVIEW_H
#define POMODOROVIEW_H

#include <QApplication>
#include <QDebug>
#include <QLayout>
#include <QWidget>

#include "../../Models/PomodoroModel/ipomodoromodel.h"
#include "pomodorobutton.h"
#include "mytreeview.h"
#include "designproxymodel.h"

namespace Ui {
class PomodoroView;
}

//! \defgroup PomodoroView
//!     \ingroup MainMenuPlugin_rel_v
//! \defgroup PomodoroView_imp Implementation
//!     \ingroup PomodoroView

//! \addtogroup PomodoroView_imp
//! \{
class PomodoroView : public QWidget, IViewPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "TimeKeeper.Module.Test" FILE "PluginMeta.json")
    Q_INTERFACES(IViewPlugin)

public:
    explicit PomodoroView(QWidget *parent = 0);
    ~PomodoroView();

private:
    PluginInfo *pluginInfo;
    Ui::PomodoroView *ui;
    IPomodoroModel *myModel;
    QAbstractItemModel *proxyModel;

    QModelIndex currentTask;
    IPomodoroModel::WorkSetup workSetup;

    // IPlugin interface
    void InstallWorkSetup();
    void UpdateSelectedTask();

public:
    void SetPluginInfo(PluginInfo *pluginInfo) override;
    void OnAllSetup() override;
    QString GetLastError() override;
    void AddReferencePlugin(PluginInfo *pluginInfo) override;

public slots:
    void ReferencePluginClosed(PluginInfo *pluginInfo) override;

    // IViewPlugin interface
public slots:
    bool Open(IModelPlugin *model) override;
    bool Close() override;

signals:
    void OnOpen(QWidget*);
    void OnClose(PluginInfo*);
    void OnClose();

private slots:
    void PomodoroFinished();
    void on_buttonProjects_clicked();
    void on_buttonEdit_clicked();

    // QWidget interface
    void on_buttonDelete_clicked();

    void on_buttonAdd_clicked();
    void on_treeView_clicked(const QModelIndex &index);
    void on_treeView_pressed(const QModelIndex &index);

    // QObject interface
public:
    bool eventFilter(QObject *watched, QEvent *event) override;
};
//! \}
#endif // TASKLISTVIEW_H