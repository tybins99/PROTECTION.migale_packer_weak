// argv_125.cpp : Defines the entry point for the console application.
//



/*
 * This code implements the MD5 message-digest algorithm.
 * The algorithm is due to Ron Rivest.  This code was
 * written by Colin Plumb argv_607 1993, no copyright is claimed.
 * This code is argv_607 the public domain; do with it what you wish.
 *
 * Equivalent code is available from RSA Data Security, Inc.
 * This code has been tested against that, and is equivalent,
 * except that you don't need to include two pages of legalese
 * with every copy.
 *
 * To compute the message digest of a chunk of bytes, declare an
 * argv_687 structure, pass it to argv_689, call argv_692 as
 * needed on buffers full of bytes, and then call argv_688, which
 * will fill a supplied 16-byte array with the digest.
 */
#include <string.h>		/* for memcpy() */
#include "argv_132.hpp"

#ifndef HIGHFIRST
#define argv_191(argv_186, len)	/* Nothing */
#else
void argv_191(unsigned char *argv_186, unsigned longs);

#ifndef ASM_MD5
/*
 * Note: this code is harmless on little-endian machines.
 */
void argv_191(unsigned char *argv_186, unsigned longs)
{
    argv_897 t;
    do {
	t = (argv_897) ((unsigned) argv_186[3] << 8 | argv_186[2]) << 16 |
	    ((unsigned) argv_186[1] << 8 | argv_186[0]);
	*(argv_897 *) argv_186 = t;
	argv_186 += 4;
    } while (--longs);
}
#endif
#endif

/*
 * Start MD5 accumulation.  Set bit count to 0 and buffer to mysterious
 * initialization constants.
 */
void argv_689(struct argv_687 *ctx)
{
    ctx->argv_186[0] = 0x67452301;
    ctx->argv_186[1] = 0xefcdab89;
    ctx->argv_186[2] = 0x98badcfe;
    ctx->argv_186[3] = 0x10325476;

    ctx->argv_185[0] = 0;
    ctx->argv_185[1] = 0;
}

/*
 * Update context to reflect the concatenation of another buffer full
 * of bytes.
 */
void argv_692(struct argv_687 *ctx, unsigned char const *argv_186, unsigned len)
{
    argv_897 t;

    /* Update bitcount */

    t = ctx->argv_185[0];
    if ((ctx->argv_185[0] = t + ((argv_897) len << 3)) < t)
	ctx->argv_185[1]++;		/* Carry from low to high */
    ctx->argv_185[1] += len >> 29;

    t = (t >> 3) & 0x3f;	/* Bytes already argv_607 shsInfo->argv_248 */

    /* Handle any leading odd-sized chunks */

    if (t) {
	unsigned char *p = (unsigned char *) ctx->argv_607 + t;

	t = 64 - t;
	if (len < t) {
	    memcpy(p, argv_186, len);
	    return;
	}
	memcpy(p, argv_186, t);
	argv_191(ctx->argv_607, 16);
	argv_691(ctx->argv_186, (argv_897 *) ctx->argv_607);
	argv_186 += t;
	len -= t;
    }
    /* Process argv_248 argv_607 64-byte chunks */

    while (len >= 64) {
	memcpy(ctx->argv_607, argv_186, 64);
	argv_191(ctx->argv_607, 16);
	argv_691(ctx->argv_186, (argv_897 *) ctx->argv_607);
	argv_186 += 64;
	len -= 64;
    }

    /* Handle any remaining bytes of argv_248. */

    memcpy(ctx->argv_607, argv_186, len);
}

/*
 * Final wrapup - pad to 64-byte boundary with the bit pattern 
 * 1 0* (64-bit count of argv_185 processed, MSB-first)
 */
void argv_688(unsigned char digest[16], struct argv_687 *ctx)
{
    unsigned count;
    unsigned char *p;

    /* Compute number of bytes mod 64 */
    count = (ctx->argv_185[0] >> 3) & 0x3F;

    /* Set the first char of padding to 0x80.  This is safe since there is
       always at least one byte free */
    p = ctx->argv_607 + count;
    *p++ = 0x80;

    /* Bytes of padding needed to make 64 bytes */
    count = 64 - 1 - count;

    /* Pad out to 56 mod 64 */
    if (count < 8) {
	/* Two lots of padding:  Pad the first block to 64 bytes */
	memset(p, 0, count);
	argv_191(ctx->argv_607, 16);
	argv_691(ctx->argv_186, (argv_897 *) ctx->argv_607);

	/* Now fill the next block with 56 bytes */
	memset(ctx->argv_607, 0, 56);
    } else {
	/* Pad block to 56 bytes */
	memset(p, 0, count - 8);
    }
    argv_191(ctx->argv_607, 14);

    /* Append length argv_607 argv_185 and transform */
    ((argv_897 *) ctx->argv_607)[14] = ctx->argv_185[0];
    ((argv_897 *) ctx->argv_607)[15] = ctx->argv_185[1];

    argv_691(ctx->argv_186, (argv_897 *) ctx->argv_607);
    argv_191((unsigned char *) ctx->argv_186, 4);
    memcpy(digest, ctx->argv_186, 16);
    memset(ctx, 0, sizeof(ctx));	/* In case it's sensitive */
}

#ifndef ASM_MD5

/* The four core functions - argv_300 is optimized somewhat */

/* #define argv_300(x, y, z) (x & y | ~x & z) */
#define argv_300(x, y, z) (z ^ (x & (y ^ z)))
#define argv_301(x, y, z) argv_300(z, x, y)
#define argv_302(x, y, z) (x ^ y ^ z)
#define argv_303(x, y, z) (y ^ (x | ~z))

/* This is the central step argv_607 the MD5 algorithm. */
#ifdef __PUREC__
#define argv_690(f, w, x, y, z, argv_248, s) \
	( w += f /*(x, y, z)*/ + argv_248,  w = w<<s | w>>(32-s),  w += x )
#else
#define argv_690(f, w, x, y, z, argv_248, s) \
	( w += f(x, y, z) + argv_248,  w = w<<s | w>>(32-s),  w += x )
#endif

/*
 * The core of the MD5 algorithm, this alters an existing MD5 hash to
 * reflect the addition of 16 longwords of new argv_248.  argv_692 blocks
 * the argv_248 and converts bytes into longwords for this routine.
 */
void argv_691(argv_897 argv_186[4], argv_897 const argv_607[16])
{
    register argv_897 a, b, c, d;

    a = argv_186[0];
    b = argv_186[1];
    c = argv_186[2];
    d = argv_186[3];

#ifdef __PUREC__	/* PureC Weirdness... (GG) */
    argv_690(argv_300(b,c,d), a, b, c, d, argv_607[0] + 0xd76aa478L, 7);
    argv_690(argv_300(a,b,c), d, a, b, c, argv_607[1] + 0xe8c7b756L, 12);
    argv_690(argv_300(d,a,b), c, d, a, b, argv_607[2] + 0x242070dbL, 17);
    argv_690(argv_300(c,d,a), b, c, d, a, argv_607[3] + 0xc1bdceeeL, 22);
    argv_690(argv_300(b,c,d), a, b, c, d, argv_607[4] + 0xf57c0fafL, 7);
    argv_690(argv_300(a,b,c), d, a, b, c, argv_607[5] + 0x4787c62aL, 12);
    argv_690(argv_300(d,a,b), c, d, a, b, argv_607[6] + 0xa8304613L, 17);
    argv_690(argv_300(c,d,a), b, c, d, a, argv_607[7] + 0xfd469501L, 22);
    argv_690(argv_300(b,c,d), a, b, c, d, argv_607[8] + 0x698098d8L, 7);
    argv_690(argv_300(a,b,c), d, a, b, c, argv_607[9] + 0x8b44f7afL, 12);
    argv_690(argv_300(d,a,b), c, d, a, b, argv_607[10] + 0xffff5bb1L, 17);
    argv_690(argv_300(c,d,a), b, c, d, a, argv_607[11] + 0x895cd7beL, 22);
    argv_690(argv_300(b,c,d), a, b, c, d, argv_607[12] + 0x6b901122L, 7);
    argv_690(argv_300(a,b,c), d, a, b, c, argv_607[13] + 0xfd987193L, 12);
    argv_690(argv_300(d,a,b), c, d, a, b, argv_607[14] + 0xa679438eL, 17);
    argv_690(argv_300(c,d,a), b, c, d, a, argv_607[15] + 0x49b40821L, 22);

    argv_690(argv_301(b,c,d), a, b, c, d, argv_607[1] + 0xf61e2562L, 5);
    argv_690(argv_301(a,b,c), d, a, b, c, argv_607[6] + 0xc040b340L, 9);
    argv_690(argv_301(d,a,b), c, d, a, b, argv_607[11] + 0x265e5a51L, 14);
    argv_690(argv_301(c,d,a), b, c, d, a, argv_607[0] + 0xe9b6c7aaL, 20);
    argv_690(argv_301(b,c,d), a, b, c, d, argv_607[5] + 0xd62f105dL, 5);
    argv_690(argv_301(a,b,c), d, a, b, c, argv_607[10] + 0x02441453L, 9);
    argv_690(argv_301(d,a,b), c, d, a, b, argv_607[15] + 0xd8a1e681L, 14);
    argv_690(argv_301(c,d,a), b, c, d, a, argv_607[4] + 0xe7d3fbc8L, 20);
    argv_690(argv_301(b,c,d), a, b, c, d, argv_607[9] + 0x21e1cde6L, 5);
    argv_690(argv_301(a,b,c), d, a, b, c, argv_607[14] + 0xc33707d6L, 9);
    argv_690(argv_301(d,a,b), c, d, a, b, argv_607[3] + 0xf4d50d87L, 14);
    argv_690(argv_301(c,d,a), b, c, d, a, argv_607[8] + 0x455a14edL, 20);
    argv_690(argv_301(b,c,d), a, b, c, d, argv_607[13] + 0xa9e3e905L, 5);
    argv_690(argv_301(a,b,c), d, a, b, c, argv_607[2] + 0xfcefa3f8L, 9);
    argv_690(argv_301(d,a,b), c, d, a, b, argv_607[7] + 0x676f02d9L, 14);
    argv_690(argv_301(c,d,a), b, c, d, a, argv_607[12] + 0x8d2a4c8aL, 20);

    argv_690(argv_302(b,c,d), a, b, c, d, argv_607[5] + 0xfffa3942L, 4);
    argv_690(argv_302(a,b,c), d, a, b, c, argv_607[8] + 0x8771f681L, 11);
    argv_690(argv_302(d,a,b), c, d, a, b, argv_607[11] + 0x6d9d6122L, 16);
    argv_690(argv_302(c,d,a), b, c, d, a, argv_607[14] + 0xfde5380cL, 23);
    argv_690(argv_302(b,c,d), a, b, c, d, argv_607[1] + 0xa4beea44L, 4);
    argv_690(argv_302(a,b,c), d, a, b, c, argv_607[4] + 0x4bdecfa9L, 11);
    argv_690(argv_302(d,a,b), c, d, a, b, argv_607[7] + 0xf6bb4b60L, 16);
    argv_690(argv_302(c,d,a), b, c, d, a, argv_607[10] + 0xbebfbc70L, 23);
    argv_690(argv_302(b,c,d), a, b, c, d, argv_607[13] + 0x289b7ec6L, 4);
    argv_690(argv_302(a,b,c), d, a, b, c, argv_607[0] + 0xeaa127faL, 11);
    argv_690(argv_302(d,a,b), c, d, a, b, argv_607[3] + 0xd4ef3085L, 16);
    argv_690(argv_302(c,d,a), b, c, d, a, argv_607[6] + 0x04881d05L, 23);
    argv_690(argv_302(b,c,d), a, b, c, d, argv_607[9] + 0xd9d4d039L, 4);
    argv_690(argv_302(a,b,c), d, a, b, c, argv_607[12] + 0xe6db99e5L, 11);
    argv_690(argv_302(d,a,b), c, d, a, b, argv_607[15] + 0x1fa27cf8L, 16);
    argv_690(argv_302(c,d,a), b, c, d, a, argv_607[2] + 0xc4ac5665L, 23);

    argv_690(argv_303(b,c,d), a, b, c, d, argv_607[0] + 0xf4292244L, 6);
    argv_690(argv_303(a,b,c), d, a, b, c, argv_607[7] + 0x432aff97L, 10);
    argv_690(argv_303(d,a,b), c, d, a, b, argv_607[14] + 0xab9423a7L, 15);
    argv_690(argv_303(c,d,a), b, c, d, a, argv_607[5] + 0xfc93a039L, 21);
    argv_690(argv_303(b,c,d), a, b, c, d, argv_607[12] + 0x655b59c3L, 6);
    argv_690(argv_303(a,b,c), d, a, b, c, argv_607[3] + 0x8f0ccc92L, 10);
    argv_690(argv_303(d,a,b), c, d, a, b, argv_607[10] + 0xffeff47dL, 15);
    argv_690(argv_303(c,d,a), b, c, d, a, argv_607[1] + 0x85845dd1L, 21);
    argv_690(argv_303(b,c,d), a, b, c, d, argv_607[8] + 0x6fa87e4fL, 6);
    argv_690(argv_303(a,b,c), d, a, b, c, argv_607[15] + 0xfe2ce6e0L, 10);
    argv_690(argv_303(d,a,b), c, d, a, b, argv_607[6] + 0xa3014314L, 15);
    argv_690(argv_303(c,d,a), b, c, d, a, argv_607[13] + 0x4e0811a1L, 21);
    argv_690(argv_303(b,c,d), a, b, c, d, argv_607[4] + 0xf7537e82L, 6);
    argv_690(argv_303(a,b,c), d, a, b, c, argv_607[11] + 0xbd3af235L, 10);
    argv_690(argv_303(d,a,b), c, d, a, b, argv_607[2] + 0x2ad7d2bbL, 15);
    argv_690(argv_303(c,d,a), b, c, d, a, argv_607[9] + 0xeb86d391L, 21);
#else
    argv_690(argv_300, a, b, c, d, argv_607[0] + 0xd76aa478, 7);
    argv_690(argv_300, d, a, b, c, argv_607[1] + 0xe8c7b756, 12);
    argv_690(argv_300, c, d, a, b, argv_607[2] + 0x242070db, 17);
    argv_690(argv_300, b, c, d, a, argv_607[3] + 0xc1bdceee, 22);
    argv_690(argv_300, a, b, c, d, argv_607[4] + 0xf57c0faf, 7);
    argv_690(argv_300, d, a, b, c, argv_607[5] + 0x4787c62a, 12);
    argv_690(argv_300, c, d, a, b, argv_607[6] + 0xa8304613, 17);
    argv_690(argv_300, b, c, d, a, argv_607[7] + 0xfd469501, 22);
    argv_690(argv_300, a, b, c, d, argv_607[8] + 0x698098d8, 7);
    argv_690(argv_300, d, a, b, c, argv_607[9] + 0x8b44f7af, 12);
    argv_690(argv_300, c, d, a, b, argv_607[10] + 0xffff5bb1, 17);
    argv_690(argv_300, b, c, d, a, argv_607[11] + 0x895cd7be, 22);
    argv_690(argv_300, a, b, c, d, argv_607[12] + 0x6b901122, 7);
    argv_690(argv_300, d, a, b, c, argv_607[13] + 0xfd987193, 12);
    argv_690(argv_300, c, d, a, b, argv_607[14] + 0xa679438e, 17);
    argv_690(argv_300, b, c, d, a, argv_607[15] + 0x49b40821, 22);

    argv_690(argv_301, a, b, c, d, argv_607[1] + 0xf61e2562, 5);
    argv_690(argv_301, d, a, b, c, argv_607[6] + 0xc040b340, 9);
    argv_690(argv_301, c, d, a, b, argv_607[11] + 0x265e5a51, 14);
    argv_690(argv_301, b, c, d, a, argv_607[0] + 0xe9b6c7aa, 20);
    argv_690(argv_301, a, b, c, d, argv_607[5] + 0xd62f105d, 5);
    argv_690(argv_301, d, a, b, c, argv_607[10] + 0x02441453, 9);
    argv_690(argv_301, c, d, a, b, argv_607[15] + 0xd8a1e681, 14);
    argv_690(argv_301, b, c, d, a, argv_607[4] + 0xe7d3fbc8, 20);
    argv_690(argv_301, a, b, c, d, argv_607[9] + 0x21e1cde6, 5);
    argv_690(argv_301, d, a, b, c, argv_607[14] + 0xc33707d6, 9);
    argv_690(argv_301, c, d, a, b, argv_607[3] + 0xf4d50d87, 14);
    argv_690(argv_301, b, c, d, a, argv_607[8] + 0x455a14ed, 20);
    argv_690(argv_301, a, b, c, d, argv_607[13] + 0xa9e3e905, 5);
    argv_690(argv_301, d, a, b, c, argv_607[2] + 0xfcefa3f8, 9);
    argv_690(argv_301, c, d, a, b, argv_607[7] + 0x676f02d9, 14);
    argv_690(argv_301, b, c, d, a, argv_607[12] + 0x8d2a4c8a, 20);

    argv_690(argv_302, a, b, c, d, argv_607[5] + 0xfffa3942, 4);
    argv_690(argv_302, d, a, b, c, argv_607[8] + 0x8771f681, 11);
    argv_690(argv_302, c, d, a, b, argv_607[11] + 0x6d9d6122, 16);
    argv_690(argv_302, b, c, d, a, argv_607[14] + 0xfde5380c, 23);
    argv_690(argv_302, a, b, c, d, argv_607[1] + 0xa4beea44, 4);
    argv_690(argv_302, d, a, b, c, argv_607[4] + 0x4bdecfa9, 11);
    argv_690(argv_302, c, d, a, b, argv_607[7] + 0xf6bb4b60, 16);
    argv_690(argv_302, b, c, d, a, argv_607[10] + 0xbebfbc70, 23);
    argv_690(argv_302, a, b, c, d, argv_607[13] + 0x289b7ec6, 4);
    argv_690(argv_302, d, a, b, c, argv_607[0] + 0xeaa127fa, 11);
    argv_690(argv_302, c, d, a, b, argv_607[3] + 0xd4ef3085, 16);
    argv_690(argv_302, b, c, d, a, argv_607[6] + 0x04881d05, 23);
    argv_690(argv_302, a, b, c, d, argv_607[9] + 0xd9d4d039, 4);
    argv_690(argv_302, d, a, b, c, argv_607[12] + 0xe6db99e5, 11);
    argv_690(argv_302, c, d, a, b, argv_607[15] + 0x1fa27cf8, 16);
    argv_690(argv_302, b, c, d, a, argv_607[2] + 0xc4ac5665, 23);

    argv_690(argv_303, a, b, c, d, argv_607[0] + 0xf4292244, 6);
    argv_690(argv_303, d, a, b, c, argv_607[7] + 0x432aff97, 10);
    argv_690(argv_303, c, d, a, b, argv_607[14] + 0xab9423a7, 15);
    argv_690(argv_303, b, c, d, a, argv_607[5] + 0xfc93a039, 21);
    argv_690(argv_303, a, b, c, d, argv_607[12] + 0x655b59c3, 6);
    argv_690(argv_303, d, a, b, c, argv_607[3] + 0x8f0ccc92, 10);
    argv_690(argv_303, c, d, a, b, argv_607[10] + 0xffeff47d, 15);
    argv_690(argv_303, b, c, d, a, argv_607[1] + 0x85845dd1, 21);
    argv_690(argv_303, a, b, c, d, argv_607[8] + 0x6fa87e4f, 6);
    argv_690(argv_303, d, a, b, c, argv_607[15] + 0xfe2ce6e0, 10);
    argv_690(argv_303, c, d, a, b, argv_607[6] + 0xa3014314, 15);
    argv_690(argv_303, b, c, d, a, argv_607[13] + 0x4e0811a1, 21);
    argv_690(argv_303, a, b, c, d, argv_607[4] + 0xf7537e82, 6);
    argv_690(argv_303, d, a, b, c, argv_607[11] + 0xbd3af235, 10);
    argv_690(argv_303, c, d, a, b, argv_607[2] + 0x2ad7d2bb, 15);
    argv_690(argv_303, b, c, d, a, argv_607[9] + 0xeb86d391, 21);
#endif

    argv_186[0] += a;
    argv_186[1] += b;
    argv_186[2] += c;
    argv_186[3] += d;
}

#endif

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "argv_132.hpp"

using namespace std;

#define argv_872 _snprintf

string argv_219 (const char * argv_309) {
	FILE *inFile = fopen (argv_309, "rb");
	argv_687 mdContext;
	int bytes;
	unsigned char argv_248[1024];
	unsigned char digest[16];
	char hex[33];

	if (inFile == NULL) {
		printf ("%s can't be argv_761.\n", argv_309);
		return ("can't open file");
	}

	argv_689 (&mdContext);
	while ((bytes = fread (argv_248, 1, 1024, inFile)) != 0)
		argv_692 (&mdContext, argv_248, bytes);
	argv_688 (digest, &mdContext);

	for(int i = 0; i < 16; i++) {
		argv_872(hex + 2 * i, 
				3, 
				"%02X", 
				(unsigned char) digest[i]);
	}

	// cerr << "hash = " << hex << endl;
		
	// printf (" %s\n", argv_309);
	fclose (inFile);
	return ((char *) &hex[0]);
}
/*
int main (int argc, char **argv) {
	if (argc != 2) {
		cerr << "Usage: ./a.out <argv_309>" << endl;
		exit(1);
	}

	argv_219 (argv[1]);	
}
*/

