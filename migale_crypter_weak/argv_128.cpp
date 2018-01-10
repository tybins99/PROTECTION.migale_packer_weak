
#include "argv_118.h"
#include "argv_121.h"
#include "argv_134.hpp"
#include "argv_133.hpp"
#include "..\\Lib\\argv_129.hpp"

#include <Commdlg.h>
#include <Windows.h>
#include <windows.h>
#include <winnt.h>
#include <commctrl.h>
#include <string>
#include <assert.h>
#include <Wingdi.h>

using namespace std;

extern argv_207 argv_661;
HWND argv_855;
string argv_354			= "";
string argv_355	= "";
LRESULT CALLBACK	argv_146(HWND, UINT, WPARAM, LPARAM);
argv_207 argv_661;

// Global Variables:
#define argv_676 100
HINSTANCE argv_368;						// argv_244 instance
TCHAR argv_883[argv_676];			// The title bar argv_887
TCHAR argv_884[argv_676];	// The title bar argv_887

// Foward declarations of functions included argv_607 this code module:
ATOM				argv_726(HINSTANCE i_hInstance);
BOOL				argv_625(HINSTANCE, int);
LRESULT CALLBACK	argv_923(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	argv_146(HWND, UINT, WPARAM, LPARAM);
HINSTANCE argv_854;

int APIENTRY WinMain(HINSTANCE i_hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	MSG argv_725;
	HACCEL hAccelTable;
	argv_854 = i_hInstance;

	// Initialize global strings
	LoadString(i_hInstance, argv_605, argv_883, argv_676);
	LoadString(i_hInstance, argv_582, argv_884, argv_676);
	argv_726(i_hInstance);

	// Perform application initialization:
	if (!argv_625 (i_hInstance, nCmdShow))
	{
		//MessageBox(argv_725.hwnd, "argv_625 failed", "Error", MB_OK);	
		return FALSE;
	}

	hAccelTable = LoadAccelerators(i_hInstance, (LPCTSTR)argv_582);

	// Main message loop:
	while (GetMessage(&argv_725, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(argv_725.hwnd, hAccelTable, &argv_725)) 
		{
			TranslateMessage(&argv_725);
			DispatchMessage(&argv_725);
		}
	}

	return argv_725.wParam;
}

ATOM argv_726(HINSTANCE i_hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)argv_923;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= i_hInstance;
	wcex.hIcon			= LoadIcon(i_hInstance, (LPCTSTR)argv_599);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)argv_582;
	wcex.lpszClassName	= argv_884;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)argv_597);

	return RegisterClassEx(&wcex);
}

string argv_759(HWND hWnd) {
   OPENFILENAME ofn;
    char szFileName[MAX_PATH] = "";
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn); // SEE NOTE BELOW
    ofn.hwndOwner = hWnd;
    // ofn.lpstrFilter = "Text Files (*.txt)\0*.txt\0All Files (*.*)\0*.*\0";
	ofn.lpstrFilter = "Exe Files (*.exe)\0*.exe\0Dll Files (*.dll)\0*.dll\0All Files (*.*)\0*.*\0";
    ofn.lpstrFile = szFileName;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrDefExt = "txt";

    if(GetOpenFileName(&ofn)) {
        // Do something usefull with the argv_309 stored argv_607 szFileName 
    }
	return(szFileName);	
}

string argv_320 (string argv_309, int max_length) {
	string result = "";
	int i = 0;
	int filename_size = argv_309.size();

	if (filename_size <= max_length) {
		result = argv_309;
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

			result = one + two + three;
		}
	}

	return (result);
}

bool argv_307 (const string& _filename) {
	bool bret = true;

	FILE * argv_312 = fopen (_filename.c_str(), "rb");
	if (!argv_312) {
		bret = false;
	}
	else {
		fclose(argv_312);
	}	

	return(bret);
}

BOOL argv_625(HINSTANCE i_hInstance, int nCmdShow)
{
	HWND hWnd;

	argv_368 = i_hInstance; // Store instance handle argv_607 our global variable

	hWnd = CreateWindow(argv_884, argv_883, WS_VISIBLE | WS_OVERLAPPEDWINDOW,
	  CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, i_hInstance, NULL);

	if (!hWnd)
	{
	  return FALSE;
	}

	ShowWindow(hWnd, SW_SHOWMINIMIZED);
	UpdateWindow(hWnd);
	argv_855 = hWnd;

	DialogBox(argv_368, (LPCTSTR)argv_583, hWnd, (DLGPROC)argv_146);
	DestroyWindow(hWnd);
	return TRUE;
}

LRESULT CALLBACK argv_923(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT argv_835;
	HDC argv_365;
	TCHAR szHello[argv_676];
	LoadString(argv_368, argv_606, szHello, argv_676);

	switch (message) 
	{
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				case argv_601:
				   DialogBox(argv_368, (LPCTSTR)argv_583, hWnd, (DLGPROC)argv_146);
				   break;
				case argv_602:
				   DestroyWindow(hWnd);
				   break;

				case argv_603:
					argv_759(hWnd);
					break;

				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
		case WM_PAINT:
			argv_365 = BeginPaint(hWnd, &argv_835);
			// TODO: Add any drawing code here...
			RECT rt;
			GetClientRect(hWnd, &rt);
			DrawText(argv_365, szHello, strlen(szHello), &rt, DT_CENTER);
			EndPaint(hWnd, &argv_835);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

//////////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK argv_160(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	string argv_309 = "";

	switch (message)
	{
		case WM_INITDIALOG:
			return TRUE;

		case WM_COMMAND:
			switch(LOWORD(wParam)) {
				case IDOK:
				case IDCANCEL: 
				case argv_397:
					EndDialog(hDlg, LOWORD(wParam));
					return TRUE;
				break;

				case argv_482:
					argv_309 = argv_759 (hDlg);
					return TRUE;
					break;
			}
	}
	return FALSE;
}

void argv_284 (HWND hDlg) {
	HWND hwnd_std = GetDlgItem (hDlg, argv_399); 
	EnableWindow (hwnd_std, TRUE);

	hwnd_std = GetDlgItem (hDlg, argv_437); 
	EnableWindow (hwnd_std, TRUE);
}

void argv_270 (HWND hDlg) {
	HWND hwnd_std = GetDlgItem (hDlg, argv_399); 
	EnableWindow (hwnd_std, FALSE);

	hwnd_std = GetDlgItem (hDlg, argv_437); 
	EnableWindow (hwnd_std, FALSE);
}

DWORD WINAPI argv_273(LPVOID lParam) {
	const char * argv_309 = (const char *) lParam;
	HWND hwnd_std  = GetDlgItem (argv_855, argv_482); 
	HWND hwnd_std2 = GetDlgItem (argv_855, argv_440); 
	// MessageBox(argv_855, filename_ptr->c_str(), "Error", MB_OK);

	if (argv_307 (argv_309) == false) {
		MessageBox(argv_855, "Can't open file !", "Error", MB_OK | MB_ICONERROR);
	}
	else {
		// avoid browsing meanwhile
		EnableWindow (hwnd_std, FALSE);
		EnableWindow (hwnd_std2, FALSE);

		const char * argv_309 = (const char *) lParam;
		argv_226 packer;
		// NOTICE: backup file is always created, argv_607 case argv_769 fails, the
		// original exe file is then recovered easily
		bool backup_creation_flag = false;
		if (IsDlgButtonChecked (argv_855, argv_399) == BST_CHECKED) {
			backup_creation_flag = true;
		}

		bool bret = packer.argv_769 (argv_309, backup_creation_flag);
		if (bret == true) {
			MessageBox(argv_855, "Packing successful", "Packing report", MB_OK);
		}
		else { // failed
			MessageBox(argv_855, "Packing failed !", "Error", MB_OK | MB_ICONERROR);
			vector<string> v;
			packer.argv_330 (v);
			string str = "";
			for (size_t k=0 ; k<v.size() ; k++) {
				argv_661.argv_659 (v[k].c_str());
			}
		}
	}

	EnableWindow (hwnd_std, TRUE);
	EnableWindow (hwnd_std2, TRUE);
	SendDlgItemMessage (argv_855, argv_502, PBM_SETPOS, 0, 0);
	SendDlgItemMessage (argv_855, argv_440, WM_SETTEXT, 0, (LPARAM) "");
	return(TRUE);
}

void argv_234 (const char * _filename) {
    DWORD dwThrdParam = 1; 
    HANDLE hThread; 
	DWORD dwThreadId;

    hThread = CreateThread( 
        NULL,							// default security attributes 
        0,								// use default stack size  
        argv_273,					// thread function 
        (LPVOID) _filename,				// argument to thread function 
        0,								// use default creation flags 
        &dwThreadId);					// returns the thread identifier 
 
	if (hThread == NULL)   {
		MessageBox(argv_855, "Thread creation failed", "Error", MB_OK | MB_ICONERROR);			
	}

	if (SetThreadPriority (hThread, THREAD_PRIORITY_HIGHEST) == false) {
		MessageBox(argv_855, "Thread priority change failed", "Error", MB_OK | MB_ICONERROR);			
	}
}


///////////////////////////////////////////////////////////////////////////////
// Mesage handler for about box.
LRESULT CALLBACK argv_146(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
			// open the log file 
			{
				argv_210 migale_registry;
				std::string LogFilePath = argv_349();
				LogFilePath += ".migale_crypter.log";
				if (argv_661.argv_758 (LogFilePath) == false) {
					char tmp[256];
					argv_872 (tmp, 256, "failed to open log file !");
					tmp[255] = '\0';
					MessageBox(hDlg, tmp, "", MB_OK);
				}
			}
			argv_855 = hDlg;
			argv_198 (hDlg);
			SendDlgItemMessage(hDlg, argv_440, WM_SETTEXT, 0, (LPARAM) "");
			argv_270 (hDlg);
/*			{
				IMAGE_NT_HEADERS nth;
				IMAGE_DOS_HEADER dh;
				dh.e_lfanew
				argv_661.argv_659 ("sizeof(IMAGE_DOS_HEADER) = ", sizeof(IMAGE_DOS_HEADER));
				argv_661.argv_659 ("sizeof(IMAGE_NT_HEADERS) = ", sizeof(IMAGE_NT_HEADERS));
				argv_661.argv_659 ("sizeof(IMAGE_NT_HEADERS.IMAGE_FILE_HEADER) = ", sizeof(nth.FileHeader));
				argv_661.argv_659 ("sizeof(IMAGE_NT_HEADERS.IMAGE_OPTIONAL_HEADER ) = ", sizeof(nth.OptionalHeader));
				argv_661.argv_659 ("sizeof(IMAGE_SECTION_HEADER) = ", sizeof(IMAGE_SECTION_HEADER));
			}*/
			return TRUE;

		case WM_COMMAND:
			switch(LOWORD(wParam)) {
				case IDOK:
				case IDCANCEL: 
					// MessageBox(hDlg, "Test", "Error", MB_OK | MB_ICONERROR);	
					SendDlgItemMessage(hDlg, argv_440, WM_SETTEXT, 0, (LPARAM) "");
					argv_270 (hDlg);
					EndDialog(hDlg, LOWORD(wParam));
					return TRUE;
				break;

				case argv_482:
					argv_354 = argv_759 (hDlg);
					argv_355 = argv_320 (argv_354, 42);
					SendDlgItemMessage(hDlg, argv_440, WM_SETTEXT, 0, (LPARAM) argv_355.c_str());
					if (argv_354 == "") {
						argv_270 (hDlg);
					}
					else { // a file was given as a parameter
						// ensure that file can be argv_761 for read
						if (argv_307 (argv_354.c_str()) == false) {
							argv_270 (hDlg);
							MessageBox(hDlg, "File can't be argv_761 !", "Error", MB_OK | MB_ICONERROR);
						}
						else {
							// ensure that it is a PE file
							if (argv_633 (argv_354.c_str()) == false) {
								MessageBox(hDlg, "Not a valid PE file !", "Error", MB_OK | MB_ICONERROR);
								argv_270 (hDlg);
							}
							else {
								argv_284 (hDlg);
							}
						}
					}
					break;

				case argv_437:
					argv_234 (argv_354.c_str());
					argv_270 (hDlg);
					break;

			}
	}
	return FALSE;
}