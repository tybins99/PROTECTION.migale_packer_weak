#ifndef argv_138
#define argv_138



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

#include "..\\Lib\\argv_129.hpp"


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ namespace usage declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
using namespace std;



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ constants declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
enum argv_825 {
    argv_742,
    argv_919,
    argv_290,
    argv_163,
    argv_253,
    argv_741,
};



const int argv_660 = 256;


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ DESCRIPTION:
// @@ This object permits to open a log file,
// @@ save argv_248 into it, and close it.
// @@ It can be thread safe depending on the compilation
// @@ flags you choose.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class argv_207
{
	private:
		string  argv_853;
		FILE *	argv_312;
		bool	argv_658;
#if defined (THREAD_SAFE_LOG)
		CRITICAL_SECTION argv_239;
#endif
		char argv_885[argv_660];
		SYSTEMTIME argv_888;
		void argv_906 (bool _large_mode=false);
		void argv_627 ();
		void argv_628 (uint32_t);

	public:
		argv_207();
		virtual ~argv_207();
		bool argv_758 (string, bool _in_file=true);
		void argv_208 ();
		void argv_659 (uint32_t, const char *, bool _no_eol=false);
		void argv_659 (uint32_t, const char *, int32_t);
		void argv_659 (uint32_t, const char *, uint32_t);
		void argv_659 (uint8_t);
		void argv_659 (uint32_t, uint32_t, uint32_t);
		void argv_659 (uint32_t, const char *, const char *);
		void argv_659 (uint32_t, const char *, const char *, const char *);
		void argv_659 (uint32_t, const char *, const char *, const char *, const char *);
		//void argv_659 (uint32_t, const char *, uint64_t);

		void argv_659 (uint32_t, uint32_t);
		void argv_659 (const char *, bool _no_eol=false);
		void argv_659 (const char *, int32_t);
		void argv_659 (const char *, uint32_t);
		void argv_659(const char *, unsigned long);
		void argv_659 (const char *, const char *);
		void argv_659 (const char *, const char *, const char *);
		void argv_659 (const char *, const char *, const char *, const char *);
		//void argv_659 (const char *, uint64_t);
		void argv_657 (const char *);
};


#endif // argv_138



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
