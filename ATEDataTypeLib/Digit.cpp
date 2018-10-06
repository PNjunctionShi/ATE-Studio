#include "stdafx.h"
#include "ATEDataTypes.h"
#include "atlcoll.h"
#include "stdlib.h"
#include <comutil.h> 
#pragma comment(lib, "comsuppw.lib") 

using namespace ATL;

CDigit::CDigit()
{
}


CDigit::~CDigit()
{
}

HRESULT CDigit::get_StrValue(BSTR * pVal)
{
	pVal = &m_bstrValue;
	return S_OK;
}

HRESULT CDigit::put_StrValue(BSTR newVal)
{
	m_bstrValue=newVal;
	return S_OK;
}

HRESULT CDigit::get_Value(DOUBLE * pVal)
{
	*pVal = atof(_com_util::ConvertBSTRToString(m_bstrValue));
	return S_OK;
}

HRESULT CDigit::get_SubLeft(IATEBaseData ** pVal)
{
	*pVal = NULL;
	return S_OK;
}

HRESULT CDigit::get_SubRight(IATEBaseData ** pVal)
{
	*pVal = NULL;
	return S_OK;
}

STDMETHODIMP CDigit::SetSubLeft(dsBaseDataType DataType, IATEBaseData ** pSubLeft)
{
	*pSubLeft = NULL;
	return S_OK;
}

STDMETHODIMP CDigit::SetSubRight(dsBaseDataType DataType, IATEBaseData ** pSubRight)
{
	*pSubRight = NULL;
	return S_OK;
}
