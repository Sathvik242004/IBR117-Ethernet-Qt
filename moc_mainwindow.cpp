/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[379];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 17), // "on_tcpdia_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 17), // "on_udpdia_clicked"
QT_MOC_LITERAL(4, 48, 20), // "on_connected_clicked"
QT_MOC_LITERAL(5, 69, 20), // "on_getWifiIP_clicked"
QT_MOC_LITERAL(6, 90, 19), // "on_getethip_clicked"
QT_MOC_LITERAL(7, 110, 23), // "on_Internetstat_clicked"
QT_MOC_LITERAL(8, 134, 15), // "on_prop_clicked"
QT_MOC_LITERAL(9, 150, 17), // "on_tcpmes_clicked"
QT_MOC_LITERAL(10, 168, 20), // "on_diaip_textChanged"
QT_MOC_LITERAL(11, 189, 4), // "arg1"
QT_MOC_LITERAL(12, 194, 20), // "on_socip_textChanged"
QT_MOC_LITERAL(13, 215, 18), // "on_udpmess_clicked"
QT_MOC_LITERAL(14, 234, 17), // "on_Listen_clicked"
QT_MOC_LITERAL(15, 252, 24), // "on_StopListening_clicked"
QT_MOC_LITERAL(16, 277, 13), // "updateTextBox"
QT_MOC_LITERAL(17, 291, 7), // "message"
QT_MOC_LITERAL(18, 299, 20), // "on_setdestip_clicked"
QT_MOC_LITERAL(19, 320, 19), // "on_setdevip_clicked"
QT_MOC_LITERAL(20, 340, 20), // "on_setportno_clicked"
QT_MOC_LITERAL(21, 361, 17) // "updateRtClockTime"

    },
    "MainWindow\0on_tcpdia_clicked\0\0"
    "on_udpdia_clicked\0on_connected_clicked\0"
    "on_getWifiIP_clicked\0on_getethip_clicked\0"
    "on_Internetstat_clicked\0on_prop_clicked\0"
    "on_tcpmes_clicked\0on_diaip_textChanged\0"
    "arg1\0on_socip_textChanged\0on_udpmess_clicked\0"
    "on_Listen_clicked\0on_StopListening_clicked\0"
    "updateTextBox\0message\0on_setdestip_clicked\0"
    "on_setdevip_clicked\0on_setportno_clicked\0"
    "updateRtClockTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x08 /* Private */,
       3,    0,  105,    2, 0x08 /* Private */,
       4,    0,  106,    2, 0x08 /* Private */,
       5,    0,  107,    2, 0x08 /* Private */,
       6,    0,  108,    2, 0x08 /* Private */,
       7,    0,  109,    2, 0x08 /* Private */,
       8,    0,  110,    2, 0x08 /* Private */,
       9,    0,  111,    2, 0x08 /* Private */,
      10,    1,  112,    2, 0x08 /* Private */,
      12,    1,  115,    2, 0x08 /* Private */,
      13,    0,  118,    2, 0x08 /* Private */,
      14,    0,  119,    2, 0x08 /* Private */,
      15,    0,  120,    2, 0x08 /* Private */,
      16,    1,  121,    2, 0x08 /* Private */,
      18,    0,  124,    2, 0x08 /* Private */,
      19,    0,  125,    2, 0x08 /* Private */,
      20,    0,  126,    2, 0x08 /* Private */,
      21,    0,  127,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_tcpdia_clicked(); break;
        case 1: _t->on_udpdia_clicked(); break;
        case 2: _t->on_connected_clicked(); break;
        case 3: _t->on_getWifiIP_clicked(); break;
        case 4: _t->on_getethip_clicked(); break;
        case 5: _t->on_Internetstat_clicked(); break;
        case 6: _t->on_prop_clicked(); break;
        case 7: _t->on_tcpmes_clicked(); break;
        case 8: _t->on_diaip_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_socip_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->on_udpmess_clicked(); break;
        case 11: _t->on_Listen_clicked(); break;
        case 12: _t->on_StopListening_clicked(); break;
        case 13: _t->updateTextBox((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->on_setdestip_clicked(); break;
        case 15: _t->on_setdevip_clicked(); break;
        case 16: _t->on_setportno_clicked(); break;
        case 17: _t->updateRtClockTime(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
