/****************************************************************************
** Meta object code from reading C++ file 'mypushbutton.h'
**
** Created: Fri Nov 22 09:54:18 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../chatClient/mypushbutton.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mypushbutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyPushButton[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      39,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      58,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyPushButton[] = {
    "MyPushButton\0\0sendButtonIndex(QString)\0"
    "sendErrorMessage()\0buttonClicked()\0"
};

const QMetaObject MyPushButton::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyPushButton,
      qt_meta_data_MyPushButton, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyPushButton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyPushButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyPushButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyPushButton))
        return static_cast<void*>(const_cast< MyPushButton*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyPushButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendButtonIndex((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: sendErrorMessage(); break;
        case 2: buttonClicked(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MyPushButton::sendButtonIndex(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyPushButton::sendErrorMessage()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
