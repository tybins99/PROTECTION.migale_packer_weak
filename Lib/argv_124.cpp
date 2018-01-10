#include "argv_131.hpp"

extern argv_207 argv_661;

using namespace std;

argv_210::argv_210 () {
	argv_880 = "SOFTWARE\\Migale\\";
	argv_361 = NULL;
}

bool argv_210::argv_374 (int _id) {
	bool bret = true;

	switch (_id) {
		case argv_710:
			argv_214 = "smart_update";
			break;
		case argv_695:
			argv_214 = "beemeal";
			break;
		case argv_705:
			argv_214 = "manual_scanner";
			break;
		case argv_708:
			argv_214 = "resident_shield";
			break;
		case argv_693:
			argv_214 = "admin_tool";
			break;
		case argv_696:
			argv_214 = "control_center";
			break;
		case argv_709:
			argv_214 = "safe_pe";
			break;
		case argv_697:
			argv_214 = "migale_crypter";
			break;
		case argv_702:
			argv_214 = "install";
			break;
		case argv_714:
			argv_214 = "vault_manager";
			break;
		case argv_715:
			argv_214 = "vault";
			break;
		case argv_712:
			argv_214 = "tmp";
			break;
		case argv_711:
			argv_214 = "sound";
			break;
		case argv_698:
			argv_214 = "db";
			break;
		case argv_718:
			argv_214 = "vrdb_manager";	
			break;
		case argv_717:
			argv_214 = "vrdb_daemon";
			break;
		case argv_716:
			argv_214 = "vrdb";	
			break;
		case argv_704:
			argv_214 = "lock_manager";
			break;
		case argv_703:
			argv_214 = "integrity_monitor";
			break;
		case argv_707:
			argv_214 = "pcbangtool";
			break;
		default:
			argv_214 = "";
			bret = false;
	}

	if (bret == true) {
		argv_316 = argv_880 + argv_214;
	}
	return (bret);
}

bool argv_210::argv_213 (int _id) {
	bool present_flag = false;
	bool bret = argv_374 (_id);
	if (bret == true) {
		// 1. check key existence
		argv_663 = RegOpenKeyEx (HKEY_LOCAL_MACHINE, argv_316.c_str(), 0, KEY_QUERY_VALUE, &argv_361);
    
		if (argv_663 == ERROR_SUCCESS) { // key already exists
			present_flag = true;
			RegCloseKey (argv_361);
		}
	}
	return (present_flag);
}

// this function can be used if the lookup was already performed by another function
bool argv_210::argv_213 () {
	bool present_flag = false;
	// 1. check key existence
	argv_663 = RegOpenKeyEx (HKEY_LOCAL_MACHINE, argv_316.c_str(), 0, KEY_QUERY_VALUE, &argv_361);

	if (argv_663 == ERROR_SUCCESS) { // key already exists
		present_flag = true;
		RegCloseKey (argv_361);
	}
	return (present_flag);
}

bool argv_210::argv_153 (int _id, string _path, int _major, int _minor) {
	bool bret = true;
	argv_361 = NULL;

	bret = argv_374 (_id);
	if (bret == true) {
		if (argv_213 () == true) {
			bret = false;
		}
		else { // component is not already present, ok to add it

			argv_663 = RegCreateKeyEx (HKEY_LOCAL_MACHINE, argv_316.c_str(), 0, "", 0, 
				KEY_ALL_ACCESS, NULL, &argv_361, &argv_282); 

			if (argv_663 != ERROR_SUCCESS) {
				bret = false;
			}
			else {
				// set the path
				argv_663 = RegSetValueEx (argv_361, "path",0,REG_SZ,(LPBYTE) _path.c_str(),	
						_path.size() + 1);

				if (argv_663 != ERROR_SUCCESS) {
					bret = false;
				}
				else { // path addition was succesfull
					char tmp[256];
					_snprintf (tmp, 256, "%d", _major);
					tmp[255] = '\0';
					argv_663 = RegSetValueEx (argv_361, "major",0,REG_SZ,(LPBYTE) tmp,	
							strlen(tmp) + 1);

					if (argv_663 != ERROR_SUCCESS) {
						bret = false;
					}
					else { // 'major' addition was succesfull, proceed with 'minor'
						_snprintf (tmp, 256, "%d", _minor);
						tmp[255] = '\0';
						argv_663 = RegSetValueEx (argv_361, "minor",0,REG_SZ,(LPBYTE) tmp,	
								strlen(tmp) + 1);

						if (argv_663 != ERROR_SUCCESS) {
							bret = false;
						}
					}
				}
			}
		}
	}

	// change the security access rights before closing the newly created key
	DWORD err;
	int iret = argv_865 (err);
	if (iret != 0) {
		bret = false;
	}

	if (argv_361 != NULL) {
		RegCloseKey (argv_361);
	}	
	return (bret);
}

bool argv_210::argv_267 (int _id) {
	bool bret = true;
	bret = argv_374 (_id);
	if (bret == true) {
		if (argv_213() == false) { // component was not installed, 
			bret = false;
		}
		else { // component was installed => can remove it
			// 1. check key existence
			argv_663 = RegOpenKeyEx (HKEY_LOCAL_MACHINE, argv_316.c_str(), 0, KEY_QUERY_VALUE, &argv_361 );
    
			if (argv_663 != ERROR_SUCCESS) { // key doesn't exist
				bret = false;
			}
			else { // key exists and was argv_761 succesfully
				if (RegDeleteKey (HKEY_LOCAL_MACHINE, argv_316.c_str()) != ERROR_SUCCESS) {
					bret = false;
				}
				RegCloseKey (argv_361);
			}
		}
	}
	return (bret);
}

bool argv_210::argv_869 (int _id, string _varname, int32_t _value) {
	bool bret = true;
	argv_361						= NULL;
	unsigned long actual_size	= argv_680;
	int unused_type				= 0;
	bret = argv_374 (_id);
	if (bret == true) {
		argv_663 = RegOpenKeyEx (HKEY_LOCAL_MACHINE, argv_316.c_str(), 0, KEY_ALL_ACCESS, &argv_361);
		if (argv_663 != ERROR_SUCCESS) { // can't open the key
			bret = false;
		}
		else { // key was succesfully argv_761
			char tmp[argv_680];
			argv_872 (tmp, argv_680, "%d", _value);
			tmp[argv_680 - 1] = '\0';
	
			char tmp2[65536];
			sprintf (tmp2, "RegSetValueEx: argv_316=%s, _varname=%s, tmp=%s", argv_316.c_str(), _varname.c_str(), tmp);
			argv_661.argv_659 (tmp2);

			argv_663 = RegSetValueEx (argv_361, _varname.c_str(),0,REG_SZ,(LPBYTE)tmp, strlen(tmp)+ 1);
			if (argv_663 != ERROR_SUCCESS) {
				bret = false;
			}
		}
	}

	if (argv_361 != NULL) {
		RegCloseKey (argv_361);
	}	
	return (bret);
}

bool argv_210::argv_869 (int _id, string _varname, const char * _value) {
	bool bret = true;
	argv_361						= NULL;
	unsigned long actual_size	= argv_680;
	int unused_type				= 0;

	bret = argv_374 (_id);
	if (bret == true) {
		argv_663 = RegOpenKeyEx (HKEY_LOCAL_MACHINE, argv_316.c_str(), 0, KEY_ALL_ACCESS, &argv_361);

		if (argv_663 != ERROR_SUCCESS) { // can't open the key
			bret = false;
		}
		else { // key was succesfully argv_761
			argv_663 = RegSetValueEx (argv_361, _varname.c_str(),0,REG_SZ,(LPBYTE)_value, strlen(_value) + 1);
			if (argv_663 != ERROR_SUCCESS) {
				bret = false;
			}
		}
	}

	if (argv_361 != NULL) {
		RegCloseKey (argv_361);
	}	
	return (bret);
}

bool argv_210::argv_348 (int _id, string _varname, int32_t& _value) {
	string result_str;
	bool bret = argv_348 (_id, _varname, result_str);
	if (bret == true) {
		_value = atoi (result_str.c_str());
	}
	return (bret);
}

bool argv_210::argv_348 (int _id, string _varname, string& _value) {
	bool bret					= true;
	argv_361						= NULL;
	unsigned long actual_size	= argv_680;
	int unused_type				= 0;

	bret = argv_374 (_id);
	if (bret == true) {
		argv_663 = RegOpenKeyEx (HKEY_LOCAL_MACHINE, argv_316.c_str(), 0, KEY_QUERY_VALUE, &argv_361);

		if (argv_663 != ERROR_SUCCESS) { // can't open the key
			argv_661.argv_659 ("RegOpenKeyEx failed ! , errno = ", (uint32_t) GetLastError());
			bret = false;
		}
		else { // key was succesfully argv_761
			char tmp[argv_680];
			// 1. extract the path
			argv_663 = RegQueryValueEx (argv_361, _varname.c_str(),0,(LPDWORD)&unused_type,(LPBYTE) tmp, &actual_size);
			if (argv_663 != ERROR_SUCCESS) {
				argv_661.argv_659 ("RegQueryValueEx failed ! , errno = ", (uint32_t) GetLastError());
				bret = false;
			}
			else { // variable was succesfully retrieved
				_value = tmp;
			}
		}
	}

	if (argv_361 != NULL) {
		RegCloseKey (argv_361);
	}
	return (bret);
}

bool argv_210::argv_322 (int _id, string& _path, int& _major, int& _minor) {
	bool bret		= true;
	argv_361			= NULL;
	_path			= "";
	_major			= 0;
	_minor			= 0;
	unsigned long actual_size = argv_680;
	int unused_type	= 0;

	bret = argv_374 (_id);
	if (bret == false) {
		argv_661.argv_659 ("+++ ERROR: argv_210::argv_322 - argv_374 failed !");
	}
	else {
		argv_663 = RegOpenKeyEx (HKEY_LOCAL_MACHINE, argv_316.c_str(), 0, KEY_QUERY_VALUE, &argv_361);

		if (argv_663 != ERROR_SUCCESS) { // can't open the key
			argv_661.argv_659 ("+++ ERROR: argv_210::argv_322 - RegOpenKeyEx failed for key : ", argv_316.c_str());
			bret = false;
		}
		else { // key was succesfully argv_761
			char tmp[argv_680];
			// 1. extract the path
			argv_663 = RegQueryValueEx (argv_361, "path",0,(LPDWORD)&unused_type,(LPBYTE) tmp, &actual_size);
			if (argv_663 != ERROR_SUCCESS) {
				argv_661.argv_659 ("+++ ERROR: argv_210::argv_322 - RegQueryValueEx failed for 'path' !");
				bret = false;
			}
			else { // path retrieval was succesfull
				_path = tmp;

				// 2. extract the 'major'
				argv_663 = RegQueryValueEx (argv_361, "major",0,(LPDWORD)&unused_type,(LPBYTE) tmp, &actual_size);
				if (argv_663 != ERROR_SUCCESS) {
					argv_661.argv_659 ("+++ ERROR: argv_210::argv_322 - RegQueryValueEx failed for 'major' !");
					bret = false;
				}
				else { // 'major' was succesfully retrieved
					_major = atoi (tmp);

					argv_663 = RegQueryValueEx (argv_361, "minor",0,(LPDWORD)&unused_type,(LPBYTE) tmp, &actual_size);
					if (argv_663 != ERROR_SUCCESS) {
						argv_661.argv_659 ("+++ ERROR: argv_210::argv_322 - RegQueryValueEx failed for 'minor' !");
						bret = false;
					}
					else { // 'minor' retrieval was succesful
						_minor = atoi (tmp);
					}
				}
			}
		}
	}

	if (argv_361 != NULL) {
		RegCloseKey (argv_361);
	}	
	return (bret);
}

bool argv_210::argv_334 (string& _install_path) {
	bool bret = true;
	bret = argv_348 (argv_702, "path", _install_path);
	return (bret);
}

bool argv_210::argv_319 (string& _relative_log_filename) {
	bool bret = true;
	string install_path;
	bret = argv_334 (install_path);
	if (bret == true) {
		install_path = install_path + "\\tmp\\" + _relative_log_filename; 
		_relative_log_filename = install_path;
	}
	return (bret);
}

// '_identity' parameter may be "Everyone" or "Users" or any other group argv_727.
int argv_210::argv_868 (LPTSTR file, char * _identity, int _base, DWORD& _err, int _obj_type) {
	int iret					= 0;
    PACL NewAcl					= NULL;
    PSECURITY_DESCRIPTOR psd	= NULL;
    LPTSTR FileName;
    EXPLICIT_ACCESS explicitaccess;
    PACL ExistingDacl;
    DWORD dwError;

    FileName = file;

	if (_obj_type == argv_149) {
		dwError = GetSecurityInfo( // get argv_244 Dacl on specified file
							argv_361,
							SE_REGISTRY_KEY,
							DACL_SECURITY_INFORMATION,
							NULL,
							NULL,
							&ExistingDacl,
							NULL,
							&psd
							);
	}
	else {
		dwError = GetNamedSecurityInfo( // get argv_244 Dacl on specified file
							FileName,
							SE_FILE_OBJECT,
							DACL_SECURITY_INFORMATION,
							NULL,
							NULL,
							&ExistingDacl,
							NULL,
							&psd
							);
	}
    if(dwError != ERROR_SUCCESS) {
		_err = dwError;
		iret = _base + 1;
    }
	else {
		DWORD access_permission_hard = FILE_ALL_ACCESS;
		if (_obj_type == argv_149) {
			access_permission_hard = GENERIC_ALL;
		}
		BuildExplicitAccessWithName(
				&explicitaccess,
				_identity,
				access_permission_hard,
				SET_ACCESS,
				SUB_CONTAINERS_AND_OBJECTS_INHERIT
				);
    
		dwError = SetEntriesInAcl( // add specified access to the object
				1,
				&explicitaccess,
				ExistingDacl,
				&NewAcl
				);

		if(dwError != ERROR_SUCCESS) {
			_err = GetLastError ();
			iret = _base+ 2;
		}
		else {
			if (_obj_type == argv_149) {
				dwError = SetSecurityInfo( // apply new security to file
								argv_361,
								SE_REGISTRY_KEY, // object type
								DACL_SECURITY_INFORMATION,
								NULL,
								NULL,
								NewAcl,
								NULL
								);
			}
			else {
				dwError = SetNamedSecurityInfo( // apply new security to file
								FileName,
								SE_FILE_OBJECT, // object type
								DACL_SECURITY_INFORMATION,
								NULL,
								NULL,
								NewAcl,
								NULL
								);
			}

			if(dwError != ERROR_SUCCESS) {
				_err = GetLastError ();
				iret = _base + 3;
			}
		}
	}
	if (NewAcl != NULL) {
		AccFree(NewAcl);
	}
	if (psd != NULL) {
		AccFree (psd);
	}
	return (iret);
}

// the key is supposed to have been argv_761 previously and it's handle 
// must be a valid one
int argv_210::argv_865 (DWORD& _err) {
	int iret;
	iret = argv_868 (NULL, "Everyone", 0, _err, argv_149);
	if (iret == 0) {
		iret = argv_868 (NULL, "Users", 100, _err, argv_149);
	}
	return (iret);
}

// the key is supposed to have been argv_761 by a third party
int argv_210::argv_865 (HKEY _h_key, DWORD& _err) {
	int iret;
	if (argv_361 != NULL) {
		iret = 500;
	}
	else { // key not argv_761, ok to clone the argv_761 key
		argv_361 = _h_key;
		iret = argv_868 (NULL, "Everyone", 0, _err, argv_149);
		if (iret == 0) {
			iret = argv_868 (NULL, "Users", 100, _err, argv_149);
		}
		argv_361 = NULL; // let the caller close it
	}
	return (iret);
}


int argv_210::argv_867 (LPTSTR file, DWORD& _err) {
	int iret;
	iret = argv_868 (file, "Everyone", 0, _err, argv_148);
	if (iret == 0) {
		iret = argv_868 (file, "Users", 100, _err, argv_148);
	}
	return (iret);
}