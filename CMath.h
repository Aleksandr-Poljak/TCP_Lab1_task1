#pragma once
#include "IMath.h"

extern long g_lObjs;
extern long g_lLocks;

class CMath : public IMath
{
protected:
	// Reference count
	long m_lRef;

public:
	CMath();
	~CMath();
public:
	// IUnknown
	STDMETHOD(QueryInterface(REFIID, void**));
	STDMETHOD_(ULONG, AddRef());
	STDMETHOD_(ULONG, Release());

	// IMath
	STDMETHOD(Add(long, long, long*));
	STDMETHOD(Sub(long, long, long*));
	STDMETHOD(Mul(long, long, long*));
	STDMETHOD(Divide(long, long, long*));
};

class MathClassFactory : public IClassFactory
{
protected:
	long m_lRef;

public:
	MathClassFactory();
	~MathClassFactory();

	// IUnknown
	STDMETHOD(QueryInterface(REFIID, void**));
	STDMETHOD_(ULONG, AddRef());
	STDMETHOD_(ULONG, Release());
	// IClassFactory
	STDMETHOD(CreateInstance(LPUNKNOWN, REFIID, void**));
	STDMETHOD(LockServer(BOOL));
};
