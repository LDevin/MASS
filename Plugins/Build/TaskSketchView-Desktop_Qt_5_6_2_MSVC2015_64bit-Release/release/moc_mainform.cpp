/****************************************************************************
** Meta object code from reading C++ file 'mainform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../TaskSketchView/mainform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainForm_t {
    QByteArrayData data[11];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainForm_t qt_meta_stringdata_MainForm = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MainForm"
QT_MOC_LITERAL(1, 9, 7), // "onClose"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 13), // "OnItemConvert"
QT_MOC_LITERAL(4, 32, 5), // "index"
QT_MOC_LITERAL(5, 38, 12), // "OnItemDelete"
QT_MOC_LITERAL(6, 51, 17), // "OnItemConvertSlot"
QT_MOC_LITERAL(7, 69, 22), // "on_buttonClose_clicked"
QT_MOC_LITERAL(8, 92, 23), // "on_buttonCreate_clicked"
QT_MOC_LITERAL(9, 116, 21), // "on_buttonSave_clicked"
QT_MOC_LITERAL(10, 138, 28) // "on_buttonOpenGallery_clicked"

    },
    "MainForm\0onClose\0\0OnItemConvert\0index\0"
    "OnItemDelete\0OnItemConvertSlot\0"
    "on_buttonClose_clicked\0on_buttonCreate_clicked\0"
    "on_buttonSave_clicked\0"
    "on_buttonOpenGallery_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   58,    2, 0x08 /* Private */,
       6,    1,   61,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainForm *_t = static_cast<MainForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onClose(); break;
        case 1: _t->OnItemConvert((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->OnItemDelete((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->OnItemConvertSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_buttonClose_clicked(); break;
        case 5: _t->on_buttonCreate_clicked(); break;
        case 6: _t->on_buttonSave_clicked(); break;
        case 7: _t->on_buttonOpenGallery_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainForm::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainForm::onClose)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainForm::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainForm::OnItemConvert)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MainForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainForm.data,
      qt_meta_data_MainForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainForm.stringdata0))
        return static_cast<void*>(const_cast< MainForm*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MainForm::onClose()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MainForm::OnItemConvert(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
