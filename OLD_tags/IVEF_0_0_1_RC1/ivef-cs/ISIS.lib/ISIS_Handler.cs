using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Xml;
using System.Diagnostics;

using System.Xml.Serialization;


namespace ISIS.lib
{
    public delegate void ReceiveHandlerVesselData(ISIS.lib.VesselData[] VesselData);
    public delegate void ReceiveHandlerLoginResponse(LoginResponse loginResponse);

    public class ISIS_Handler
    {
        public event ReceiveHandlerVesselData ReceiveVesselData;
        public event ReceiveHandlerLoginResponse ReceiveLoginResponse;

        public void ProcessInput(StreamReader input)
        {
            ISIS_Convertor convertor = new ISIS_Convertor();

            XmlReaderSettings settings = new XmlReaderSettings();
            settings.ConformanceLevel = ConformanceLevel.Fragment;
            settings.IgnoreWhitespace = true;
            settings.IgnoreComments = true;
            //settings.Schemas.Add(ISIS_Constants.urn, ISIS_Constants.XSDfile );
            //settings.ValidationType = ValidationType.Schema;


            XmlReader reader = XmlReader.Create(input, settings);

            while (reader.Read())
            {
                try
                {
                    if ((reader.NodeType == XmlNodeType.Element) && (reader.Depth == 0))
                    {
                        object obj = convertor.ParseMsg(reader);

                        if (obj != null)
                        {
                            switch (obj.GetType().ToString())
                            {
                                case "ISIS.lib.VesselData[]":
                                {
                                    if (ReceiveVesselData != null)
                                        ReceiveVesselData((VesselData[])obj);
                                    break;
                                }
                                case "ISIS.lib.LoginResponse":
                                {
                                    if (ReceiveLoginResponse != null)
                                        ReceiveLoginResponse((LoginResponse)obj);
                                    break;
                                }
                            }
                        }
                    }
                }
                catch (Exception e)
                {
                    Debug.WriteLine(e.InnerException.Message);
                }
            }
        }
    }
}
