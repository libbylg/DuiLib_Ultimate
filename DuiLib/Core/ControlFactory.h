#pragma once
#include <map>
namespace DuiLib 
{
	typedef CControlUI* (*CreateClass)();
	typedef std::map<CDuiString, CreateClass> MAP_DUI_CTRATECLASS;

	class UILIB_API CControlFactory
	{
	public:
		CControlUI* CreateControl(CDuiString strClassName);
		void RegistControl(CDuiString strClassName, CreateClass pFunc);

		static CControlFactory* GetInstance();
		void Release();

	private:	
		CControlFactory();
		virtual ~CControlFactory();

	private:
		MAP_DUI_CTRATECLASS m_mapControl;
	};




#define REGIST_DUICONTROL(class_name)\
	CControlFactory::GetInstance()->RegistControl(_T(#class_name), (CreateClass)class_name::CreateControl);

#define INNER_REGISTER_DUICONTROL(class_name)\
	RegistControl(_T(#class_name), (CreateClass)class_name::CreateControl);
}