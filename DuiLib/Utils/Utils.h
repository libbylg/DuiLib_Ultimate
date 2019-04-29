#ifndef __UTILS_H__
#define __UTILS_H__

#include "UILIB.h"

namespace DuiLib
{
    /////////////////////////////////////////////////////////////////////////////////////
    //

    class DUILIB_API STRINGorID
    {
    public:
        STRINGorID(LPCTSTR lpString) : m_lpstr(lpString)
        {
        }
        STRINGorID(UINT nID) : m_lpstr(MAKEINTRESOURCE(nID))
        {
        }
        LPCTSTR m_lpstr;
    };

    /////////////////////////////////////////////////////////////////////////////////////
    //

    class DUILIB_API CDuiPoint : public tagPOINT
    {
    public:
        CDuiPoint();
        CDuiPoint(const POINT& src);
        CDuiPoint(int x, int y);
        CDuiPoint(LPARAM lParam);
    };


    /////////////////////////////////////////////////////////////////////////////////////
    //

    class DUILIB_API CDuiSize : public tagSIZE
    {
    public:
        CDuiSize();
        CDuiSize(const SIZE& src);
        CDuiSize(const RECT rc);
        CDuiSize(int cx, int cy);
    };


    /////////////////////////////////////////////////////////////////////////////////////
    //

    class DUILIB_API CDuiRect : public tagRECT
    {
    public:
        CDuiRect();
        CDuiRect(const RECT& src);
        CDuiRect(int iLeft, int iTop, int iRight, int iBottom);

        int GetWidth() const;
        int GetHeight() const;
        void Empty();
        BOOL IsNull() const;
        void Join(const RECT& rc);
        void ResetOffset();
        void Normalize();
        void Offset(int cx, int cy);
        void Inflate(int cx, int cy);
        void Deflate(int cx, int cy);
        void Union(CDuiRect& rc);
    };

    /////////////////////////////////////////////////////////////////////////////////////
    //

    class DUILIB_API CStdPtrArray
    {
    public:
        CStdPtrArray(int iPreallocSize = 0);
        CStdPtrArray(const CStdPtrArray& src);
        ~CStdPtrArray();

        void Empty();
        void Resize(int iSize);
        BOOL IsEmpty() const;
        int Find(LPVOID iIndex) const;
        BOOL Add(LPVOID pData);
        BOOL SetAt(int iIndex, LPVOID pData);
        BOOL InsertAt(int iIndex, LPVOID pData);
        BOOL Remove(int iIndex);
        int GetSize() const;
        LPVOID* GetData();

        LPVOID GetAt(int iIndex) const;
        LPVOID operator[] (int nIndex) const;

    protected:
        LPVOID* m_ppVoid;
        int m_nCount;
        int m_nAllocated;
    };


    /////////////////////////////////////////////////////////////////////////////////////
    //

    class DUILIB_API CStdValArray
    {
    public:
        CStdValArray(int iElementSize, int iPreallocSize = 0);
        ~CStdValArray();

        void Empty();
        BOOL IsEmpty() const;
        BOOL Add(LPCVOID pData);
        BOOL Remove(int iIndex);
        int GetSize() const;
        LPVOID GetData();

        LPVOID GetAt(int iIndex) const;
        LPVOID operator[] (int nIndex) const;

    protected:
        LPBYTE m_pVoid;
        int m_iElementSize;
        int m_nCount;
        int m_nAllocated;
    };


    /////////////////////////////////////////////////////////////////////////////////////
    //

    class DUILIB_API CDuiString
    {
    public:
        enum { MAX_LOCAL_STRING_LEN = 63 };

        CDuiString();
        CDuiString(const TCHAR ch);
        CDuiString(const CDuiString& src);
        CDuiString(LPCTSTR lpsz, int nLen = -1);
        ~CDuiString();

        void Empty();
        int GetLength() const;
        BOOL IsEmpty() const;
        TCHAR GetAt(int nIndex) const;
        void Append(LPCTSTR pstr);
        void Assign(LPCTSTR pstr, int nLength = -1);
        LPCTSTR GetData() const;

        void SetAt(int nIndex, TCHAR ch);
        operator LPCTSTR() const;

        TCHAR operator[] (int nIndex) const;
        const CDuiString& operator=(const CDuiString& src);
        const CDuiString& operator=(const TCHAR ch);
        const CDuiString& operator=(LPCTSTR pstr);
#ifdef _UNICODE
        const CDuiString& CDuiString::operator=(LPCSTR lpStr);
        const CDuiString& CDuiString::operator+=(LPCSTR lpStr);
#else
        const CDuiString& CDuiString::operator=(LPCWSTR lpwStr);
        const CDuiString& CDuiString::operator+=(LPCWSTR lpwStr);
#endif
        CDuiString operator+(const CDuiString& src) const;
        CDuiString operator+(LPCTSTR pstr) const;
        const CDuiString& operator+=(const CDuiString& src);
        const CDuiString& operator+=(LPCTSTR pstr);
        const CDuiString& operator+=(const TCHAR ch);

        BOOL operator == (LPCTSTR str) const;
        BOOL operator != (LPCTSTR str) const;
        BOOL operator <= (LPCTSTR str) const;
        BOOL operator <  (LPCTSTR str) const;
        BOOL operator >= (LPCTSTR str) const;
        BOOL operator >  (LPCTSTR str) const;

        int Compare(LPCTSTR pstr) const;
        int CompareNoCase(LPCTSTR pstr) const;

        void MakeUpper();
        void MakeLower();

        CDuiString Left(int nLength) const;
        CDuiString Mid(int iPos, int nLength = -1) const;
        CDuiString Right(int nLength) const;

        int Find(TCHAR ch, int iPos = 0) const;
        int Find(LPCTSTR pstr, int iPos = 0) const;
        int ReverseFind(TCHAR ch) const;
        int Replace(LPCTSTR pstrFrom, LPCTSTR pstrTo);

        int __cdecl Format(LPCTSTR pstrFormat, ...);
        int __cdecl SmallFormat(LPCTSTR pstrFormat, ...);

    protected:
        int __cdecl InnerFormat(LPCTSTR pstrFormat, va_list Args);

    protected:
        LPTSTR m_pstr;
        TCHAR m_szBuffer[MAX_LOCAL_STRING_LEN + 1];
    };

    static std::vector<CDuiString> StrSplit(CDuiString text, CDuiString sp)
    {
        std::vector<CDuiString> vResults;
        int pos = text.Find(sp, 0);
        while (pos >= 0) {
            CDuiString t = text.Left(pos);
            vResults.push_back(t);
            text = text.Right(text.GetLength() - pos - sp.GetLength());
            pos = text.Find(sp);
        }
        vResults.push_back(text);
        return vResults;
    }
    /////////////////////////////////////////////////////////////////////////////////////
    //

    struct TITEM
    {
        CDuiString Key;
        LPVOID Data;
        struct TITEM* pPrev;
        struct TITEM* pNext;
    };

    class DUILIB_API CStdStringPtrMap
    {
    public:
        CStdStringPtrMap(int nSize = 83);
        ~CStdStringPtrMap();

        void Resize(int nSize = 83);
        LPVOID Find(LPCTSTR key, BOOL optimize = true) const;
        BOOL Insert(LPCTSTR key, LPVOID pData);
        LPVOID Set(LPCTSTR key, LPVOID pData);
        BOOL Remove(LPCTSTR key);
        void RemoveAll();
        int GetSize() const;
        LPCTSTR GetAt(int iIndex) const;
        LPCTSTR operator[] (int nIndex) const;

    protected:
        TITEM** m_aT;
        int m_nBuckets;
        int m_nCount;
    };

    /////////////////////////////////////////////////////////////////////////////////////
    //

    class DUILIB_API CWaitCursor
    {
    public:
        CWaitCursor();
        ~CWaitCursor();

    protected:
        HCURSOR m_hOrigCursor;
    };

    /////////////////////////////////////////////////////////////////////////////////////
    //

    class CDuiVariant : public VARIANT
    {
    public:
        CDuiVariant()
        {
            VariantInit(this);
        }
        CDuiVariant(int i)
        {
            VariantInit(this);
            this->vt = VT_I4;
            this->intVal = i;
        }
        CDuiVariant(float f)
        {
            VariantInit(this);
            this->vt = VT_R4;
            this->fltVal = f;
        }
        CDuiVariant(LPOLESTR s)
        {
            VariantInit(this);
            this->vt = VT_BSTR;
            this->bstrVal = s;
        }
        CDuiVariant(IDispatch* disp)
        {
            VariantInit(this);
            this->vt = VT_DISPATCH;
            this->pdispVal = disp;
        }

        ~CDuiVariant()
        {
            VariantClear(this);
        }
    };

    //////////////////////////////////////////////////////////////////////////////////////
    //
    static char* w2a(wchar_t* lpszSrc, UINT   CodePage = CP_ACP)
    {
        if (lpszSrc != NULL) {
            int  nANSILen = WideCharToMultiByte(CodePage, 0, lpszSrc, -1, NULL, 0, NULL, NULL);
            char* pANSI = new char[nANSILen + 1];
            if (pANSI != NULL) {
                ZeroMemory(pANSI, nANSILen + 1);
                WideCharToMultiByte(CodePage, 0, lpszSrc, -1, pANSI, nANSILen, NULL, NULL);
                return pANSI;
            }
        }
        return NULL;
    }

    static wchar_t* a2w(char* lpszSrc, UINT   CodePage = CP_ACP)
    {
        if (lpszSrc != NULL) {
            int nUnicodeLen = MultiByteToWideChar(CodePage, 0, lpszSrc, -1, NULL, 0);
            LPWSTR pUnicode = new WCHAR[nUnicodeLen + 1];
            if (pUnicode != NULL) {
                ZeroMemory((void*)pUnicode, (nUnicodeLen + 1) * sizeof(WCHAR));
                MultiByteToWideChar(CodePage, 0, lpszSrc, -1, pUnicode, nUnicodeLen);
                return pUnicode;
            }
        }
        return NULL;
    }

    ///////////////////////////////////////////////////////////////////////////////////////
    ////
    //struct TImageInfo;
    //class CPaintManagerUI;
    //class UILIB_API CImageString
    //{
    //public:
    //	CImageString();
    //	CImageString(const CImageString&);
    //	const CImageString& operator=(const CImageString&);
    //	virtual ~CImageString();

    //	const CDuiString& GetAttributeString() const;
    //	void SetAttributeString(LPCTSTR pStrImageAttri);
    //	void ModifyAttribute(LPCTSTR pStrModify);
    //	BOOL LoadImage(CPaintManagerUI* pManager);
    //	BOOL IsLoadSuccess();

    //	RECT GetDest() const;
    //	void SetDest(const RECT &rcDest);
    //	const TImageInfo* GetImageInfo() const;

    //private:
    //	void Clone(const CImageString&);
    //	void Clear();
    //	void ParseAttribute(LPCTSTR pStrImageAttri);

    //protected:
    //	friend class CRenderEngine;
    //	CDuiString	m_sImageAttribute;

    //	CDuiString	m_sImage;
    //	CDuiString	m_sResType;
    //	TImageInfo	*m_imageInfo;
    //	BOOL		m_bLoadSuccess;

    //	RECT	m_rcDest;
    //	RECT	m_rcSource;
    //	RECT	m_rcCorner;
    //	BYTE	m_bFade;
    //	DWORD	m_dwMask;
    //	BOOL	m_bHole;
    //	BOOL	m_bTiledX;
    //	BOOL	m_bTiledY;
    //};
}// namespace DuiLib

#endif // __UTILS_H__