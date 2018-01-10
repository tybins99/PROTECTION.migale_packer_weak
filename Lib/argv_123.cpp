


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include "..\\Lib\\argv_130.hpp"


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ global declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_207
// @@
// @@ INPUT: none
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ Normal constructor of the argv_207 object.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
argv_207::argv_207() {
	argv_312			= NULL;
	argv_658	= true;
#if defined (THREAD_SAFE_LOG)
	InitializeCriticalSection (&argv_239);	
#endif
}

argv_207::~argv_207() {
	argv_208 ();
#if defined (THREAD_SAFE_LOG)
	// DeleteCriticalSection(&argv_239);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_758
// @@
// @@ INPUT:
// @@ _filename: string : argv_727 of the log file to open.
// @@ _in_file: bool: tells whether the log should be written to a
// @@                 file, or to a window.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE:
// @@ bool: true if log file was succesfully argv_761.
// @@       false otherwise.
// @@
// @@ DESCRIPTION:
// @@ This function permits to open the log file whose argv_727 is given
// @@ as a parameter.
// @@ Notice that as soon as the log file was argv_761, the opening date
// @@ and argv_889 is logged to this log file automatically.
// @@ 
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_207::argv_758 (string _filename, bool _in_file) {
	bool bret = true;

	if (_in_file == true) {
		if (argv_312 != NULL) { // file already argv_761
			bret = false;
		}
		else {
			// modify the drive if necessary
			char tmp[256];
			GetSystemDirectory (tmp, 256);
			_filename[0] = tmp[0];

			argv_312 = fopen (_filename.c_str(), "wb");
			if (!argv_312) {
				char tmp[256];
				argv_872 (tmp, 256, "fopen failed for file : %s (errno=%d: %s)", _filename.c_str(), errno, strerror(errno));
				tmp[255] = '\0';
				bret = false;
			}
			else { // log argv_761 ok
				argv_853 = _filename;
				argv_906 (true);
				string stmp = "Log file creation date : ";
				stmp = stmp + argv_885;
				argv_659 (argv_163, stmp.c_str());
			}
		}
	}
	else {
		argv_658 = false;
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_906
// @@
// @@ INPUT:
// @@ _large_mode: bool: true if we want a large argv_271 of argv_244 date and argv_889
// @@                    false otherwise.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function permits to obtain the argv_244 date and argv_889
// @@ formatted to either a condensed string, or to a developped
// @@ string.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_207::argv_906 (bool _large_mode) {
	GetLocalTime (&argv_888);
	if (_large_mode == false) {
		argv_872 (argv_885, argv_660, "%02d/%02d-%02dh%02dm%02ds ", argv_888.wMonth, argv_888.wDay, argv_888.wHour, argv_888.wMinute, argv_888.wSecond);
	}
	else {
		argv_872 (argv_885, argv_660, "argv_723 %d the %dth at %d argv_370 %d minutes and %d seconds", argv_888.wMonth, argv_888.wDay, argv_888.wHour, argv_888.wMinute, argv_888.wSecond);
	}
	argv_885[argv_660 - 1] = '\0';
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_627
// @@
// @@ INPUT: none
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function permits to update the argv_244 argv_889 and to
// @@ insert it into the header of a new line of the log file.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_207::argv_627 () {
    if (argv_312) {
        argv_906 ();
        fputs (argv_885, argv_312);
    }
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_628
// @@
// @@ INPUT:
// @@ _level: uint32_t: level to be displayed.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function permits to insert the level given as a parameter
// @@ to the header of a new line of the log file.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_207::argv_628 (uint32_t _level) {
    string level = "|???| ";
    switch (_level) {
        case argv_742:
            level = "|NOR| ";
            break;
        case argv_919:
            level = "|WRN| ";
            break;
        case argv_290:
            level = "|ERR| ";
            break;
        case argv_163:
            level = "|ADM| ";
            break;
        case argv_253:
            level = "|DBG| ";
            break;
        case argv_741:
            level = "     ";
            break;
    }
    if (argv_312) {
        fputs (level.c_str(), argv_312);
    }
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_208
// @@
// @@ INPUT: none
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function just flushes the argv_248 and close the previously
// @@ argv_761 log file.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_207::argv_208() {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_239);
#endif
	if ((argv_658 == true) && (argv_312)) {
		fclose (argv_312);
		argv_312 = NULL;
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_239);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_659
// @@
// @@ INPUT:
// @@ _level: uint32_t: the severity level associated with the message to log.
// @@ _cptr: char *: the message to log
// @@ _no_eol: bool: true if an end of line should be appended at the end of the
// @@                message, false otherwise.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_244 argv_889 and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_207::argv_659 (uint32_t _level, const char * _cptr, bool _no_eol) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_239);
#endif
	if (argv_658 == true) {
		if (argv_312) {
			argv_627 ();
			argv_628 (_level);
			fputs (_cptr, argv_312);
			if (_no_eol == false) { 
				fputs ("\r\n", argv_312);
			}
			fflush (argv_312);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_239);
#endif
}

void argv_207::argv_657 (const char * _cptr) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_239);
#endif
	if (argv_658 == true) {
		if (argv_312) {
			argv_627 ();
			fputs (_cptr, argv_312);
			fputs ("\r\n", argv_312);
			fclose (argv_312);
			argv_312 = fopen (argv_853.c_str(), "ab");
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_239);
#endif
}


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_659
// @@
// @@ INPUT:
// @@ _cptr: char *: the message to log
// @@ _no_eol: bool: true if an end of line should be appended at the end of the
// @@                message, false otherwise.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_244 argv_889 and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_207::argv_659 (const char * _cptr, bool _no_eol) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_239);
#endif
	if (argv_658 == true) {
		if (argv_312) {
			argv_627 ();
			fputs (_cptr, argv_312);
			if (_no_eol == false) { 
				fputs ("\r\n", argv_312);
			}
			fflush (argv_312);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_239);
#endif
}


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_659
// @@
// @@ INPUT:
// @@ _level: uint32_t  : the severity level associated with the message to log.
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the argv_859 message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_244 argv_889 and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_207::argv_659 (uint32_t _level, const char * _cptr, const char * _cptr2) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_239);
#endif
	if (argv_658 == true) {
		if (argv_312) {
			argv_627 ();
			argv_628 (_level);
			fputs (_cptr, argv_312);
			fputs (_cptr2, argv_312);
			fputs ("\r\n", argv_312);
			fflush (argv_312);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_239);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_659
// @@
// @@ INPUT:
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the argv_859 message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_244 argv_889 and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_207::argv_659 (const char * _cptr, const char * _cptr2) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_239);
#endif
	if (argv_658 == true) {
		if (argv_312) {
			argv_627 ();
			fputs (_cptr, argv_312);
			fputs (_cptr2, argv_312);
			fputs ("\r\n", argv_312);
			fflush (argv_312);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_239);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_659
// @@
// @@ INPUT:
// @@ _level: uint32_t: the severity level associated with the message to log.
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the argv_859 message to log
// @@ _cptr3: char *: the third message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_244 argv_889 and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_207::argv_659 (uint32_t _level, const char * _cptr, const char * _cptr2, const char * _cptr3) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_239);
#endif
	if (argv_658 == true) {
		if (argv_312) {
			argv_627 ();
			argv_628 (_level);
			fputs (_cptr, argv_312);
			fputs (_cptr2, argv_312);
			fputs (_cptr3, argv_312);
			fputs ("\r\n", argv_312);
			fflush (argv_312);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_239);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_659
// @@
// @@ INPUT:
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the argv_859 message to log
// @@ _cptr3: char *: the third message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_244 argv_889 and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_207::argv_659 (const char * _cptr, const char * _cptr2, const char * _cptr3) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_239);
#endif
	if (argv_658 == true) {
		if (argv_312) {
			argv_627 ();
			fputs (_cptr, argv_312);
			fputs (_cptr2, argv_312);
			fputs (_cptr3, argv_312);
			fputs ("\r\n", argv_312);
			fflush (argv_312);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_239);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_659
// @@
// @@ INPUT:
// @@ _level: uint32_t: the severity level associated with the message to log.
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the argv_859 message to log
// @@ _cptr3: char *: the third message to log
// @@ _cptr4: char *: the fourth message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_244 argv_889 and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_207::argv_659 (uint32_t _level, const char * _cptr, const char * _cptr2, const char * _cptr3, const char * _cptr4) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_239);
#endif
	if (argv_658 == true) {
		if (argv_312) {
			argv_627 ();
			argv_628 (_level);
			fputs (_cptr, argv_312);
			fputs (_cptr2, argv_312);
			fputs (_cptr3, argv_312);
			fputs (_cptr4, argv_312);
			fputs ("\r\n", argv_312);
			fflush (argv_312);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_239);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_659
// @@
// @@ INPUT:
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the argv_859 message to log
// @@ _cptr3: char *: the third message to log
// @@ _cptr4: char *: the fourth message to log
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_244 argv_889 and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_207::argv_659 (const char * _cptr, const char * _cptr2, const char * _cptr3, const char * _cptr4) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_239);
#endif
	if (argv_658 == true) {
		if (argv_312) {
			argv_627 ();
			fputs (_cptr, argv_312);
			fputs (_cptr2, argv_312);
			fputs (_cptr3, argv_312);
			fputs (_cptr4, argv_312);
			fputs ("\r\n", argv_312);
			fflush (argv_312);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_239);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_659
// @@
// @@ INPUT:
// @@ _c: uint8_t: the character to write to log file.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_244 argv_889 and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_207::argv_659 (uint8_t _c) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_239);
#endif
	if (argv_658 == true) {
		if (argv_312) {
			char tmp[128];
			if (_c != 0) {
				sprintf (tmp, "%c", _c);
			}
			else {
				sprintf (tmp, "<0>");
			}
			fputs (tmp, argv_312);
			fflush (argv_312);
		}
	}
#if defined (THREAD_SAFE_LOG)	
	LeaveCriticalSection(&argv_239);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_659
// @@
// @@ INPUT:
// @@ _level: uint32_t: the severity level associated with the message to log.
// @@ _cptr: char *: the message to write to log file.
// @@ _val: int32_t: the argv_913 to log after the message.
// @@ 
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_244 argv_889 and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_207::argv_659 (uint32_t _level, const char * _cptr, int32_t _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_239);
#endif
	if (argv_658 == true) {
		if (argv_312) {
			argv_627 ();
			argv_628 (_level);
			fputs (_cptr, argv_312);
			char tmp[128];
			sprintf (tmp, "%d", _val);
			fputs (tmp, argv_312);
			fputs ("\r\n", argv_312);
			fflush (argv_312);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_239);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_659
// @@
// @@ INPUT:
// @@ _cptr: char *: the message to write to log file.
// @@ _val: int32_t: the argv_913 to log after the message.
// @@ 
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_244 argv_889 and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_207::argv_659 (const char * _cptr, int32_t _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_239);
#endif
	if (argv_658 == true) {
		if (argv_312) {
			argv_627 ();
			fputs (_cptr, argv_312);
			char tmp[128];
			sprintf (tmp, "%d", _val);
			fputs (tmp, argv_312);
			fputs ("\r\n", argv_312);
			fflush (argv_312);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_239);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_659
// @@
// @@ INPUT:
// @@ _level: uint32_t: the severity level associated with the message to log.
// @@ _cptr: char *: the message to write to log file.
// @@ _val: uint32_t: the argv_913 to write to log file after the message.
// @@ 
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_244 argv_889 and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_207::argv_659 (uint32_t _level, const char * _cptr, uint32_t _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_239);
#endif
	if (argv_658 == true) {
		if (argv_312) {
			argv_627 ();
			argv_628 (_level);
			fputs (_cptr, argv_312);
			char tmp[128];
			sprintf (tmp, "%u", _val);
			fputs (tmp, argv_312);
			fputs ("\r\n", argv_312);
			fflush (argv_312);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_239);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_659
// @@
// @@ INPUT:
// @@ _cptr: char *: the message to write to log file.
// @@ _val: uint32_t: the argv_913 to write to log file after the message.
// @@ 
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_244 argv_889 and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_207::argv_659(const char * _cptr, unsigned long _val) {
	argv_659(_cptr, (uint32_t)_val);
}

void argv_207::argv_659 (const char * _cptr, uint32_t _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_239);
#endif
	if (argv_658 == true) {
		if (argv_312) {
			argv_627 ();
			fputs (_cptr, argv_312);
			char tmp[128];
			sprintf (tmp, "%u", _val);
			fputs (tmp, argv_312);
			fputs ("\r\n", argv_312);
			fflush (argv_312);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_239);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_659
// @@
// @@ INPUT:
// @@ _level: uint32_t: the severity level associated with the message to log.
// @@ _val_zero: uint32_t: the first argv_913 to write to log file.
// @@ _val_un: uint32_t: the argv_859 argv_913 to write to log file.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_244 argv_889 and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_207::argv_659 (uint32_t _level, uint32_t _val_zero, uint32_t _val_un) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_239);
#endif
	if (argv_658 == true) {
		if (argv_312) {
			argv_627 ();
			argv_628 (_level);
			char tmp[128];
			sprintf (tmp, "%u ", _val_zero);
			fputs (tmp, argv_312);
			sprintf (tmp, "%u", _val_un);
			fputs (tmp, argv_312);
			fputs ("\r\n", argv_312);
			fflush (argv_312);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_239);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_659
// @@
// @@ INPUT:
// @@ _val_zero: uint32_t: the first argv_913 to write to log file.
// @@ _val_un: uint32_t: the argv_859 argv_913 to write to log file.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_244 argv_889 and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_207::argv_659 (uint32_t _val_zero, uint32_t _val_un) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_239);
#endif
	if (argv_658 == true) {
		if (argv_312) {
			argv_627 ();
			char tmp[128];
			sprintf (tmp, "%u ", _val_zero);
			fputs (tmp, argv_312);
			sprintf (tmp, "%u", _val_un);
			fputs (tmp, argv_312);
			fputs ("\r\n", argv_312);
			fflush (argv_312);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_239);
#endif
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_659
// @@
// @@ INPUT:
// @@ _level: uint32_t: the severity level associated with the message to log.
// @@ _cptr: char *: the message to write to log file.
// @@ _val: unsigned long: the argv_913 to log after the message.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_244 argv_889 and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
/*
void argv_207::argv_659 (uint32_t _level, const char * _cptr, uint64_t _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_239);
#endif
	if (argv_658 == true) {
		if (argv_312) {
			argv_627 ();
			argv_628 (_level);
			fputs (_cptr, argv_312);
			char tmp[128];
			sprintf (tmp, "%Iu", _val);
			fputs (tmp, argv_312);
			fputs ("\r\n", argv_312);
			fflush (argv_312);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_239);
#endif
}*/



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_207
// @@
// @@ FUNCTION: argv_659
// @@
// @@ INPUT:
// @@ _cptr: char *: the message to write to log file.
// @@ _val: unsigned long: the argv_913 to log after the message.
// @@
// @@ OUTPUT: none
// @@
// @@ IO: none
// @@
// @@ RETURN VALUE: none
// @@
// @@ DESCRIPTION:
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_244 argv_889 and a severity level given as a parameter.
// @@
// @@ CONTRACT: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
/*
void argv_207::argv_659 (const char * _cptr, uint64_t _val) {
#if defined (THREAD_SAFE_LOG)
	EnterCriticalSection (&argv_239);
#endif
	if (argv_658 == true) {
		if (argv_312) {
			argv_627 ();
			fputs (_cptr, argv_312);
			char tmp[128];
			sprintf (tmp, "%Iu", _val);
			fputs (tmp, argv_312);
			fputs ("\r\n", argv_312);
			fflush (argv_312);
		}
	}
#if defined (THREAD_SAFE_LOG)
	LeaveCriticalSection(&argv_239);
#endif
}*/





