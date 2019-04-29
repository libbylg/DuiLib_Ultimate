#ifndef __UICONTROL_H__
#define __UICONTROL_H__

#include "Utils/UIDelegate.h"
#include "Core/UIDefine.h"
#include "Core/UIManager.h"

namespace DuiLib {

	/////////////////////////////////////////////////////////////////////////////////////
	//

    class CPaintManagerUI;

    typedef CControlUI* (CALLBACK* FINDCONTROLPROC)(CControlUI*, LPVOID);

	class DUILIB_API CControlUI
	{
		DECLARE_DUICONTROL(CControlUI)
	public:
		CControlUI();
		virtual ~CControlUI();

	public:
		virtual CDuiString GetName() const;
		virtual void SetName(LPCTSTR pstrName);
		virtual LPCTSTR GetClass() const;
		virtual LPVOID GetInterface(LPCTSTR pstrName);
		virtual UINT GetControlFlags() const;

		virtual BOOL Activate();
		virtual CPaintManagerUI* GetManager() const;
		virtual void SetManager(CPaintManagerUI* pManager, CControlUI* pParent, BOOL bInit = true);
		virtual CControlUI* GetParent() const;
	    void setInstance(HINSTANCE instance = NULL) {m_instance = instance;};
		
		// ��ʱ��
		BOOL SetTimer(UINT nTimerID, UINT nElapse);
		void KillTimer(UINT nTimerID);

		// �ı����
		virtual CDuiString GetText() const;
		virtual void SetText(LPCTSTR pstrText);

		virtual BOOL IsResourceText() const;
		virtual void SetResourceText(BOOL bResource);

		virtual BOOL IsDragEnabled() const;
		virtual void SetDragEnable(BOOL bDrag);

		virtual BOOL IsDropEnabled() const;
		virtual void SetDropEnable(BOOL bDrop);

		// ͼ�����
		LPCTSTR GetGradient();
		void SetGradient(LPCTSTR pStrImage);
		DWORD GetBkColor() const;
		void SetBkColor(DWORD dwBackColor);
		DWORD GetBkColor2() const;
		void SetBkColor2(DWORD dwBackColor);
		DWORD GetBkColor3() const;
		void SetBkColor3(DWORD dwBackColor);
		DWORD GetForeColor() const;
		void SetForeColor(DWORD dwForeColor);
		LPCTSTR GetBkImage();
		void SetBkImage(LPCTSTR pStrImage);
		LPCTSTR GetForeImage() const;
		void SetForeImage(LPCTSTR pStrImage);

		DWORD GetFocusBorderColor() const;
		void SetFocusBorderColor(DWORD dwBorderColor);
		BOOL IsColorHSL() const;
		void SetColorHSL(BOOL bColorHSL);
		SIZE GetBorderRound() const;
		void SetBorderRound(SIZE cxyRound);
		BOOL DrawImage(HDC hDC, LPCTSTR pStrImage, LPCTSTR pStrModify = NULL);

		//�߿����
		int GetBorderSize() const;
		void SetBorderSize(int nSize);
		DWORD GetBorderColor() const;
		void SetBorderColor(DWORD dwBorderColor);
		void SetBorderSize(RECT rc);
		int GetLeftBorderSize() const;
		void SetLeftBorderSize(int nSize);
		int GetTopBorderSize() const;
		void SetTopBorderSize(int nSize);
		int GetRightBorderSize() const;
		void SetRightBorderSize(int nSize);
		int GetBottomBorderSize() const;
		void SetBottomBorderSize(int nSize);
		int GetBorderStyle() const;
		void SetBorderStyle(int nStyle);

		// λ�����
		virtual RECT GetRelativePos() const; // ���(���ؼ�)λ��
		virtual RECT GetClientPos() const; // �ͻ����򣨳�ȥscrollbar��inset��
		virtual const RECT& GetPos() const;
		virtual void SetPos(RECT rc, BOOL bNeedInvalidate = true);
		virtual void Move(SIZE szOffset, BOOL bNeedInvalidate = true);
		virtual int GetWidth() const;
		virtual int GetHeight() const;
		virtual int GetX() const;
		virtual int GetY() const;
		virtual RECT GetPadding() const;
		virtual void SetPadding(RECT rcPadding); // ������߾࣬���ϲ㴰�ڻ���
		virtual SIZE GetFixedXY() const;         // ʵ�ʴ�Сλ��ʹ��GetPos��ȡ������õ�����Ԥ��Ĳο�ֵ
		virtual void SetFixedXY(SIZE szXY);      // ��floatΪtrueʱ��Ч
		virtual int GetFixedWidth() const;       // ʵ�ʴ�Сλ��ʹ��GetPos��ȡ������õ�����Ԥ��Ĳο�ֵ
		virtual void SetFixedWidth(int cx);      // Ԥ��Ĳο�ֵ
		virtual int GetFixedHeight() const;      // ʵ�ʴ�Сλ��ʹ��GetPos��ȡ������õ�����Ԥ��Ĳο�ֵ
		virtual void SetFixedHeight(int cy);     // Ԥ��Ĳο�ֵ
		virtual int GetMinWidth() const;
		virtual void SetMinWidth(int cx);
		virtual int GetMaxWidth() const;
		virtual void SetMaxWidth(int cx);
		virtual int GetMinHeight() const;
		virtual void SetMinHeight(int cy);
		virtual int GetMaxHeight() const;
		virtual void SetMaxHeight(int cy);
		virtual TPercentInfo GetFloatPercent() const;
		virtual void SetFloatPercent(TPercentInfo piFloatPercent);
		virtual void SetFloatAlign(UINT uAlign);
		virtual UINT GetFloatAlign() const;
		// �����ʾ
		virtual CDuiString GetToolTip() const;
		virtual void SetToolTip(LPCTSTR pstrText);
		virtual void SetToolTipWidth(int nWidth);
		virtual int	  GetToolTipWidth(void);	// ����ToolTip��������
		
		// ���
		virtual WORD GetCursor();
		virtual void SetCursor(WORD wCursor);

		// ��ݼ�
		virtual TCHAR GetShortcut() const;
		virtual void SetShortcut(TCHAR ch);

		// �˵�
		virtual BOOL IsContextMenuUsed() const;
		virtual void SetContextMenuUsed(BOOL bMenuUsed);

		// �û�����
		virtual const CDuiString& GetUserData(); // �������������û�ʹ��
		virtual void SetUserData(LPCTSTR pstrText); // �������������û�ʹ��
		virtual UINT_PTR GetTag() const; // �������������û�ʹ��
		virtual void SetTag(UINT_PTR pTag); // �������������û�ʹ��

		// һЩ��Ҫ������
		virtual BOOL IsVisible() const;
		virtual void SetVisible(BOOL bVisible = true);
		virtual void SetInternVisible(BOOL bVisible = true); // �����ڲ����ã���ЩUIӵ�д��ھ������Ҫ��д�˺���
		virtual BOOL IsEnabled() const;
		virtual void SetEnabled(BOOL bEnable = true);
		virtual BOOL IsMouseEnabled() const;
		virtual void SetMouseEnabled(BOOL bEnable = true);
		virtual BOOL IsKeyboardEnabled() const;
		virtual void SetKeyboardEnabled(BOOL bEnable = true);
		virtual BOOL IsFocused() const;
		virtual void SetFocus();
		virtual BOOL IsFloat() const;
		virtual void SetFloat(BOOL bFloat = true);

		virtual CControlUI* FindControl(FINDCONTROLPROC Proc, LPVOID pData, UINT uFlags);

		void Invalidate();
		BOOL IsUpdateNeeded() const;
		void NeedUpdate();
		void NeedParentUpdate();
		DWORD GetAdjustColor(DWORD dwColor);

		virtual void Init();
		virtual void DoInit();

		virtual void Event(TEventUI& event);
		virtual void DoEvent(TEventUI& event);

		// �Զ���(δ�����)����
		void AddCustomAttribute(LPCTSTR pstrName, LPCTSTR pstrAttr);
		LPCTSTR GetCustomAttribute(LPCTSTR pstrName) const;
		BOOL RemoveCustomAttribute(LPCTSTR pstrName);
		void RemoveAllCustomAttribute();

		virtual void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);
		CControlUI* ApplyAttributeList(LPCTSTR pstrList);

		virtual SIZE EstimateSize(SIZE szAvailable);
		virtual BOOL Paint(HDC hDC, const RECT& rcPaint, CControlUI* pStopControl = NULL); // ����Ҫ��Ҫ��������
		virtual BOOL DoPaint(HDC hDC, const RECT& rcPaint, CControlUI* pStopControl);
		virtual void PaintBkColor(HDC hDC);
		virtual void PaintBkImage(HDC hDC);
		virtual void PaintStatusImage(HDC hDC);
		virtual void PaintForeColor(HDC hDC);
		virtual void PaintForeImage(HDC hDC);
		virtual void PaintText(HDC hDC);
		virtual void PaintBorder(HDC hDC);

		virtual void DoPostPaint(HDC hDC, const RECT& rcPaint);

		//���ⴰ�ڲ���
		void SetVirtualWnd(LPCTSTR pstrValue);
		CDuiString GetVirtualWnd() const;

	public:
		CEventSource OnInit;
		CEventSource OnDestroy;
		CEventSource OnSize;
		CEventSource OnEvent;
		CEventSource OnNotify;

	protected:
		CPaintManagerUI* m_pManager;
		CControlUI* m_pParent;
		CDuiString m_sVirtualWnd;
		CDuiString m_sName;
		BOOL m_bUpdateNeeded;
		BOOL m_bMenuUsed;
		RECT m_rcItem;
		RECT m_rcPadding;
		SIZE m_cXY;
		SIZE m_cxyFixed;
		SIZE m_cxyMin;
		SIZE m_cxyMax;
		BOOL m_bVisible;
		BOOL m_bInternVisible;
		BOOL m_bEnabled;
		BOOL m_bMouseEnabled;
		BOOL m_bKeyboardEnabled ;
		BOOL m_bFocused;
		BOOL m_bFloat;
		TPercentInfo m_piFloatPercent;
		UINT m_uFloatAlign;
		BOOL m_bSetPos; // ��ֹSetPosѭ������

		BOOL m_bDragEnabled;
		BOOL m_bDropEnabled;

		BOOL m_bResourceText;
		CDuiString m_sText;
		CDuiString m_sToolTip;
		TCHAR m_chShortcut;
		CDuiString m_sUserData;
		UINT_PTR m_pTag;

		CDuiString m_sGradient;
		DWORD m_dwBackColor;
		DWORD m_dwBackColor2;
		DWORD m_dwBackColor3;
		DWORD m_dwForeColor;
		CDuiString m_sBkImage;
		CDuiString m_sForeImage;
		DWORD m_dwBorderColor;
		DWORD m_dwFocusBorderColor;
		BOOL m_bColorHSL;
		int m_nBorderSize;
		int m_nBorderStyle;
		int m_nTooltipWidth;
		WORD m_wCursor;
		SIZE m_cxyBorderRound;
		RECT m_rcPaint;
		RECT m_rcBorderSize;
	    HINSTANCE m_instance;

		CStdStringPtrMap m_mCustomAttrHash;
	};

} // namespace DuiLib

#endif // __UICONTROL_H__
