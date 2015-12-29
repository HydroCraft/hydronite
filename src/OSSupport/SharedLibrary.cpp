
#include "Globals.h"

#include "SharedLibrary.h"

// Windows.h is already included by Globals.h if compiled under Windows.
#ifndef _WIN32
#include <dlfcn.h>
#endif // _WIN32





cSharedLibrary::cSharedLibrary() :
	m_Handle(nullptr)
{
}





cSharedLibrary::cSharedLibrary(const AString & a_LibName) :
	m_Handle(nullptr)
{
	Load(a_LibName);
}





cSharedLibrary::~cSharedLibrary()
{
	if(m_Handle)
	{
		Close();
	}
	m_Handle = nullptr;
}





bool cSharedLibrary::Load(const AString & a_LibName)
{
#ifdef _WIN32
	// TODO: Implement Windows DLL loading routine.
#else
	m_Handle = dlopen(a_LibName.c_str(), RTLD_LOCAL | RTLD_LAZY);
#endif // _WIN32

	return m_Handle != nullptr;
}





void cSharedLibrary::Close()
{
	if(!m_Handle)
	{
		return;
	}

#ifdef _WIN32
	// TODO: Implement Windows DLL un-loading routine.
#else
	dlclose(m_Handle);
#endif // _WIN32
}





bool cSharedLibrary::IsLoaded() const
{
	return m_Handle != nullptr;
}





template <class T>
T * cSharedLibrary::RetrieveSymbol(const AString & a_SymbolName)
{
	T * Symbol = nullptr;
#ifdef _WIN32
	// TODO: Implement Windows symbol retrieval.
#else
	Symbol = (T *) dlsym(m_Handle, a_SymbolName.c_str());
	if(dlerror())
	{
		return nullptr;
	}
#endif
	return Symbol;
}




