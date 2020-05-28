/****************************************************************************
** Meta object code from reading C++ file 'accountinfo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../lms/accountinfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'accountinfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_accountInfo_t {
    QByteArrayData data[16];
    char stringdata0[287];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_accountInfo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_accountInfo_t qt_meta_stringdata_accountInfo = {
    {
QT_MOC_LITERAL(0, 0, 11), // "accountInfo"
QT_MOC_LITERAL(1, 12, 20), // "on_returnBtn_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 9), // "startInit"
QT_MOC_LITERAL(4, 44, 19), // "getResponseReceived"
QT_MOC_LITERAL(5, 64, 14), // "QNetworkReply*"
QT_MOC_LITERAL(6, 79, 5), // "reply"
QT_MOC_LITERAL(7, 85, 18), // "on_ExitBtn_clicked"
QT_MOC_LITERAL(8, 104, 17), // "on_update_clicked"
QT_MOC_LITERAL(9, 122, 21), // "patchResponseReceived"
QT_MOC_LITERAL(10, 144, 31), // "on_PasswordLineEdit_textChanged"
QT_MOC_LITERAL(11, 176, 4), // "arg1"
QT_MOC_LITERAL(12, 181, 27), // "on_NameLineEdit_textChanged"
QT_MOC_LITERAL(13, 209, 30), // "on_SurnameLineEdit_textChanged"
QT_MOC_LITERAL(14, 240, 28), // "on_EmailLineEdit_textChanged"
QT_MOC_LITERAL(15, 269, 17) // "ft_checkEditLines"

    },
    "accountInfo\0on_returnBtn_clicked\0\0"
    "startInit\0getResponseReceived\0"
    "QNetworkReply*\0reply\0on_ExitBtn_clicked\0"
    "on_update_clicked\0patchResponseReceived\0"
    "on_PasswordLineEdit_textChanged\0arg1\0"
    "on_NameLineEdit_textChanged\0"
    "on_SurnameLineEdit_textChanged\0"
    "on_EmailLineEdit_textChanged\0"
    "ft_checkEditLines"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_accountInfo[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    1,   71,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    1,   76,    2, 0x08 /* Private */,
      10,    1,   79,    2, 0x08 /* Private */,
      12,    1,   82,    2, 0x08 /* Private */,
      13,    1,   85,    2, 0x08 /* Private */,
      14,    1,   88,    2, 0x08 /* Private */,
      15,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,

       0        // eod
};

void accountInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<accountInfo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_returnBtn_clicked(); break;
        case 1: _t->startInit(); break;
        case 2: _t->getResponseReceived((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: _t->on_ExitBtn_clicked(); break;
        case 4: _t->on_update_clicked(); break;
        case 5: _t->patchResponseReceived((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 6: _t->on_PasswordLineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_NameLineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_SurnameLineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_EmailLineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->ft_checkEditLines(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject accountInfo::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_accountInfo.data,
    qt_meta_data_accountInfo,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *accountInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *accountInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_accountInfo.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int accountInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
