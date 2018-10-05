#include "stdafx.h"
#include "ATEDataTypes.h"


STDMETHODIMP CATETable::debug1(BSTR* val)
{
	*val = ::SysAllocString(L"Hello World!");
	IATEBaseData* aaa;
	HRESULT hr = CUnit::CreateInstance(&aaa);
	//aaa->put_StrValue(L"KHz");
	CComPtr<IATEBaseData> pt = aaa;
	pt->put_StrValue(L"KHz");
	DOUBLE bbb;
	hr = pt->get_Value(&bbb);
	return S_OK;
}

