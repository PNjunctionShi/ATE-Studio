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
	HRESULT hr = CLSIDFromProgID(OLESTR("ATEData.ATETable"), &clsidr);
	IATETable * ptrATETable;
	hr = CoCreateInstance(clsidr, NULL, CLSCTX_INPROC_SERVER,
		__uuidof(IATETable), (LPVOID*)&ptrATETable);
	cout << "aa" << endl;
	BSTR aa= ptrATETable->debug1();
	//ptrATETable->debug1(& aa);
	//cout << aa << endl;
	CoUninitialize();
    return 0;
}

