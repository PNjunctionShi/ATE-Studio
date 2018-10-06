#pragma once
#include "resource.h"
#include "ATEDataTypeLib_i.h"
#include "atlbase.h"
#include "atlcoll.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;

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