
#pragma once





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
	template <class T> T * RetrieveSymbol(const AString &);
private:
	void * m_Handle;
};




