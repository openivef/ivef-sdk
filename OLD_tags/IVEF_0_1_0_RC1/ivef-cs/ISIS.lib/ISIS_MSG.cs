//------------------------------------------------------------------------------
//   this. code is compliant to the ISIS 1.1 specificication
//
// 	 Date : 2008-07-24
//	 Author : Richard jonker
// 	
// 	 this. software is free software: you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation, either version 3 of the License, or
//   (at your option) any later version.
//------------------------------------------------------------------------------

using System.Xml.Serialization;
using System;


namespace ISIS.lib
{
    [System.SerializableAttribute()]
    public enum YesNo
	{
        [XmlEnumAttribute("no")]  No = 0,
        [XmlEnumAttribute("yes")] Yes = 1,
    }
    
//[XmlRootAttribute(Namespace = "urn:http://www.hitt.nl/XMLSchema/ISIS/1.1", IsNullable = false)]
    [System.SerializableAttribute()]
    public class MSG_Base
    {
        private Header headerField = new Header();

        [XmlElement]
        public Header Header
        {
            get { return this.headerField; }
            set { this.headerField = value; }
        }
    }

    #region Header
    // Header information as used in all messages
    [System.SerializableAttribute()]
    [XmlRootAttribute(Namespace="urn:http://www.hitt.nl/XMLSchema/ISIS/1.1", IsNullable=false)]
    public class Header 
	{
        private string versionField = ISIS_Constants.Version;
        private string msgRefIdField = System.Guid.NewGuid().ToString("P");
        
        [XmlAttributeAttribute]
        public string Version 
        {
            get { return this.versionField;  }
            set { this.versionField = value; }
        }
        
        [XmlAttributeAttribute]
        public string MsgRefId 
	    {
            get { return this.msgRefIdField; }
            set { this.msgRefIdField = value; }
        }
    }
    #endregion


    #region MSG_VesselData

    [System.SerializableAttribute()]
    [XmlRootAttribute(Namespace="urn:http://www.hitt.nl/XMLSchema/ISIS/1.1", IsNullable=false)] 
    public class MSG_VesselData : MSG_Base
	{
        private VesselData[] bodyField = null;
        
        [XmlArrayItemAttribute("VesselData", IsNullable=false)]
        public VesselData[] Body 
	    {
            get { return this.bodyField; }
            set { this.bodyField = value; }
        }
    }

    [System.SerializableAttribute()]
    [XmlRootAttribute(Namespace="urn:http://www.hitt.nl/XMLSchema/ISIS/1.1", IsNullable=false)]
    public class VesselData
	{
        private PosReport posReportField = null;
        private StaticData[] staticDataField = null;
        private Voyage[] voyageField = null;
        
        public PosReport PosReport 
	    {
            get { return this.posReportField; }
            set { this.posReportField = value; }
        }
        
        [XmlElementAttribute("StaticData")]
        public StaticData[] StaticData 
	    {
            get { return this.staticDataField; }
            set { this.staticDataField = value; }
        }
        
        [XmlElementAttribute("Voyage")]
        public Voyage[] Voyage 
	    {
            get { return this.voyageField; }
            set { this.voyageField = value; }
        }
    }

    #region position

    [System.SerializableAttribute()]
    [XmlRootAttribute(Namespace="urn:http://www.hitt.nl/XMLSchema/ISIS/1.1", IsNullable=false)]
    public class PosReport 
	{
        private Pos posField;
        private int idField;
        private bool idFieldSpecified = false;
        private int sourceIdField;
        private bool sourceIdSpecified = false;
        private DateTime updateTimeField;
        private bool updateTimeFieldSpecified = false;
        private decimal sOGField;
        private bool sOGFieldSpecified = false;
        private decimal cOGField;
        private bool cOGFieldSpecified = false;
        private decimal rateOfTurnField;
        private bool rateOfTurnFieldSpecified;        
        private YesNo lostField;
        private bool lostFieldSpecified = false; 
        private decimal orientationField;
        private bool orientationFieldSpecified = false;
        private decimal lengthField;
        private bool lengthFieldSpecified = false;
        private decimal breadthField;
        private bool breadthFieldSpecified = false;
        private decimal altitudeField;
        private bool altitudeFieldSpecified;
        private PosReportNavStatus navStatusField;
        private bool navStatusFieldSpecified = false;
        private PosReportUpdSensorType updSensorTypeField;
        private bool updSensorTypeFieldSpecified = false;
        private bool aTONOffPosField;
        private bool aTONOffPosFieldSpecified = false;
        
        public Pos Pos 
	    {
            get { return this.posField; }
            set { this.posField = value; }
        }
        
        [XmlAttribute]
        public int Id 
	    {
            get { return this.idField; }
            set { this.idField = value; this.idFieldSpecified = true; }
        }
        [XmlIgnoreAttribute()]
        public bool IdSpecified
        {
            get { return this.idFieldSpecified; }
            set { this.idFieldSpecified = value; }
        }

        [XmlAttribute]
        public int SourceId 
	    {
            get { return this.sourceIdField; }
            set { this.sourceIdField = value; this.sourceIdSpecified = true; }
        }
        [XmlIgnoreAttribute()]
        public bool SourceIdSpecified
        {
            get { return this.sourceIdSpecified; }
            set { this.sourceIdSpecified = value; }
        }
        
        [XmlAttribute]
        public DateTime UpdateTime 
	    {
            get { return this.updateTimeField; }
            set { this.updateTimeField = value; this.updateTimeFieldSpecified = true; }
        }
        [XmlIgnoreAttribute()]
        public bool UpdateTimeSpecified
        {
            get { return this.updateTimeFieldSpecified; }
            set { this.updateTimeFieldSpecified = value; }
        }
        
        [XmlAttribute]
        public decimal SOG 
	    {
            get { return this.sOGField; }
            set { this.sOGField = value; this.sOGFieldSpecified = true; }
        }
        [XmlIgnoreAttribute()]
        public bool SOGSpecified
        {
            get { return this.sOGFieldSpecified; }
            set { this.sOGFieldSpecified = value; }
        }
        
        [XmlAttribute]
        public decimal COG 
	    {
            get { return this.cOGField; }
            set { this.cOGField = value; this.cOGFieldSpecified = true; }
        }
        [XmlIgnoreAttribute()]
        public bool COGSpecified
        {
            get { return this.cOGFieldSpecified; }
            set { this.cOGFieldSpecified = value; }
        }
        
        [XmlAttribute]
        public YesNo Lost 
	    {
            get { return this.lostField; }
            set { this.lostField = value; this.lostFieldSpecified = true; }
        }
        [XmlIgnoreAttribute()]
        public bool LostSpecified
        {
            get { return this.lostFieldSpecified; }
            set { this.lostFieldSpecified = value; }
        }
        
        [XmlAttribute]
        public decimal RateOfTurn 
	    {
            get { return this.rateOfTurnField; }
            set { this.rateOfTurnField = value; this.rateOfTurnFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool RateOfTurnSpecified
        {
            get { return this.rateOfTurnFieldSpecified; }
            set { this.rateOfTurnFieldSpecified = value; }
        }
        
        [XmlAttribute]
        public decimal Orientation 
	    {
            get { return this.orientationField; }
            set { this.orientationField = value; this.orientationFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool OrientationSpecified
        {
            get { return this.orientationFieldSpecified; }
            set { this.orientationFieldSpecified = value; }
        }
        
        [XmlAttribute]
        public decimal Length 
	    {
            get { return this.lengthField; }
            set { this.lengthField = value; this.lengthFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool LengthSpecified
        {
            get { return this.lengthFieldSpecified; }
            set { this.lengthFieldSpecified = value; }
        }
        
        [XmlAttribute]
        public decimal Breadth 
	    {
            get { return this.breadthField; }
            set { this.breadthField = value; this.breadthFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool BreadthSpecified
        {
            get { return this.breadthFieldSpecified; }
            set { this.breadthFieldSpecified = value; }
        }
        
        [XmlAttribute]
        public decimal Altitude 
	    {
            get { return this.altitudeField; }
            set { this.altitudeField = value; this.altitudeFieldSpecified = true; }
        }

        [XmlIgnoreAttribute]
        public bool AltitudeSpecified
        {
            get { return this.altitudeFieldSpecified; }
            set { this.altitudeFieldSpecified = value; }
        }
        
        [XmlAttribute]
        public PosReportNavStatus NavStatus 
	    {
            get { return this.navStatusField; }
            set { this.navStatusField = value; this.navStatusFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool NavStatusSpecified
        {
            get { return this.navStatusFieldSpecified; }
            set { this.navStatusFieldSpecified = value; }
        }
        
        [XmlAttribute]
        public PosReportUpdSensorType UpdSensorType 
	    {
            get { return this.updSensorTypeField; }
            set { this.updSensorTypeField = value; this.updSensorTypeFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool UpdSensorTypeSpecified
        {
            get { return this.updSensorTypeFieldSpecified; }
            set { this.updSensorTypeFieldSpecified = value; }
        }
        
        [XmlAttribute]
        public bool ATONOffPos 
	    {
            get { return this.aTONOffPosField; }
            set { this.aTONOffPosField = value; this.aTONOffPosFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool ATONOffPosSpecified
        {
            get { return this.aTONOffPosFieldSpecified; }
            set { this.aTONOffPosFieldSpecified = value; }
        }
    }

    [System.SerializableAttribute()]
    [XmlRootAttribute(Namespace="urn:http://www.hitt.nl/XMLSchema/ISIS/1.1", IsNullable=false)]
    public class Pos 
    {
        private decimal latField;
        private decimal longField;
        
        [XmlAttribute]
        public decimal Latitude 
	    {
		    get { return this.latField;}
		    set { this.latField = value; }
        }
        
        [XmlAttribute]
        public decimal Longitude 
	    {
		    get { return this.longField;}
		    set { this.longField = value; }
        }
    }

    /// <summary>
    /// 0 = under way using engine
    /// 1 = at anchor
    /// 2 = not under command
    /// 3 = restricted manoeuvrability
    /// 4 = constrained by her draught
    /// 5 = moored
    /// 6 = aground
    /// 7 = engaged in fishing
    /// 8 = under way sailing
    /// 9 - 14 = reserved for future use
    /// 15 = undefined default
    /// </summary>
    [System.SerializableAttribute()]
    public enum PosReportNavStatus 
	{
        [XmlEnumAttribute("0")]        Underway = 0,
        [XmlEnumAttribute("1")]        AtAnchor = 1,
        [XmlEnumAttribute("2")]        NotUnderCommand = 2,
        [XmlEnumAttribute("3")]        Restrictedmanoeuvrability = 3,
        [XmlEnumAttribute("4")]        ContraintedByDraught = 4,
        [XmlEnumAttribute("5")]        Moored = 5,
        [XmlEnumAttribute("6")]        Aground = 6,
        [XmlEnumAttribute("7")]        Fishing = 7,
        [XmlEnumAttribute("8")]        Sailing = 8,
        [XmlEnumAttribute("9")]        _FutureUse = 9,
        [XmlEnumAttribute("10")]       _FutureUse10 = 10,
        [XmlEnumAttribute("11")]       _FutureUse11 = 11,
        [XmlEnumAttribute("12")]       _FutureUse12 = 12,
        [XmlEnumAttribute("13")]       _FutureUse13 = 13,
        [XmlEnumAttribute("14")]       _FutureUse14 = 14,
        [XmlEnumAttribute("15")]       Undefined = 15,
    }

    [System.SerializableAttribute()]
    public enum PosReportUpdSensorType 
	{
        [XmlEnumAttribute("1")]        Radar = 1,
        [XmlEnumAttribute("2")]        AIS = 2,
        [XmlEnumAttribute("3")]        AIS_Radar = 3,
        [XmlEnumAttribute("4")]        DeadReckoning = 4,
    }
    #endregion

    #region static data

    [System.SerializableAttribute()]
    [XmlRootAttribute(Namespace="urn:http://www.hitt.nl/XMLSchema/ISIS/1.1", IsNullable=false)]
    public partial class StaticData 
	{
        private int idField;
        private string sourceNameField;
        private StaticDataSource sourceField;
        private decimal lengthField = decimal.MinValue;
        private bool lengthFieldSpecified;
        private decimal breadthField;
        private bool breadthFieldSpecified;             //@@@@ beam ?
        private string callsignField;
        private string shipNameField;
        private StaticDataObjectType objectTypeField;
        private bool objectTypeFieldSpecified;
        private StaticDataShipType shipTypeField;
        private bool shipTypeFieldSpecified;
        private int iMOField;
        private int mMSIField;
        private StaticDataATONType aTONTypeField;
        private bool aTONTypeFieldSpecified;
        private string aTONNameField;
        private decimal antPosDistFromFrontField;
        private bool antPosDistFromFrontFieldSpecified;
        private decimal antPosDistFromLeftField;
        private bool antPosDistFromLeftFieldSpecified;
        private string natLangShipNameField;
        private string portOfRegistryField;
        private string countryFlagField;
        private decimal maxAirDraughtField;
        private bool maxAirDraughtFieldSpecified;
        private decimal maxDraughtField;
        private bool maxDraughtFieldSpecified;
        private YesNo deepWaterVesselindField;
        private bool deepWaterVesselindFieldSpecified;

        [XmlAttribute]
        public int Id
        {
            get { return this.idField; }
            set { this.idField = value; }
        }

        [XmlAttribute()]
        public string SourceName
        {
            get { return this.sourceNameField; }
            set { this.sourceNameField = value; }
        }

        [XmlAttribute()]
        public StaticDataSource Source
        {
            get { return this.sourceField; }
            set { this.sourceField = value; }
        }

        [XmlAttribute()]
        public decimal Length
        {
            get { return this.lengthField; }
            set { this.lengthField = value; this.lengthFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool LengthSpecified
        {
            get { return this.lengthFieldSpecified; }
            set { this.lengthFieldSpecified = value; }
        }

        [XmlAttribute()]
        public decimal Breadth                          /// @@@ Breadth -> Beam
        {
            get { return this.breadthField; }
            set { this.breadthField = value; this.breadthFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool BreadthSpecified
        {
            get { return this.breadthFieldSpecified; }
            set { this.breadthFieldSpecified = value; }
        }
        
        [XmlAttribute()]
        public string Callsign 
        {
            get { return this.callsignField;}
            set { this.callsignField = value; }
        }
        
        [XmlAttribute()]
        public string ShipName 
        {
            get { return this.shipNameField;}
            set { this.shipNameField = value; }
        }
        
        [XmlAttribute()]
        public StaticDataObjectType ObjectType 
        {
            get { return this.objectTypeField;}
            set { this.objectTypeField = value; this.objectTypeFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool ObjectTypeSpecified
        {
            get { return this.objectTypeFieldSpecified; }
            set { this.objectTypeFieldSpecified = value; }
        }
        
        [XmlAttribute()]
        public StaticDataShipType ShipType 
        {
            get { return this.shipTypeField;}
            set { this.shipTypeField = value; this.shipTypeFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool ShipTypeSpecified
        {
            get { return this.shipTypeFieldSpecified; }
            set { this.shipTypeFieldSpecified = value; }
        }
        
        [XmlAttribute]
        public int IMO 
        {
            get { return this.iMOField; }
            set { this.iMOField = value; }
        }
        
        [XmlAttribute]
        public int MMSI 
	    {
		    get { return this.mMSIField; }
		    set { this.mMSIField = value; }
        }
        
        [XmlAttribute()]
        public StaticDataATONType ATONType 
        {
		    get { return this.aTONTypeField; }
            set { this.aTONTypeField = value; this.aTONTypeFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool ATONTypeSpecified
        {
            get { return this.aTONTypeFieldSpecified; }
            set { this.aTONTypeFieldSpecified = value; }
        }
        
        [XmlAttribute()]
        public  string ATONName 
	    {
            
		    get { return this.aTONNameField;}
		    set { this.aTONNameField = value; }
        }
        
        [XmlAttribute()]
        public  decimal AntPosDistFromFront 
	    {
            
		    get { return this.antPosDistFromFrontField;}
            set { this.antPosDistFromFrontField = value; this.antPosDistFromFrontFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool AntPosDistFromFrontSpecified
        {

            get { return this.antPosDistFromFrontFieldSpecified; }
            set { this.antPosDistFromFrontFieldSpecified = value; }
        }
        
        [XmlAttribute()]
        public  decimal AntPosDistFromLeft 
	    {
            
		    get { return this.antPosDistFromLeftField;}
            set { this.antPosDistFromLeftField = value; this.antPosDistFromLeftFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool AntPosDistFromLeftSpecified
        {

            get { return this.antPosDistFromLeftFieldSpecified; }
            set { this.antPosDistFromLeftFieldSpecified = value; }
        }
        
        [XmlAttribute()]
        public  string NatLangShipName 
	    {
            
		    get { return this.natLangShipNameField;}
		    set { this.natLangShipNameField = value; }
        }
        
        [XmlAttribute()]
        public  string PortOfRegistry 
	    {
            
		    get { return this.portOfRegistryField;}
		    set { this.portOfRegistryField = value; }
        }
        
        [XmlAttribute()]
        public  string CountryFlag 
	    {
            
		    get { return this.countryFlagField;}
		    set { this.countryFlagField = value; }
        }
        
        [XmlAttribute()]
        public  decimal MaxAirDraught 
	    {
            
		    get { return this.maxAirDraughtField;}
            set { this.maxAirDraughtField = value; this.maxAirDraughtFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool MaxAirDraughtSpecified
        {
            get { return this.maxAirDraughtFieldSpecified; }
            set { this.maxAirDraughtFieldSpecified = value; }
        }
        
        [XmlAttribute()]
        public  decimal MaxDraught 
	    {
		    get { return this.maxDraughtField;}
            set { this.maxDraughtField = value; this.maxDraughtFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool MaxDraughtSpecified
        {
            get { return this.maxDraughtFieldSpecified; }
            set { this.maxDraughtFieldSpecified = value; }
        }
        
        [XmlAttribute()]
        public  YesNo DeepWaterVesselind 
	    {
		    get { return this.deepWaterVesselindField;}
            set { this.deepWaterVesselindField = value; this.deepWaterVesselindFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool DeepWaterVesselindSpecified
        {
            get { return this.deepWaterVesselindFieldSpecified; }
            set { this.deepWaterVesselindFieldSpecified = value; }
        }
    }

    [System.SerializableAttribute()]
    public  enum StaticDataObjectType 
	{
        [XmlEnumAttribute("1")]        Aircraft = 1,
        [XmlEnumAttribute("2")]        Vessel = 2,
        [XmlEnumAttribute("3")]        Vehicle = 3,  // not an aircraft or vessel
        [XmlEnumAttribute("4")]        BaseStation =4,
        [XmlEnumAttribute("5")]        AidsToNavigate = 5,
        [XmlEnumAttribute("6")]        VirtualAidsToNavigate = 6,
        [XmlEnumAttribute("7")]        FieldTransponder = 7,
    }

    [System.SerializableAttribute()]
    public  enum StaticDataShipType 
	{
        [XmlEnumAttribute("20")]        WIG = 20,
        [XmlEnumAttribute("30")]        FishingVessel = 30,
        [XmlEnumAttribute("31")]        TowingVessel = 31,                  // @@@ is dit niet een tug
        [XmlEnumAttribute("32")]        LargeTowingVessel = 32,             // @@@ TuG
        [XmlEnumAttribute("33")]        DredgingVessel = 33,
        [XmlEnumAttribute("34")]        DivingVessel = 34,
        [XmlEnumAttribute("35")]        MiltaryVessel = 35,
        [XmlEnumAttribute("36")]        SailingVessel = 36,
        [XmlEnumAttribute("37")]        PleasureCraft = 37,
        [XmlEnumAttribute("40")]        HighSpeedCraft = 40,
        [XmlEnumAttribute("50")]        PilotsVessel = 50,
        [XmlEnumAttribute("51")]        SAR = 51,
        [XmlEnumAttribute("52")]        Tug = 52,
        [XmlEnumAttribute("53")]        PortTender = 53,
        [XmlEnumAttribute("54")]        AntiPolutionVessel = 54,
        [XmlEnumAttribute("55")]        LawEnforcementVessel = 55,
        [XmlEnumAttribute("58")]        MedicalVessel = 58,
        [XmlEnumAttribute("59")]        Mob83Vessel = 59,
        [XmlEnumAttribute("60")]        PassengerShip = 60,
        [XmlEnumAttribute("70")]        CargoShip = 70,
        [XmlEnumAttribute("80")]        Tanker = 80,
        [XmlEnumAttribute("90")]        Other = 90,
    }

    [System.SerializableAttribute()]
    public  enum StaticDataATONType 
    {
        [XmlEnumAttribute("0")]        Unknown = 0,
        
        [XmlEnumAttribute("1")]        UnknownFixed = 1,
        [XmlEnumAttribute("2")]        UnknowFloating = 2,
        [XmlEnumAttribute("3")]        FixedOffShoreStructure = 3,
        [XmlEnumAttribute("5")]        LightWithoutSectors = 5,
        [XmlEnumAttribute("6")]        LightWithSectors = 6,
        [XmlEnumAttribute("7")]        LeadingLightFront = 7,
        [XmlEnumAttribute("8")]        LeadingLightRear = 8,
        [XmlEnumAttribute("9")]        BeaconCardinalN = 9,
        [XmlEnumAttribute("10")]       BeaconCardinalE = 10,
        [XmlEnumAttribute("11")]       BeaconCardinalS = 11,
        [XmlEnumAttribute("12")]       BeaconCardinalW = 12,
        [XmlEnumAttribute("13")]       BeaconPort = 13,
        [XmlEnumAttribute("14")]       BeaconStarboard = 14,
        [XmlEnumAttribute("15")]       BeaconPrefferedPort = 15,
        [XmlEnumAttribute("16")]       BeaconPrefferedStarboard = 16,
        [XmlEnumAttribute("17")]       BeaconIsolatedDanger = 17,
        [XmlEnumAttribute("18")]       BeaconSafeWater = 18,
        [XmlEnumAttribute("19")]       BeaconSpecialMark = 19,
        [XmlEnumAttribute("20")]       CardinalMarkN = 20,
        [XmlEnumAttribute("21")]       CardinalMarkE = 21,
        [XmlEnumAttribute("22")]       CardinalMarkS = 22,
        [XmlEnumAttribute("23")]       CardinalMarkW = 23,
        [XmlEnumAttribute("24")]       PortMark = 24,
        [XmlEnumAttribute("25")]       StarboardMark = 25,
        [XmlEnumAttribute("26")]       PrefferedPort = 26,
        [XmlEnumAttribute("27")]       PrefferedStarboard = 27,
        [XmlEnumAttribute("28")]       IsolatedDanger = 28,
        [XmlEnumAttribute("29")]       SafeWater = 29,
        [XmlEnumAttribute("30")]       SpecialMark = 30,
        [XmlEnumAttribute("31")]       LightVessel = 31,
        [XmlEnumAttribute("32")]       ReferencePoint = 32,
        [XmlEnumAttribute("33")]       Racon = 33,
    }
    #endregion 

    #region voyage
    [System.SerializableAttribute()]
    [XmlRootAttribute(Namespace="urn:http://www.hitt.nl/XMLSchema/ISIS/1.1", IsNullable=false)]
    public  partial class Voyage 
    {
        private string idField;                     // @@@ waarom hier een string 
        private string sourceNameField;
        private StaticDataSource sourceField;
        private VoyageCargoType cargoTypeField;
        private bool cargoTypeFieldSpecified;
        private string destinationField;
        private DateTime eTAField;
        private bool eTAFieldSpecified;
        private DateTime aTAField;
        private bool aTAFieldSpecified;
        private decimal airDraughtField;
        private bool airDraughtFieldSpecified;
        private decimal draughtField;
        private bool draughtFieldSpecified;
        
        [XmlAttributeAttribute()]
        public  string Id 
	    {
		    get { return this.idField;}
		    set { this.idField = value; }
        }
        
        [XmlAttributeAttribute()]
        public  string SourceName 
	    {
		    get { return this.sourceNameField;}
		    set { this.sourceNameField = value; }
        }
        
        [XmlAttributeAttribute()]
        public StaticDataSource Source 
	    {
		    get { return this.sourceField;}
		    set { this.sourceField = value; }
        }
        
        [XmlAttributeAttribute()]
        public  VoyageCargoType CargoType 
	    {
		    get { return this.cargoTypeField;}
            set { this.cargoTypeField = value; this.cargoTypeFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool CargoTypeSpecified
        {
            get { return this.cargoTypeFieldSpecified; }
            set { this.cargoTypeFieldSpecified = value; }
        }
        
        [XmlAttributeAttribute()]
        public  string Destination 
	    {
		    get { return this.destinationField;}
		    set { this.destinationField = value; }
        }
        
        [XmlAttributeAttribute()]
        public  DateTime ETA 
	    {
		    get { return this.eTAField;}
            set { this.eTAField = value; this.eTAFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool ETASpecified
        {
            get { return this.eTAFieldSpecified; }
            set { this.eTAFieldSpecified = value; }
        }
        
        [XmlAttributeAttribute()]
        public  DateTime ATA 
	    {
		    get { return this.aTAField;}
            set { this.aTAField = value; this.aTAFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool ATASpecified
        {
            get { return this.aTAFieldSpecified; }
            set { this.aTAFieldSpecified = value; }
        }
        
        [XmlAttributeAttribute()]
        public  decimal AirDraught 
	    {
		    get { return this.airDraughtField;}
            set { this.airDraughtField = value; this.airDraughtFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool AirDraughtSpecified
        {
            get { return this.airDraughtFieldSpecified; }
            set { this.airDraughtFieldSpecified = value; }
        }
        
        [XmlAttributeAttribute()]
        public  decimal Draught 
	    {
		    get { return this.draughtField;}
            set { this.draughtField = value; this.draughtFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool DraughtSpecified
        {
            get { return this.draughtFieldSpecified; }
            set { this.draughtFieldSpecified = value; }
        }
    }

    [System.SerializableAttribute()]
    public  enum StaticDataSource 
    {
        [XmlEnumAttribute("1")]        Transponder = 1,
        [XmlEnumAttribute("2")]        Database = 2,
        [XmlEnumAttribute("3")]        Manual = 3,
    }

    [System.SerializableAttribute()]
    public  enum VoyageCargoType 
    {
        [XmlEnumAttribute("0")]        Other = 0,
        [XmlEnumAttribute("1")]        CatA = 1,
        [XmlEnumAttribute("2")]        CatB = 2,
        [XmlEnumAttribute("3")]        CatC = 3,
        [XmlEnumAttribute("4")]        CatD = 4,
        [XmlEnumAttribute("9")]        NA = 9,
    }
    #endregion 
    
    #endregion

    #region MSG_LoginRequest

    [System.SerializableAttribute()]
    [XmlRootAttribute(Namespace = "urn:http://www.hitt.nl/XMLSchema/ISIS/1.1", IsNullable = false)] 
    public class MSG_LoginRequest : MSG_Base
    {
        private LoginRequest loginRequestField;
        
        public LoginRequest LoginRequest 
	    {
		    get { return this.loginRequestField;}
		    set { this.loginRequestField = value; }
        }
    }

    [System.SerializableAttribute()]
    [XmlRootAttribute(Namespace="urn:http://www.hitt.nl/XMLSchema/ISIS/1.1", IsNullable=false)]
    public class LoginRequest 
    {
        private string nameField;
        private string passwordField;
        private LoginRequestEncryption encryptionField;
        
        [XmlAttribute]
        public string Name 
	    {
		    get { return this.nameField;}
		    set { this.nameField = value; }
        }
        
        [XmlAttribute]
        public string Password 
	    {
		    get { return this.passwordField;}
		    set { this.passwordField = value; }
        }
        
        [XmlAttribute]
        public LoginRequestEncryption Encryption 
	    {
		    get { return this.encryptionField;}
		    set { this.encryptionField = value; }
        }
    }

    [System.SerializableAttribute()]
    public enum LoginRequestEncryption 
	{
        [XmlEnumAttribute("1")]        Plain = 1,
        [XmlEnumAttribute("2")]        MD5 = 2,
    }
    #endregion

    #region MSG_LoginResponse
    [System.SerializableAttribute()]
    [XmlRootAttribute(Namespace = "urn:http://www.hitt.nl/XMLSchema/ISIS/1.1", IsNullable = false)] 
    public class MSG_LoginResponse : MSG_Base
	{
        private MSG_LoginResponseBody bodyField = null;

        public MSG_LoginResponseBody Body
        {
            get { return this.bodyField; }
            set { this.bodyField = value; }
        }
    }

    public partial class MSG_LoginResponseBody
    {
        private LoginResponse loginResponseField;

        public LoginResponse LoginResponse
        {
            get { return this.loginResponseField; }
            set { this.loginResponseField = value; }
        }
    }

    [System.SerializableAttribute()]
    //[XmlRootAttribute(Namespace="urn:http://www.hitt.nl/XMLSchema/ISIS/1.1", IsNullable=false)]
    public class LoginResponse 
    {
        private string msgIdField;
        private LoginResponseResult resultField;
        private string reasonField;
        
        [XmlAttribute]
        public string MsgId 
	    {
		    get { return this.msgIdField;}
		    set { this.msgIdField = value; }
        }
        
        [XmlAttribute]
        public LoginResponseResult Result 
	    {
		    get { return this.resultField;}
		    set { this.resultField = value; }
        }
        
        [XmlAttribute]
        public string Reason 
	    {
		    get { return this.reasonField;}
		    set { this.reasonField = value; }
        }
    }

    [System.SerializableAttribute()]
    public enum LoginResponseResult 
    {
        [XmlEnumAttribute("1")]        Accepted = 1,
        [XmlEnumAttribute("2")]        Declined = 2,
    }
    #endregion

    #region MSG_Ping

    [System.SerializableAttribute()]
    [XmlRootAttribute(Namespace = "urn:http://www.hitt.nl/XMLSchema/ISIS/1.1", IsNullable = false)] 
    public class MSG_Ping : MSG_Base
    {
        private Ping pingField;

        public Ping Ping 
	    {
		    get { return this.pingField;}
		    set { this.pingField = value; }
        }
    }

    [System.SerializableAttribute()]
    [XmlRootAttribute(Namespace="urn:http://www.hitt.nl/XMLSchema/ISIS/1.1", IsNullable=false)]
    public class Ping 
    {
        private DateTime timeStampField;
        
        [XmlAttribute]
        public DateTime TimeStamp 
	    {
		    get { return this.timeStampField;}
		    set { this.timeStampField = value; }
        }
    }
    #endregion

    #region MSG_Pong
    [System.SerializableAttribute()]
    [XmlRootAttribute(Namespace = "urn:http://www.hitt.nl/XMLSchema/ISIS/1.1", IsNullable = false)] 
    public class MSG_Pong : MSG_Base 
    {
        private Pong pongField;
        
        public Pong Pong 
	    {
		    get { return this.pongField;}
		    set { this.pongField = value; }
        }
    }

    [System.SerializableAttribute()]
    [XmlRootAttribute(Namespace="urn:http://www.hitt.nl/XMLSchema/ISIS/1.1", IsNullable=false)]
    public class Pong 
    {
        private DateTime timeStampField;
        private string msgIdField;
        private int sourceIdField;
        
        [XmlAttribute]
        public DateTime TimeStamp 
	    {
		    get { return this.timeStampField;}
		    set { this.timeStampField = value; }
        }
        
        [XmlAttribute]
        public string MsgId 
	    {
		    get { return this.msgIdField;}
		    set { this.msgIdField = value; }
        }
        
        [XmlAttribute]
        public int SourceId 
	    {
		    get { return this.sourceIdField;}
		    set { this.sourceIdField = value; }
        }
    }
    #endregion

    #region MSG_ServerStatus

    [System.SerializableAttribute()]
    [XmlRootAttribute(Namespace = "urn:http://www.hitt.nl/XMLSchema/ISIS/1.1", IsNullable = false)] 
    public  partial class MSG_ServerStatus : MSG_Base 
    {
        private ServerStatus serverStatusField;
        
        public  ServerStatus ServerStatus 
	    {
		    get { return this.serverStatusField;}
		    set { this.serverStatusField = value; }
        }
    }

    [System.SerializableAttribute()]
    [XmlRootAttribute(Namespace="urn:http://www.hitt.nl/XMLSchema/ISIS/1.1", IsNullable=false)]
    public  partial class ServerStatus 
    {
        private ServerStatusStatus statusField;
        private string detailsField;
        
        [XmlAttributeAttribute()]
        public  ServerStatusStatus Status 
	    {
		    get { return this.statusField;}
		    set { this.statusField = value; }
        }
        
        [XmlAttributeAttribute()]
        public  string Details 
	    {
		    get { return this.detailsField;}
		    set { this.detailsField = value; }
        }
    }

    [System.SerializableAttribute()]
    public  enum ServerStatusStatus 
    {
        [XmlEnumAttribute("queuefull")]         QueueFull = 1,
        [XmlEnumAttribute("ok")]                OK = 2,
    }   
    #endregion

    #region MSG_Logout

    [System.SerializableAttribute()]
    [XmlRootAttribute(Namespace = "urn:http://www.hitt.nl/XMLSchema/ISIS/1.1", IsNullable = false)] 
    public  partial class MSG_Logout : MSG_Base 
    {
        private object logoutField;
        
        public  object Logout 
	    {
		    get { return this.logoutField;}
		    set { this.logoutField = value; }
        }
    }


    [System.SerializableAttribute()]
    [XmlRootAttribute(Namespace="urn:http://www.hitt.nl/XMLSchema/ISIS/1.1", IsNullable=false)]
    public  partial class Logout 
    {
    }
    #endregion

    #region MSG_ServiceRequest

    [System.SerializableAttribute()]
    public class MSG_ServiceRequest : MSG_Base 
    {
        private ServiceRequest serviceRequestField;
        
        public ServiceRequest ServiceRequest 
	    {
		    get { return this.serviceRequestField;}
		    set { this.serviceRequestField = value; }
        }
    }

    [System.SerializableAttribute()]
    [XmlRootAttribute(Namespace="urn:http://www.hitt.nl/XMLSchema/ISIS/1.1", IsNullable=false)]
    public class ServiceRequest 
    {
        private Pos[][] areaField;
        private ServiceRequestTransmission transmissionField;
        private ServiceRequestItem[] itemField;
        private ServiceRequestObject[] objectField;
        
        [XmlArrayItemAttribute("Pos", typeof(Pos), IsNullable=false)]
        public Pos[][] Area 
	    {
		    get { return this.areaField;}
		    set { this.areaField = value; }
        }
        
        public ServiceRequestTransmission Transmission 
	    {
		    get { return this.transmissionField;}
		    set { this.transmissionField = value; }
        }
        
        [XmlElementAttribute("Item")]
        public ServiceRequestItem[] Item 
	    {
		    get { return this.itemField;}
		    set { this.itemField = value; }
        }
        
        [XmlElementAttribute("Object")]
        public ServiceRequestObject[] Object 
	    {
		    get { return this.objectField;}
		    set { this.objectField = value; }
        }
    }

    [System.SerializableAttribute()]
    public class ServiceRequestTransmission 
    {
        private ServiceRequestTransmissionType typeField;
        private decimal periodField;
        private bool periodFieldSpecified;
        
        [XmlAttribute]
        public ServiceRequestTransmissionType Type 
	    {
		    get { return this.typeField;}
		    set { this.typeField = value; }
        }
        
        [XmlAttribute]
        public decimal Period 
	    {
		    get { return this.periodField;}
            set { this.periodField = value; this.periodFieldSpecified = true; }
        }

        [XmlIgnoreAttribute()]
        public bool PeriodSpecified
        {
            get { return this.periodFieldSpecified; }
            set { this.periodFieldSpecified = value; }
        }
    }

    [System.SerializableAttribute()]
    public enum ServiceRequestTransmissionType 
    {    
        [XmlEnumAttribute("1")]        Single = 1,
        [XmlEnumAttribute("2")]        Periodic = 2,
        [XmlEnumAttribute("3")]        Synchronic = 3,
        [XmlEnumAttribute("4")]        Onchange = 4,
    }

    [System.SerializableAttribute()]
    public class ServiceRequestItem 
    {
        private ServiceRequestItemElement elementField;
        private string fieldField;
        
        [XmlAttribute]
        public ServiceRequestItemElement Element 
	    {
		    get { return this.elementField;}
		    set { this.elementField = value; }
        }
        
        [XmlAttribute]
        public string Field 
	    {
		    get { return this.fieldField;}
		    set { this.fieldField = value; }
        }
    }

    [System.SerializableAttribute()]
    public enum ServiceRequestItemElement 
    {
        [XmlEnumAttribute("1")]        Position = 1,
        [XmlEnumAttribute("2")]        StaticData = 2,
        [XmlEnumAttribute("3")]        Voyage = 3,
    }

    [System.SerializableAttribute()]
    public class ServiceRequestObject 
    {
        private string fileNameField;
        
        [XmlAttribute]
        public string FileName 
	    {
		    get { return this.fileNameField;}
		    set { this.fileNameField = value; }
        }
    }
    #endregion
}