// MonitoringClientEx.cpp: ����Ŀ�ļ���

#include "stdafx.h"
#include"Time.h"
#include"HookPro.h"
#include"XmlOperator.h"
#include"CLientConect.h"
#include "Form1.h"

using namespace MonitoringClientEx;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// �ڴ����κοؼ�֮ǰ���� Windows XP ���ӻ�Ч��
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// ���������ڲ�������
	Application::Run(gcnew Form1());
	return 0;
}
