using System;
using System.Collections.Generic;
using System.IO;
using System.Net;
using System.Text;
using System.Net.Sockets;

using ISIS.lib;

namespace ISIS.example
{
    class Program
    {
        static void Main(string[] args)
        {
            ISIS_Handler hndlr = new ISIS_Handler();
            string file = @"C:\Documents and Settings\jonker\My Documents\ISIS\logging";

            // your own processsing via a callback methods
            hndlr.ReceiveVesselData += new ReceiveHandlerVesselData(MyReceiverVesselData);   
            hndlr.ReceiveLoginResponse += new ReceiveHandlerLoginResponse(MyLoginResponse);

            StreamReader sr = new StreamReader(file);

            hndlr.ProcessInput(sr); // process the input a read from the stream;

            sr.Close();
            Console.ReadLine();

            //hndlr.ParseMsg(msg);
            //Console.ReadLine();
            //try 
            //{
            //    TcpClient tcpclnt = new TcpClient();
            //    Console.WriteLine("Connecting.....");

            //    tcpclnt.Connect("isis.hitt.nl",8043); // use the ipaddress as in the server program
            //    NetworkStream stream = client.GetStream();


            //    Console.WriteLine("Connected");
            //    Console.Write("Enter the string to be transmitted : ");

            //    String str=Console.ReadLine();
            //    Stream stm = tcpclnt.GetStream();

            //    ASCIIEncoding asen= new ASCIIEncoding();

            //    byte[] ba=asen.GetBytes(str);

            //    Console.WriteLine("Transmitting.....");

            //    stm.Write(ba,0,ba.Length);


            //    //byte[] bb=new byte100;
            //    //int k=stm.Read(bb,0,100);

            //    //for (int i=0;i k;i++)
            //    //    Console.Write(Convert.ToChar(bbi));

            //    tcpclnt.Close();
            //}
            //catch (Exception e) 
            //{
            //    Console.WriteLine("Error..... " + e.StackTrace);
            //}
        }


        static private void  MyReceiverVesselData(VesselData[] vd)
        {
            Console.WriteLine(string.Format("{0} VesselData records received", vd.Length));
        }

        static private void MyLoginResponse(LoginResponse lr)
        {
            Console.WriteLine(string.Format("login result {0} ", lr.Result));
        }
    }
}


