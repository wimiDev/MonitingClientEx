//write by wangwang
//the time is 2014-10-06 20:28
#ifndef HOOK_
#define  HOOK_
using namespace System;
using namespace System::IO;
using namespace System::Threading;
using namespace System::Text;
using namespace System::Timers;
using namespace System::Windows::Forms;
using namespace System::Reflection;
public ref class hookpro
{
 public: char hookdata;
		bool HookOk;
		String^SHookData;//hook返回的数据
public: hookpro();
		~hookpro();
		int SetHook();
		int UnHook();
		 void GetHookData();
		void chartostring(char dat);
private:
	String^TempKey;
};
#endif