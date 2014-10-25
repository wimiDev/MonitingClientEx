#ifndef _TIME
#define _TIME
#include"XmlOperator.h"
using namespace System;
using namespace System::Text;
using namespace System::Windows;
public ref class TimeData
{
public: String^Day;
		String^Time;
		XmlOperator^writedaynode;
		XmlNode^Node;
		String^OldTime;
		String^NewTime;
public: TimeData();
	   ~TimeData();
public: delegate void DelegateDayOverEvent(String^day);//声明委托
public:event DelegateDayOverEvent^DayOver;

protected: void OnDayOver(String^day)
{
			   DayOver(day);
}
public:int GetTime();//获取时间，包括日期和时间（从系统获取）
	   int TimeCmp(DateTime^Dat1,DateTime^Dat2);
	    void _OnDayOver(String^day);
};
#endif