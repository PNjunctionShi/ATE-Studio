// dllmain.h : Declaration of module class.

class CATEDataTypeLibModule : public ATL::CAtlDllModuleT< CATEDataTypeLibModule >
{
public :
	DECLARE_LIBID(LIBID_ATEDataTypeLibLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATEDATATYPELIB, "{FB69CD35-7DF3-46A9-8F37-C789C93D250A}")
};

extern class CATEDataTypeLibModule _AtlModule;
