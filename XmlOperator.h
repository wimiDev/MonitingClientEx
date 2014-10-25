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
	   void WriteNode(String^day);//写入一个节点
	   int WriteElement(String^NodeName, String^time, String^KeyData, String^IsSend);//向节点写入数据
	   int ReadNodeElement(String^NodeName);
	   void WriteSendflag(XmlNode^Node);
public:bool Isfile;
	   File^file;
	   XmlTextWriter^writefile;
	   XmlNode^Node;//读取该属性时先调用相应的方法
	   XmlNode^XmlLastNode;//读取该属性时先调用相应的方法 
	   XmlDocument^doc;
	   //TimeData^_TimeData;
private:
	XmlNode^RNode;
};
#endif