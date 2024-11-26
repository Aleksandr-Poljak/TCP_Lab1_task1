#include <windows.h>
#include "Cmath.h"

// Realization of CMath class methods

CMath::CMath()
{
	m_lRef = 0;
	InterlockedIncrement(&g_lObjs);
}
CMath::~CMath()
{
	InterlockedDecrement(&g_lObjs);
}

STDMETHODIMP CMath::QueryInterface(REFIID riid, void** ppv)
{
	*ppv = 0;
	if (riid == IID_IUnknown || riid == IID_IMath)
		*ppv = this;
	if (*ppv)
	{
		AddRef();
		return(S_OK);
	}
	return (E_NOINTERFACE);
}
STDMETHODIMP_(ULONG) CMath::AddRef()
{
	return InterlockedIncrement(&m_lRef);
}
STDMETHODIMP_(ULONG) CMath::Release()
{
	if (InterlockedDecrement(&m_lRef) == 0)
	{
		delete this;
		return 0;
	}
}

STDMETHODIMP CMath::Add(long lOp1, long lOp2, long* pResult)
{
	*pResult = lOp1 + lOp2;
	return S_OK;
}
STDMETHODIMP CMath::Sub(long lOp1, long lOp2, long*
	pResult)
{
	*pResult = lOp1 - lOp2;
	return S_OK;
}
STDMETHODIMP CMath::Mul(long lOp1, long lOp2, long*
	pResult)
{
	*pResult = lOp1 * lOp2;
	return S_OK;
}
STDMETHODIMP CMath::Divide(long lOp1, long lOp2, long* pResult
)
{
	*pResult = lOp1 / lOp2;
	return S_OK;
}

// Realization of CMath class MathClassFactory

MathClassFactory::MathClassFactory()
{
	m_lRef = 0;
}
MathClassFactory::~MathClassFactory()
{
}
STDMETHODIMP MathClassFactory::QueryInterface(REFIID riid,
	void** ppv)
{
	*ppv = 0;
	if (riid == IID_IUnknown || riid == IID_IClassFactory)
		*ppv = this;
	if (*ppv)
	{
		AddRef();
		return S_OK;
	}
	return(E_NOINTERFACE);
}
STDMETHODIMP_(ULONG) MathClassFactory::AddRef()
{
	return InterlockedIncrement(&m_lRef);
}

STDMETHODIMP_(ULONG) MathClassFactory::Release()
{
	if (InterlockedDecrement(&m_lRef) == 0)
	{
		delete this;
		return 0;
	}
	return m_lRef;
}

STDMETHODIMP MathClassFactory::CreateInstance
(LPUNKNOWN pUnkOuter, REFIID riid, void** ppvObj)
{
	CMath* pMath;
	HRESULT hr;
	*ppvObj = 0;
	pMath = new CMath;
	if (pMath == 0)
		return(E_OUTOFMEMORY);
	hr = pMath->QueryInterface(riid, ppvObj);
	if (FAILED(hr))
		delete pMath;
	return hr;
}

STDMETHODIMP MathClassFactory::LockServer(BOOL fLock)
{
	if (fLock)
		InterlockedIncrement(&g_lLocks);
	else
		InterlockedDecrement(&g_lLocks);
	return S_OK;
}
