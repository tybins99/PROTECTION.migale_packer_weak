
#include "argv_134.hpp"
#include <Wingdi.h>

extern argv_207 argv_661;

bool	argv_353			= true;
bool	argv_352	= true;
string	argv_350 = "";
int32_t	argv_351 = 0;

argv_194::argv_194() {
	clear();
}

void argv_194::argv_152 (uint8_t octet) {
	argv_913.push_back (octet);
}

void argv_194::argv_151 (uint8_t octet) {
	argv_293.push_back (octet);
}

void argv_194::argv_864 (string name_arg) {
	argv_727 = name_arg;
}

void argv_194::argv_863 (string comment_arg) {
	argv_212 = comment_arg;
}

void argv_194::argv_866 (int32_t size_arg) {
	size = size_arg;
}

void argv_194::set (int32_t size_arg, string name_arg) {
	clear();
	size	= size_arg;
	argv_727	= name_arg;
}

void argv_194::set (int32_t size_arg, string name_arg, string comment_arg) {
	argv_727 	= name_arg;
	argv_212	= comment_arg;
	size	= size_arg;
}

string argv_194::argv_336() {
	return (argv_727);
}

string argv_194::argv_321() {
	return (argv_212);
}

vector<uint8_t> argv_194::argv_346() {
	return (argv_913);
}

vector<uint8_t> * argv_194::argv_347() {
	return (&argv_913);		
}

vector<uint8_t> argv_194::argv_331() {
	return (argv_293);
}

int32_t argv_194::argv_344() {
	return (size);
}

bool argv_194::argv_305() {
	bool bret = true;
	
	int32_t value_size = argv_913.size();
	int32_t expected_value_size = argv_293.size();

	if (expected_value_size > 0) {
		if (value_size != expected_value_size) {
			bret = false;
		}
		else {
			for (int32_t i=0 ; i<value_size ; i++) {
				if (argv_913[i] != argv_293[i]) {
					bret = false;
					break;
				}
			}
		}
	}	

	return (bret);
}

void argv_194::clear() {
	argv_913.clear();
	argv_293.clear();
	argv_212 = "";
	argv_727 	= "";
	size	= 0;
}

void argv_194::argv_271 (HWND hDlg) {
	
	int32_t size = argv_913.size();
	int32_t expected_size = argv_293.size();
	char tmp[65536];
	char tmp2[65536];

	// 0. argv_727
	// out << " (" << c.size << " bytes) "; 
	argv_872 (tmp, 65536, "%s (%d bytes)", argv_727.c_str(), size);
	tmp[65535] = '\0';
	argv_661.argv_659 (tmp);
	if (argv_336() == "dos stub") {
		// out << " (argv_913 not displayed)";
		argv_661.argv_659 (" (argv_913 not displayed)");
		strcat (tmp, " (argv_913 not displayed)");
	}
	else {
		// 2. argv_913
		if (size > 0) {	
			// out << " -> ";
			// argv_661.argv_659 (" -> ");
			strcat (tmp, " -> ");
			if (argv_336() == "address of entry point") {
				argv_350 = "";		
			}

			argv_178 typ;
			bool is_nb_rva_and_size = false;
			if (argv_336() == "number of RVA and sizes") {
				is_nb_rva_and_size = true;
			}

			for (int32_t i=0 ; i<size ; i++) {
				argv_872 (tmp2, 32, "%02x ", argv_913[i]);
				tmp2[31] = '\0';
				
				// out << tmp << " "; 
				argv_661.argv_659 (tmp);
				strcat (tmp, tmp2);
				if (argv_336() == "address of entry point") {
					argv_350 += tmp2;
				}
				else if (is_nb_rva_and_size == true) {
					MessageBox(hDlg, tmp2, "Error", MB_OK | MB_ICONERROR);
					char tmpc[256];
					sprintf(tmpc, ":: %u", argv_913[i]);
					MessageBox(hDlg, tmpc, "Error", MB_OK | MB_ICONERROR);
					typ.argv_176[i] = argv_913[i]; 
				}
			}

			if (is_nb_rva_and_size == true) {
				char tmpb[256];
				sprintf(tmpb, "%u,%u,%u,%u -> %u", typ.argv_176[0], typ.argv_176[1], typ.argv_176[2], typ.argv_176[3], typ.argv_165);
				MessageBox(hDlg, tmpb, "Error", MB_OK | MB_ICONERROR);
				argv_351 = 0x0000A; // typ.argv_165; 
			}
		}		
	
		// 3.expected argv_913
		if (expected_size > 0) {
			// out << " (expected:";  
			argv_661.argv_659("(expected:");
			strcat (tmp, "(expected:");
			for (int32_t i=0 ; i<expected_size ; i++) {
				argv_872 (tmp2, 32, "%02x", argv_293[i]);
				tmp2[31] = '\0';
				// out << tmp;
				//argv_661.argv_659 (tmp);
				strcat (tmp, tmp2);
				if ((i+1) < expected_size) {
					// out << " ";
					//argv_661.argv_659(" ");
					strcat (tmp, " ");
				}	
			}
			// out << ")";
			//argv_661.argv_659(")");
			strcat (tmp, ")");

			if (argv_305() == false) {
				// out << "++ BAD VALUE";
				//argv_661.argv_659 ("++ BAD VALUE");
				strcat (tmp, "++ BAD VALUE");
				string stm = argv_336();
				if (stm == "dos header signature") {
					argv_352 = false;
				}

				if (stm == "pe signature") {
					argv_353 = false;
				}
			}
		}
	}	

	// 4. argv_212
	if (argv_212.size() > 0) {
		// out << " (" << c.argv_212 << ")"; 
		argv_872 (tmp2, 65536, "(%s)", argv_212.c_str());
		tmp2[65535] = '\0';
		//argv_661.argv_659 (tmp);
		strcat (tmp, tmp2);
	}	
	argv_661.argv_659 (tmp);
}
/*
ostream& operator << (ostream& out, argv_194& c) {
	int32_t size = c.argv_913.size();
	int32_t expected_size = c.argv_293.size();	

	// 0. argv_727
	out << c.argv_727;

	out << " (" << c.size << " bytes) "; 
	
	if (c.argv_336() == "dos stub") {
		out << " (argv_913 not displayed)";
	}
	else {
		// 2. argv_913
		if (size > 0) {	
			out << " -> ";
			char tmp[32];
		
			for (int32_t i=0 ; i<size ; i++) {
				argv_872 (tmp, 32, "%02x", c.argv_913[i]);
				tmp[31] = '\0';
				out << tmp << " "; 
			}
		}		
	
		// 3.expected argv_913
		if (expected_size > 0) {
			char tmp[32];
			out << " (expected:";  
			for (int32_t i=0 ; i<expected_size ; i++) {
				argv_872 (tmp, 32, "%02x", c.argv_293[i]);
				tmp[31] = '\0';
				out << tmp;
				if ((i+1) < expected_size) {
					out << " ";
				}	
			}
			out << ")";

			if (c.argv_305() == false) {
				out << "++ BAD VALUE";
			}
		}
	}	

	// 4. argv_212
	if (c.argv_212.size() > 0) {
		out << " (" << c.argv_212 << ")"; 
	}	
	
	return (out);
}
*/
//////////////////////////////////////////////
argv_202::argv_202() {
	clear();	
}

void argv_202::clear() {
	argv_310 = false;
	argv_907.clear();
	argv_246 = 0;
	argv_727 = "";
}

void argv_202::argv_864 (string name_arg) {
	argv_727 = name_arg;
}

string argv_202::argv_336() {
	return (argv_727);
}

void argv_202::argv_154 (const argv_194& c) {
	argv_907.push_back (c);
}

bool argv_202::argv_268 (string argv_727) {
	bool bret = false;

	vector<argv_194>::iterator iter;
	for (iter=argv_907.begin() ; iter != argv_907.end() ; ++iter) {
		if (iter->argv_336() == argv_727) {
			argv_907.erase (iter);
			bret = true;
			break;
		}
	}

	return (bret); 
}

bool argv_202::argv_332 (argv_194 *& couple_ptr) {
	bool bret = false;

	if (argv_907.size() > 0) {
		couple_ptr = &argv_907[0];
		argv_310 = true;
		argv_246 = 1; 
		bret = true;
	}
	
	return (bret);
}

bool argv_202::argv_341 (argv_194 *& couple_ptr) {
	bool bret = false;

	if ((argv_310 == true) && (argv_246 < argv_907.size())) {
		couple_ptr = &argv_907[argv_246];
		argv_246++;
		bret = true;
	}

	return (bret);
}

bool argv_202::argv_323 (string his_name, argv_194 *& couple_ptr) {
	bool bret = false;

	int32_t size = argv_907.size();
	cerr << "argv_202::argv_323 - argv_907.size() = " << argv_907.size() << endl;
	for (int32_t i=0 ; i<size ; i++) {
		cerr << "argv_202::argv_323 - argv_907[i].argv_336() = " << argv_907[i].argv_336() << endl;
		if (argv_907[i].argv_336() == his_name) {
			couple_ptr = &argv_907[i];
			bret = true;	
			break;
		}
	}
	
	return (bret);
}

int32_t argv_202::size() {
	return (argv_907.size());
}

void argv_202::argv_271 (HWND hDlg) {
	int32_t size = argv_907.size();

	string argv_727 = argv_336();
	if (argv_727 != "") {
		// out << "- " << argv_727 << " -" << endl;
		char tmp[65536];
		argv_872 (tmp, 65536, "-%s-", argv_727.c_str());
		tmp[65535] = '\0';
		argv_661.argv_659 (tmp);
	}
	
	for (int32_t i=0 ; i<size ; i++) {
		argv_907[i].argv_271(hDlg);
	}

}
/*
ostream& operator << (ostream& out, argv_202& g) {
	int32_t size = g.argv_907.size();

	string argv_727 = g.argv_336();
	if (argv_727 != "") {
		out << "- " << argv_727 << " -" << endl;
	}
	
	for (int32_t i=0 ; i<size ; i++) {
		out << g.argv_907[i] << endl;
	}
	
	return (out);
}
*/
/////////////////////////////
void argv_227::clear () {
	argv_732 								= 0;
	argv_735 								= 0;
	argv_746					= 0;	
	argv_245						= NULL;
	argv_894							= 0;
	argv_912					= true;
	argv_910			= true;
	argv_353			= true;
	argv_352	= true;
	argv_287						= "";
	argv_350							= "";
}

argv_227::argv_227() {
	clear();
	argv_194 couple_tmp;
	argv_276.argv_864 ("dos header");	
	// dos header ===============================
	couple_tmp.set (2, "dos header signature");
	couple_tmp.argv_151 (0x5A);
	couple_tmp.argv_151 (0x4D);
	argv_276.argv_154 (couple_tmp);

	couple_tmp.set (2, "Last Page Size");
	argv_276.argv_154 (couple_tmp);

	couple_tmp.set (2, "Total pages argv_607 file");
	argv_276.argv_154 (couple_tmp);

	couple_tmp.set (2, "Relocation items");
	argv_276.argv_154 (couple_tmp);

	couple_tmp.set (2, "paragraphs argv_607 header");
	argv_276.argv_154 (couple_tmp);

	couple_tmp.set (2, "minimum argv_295 paragraphs");
	argv_276.argv_154 (couple_tmp);
	
	couple_tmp.set (2, "maximum argv_295 paragraphs");
	argv_276.argv_154 (couple_tmp);

	couple_tmp.set (2, "initial stack segment");
	argv_276.argv_154 (couple_tmp);
	
	couple_tmp.set (2, "initial stack pointer");
	argv_276.argv_154 (couple_tmp);
	
	couple_tmp.set (2, "complemented checksum");
	argv_276.argv_154 (couple_tmp);

	couple_tmp.set (2, "initial instruction pointer");
	argv_276.argv_154 (couple_tmp);
	
	couple_tmp.set (2, "initial code sgement");
	argv_276.argv_154 (couple_tmp);
	
	couple_tmp.set (2, "relocation table offset");
	argv_276.argv_154 (couple_tmp);
	
	couple_tmp.set (2, "overlay number");
	argv_276.argv_154 (couple_tmp);
	
	couple_tmp.set (32, "argv_844");
	argv_276.argv_154 (couple_tmp);

	couple_tmp.set (2, "offset to new header");
	argv_276.argv_154 (couple_tmp);
	
	// dos stub =================================
	argv_278.argv_864 ("dos stub");
	couple_tmp.set (argv_746, "dos stub");
	argv_278.argv_154 (couple_tmp);

	// pe header ================================
	argv_820.argv_864 ("pe header");
	couple_tmp.set (4, "pe signature");
	couple_tmp.argv_151 (0x00);
	couple_tmp.argv_151 (0x00);
	couple_tmp.argv_151 (0x45);
	couple_tmp.argv_151 (0x50);
	argv_820.argv_154 (couple_tmp);
	
	couple_tmp.set (2, "machine");
	argv_820.argv_154 (couple_tmp);

	couple_tmp.set (2, "number of section");
	argv_820.argv_154 (couple_tmp);

	couple_tmp.set (4, "argv_889 datestamp");
	argv_820.argv_154 (couple_tmp);

	couple_tmp.set (4, "symbol pointer");
	argv_820.argv_154 (couple_tmp);

	couple_tmp.set (4, "number of symbols");
	argv_820.argv_154 (couple_tmp);

	couple_tmp.set (2, "size of optional header");
	argv_820.argv_154 (couple_tmp);

	couple_tmp.set (2, "characteristics");
	argv_820.argv_154 (couple_tmp);

	// optional header ================================
	argv_762.argv_864 ("optional header");
	couple_tmp.set (2, "magic");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (2, "linker version");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (4, "size of code");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (4, "size of initialized argv_248");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (4, "size of uninitialized argv_248");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (4, "address of entry point");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (4, "base of code");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (4, "base of argv_248");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (4, "image base");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (4, "section alignment");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (4, "file alignment");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (2, "major argv_766 version");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (2, "minor argv_766 version");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (2, "major image version");
	argv_762.argv_154 (couple_tmp);
	
	couple_tmp.set (2, "minor image version");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (2, "major subsystem version");
	argv_762.argv_154 (couple_tmp);	

	couple_tmp.set (2, "minor subsystem version");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (4, "argv_844");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (4, "size of image");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (4, "size of headers");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (4, "checksum");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (2, "subsystem");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (2, "dll characteristics");	
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (4, "size of stack reserve");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (4, "size of stack commit");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (4, "size of heap reserve");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (4, "size of heap commit");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (4, "loader flags");
	argv_762.argv_154 (couple_tmp);

	couple_tmp.set (4, "number of RVA and sizes");
	argv_762.argv_154 (couple_tmp);

	// argv_248 directories ==================
	argv_830 ("IMAGE_DIRECTORY_ENTRY_EXPORT");
	argv_830 ("IMAGE_DIRECTORY_ENTRY_IMPORT");
	argv_830 ("IMAGE_DIRECTORY_ENTRY_RESOURCE");
	argv_830 ("IMAGE_DIRECTORY_ENTRY_EXCEPTION");
	
	argv_830 ("IMAGE_DIRECTORY_ENTRY_SECURITY");
	argv_830 ("IMAGE_DIRECTORY_ENTRY_BASERELOC");
	argv_830 ("IMAGE_DIRECTORY_ENTRY_DEBUG");
	argv_830 ("IMAGE_DIRECTORY_ENTRY_ARCHITECTURE");
	
	argv_830 ("IMAGE_DIRECTORY_ENTRY_GLOBALPTR");
	argv_830 ("IMAGE_DIRECTORY_ENTRY_TLS");
	argv_830 ("IMAGE_DIRECTORY_ENTRY_LOADCONFIG");
	argv_830 ("IMAGE_DIRECTORY_ENTRY_BOUNDIMPORT");
	
	argv_830 ("IMAGE_DIRECTORY_ENTRY_IAT");
	argv_830 ("IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT");
	argv_830 ("IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR");
	argv_830 ("unnamed directory");

	// section headers (argv_274 at runtime)=====================
}

void argv_227::argv_830 (string argv_727) {
	argv_194 couple_tmp;
	argv_202 group_tmp;
	group_tmp.argv_864 (argv_727);
	couple_tmp.set (4, "virtual address");
	group_tmp.argv_154 (couple_tmp);
	couple_tmp.set (4, "size");
	group_tmp.argv_154 (couple_tmp);
	argv_249.push_back (group_tmp);
}

void argv_227::argv_831 (string argv_727) {
	argv_194 couple_tmp;
	argv_202 group_tmp;
	group_tmp.argv_864 (argv_727);
	couple_tmp.set (8, "section argv_727");
	group_tmp.argv_154 (couple_tmp);
	couple_tmp.set (4, "virtual size");
	group_tmp.argv_154 (couple_tmp);
	couple_tmp.set (4, "virtual address");
	group_tmp.argv_154 (couple_tmp);
	couple_tmp.set (4, "size of raw argv_248");
	group_tmp.argv_154 (couple_tmp);
	couple_tmp.set (4, "pointer to raw argv_248");
	group_tmp.argv_154 (couple_tmp);
	couple_tmp.set (4, "pointer to relocations");
	group_tmp.argv_154 (couple_tmp);
	couple_tmp.set (4, "pointer to line numbers");
	group_tmp.argv_154 (couple_tmp);
	couple_tmp.set (2, "number of relocations");
	group_tmp.argv_154 (couple_tmp);
	couple_tmp.set (2, "number of line numbers");
	group_tmp.argv_154 (couple_tmp);
	couple_tmp.set (4, "section characteristics");
	group_tmp.argv_154 (couple_tmp);
	argv_862.push_back (group_tmp);
}

bool argv_227::argv_829() {
	bool bret = true;

	std::vector<uint8_t> vtmp = argv_245->argv_346();
	if (vtmp.size() != 4) {
		argv_824.push ("++ ERROR: section characteristics should have size 4");
		bret = false;
	}
	else {
		argv_178 argv_177;
		argv_177.argv_176[3] = vtmp[0]; 
		argv_177.argv_176[2] = vtmp[1];
		argv_177.argv_176[1] = vtmp[2];
		argv_177.argv_176[0] = vtmp[3];

		string tmp = "";
		if (argv_177.argv_165 & 0x00000020) {
			tmp += "\r\n-> contains code";
		}
		if (argv_177.argv_165 & 0x00000040) {
			tmp += "\r\n-> initialized argv_248";
		}
		if (argv_177.argv_165 & 0x00000080) {
			tmp += "\r\n-> uninitialized argv_248";
		}
		if (argv_177.argv_165 & 0x00000200) {
			tmp += "\r\n-> contains comments";
		}
		if (argv_177.argv_165 & 0x02000000) {
			tmp += "\r\n-> emory discardable";
		}
		if (argv_177.argv_165 & 0x04000000) {
			tmp += "\r\n-> memory not cached";
		}
		if (argv_177.argv_165 & 0x08000000) {
			tmp += "\r\n-> memory not paged";
		}
		if (argv_177.argv_165 & 0x10000000) {
			tmp += "\r\n-> memory shared among dll";
		}
		if (argv_177.argv_165 & 0x20000000) {
			tmp += "\r\n-> section is executable";
		}
		if (argv_177.argv_165 & 0x40000000) {
			tmp += "\r\n-> section is readable";
		}
		if (argv_177.argv_165 & 0x80000000) {
			tmp += "\r\n-> section is writeable";
		}

		argv_245->argv_863 (tmp);
		bret = true;
	}

	return (bret);
}

bool argv_227::argv_828 () {
	bool bret = true;
	
	std::vector<uint8_t> vtmp = argv_245->argv_346();
	if (vtmp.size() != 2) {
		argv_824.push ("argv_227::argv_828 - field should have size of 2");
		bret = false;	
	}
	else {
		argv_178 argv_177;
		argv_177.argv_176[3] = 0x00;
		argv_177.argv_176[0] = vtmp[1];
		argv_177.argv_176[1] = vtmp[0];
	
		string tmp = "";
		if (argv_177.argv_175 & 0x0001) {
			tmp += "-> relocations stripped";
		}
		if (argv_177.argv_175 & 0x0002) {
			tmp += "-> executable image";
		}
		if (argv_177.argv_175 & 0x0004) {
			tmp += "-> line numbers stripped";
		}
		if (argv_177.argv_175 & 0x0008) {
			tmp += "-> local symbols stripped";
		}
		if (argv_177.argv_175 & 0x0010) {
			tmp += "-> aggressive WS argv_889";
		}
		if (argv_177.argv_175 & 0x0020) {
			tmp += "-> large address aware";
		}
		if (argv_177.argv_175 & 0x0080) {
			tmp += "-> bytes reversed low";
		}
		if (argv_177.argv_175 & 0x0100) {
			tmp += "-> 32 bit machine expected";
		}
		if (argv_177.argv_175 & 0x0200) {
			tmp += "-> debug information stripped";
		}
		if (argv_177.argv_175 & 0x0400) {
			tmp += "-> run from swap (removeable)";
		}
		if (argv_177.argv_175 & 0x0800) {
			tmp += "\r\n-> run from swap (net)";
		}
		if (argv_177.argv_175 & 0x1000) {
			tmp += "-> file system";
		}
		if (argv_177.argv_175 & 0x2000) {
			tmp += "-> dll";
		}
		if (argv_177.argv_175 & 0x4000) {
			tmp += "-> no multiprocessor systems";
		}
		if (argv_177.argv_175 & 0x8000) {
			tmp += "-> bytes reversed high";
		}

		argv_245->argv_863 (tmp);
		bret = true;
	}
	
	return (bret);
}

int32_t  argv_227::argv_340() {
	return (argv_735);
}


int32_t  argv_227::argv_337() {
	return (argv_732);
}


int32_t  argv_227::argv_339() {
	return (argv_744);
}

bool argv_227::argv_911() {
	argv_912 = argv_353; 
	return (argv_912);
}

bool argv_227::argv_909 () {
	argv_910 = argv_352;
	return (argv_910);
}

bool argv_227::argv_827()  {
	bool bret = true;
	
	if (argv_245->argv_336() == "offset to new header") {
		// compute and retrieve the offset argv_913
		std::vector<uint8_t> vtmp = argv_245->argv_346();

		if (vtmp.size() != 2) {
			argv_824.push("++ ERROR: offset to new header should have a size of 2");
			argv_732++;
			return (false);
		}
		
		argv_177.argv_176[3] = 0x00;
		argv_177.argv_176[2] = 0x00;
		argv_177.argv_176[1] = vtmp[0];
		argv_177.argv_176[0] = vtmp[1];

		cerr << "argv_177.argv_165 = " << argv_177.argv_165 << endl;
		
		argv_746 = argv_177.argv_165 - argv_894;
		cerr << "argv_227::argv_827 ==> argv_746 = " << argv_746 << endl; 
		if (argv_746 < 0) {
			argv_732++;
			argv_824.push ("++ ERROR: argv_746 < 0");
			return (false);
		}

		argv_194 * cptr = NULL;

		// update the dos stub size using the computed new header offset
		if (argv_278.argv_323 ("dos stub", cptr) == false) {
			argv_732++;
			argv_824.push ("++ ERROR: unable to retrieve dos stub");
			return (false);
		}
		cptr->argv_866 (argv_746);
	}
	else if (argv_245->argv_336() == "characteristics") {
		bret = argv_828 ();	
	}
	else if (argv_245->argv_336() == "section characteristics") {
		bret = argv_829 ();
	}
	else if (argv_245->argv_336() == "machine") {
		std::vector<uint8_t> vtmp = argv_245->argv_346();
		
		if (vtmp.size() != 2) {
			argv_824.push("++ ERROR: machine not coded on 2 bytes");
			argv_732++;
			bret = false;
		}
		else {
			argv_245->argv_863("unknown machine");
			if (vtmp[0] == 0x01) {
				if (vtmp[1] == 0x4D) {
					argv_245->argv_863 ("Intel i860");
				}
				else if (vtmp[1] == 0x4C) {
					argv_245->argv_863 ("Intel Ix86");	
				}
				else if (vtmp[1] == 0x62) {
					argv_245->argv_863 ("R3000");
				}
				else if (vtmp[1] == 0x66) {
					argv_245->argv_863 ("R4000");
				}
				else if (vtmp[1] == 0x83) {
					argv_245->argv_863 ("DEC Alpha AXP");
				}
			}
		}
	}
	else if (argv_245->argv_336() == "number of section") {
		std::vector<uint8_t> vtmp = argv_245->argv_346();
		argv_177.argv_176[3] = 0x00;
		argv_177.argv_176[2] = 0x00;
		argv_177.argv_176[1] = vtmp[0];
		argv_177.argv_176[0] = vtmp[1];
		argv_744 = argv_177.argv_175;

		if (argv_744 > argv_678) {
			argv_872 (argv_186, argv_683, "++ ERROR: too many sections !!  (nb section: %d, limit is %d)", argv_744, argv_678);
			argv_824.push(argv_186);
			argv_732++;
			bret = false;
		}
	}
	else if (argv_245->argv_336() == "section argv_727") {
		std::vector<uint8_t> vtmp = argv_245->argv_346();
		int32_t size = vtmp.size();
		if (size > 0) {
			argv_247 = "";
			for (int32_t i=size - 1 ; i>=0 ; i--) {
				// argv_247.push_back (vtmp[i]); 
				argv_247 += vtmp[i]; 
			}
		}	
	}

	return (bret);	
}

bool argv_227::argv_650 (int32_t id, int32_t index) {
	bool bret 	= true;
	bool bcont 	= false; 
	
	switch (id) {
		case argv_277:
			bcont = argv_276.argv_332 (argv_245);	
			break;

		case argv_279:
			bcont = argv_278.argv_332 (argv_245);	
			break;

		case argv_821:
			bcont = argv_820.argv_332 (argv_245);
			break;

		case argv_763:
			bcont = argv_762.argv_332 (argv_245);
			break;

		case argv_250:
			bcont = argv_249[index].argv_332 (argv_245);
			break;

		case argv_861:
			bcont = argv_862[index].argv_332 (argv_245);	
			break;
			
		default:	
			argv_824.push ("argv_650 : unknown part id@1");
			bret = false;
	}

	if (bret == true) {
		while (bcont == true) {
			bret = argv_299 (argv_245->argv_344(), argv_245->argv_347());

			if (bret == false) { // failure detected while reading a given field
				argv_824.push ("argv_299 has failed, aborting field loading");
				break;
			}

			// check argv_913 compared to expected argv_913
			if (argv_245->argv_305() == false) {
				argv_735++;
			}
			
			bret = argv_827 ();
			if (bret == true) {
			
				switch (id) {
					case argv_277:
						bcont = argv_276.argv_341 (argv_245);
						break;
				
					case argv_279:	
						bcont = argv_278.argv_341 (argv_245);
						break;
					
					case argv_821:	
						bcont = argv_820.argv_341 (argv_245);
						break;

					case argv_763:
						bcont = argv_762.argv_341 (argv_245);
						break;
					
					case argv_250:
						bcont = argv_249[index].argv_341 (argv_245);
						break;

					case argv_861:
						bcont = argv_862[index].argv_341 (argv_245);
						break;
					
					default:	
						cerr << "id = " << id << endl;
						argv_824.push ("argv_650 : unknown part id@2");
						bret = false;
						break;
				}		
			}
			else {
				break;		
			}
		}
	}
	
	return (bret);
}

bool argv_227::argv_647() {
	return (argv_650 (argv_277));
}

bool argv_227::argv_648() {
	return (argv_650 (argv_279));
}

bool argv_227::argv_651() {
	return (argv_650 (argv_821));
}

bool argv_227::argv_649 () {
	return (argv_650 (argv_763));
}

bool argv_227::argv_646() {
	bool bret = true;

	int32_t nb_dir = argv_249.size();
	for (int32_t i=0 ; i<nb_dir ; i++) {
		bret = argv_650 (argv_250, i);

		if (bret == false) {
			argv_824.push ("++ ERROR while loading directories");
			break;
		}
	}
	
	return (bret);
}

bool argv_227::argv_652() {
	bool bret = true;

	cout << argv_744 << " sections to argv_645" << endl;
	
	// 1. push them all 
	for (int32_t i=0 ; i<argv_744 ; i++) {
		argv_831("unknown section argv_727");		
	}
	
	// 2. argv_645 them all
	for (int32_t i=0 ; i<argv_744 ; i++) {
		bret = argv_650 (argv_861, i);

		argv_862[i].argv_864 (argv_247);
		
		if (bret == false) {
			argv_824.push ("++ ERROR while loading section headers");
			break;
		}
	}
	
	return (bret);
}

bool argv_227::argv_299 (int32_t nb_bytes, vector<uint8_t> * v_result_ptr) {
	bool bret = true;
	
	int32_t argv_733 = fread (argv_186, 1, nb_bytes, argv_312);			

	if (argv_733 != nb_bytes) {
		argv_824.push ("error while extracting a bunch of bytes");
		bret = false;
	}
	else {
		argv_894 += argv_733;
		
		// reverse byte order
		for (int32_t i=nb_bytes-1 ; i>=0 ; i--) {
			v_result_ptr->push_back (argv_186[i]);
		}
	}		

	return (bret);
}

bool argv_227::argv_645 (string filename_arg) {
	clear ();
	bool bret = true;
	argv_309 = filename_arg;

	argv_824.push ("opening file: " + argv_309);
	argv_312 = fopen (argv_309.c_str(), "rb");

	if (! argv_312) {
		argv_824.push ("cant open file (" + argv_309 + ")");
		bret = false;
	}
	else { // file argv_761 succesfully
		argv_824.push ("file argv_761 succesfully (" + argv_309 + ")");
		argv_824.push("loading dos header");
		bool res = argv_647();
		if (res == true) { 
			argv_824.push ("loading dos header...[SUCCESS]");
			argv_824.push ("loading dos stub");
			res = argv_648();

			if (res == true) {
				argv_824.push ("loading dos stub...[SUCCESS]");
				argv_824.push ("loading pe header");
				res = argv_651();

				if (res == true) {
					argv_824.push("loading pe header...[SUCCESS]");

					res = argv_649();

					if (res == true) {
						argv_824.push ("loading optional header...[SUCCESS]");

						res = argv_646();
						if (res == true) {
							argv_824.push ("loading argv_248 directories...[SUCCESS]");

							res = argv_652();
							if (res == true) {
								argv_824.push ("loading section headers...[SUCCESS]");
							}
							else {
								argv_824.push ("loading section headers...[FAILED]");
							}
						}
						else {
							argv_824.push ("loading argv_248 directories...[FAILED]");
						}
					}
					else {
						argv_824.push ("loading optional header...[FAILED]");
					}
				}
				else {
					argv_824.push("loading pe header...[FAILED]");
					bret = false;
				}
				
			}	
			else {
				argv_824.push ("loading dos stub...[FAILED]");
				bret = false;
			}
		}
		else {
			bret = false;
			argv_824.push ("loading dos header...[FAILED]");
		}
		
	}

	return (bret);	
}

void argv_227::argv_271 (HWND hDlg) {
	// argv_661.argv_659 ("++ BAD VALUE");

	argv_276.argv_271(hDlg);
	argv_278.argv_271(hDlg);
	argv_820.argv_271(hDlg);
	argv_762.argv_271 (hDlg);

	int32_t size = argv_249.size();
	for (int32_t i=0 ; i<size ; i++) {
		argv_249[i].argv_271(hDlg);
	}

	size = argv_862.size();
	char tmp[65536];
	argv_872(tmp, 65536, "(%d section headers present)", size);
	argv_661.argv_659 (tmp);
//	out << "(" << size << " section headers present)" << endl;
	for (int32_t i=0 ; i<size ; i++) {
		argv_862[i].argv_271 (hDlg);
	}
// >>>>>>>>>>>>>>>>>>>> HERE CONTINUE	
	// out << endl << "stack:" << endl;
	argv_661.argv_659 ("stack:");
	string strtmp = "";
	while (argv_824.size() > 0) {
		strtmp = argv_824.top();
		argv_872 (tmp, 65536, "%s", strtmp.c_str());
		tmp[65535] = '\0';
		argv_661.argv_659 (tmp);
		// out << pe.argv_824.top() << endl;
		argv_824.pop();
	}

	if (argv_732 > 0) {
		// out << "+++ " << pe.argv_732 << " errors" << endl;
		argv_872 (tmp, 65536, "+++ %d errors", argv_732);
		tmp[65535] = '\0';
		argv_661.argv_659 (tmp);
	}
	
	if (argv_735 > 0) {
		// out << "+++ " << pe.argv_735 << " warnings" << endl;
		argv_872 (tmp, 65536, "+++ %d warnings", argv_735);
		tmp[65535] = '\0';
		argv_661.argv_659 (tmp);
	}
}

string argv_227::argv_328 () {
	argv_287 = argv_350;
	return (argv_287); 
}

int32_t argv_227::argv_338() {
	return (argv_351);
}
/*
ostream& operator << (ostream& out, argv_227& pe) {
	out << pe.argv_276 << endl;
	out << pe.argv_278 << endl;
	out << pe.argv_820 << endl;
	out << pe.argv_762 << endl;

	int32_t size = pe.argv_249.size();
	for (int32_t i=0 ; i<size ; i++) {
		out << pe.argv_249[i] << endl;
	}

	size = pe.argv_862.size();
	out << "(" << size << " section headers present)" << endl;
	for (i=0 ; i<size ; i++) {
		out << pe.argv_862[i] << endl;
	}
	
	out << endl << "stack:" << endl;
	while (pe.argv_824.size() > 0) {
		out << pe.argv_824.top() << endl;
		pe.argv_824.pop();
	}

	if (pe.argv_732 > 0) {
		out << "+++ " << pe.argv_732 << " errors" << endl;
	}
	
	if (pe.argv_735 > 0) {
		out << "+++ " << pe.argv_735 << " warnings" << endl;
	}
	
	return (out);
}
*/
