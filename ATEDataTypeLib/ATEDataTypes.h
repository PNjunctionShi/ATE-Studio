#pragma once
#include "ATEDataTypeLib_i.h"
#include "atlbase.h"
#include "atlcoll.h"


using namespace ATL;

class CUnit :
	public IATEBaseData
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

public:
	virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_StrValue( /* [retval][out] */ BSTR *pVal);
	virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_StrValue( /* [in] */ BSTR newVal);
	virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( /* [retval][out] */ DOUBLE *pVal);
};

