
#include "IVEF2voyage.h"

Voyage::Voyage() {

    m_sourceNamePresent = false;
    m_updateTimePresent = false;
    m_cargoTypePresent = false;
    m_cargoDescrPresent = false;
    m_cargoWeightPresent = false;
    m_loadedPresent = false;
    m_destCodePresent = false;
    m_destNamePresent = false;
    m_ETAPresent = false;
    m_ATAPresent = false;
    m_airDraughtPresent = false;
    m_draughtPresent = false;
    m_routePresent = false;
    m_personsOnBoardPresent = false;
    m_crewPresent = false;
    m_passengersPresent = false;
    m_supportPresent = false;
    m_tugsPresent = false;
}

Voyage::Voyage(const Voyage &val) : QObject() {

    m_taggedItemss = val.m_taggedItemss;
    m_waypointss = val.m_waypointss;
    m_id = val.m_id;
    m_sourceType = val.m_sourceType;
    m_sourceId = val.m_sourceId;
    m_sourceNamePresent = val.m_sourceNamePresent;
    m_sourceName = val.m_sourceName;
    m_updateTimePresent = val.m_updateTimePresent;
    m_updateTime = val.m_updateTime;
    m_cargoTypePresent = val.m_cargoTypePresent;
    m_cargoType = val.m_cargoType;
    m_cargoDescrPresent = val.m_cargoDescrPresent;
    m_cargoDescr = val.m_cargoDescr;
    m_cargoWeightPresent = val.m_cargoWeightPresent;
    m_cargoWeight = val.m_cargoWeight;
    m_loadedPresent = val.m_loadedPresent;
    m_loaded = val.m_loaded;
    m_destCodePresent = val.m_destCodePresent;
    m_destCode = val.m_destCode;
    m_destNamePresent = val.m_destNamePresent;
    m_destName = val.m_destName;
    m_ETAPresent = val.m_ETAPresent;
    m_ETA = val.m_ETA;
    m_ATAPresent = val.m_ATAPresent;
    m_ATA = val.m_ATA;
    m_airDraughtPresent = val.m_airDraughtPresent;
    m_airDraught = val.m_airDraught;
    m_draughtPresent = val.m_draughtPresent;
    m_draught = val.m_draught;
    m_routePresent = val.m_routePresent;
    m_route = val.m_route;
    m_personsOnBoardPresent = val.m_personsOnBoardPresent;
    m_personsOnBoard = val.m_personsOnBoard;
    m_crewPresent = val.m_crewPresent;
    m_crew = val.m_crew;
    m_passengersPresent = val.m_passengersPresent;
    m_passengers = val.m_passengers;
    m_supportPresent = val.m_supportPresent;
    m_support = val.m_support;
    m_tugsPresent = val.m_tugsPresent;
    m_tugs = val.m_tugs;
}

Voyage & Voyage::operator=(const Voyage &val) {

    m_taggedItemss = val.m_taggedItemss;
    m_waypointss = val.m_waypointss;
    m_id = val.m_id;
    m_sourceType = val.m_sourceType;
    m_sourceId = val.m_sourceId;
    m_sourceNamePresent = val.m_sourceNamePresent;
    m_sourceName = val.m_sourceName;
    m_updateTimePresent = val.m_updateTimePresent;
    m_updateTime = val.m_updateTime;
    m_cargoTypePresent = val.m_cargoTypePresent;
    m_cargoType = val.m_cargoType;
    m_cargoDescrPresent = val.m_cargoDescrPresent;
    m_cargoDescr = val.m_cargoDescr;
    m_cargoWeightPresent = val.m_cargoWeightPresent;
    m_cargoWeight = val.m_cargoWeight;
    m_loadedPresent = val.m_loadedPresent;
    m_loaded = val.m_loaded;
    m_destCodePresent = val.m_destCodePresent;
    m_destCode = val.m_destCode;
    m_destNamePresent = val.m_destNamePresent;
    m_destName = val.m_destName;
    m_ETAPresent = val.m_ETAPresent;
    m_ETA = val.m_ETA;
    m_ATAPresent = val.m_ATAPresent;
    m_ATA = val.m_ATA;
    m_airDraughtPresent = val.m_airDraughtPresent;
    m_airDraught = val.m_airDraught;
    m_draughtPresent = val.m_draughtPresent;
    m_draught = val.m_draught;
    m_routePresent = val.m_routePresent;
    m_route = val.m_route;
    m_personsOnBoardPresent = val.m_personsOnBoardPresent;
    m_personsOnBoard = val.m_personsOnBoard;
    m_crewPresent = val.m_crewPresent;
    m_crew = val.m_crew;
    m_passengersPresent = val.m_passengersPresent;
    m_passengers = val.m_passengers;
    m_supportPresent = val.m_supportPresent;
    m_support = val.m_support;
    m_tugsPresent = val.m_tugsPresent;
    m_tugs = val.m_tugs;
    return *this;
}

void Voyage::addTaggedItems(TaggedItems val) {

    m_taggedItemss.append(val);
}

TaggedItems Voyage::getTaggedItemsAt(int i) const {

    return m_taggedItemss.at(i);
}

int Voyage::countOfTaggedItemss() const {

    return m_taggedItemss.count();
}

void Voyage::addWaypoints(Waypoints val) {

    m_waypointss.append(val);
}

Waypoints Voyage::getWaypointsAt(int i) const {

    return m_waypointss.at(i);
}

int Voyage::countOfWaypointss() const {

    return m_waypointss.count();
}

void Voyage::setId(QString val) {

    m_id = val;
}

QString Voyage::getId() const {

    return m_id;
}

void Voyage::setSourceType(int val) {

    if ( ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) )
        return;
    m_sourceType = val;
}

int Voyage::getSourceType() const {

    return m_sourceType;
}

void Voyage::setSourceId(int val) {

    m_sourceId = val;
}

int Voyage::getSourceId() const {

    return m_sourceId;
}

void Voyage::setSourceName(QString val) {

    m_sourceNamePresent = true;
    m_sourceName = val;
}

QString Voyage::getSourceName() const {

    return m_sourceName;
}

bool Voyage::hasSourceName() {

    return m_sourceNamePresent;
}

void Voyage::setUpdateTime(QDateTime val) {

    m_updateTimePresent = true;
    m_updateTime = val;
}

QDateTime Voyage::getUpdateTime() const {

    return m_updateTime;
}

bool Voyage::hasUpdateTime() {

    return m_updateTimePresent;
}

void Voyage::setCargoType(int val) {

    if ( ( val != 0 ) &&
         ( val != 1 ) &&
         ( val != 2 ) &&
         ( val != 3 ) &&
         ( val != 4 ) &&
         ( val != 9 ) )
        return;
    m_cargoTypePresent = true;
    m_cargoType = val;
}

int Voyage::getCargoType() const {

    return m_cargoType;
}

bool Voyage::hasCargoType() {

    return m_cargoTypePresent;
}

void Voyage::setCargoDescr(QString val) {

    m_cargoDescrPresent = true;
    m_cargoDescr = val;
}

QString Voyage::getCargoDescr() const {

    return m_cargoDescr;
}

bool Voyage::hasCargoDescr() {

    return m_cargoDescrPresent;
}

void Voyage::setCargoWeight(int val) {

    m_cargoWeightPresent = true;
    m_cargoWeight = val;
}

int Voyage::getCargoWeight() const {

    return m_cargoWeight;
}

bool Voyage::hasCargoWeight() {

    return m_cargoWeightPresent;
}

void Voyage::setLoaded(bool val) {

    m_loadedPresent = true;
    m_loaded = val;
}

bool Voyage::getLoaded() const {

    return m_loaded;
}

bool Voyage::hasLoaded() {

    return m_loadedPresent;
}

void Voyage::setDestCode(QString val) {

    m_destCodePresent = true;
    m_destCode = val;
}

QString Voyage::getDestCode() const {

    return m_destCode;
}

bool Voyage::hasDestCode() {

    return m_destCodePresent;
}

void Voyage::setDestName(QString val) {

    m_destNamePresent = true;
    m_destName = val;
}

QString Voyage::getDestName() const {

    return m_destName;
}

bool Voyage::hasDestName() {

    return m_destNamePresent;
}

void Voyage::setETA(QDateTime val) {

    m_ETAPresent = true;
    m_ETA = val;
}

QDateTime Voyage::getETA() const {

    return m_ETA;
}

bool Voyage::hasETA() {

    return m_ETAPresent;
}

void Voyage::setATA(QDateTime val) {

    m_ATAPresent = true;
    m_ATA = val;
}

QDateTime Voyage::getATA() const {

    return m_ATA;
}

bool Voyage::hasATA() {

    return m_ATAPresent;
}

void Voyage::setAirDraught(float val) {

    m_airDraughtPresent = true;
    m_airDraught = val;
}

float Voyage::getAirDraught() const {

    return m_airDraught;
}

bool Voyage::hasAirDraught() {

    return m_airDraughtPresent;
}

void Voyage::setDraught(float val) {

    m_draughtPresent = true;
    m_draught = val;
}

float Voyage::getDraught() const {

    return m_draught;
}

bool Voyage::hasDraught() {

    return m_draughtPresent;
}

void Voyage::setRoute(QString val) {

    m_routePresent = true;
    m_route = val;
}

QString Voyage::getRoute() const {

    return m_route;
}

bool Voyage::hasRoute() {

    return m_routePresent;
}

void Voyage::setPersonsOnBoard(float val) {

    m_personsOnBoardPresent = true;
    m_personsOnBoard = val;
}

float Voyage::getPersonsOnBoard() const {

    return m_personsOnBoard;
}

bool Voyage::hasPersonsOnBoard() {

    return m_personsOnBoardPresent;
}

void Voyage::setCrew(float val) {

    m_crewPresent = true;
    m_crew = val;
}

float Voyage::getCrew() const {

    return m_crew;
}

bool Voyage::hasCrew() {

    return m_crewPresent;
}

void Voyage::setPassengers(float val) {

    m_passengersPresent = true;
    m_passengers = val;
}

float Voyage::getPassengers() const {

    return m_passengers;
}

bool Voyage::hasPassengers() {

    return m_passengersPresent;
}

void Voyage::setSupport(float val) {

    m_supportPresent = true;
    m_support = val;
}

float Voyage::getSupport() const {

    return m_support;
}

bool Voyage::hasSupport() {

    return m_supportPresent;
}

void Voyage::setTugs(float val) {

    m_tugsPresent = true;
    m_tugs = val;
}

float Voyage::getTugs() const {

    return m_tugs;
}

bool Voyage::hasTugs() {

    return m_tugsPresent;
}

QString Voyage::toXML() {

    QString xml = "<Voyage";
    xml.append(" Id=\"" + m_id + "\"");
    xml.append(" SourceType=\"" + QString::number(m_sourceType) + "\"");
    xml.append(" SourceId=\"" + QString::number(m_sourceId) + "\"");
    if ( hasSourceName() ) {
        xml.append(" SourceName=\"" + m_sourceName + "\"");
    }
    if ( hasUpdateTime() ) {
        xml.append(" UpdateTime=\"" + m_updateTime.toString("yyyy-MM-ddThh:mm:ss.zzz") + "\"");
    }
    if ( hasCargoType() ) {
        xml.append(" CargoType=\"" + QString::number(m_cargoType) + "\"");
    }
    if ( hasCargoDescr() ) {
        xml.append(" CargoDescr=\"" + m_cargoDescr + "\"");
    }
    if ( hasCargoWeight() ) {
        xml.append(" CargoWeight=\"" + QString::number(m_cargoWeight) + "\"");
    }
    if ( hasLoaded() ) {
        xml.append(" Loaded=\"" + QString::number(m_loaded) + "\"");
    }
    if ( hasDestCode() ) {
        xml.append(" DestCode=\"" + m_destCode + "\"");
    }
    if ( hasDestName() ) {
        xml.append(" DestName=\"" + m_destName + "\"");
    }
    if ( hasETA() ) {
        xml.append(" ETA=\"" + m_ETA.toString("yyyy-MM-ddThh:mm:ss.zzz") + "\"");
    }
    if ( hasATA() ) {
        xml.append(" ATA=\"" + m_ATA.toString("yyyy-MM-ddThh:mm:ss.zzz") + "\"");
    }
    if ( hasAirDraught() ) {
        xml.append(" AirDraught=\"" + QString::number(m_airDraught) + "\"");
    }
    if ( hasDraught() ) {
        xml.append(" Draught=\"" + QString::number(m_draught) + "\"");
    }
    if ( hasRoute() ) {
        xml.append(" Route=\"" + m_route + "\"");
    }
    if ( hasPersonsOnBoard() ) {
        xml.append(" PersonsOnBoard=\"" + QString::number(m_personsOnBoard) + "\"");
    }
    if ( hasCrew() ) {
        xml.append(" Crew=\"" + QString::number(m_crew) + "\"");
    }
    if ( hasPassengers() ) {
        xml.append(" Passengers=\"" + QString::number(m_passengers) + "\"");
    }
    if ( hasSupport() ) {
        xml.append(" Support=\"" + QString::number(m_support) + "\"");
    }
    if ( hasTugs() ) {
        xml.append(" Tugs=\"" + QString::number(m_tugs) + "\"");
    }
    xml.append(">\n");
    for(int i=0; i < m_taggedItemss.count(); i++ ) {
       TaggedItems attribute = m_taggedItemss.at(i);
        xml.append( attribute.toXML() );
    }
    for(int i=0; i < m_waypointss.count(); i++ ) {
       Waypoints attribute = m_waypointss.at(i);
        xml.append( attribute.toXML() );
    }
    xml.append( "</Voyage>\n");
    return xml;
}

QString Voyage::toString(QString lead) {

    QString str = lead + "Voyage\n";
    str.append( lead + "    Id = " + m_id + "\n");
    str.append( lead + "    SourceType = " + QString::number(m_sourceType) + "\n");
    str.append( lead + "    SourceId = " + QString::number(m_sourceId) + "\n");
    if ( hasSourceName() ) {
        str.append( lead + "    SourceName = " + m_sourceName + "\n");
    }
    if ( hasUpdateTime() ) {
        str.append( lead + "    UpdateTime = " + m_updateTime.toString("yyyy-MM-ddThh:mm:ss.zzz") + "\n");
    }
    if ( hasCargoType() ) {
        str.append( lead + "    CargoType = " + QString::number(m_cargoType) + "\n");
    }
    if ( hasCargoDescr() ) {
        str.append( lead + "    CargoDescr = " + m_cargoDescr + "\n");
    }
    if ( hasCargoWeight() ) {
        str.append( lead + "    CargoWeight = " + QString::number(m_cargoWeight) + "\n");
    }
    if ( hasLoaded() ) {
        str.append( lead + "    Loaded = " + QString::number(m_loaded) + "\n");
    }
    if ( hasDestCode() ) {
        str.append( lead + "    DestCode = " + m_destCode + "\n");
    }
    if ( hasDestName() ) {
        str.append( lead + "    DestName = " + m_destName + "\n");
    }
    if ( hasETA() ) {
        str.append( lead + "    ETA = " + m_ETA.toString("yyyy-MM-ddThh:mm:ss.zzz") + "\n");
    }
    if ( hasATA() ) {
        str.append( lead + "    ATA = " + m_ATA.toString("yyyy-MM-ddThh:mm:ss.zzz") + "\n");
    }
    if ( hasAirDraught() ) {
        str.append( lead + "    AirDraught = " + QString::number(m_airDraught) + "\n");
    }
    if ( hasDraught() ) {
        str.append( lead + "    Draught = " + QString::number(m_draught) + "\n");
    }
    if ( hasRoute() ) {
        str.append( lead + "    Route = " + m_route + "\n");
    }
    if ( hasPersonsOnBoard() ) {
        str.append( lead + "    PersonsOnBoard = " + QString::number(m_personsOnBoard) + "\n");
    }
    if ( hasCrew() ) {
        str.append( lead + "    Crew = " + QString::number(m_crew) + "\n");
    }
    if ( hasPassengers() ) {
        str.append( lead + "    Passengers = " + QString::number(m_passengers) + "\n");
    }
    if ( hasSupport() ) {
        str.append( lead + "    Support = " + QString::number(m_support) + "\n");
    }
    if ( hasTugs() ) {
        str.append( lead + "    Tugs = " + QString::number(m_tugs) + "\n");
    }
    for(int i=0; i < m_taggedItemss.count(); i++ ) {
       TaggedItems attribute = m_taggedItemss.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    for(int i=0; i < m_waypointss.count(); i++ ) {
       Waypoints attribute = m_waypointss.at(i);
       str.append( attribute.toString(lead + "    ") );
    }
    return str;
}

