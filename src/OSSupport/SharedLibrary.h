
#pragma once





#include <dlfcn.h>





class cSharedLibrary
{
public:
	/** Constructs cSharedLibrary without loading a shared library. */
	cSharedLibrary();

	/** Constructs cSharedLibrary and loads the shared library with the given name. */
	cSharedLibrary(const AString &);

	/** If the shared lib handle is still open, the destructor will auto-close it. */
	~cSharedLibrary();

	bool Load(const AString &);
	void Close();
	bool IsLoaded() const;





	/** Retrieve symbol of type T in library. */
	template <class T>
	T * RetrieveSymbol(const AString & a_SymbolName)
	{
		ASSERT(IsLoaded());

		if (!IsLoaded())
		{
			return nullptr;
		}

		T * Symbol = nullptr;
#ifdef _WIN32
		// TODO: Implement Windows symbol retrieval.
#else
		Symbol = (T *) dlsym(m_Handle, a_SymbolName.c_str());
		if (dlerror())
		{
			return nullptr;
		}
#endif  // _WIN32
		return Symbol;
	}





private:
	void * m_Handle;
};




