#pragma once
#include "objbase.h"

// {64707F09-D519-428F-89CF-5B774871C8CC}
DEFINE_GUID(CLSID_Math,
	0x64707f09, 0xd519, 0x428f, 0x89, 0xcf, 0x5b, 0x77, 0x48, 0x71, 0xc8, 0xcc);

// {20846773-B7E3-49D3-89A1-1397B7B868CD}
DEFINE_GUID(IID_IMath,
	0x20846773, 0xb7e3, 0x49d3, 0x89, 0xa1, 0x13, 0x97, 0xb7, 0xb8, 0x68, 0xcd);



class IMath : public IUnknown
{
public: 
	STDMETHOD(Add(long, long, long*)) PURE;
	STDMETHOD(Sub(long, long, long*)) PURE;
	STDMETHOD(Mul(long, long, long*)) PURE;
	STDMETHOD(Divide(long, long, long*)) PURE;
};