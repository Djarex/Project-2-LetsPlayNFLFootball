/****************************************************************************
** Meta object code from reading C++ file 'adminwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../adminwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adminwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_adminWindow_t {
    QByteArrayData data[11];
    char stringdata0[311];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_adminWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_adminWindow_t qt_meta_stringdata_adminWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "adminWindow"
QT_MOC_LITERAL(1, 12, 36), // "on_comboBox_Team_Selection_ac..."
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 5), // "index"
QT_MOC_LITERAL(4, 56, 36), // "on_comboBox_SelectSouvenir_ac..."
QT_MOC_LITERAL(5, 93, 4), // "arg1"
QT_MOC_LITERAL(6, 98, 45), // "on_pushButton_SelectSouvenir_..."
QT_MOC_LITERAL(7, 144, 43), // "on_pushButton_SelectSouvenir_..."
QT_MOC_LITERAL(8, 188, 37), // "on_pushButton_NewSouvenir_Add..."
QT_MOC_LITERAL(9, 226, 36), // "on_pushButton_NewStadium_Add_..."
QT_MOC_LITERAL(10, 263, 47) // "on_pushButton_SelectStadium_S..."

    },
    "adminWindow\0on_comboBox_Team_Selection_activated\0"
    "\0index\0on_comboBox_SelectSouvenir_activated\0"
    "arg1\0on_pushButton_SelectSouvenir_SetPrice_clicked\0"
    "on_pushButton_SelectSouvenir_Delete_clicked\0"
    "on_pushButton_NewSouvenir_Add_clicked\0"
    "on_pushButton_NewStadium_Add_clicked\0"
    "on_pushButton_SelectStadium_SetCapacity_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_adminWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       4,    1,   52,    2, 0x08 /* Private */,
       6,    0,   55,    2, 0x08 /* Private */,
       7,    0,   56,    2, 0x08 /* Private */,
       8,    0,   57,    2, 0x08 /* Private */,
       9,    0,   58,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void adminWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<adminWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_comboBox_Team_Selection_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_comboBox_SelectSouvenir_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_SelectSouvenir_SetPrice_clicked(); break;
        case 3: _t->on_pushButton_SelectSouvenir_Delete_clicked(); break;
        case 4: _t->on_pushButton_NewSouvenir_Add_clicked(); break;
        case 5: _t->on_pushButton_NewStadium_Add_clicked(); break;
        case 6: _t->on_pushButton_SelectStadium_SetCapacity_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject adminWindow::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_adminWindow.data,
    qt_meta_data_adminWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *adminWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *adminWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_adminWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int adminWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
