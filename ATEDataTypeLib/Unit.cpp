#include "stdafx.h"
#include "ATEDataTypes.h"

CUnit::CinitUnitTable CUnit::m_UnitTable;
CUnit::CinitUnitTable::CinitUnitTable()
{
	mUnitTable.SetAt(L"A", 1);
	mUnitTable.SetAt(L"mA", 1e-3);
	mUnitTable.SetAt(L"uA", 1e-6);
	mUnitTable.SetAt(L"nA", 1e-9);
	mUnitTable.SetAt(L"pA", 1e-12);
	mUnitTable.SetAt(L"V", 1);
	mUnitTable.SetAt(L"mV", 1e-3);
	mUnitTable.SetAt(L"uV", 1e-6);
	mUnitTable.SetAt(L"s", 1);
	mUnitTable.SetAt(L"ms", 1e-3);
	mUnitTable.SetAt(L"us", 1e-6);
	mUnitTable.SetAt(L"ns", 1e-9);
	mUnitTable.SetAt(L"ps", 1e-12);
	mUnitTable.SetAt(L"Hz", 1);
	mUnitTable.SetAt(L"KHz", 1e3);
	mUnitTable.SetAt(L"MHz", 1e6);
	mUnitTable.SetAt(L"GHz", 1e9);
	mUnitTable.SetAt(L"bps", 1);
	mUnitTable.SetAt(L"Kbps", 1e3);
	mUnitTable.SetAt(L"Mbps", 1e6);
	mUnitTable.SetAt(L"Gbps", 1e9);
}

CUnit::CinitUnitTable::~CinitUnitTable()
{

}

CUnit::CUnit()
{
}


CUnit::~CUnit()
{
}

HRESULT CUnit::get_StrValue(BSTR * pVal)
{
	pVal = &m_bstrValue;
	return S_OK;
}

HRESULT CUnit::put_StrValue(BSTR newVal)
{
	m_bstrValue.Attach(newVal);
	return S_OK;
}

HRESULT CUnit::get_Value(DOUBLE * pVal)
{
	*pVal= m_UnitTable.mUnitTable.Lookup(m_bstrValue)->m_value;
	return S_OK;
}
