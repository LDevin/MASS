/****************************************************************************
** Meta object code from reading C++ file 'mainmenumodelplugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainmenumodelplugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainmenumodelplugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainMenuModelPlugin_t {
    QByteArrayData data[14];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainMenuModelPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainMenuModelPlugin_t qt_meta_stringdata_MainMenuModelPlugin = {
    {
QT_MOC_LITERAL(0, 0, 19), // "MainMenuModelPlugin"
QT_MOC_LITERAL(1, 20, 7), // "OnClose"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 13), // "IModelPlugin*"
QT_MOC_LITERAL(4, 43, 7), // "pointer"
QT_MOC_LITERAL(5, 51, 4), // "Open"
QT_MOC_LITERAL(6, 56, 5), // "model"
QT_MOC_LITERAL(7, 62, 8), // "QWidget*"
QT_MOC_LITERAL(8, 71, 11), // "modelWidget"
QT_MOC_LITERAL(9, 83, 18), // "RelatedModelClosed"
QT_MOC_LITERAL(10, 102, 17), // "RelatedViewClosed"
QT_MOC_LITERAL(11, 120, 12), // "IViewPlugin*"
QT_MOC_LITERAL(12, 133, 4), // "view"
QT_MOC_LITERAL(13, 138, 5) // "Close"

    },
    "MainMenuModelPlugin\0OnClose\0\0IModelPlugin*\0"
    "pointer\0Open\0model\0QWidget*\0modelWidget\0"
    "RelatedModelClosed\0RelatedViewClosed\0"
    "IViewPlugin*\0view\0Close"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainMenuModelPlugin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       1,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   48,    2, 0x0a /* Public */,
       9,    1,   53,    2, 0x0a /* Public */,
      10,    1,   56,    2, 0x0a /* Public */,
      13,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 3, 0x80000000 | 7,    6,    8,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,

       0        // eod
};

void MainMenuModelPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainMenuModelPlugin *_t = static_cast<MainMenuModelPlugin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnClose((*reinterpret_cast< IModelPlugin*(*)>(_a[1]))); break;
        case 1: _t->OnClose(); break;
        case 2: { bool _r = _t->Open((*reinterpret_cast< IModelPlugin*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->RelatedModelClosed((*reinterpret_cast< IModelPlugin*(*)>(_a[1]))); break;
        case 4: _t->RelatedViewClosed((*reinterpret_cast< IViewPlugin*(*)>(_a[1]))); break;
        case 5: _t->Close(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainMenuModelPlugin::*_t)(IModelPlugin * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainMenuModelPlugin::OnClose)) {
                *result = 0;
            }
        }
        {
            typedef void (MainMenuModelPlugin::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainMenuModelPlugin::OnClose)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MainMenuModelPlugin::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MainMenuModelPlugin.data,
      qt_meta_data_MainMenuModelPlugin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainMenuModelPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainMenuModelPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainMenuModelPlugin.stringdata0))
        return static_cast<void*>(const_cast< MainMenuModelPlugin*>(this));
    if (!strcmp(_clname, "IMainMenuPluginModel"))
        return static_cast< IMainMenuPluginModel*>(const_cast< MainMenuModelPlugin*>(this));
    if (!strcmp(_clname, "IRootModelPlugin"))
        return static_cast< IRootModelPlugin*>(const_cast< MainMenuModelPlugin*>(this));
    if (!strcmp(_clname, "IModelPlugin v0.1"))
        return static_cast< IModelPlugin*>(const_cast< MainMenuModelPlugin*>(this));
    if (!strcmp(_clname, "IRootModelPlugin v0.1"))
        return static_cast< IRootModelPlugin*>(const_cast< MainMenuModelPlugin*>(this));
    if (!strcmp(_clname, "IMainMenuModule v0.1"))
        return static_cast< IMainMenuPluginModel*>(const_cast< MainMenuModelPlugin*>(this));
    return QObject::qt_metacast(_clname);
}

int MainMenuModelPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MainMenuModelPlugin::OnClose(IModelPlugin * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainMenuModelPlugin::OnClose()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

QT_PLUGIN_METADATA_SECTION const uint qt_section_alignment_dummy = 42;

#ifdef QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    0x18, 0x01, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0x04, 0x01, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    0x16, 0x00, 'T',  'i',  'm',  'e',  'K',  'e', 
    'e',  'p',  'e',  'r',  '.',  'M',  'o',  'd', 
    'u',  'l',  'e',  '.',  'T',  'e',  's',  't', 
    0x1b, 0x08, 0x00, 0x00, 0x09, 0x00, 'c',  'l', 
    'a',  's',  's',  'N',  'a',  'm',  'e',  0x00,
    0x13, 0x00, 'M',  'a',  'i',  'n',  'M',  'e', 
    'n',  'u',  'M',  'o',  'd',  'e',  'l',  'P', 
    'l',  'u',  'g',  'i',  'n',  0x00, 0x00, 0x00,
    ':',  0xa0, 0xa0, 0x00, 0x07, 0x00, 'v',  'e', 
    'r',  's',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    0x11, 0x00, 0x00, 0x00, 0x05, 0x00, 'd',  'e', 
    'b',  'u',  'g',  0x00, 0x95, 0x10, 0x00, 0x00,
    0x08, 0x00, 'M',  'e',  't',  'a',  'D',  'a', 
    't',  'a',  0x00, 0x00, 0x80, 0x00, 0x00, 0x00,
    0x09, 0x00, 0x00, 0x00, 'p',  0x00, 0x00, 0x00,
    0x1b, 0x03, 0x00, 0x00, 0x04, 0x00, 'N',  'a', 
    'm',  'e',  0x00, 0x00, 0x0d, 0x00, 'M',  'a', 
    'i',  'n',  'M',  'e',  'n',  'u',  'M',  'o', 
    'd',  'e',  'l',  0x00, 0x1b, 0x07, 0x00, 0x00,
    0x0a, 0x00, 'P',  'l',  'u',  'g',  'i',  'n', 
    'T',  'y',  'p',  'e',  0x09, 0x00, 'R',  'o', 
    'o',  't',  'M',  'o',  'd',  'e',  'l',  0x00,
    0x9b, 0x0a, 0x00, 0x00, 0x0a, 0x00, 'P',  'a', 
    'r',  'e',  'n',  't',  'N',  'a',  'm',  'e', 
    0x00, 0x00, 0x00, 0x00, 0x9b, 0x0d, 0x00, 0x00,
    0x0b, 0x00, 'D',  'a',  't',  'a',  'M',  'a', 
    'n',  'a',  'g',  'e',  'r',  0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 'X',  0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 'D',  0x00, 0x00, 0x00,
    '(',  0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    't',  0x00, 0x00, 0x00, '0',  0x00, 0x00, 0x00,
    'h',  0x00, 0x00, 0x00, 'X',  0x00, 0x00, 0x00
};

#else // QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    0x18, 0x01, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    0x04, 0x01, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    0x16, 0x00, 'T',  'i',  'm',  'e',  'K',  'e', 
    'e',  'p',  'e',  'r',  '.',  'M',  'o',  'd', 
    'u',  'l',  'e',  '.',  'T',  'e',  's',  't', 
    0x15, 0x08, 0x00, 0x00, 0x08, 0x00, 'M',  'e', 
    't',  'a',  'D',  'a',  't',  'a',  0x00, 0x00,
    0x80, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00,
    'p',  0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x04, 0x00, 'N',  'a',  'm',  'e',  0x00, 0x00,
    0x0d, 0x00, 'M',  'a',  'i',  'n',  'M',  'e', 
    'n',  'u',  'M',  'o',  'd',  'e',  'l',  0x00,
    0x1b, 0x07, 0x00, 0x00, 0x0a, 0x00, 'P',  'l', 
    'u',  'g',  'i',  'n',  'T',  'y',  'p',  'e', 
    0x09, 0x00, 'R',  'o',  'o',  't',  'M',  'o', 
    'd',  'e',  'l',  0x00, 0x9b, 0x0a, 0x00, 0x00,
    0x0a, 0x00, 'P',  'a',  'r',  'e',  'n',  't', 
    'N',  'a',  'm',  'e',  0x00, 0x00, 0x00, 0x00,
    0x9b, 0x0d, 0x00, 0x00, 0x0b, 0x00, 'D',  'a', 
    't',  'a',  'M',  'a',  'n',  'a',  'g',  'e', 
    'r',  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    'X',  0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    'D',  0x00, 0x00, 0x00, '(',  0x00, 0x00, 0x00,
    0x1b, 0x1a, 0x00, 0x00, 0x09, 0x00, 'c',  'l', 
    'a',  's',  's',  'N',  'a',  'm',  'e',  0x00,
    0x13, 0x00, 'M',  'a',  'i',  'n',  'M',  'e', 
    'n',  'u',  'M',  'o',  'd',  'e',  'l',  'P', 
    'l',  'u',  'g',  'i',  'n',  0x00, 0x00, 0x00,
    '1',  0x00, 0x00, 0x00, 0x05, 0x00, 'd',  'e', 
    'b',  'u',  'g',  0x00, ':',  0xa0, 0xa0, 0x00,
    0x07, 0x00, 'v',  'e',  'r',  's',  'i',  'o', 
    'n',  0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    '0',  0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00,
    0xe8, 0x00, 0x00, 0x00, 0xf4, 0x00, 0x00, 0x00
};
#endif // QT_NO_DEBUG

QT_MOC_EXPORT_PLUGIN(MainMenuModelPlugin, MainMenuModelPlugin)

QT_END_MOC_NAMESPACE
