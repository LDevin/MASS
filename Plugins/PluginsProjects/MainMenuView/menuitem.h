#ifndef MENUITEM_H
#define MENUITEM_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QPainter>
#include <QWidget>
#include <QRegExp>
#include <QEvent>
#include <QStringList>

#include "../../PluginsInterfaces/imainmenumodule.h"

//! \addtogroup MainMenuPluginView_imp
//! \{
class MenuItemGraphicsObject : public QWidget, public QGraphicsItem
{
    Q_OBJECT
    void FormatMenuItemName(QString name);

public:
    MenuItemGraphicsObject(MenuItemGraphicsObject *ParentMenuItem, IMainMenuModel::IMenuItem *MenuItemGraphicsObject,
                           MetaInfo *ViewPlugin, QWidget *parent = 0);
    MenuItemGraphicsObject(QString name, QWidget *parent = 0);
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    MenuItemGraphicsObject *parentMenuItem;
    IMainMenuModel::IMenuItem *menuItem;
    MetaInfo *viewPluginMeta;

protected:
    bool pressed;
    int dx, dy;
    QString itemMenuName;
    QRectF boundRect;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

signals:
    void OnClicked(MenuItemGraphicsObject *me);
};
//! \}
#endif // MENUITEM_H