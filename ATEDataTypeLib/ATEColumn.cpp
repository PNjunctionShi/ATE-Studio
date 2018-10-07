#include "stdafx.h"
#include "ATEDataTypes.h"

using namespace ATL;

STDMETHODIMP CATEColumn::SetSize(LONG n)
{
	m_coll.resize(n);
	return S_OK;
}