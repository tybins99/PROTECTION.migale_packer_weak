#ifndef argv_140
#define argv_140

#include <string>
#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <math.h>
#include <cstdio>
#include <string>
#include <list>
#include <vector>
#include <cstdint>
#include "argv_118.h"
#include "..\\Lib\\argv_130.hpp"

const int32_t argv_683 			= 65536;
const int32_t argv_678	= 127;

#define argv_872 _snprintf

enum argv_816 {
	argv_277,
	argv_279,
	argv_821,
	argv_763,
	argv_250,
	argv_861,
};

using namespace std;

class argv_194
{
	private:
		vector<uint8_t> argv_913;
		vector<uint8_t> argv_293;
		string argv_212;
		string argv_727;
		int32_t size;
		
		union argv_178 {
	    	int argv_165;
			short argv_175;
		    char argv_176[4];
		};
	public:
		argv_194();

		void 	argv_152 (uint8_t);
		void 	argv_151 (uint8_t);
		
		void 	argv_864 (string);
		void 	argv_863 (string);
		void 	argv_866 (int32_t);
		void	set (int32_t, string name_arg);
		void 	set (int32_t, string name_arg, string comment_arg);
		
		string 	argv_336();
		string	argv_321();
		vector<uint8_t> argv_346();
		vector<uint8_t> * argv_347();
		vector<uint8_t> argv_331();
		int32_t 	argv_344();
		bool 	argv_305(); // compare argv_913 and expected argv_913 if expected argv_913 is not empty

		void 	clear();

		friend ostream& operator << (ostream&, argv_194&);
		void argv_271 (HWND hDlg);
};

class argv_202  
{
	private:
		vector<argv_194>	argv_907;
		bool argv_310;
		uint32_t argv_246;
		string argv_727;

	public:
		argv_202();
		void clear();
		int32_t size();

		void argv_864(string);
		string argv_336();
		
		void argv_154 (const argv_194&);
		bool argv_268 (string argv_727);

		bool argv_323 (string, argv_194 *&);
		bool argv_332 (argv_194 *&);
		bool argv_341 (argv_194 *&);	

		friend ostream& operator << (ostream&, argv_202&);
		void argv_271 (HWND hDlg);
};

class argv_227
{
	private:
		union argv_178 {
	    	int argv_165;
			short argv_175;
		    char argv_176[4];
		};
		
		argv_178			argv_177;	
		int32_t			argv_746;
		int32_t			argv_744;
		int32_t			argv_732;
		int32_t			argv_735;
		int32_t			argv_894;
		char 			argv_186[argv_683];
		FILE * 			argv_312;
		string 			argv_309;
		argv_194	*		argv_245;
		string			argv_247;
		stack<string>	argv_824;
		bool			argv_912;
		bool			argv_910;
		string			argv_287;

		argv_202			argv_276;
		argv_202			argv_278;
		argv_202			argv_820;
		argv_202  		argv_762;
		vector<argv_202>	argv_249;
		vector<argv_202>	argv_862;
	
		void argv_830 (string);
		void argv_831 (string);
		
		bool argv_650 (int32_t, int32_t index=-1);	
		bool argv_647();
		bool argv_648(); // skipped 
		bool argv_651();
		bool argv_649();
		bool argv_646 ();
		bool argv_652();

		bool argv_299 (int32_t, vector<uint8_t> *);
		bool argv_828();
		bool argv_829();
		bool argv_827 ();
		void clear();
		
	public:
		argv_227();
		bool argv_645 (string);
		int32_t  argv_340();
		int32_t  argv_337();
		int32_t  argv_339();
		bool  argv_911();
		bool  argv_909();
		string argv_328 ();
		int32_t  argv_338();

		friend ostream& operator << (ostream&, argv_227&);
		void argv_271 (HWND hDlg);
};		



#endif // argv_140
