#ifndef _CLIENT
#define _CLIENT
#include"stdafx.h"
#include"XmlOperator.h"
using namespace System;
using namespace System::Text;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Xml;
ref class Client
{
public:Client();
	   ~Client();
	   int CreatClient(String^ServerIp, int Port);
	   int StopClient();
	  int SendClientData();
	  
	  bool ConectTest();
	  String^KeyData;
	  String^WriteTime;
	  NetworkStream^stream;
private:
	XmlOperator^XmlText; 
	TcpClient^_Client;
	array<Byte>^ClientData;
	bool IsConect;
	//void WriteSendflag(XmlNode^Node);
	int CloseIfo();
};
#endif // !_CLIENT