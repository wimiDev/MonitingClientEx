#include"stdafx.h"
#include"XmlOperator.h"
XmlOperator::XmlOperator()
{
	doc = gcnew XmlDocument();
		   //�ж��ļ��Ƿ���ڣ������ھʹ����ļ�
		   if (!_IsFile())
		   {
			   Creatfile();
		   }

}
XmlOperator:: ~XmlOperator()
	   {
		   if (doc != nullptr)
			   doc->Save(Application::StartupPath + "\\DebugClientData.xml");
		   GC::Collect();
	   }
bool XmlOperator:: _IsFile()
	   {
	if (file->Exists(Application::StartupPath + "\\DebugClientData.xml"))
		   {
			   Isfile = true;
			   return true;
		   }
		   else
			   return false;
	   }
 int XmlOperator::Creatfile()
	   {
		   Encoding^ encoding;
		   writefile = gcnew XmlTextWriter(Application::StartupPath + "\\DebugClientData.xml", encoding->UTF8);
		   writefile->WriteStartDocument();
		   writefile->Formatting = Formatting::Indented;
		   writefile->WriteStartElement("DataRoot");
		   writefile->WriteStartElement("Info");
		   writefile->WriteStartElement("Info");
		   writefile->WriteAttributeString("author", "wang");
		   writefile->WriteEndElement();
		   writefile->WriteEndElement();
		   writefile->Close();
		   return 0;
	   }
 int XmlOperator::ReadANode(String^Name)
	   {
	 doc->Load(Application::StartupPath + "\\DebugClientData.xml");
		   Node = doc->DocumentElement;
		  RNode = Node = Node->SelectSingleNode(Name);
		  doc->Save(Application::StartupPath + "\\DebugClientData.xml");
		  GC::Collect();
		   return 0;
	   }
 int XmlOperator::ReadTheLastNode()
	   {
		  // XmlDocument^doc = gcnew XmlDocument();
		   doc->Load(Application::StartupPath + "\\DebugClientData.xml");
		   XmlLastNode = doc->LastChild;
		   XmlLastNode = XmlLastNode->LastChild;
		  doc->Save(Application::StartupPath + "\\DebugClientData.xml");
		  GC::Collect();
		   return 0;
	   }



void XmlOperator::WriteNode(String^day)//д��һ���ڵ�
	   {
		   XmlNode^WNode;
		   XmlNode^root;
		   XmlElement^Add;
		   XmlDocument^doc = gcnew XmlDocument();
		   doc->Load(Application::StartupPath + "\\DebugClientData.xml");
		   root = doc->SelectSingleNode("DataRoot");
		   WNode = doc->CreateNode(XmlNodeType::Element, day, nullptr);
		   Add = doc->CreateElement("Add_New_Node");
		   Add->SetAttribute("A_New_Day", day);
		   WNode->AppendChild(Add);
		   root->AppendChild(WNode);
		   doc->Save(Application::StartupPath + "\\DebugClientData.xml");
		   GC::Collect();
	   }
 int XmlOperator::WriteElement(String^NodeName,String^time, String^KeyData, String^IsSend)//��ڵ�д������
 {
	 //XmlDocument^ OperateFile = gcnew XmlDocument();
	 XmlNode^Cnode;
	 XmlNode^Root;
	 XmlElement^add;
	doc->Load(Application::StartupPath + "\\DebugClientData.xml");//װ���ļ�
	 Root = doc->DocumentElement;//���Ҹ��ڵ�
	 Cnode = Root->SelectSingleNode(NodeName);
	 add = doc->CreateElement("AddData");
	 add->SetAttribute("Key", KeyData);
	 add->SetAttribute("Time", time);
	 add->SetAttribute("IsSend",IsSend);
	 Cnode->AppendChild(add);
	 Root->AppendChild(Cnode);
	 doc->Save(Application::StartupPath+"\\DebugClientData.xml");
	 GC::Collect();
	 return 0;
 }
 int XmlOperator::ReadNodeElement(String^NodeName)
 {
	 ReadANode(NodeName);
	 return 0;
 }
 void XmlOperator::WriteSendflag(XmlNode^Node)//д���ѷ��ͱ�־
{
	// XmlDocument^ OperateFile = gcnew XmlDocument();
	doc->Load(Application::StartupPath + "\\DebugClientData.xml");
	XmlNode^_Node = doc->DocumentElement;
	_Node = _Node->LastChild;
	_Node = _Node->LastChild;
	//_Node = _Node->SelectSingleNode(Node);
	XmlNamedNodeMap^Map = _Node->Attributes;
	Map->Item(Map->Count-1)->Value="Y";
	doc->Save(Application::StartupPath + "\\DebugClientData.xml");
	GC::Collect();
}