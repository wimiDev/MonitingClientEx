#include"stdafx.h"
#include"Time.h"
TimeData::TimeData()
{
	this->Day = " ";
	this->Time = " ";
	writedaynode = gcnew XmlOperator();
	GetTime();
	
}
TimeData::~TimeData(){ GC::Collect(); };
int TimeData:: GetTime()
{
	 writedaynode->ReadTheLastNode();
	 Node = writedaynode->XmlLastNode;
	OldTime=Node->Name->ToString();
	DateTime^_DataTime=gcnew DateTime();
	Day =Convert::ToString(_DataTime->Now.ToString("_yyyy_MM_dd"));
	NewTime = this->Day->ToString();
	if (OldTime != NewTime)
	{
		_OnDayOver(NewTime);
	}
	Time = Convert::ToString(_DataTime->Now.ToShortTimeString());
	return 0;
}
int TimeData::TimeCmp(DateTime^dat1, DateTime^dat2)
{
	String^Time1;
	String^Time2;
	Time1=dat1->ToString();
	Time2 = dat2->ToString();
	if (Time1 == Time2)
	{
		return 0;
	}
	else
		return -1;
}
void TimeData::_OnDayOver(String^day)
{
		DayOver(NewTime);
		//´¥·¢ÊÂ¼þ
}