// Demo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#import <ATEDataTypeLib.dll>

using namespace std;
using namespace ATEDataTypeLib;
int main()
{
	CLSID clsidr;
	CoInitialize(NULL);
	HRESULT hr = CLSIDFromProgID(OLESTR("ATEData.Operator"), &clsidr);
	IATEBaseData * ptrOperator;
	hr = CoCreateInstance(clsidr, NULL, CLSCTX_INPROC_SERVER,
		__uuidof(IATEBaseData), (LPVOID*)&ptrOperator);
	ptrOperator->put_StrValue(L"/");
	ptrOperator->SetSubLeft(dsData)->put_StrValue(L"0.002");
	ptrOperator->SetSubRight(dsUnit)->put_StrValue(L"MHz");
	DOUBLE aa;
	ptrOperator->get_Value(&aa);
	//DOUBLE aa = ptrOperator->SubRight->Value;
	cout << aa << endl;
	//BSTR aa= ptrATETable->debug1();

	//ptrATETable->debug1(& aa);
	//cout << aa << endl;
	CoUninitialize();
	//cin >> aa;
    return 0;
}

