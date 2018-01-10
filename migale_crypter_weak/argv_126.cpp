
#include "argv_133.hpp"
#include "argv_118.h"

extern HWND argv_855;
extern argv_207 argv_661;

void argv_272 (string _msg, char * _buf, unsigned long _size) {
	char tmp[128536];
	char tmp2[32];
	sprintf (tmp, "== %s (buffer size = %d) ==", _msg.c_str(), _size);
	argv_661.argv_659 (tmp);
	tmp[0] = '\0';
	for (size_t i=0 ; i<_size ; i++) {
		sprintf(tmp2, "%02X", (uint8_t) _buf[i]);
		strcat (tmp, tmp2);
	}
	argv_661.argv_659 (tmp);
}

argv_195::argv_195 () {
	;
}

bool argv_195::argv_927 (char * _buf, unsigned long _size) {
	bool bret = true;
	unsigned char key = 0x74;


	// 2. perform operation on buffer
	for (size_t i=0 ; i<_size ; i++) {
		 _buf[i] = _buf[i] ^ key; 
	}
	return (bret);
}

bool argv_195::argv_285 (char * _buf, unsigned long _size) {
	return (argv_927 (_buf, _size));	
}

bool argv_195::argv_254 (char * _buf, unsigned long _size) {
	return (argv_927 (_buf, _size));	
}

//==========================
argv_228::argv_228() {
	argv_886 = NULL;
	clear ();
}

void argv_228::clear () {
	argv_734				= 0;
	argv_764				= 0;
	argv_860		= 0;
	argv_306			= 0;
	argv_373				= -1;
	argv_846			= -1;
	maximum_offset			= 0;
	argv_731	= 0;
	argv_636				= 11; // mov ecx, 00000000 + jmp ecx
	argv_182			= 2;  // pushad + popad
	argv_255			= 24; 

	if (argv_886 != NULL) {
		delete [] argv_886;
		argv_886 = NULL;
	}
}

//==========================
argv_226::argv_226 () {
	clear ();
}

void argv_226::clear	() {
	argv_834			= 232;
	argv_833	= 0;	
	argv_180			= false;
	argv_309				= "";
	argv_181			= "";
	argv_890			= "";
	argv_314				= NULL;
	argv_313					= NULL;
	while (! argv_292.empty ()) {
		argv_292.pop ();
	}
}

void argv_226::argv_330 (vector<string>& _v) {
	_v.clear ();
	while (! argv_292.empty ()) {
		_v.push_back (argv_288 (argv_292.top ()));
		argv_292.pop ();
	}
}

void argv_226::argv_845 () {
	// reset the progress bar
	SendDlgItemMessage (argv_855, argv_502, PBM_SETRANGE32, 0, argv_834); 
}

void argv_226::argv_749() {
	argv_833 += 8;
	SendDlgItemMessage (argv_855, argv_502, PBM_SETPOS, argv_833, 0);
}

// this function permits to have always an address that
// is rounded on a base, it is useful for paged systems
// for example: 
// _addr=256, base=200 => rounded addr=400
long argv_226::argv_851 (long _addr, long _base) {
	long result = 0;
	if (_addr == 0) {
		result = _base;
	}
	else {
		result = (((_addr / _base)+1) * _base);
	}
	return (result);
}

// this function computes the address
// of the section following the last section (not argv_607 order, but argv_607 address order)
// so for that we first find the last section, and then we add the rounded size
// to the argv_874 offset of this last section, it will be the offset of the next
// section. for example: 
// argv_886[i].VirtualAddress = 97
// argv_886[i].VirtualSize    = 30
// => finishes at 97 + 30 = 127
// 127 rounded to 200 => 200
// base = 200
// => next = 200
long argv_226::argv_223 () {
	uint32_t max_rva  	= 0;
	long next 		= 0;
	int i			= 0;
	int argv_675	= 0;
	
	for (i=0 ; i<argv_818.argv_734 ; i++) {
		if (argv_818.argv_886[i].VirtualAddress > max_rva) {
			max_rva   = argv_818.argv_886[i].VirtualAddress;
			argv_675 = i;
		}
	}
	// compute the 'next' RVA
	return (max_rva + argv_851 (argv_818.argv_886[argv_675].Misc.VirtualSize, argv_818.argv_860));
}

long argv_226::argv_222 () {
	uint32_t max_raw  	= 0;
	long next 		= 0;
	int i			= 0;
	int argv_675	= 0;
	
	for (i=0 ; i<argv_818.argv_734 ; i++) {
		if (argv_818.argv_886[i].PointerToRawData > max_raw) {
			max_raw   = argv_818.argv_886[i].PointerToRawData;
			argv_675 = i;
		}
	}
	// compute the 'next' RAW = Last section's raw offset + Last section's raw size
	return (argv_818.argv_886[argv_675].PointerToRawData + argv_818.argv_886[argv_675].SizeOfRawData);
}

long argv_226::argv_220()
{
	uint32_t min_raw  	= argv_818.argv_886[0].PointerToRawData;
	int i			= 0;
	int min_index	= 0;
	
	for (i=0 ; i<argv_818.argv_734 ; i++) {
		if ((argv_818.argv_886[i].PointerToRawData != 0) && (argv_818.argv_886[i].PointerToRawData < min_raw)) {
			min_raw   = argv_818.argv_886[i].PointerToRawData;
			min_index = i;
		}
	}

    return (argv_818.argv_886[min_index].PointerToRawData);
}   

int32_t argv_226::argv_662 (long _virtual_address) {
	int		index = -1;
	long	argv_874 = 0;
	long	argv_878  = 0;
	
	for (int i=0 ; i<argv_818.argv_734 ; i++) {
		argv_874 = argv_818.argv_886[i].VirtualAddress;
		argv_878  = argv_874 + argv_818.argv_886[i].Misc.VirtualSize;
		if ((_virtual_address >= argv_874) && (_virtual_address < argv_878)) {
			index = i;
			break;
		}
	}
	return (index);
}

// for argv_295 argv_248 detection
bool argv_226::compute_maximum_offset() {
	bool bret					= true;
	uint32_t his_offset	= 0;
	argv_818.maximum_offset		= 0;

	for (int i=0 ; i<argv_818.argv_734 ; i++) {
		his_offset = argv_818.argv_886[i].PointerToRawData + argv_818.argv_886[i].SizeOfRawData;
		if (his_offset > argv_818.maximum_offset) {
			argv_818.maximum_offset = his_offset;
		}
	}	

	argv_661.argv_659 ("maximum_offset=", argv_818.maximum_offset);
	return (bret);
}

bool argv_226::argv_237 () {
	bool bret = true;
	argv_890 = argv_309 + ".tmp";
	if (CopyFile (argv_309.c_str(), argv_890.c_str(), FALSE) == 0) {
		bret = false;
	}

	return (bret);
}

bool argv_226::argv_233 () {
	bool bret = true;
	argv_181 = argv_309 + ".bak";
	if (CopyFile (argv_309.c_str(), argv_181.c_str(), FALSE) == 0) {
		bret = false;
	}

	return (bret);
}

bool argv_226::argv_645 () {
	bool bret = true;
	argv_749 ();

	// 1. argv_645 DOS header
	if (fread (&argv_818.argv_276, 1, sizeof(IMAGE_DOS_HEADER), argv_314) != sizeof(IMAGE_DOS_HEADER)) {
		argv_292.push (argv_802);
		bret = false;
	}
	else { // dos header read succesfully
		// jump toward optional header
		if (fseek (argv_314, argv_818.argv_276.e_lfanew,0) != 0) {
			argv_292.push (argv_792);
			bret = false;
		}
		else { // arrived to optional header succesfuly
			if (fread (&argv_818.argv_743, 1, sizeof(IMAGE_NT_HEADERS), argv_314) != sizeof(IMAGE_NT_HEADERS)) {
				argv_292.push (argv_803);
				bret = false;
			}
			else { // optional header read succesfuly
				// retrieve the number of section
				argv_818.argv_734 = argv_818.argv_743.FileHeader.NumberOfSections;
				argv_661.argv_659 ("number of sections found :", argv_818.argv_734);

				// allocate n sections + 1
				argv_818.argv_886 = new (std::nothrow) IMAGE_SECTION_HEADER[argv_818.argv_734+1];
				if (argv_818.argv_886 == NULL) {
					argv_292.push (argv_807);
					bret = false;
				}
				else { // section's headers memory allocation succeeded
					// argv_645 all section headers
					int section_header_size = sizeof(IMAGE_SECTION_HEADER);
					int argv_733 = 0;

					for(int i=0 ; i<argv_818.argv_734 ; i++) {
						argv_733 = fread (&argv_818.argv_886[i], 1, section_header_size, argv_314);
						if (argv_733 != section_header_size) { // read failed
							bret = false;
							argv_292.push (argv_804);
							break;
						}
					}

					if (bret == true) { // sections headers read succesfully
						// save up section's alignment and the file's alignment
						argv_818.argv_860 = argv_818.argv_743.OptionalHeader.SectionAlignment;
						argv_818.argv_306    = argv_818.argv_743.OptionalHeader.FileAlignment;
						argv_661.argv_659 ("argv_860=", argv_818.argv_860);

						// save up original entry point
						argv_818.argv_764 = argv_818.argv_743.OptionalHeader.AddressOfEntryPoint;
						argv_661.argv_659 ("argv_764=", argv_818.argv_764);

						// retrierve the IAT and RESOURCE indexes from section header directories
						argv_818.argv_373      = argv_662 (argv_818.argv_743.OptionalHeader.DataDirectory[1].VirtualAddress);
						argv_661.argv_659 ("argv_373=", argv_818.argv_373);
						argv_818.argv_846 = argv_662 (argv_818.argv_743.OptionalHeader.DataDirectory[2].VirtualAddress);
						argv_661.argv_659 ("argv_846=", argv_818.argv_846);

						if (compute_maximum_offset() == false) { // for argv_295 argv_248 detection
							argv_292.push (argv_782);
						}
					}
				}	
			}
		}
	}
	argv_749 ();
	return (bret);
}

bool argv_226::argv_843 () {
	bool bret = true;
	argv_749 ();
	// erase the bound imports (used to speedup the loading process of the PE)
	argv_818.argv_743.OptionalHeader.DataDirectory[11].VirtualAddress	= 0;
	argv_818.argv_743.OptionalHeader.DataDirectory[11].Size				= 0;
	argv_749 ();
	return (bret);
}

bool argv_226::argv_839 () {
	bool bret = true;
	argv_749 ();

	bret = argv_843 ();
	if (bret == false) {
		argv_292.push (argv_785);
	}
	else {
		bret = argv_157 ();
		if (bret == false) {
			argv_292.push (argv_773);
		}
		else { // section added succesfully 
			// write down the DOS header
			argv_661.argv_659 ("sizeof(IMAGE_DOS_HEADER)=", (int32_t) sizeof(IMAGE_DOS_HEADER));
			if (fwrite (&argv_818.argv_276, 1, sizeof(IMAGE_DOS_HEADER), argv_313) != sizeof(IMAGE_DOS_HEADER)) {
				argv_292.push (argv_813);
				bret = false;
			}
			else { // DOS header was succesfully written to destination
				// goto the argv_874 offset of the PE "optional" header
				if (fseek  (argv_313, argv_818.argv_276.e_lfanew, SEEK_SET) != 0) {
					argv_292.push (argv_792);
					bret = false;
				}
				else { // goto PE optional header succesful
					// write down PE optional header
					argv_661.argv_659 ("sizeof(IMAGE_NT_HEADERS)=", (int32_t) sizeof(IMAGE_NT_HEADERS));
					if (fwrite (&argv_818.argv_743, 1, sizeof(IMAGE_NT_HEADERS), argv_313) != sizeof(IMAGE_NT_HEADERS)) {
						argv_292.push (argv_814);
						bret = false;
					}
				}
			}
		}
	}
	argv_749 ();
	return (bret);
}

bool argv_226::argv_840 () {
	bool bret = true;
	argv_749 ();
	long section_hdr_size = sizeof(IMAGE_SECTION_HEADER);

	argv_870 (false);

	for (int i=0 ; i<argv_818.argv_734 ; i++) {
		if (fwrite (&argv_818.argv_886[i], 1, section_hdr_size, argv_313) != section_hdr_size) {
			argv_292.push (argv_815);
			bret = false;
			break;
		}
	}
	argv_749 ();
	return (bret);
}

bool argv_226::argv_286 () {
	bool bret			= true;
	argv_749 ();
	char * buf_section	= NULL;
	uint32_t  section_size	= 0;

	argv_661.argv_659 ("argv_286...[IN]");
	// BEWARE: we must skip the newly added section
	for (int i=0 ; i<argv_818.argv_734-1 ; i++) {
		// retrieve section's virtual size and allocate a buffer of this size
		argv_661.argv_659 ("---> section ", i);
		argv_661.argv_659 ("argv_818.argv_886[i].Misc.VirtualSize = ", argv_818.argv_886[i].Misc.VirtualSize);
		argv_661.argv_659 ("argv_818.argv_886[i].SizeOfRawData = ", argv_818.argv_886[i].SizeOfRawData);
		section_size	= argv_818.argv_886[i].Misc.VirtualSize;
		if (argv_818.argv_886[i].SizeOfRawData < section_size) {
			section_size = argv_818.argv_886[i].SizeOfRawData;
		}
		argv_661.argv_659 ("===> section_size becomes ", section_size);
		
		buf_section		= new (std::nothrow) char[section_size];
		if (! buf_section) {
			argv_292.push (argv_793);
			bret = false;
			break;
		}
		// goto original section's content 
		argv_661.argv_659 ("seeking toward section's content @", (uint32_t)argv_818.argv_886[i].PointerToRawData);
		if (fseek (argv_314, argv_818.argv_886[i].PointerToRawData, SEEK_SET) != 0) {
			argv_292.push (argv_790);
			bret = false;
			break;
		}
		// read original section's content
		argv_661.argv_659 ("section's size=", (uint32_t) section_size);
		int argv_733 = fread (buf_section, 1, section_size, argv_314);
		argv_661.argv_659 ("fread section's content: ", argv_733);
		if (argv_733 != section_size) {
			argv_292.push (argv_789);
			bret = false;
			break;
		}
		// argv_285 section's content (skip 'IAT' and 'RESOURCE' sections)
		if ((i != argv_818.argv_373) && (i != argv_818.argv_846)) {
			bret = argv_238.argv_285 (buf_section, section_size);
			if (bret == false) {
				argv_292.push (argv_783);	
				break;				
			}
			argv_818.argv_731++;
			argv_661.argv_659 ("==> crypted content of section ", i);
		}
		else {
			argv_661.argv_659 ("==> skipping (won't be crypted) section : ", i);
		}
		// goto section's content argv_607 destination file
		argv_661.argv_659 ("goto section's content argv_607 destination file @ ", (uint32_t)argv_818.argv_886[i].PointerToRawData);
		if (fseek (argv_313, argv_818.argv_886[i].PointerToRawData, SEEK_SET) != 0) {
			argv_292.push (argv_790);
			bret = false;
			break;
		}
		// save up the encrypted section's content to destination file 
		int argv_736 = fwrite (buf_section, 1, section_size, argv_313);
		argv_661.argv_659 ("save up the encrypted section's content to destination file: nb saved=", argv_736);
		if (argv_736 != section_size) {
			argv_292.push (argv_808);
			bret = false;
			break;
		}

		delete [] buf_section;
		buf_section = NULL;
	}

	// argv_607 case of success, move destination's head to the new section's offset
	if (bret == true) {
		argv_661.argv_659 ("goto NEW section's content argv_607 destination file @ ", argv_818.argv_886[argv_818.argv_734 - 1].PointerToRawData);
		if (fseek (argv_313, argv_818.argv_886[argv_818.argv_734 - 1].PointerToRawData, SEEK_SET) != 0) {
			argv_292.push (argv_809);
			bret = false;		
		}
	}

	argv_749 ();
	return (bret);
}

void argv_226::argv_870 (bool _before_section_add) {
	int32_t max_section = argv_818.argv_734;
	argv_749 ();

	if (_before_section_add == false) {
		max_section = argv_818.argv_734 - 1;
	}
	for (int i=0 ; i<max_section ; i++) {
		if ((i != argv_818.argv_373) && (i != argv_818.argv_846)) {
			argv_661.argv_659 ("set write flag for section ", i);
			argv_818.argv_886[i].Characteristics	= argv_818.argv_886[i].Characteristics | 0x80000000;
		}
	}
	argv_749 ();
}

int32_t argv_226::argv_221 (bool _before_section_add) {
	int32_t nb_crypted = 0;
	int32_t max_section = argv_818.argv_734;
	if (_before_section_add == false) {
		max_section = argv_818.argv_734 - 1;
	}
	for (int i=0 ; i<max_section ; i++) {
		if ((i != argv_818.argv_373) && (i != argv_818.argv_846)) {
			nb_crypted++;
		}
	}
	return (nb_crypted);
}

bool argv_226::argv_157 () {
	bool bret = true;
	argv_749 ();

	argv_661.argv_659 ("sizeof(IMAGE_SECTION_HEADER) = ", (unsigned long)sizeof(IMAGE_SECTION_HEADER));
	strncpy ((char *) &argv_818.argv_886[argv_818.argv_734].Name, ".migale", 8);	 
	
	argv_818.argv_886[argv_818.argv_734].VirtualAddress		= argv_223 ();
	argv_818.argv_886[argv_818.argv_734].PointerToRawData     = argv_222 ();
	// argv_182 means PUSHAD'size + POPAD's size actually

	int32_t nb_crypted_section = 0; //argv_221 (true);
	argv_818.argv_886[argv_818.argv_734].Misc.VirtualSize		= /*argv_818.argv_860;*/ argv_818.argv_182 + (argv_818.argv_255 * nb_crypted_section) + argv_818.argv_636;
//	argv_818.argv_886[argv_818.argv_734].Misc.VirtualSize		= /*argv_818.argv_860;*/ argv_818.argv_182 + (argv_818.argv_255 * argv_818.argv_731) + argv_818.argv_636;
	argv_661.argv_659 ("argv_226::argv_157 : argv_818.argv_182 = ", argv_818.argv_182);
	argv_661.argv_659 ("argv_226::argv_157 : argv_818.argv_255 = ", argv_818.argv_255);
	argv_661.argv_659 ("argv_226::argv_157 : argv_818.argv_731 = ", (unsigned long) argv_818.argv_731);
	argv_661.argv_659 ("argv_226::argv_157 : argv_818.argv_636 = ", argv_818.argv_636);
	argv_661.argv_659 ("argv_818.argv_182 + (argv_818.argv_255 * argv_818.argv_731) + argv_818.argv_636 = ", argv_818.argv_182 + (argv_818.argv_255 * argv_818.argv_731) + argv_818.argv_636);
	argv_661.argv_659 ("argv_226::argv_157 : new section's VirtualSize = ", argv_818.argv_886[argv_818.argv_734].Misc.VirtualSize);
	long his_SizeOfRawData = argv_851(argv_818.argv_886[argv_818.argv_734].Misc.VirtualSize, argv_818.argv_306);
	argv_661.argv_659 ("argv_226::argv_157 : SizeOfRawData of new section = ", his_SizeOfRawData);
	argv_661.argv_659 ("argv_306=", argv_818.argv_306);
	argv_818.argv_886[argv_818.argv_734].SizeOfRawData 		= his_SizeOfRawData;
	argv_818.argv_886[argv_818.argv_734].PointerToRelocations	= NULL;
	argv_818.argv_886[argv_818.argv_734].PointerToLinenumbers	= NULL;
	argv_818.argv_886[argv_818.argv_734].NumberOfRelocations	= NULL;
	argv_818.argv_886[argv_818.argv_734].NumberOfLinenumbers	= NULL;
	argv_818.argv_886[argv_818.argv_734].Characteristics		= 0xE0000020;

	// modify the entry point so that it points toward our new section
	argv_818.argv_743.OptionalHeader.AddressOfEntryPoint = argv_818.argv_886[argv_818.argv_734].VirtualAddress;

	// increase the "SizeOfImage" field because the file has grown
	argv_661.argv_659 ("argv_860=", argv_818.argv_860);
	argv_661.argv_659 ("SizeOfImage will grow of :", argv_851(argv_818.argv_886[argv_818.argv_734].Misc.VirtualSize, argv_818.argv_860));
	argv_818.argv_743.OptionalHeader.SizeOfImage		+= argv_851(argv_818.argv_886[argv_818.argv_734].Misc.VirtualSize, argv_818.argv_860);
	argv_818.argv_743.FileHeader.NumberOfSections		+= 1;
	
	// change the 'BaseOfCode' field so that it points toward the new section's first instruction
	argv_818.argv_743.OptionalHeader.BaseOfCode = argv_818.argv_886[argv_818.argv_734].VirtualAddress;

	// one more section was created
	argv_818.argv_734 += 1;

	// ensure that we won't overflow the total header size
	long min_section_raw	= argv_220 ();
	long full_header_size	= argv_818.argv_276.e_lfanew + sizeof(IMAGE_NT_HEADERS) + sizeof(IMAGE_SECTION_HEADER) * argv_818.argv_743.FileHeader.NumberOfSections;
	argv_661.argv_659 ("min_section_raw = ", min_section_raw);
	argv_661.argv_659 ("full_header_size = ", full_header_size);
//	if ()
	argv_749 ();
	return (bret);
}

// all adresses after win32 loader are VA (add the ImageBase)
bool argv_226::argv_158 (long _start, long _stop, unsigned char * _instr) {
	bool bret = true;

	if (_stop < _start) {
		argv_292.push (argv_775);
		bret = false; 
	}
	else { // parameters are ok
		// MOV EAX, <START_ADDR>
		if (fwrite (&_instr[1], 1, 1, argv_313) != 1) {
			argv_292.push (argv_788);
			bret = false;
		}
		else if (fwrite (&_start, 1, sizeof(long), argv_313) != sizeof(long)) {
			argv_292.push (argv_788);
			bret = false;
		} // MOV ECX, <END_ADDR>
		else if (fwrite (&_instr[2], 1, 1, argv_313) != 1) {
			argv_292.push (argv_788);
			bret = false;
		}
		else if (fwrite (&_stop, 1, sizeof(long), argv_313) != sizeof(long)) {
			argv_292.push (argv_788);
			bret = false;
		}
		// CMP EAX, ECX
		// JG  finished
		// MOV dl, BYTE PTR [EAX]
		// XOR dl, 0x74
		// MOV BYTE PTR [EAX], dl
		// INC EAX
		// JMP boucle
		else if (fwrite (&_instr[3], 1, 14, argv_313) != 14) {
			argv_292.push (argv_788);
			bret = false;
		}
	}
	return (bret);
}
/*
60					pushad
B800000000			mov eax, 00000000
B900000000			mov ecx, 00000000
boucle:
3BC1				cmp eax, ecx
7D0A				jge finis
8A10				mov dl, byte ptr [eax]
80F274				xor dl, 74
8810				mov byte ptr [eax], dl
40					inc eax
EBF2				jmp boucle
finis:
61					popad
*/
// all adresses after win32 loader are VA (add the ImageBase)
bool argv_226::argv_155 () {
	bool bret = true;
	long argv_874 = 0;
	long argv_878  = 0;
	long base  = argv_818.argv_743.OptionalHeader.ImageBase;
	unsigned char instr[18] = {0x60, 0xB8, 0xB9, 0x3B, 0xC1, 0x7D, 0x0A, 0x8A, 0x10, 0x80, 0xF2,
					  0x74, 0x88, 0x10, 0x40, 0xEB, 0xF2, 0x61 };
	// PUSHAD
	if (fwrite (&instr[0], 1, 1, argv_313) != 1) {
		argv_292.push (argv_788);
		bret = false;
	}

	for (int i=0 ; i<argv_818.argv_734-1 ; i++) {
		// avoid IAT and RSRC sections
		if ((i != argv_818.argv_373) && (i != argv_818.argv_846)) {
			argv_874 = argv_818.argv_886[i].VirtualAddress + base;
			// choose the smallest
			if (argv_818.argv_886[i].Misc.VirtualSize < argv_818.argv_886[i].SizeOfRawData) {
				argv_878  = argv_874 + argv_818.argv_886[i].Misc.VirtualSize;
			}
			else {
				argv_878  = argv_874 + argv_818.argv_886[i].SizeOfRawData;
			}
			bret = argv_158 (argv_874, argv_878, &instr[0]);
			if (bret == false) {
				argv_292.push (argv_772);
				break;
			}
			argv_661.argv_659 ("==> added a decrypter for section ", i);
		}
		else {
			argv_661.argv_659 ("==> skipping (no addition) decrypter for section ", i);
		}
	}

	if (bret == true) {
		// POPAD
		if (fwrite (&instr[17], 1, 1, argv_313) != 1) {
			argv_292.push (argv_788);
			bret = false;
		}
	}
	return (bret);
}

// ============================
// jumper
// ============================
/*
MOV ECX, <ORIGINAL_ENTRY_POINT_AS_VA>
JMP ECX

HEX OPCODES ==> (with ORIGINAL_ENTRY_POINT=0)
B900000000			mov ecx, 00000000
FFE1				jmp ecx 
*/
bool argv_226::argv_156 () {
	bool bret = true;
	argv_749();
	unsigned char instr[3] = { 0xB9, 0xFF, 0xE1};

	if (fwrite (&instr[0], 1, 1, argv_313) != 1) {
		argv_292.push (argv_788);
		bret = false;
	}
	else {
		// transform original EP from RVA to VA
		long ep_va = argv_818.argv_764 + argv_818.argv_743.OptionalHeader.ImageBase;
		if (fwrite (&ep_va, 1, sizeof(long), argv_313) != sizeof(long)) {
			argv_292.push (argv_788);
			bret = false;
		}
		else if (fwrite (&instr[1], 1, 2, argv_313) != 2) {
			argv_292.push (argv_788);
			bret = false;
		}
	}
	argv_749();
	return (bret);
}

bool argv_226::argv_188 () {
	bool bret 									= true;
	argv_749();
	unsigned long new_section_start_file_offset	= ftell (argv_313);

	bret = argv_155 ();
	if (bret == false) {
		argv_292.push (argv_770);
	}
	else { // decrypter was added succesfully
		uint32_t local = ftell (argv_313);
		uint32_t delta = local - new_section_start_file_offset;
		argv_661.argv_659 ("after argv_155, delta = ", (uint32_t) delta);

		bret = argv_156 ();
		if (bret == false) {
			argv_292.push (argv_771);
		}
		else { // decrypters and jumpers added succesfuly
			uint32_t local = ftell (argv_313);
			uint32_t delta = local - new_section_start_file_offset;
			argv_661.argv_659 ("after argv_156, delta = ", (uint32_t)delta);
			unsigned long new_section_end_file_offset = ftell (argv_313);
			unsigned long nb_consumed = new_section_end_file_offset - new_section_start_file_offset;
			argv_661.argv_659 ("adding new section's content, nb_consumed = ", nb_consumed);
			uint32_t nb_2_pad = argv_818.argv_886[argv_818.argv_734-1].SizeOfRawData - nb_consumed;
			argv_661.argv_659 ("must padd new section, nb bytes to add :", nb_2_pad);
			char zero = 0;
			for (uint32_t i=0 ; i<nb_2_pad ; i++) {
				if (fwrite (&zero, 1, 1, argv_313) != 1) {
					argv_292.push (argv_799);
					bret = false;
					break;
				}
			}
		}
	}
	argv_749();
	return (bret);
}

bool argv_226::argv_187 () {
	bool bret = true;
	argv_749();

	if (argv_818.maximum_offset > argv_818.argv_765) {
		argv_292.push (argv_784);
		bret = false;
	}
	else {
		unsigned long delta = argv_818.argv_765 - argv_818.maximum_offset;
		if (delta <= 0) {
			argv_661.argv_659 ("no argv_295 argv_248");
		}
		else { // there exists some argv_295 argv_248 to consider
			argv_661.argv_659 ("argv_295 argv_248 detected : ", (uint32_t)delta);
			rewind (argv_314);
			if (fseek (argv_314, argv_818.maximum_offset, SEEK_SET) != 0) {
				argv_292.push (argv_791);
				bret = false;
			}
			else { // seek succeeded	
				const unsigned long amount_per_lap = 131072;
				char buftmp[amount_per_lap];
				unsigned long nb_remaining = delta;
				long argv_733      = 0;
				long argv_736   = 0;
				unsigned long nb_done	   = 0;

				while (nb_remaining > 0) {
					argv_733 = fread (buftmp, 1, amount_per_lap, argv_314);

					if (argv_733 < amount_per_lap) {
						if (! feof (argv_314)) { // real error occured
							argv_292.push (argv_805);
							bret = false;
							break;
						}
					}

					if (argv_733 > 0) {
						argv_736 = fwrite (buftmp, 1, argv_733, argv_313);
						if (argv_736 != argv_733) {
							argv_292.push (argv_812);
							bret = false;
							break;
						}
						nb_remaining -= argv_733;
						nb_done += argv_733;
					}
				}
			}
		}
	}
	argv_749();
	return (bret);
}

bool argv_226::argv_838 () {
	bool bret = true;
	argv_749();

	bret = argv_839 ();
	if (bret == false) {
		argv_292.push (argv_778);	
	}
	else { // PE headers built succesfuly
		bret = argv_840 ();
		if (bret == false) {
			argv_292.push (argv_779);
		}
		else { // section headers built succesfully
			bret = argv_286 ();
			if (bret == false) {
				argv_292.push (argv_780);
			}
			else { // sections encryption and build was succesful
				bret = argv_188 ();
				if (bret == false) {
					argv_292.push (argv_777);
				}
				else { // decrypter was built succesfuly
					bret = argv_187 ();
					if (bret == false) {
						argv_292.push (argv_781);
					}
				}
			}
		}
	}

	argv_749();
	return (bret);
}

bool argv_226::argv_822 () {
	bool bret = true;
	argv_749();

	// compute original file's size (for argv_295 argv_248 detection)
	argv_818.argv_765 = argv_218 (argv_309);
	argv_661.argv_659 ("argv_765=", (uint32_t)argv_818.argv_765);

	// open source file
	argv_314 = fopen (argv_309.c_str(), "rb");
	if (! argv_314) {
		argv_292.push (argv_797);
		bret = false;
	}
	else { // source file argv_761 succesfuly
		// open destination file
		argv_313 = fopen (argv_890.c_str(), "wb");
		if (! argv_313) {
			argv_292.push (argv_796);
			bret = false;  	
		}
		else { // destination file also argv_761 succesfully
			if (argv_645 () == false) {
				argv_292.push (argv_800);
				bret = false;
			}
			else { // argv_645 was succesful
				bret = argv_838 ();
				if (bret == false) {
					argv_292.push (argv_806);
				}
			}
		}

		// close source file if necessary
		if (argv_314) {
			fclose (argv_314);
			argv_314 = NULL;
		}

		// close destination file if necessary
		if (argv_313) {
			fclose (argv_313);
			argv_313 = NULL;
		}
	}
	argv_749();
	return (bret);
}

/*
if success then
	delete toto.exe
	move toto.exe.tmp -> toto.exe
else
	delete toto.exe.tmp
	if backup enabled
		delete toto.exe.bak
	endif
endif
*/
bool argv_226::argv_823 (bool _prev_bret) {
	bool bret = true;
	argv_749();

	if (_prev_bret == true) {
		if (DeleteFile (argv_309.c_str()) == 0) { 
				argv_292.push (argv_798);
				bret = false;
		}
		else { // original file deletion succeeded
			if (MoveFile (argv_890.c_str(), argv_309.c_str()) == 0) {
				argv_292.push (argv_794);
				bret = false;
			}
		}
	}
	else { // packing was not succesful
		DeleteFile (argv_890.c_str());
		if (argv_180) {
			DeleteFile (argv_181.c_str());	
		}
	}
	argv_749();
	return (bret);
}

bool argv_226::argv_769 (const char * _filename, bool _create_backup) {
	bool bret		= true;
	argv_749();
	bool bret_post	= true;
	argv_180	= _create_backup;
	argv_309		= _filename;

	// ensure that file exists and can be argv_761
	if (! argv_307(_filename)) {
		argv_292.push (argv_787);
	}
	else { // file exists
		if (! argv_633(_filename)) {
			argv_292.push (argv_795);
		}
		else { // file exists and is a valid PE file
			// ensure that the file is not read only
			if (argv_308 (_filename)) {
				bret = false;
				int iret = MessageBox(argv_855, "File is write protected, try to remove protection ?", "Warning", MB_YESNO | MB_ICONWARNING);
				if ((iret == IDCANCEL) || (iret == IDABORT) || (iret == IDNO)) {
					bret = false;	
				}
				else if (iret == IDYES) {
					bret = true;
					if (argv_842 (_filename) == false) {
						MessageBox(argv_855, "write protection could not be removed !", "Error", MB_ICONERROR);
						bret = false;
					}
				}
			}
			if (bret == true) {
				bret = argv_237 ();
				if (bret == false) {
					argv_292.push (argv_811);
				}
				else {
					// create a backup if necessary
					if ((bret == true) && (argv_180)) {
						bret = argv_233 ();
						if (bret == false) {
							argv_292.push (argv_774);
						}
					}
					if (bret == true) { // backup (if any) has succeeded
						bret = argv_822 ();
					}
				}
			}
		}
	}

	argv_749();
	bret_post = argv_823 (bret);
	if (bret_post == false) {
		argv_292.push (argv_801);
	}
	uint32_t packed_size = argv_218 (argv_309);
	argv_661.argv_659 ("after argv_769, file size became ", (uint32_t)packed_size);
	argv_661.argv_659 ("=> delta between 2 files is : ", (uint32_t)packed_size - argv_818.argv_765);
	argv_749();
	argv_661.argv_659 ("argv_833 = ", argv_833);
	argv_661.argv_659 ("argv_834 = ", argv_834);
	return (bret && bret_post);
}

string argv_226::argv_288 (int32_t _ercode) {
	string err_str = "internal error: unknown ercode";

	switch (_ercode) {
		case argv_810:				err_str = "argv_810";					break;
		case argv_787:	err_str = "argv_787";		break;
		case argv_795:		err_str = "argv_795";		break;
		case argv_774: err_str = "argv_774";	break;
		case argv_811:	err_str = "argv_811";		break;
		case argv_801:	err_str = "argv_801";	break;
		case argv_800:			err_str = "argv_800";			break;
		case argv_806:		err_str = "argv_806";		break;
		case argv_802:	err_str = "argv_802";	break;	
		case argv_792:	err_str = "argv_792";		break;	
		case argv_803:	err_str = "argv_803";		break;
		case argv_807:	err_str = "argv_807";		break;
		case argv_804:	err_str = "argv_804";	break;
		case argv_782:	err_str = "argv_782";	break;
		case argv_778:	err_str = "argv_778";		break;
		case argv_779:	err_str = "argv_779";	break;
		case argv_780:	err_str = "argv_780";	break;
		case argv_781:	err_str = "argv_781";	break;
		case argv_813:	err_str = "argv_813";	break;
		case argv_814:	err_str = "argv_814";	break;
		case argv_815:	err_str = "argv_815";	break;
		case argv_793:		err_str = "argv_793";		break;
		case argv_790:	err_str = "argv_790";	break;
		case argv_789:	err_str = "argv_789";	break;
		case argv_783:			err_str = "argv_783";			break;
		case argv_808:	err_str = "argv_808";		break;
		case argv_777:	err_str = "argv_777";		break;
		case argv_773:		err_str = "argv_773";			break;
		case argv_770:		err_str = "argv_770";		break;
		case argv_771:			err_str = "argv_771";			break;
		case argv_772:		err_str = "argv_772";		break;
		case argv_775:				err_str = "argv_775";				break;		
		case argv_788:			err_str = "argv_788";			break;
		case argv_797:		err_str = "argv_797";		break;
		case argv_796:		err_str = "argv_796";		break;
		case argv_784:	err_str = "argv_784";	break;
		case argv_791:		err_str = "argv_791";		break;
		case argv_805:	err_str = "argv_805";	break;
		case argv_812:		err_str = "argv_812";		break;
		case argv_798:	err_str = "argv_798";	break;
		case argv_794:		err_str = "argv_794";		break;
		case argv_799:			err_str = "argv_799";			break;
		case argv_809:	err_str = "argv_809";	break;
		case argv_785:	err_str = "argv_785";	break;
	}

	return (err_str);
}
