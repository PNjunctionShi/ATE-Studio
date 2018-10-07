#pragma once
#include "resource.h"
#include "ATEDataTypeLib_i.h"
#include "atlbase.h"
#include "atlcoll.h"
#include <list>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;
using namespace std;

class ATL_NO_VTABLE CUnit :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CUnit, &CLSID_Unit>,
	public IDispatchImpl<IATEBaseData, &IID_IATEBaseData, &LIBID_ATEDataTypeLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
private:
	class CinitUnitTable
	{
	public:
		CinitUnitTable();
		~CinitUnitTable();
	public:
		CRBMap<CComBSTR, DOUBLE> mUnitTable;
	};
private:
	CComBSTR m_bstrValue;
	static CinitUnitTable m_UnitTable;
public:
	CUnit();
	~CUnit();

	DECLARE_REGISTRY_RESOURCEID(IDR_UNIT)


	BEGIN_COM_MAP(CUnit)
		COM_INTERFACE_ENTRY(IATEBaseData)
		COM_INTERFACE_ENTRY(IDispatch)
	END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_StrValue( /* [retval][out] */ BSTR *pVal);
	virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_StrValue( /* [in] */ BSTR newVal);
	virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( /* [retval][out] */ DOUBLE *pVal);
	virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_SubLeft( /* [retval][out] */ IATEBaseData** pVal);
	virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_SubRight( /* [retval][out] */ IATEBaseData** pVal);
	STDMETHOD(SetSubLeft)(dsBaseDataType DataType, IATEBaseData** pSubLeft);
	STDMETHOD(SetSubRight)(dsBaseDataType DataType, IATEBaseData** pSubRight);


};

class ATL_NO_VTABLE CDigit :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDigit, &CLSID_Digit>,
	public IDispatchImpl<IATEBaseData, &IID_IATEBaseData, &LIBID_ATEDataTypeLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
private:
	CComBSTR m_bstrValue;
public:
	CDigit();
	~CDigit();

	DECLARE_REGISTRY_RESOURCEID(IDR_DIGIT)


	BEGIN_COM_MAP(CDigit)
		COM_INTERFACE_ENTRY(IATEBaseData)
		COM_INTERFACE_ENTRY(IDispatch)
	END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_StrValue( /* [retval][out] */ BSTR *pVal);
	virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_StrValue( /* [in] */ BSTR newVal);
	virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( /* [retval][out] */ DOUBLE *pVal);
	virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_SubLeft( /* [retval][out] */ IATEBaseData** pVal);
	virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_SubRight( /* [retval][out] */ IATEBaseData** pVal);
	STDMETHOD(SetSubLeft)(dsBaseDataType DataType, IATEBaseData** pSubLeft);
	STDMETHOD(SetSubRight)(dsBaseDataType DataType, IATEBaseData** pSubRight);


};

class ATL_NO_VTABLE CStr :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CStr, &CLSID_Digit>,
	public IDispatchImpl<IATEBaseData, &IID_IATEBaseData, &LIBID_ATEDataTypeLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
private:
	CComBSTR m_bstrValue;
public:
	CStr();
	~CStr();

	DECLARE_REGISTRY_RESOURCEID(IDR_STRING)


	BEGIN_COM_MAP(CStr)
		COM_INTERFACE_ENTRY(IATEBaseData)
		COM_INTERFACE_ENTRY(IDispatch)
	END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_StrValue( /* [retval][out] */ BSTR *pVal);
	virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_StrValue( /* [in] */ BSTR newVal);
	virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( /* [retval][out] */ DOUBLE *pVal);
	virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_SubLeft( /* [retval][out] */ IATEBaseData** pVal);
	virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_SubRight( /* [retval][out] */ IATEBaseData** pVal);
	STDMETHOD(SetSubLeft)(dsBaseDataType DataType, IATEBaseData** pSubLeft);
	STDMETHOD(SetSubRight)(dsBaseDataType DataType, IATEBaseData** pSubRight);


};

class ATL_NO_VTABLE COper :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<COper, &CLSID_Digit>,
	public IDispatchImpl<IATEBaseData, &IID_IATEBaseData, &LIBID_ATEDataTypeLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
private:
	class CinitOperTable
	{
	public:
		CinitOperTable();
		~CinitOperTable();
	public:
		CRBMap<CComBSTR, dsOperatorType> mOperTable;
	};
private:
	static CinitOperTable m_OperTable;
	dsOperatorType m_Operator;
	CComPtr<IATEBaseData> m_pSubLeft;
	CComPtr<IATEBaseData> m_pSubRight;
public:
	COper();
	~COper();

	DECLARE_REGISTRY_RESOURCEID(IDR_OPERATOR)


	BEGIN_COM_MAP(COper)
		COM_INTERFACE_ENTRY(IATEBaseData)
		COM_INTERFACE_ENTRY(IDispatch)
	END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_StrValue( /* [retval][out] */ BSTR *pVal);
	virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_StrValue( /* [in] */ BSTR newVal);
	virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( /* [retval][out] */ DOUBLE *pVal);
	virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_SubLeft( /* [retval][out] */ IATEBaseData** pVal);
	virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_SubRight( /* [retval][out] */ IATEBaseData** pVal);
	STDMETHOD(SetSubLeft)(dsBaseDataType DataType, IATEBaseData** pSubLeft);
	STDMETHOD(SetSubRight)(dsBaseDataType DataType, IATEBaseData** pSubRight);

private:
	VOID CreateATEBaseData(dsBaseDataType DataType, CComPtr<IATEBaseData> & p);

};

///////以下为ATE Column定义///////////////////
template <typename T>
struct _CopyVariantFromAdaptItf {
	static HRESULT copy(VARIANT* p1, const CAdapt< CComPtr<T> >* p2) {
		HRESULT hr = p2->m_T->QueryInterface(IID_IDispatch, (void**)&p1->pdispVal);
		if (SUCCEEDED(hr)) {
			p1->vt = VT_DISPATCH;
		}
		else {
			hr = p2->m_T->QueryInterface(IID_IUnknown, (void**)&p1->punkVal);
			if (SUCCEEDED(hr)) {
				p1->vt = VT_UNKNOWN;
			}
		}

		return hr;
	}

	static void init(VARIANT* p) { VariantInit(p); }
	static void destroy(VARIANT* p) { VariantClear(p); }
};

typedef CComEnumOnSTL<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT,
	_CopyVariantFromAdaptItf<IATEBaseData>,
	list< CAdapt< CComPtr<IATEBaseData> > > >
	CComEnumVariantOnListOfATEBaseData;

template <typename T>
struct _CopyItfFromAdaptItf {
	static HRESULT copy(T** p1, const CAdapt< CComPtr<T> >* p2) {
		if (*p1 = p2->m_T) return (*p1)->AddRef(), S_OK;
		return E_POINTER;
	}

	static void init(T** p) {}
	static void destroy(T** p) { if (*p) (*p)->Release(); }
};

typedef ICollectionOnSTLImpl<IDispatchImpl<IATEColumn, &IID_IATEColumn>,
	list< CAdapt< CComPtr<IATEBaseData> > >,
	IATEBaseData*,
	_CopyItfFromAdaptItf<IATEBaseData>,
	CComEnumVariantOnListOfATEBaseData>
	IATEColumnCollImpl;

class ATL_NO_VTABLE CATEColumn :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CATEColumn>, 
	public IATEColumnCollImpl
{
public:
	DECLARE_REGISTRY_RESOURCEID(IDR_ATECOLUMN)
	DECLARE_NOT_AGGREGATABLE(CATEColumn)
	DECLARE_PROTECT_FINAL_CONSTRUCT()

	BEGIN_COM_MAP(CATEColumn)
		COM_INTERFACE_ENTRY(IATEColumn)
		COM_INTERFACE_ENTRY(IDispatch)
	END_COM_MAP()
};

///////以上为ATE Column定义///////////////////



class ATL_NO_VTABLE CATETable :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CATETable, &CLSID_ATETable>,
	public IDispatchImpl<IATETable, &IID_IATETable, &LIBID_ATEDataTypeLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CATETable()
	{
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_ATETABLE)


	BEGIN_COM_MAP(CATETable)
		COM_INTERFACE_ENTRY(IATETable)
		COM_INTERFACE_ENTRY(IDispatch)
	END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:


	STDMETHOD(debug1)(BSTR* val);
};

OBJECT_ENTRY_AUTO(__uuidof(ATETable), CATETable)
//OBJECT_ENTRY_AUTO(__uuidof(Unit), CUnit)
//OBJECT_ENTRY_AUTO(__uuidof(Digit), CDigit)
//OBJECT_ENTRY_AUTO(__uuidof(Operator), COper)
//OBJECT_ENTRY_AUTO(__uuidof(String), CStr)