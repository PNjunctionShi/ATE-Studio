#include "stdafx.h"
#include "ATEDataTypes.h"


STDMETHODIMP CATETable::debug1(BSTR* val)
{
	*val = ::SysAllocString(L"Hello World!");

	return S_OK;
}

