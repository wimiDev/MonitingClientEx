//write by wangwang
//the time is 2014-10-06 20:28
#ifndef XML_
#define  XML_

using namespace System;
using namespace System::Xml;
using namespace System::Text;
using namespace System::IO;
using namespace System::Windows::Forms;
 public  ref class XmlOperator
{
public:XmlOperator();
	   ~XmlOperator();
	   bool _IsFile();
	   int Creatfile();
	   int ReadANode(String^Name);
	   int ReadTheLastNode();
	   void WriteNode(String^day);//д��һ���ڵ�
	   int WriteElement(String^NodeName, String^time, String^KeyData, String^IsSend);//��ڵ�д������
	   int ReadNodeElement(String^NodeName);
	   void WriteSendflag(XmlNode^Node);
public:bool Isfile;
	   File^file;
	   XmlTextWriter^writefile;
	   XmlNode^Node;//��ȡ������ʱ�ȵ�����Ӧ�ķ���
	   XmlNode^XmlLastNode;//��ȡ������ʱ�ȵ�����Ӧ�ķ��� 
	   XmlDocument^doc;
	   //TimeData^_TimeData;
private:
	XmlNode^RNode;
};
#endif