/****************************************************************************
** Meta object code from reading C++ file 'mode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_mode_t {
    QByteArrayData data[22];
    char stringdata0[204];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mode_t qt_meta_stringdata_mode = {
    {
QT_MOC_LITERAL(0, 0, 4), // "mode"
QT_MOC_LITERAL(1, 5, 7), // "ExitWin"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 9), // "sendlogin"
QT_MOC_LITERAL(4, 24, 1), // "s"
QT_MOC_LITERAL(5, 26, 15), // "returntoConnect"
QT_MOC_LITERAL(6, 42, 4), // "exit"
QT_MOC_LITERAL(7, 47, 11), // "recvMessage"
QT_MOC_LITERAL(8, 59, 13), // "returnConnect"
QT_MOC_LITERAL(9, 73, 10), // "controlcam"
QT_MOC_LITERAL(10, 84, 5), // "index"
QT_MOC_LITERAL(11, 90, 9), // "readframe"
QT_MOC_LITERAL(12, 100, 7), // "capture"
QT_MOC_LITERAL(13, 108, 5), // "recap"
QT_MOC_LITERAL(14, 114, 6), // "upload"
QT_MOC_LITERAL(15, 121, 5), // "query"
QT_MOC_LITERAL(16, 127, 13), // "normal_signin"
QT_MOC_LITERAL(17, 141, 14), // "dynamic_signin"
QT_MOC_LITERAL(18, 156, 13), // "finish_signin"
QT_MOC_LITERAL(19, 170, 9), // "broadcast"
QT_MOC_LITERAL(20, 180, 13), // "teacher_query"
QT_MOC_LITERAL(21, 194, 9) // "manSignin"

    },
    "mode\0ExitWin\0\0sendlogin\0s\0returntoConnect\0"
    "exit\0recvMessage\0returnConnect\0"
    "controlcam\0index\0readframe\0capture\0"
    "recap\0upload\0query\0normal_signin\0"
    "dynamic_signin\0finish_signin\0broadcast\0"
    "teacher_query\0manSignin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mode[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    1,  105,    2, 0x06 /* Public */,
       5,    0,  108,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  109,    2, 0x08 /* Private */,
       7,    0,  110,    2, 0x08 /* Private */,
       8,    0,  111,    2, 0x08 /* Private */,
       9,    1,  112,    2, 0x08 /* Private */,
      11,    0,  115,    2, 0x08 /* Private */,
      12,    0,  116,    2, 0x08 /* Private */,
      13,    0,  117,    2, 0x08 /* Private */,
      14,    0,  118,    2, 0x08 /* Private */,
      15,    0,  119,    2, 0x08 /* Private */,
      16,    0,  120,    2, 0x08 /* Private */,
      17,    0,  121,    2, 0x08 /* Private */,
      18,    0,  122,    2, 0x08 /* Private */,
      19,    0,  123,    2, 0x08 /* Private */,
      20,    0,  124,    2, 0x08 /* Private */,
      21,    0,  125,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mode *_t = static_cast<mode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ExitWin(); break;
        case 1: _t->sendlogin((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->returntoConnect(); break;
        case 3: _t->exit(); break;
        case 4: _t->recvMessage(); break;
        case 5: _t->returnConnect(); break;
        case 6: _t->controlcam((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->readframe(); break;
        case 8: _t->capture(); break;
        case 9: _t->recap(); break;
        case 10: _t->upload(); break;
        case 11: _t->query(); break;
        case 12: _t->normal_signin(); break;
        case 13: _t->dynamic_signin(); break;
        case 14: _t->finish_signin(); break;
        case 15: _t->broadcast(); break;
        case 16: _t->teacher_query(); break;
        case 17: _t->manSignin(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (mode::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&mode::ExitWin)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (mode::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&mode::sendlogin)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (mode::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&mode::returntoConnect)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject mode::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_mode.data,
      qt_meta_data_mode,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *mode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mode::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_mode.stringdata0))
        return static_cast<void*>(const_cast< mode*>(this));
    return QWidget::qt_metacast(_clname);
}

int mode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void mode::ExitWin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void mode::sendlogin(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void mode::returntoConnect()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
