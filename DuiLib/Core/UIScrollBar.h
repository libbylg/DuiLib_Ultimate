#ifndef __UISCROLLBAR_H__
#define __UISCROLLBAR_H__

#include "UILIB.h"
#include "Utils/Utils.h"
#include "Core/UIContainer.h"
#include "Core/UIDefine.h"

namespace DuiLib
{
    class DUILIB_API CScrollBarUI : public CControlUI
    {
        DECLARE_DUICONTROL(CScrollBarUI)
    public:
        CScrollBarUI();

        LPCTSTR GetClass() const;
        LPVOID GetInterface(LPCTSTR pstrName);

        CContainerUI* GetOwner() const;
        void SetOwner(CContainerUI* pOwner);

        void SetVisible(BOOL bVisible = true);
        void SetEnabled(BOOL bEnable = true);
        void SetFocus();

        BOOL IsHorizontal();
        void SetHorizontal(BOOL bHorizontal = true);
        int GetScrollRange() const;
        void SetScrollRange(int nRange);
        int GetScrollPos() const;
        void SetScrollPos(int nPos);
        int GetLineSize() const;
        void SetLineSize(int nSize);

        BOOL GetShowButton1();
        void SetShowButton1(BOOL bShow);
        LPCTSTR GetButton1NormalImage();
        void SetButton1NormalImage(LPCTSTR pStrImage);
        LPCTSTR GetButton1HotImage();
        void SetButton1HotImage(LPCTSTR pStrImage);
        LPCTSTR GetButton1PushedImage();
        void SetButton1PushedImage(LPCTSTR pStrImage);
        LPCTSTR GetButton1DisabledImage();
        void SetButton1DisabledImage(LPCTSTR pStrImage);

        BOOL GetShowButton2();
        void SetShowButton2(BOOL bShow);
        LPCTSTR GetButton2NormalImage();
        void SetButton2NormalImage(LPCTSTR pStrImage);
        LPCTSTR GetButton2HotImage();
        void SetButton2HotImage(LPCTSTR pStrImage);
        LPCTSTR GetButton2PushedImage();
        void SetButton2PushedImage(LPCTSTR pStrImage);
        LPCTSTR GetButton2DisabledImage();
        void SetButton2DisabledImage(LPCTSTR pStrImage);

        LPCTSTR GetThumbNormalImage();
        void SetThumbNormalImage(LPCTSTR pStrImage);
        LPCTSTR GetThumbHotImage();
        void SetThumbHotImage(LPCTSTR pStrImage);
        LPCTSTR GetThumbPushedImage();
        void SetThumbPushedImage(LPCTSTR pStrImage);
        LPCTSTR GetThumbDisabledImage();
        void SetThumbDisabledImage(LPCTSTR pStrImage);

        LPCTSTR GetRailNormalImage();
        void SetRailNormalImage(LPCTSTR pStrImage);
        LPCTSTR GetRailHotImage();
        void SetRailHotImage(LPCTSTR pStrImage);
        LPCTSTR GetRailPushedImage();
        void SetRailPushedImage(LPCTSTR pStrImage);
        LPCTSTR GetRailDisabledImage();
        void SetRailDisabledImage(LPCTSTR pStrImage);

        LPCTSTR GetBkNormalImage();
        void SetBkNormalImage(LPCTSTR pStrImage);
        LPCTSTR GetBkHotImage();
        void SetBkHotImage(LPCTSTR pStrImage);
        LPCTSTR GetBkPushedImage();
        void SetBkPushedImage(LPCTSTR pStrImage);
        LPCTSTR GetBkDisabledImage();
        void SetBkDisabledImage(LPCTSTR pStrImage);

        void SetPos(RECT rc, BOOL bNeedInvalidate = true);
        void DoEvent(TEventUI& event);
        void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);

        BOOL DoPaint(HDC hDC, const RECT& rcPaint, CControlUI* pStopControl);

        void PaintBk(HDC hDC);
        void PaintButton1(HDC hDC);
        void PaintButton2(HDC hDC);
        void PaintThumb(HDC hDC);
        void PaintRail(HDC hDC);

    protected:

        enum
        {
            DEFAULT_SCROLLBAR_SIZE = 16,
            DEFAULT_TIMERID = 10,
        };

        BOOL m_bHorizontal;
        int m_nRange;
        int m_nScrollPos;
        int m_nLineSize;
        CContainerUI* m_pOwner;
        POINT ptLastMouse;
        int m_nLastScrollPos;
        int m_nLastScrollOffset;
        int m_nScrollRepeatDelay;

        CDuiString m_sBkNormalImage;
        CDuiString m_sBkHotImage;
        CDuiString m_sBkPushedImage;
        CDuiString m_sBkDisabledImage;

        BOOL m_bShowButton1;
        RECT m_rcButton1;
        UINT m_uButton1State;
        CDuiString m_sButton1NormalImage;
        CDuiString m_sButton1HotImage;
        CDuiString m_sButton1PushedImage;
        CDuiString m_sButton1DisabledImage;

        BOOL m_bShowButton2;
        RECT m_rcButton2;
        UINT m_uButton2State;
        CDuiString m_sButton2NormalImage;
        CDuiString m_sButton2HotImage;
        CDuiString m_sButton2PushedImage;
        CDuiString m_sButton2DisabledImage;

        RECT m_rcThumb;
        UINT m_uThumbState;
        CDuiString m_sThumbNormalImage;
        CDuiString m_sThumbHotImage;
        CDuiString m_sThumbPushedImage;
        CDuiString m_sThumbDisabledImage;

        CDuiString m_sRailNormalImage;
        CDuiString m_sRailHotImage;
        CDuiString m_sRailPushedImage;
        CDuiString m_sRailDisabledImage;

        CDuiString m_sImageModify;
    };
}

#endif // __UISCROLLBAR_H__