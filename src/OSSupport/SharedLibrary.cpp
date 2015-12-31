
#include "Globals.h"

#include "SharedLibrary.h"





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
	if (m_Handle)
	{
		Close();
	}
}





bool cSharedLibrary::Load(const AString & a_LibName)
{
	ASSERT(!IsLoaded());

	if (IsLoaded())
	{
		Close();
	}

#ifdef _WIN32
	// TODO: Implement Windows DLL loading routine.
#else
	m_Handle = dlopen(a_LibName.c_str(), RTLD_LOCAL | RTLD_LAZY);
#endif  // _WIN32

	return m_Handle != nullptr;
}





void cSharedLibrary::Close()
{
	if (!m_Handle)
	{
		return;
	}

#ifdef _WIN32
	// TODO: Implement Windows DLL un-loading routine.
#else
	dlclose(m_Handle);
#endif  // _WIN32
	m_Handle = nullptr;
}





bool cSharedLibrary::IsLoaded() const
{
	return m_Handle != nullptr;
}




