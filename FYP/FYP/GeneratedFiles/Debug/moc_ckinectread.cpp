/****************************************************************************
** Meta object code from reading C++ file 'ckinectread.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ckinectread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ckinectread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CKinectRead[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      27,   12,   12,   12, 0x08,
      40,   12,   12,   12, 0x08,
      49,   12,   12,   12, 0x08,
      67,   61,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CKinectRead[] = {
    "CKinectRead\0\0startRecord()\0stopRecord()\0"
    "insert()\0showGrade()\0index\0"
    "itemClicked(QModelIndex)\0"
};

void CKinectRead::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CKinectRead *_t = static_cast<CKinectRead *>(_o);
        switch (_id) {
        case 0: _t->startRecord(); break;
        case 1: _t->stopRecord(); break;
        case 2: _t->insert(); break;
        case 3: _t->showGrade(); break;
        case 4: _t->itemClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CKinectRead::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CKinectRead::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CKinectRead,
      qt_meta_data_CKinectRead, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CKinectRead::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CKinectRead::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CKinectRead::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CKinectRead))
        return static_cast<void*>(const_cast< CKinectRead*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CKinectRead::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
