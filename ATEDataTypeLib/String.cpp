#include "stdafx.h"
#include "ATEDataTypes.h"

using namespace ATL;

CStr::CStr()
{
}


CStr::~CStr()
{
}

HRESULT CStr::get_StrValue(BSTR * pVal)
{
	pVal = &m_bstrValue;
	return S_OK;
}

HRESULT CStr::put_StrValue(BSTR newVal)
{
	m_bstrValue=newVal;
	return S_OK;
}

HRESULT CStr::get_Value(DOUBLE * pVal)
{
	*pVal = 0;
	return S_OK;
}

HRESULT CStr::get_SubLeft(IATEBaseData ** pVal)
{
	*pVal = NULL;
	return S_OK;
}

HRESULT CStr::get_SubRight(IATEBaseData ** pVal)
{
	*pVal = NULL;
	return S_OK;
}

STDMETHODIMP CStr::SetSubLeft(dsBaseDataType DataType, IATEBaseData ** pSubLeft)
{
	*pSubLeft = NULL;
	return S_OK;
}

STDMETHODIMP CStr::SetSubRight(dsBaseDataType DataType, IATEBaseData ** pSubRight)
{
	*pSubRight = NULL;
	return S_OK;
}
