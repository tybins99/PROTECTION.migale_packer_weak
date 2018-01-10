#ifndef argv_141
#define argv_141

//#include <Commdlg.h>
#include <Windows.h>
#include <commctrl.h>
#include <string>
#include <list>
#include <assert.h>
#include <io.h>
#include <fcntl.h>
#include <shlobj.h>
#include <vector>
#include <shellapi.h>
#include <WINNT.h>

#include "..\\Lib\\argv_129.hpp"
#include "..\\Lib\\argv_130.hpp"

using namespace std;

#define argv_680  4096

//------------------------------------------------------------
// these identifiers will permit to check installed components
//------------------------------------------------------------
enum argv_173 {
	argv_710,
	argv_695,
	argv_705,
	argv_708,
	argv_693,
	argv_696,
	argv_709,
	argv_697,
	argv_702,
	argv_714,
	argv_715,
	argv_712,
	argv_711,
	argv_698,
	argv_716,
	argv_718,
	argv_717,
	argv_704,
	argv_703,
	argv_707,
};

class argv_210
{
	private:
		HKEY				argv_361;
		LONG				argv_663;
		string				argv_880;
		SECURITY_ATTRIBUTES argv_852;
		DWORD				argv_282;
		string				argv_214;
		string				argv_316;

		bool				argv_374 (int);
		int					argv_868 (LPTSTR, char *, int, DWORD&, int);

	public:
		void clear();
		argv_210();
		/*
		bool uninstall_key_exists (const string&);
		bool add_uninstall_entry (const string&, const string&);
		bool del_uninstall_entry (const string&);
		*/
		bool argv_213 (int);
		bool argv_213();
		bool argv_153 (int, string, int, int); 
		bool argv_267 (int);
		bool argv_322 (int, string&, int&, int&);

		bool argv_348 (int, string, int32_t&);
		bool argv_348 (int, string, string&);
		bool argv_869 (int, string, int32_t);
		bool argv_869 (int, string, const char *);

		bool argv_334 (string&);
		bool argv_319 (string&);

		int argv_867 (LPTSTR file, DWORD&);
		int argv_865 (DWORD& _err);
		int argv_865 (HKEY, DWORD& _err);
};


#endif // argv_141