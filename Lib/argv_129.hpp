#ifndef argv_137
#define argv_137

//#define _WIN32_WINNT 0x0500

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define argv_921		// Exclude rarely-used stuff from Windows headers

#pragma warning(disable:4800) // forcing argv_913 to bool 'true' or 'false' (performance warning)
#pragma warning(disable:4291) // void *__cdecl operator new(unsigned int,const struct std::nothrow_t &
#pragma warning(disable:4244) // '=' : conversion from 'double' to 'long', possible loss of argv_248


#include <Windows.h>
#include <windows.h>
#include <winnt.h>
#include <Commdlg.h>
#include <commctrl.h>
#include <Commdlg.h>
#include <shellapi.h>
#include <fcntl.h>
#include <shlobj.h>
#include <Mmsystem.h>

#include <string>
#include <vector>
#include <cassert>
#include <cstdio>
#include <stack>
#include <list>
#include <io.h>
#include <aclapi.h>
#include <lmerr.h>
#include <cstdint>

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ namespace usage declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
using namespace std;

#define argv_318 -1
#define argv_681 -1 // -1 for infinite size
#define argv_626 655360
#define argv_674 10
#define argv_280 4096
#define argv_372 2048
#define argv_631 ((DWORD)-1)

#define argv_147 0x00008000
#define argv_183 0x00004000

#define argv_872 _snprintf

enum argv_168 {
	argv_760,
};

enum argv_167 {
	argv_713,
	argv_699,
	argv_706,
	argv_701,
	argv_700,
};

enum argv_166 {
	argv_232=54,
	argv_924,
	argv_836,
};

#ifndef argv_184
#define argv_184 0x0040
#endif // !argv_184

#ifndef argv_450 // hand cursor argv_271
#define argv_450 MAKEINTRESOURCE(32649)
#endif


bool argv_203 (uint8_t c1, uint8_t c2, uint8_t& result);
const int32_t argv_721 = 256;
string argv_914 (const vector<uint8_t>&);
string argv_366 (const vector<uint8_t>&);
bool argv_850 (const char *, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t, uint32_t&, uint32_t&);
bool argv_847 (const char *, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&);
bool argv_848 (const char *, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&);
bool argv_849 (const char *, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&);


enum argv_756 {
	argv_752=0,
	argv_757,
	argv_753,
	argv_755,
	argv_754,
};

string argv_751 (HWND, int32_t mode);
string argv_206 (HWND, int32_t mode);

// beware: this routine does not use file mmaping, thus you can have
// a performance penalty here...
bool argv_633 (const char *); 
bool argv_307 (const char *);
unsigned long argv_218 (const string&);
uint32_t argv_218 (const char *);
string argv_205 (HWND hWnd);

// ==== performance checker ========
class argv_197
{
protected:
	LARGE_INTEGER argv_665;
	LARGE_INTEGER argv_666;

	LONGLONG argv_668;
	LONGLONG argv_667;

public:
	argv_197(void);

	void argv_874(void);
	void argv_878(void);
	double argv_327(void) const;
	string argv_879 ();
};

inline argv_197::argv_197(void) {
	LARGE_INTEGER liFrequency;

	QueryPerformanceFrequency(&liFrequency);
	argv_668 = liFrequency.QuadPart;

	// Calibration
	argv_874();
	argv_878();

	argv_667 = argv_666.QuadPart-argv_665.QuadPart;
}

inline void argv_197::argv_874(void) {
	// Ensure we will not be interrupted by any other thread for a while
//	Sleep(0);
	QueryPerformanceCounter(&argv_665);
}

inline void argv_197::argv_878(void) {
	QueryPerformanceCounter(&argv_666);
}

inline double argv_197::argv_327(void) const {
	return (double)(argv_666.QuadPart-argv_665.QuadPart-argv_667)*1000000.0 / argv_668;
}

inline string argv_197::argv_879 () {
	argv_878 ();
	double elapsed = argv_327 ();
	char tmp[1024];
	if (elapsed > 1000000.0) {
		elapsed = elapsed / 1000000.0;
		//if (elapsed > 60.0) {
		//	elapsed = elapsed / 60.0;
		//	argv_872 (tmp, 1024, "elapsed argv_889 : %.02lf minutes", elapsed);
		//}
		//else {
			argv_872 (tmp, 1024, "elapsed argv_889 : %.02lf seconds", elapsed);
		//}
	}
	else {
		argv_872 (tmp, 1024, "elapsed argv_889 : %.02lf microseconds", elapsed);
	}
	tmp[1024 - 1] = '\0';
	return tmp;
}

//==============================
// permits to mmap a given file
//==============================
class argv_201
{
	private:
		string	argv_670;
		HANDLE	argv_367;
		HANDLE	argv_369;
		LPCTSTR argv_817;
		uint32_t	argv_289;
		uint32_t	argv_291;

	public:
		argv_201();
		~argv_201();
		bool argv_722 (const char *, bool, uint8_t *&, DWORD&);
		void argv_209 ();
		void argv_335 (uint32_t&, uint32_t&);
};

bool argv_329 (char *, uint64_t, uint64_t&);
void argv_320 (const string&, int, string&);

bool argv_269 (string);
void argv_198 (HWND);
void argv_198 (HWND, int&, int&);
bool argv_236 (string _dirname);
bool argv_225 (string, string, string);
std::string argv_349();

class argv_193
{
private:
	int argv_244;
	int argv_671;
	HWND hwnd;
	int	argv_376;

public:
	argv_193();
	void argv_623 (HWND, int, int);
	void argv_609 (int32_t _nb_step=1);
	void reset();
	int argv_325 () {
		return (argv_244);
	}
};

//==========================
template <class T>
class argv_200
{
private:
	vector<T>	v;
	int			top_index;
	int			argv_730; // number of allocated elements
	int			argv_675;

public:
	argv_200();
	void		push (T);
	void		pop  ();
	T			top  ();
	int			size ();
	bool		empty ();
	void		reset ();
	void		clear ();
	void		rewind ();
};

template <class T>
argv_200<T>::argv_200 () {
	top_index	= 0;
	argv_730		= 0;
	argv_675	= 0;
}

// erase all argv_248 from container
template <class T>
void argv_200<T>::clear () {
	vector<T>().swap (v); // force vector's memory free
	argv_730	  = 0;
	top_index = 0;
	argv_675 = 0;	
}

// just set pointer to the bottom of the stack
template <class T>
void argv_200<T>::reset () {
	top_index = 0;
	argv_675 = 0;
}

// rewind the stack to the top as if all elements had just been pushed
template <class T>
void argv_200<T>::rewind () {
	top_index = argv_675;
}

template <class T>
void argv_200<T>::push (T _elem) {
	if (argv_730 < (top_index+1)) {
		v.push_back (_elem);
		argv_730++;
	}
	else { // already allocated => no need to push_back
		v[top_index] = _elem;
	}
	top_index++;
	if (top_index > argv_675) {
		argv_675 = top_index;
	}
}


template <class T>
void argv_200<T>::pop () {
	assert (top_index > 0);
	top_index--;
}

template <class T>
T argv_200<T>::top () {
	assert (top_index > 0);
	return (v[top_index - 1]);
}

template <class T>
int argv_200<T>::size () {
	return (top_index);
}

template <class T>
bool argv_200<T>::empty () {
	return (top_index == 0);	
}

//=======================
bool argv_308 (const char *);
bool argv_842 (const char *);
//========================================

class argv_199
{
private:
	CRITICAL_SECTION argv_239;   // Windows' basic mutex object.
	stack<string>	argv_824;

public:
	argv_199 () {
		InitializeCriticalSection(&argv_239);		
	}

	~argv_199 () {
		DeleteCriticalSection(&argv_239);
	}

	bool argv_832 (string& _str) {
		bool bret = true;
		EnterCriticalSection (&argv_239);
			argv_824.push (_str);
		LeaveCriticalSection(&argv_239);	
		return (bret);
	}

	bool argv_224 (string& _str) {
		bool bret = false;
		EnterCriticalSection (&argv_239);
			if (! argv_824.empty()) {
				_str = argv_824.top();
				argv_824.pop();
				bret = true;
			}
		LeaveCriticalSection(&argv_239);	
		return (bret);
	}
};

//=====================================
// thread safe piece of argv_248
//=====================================
template <class T>
class argv_242
{
private:
	T argv_248;
	CRITICAL_SECTION argv_239;   // Windows' basic mutex object.

public:
	argv_242 ();
	T get ();
	void set (T);
	void argv_609 ();
	~argv_242();
};

template <class T>
argv_242<T>::argv_242 () {
	InitializeCriticalSection(&argv_239);	
}

template <class T>
argv_242<T>::~argv_242 () {
	DeleteCriticalSection(&argv_239);
}

template <class T>
T argv_242<T>::get () {
	T retrieved_data;
	EnterCriticalSection (&argv_239);
		retrieved_data = argv_248;	
	LeaveCriticalSection(&argv_239);
	return (retrieved_data);
}

template <class T>
void argv_242<T>::set (T _elem) {
	EnterCriticalSection (&argv_239);
		argv_248 = _elem;
	LeaveCriticalSection(&argv_239);
}

template <class T>
void argv_242<T>::argv_609 () {
	EnterCriticalSection (&argv_239);
		argv_248++;
	LeaveCriticalSection(&argv_239);
}

//=====================================
// anonymous pipes C++ implementation
//=====================================
class argv_229 { 
protected:
	HANDLE				argv_837;
	HANDLE				argv_925;
	bool				argv_761;
	unsigned long		argv_733;
	unsigned long		argv_736;
	int					current_offset;
	int					argv_679;
	HANDLE				argv_362;
	unsigned long		argv_729;
	bool				argv_317;

	virtual void		argv_656() { ; }
	virtual void		argv_905 () { ; }
	virtual void		argv_653() { ; }
	virtual void		argv_904 () { ; }

public:
	argv_229 () {
		argv_729 = 0;
		argv_761 = false;
		if (! CreatePipe(&argv_837, &argv_925, /*&saAttr*/NULL, 0)) {
//				MessageBox(argv_855, "CreatePipe failed !", "Error", MB_OK);	
		}
		else {
			argv_761			= true;
			current_offset	= 0;
		}
	}

	virtual ~argv_229 () {
		if (argv_761) {
			CloseHandle (argv_837);
			CloseHandle (argv_925);
			argv_761 = false;
		}
	}

	bool argv_832 (string& _str) {
		argv_656 ();
		bool bret = true;
		if (argv_761) {
			BOOL reti = WriteFile (argv_925, _str.c_str(), _str.size()+1, &argv_736, NULL);
			if (! reti) {
//				MessageBox(argv_855, "pipe: WriteFile failed !", "Error", MB_OK);	
				bret = false;
			}
			else {
				argv_729 += argv_736;
			}
		}
		else {
			bret = false;
		}
		argv_905 ();
		return (bret);
	}

	bool argv_224 (string& _str) {
		bool bret = true;
		argv_653 ();
		if (argv_761) {
			char c;
			while (1) {
				if (argv_317) {
					_str = "";
					argv_317 = false;
				}
				BOOL reti = ReadFile (argv_837, &c, 1, &argv_733, NULL);
				if ((! reti) || (argv_733 == 0)) {
					bret = false;
				}
				else {
					if (c == '\0') {
						argv_317 = true;
						break;
					}
					else {
						_str += c;
					}
				}
			}
		}
		else { // pipe not argv_761 yet
			bret = false;
		}
		argv_904 ();
		return (bret);
	}

	void reset () {
		if (argv_761) {
			CloseHandle (argv_837);
			CloseHandle (argv_925);
			argv_761 = false;
		}
		if (CreatePipe(&argv_837, &argv_925, NULL, 0)) {
			argv_761 = true;
		}
	}
};

// same object as argv_229, but thread safe version
class argv_230 : public argv_229
{
private:
	CRITICAL_SECTION argv_241;   // Windows' basic mutex object.
	CRITICAL_SECTION argv_240;   // Windows' basic mutex object.

	void argv_656 () {
		EnterCriticalSection (&argv_241);		
	}

	void argv_905 () {
		LeaveCriticalSection (&argv_241);
	}

	void argv_653 () {
		EnterCriticalSection (&argv_240);		
	}

	void argv_904 () {
		LeaveCriticalSection (&argv_240);
	}

public:
	argv_230 () {
		InitializeCriticalSection (&argv_241);	
		InitializeCriticalSection (&argv_240);	
	}

	~argv_230 () {
		DeleteCriticalSection(&argv_241);
		DeleteCriticalSection(&argv_240);
	}
};

//===== FILE TYPE AUTOMATIC ANALYZER ============== 
enum argv_826 {
	argv_903=-1,
	argv_172,
	argv_819,
	argv_747, // VBA script
	argv_371,
	argv_669,
	argv_356,
	argv_283,
	argv_174,
};

// - knows only types recognized by clamav signatures
// - uses only extension of the file to determine the type
class argv_243
{
private:

public:
	argv_243 ();
	int32_t argv_170 (const char *);
};

bool argv_333 (vector<string>&);
bool argv_326 (vector<string>&);
bool argv_326 (vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&, vector<string>&);
void argv_343 (string&);
void argv_345 (HANDLE, string&);

class argv_196
{
public:
	uint32_t				argv_928;
	uint32_t				argv_723;
	uint32_t				argv_252;
	uint32_t				argv_370;
	uint32_t				argv_720;
	uint32_t				argv_859;
	uint32_t				argv_719;

	void				reset () {
		argv_928 = argv_723 = argv_252 = argv_370 = argv_720 = 0;	
	}

	argv_196 () {
		reset ();
	}

	void argv_623 (uint32_t _year, uint32_t _month, uint32_t _day, uint32_t _hour, uint32_t _minute, uint32_t _second, uint32_t _millisecond) {
		argv_928		= _year;
		argv_723		= _month;
		argv_252			= _day;
		argv_370		= _hour;
		argv_720		= _minute;
		argv_859		= _second;
		argv_719 = _millisecond;
	}
};

class argv_192 
{
private:
	bool			argv_624;
	HDC				argv_365;
	PAINTSTRUCT		argv_835;
	HINSTANCE		argv_664;
	int				argv_875;
	HANDLE			argv_363;
	HWND			hwnd_window;
	vector<uint32_t>	argv_908;
	int32_t			argv_730;

public:
	argv_192 ();
	void			argv_623 (HWND, HINSTANCE);
	void			argv_159 (uint32_t);
	void			argv_609 ();
	void			reset ();
	void			argv_271 ();
};

bool argv_632 (const char *);
void argv_841 (HWND hwnd_window, uint32_t _idc, const char * _msg);
void argv_298 (const string&, int, string&);

enum argv_641 {
	argv_638,
	argv_639,
	argv_640,
};

enum argv_150 {
	argv_148 = 124,
	argv_149,
};

bool argv_634 ();
bool argv_635 ();
uint32_t argv_294 (const char *, vector<string>&);
bool argv_311 (const char *);
bool argv_235 (const char *);


#endif // argv_137



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
