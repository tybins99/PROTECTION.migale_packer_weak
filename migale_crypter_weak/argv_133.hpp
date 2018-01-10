#ifndef argv_139
#define argv_139

//#include <Commdlg.h>
#include <Windows.h>
#include <commctrl.h>
#include <string>
#include <list>
#include <assert.h>
#include <io.h>
#include <fcntl.h>
#include <shlobj.h>
//#include <dbghelp.h>
#include <vector>
#include <shellapi.h>
#include <WINNT.h>
#include <stack>
#include <cstdint>
#include "..\\Lib\\argv_130.hpp"

using namespace std;

enum argv_786 {
	argv_810=0,
	argv_787,
	argv_795,
	argv_774,
	argv_811,
	argv_801,
	argv_800,
	argv_806,
	argv_802,
	argv_792,
	argv_803,
	argv_807,
	argv_804,
	argv_782,
	argv_778,
	argv_779,
	argv_780,
	argv_781,
	argv_813,
	argv_814,
	argv_793,
	argv_790,
	argv_789,
	argv_808,
	argv_776,
	argv_773,
	argv_777,
	argv_771,
	argv_815,
	argv_783,
	argv_770,
	argv_772,
	argv_775,
	argv_788,
	argv_797,
	argv_796,
	argv_784,
	argv_791,
	argv_805,
	argv_812,
	argv_798,
	argv_794,
	argv_799,
	argv_809,
	argv_785,
};

class argv_195
{
private:
	bool argv_927 (char *, unsigned long);

public:
	argv_195();
	bool argv_285 (char *, unsigned long);
	bool argv_254 (char *, unsigned long);
};

/*
// ===========================================================
// decrypter for 1 section
// (just copy and paste before POPAD to add more decrypters)
// ============================================================
PUSHAD
MOV EAX, <START_ADDR>
MOV ECX, <END_ADDR>

CMP EAX, ECX
JG  finished
MOV dl, BYTE PTR [EAX]
XOR dl, 0x74
MOV BYTE PTR [EAX], dl
INC EAX
JMP boucle
finished:
POPAD

HEX OPCODES ==> (with START_ADDR=0, END_ADDR=0, OUT_ADDR=0)
60					pushad
B800000000			mov eax, 00000000
B900000000			mov ecx, 00000000
boucle:
3BC1				cmp eax, ecx
7D0A				jge finis
8A10				mov dl, byte ptr [eax]
80F274				xor dl, 4A
8810				mov byte ptr [eax], dl
40					inc eax
EBF2				jmp boucle
finis:
61					popad

// ============================
// jumper
// ============================
MOV ECX, <ORIGINAL_ENTRY_POINT_AS_VA>
JMP ECX

HEX OPCODES ==> (with ORIGINAL_ENTRY_POINT_AS_VA=0)
B900000000			mov ecx, 00000000
FFE1				jmp ecx 
*/
class argv_228
{
	public:
		argv_228();
		void					clear ();

		IMAGE_DOS_HEADER 		argv_276;
		IMAGE_NT_HEADERS 		argv_743;
		int32_t					argv_734;
		IMAGE_SECTION_HEADER * 	argv_886;
		long					argv_764;
		long					argv_860;
		long					argv_306;
		int32_t					argv_373;
		int32_t					argv_846;	
		uint32_t				maximum_offset;
		int32_t					argv_731;
		int32_t					argv_182; // PUSHAD + POPAD
		int32_t					argv_255;
		int32_t					argv_636;
		unsigned long			argv_765; // for argv_295 argv_248 detection
};

class argv_226
{
private:
	argv_195		argv_238;
	bool			argv_180;
	string			argv_309;
	string			argv_181;
	string			argv_890;
	stack<int32_t>		argv_292;
	argv_228		argv_818;
	FILE *			argv_314;
	FILE *			argv_313;
	int32_t			argv_834;
	int32_t			argv_833;
	// argv_645 part
	void			argv_749 ();
	void			argv_845 ();
	bool			compute_maximum_offset (); // for argv_295 argv_248 detection  
	int32_t			argv_662 (long);
	bool			argv_822 ();
	bool			argv_823 (bool);
	string			argv_288 (int32_t);
	void			clear ();
	bool			argv_233 ();
	bool			argv_237 ();
	bool			argv_645 ();
	// rebuild part
	void			argv_870 (bool);
	bool			argv_843 ();
	long			argv_223 ();
	long			argv_222 ();
	long			argv_220 ();
	long			argv_851 (long, long);
	bool			argv_158 (long, long, unsigned char *);
	bool			argv_155 ();
	bool			argv_156 ();
	bool			argv_157 ();
	bool			argv_188 ();
	bool			argv_839 ();
	bool			argv_840 ();
	bool			argv_286 ();
	bool			argv_187 ();
	bool			argv_838 ();
	int32_t			argv_221 (bool);

public:
	argv_226 ();
	bool			argv_769 (const char *, bool _create_backup=false);
	void			argv_330 (vector<string>&);
};

#endif // argv_139
