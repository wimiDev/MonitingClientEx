#include"stdafx.h"
#include"CLientConect.h"
Client::Client()//���췽��
{
IsConect = false;
 stream = nullptr;
 ClientData = gcnew array<Byte>(128);
 XmlText = gcnew XmlOperator();
}
Client::~Client(){
	if (_Client != nullptr)
		_Client->Close();
	GC::Collect();
}
int Client :: CreatClient(String^ServerIp, int Port)//�����ͻ���
{
	try{
	ClientData->Initialize();
 _Client= gcnew TcpClient(ServerIp,Port);
 if (_Client->Client != nullptr)
	 return 0;
	}
	catch (Exception^e)
	{
		//String^err = e->ToString();
		//err = String::Empty;
		GC::Collect();
		return -1;
	}
}
int Client::StopClient()
{
	try{
		if (_Client != nullptr)
		{
			_Client->Close();
			return 0;
		}
		}
	catch (Exception^e)
	{
		//String^err=e->ToString();err = String::Empty;
		GC::Collect();
		return -1;
		
	}
}
bool Client::ConectTest()//���Ӳ�/��
{
	try{
	String^TestStr = "OK?";
	stream = _Client->GetStream();
	ClientData=Encoding::ASCII->GetBytes(TestStr);
	stream->WriteTimeout = 1000;
	stream->Write(ClientData,0,ClientData->Length);
	ClientData->Clear(ClientData,0,3);
	stream->ReadTimeout = 1000;
	TestStr = String::Empty;
	int i=stream->Read(ClientData,0,ClientData->Length);
	if (Encoding::ASCII->GetString(ClientData,0,i)=="OK!")
		return true;
	else
		return false;
	}
	catch (Exception^e)
	{
		//String^err = e->ToString();
		//err = String::Empty;
		GC::Collect();
		return false;
	}
}
int Client::SendClientData()
{
	//��Xml�ļ��ж�ȡһ��δ���͵ļ�¼
	try{
	KeyData = String::Empty;
	XmlText->ReadTheLastNode();
	XmlNode^SendNode = XmlText->XmlLastNode;
	SendNode = SendNode->LastChild;
	XmlNamedNodeMap^Map=SendNode->Attributes;
	KeyData = Map->Item(Map->Count-3)->Value;
	WriteTime = Map->Item(Map->Count-2)->Value;
	if (ConectTest() && Map->Item(Map->Count-1)->Value!="Y")//���ӳɹ���������
	{
		stream = _Client->GetStream();
		ClientData = Encoding::ASCII->GetBytes(KeyData);
		stream->WriteTimeout = 1000;
		stream->Write(ClientData, 0, ClientData->Length);
		ClientData = Encoding::ASCII->GetBytes(WriteTime);
		stream->WriteTimeout = 1000;
		stream->Write(ClientData, 0, ClientData->Length);
		XmlText->WriteSendflag(SendNode);
		if (Encoding::ASCII->GetString(ClientData, 0, stream->Read(ClientData, 0, ClientData->Length)) != "Next")
		{
			return -1;
		}
	}
	else
		return -1;
	return 0;
	}
	catch (Exception^e)
	{
		//String^err = e->ToString();
		//err = String::Empty;
		GC::Collect();
		return -1;
	}
}

int Client::CloseIfo()//�����˷��͹ر�����
{
	try
	{
	String^CloseStr="Over";
	stream = _Client->GetStream();
	ClientData = Encoding::ASCII->GetBytes(CloseStr);
	stream->Write(ClientData, 0, ClientData->Length);
	return 0;
	}
	catch (Exception^e)
	{
		//String^err = e->ToString();
		//err = String::Empty;
		GC::Collect();
		return -1;
	}
}