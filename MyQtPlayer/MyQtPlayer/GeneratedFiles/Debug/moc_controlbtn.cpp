/****************************************************************************
** Meta object code from reading C++ file 'controlbtn.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../controlbtn.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controlbtn.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ControlBtn[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      41,   11,   11,   11, 0x08,
      63,   11,   11,   11, 0x08,
      85,   11,   11,   11, 0x08,
     107,   11,   11,   11, 0x08,
     134,  130,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ControlBtn[] = {
    "ControlBtn\0\0pos\0signal_playProgress(int)\0"
    "slot_btnPlayClicked()\0slot_btnNextClicked()\0"
    "slot_btnStopClicked()\0slot_btnPauseClicked()\0"
    "val\0slot_SliderChanged(int)\0"
};

void ControlBtn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ControlBtn *_t = static_cast<ControlBtn *>(_o);
        switch (_id) {
        case 0: _t->signal_playProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->slot_btnPlayClicked(); break;
        case 2: _t->slot_btnNextClicked(); break;
        case 3: _t->slot_btnStopClicked(); break;
        case 4: _t->slot_btnPauseClicked(); break;
        case 5: _t->slot_SliderChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ControlBtn::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ControlBtn::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ControlBtn,
      qt_meta_data_ControlBtn, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ControlBtn::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ControlBtn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ControlBtn::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ControlBtn))
        return static_cast<void*>(const_cast< ControlBtn*>(this));
    return QWidget::qt_metacast(_clname);
}

int ControlBtn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ControlBtn::signal_playProgress(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
