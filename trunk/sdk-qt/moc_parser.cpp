/****************************************************************************
** Meta object code from reading C++ file 'parser.h'
**
** Created: Wed Jul 30 09:20:29 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "parser.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Parser[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      12,    8,    7,    7, 0x05,
      33,    8,    7,    7, 0x05,
      54,    8,    7,    7, 0x05,
      91,    8,    7,    7, 0x05,
     108,    8,    7,    7, 0x05,
     137,    8,    7,    7, 0x05,
     164,    8,    7,    7, 0x05,
     193,    8,    7,    7, 0x05,
     214,    8,    7,    7, 0x05,
     255,    8,    7,    7, 0x05,
     288,    8,    7,    7, 0x05,
     331,    8,    7,    7, 0x05,
     366,    8,    7,    7, 0x05,
     391,    8,    7,    7, 0x05,
     408,    8,    7,    7, 0x05,
     433,    8,    7,    7, 0x05,
     450,    8,    7,    7, 0x05,
     491,    8,    7,    7, 0x05,
     524,    8,    7,    7, 0x05,
     553,    8,    7,    7, 0x05,
     574,    8,    7,    7, 0x05,
     619,    8,    7,    7, 0x05,
     656,    8,    7,    7, 0x05,
     673,    8,    7,    7, 0x05,
     706,    8,    7,    7, 0x05,
     723,    8,    7,    7, 0x05,
     744,    8,    7,    7, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Parser[] = {
    "Parser\0\0obj\0signalSchema(Schema)\0"
    "signalHeader(Header)\0"
    "signalMSG_VesselData(MSG_VesselData)\0"
    "signalBody(Body)\0signalVesselData(VesselData)\0"
    "signalPosReport(PosReport)\0"
    "signalStaticData(StaticData)\0"
    "signalVoyage(Voyage)\0"
    "signalMSG_LoginRequest(MSG_LoginRequest)\0"
    "signalLoginRequest(LoginRequest)\0"
    "signalMSG_LoginResponse(MSG_LoginResponse)\0"
    "signalLoginResponse(LoginResponse)\0"
    "signalMSG_Ping(MSG_Ping)\0signalPing(Ping)\0"
    "signalMSG_Pong(MSG_Pong)\0signalPong(Pong)\0"
    "signalMSG_ServerStatus(MSG_ServerStatus)\0"
    "signalServerStatus(ServerStatus)\0"
    "signalMSG_Logout(MSG_Logout)\0"
    "signalLogout(Logout)\0"
    "signalMSG_ServiceRequest(MSG_ServiceRequest)\0"
    "signalServiceRequest(ServiceRequest)\0"
    "signalArea(Area)\0signalTransmission(Transmission)\0"
    "signalItem(Item)\0signalObject(Object)\0"
    "signalPos(Pos)\0"
};

const QMetaObject Parser::staticMetaObject = {
    { &QXmlDefaultHandler::staticMetaObject, qt_meta_stringdata_Parser,
      qt_meta_data_Parser, 0 }
};

const QMetaObject *Parser::metaObject() const
{
    return &staticMetaObject;
}

void *Parser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Parser))
	return static_cast<void*>(const_cast< Parser*>(this));
    return QXmlDefaultHandler::qt_metacast(_clname);
}

int Parser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QXmlDefaultHandler::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signalSchema((*reinterpret_cast< Schema(*)>(_a[1]))); break;
        case 1: signalHeader((*reinterpret_cast< Header(*)>(_a[1]))); break;
        case 2: signalMSG_VesselData((*reinterpret_cast< MSG_VesselData(*)>(_a[1]))); break;
        case 3: signalBody((*reinterpret_cast< Body(*)>(_a[1]))); break;
        case 4: signalVesselData((*reinterpret_cast< VesselData(*)>(_a[1]))); break;
        case 5: signalPosReport((*reinterpret_cast< PosReport(*)>(_a[1]))); break;
        case 6: signalStaticData((*reinterpret_cast< StaticData(*)>(_a[1]))); break;
        case 7: signalVoyage((*reinterpret_cast< Voyage(*)>(_a[1]))); break;
        case 8: signalMSG_LoginRequest((*reinterpret_cast< MSG_LoginRequest(*)>(_a[1]))); break;
        case 9: signalLoginRequest((*reinterpret_cast< LoginRequest(*)>(_a[1]))); break;
        case 10: signalMSG_LoginResponse((*reinterpret_cast< MSG_LoginResponse(*)>(_a[1]))); break;
        case 11: signalLoginResponse((*reinterpret_cast< LoginResponse(*)>(_a[1]))); break;
        case 12: signalMSG_Ping((*reinterpret_cast< MSG_Ping(*)>(_a[1]))); break;
        case 13: signalPing((*reinterpret_cast< Ping(*)>(_a[1]))); break;
        case 14: signalMSG_Pong((*reinterpret_cast< MSG_Pong(*)>(_a[1]))); break;
        case 15: signalPong((*reinterpret_cast< Pong(*)>(_a[1]))); break;
        case 16: signalMSG_ServerStatus((*reinterpret_cast< MSG_ServerStatus(*)>(_a[1]))); break;
        case 17: signalServerStatus((*reinterpret_cast< ServerStatus(*)>(_a[1]))); break;
        case 18: signalMSG_Logout((*reinterpret_cast< MSG_Logout(*)>(_a[1]))); break;
        case 19: signalLogout((*reinterpret_cast< Logout(*)>(_a[1]))); break;
        case 20: signalMSG_ServiceRequest((*reinterpret_cast< MSG_ServiceRequest(*)>(_a[1]))); break;
        case 21: signalServiceRequest((*reinterpret_cast< ServiceRequest(*)>(_a[1]))); break;
        case 22: signalArea((*reinterpret_cast< Area(*)>(_a[1]))); break;
        case 23: signalTransmission((*reinterpret_cast< Transmission(*)>(_a[1]))); break;
        case 24: signalItem((*reinterpret_cast< Item(*)>(_a[1]))); break;
        case 25: signalObject((*reinterpret_cast< Object(*)>(_a[1]))); break;
        case 26: signalPos((*reinterpret_cast< Pos(*)>(_a[1]))); break;
        }
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void Parser::signalSchema(Schema _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Parser::signalHeader(Header _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Parser::signalMSG_VesselData(MSG_VesselData _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Parser::signalBody(Body _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Parser::signalVesselData(VesselData _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Parser::signalPosReport(PosReport _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Parser::signalStaticData(StaticData _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Parser::signalVoyage(Voyage _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Parser::signalMSG_LoginRequest(MSG_LoginRequest _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Parser::signalLoginRequest(LoginRequest _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Parser::signalMSG_LoginResponse(MSG_LoginResponse _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Parser::signalLoginResponse(LoginResponse _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Parser::signalMSG_Ping(MSG_Ping _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Parser::signalPing(Ping _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Parser::signalMSG_Pong(MSG_Pong _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void Parser::signalPong(Pong _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void Parser::signalMSG_ServerStatus(MSG_ServerStatus _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void Parser::signalServerStatus(ServerStatus _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void Parser::signalMSG_Logout(MSG_Logout _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void Parser::signalLogout(Logout _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void Parser::signalMSG_ServiceRequest(MSG_ServiceRequest _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void Parser::signalServiceRequest(ServiceRequest _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void Parser::signalArea(Area _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void Parser::signalTransmission(Transmission _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void Parser::signalItem(Item _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void Parser::signalObject(Object _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void Parser::signalPos(Pos _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}
QT_END_MOC_NAMESPACE
