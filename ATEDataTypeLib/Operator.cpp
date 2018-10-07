#include "stdafx.h"
#include "ATEDataTypes.h"
#include "atlcoll.h"

using namespace ATL;
COper::CinitOperTable COper::m_OperTable;
COper::CinitOperTable::CinitOperTable()
{
	mOperTable.SetAt(L"+", dsPlus);
	mOperTable.SetAt(L"-", dsSub);
	mOperTable.SetAt(L"*", dsMul);
	mOperTable.SetAt(L"/", dsDiv);
	mOperTable.SetAt(L"^", dsPow);
}

COper::CinitOperTable::~CinitOperTable()
{

}

COper::COper()
{
}


COper::~COper()
{
}

HRESULT COper::get_StrValue(BSTR * pVal)
{
	switch (m_Operator) 
	{
	case(dsPlus): {*pVal = L"+"; break; }
	case(dsSub): {*pVal = L"-"; break; }
	case(dsMul): {*pVal = L"*"; break; }
	case(dsDiv): {*pVal = L"/"; break; }
	case(dsPow): {*pVal = L"^"; break; }
	}
	return S_OK;
}

HRESULT COper::put_StrValue(BSTR newVal)
{
	m_Operator = m_OperTable.mOperTable.Lookup(newVal)->m_value;
	return S_OK;
}

HRESULT COper::get_Value(DOUBLE * pVal)
{
	DOUBLE left;
	DOUBLE right;
	HRESULT hr;
	hr = m_pSubLeft->get_Value(&left);
	hr = m_pSubRight->get_Value(&right);

	switch (m_Operator)
	{
	case(dsPlus): {*pVal = left + right; break; }
	case(dsSub): {*pVal = left - right; break; }
	case(dsMul): {*pVal = left * right; break; }
	case(dsDiv): {*pVal = left / right; break; }
	//case(dsPow): {*pVal = left ^ right; break; }
	}
	return S_OK;
}

HRESULT COper::get_SubLeft(IATEBaseData ** pVal)
{
	m_pSubLeft.CopyTo(pVal);
	return S_OK;
}

HRESULT COper::get_SubRight(IATEBaseData ** pVal)
{
	m_pSubRight.CopyTo(pVal);
	return S_OK;
}

STDMETHODIMP COper::SetSubLeft(dsBaseDataType DataType, IATEBaseData ** pSubLeft)
{
	CreateATEBaseData(DataType, m_pSubLeft);
	m_pSubLeft.CopyTo(pSubLeft);
	return S_OK;
}

STDMETHODIMP COper::SetSubRight(dsBaseDataType DataType, IATEBaseData ** pSubRight)
{
	CreateATEBaseData(DataType,m_pSubRight);
	m_pSubRight.CopyTo(pSubRight);
	return S_OK;
}

VOID COper::CreateATEBaseData(dsBaseDataType DataType, CComPtr<IATEBaseData>& p)
{
	switch (DataType)
	{
	case dsBaseDataType::dsData:
	{
		HRESULT hr = p.CoCreateInstance(__uuidof(Digit));
		break;
	}
	case dsBaseDataType::dsOper:
	{
		HRESULT hr = p.CoCreateInstance(__uuidof(Operator));
		break;
	}
	case dsBaseDataType::dsUnit:
	{
		HRESULT hr = p.CoCreateInstance(__uuidof(Unit));
		break;
	}
	}
	return VOID();
}
