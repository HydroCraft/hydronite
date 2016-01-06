
#pragma once





#include <dlfcn.h>
#include <map>





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

		if (m_SymbolCache.find(a_SymbolName) == m_SymbolCache.end())
		{
#ifdef _WIN32
			// TODO: Implement Windows symbol retrieval.
#else
			void * Symbol = dlsym(m_Handle, a_SymbolName.c_str());
			if (dlerror())
			{
				m_SymbolCache[a_SymbolName] = nullptr;
			}
#endif  // _WIN32
			m_SymbolCache[a_SymbolName] = Symbol;
		}

		return (T *) m_SymbolCache[a_SymbolName];
	}





private:
	void * m_Handle;

	std::map<AString, void*> m_SymbolCache;
};




