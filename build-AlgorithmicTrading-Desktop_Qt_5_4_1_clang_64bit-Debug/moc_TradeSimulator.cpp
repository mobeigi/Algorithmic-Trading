/****************************************************************************
** Meta object code from reading C++ file 'TradeSimulator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Trading_Platform_GUI/TradeSimulator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TradeSimulator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TradeSimulator_t {
    QByteArrayData data[7];
    char stringdata[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TradeSimulator_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TradeSimulator_t qt_meta_stringdata_TradeSimulator = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TradeSimulator"
QT_MOC_LITERAL(1, 15, 13), // "sendEndThread"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 24), // "on_sendBuySignal_clicked"
QT_MOC_LITERAL(4, 55, 25), // "on_sendSellSignal_clicked"
QT_MOC_LITERAL(5, 81, 32), // "on_exportOrderFileButton_clicked"
QT_MOC_LITERAL(6, 114, 18) // "doThreadEndActions"

    },
    "TradeSimulator\0sendEndThread\0\0"
    "on_sendBuySignal_clicked\0"
    "on_sendSellSignal_clicked\0"
    "on_exportOrderFileButton_clicked\0"
    "doThreadEndActions"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TradeSimulator[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TradeSimulator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TradeSimulator *_t = static_cast<TradeSimulator *>(_o);
        switch (_id) {
        case 0: _t->sendEndThread(); break;
        case 1: _t->on_sendBuySignal_clicked(); break;
        case 2: _t->on_sendSellSignal_clicked(); break;
        case 3: _t->on_exportOrderFileButton_clicked(); break;
        case 4: _t->doThreadEndActions(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TradeSimulator::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TradeSimulator::sendEndThread)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TradeSimulator::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TradeSimulator.data,
      qt_meta_data_TradeSimulator,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TradeSimulator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TradeSimulator::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TradeSimulator.stringdata))
        return static_cast<void*>(const_cast< TradeSimulator*>(this));
    return QWidget::qt_metacast(_clname);
}

int TradeSimulator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TradeSimulator::sendEndThread()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
