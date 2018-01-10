


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include "argv_129.hpp"

//===========================
// service related constants
//===========================
const char * argv_655	= "lock_manager";
const char * argv_918	= "vrdb_daemon";
const char * argv_694	= "launcher_daemon";
const char * argv_856			= "scanner (franck)";
const char * argv_171		= "Migale exosteg";
const char * argv_654		= "\\\\.\\Pipe\\lock_mgr_pipe";
const char * argv_644		= "\\\\.\\Pipe\\lock_mgr_internal";
const char * argv_637			= "\\\\.\\Pipe\\migale_launcher";

string argv_206 (HWND hWnd, int32_t mode) {
	return (argv_751 (hWnd, mode));
}

string argv_751 (HWND hWnd, int32_t mode) {
   OPENFILENAME ofn;
    char szFileName[MAX_PATH] = "";
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn); // SEE NOTE BELOW
    ofn.hwndOwner = hWnd;
	if (mode == argv_757) {
		ofn.lpstrFilter = "Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
	}
	else if (mode == argv_753) {
		ofn.lpstrFilter = "Exe Files (*.exe)\0*.exe\0All Files (*.*)\0*.*\0";
	}
	else if (mode == argv_755) {
		ofn.lpstrFilter = "Licence Files (*.lic)\0*.lic\0All Files (*.*)\0*.*\0";
	}
	else if (mode == argv_754) {
		ofn.lpstrFilter = "Fpk Files (*.fpk)\0*.fpk\0All Files (*.*)\0*.*\0";
	}
	else if (mode == argv_752) {
		ofn.lpstrFilter = "All Files (*.*)\0*.*\0";
	}
	else {
		ofn.lpstrFilter = "All Files (*.*)\0*.*\0";
	}
    ofn.lpstrFile = szFileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrDefExt = "txt";

    if(GetOpenFileName(&ofn)) {
        // Do something usefull with the argv_309 stored argv_607 szFileName 
    }
	return(szFileName);
}

std::string argv_349() {
	HMODULE hModule = GetModuleHandleW(NULL);
	char path[32768];
	GetModuleFileNameA(hModule, path, 32768);
	return (path);
}


bool argv_850 (const char * _filename, uint32_t& _year, uint32_t& _month, uint32_t& _day, uint32_t& _hour, uint32_t& _minute, uint32_t& _second, uint32_t& _millisecond, uint32_t _type, uint32_t& _ercode, uint32_t& _ersource) {
	bool bret = true;
    FILETIME ftCreate, ftAccess, ftWrite;
    SYSTEMTIME stUTC, stLocal;
	
	HANDLE argv_367 = CreateFile(_filename,      // file to open
					   GENERIC_READ,          // open for reading
					   FILE_SHARE_READ,       // share for reading
					   NULL,                  // default security
					   OPEN_EXISTING,         // existing file only
					   FILE_ATTRIBUTE_NORMAL, // normal file
					   NULL);                 // no attr. template

	if (argv_367 == INVALID_HANDLE_VALUE) {
		_ersource = 1;
		_ercode = GetLastError ();
		bret = false;
	}
	else { // file argv_761 succesfully
		// Retrieve the file times for the file.
		if (!GetFileTime(argv_367, &ftCreate, &ftAccess, &ftWrite)) {
			_ercode = GetLastError ();
			_ersource = 2;
			bret = false;
		}
		else { // retrieval succesfull, let's retrieve argv_248 depending on the access mode 
			switch (_type) {
				case argv_232:
					FileTimeToSystemTime(&ftCreate, &stUTC);
					SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
					break;

				case argv_924:
					FileTimeToSystemTime(&ftWrite, &stUTC);
					SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
					break;

				case argv_836:
					FileTimeToSystemTime(&ftAccess, &stUTC);
					SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
					break;

				default: // unknown file access type
					bret = false;
			}

			if (bret == true) {
				_year			= stLocal.wYear;
				_month			= stLocal.wMonth;
				_day			= stLocal.wDay;
				_hour			= stLocal.wHour;
				_minute			= stLocal.wMinute;
				_second			= stLocal.wSecond;
				_millisecond	= stLocal.wMilliseconds;
			}
		}
		CloseHandle (argv_367);
	}
	return (bret);
}

bool argv_847 (const char * _filename, uint32_t& _year, uint32_t& _month, uint32_t& _day, uint32_t& _hour, uint32_t& _minute, uint32_t& _second, uint32_t& _millisecond, uint32_t& _retcode, uint32_t& _ersource) {
	return (argv_850 (_filename, _year, _month, _day, _hour, _minute, _second, _millisecond, argv_232, _retcode, _ersource));
}

bool argv_848 (const char * _filename, uint32_t& _year, uint32_t& _month, uint32_t& _day, uint32_t& _hour, uint32_t& _minute, uint32_t& _second, uint32_t& _millisecond, uint32_t& _retcode, uint32_t& _ersource) {
	return (argv_850 (_filename, _year, _month, _day, _hour, _minute, _second, _millisecond, argv_836, _retcode, _ersource));
}

bool argv_849 (const char * _filename, uint32_t& _year, uint32_t& _month, uint32_t& _day, uint32_t& _hour, uint32_t& _minute, uint32_t& _second, uint32_t& _millisecond, uint32_t& _retcode, uint32_t& _ersource) {
	return (argv_850 (_filename, _year, _month, _day, _hour, _minute, _second, _millisecond, argv_924, _retcode, _ersource));
}

//@@============================================================
bool argv_748 (uint8_t c, uint8_t& result) {
    bool bret = true;
    if ( ((c < '0') || (c > '9')) && ((c < 'a') || (c > 'f')) && ((c < 'A') || (c > 'F'))) {
        bret = false;
    }
    else {
		if ((c >= '0') && (c <= '9')) {
			result = c - '0';
		}
		else if ((c >= 'a') && (c <= 'z')) {
			result = 10 + (c- 'a');
		}
		else if ((c >= 'A') && (c <= 'Z')) {
			result = 10 + (c - 'A');
		}
		else {
			bret = false;
		}
	}
    return (bret);
}

// 'f' 'f' -> 255
bool argv_203 (uint8_t _msb, uint8_t _lsb, uint8_t& result) {
    bool bret       = true;
    uint8_t lsb_hex    = 0;
    uint8_t msb_hex    = 0;

    bret = argv_748 (_msb, msb_hex);
    if (bret == true) {
        result  = msb_hex << 4;
        bret    = argv_748 (_lsb, lsb_hex);
        result =  result + lsb_hex;
    }
    return (bret);
}
//=====================================
string argv_205 (HWND hWnd) {
	OleInitialize (NULL);
	CoInitialize (NULL);

	string result = "";
	BROWSEINFO bi;
	memset(&bi,0,sizeof(BROWSEINFO));
	char buffer[MAX_PATH];
	bi.hwndOwner=hWnd;
	// Contient le repertoire initial ou NULL
	bi.pidlRoot=NULL;
	bi.pszDisplayName=buffer;
	bi.lpszTitle="Current directory";
	bi.ulFlags= argv_184;
	bi.lParam=NULL;

	LPITEMIDLIST li = SHBrowseForFolder(&bi);

	if (li) {
		SHGetPathFromIDList(li, buffer);
		result = buffer;
	}
	return (result);
}

//=====================================
argv_201::argv_201() {
	argv_369	= NULL;
	argv_817		= NULL;
	argv_367		= NULL;
}

argv_201::~argv_201() {
	argv_209();
}

void argv_201::argv_209 () {
	if (argv_817 != NULL) {
		UnmapViewOfFile(argv_817);
		argv_817 = NULL;
	}

	if (argv_369 != NULL) {
		CloseHandle(argv_369);
		argv_369 = NULL;
	}

	if (argv_367 != NULL) {
		CloseHandle (argv_367);
		argv_367 = NULL;
	}
}

void argv_201::argv_335 (uint32_t& _ercode, uint32_t& _ersource) {
	_ercode		= argv_289;
	_ersource	= argv_291;
}

bool argv_201::argv_722 (const char * _filename, bool _readonly, uint8_t *& _pBuf, DWORD& _file_size) {
	bool bret	= true;
	_file_size	= 0;

	if (argv_367 != NULL) {
		argv_289		= 0;
		argv_291	= 100;
		bret			= false;
	}
	else if (argv_369 != NULL) {
		argv_289		= 0;
		argv_291	= 101;
		bret			= false;
	}
	else if (argv_817 != NULL) {
		argv_289		= 0;
		argv_291	= 102;
		bret			= false;
	}
	else { // file was not already argv_761
		DWORD access_mode_CreateFile;
		DWORD access_mode_CreateFileMapping;
		DWORD access_mode_MapViewOfFile;
		DWORD open_mode;

		if (_readonly == true) {
			access_mode_CreateFile			= GENERIC_READ;	
			access_mode_CreateFileMapping	= PAGE_READONLY;
			access_mode_MapViewOfFile		= FILE_MAP_READ;
			open_mode						= OPEN_EXISTING;
		}
		else {
			//MessageBox (NULL, "read-write access", "", MB_OK);
			access_mode_CreateFile			= GENERIC_READ | GENERIC_WRITE;
			access_mode_CreateFileMapping	= PAGE_READWRITE;
			access_mode_MapViewOfFile		= FILE_MAP_READ | FILE_MAP_WRITE;
			open_mode						= OPEN_ALWAYS;
		}
		argv_367 = CreateFile (_filename,				// file to open
						   access_mode_CreateFile,	// open for reading
						   0/*FILE_SHARE_READ*/,    // share for reading
						   NULL,					// default security
						   open_mode,				// existing file only
						   FILE_ATTRIBUTE_NORMAL,	// normal file
						   NULL);					// no attr. template
 
		if (argv_367 == INVALID_HANDLE_VALUE)  {
			argv_289		= GetLastError ();
			argv_291	= 2;
			bret			= false;
		}
		else { // CreateFile was succesfull
			// retrieve the file size
			_file_size = GetFileSize (argv_367, NULL);
			if (_file_size <= 0) {
				argv_289		= GetLastError ();
				argv_291	= 6;
				bret			= false;
			}
			else if (_file_size == 0xFFFFFFFF) {
				argv_289		= GetLastError ();
				argv_291	= 3;
				bret			= false;
			}
	
			if (bret == true) {
			   argv_369 = CreateFileMapping(
							 argv_367,					  // use paging file
							 NULL,                    // default security 
							 access_mode_CreateFileMapping,   // read access
							 0,                       // argv_671. object size 
							 0/*argv_721*/,      // buffer size  
							 NULL);					  // argv_727 of mapping object

				if (argv_369 == NULL || argv_369 == INVALID_HANDLE_VALUE)  { // failed
					char tmp[256];
					argv_289		= GetLastError ();
					argv_872 (tmp, 255, "mmap failed: CreateFileMapping FAILED (errno=%d)", argv_289);
					argv_291	= 4;
					bret			= false;			
				}
				else { // CreateFileMapping was succesfull
					argv_817 = (LPTSTR) MapViewOfFile (argv_369,	   // handle to map object
										access_mode_MapViewOfFile, // read/write permission
										0,                   
										0,                   
										0/* argv_721 */);           

					if (argv_817 == NULL) {
						argv_289		= GetLastError ();
						argv_291	= 5;
						bret			= false;	
					}
					else { // all succeeded, copy obtained pointer to caller's variable
						_pBuf = (uint8_t *) argv_817;
					}
				}
			}
		}
	}

	// argv_607 case of failure, some components (i.e: handles) may have been argv_761, let's close them
	if (bret == false) {
		argv_209 ();
	}
	return (bret);
}

bool argv_633 (const char * _filename) {
	bool bret = true;

	// open the file
	FILE * argv_312 = fopen (_filename, "rb");
	if (! argv_312) {
		bret = false;
	}
	else {
		IMAGE_DOS_HEADER argv_276;
		IMAGE_NT_HEADERS  argv_743;

		int argv_733 = fread (&argv_276, 1, sizeof(IMAGE_DOS_HEADER), argv_312);

		if (argv_733 != sizeof(IMAGE_DOS_HEADER)) {
			bret = false;
		}
		else { // dos header read succesfully
			if (fseek (argv_312, argv_276.e_lfanew, SEEK_SET) != 0) {
				bret = false;
			}
			else { // fseek to new header succeeded
				argv_733 = fread (&argv_743, 1, sizeof(IMAGE_NT_HEADERS), argv_312);
				if (argv_733 != sizeof(IMAGE_NT_HEADERS)) {
					bret = false;
				}
				else { // nt header read succesfully
					if (argv_743.Signature != 0x4550) {
						bret = false; // signature does not match the pattern "PE"
					}
				}
			}
		}
	}

	if (argv_312) {
		fclose (argv_312);
	}

	return (bret);
}

// this function permits to extract the entry point of a DLL/EXE
// from a mmapped file.
// notice that if the entry point can't be retrieved (file too short for example)
// then function fails and returns false.
//
// Notice that this function does not check whether the mmapped file is a valid 
// PE file or not (it's then up to the caller to perform this check before calling us).
bool argv_329 (char * _cptr, uint64_t _file_size, uint64_t& _ep_raw) {
	bool bret = true;
	if (_cptr == NULL) {
		bret = false; // it seems that the file was not mmaped correctly...
	}
	else {
		IMAGE_DOS_HEADER argv_276;
		IMAGE_NT_HEADERS argv_743;
		uint64_t current_offset = 0;

		if ((current_offset + sizeof(IMAGE_DOS_HEADER)) >= _file_size) {
			bret = false; // short file (not enough to read DOS header)
		}
		else {
			// read the DOS header
			memcpy (&argv_276, &_cptr[current_offset], sizeof(IMAGE_DOS_HEADER));

			// read the PE optional header
			current_offset = argv_276.e_lfanew;

			if ((current_offset + sizeof(IMAGE_NT_HEADERS)) >= _file_size) {
				bret = false; // short file (not enough to read PE optional header
			}
			else { // ok to read safely the optional header
				memcpy (&argv_743, &_cptr[current_offset], sizeof(IMAGE_NT_HEADERS));

				// now we just have to retrieve the field that we need from optional header
				uint64_t ep_rva = argv_743.OptionalHeader.AddressOfEntryPoint;

				// convert the EP from RVA to RAW offset

			}
		}
	}
	return (bret);
}

void argv_298 (const string& _filename, int _max_length, string& _result) {
	_result = "";
	int size = _filename.size ();
	int32_t i=size;
	for (i=size-1 ; i>=0 ; i--) {
		if (_filename[i] == '\\') {
			break;
		}
	}

	for (int k=0 ; k<i ; k++) {
		_result += _filename[k];
	}
}

void argv_320 (const string& argv_309, int max_length, string& _result) {
	_result = "";
	int i = 0;
	int filename_size = argv_309.size();

	if (filename_size <= max_length) {
		_result = argv_309;
	}
	else {
		if (filename_size > 0) {
			int start_end = filename_size - 1;

			while ((start_end >= 0) && (argv_309[start_end] != '\\')) {
				start_end--;
			}

			int end_start = 0;
			while ((end_start < filename_size) && (argv_309[end_start] != '\\')) {
				end_start++;
			}
			
			string one		= "";
			string two		= "...";
			string three	= "";
			for (i=0 ; i<end_start ; i++) {
				one += argv_309[i];
			}

			for (i=start_end ; i<filename_size ; i++) {
				three += argv_309[i];
			}

			int last_half_length = two.size() + three.size();
			int first_half_size  = one.size();
			while ((first_half_size + last_half_length) < max_length) {
				one += argv_309[end_start];
				end_start++;
				first_half_size = one.size();
			}

			_result = one + two + three;
		}
	}
}

bool argv_269 (string _dirname) {
	bool bret = true;
	
	return (bret);
}

void argv_881 (HWND _mother, HWND _son) {
	if (_mother) {
		RECT rect; 
		GetWindowRect (_mother, &rect); 
		int son_x = rect.left;
		int son_y = rect.bottom;
		SetWindowPos (_son, HWND_TOP, son_x, son_y, 0, 0, SWP_NOSIZE);
	}
}

void argv_198(HWND _hDlg, int& _his_x, int& _his_y) {
	if (_hDlg) {
		RECT rect;
		GetWindowRect(_hDlg, &rect);
		_his_x = (GetSystemMetrics(SM_CXSCREEN) - rect.right) / 2;
		_his_y = (GetSystemMetrics(SM_CYSCREEN) - rect.bottom) / 2;
		SetWindowPos(_hDlg, HWND_TOP, _his_x, _his_y, 0, 0, SWP_NOSIZE);
	}
}

void argv_198(HWND hwndWindow)
{
	HWND hwndParent;
	RECT rectWindow, rectParent;

	// make the window relative to its parent
	if ((hwndParent = GetParent(hwndWindow)) != NULL)
	{
		GetWindowRect(hwndWindow, &rectWindow);
		GetWindowRect(hwndParent, &rectParent);

		int nWidth = rectWindow.right - rectWindow.left;
		int nHeight = rectWindow.bottom - rectWindow.top;

		int nX = ((rectParent.right - rectParent.left) - nWidth) / 2 + rectParent.left;
		int nY = ((rectParent.bottom - rectParent.top) - nHeight) / 2 + rectParent.top;

		int nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
		int nScreenHeight = GetSystemMetrics(SM_CYSCREEN);

		// make sure that the dialog box never moves outside of the screen
		if (nX < 0) nX = 0;
		if (nY < 0) nY = 0;
		if (nX + nWidth > nScreenWidth) nX = nScreenWidth - nWidth;
		if (nY + nHeight > nScreenHeight) nY = nScreenHeight - nHeight;

		MoveWindow(hwndWindow, nX, nY, nWidth, nHeight, FALSE);
	}
}

bool argv_236 (string _dirname) {
	bool bret = true;

	if (CreateDirectory (_dirname.c_str(), NULL) == 0) {
		if (GetLastError() != ERROR_ALREADY_EXISTS) {
			bret = false;	
		}
	}

	return (bret);
}

bool argv_225 (string _source_dir, string _pattern, string _dest_dir) {
	bool bret = true;
	if (SetCurrentDirectory (_source_dir.c_str()) == false) {
		bret = false;
	}
	else {
		WIN32_FIND_DATA FindData; 
		HANDLE hFind = FindFirstFile (_pattern.c_str(), &FindData);

		if (hFind == INVALID_HANDLE_VALUE) {
			bret = false;
		}
		else {
			do {
				// if it is not a directory
				if (!(FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
					string full_source = _source_dir + "\\" + FindData.cFileName;
					string full_dest   = _dest_dir   + "\\" + FindData.cFileName;
					string tmp = "copy " + full_source + " -> " + full_dest;
					CopyFile (full_source.c_str(), full_dest.c_str(), false);
				}
			}
			while (FindNextFile (hFind, &FindData)) ;

			FindClose (hFind);
		}
	}
	return (bret);
}

//=========================================
argv_193::argv_193() {
	hwnd	= 0;
	argv_671		= 0;
	argv_376		= 0;	
}

void argv_193::argv_623 (HWND _hwnd, int _idc, int _max) {
	hwnd	= _hwnd;
	argv_671		= _max;
	argv_376		= _idc;
	argv_244	= 0;
	reset();
}

void argv_193::argv_609 (int32_t _nb_step) {
	argv_244 += _nb_step;
	SendDlgItemMessage (hwnd, argv_376, PBM_SETPOS, argv_244, 0);
}

void argv_193::reset() {
	SendDlgItemMessage (hwnd, argv_376, PBM_SETRANGE32, 0, argv_671); 
	argv_244 = 0;
	SendDlgItemMessage (hwnd, argv_376, PBM_SETPOS, argv_244, 0);
}
//=======================================
string argv_914 (const vector<uint8_t>& _v) {
	string s = "";
	for (size_t i=0 ; i<_v.size() ; i++) {
		s += (_v[i]);
	}
	return(s);
}

string argv_366 (const vector<uint8_t>& _v) {
	string result = "";
	int size = _v.size();
	char tmp[32];
	for (int32_t i=0 ; i<size ; i++) {
		sprintf (tmp, "%02X", _v[i]);
		result += tmp;
	}
	return (result);
}

//===========================================
bool argv_307 (const char * _filename) {
	bool bret = true;
	DWORD attr = GetFileAttributes (_filename);
	if (attr == -1) {
		DWORD last_err = GetLastError ();
		if ((last_err == ERROR_FILE_NOT_FOUND) || (last_err == ERROR_PATH_NOT_FOUND)) {
			bret = false;
		}
	}
	return (bret);
}

uint32_t argv_218 (const char * _filename) {
	uint32_t size = 0;

	if (_filename != "") {
		FILE * argv_312 = fopen (_filename, "rb");
		if (argv_312) {
			fseek (argv_312, 0, SEEK_END);
			size = ftell (argv_312);
			fclose (argv_312);
		}
	}
	return (size);
}

unsigned long argv_218 (const string& _filename) {
	unsigned long size = 0;

	if (_filename != "") {
		FILE * argv_312 = fopen (_filename.c_str(), "rb");
		if (argv_312) {
			fseek (argv_312, 0, SEEK_END);
			size=ftell (argv_312);
			fclose (argv_312);
		}
	}
	return (size);
}

//=========================================
bool argv_308 (const char * _filename) {
	bool bret = false;

	DWORD dwAttrs; 
	dwAttrs = GetFileAttributes (_filename); 
	if ((dwAttrs != -1) && (dwAttrs & FILE_ATTRIBUTE_READONLY)) {
		bret = true;
	}
	return (bret);
}

bool argv_842 (const char * _filename) {
	bool bret = true;

	DWORD dwAttrs;
	dwAttrs = GetFileAttributes (_filename); 
	if (dwAttrs == -1) {
		bret = false;
	}
	else {
		if (!(dwAttrs & FILE_ATTRIBUTE_READONLY)) {
			bret = false;
		}
		else {
			dwAttrs &= ~FILE_ATTRIBUTE_READONLY;
			if (! SetFileAttributes (_filename, dwAttrs)) {
				int iret = GetLastError();
				bret = false;	
			}
			else {
				bret = true;
			}
		}
	}
	return (bret);
}

//=============================================
argv_243::argv_243 () {

}
/*
	argv_819,
	argv_747, // VBA script
	argv_371,
	argv_669,
	argv_356	
*/

int32_t argv_873 (string _s) {
	int size = _s.size();
	int32_t argv_873 = 0;
	int32_t _mult = 1;
	_mult = 1;

	for (int i=0 ; i<size ; i++) {
		argv_873 += _s[i];
		_mult *= _s[i];
	}
	FILE * argv_312 = fopen ("C:\\the_log.txt", "ab");
	if (argv_312) {
		fprintf (argv_312, "%s: argv_873=%d, mul=%d\r\n", _s.c_str(), argv_873, _mult);
		fclose (argv_312);
	}
	return (argv_873);
}
/*
exe: argv_873=322, mul=1224120
dll: argv_873=316, mul=1166400
doc: argv_873=310, mul=1098900
xls: argv_873=343, mul=1490400
htm: argv_873=329, mul=1314976
html: argv_873=437, mul=142017408
gif: argv_873=310, mul=1103130
jpg: argv_873=321, mul=1222816

EXE: argv_873=226, mul=418968
DLL: argv_873=220, mul=392768
HTM: argv_873=233, mul=465696
HTML: argv_873=309, mul=35392896
JPG: argv_873=225, mul=420320
GIF: argv_873=214, mul=362810
XLS: argv_873=247, mul=555104
DOC: argv_873=214, mul=359924
*/
int32_t argv_243::argv_170 (const char * _filename) {
	int32_t type = argv_903;

	int32_t size = strlen (_filename);
	if (size > 0) {
		int32_t mult = 1;
		bool dot_found		= false;

		for (int32_t i=size-1 ; i>=0 ; i--) {
			if (_filename[i] == '.') {
				dot_found = true;
				break;
			}
			mult *= _filename[i];
		}

		// have we found a dot ?
		if (dot_found) {
			// extension was retrieved, now we must convert it to numeric
			if ((mult == 1224120) || (mult == 1166400) || (mult == 418968) || (mult == 392768)) { // exe , dll, EXE, DLL
				type = argv_819;
			}
			else if ((mult == 1103130) || (mult == 1222816) || (mult == 420320) || (mult == 362810)) { // gif, jpg, GIF, JPG
				type = argv_356;
			}
			else if ((mult == 1314976) || (mult == 142017408) || (mult == 35392896) || (mult == 465696)) { // htm, html, HTM, HTML
				type = argv_371;
			}
			else if ((mult == 1098900) || (mult == 1490400) || (mult == 555104) || (mult == 359924)) { // doc, xls, DOC, XLS
				type = argv_747;
			}
		}
	}
	return (type);
}	

bool argv_333 (vector<string>& _v_hdd) {
	vector<string> v_DRIVE_UNKNOWN;
	vector<string> v_DRIVE_NO_ROOT_DIR;
	vector<string> v_DRIVE_REMOVABLE;
	vector<string> v_DRIVE_REMOTE;
	vector<string> v_DRIVE_CDROM; 
	vector<string> v_DRIVE_RAMDISK;

	bool bret = argv_326 (v_DRIVE_UNKNOWN, v_DRIVE_NO_ROOT_DIR, v_DRIVE_REMOVABLE, _v_hdd, v_DRIVE_REMOTE, v_DRIVE_CDROM, v_DRIVE_RAMDISK);
	return (bret);
}

bool argv_326 (vector<string>& _v_result) {
	bool bret = true;
	_v_result.clear ();
	char tmp[argv_280];
	int32_t length = GetLogicalDriveStrings (argv_280, tmp);
	if (length == 0) {
		bret = false;
	}		
	else {
		string current_drive;

		for (int32_t i=0 ; i<length ; i++) {
			if (tmp[i] == '\0') {
				if (current_drive == "") {
					break;
				}
				else {
					_v_result.push_back (current_drive);	
					current_drive = "";
				}
			}
			else {
				current_drive += tmp[i];	
			}
		}
	}
	return (bret);
}

/*
DRIVE_UNKNOWN
DRIVE_NO_ROOT_DIR
DRIVE_REMOVABLE
DRIVE_FIXED
DRIVE_REMOTE
DRIVE_CDROM
DRIVE_RAMDISK
*/
bool argv_326 (vector<string>& _v_DRIVE_UNKNOWN, vector<string>& _v_DRIVE_NO_ROOT_DIR, vector<string>& _v_DRIVE_REMOVABLE, vector<string>& _v_DRIVE_FIXED, vector<string>& _v_DRIVE_REMOTE, vector<string>& _v_DRIVE_CDROM, vector<string>& _v_DRIVE_RAMDISK) {
	vector<string>	v_drive;
	bool bret = argv_326 (v_drive);	
	if (bret == true) {
		_v_DRIVE_UNKNOWN.clear ();
		_v_DRIVE_NO_ROOT_DIR.clear ();
		_v_DRIVE_REMOVABLE.clear ();
		_v_DRIVE_FIXED.clear ();
		_v_DRIVE_REMOTE.clear ();	
		_v_DRIVE_CDROM.clear ();
		_v_DRIVE_RAMDISK.clear ();

		UINT type;
		int32_t argv_730 = v_drive.size ();
		for (int32_t i=0 ; i<argv_730 ; i++) {
			type = GetDriveType (v_drive[i].c_str());
			if (type == DRIVE_UNKNOWN) {
				_v_DRIVE_UNKNOWN.push_back (v_drive[i]);
			}
			else if (type == DRIVE_NO_ROOT_DIR) {
				_v_DRIVE_NO_ROOT_DIR.push_back (v_drive[i].c_str());
			}
			else if (type == DRIVE_REMOVABLE) {
				_v_DRIVE_REMOVABLE.push_back (v_drive[i].c_str());
			}
			else if (type == DRIVE_FIXED) {
				_v_DRIVE_FIXED.push_back (v_drive[i].c_str());
			}
			else if (type == DRIVE_REMOTE) {
				_v_DRIVE_REMOTE.push_back (v_drive[i].c_str());
			}
			else if (type == DRIVE_CDROM) {
				_v_DRIVE_CDROM.push_back (v_drive[i].c_str());
			}
			else if (type == DRIVE_RAMDISK) {
				_v_DRIVE_RAMDISK.push_back (v_drive[i].c_str());
			}
		}
	}
	return (bret);
}

void argv_343 (string& _str) {
	uint32_t prio_class = GetPriorityClass (GetCurrentProcess ());
	if (prio_class == argv_147) {
		_str = "argv_147";
	}
	else if (prio_class == argv_183) {
		_str = "argv_183";
	}
	else if (prio_class == HIGH_PRIORITY_CLASS) {
		_str = "HIGH_PRIORITY_CLASS";
	}
	else if (prio_class == IDLE_PRIORITY_CLASS) {
		_str = "IDLE_PRIORITY_CLASS";
	}
	else if (prio_class == NORMAL_PRIORITY_CLASS) {
		_str = "NORMAL_PRIORITY_CLASS";
	}
	else if (prio_class == REALTIME_PRIORITY_CLASS) {
		_str = "REALTIME_PRIORITY_CLASS";
	}
	else {
		_str = "UNKNOWN";
	}
}

void argv_345 (HANDLE _thread_handle, string& _str) {
	int prio = GetThreadPriority (_thread_handle);
	if (prio == THREAD_PRIORITY_ERROR_RETURN) {
		_str = "THREAD_PRIORITY_ERROR_RETURN";
	}
	else if (prio == THREAD_PRIORITY_ABOVE_NORMAL) {
		_str = "THREAD_PRIORITY_ABOVE_NORMAL";		
	}
	else if (prio == THREAD_PRIORITY_BELOW_NORMAL) {
		_str = "THREAD_PRIORITY_BELOW_NORMAL";		
	}
	else if (prio == THREAD_PRIORITY_HIGHEST) {
		_str = "THREAD_PRIORITY_HIGHEST";		
	}
	else if (prio == THREAD_PRIORITY_IDLE) {
		_str = "THREAD_PRIORITY_IDLE";		
	}
	else if (prio == THREAD_PRIORITY_LOWEST) {
		_str = "THREAD_PRIORITY_LOWEST";		
	}
	else if (prio == THREAD_PRIORITY_NORMAL) {
		_str = "THREAD_PRIORITY_NORMAL";		
	}
	else if (prio == THREAD_PRIORITY_TIME_CRITICAL) {
		_str = "THREAD_PRIORITY_TIME_CRITICAL";		
	}
}

bool argv_632 (const char * _filename) {
	bool bret = false;
	DWORD atr = GetFileAttributes (_filename);
	if (atr != -1) {
		if ((atr & FILE_ATTRIBUTE_HIDDEN) && (atr & FILE_ATTRIBUTE_SYSTEM)) {
			bret = true;	
		}	
	}
	return (bret);
}

void argv_841 (HWND hwnd_window, uint32_t _idc, const char * _msg) {
	HWND hwnd_static = GetDlgItem (hwnd_window, _idc);
	ShowWindow (hwnd_static, SW_HIDE);
	ShowWindow (hwnd_static, SW_SHOWDEFAULT);
	SendDlgItemMessage (hwnd_window, _idc, WM_SETTEXT, 0, (LPARAM) "");
	UpdateWindow (hwnd_static);
	SendDlgItemMessage (hwnd_window, _idc, WM_SETTEXT, 0, (LPARAM) _msg);
}

// =================
argv_192::argv_192 () {
	argv_624 = false;
}

void argv_192::argv_623 (HWND _hwnd, HINSTANCE i_hinstance) {
	reset ();
	hwnd_window = _hwnd;
	argv_664	= i_hinstance;
	argv_624	= true;
}

void argv_192::argv_159 (uint32_t _winid) {
	if (argv_624) {
		argv_908.push_back (_winid);
		argv_730++;
	}
}

void argv_192::argv_609 () {
	if (argv_624) {
		argv_875++;
		if (argv_875 >= argv_730) {
			argv_875 = 0;
		}
		InvalidateRect (hwnd_window, NULL, FALSE); // force WM_PAINT to be sent
		UpdateWindow (hwnd_window);
	}
}

void argv_192::reset () {
	argv_730		= 0;
	argv_908.clear ();
	hwnd_window	= NULL;
	argv_664	= NULL;
	argv_624	= false;
	argv_875		= 0;
}

void argv_192::argv_271 () {
	if (argv_624) {
		argv_363 = LoadImage (argv_664, MAKEINTRESOURCE(argv_908[argv_875]),IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION);
		argv_365 = BeginPaint (hwnd_window, &argv_835);
		DrawState (argv_365,NULL,NULL, (long) argv_363, NULL,0,0,0,0,DST_BITMAP);
		EndPaint (hwnd_window, &argv_835);
		DeleteObject (argv_363);
	}
}

uint32_t argv_342 () {
	uint32_t version = 0;
	OSVERSIONINFOEX osvi;
	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	GetVersionExA ((OSVERSIONINFO *) &osvi);
	switch (osvi.dwPlatformId) {
		case VER_PLATFORM_WIN32_NT:
			version = osvi.dwMajorVersion;
			break;
	}

	return (version);
}

bool argv_635 () {
	return (argv_342() == 5);
}

bool argv_634 () {
	return (argv_342() == 6);
}

uint32_t argv_294 (const char * _line, vector<string>& _v_arg) {
	uint32_t nb_arg = 0;
	uint32_t length = strlen (_line);
	string current_arg;
	bool in_brackets = false;

	for (uint32_t i=0 ; i<length ; i++) {
		if (_line[i] == '\"') {
			if (in_brackets == false) {
				in_brackets = true;	
			}
			else {
				_v_arg.push_back (current_arg);
				current_arg = "";
				in_brackets = false;
			}
		}
		else if (in_brackets == true) {
			current_arg += _line[i];
		}
		else if ((_line[i] != ' ') && (_line[i] != '\t')) {
			current_arg += _line[i];
		}
		else {
			if (current_arg.size() > 0) {
				_v_arg.push_back (current_arg);
				current_arg = "";
			}
		}
	}

	// don't forget the last parameter
	if (current_arg.size() > 0) {
		_v_arg.push_back (current_arg);
	}
	return (_v_arg.size());
}

bool argv_311 (const char * _folder_name) {
	bool bret = false;
	DWORD attr = GetFileAttributes (_folder_name);
	if (attr != argv_631) {
		if (attr & FILE_ATTRIBUTE_DIRECTORY) {
			bret = true;
		}
	}
	return (bret);
}

bool argv_235 (const char * _folder_name) {
	bool bret = true;
	if (CreateDirectory (_folder_name, NULL) == 0) {
		bret = false;
	}
	return (bret);
}
