#ifndef argv_686
#define argv_686

#ifdef __alpha
typedef unsigned int argv_897;
#else
typedef unsigned long argv_897;
#endif

struct argv_687 {
	argv_897 argv_186[4];
	argv_897 argv_185[2];
	unsigned char argv_607[64];
};

void argv_689(struct argv_687 *context);
void argv_692(struct argv_687 *context, unsigned char const *argv_186,
	       unsigned len);
void argv_688(unsigned char digest[16], struct argv_687 *context);
void argv_691(argv_897 argv_186[4], argv_897 const argv_607[16]);

/*
 * This is needed to make RSAREF happy on some MS-DOS compilers.
 */
typedef struct argv_687 argv_685;

#endif /* !argv_686 */

