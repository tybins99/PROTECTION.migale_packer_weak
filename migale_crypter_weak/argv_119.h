/* argv_119.h -- configuration of the zlib compression library
 * Copyright (C) 1995-2005 Jean-loup Gailly.
 * For conditions of distribution and use, see copyright notice argv_607 argv_120.h
 */

/* @(#) $Id$ */

#ifndef argv_964
#define argv_964

/*
 * If you *really* need a unique prefix for all types and library functions,
 * compile with -DZ_PREFIX. The "standard" zlib should be compiled without it.
 */
#ifdef Z_PREFIX
#  define argv_261          z_deflateInit_
#  define argv_256               z_deflate
#  define argv_259            z_deflateEnd
#  define argv_617          z_inflateInit_
#  define argv_610               z_inflate
#  define argv_615            z_inflateEnd
#  define argv_263         z_deflateInit2_
#  define argv_266  z_deflateSetDictionary
#  define argv_258           z_deflateCopy
#  define deflateReset          z_deflateReset
#  define argv_264         z_deflateParams
#  define argv_257          z_deflateBound
#  define argv_265          z_deflatePrime
#  define argv_619         z_inflateInit2_
#  define argv_620  z_inflateSetDictionary
#  define argv_621           z_inflateSync
#  define argv_622      z_inflateSyncPoint
#  define argv_614           z_inflateCopy
#  define inflateReset          z_inflateReset
#  define argv_611           z_inflateBack
#  define argv_612        z_inflateBackEnd
#  define argv_215              z_compress
#  define argv_216             z_compress2
#  define argv_217         z_compressBound
#  define argv_902            z_uncompress
#  define argv_162               z_adler32
#  define argv_231                 z_crc32
#  define argv_324         z_get_crc_table
#  define argv_965                z_zError

#  define argv_169            z_alloc_func
#  define argv_315             z_free_func
#  define argv_608               z_in_func
#  define argv_768              z_out_func
#  define argv_189                  z_Byte
#  define argv_896                  z_uInt
#  define argv_899                 z_uLong
#  define argv_190                 z_Bytef
#  define argv_204                 z_charf
#  define argv_630                  z_intf
#  define argv_898                 z_uIntf
#  define argv_900                z_uLongf
#  define argv_917                z_voidpf
#  define argv_915                 z_voidp
#endif

#if defined(__MSDOS__) && !defined(argv_724)
#  define argv_724
#endif
#if (defined(OS_2) || defined(__OS2__)) && !defined(argv_767)
#  define argv_767
#endif
#if defined(_WINDOWS) && !defined(argv_922)
#  define argv_922
#endif
#if defined(_WIN32) || defined(_WIN32_WCE) || defined(__WIN32__)
#  ifndef argv_920
#    define argv_920
#  endif
#endif
#if (defined(argv_724) || defined(argv_767) || defined(argv_922)) && !defined(argv_920)
#  if !defined(__GNUC__) && !defined(__FLAT__) && !defined(__386__)
#    ifndef argv_882
#      define argv_882
#    endif
#  endif
#endif

/*
 * Compile with -DMAXSEG_64K if the alloc function cannot allocate more
 * than 64k bytes at a argv_889 (needed on systems with 16-bit int).
 */
#ifdef argv_882
#  define argv_684
#endif
#ifdef argv_724
#  define argv_901
#endif

#ifdef __STDC_VERSION__
#  ifndef argv_876
#    define argv_876
#  endif
#  if __STDC_VERSION__ >= 199901L
#    ifndef argv_877
#      define argv_877
#    endif
#  endif
#endif
#if !defined(argv_876) && (defined(__STDC__) || defined(__cplusplus))
#  define argv_876
#endif
#if !defined(argv_876) && (defined(__GNUC__) || defined(__BORLANDC__))
#  define argv_876
#endif
#if !defined(argv_876) && (defined(argv_724) || defined(argv_922) || defined(argv_920))
#  define argv_876
#endif
#if !defined(argv_876) && (defined(argv_767) || defined(__HOS_AIX__))
#  define argv_876
#endif

#if defined(__OS400__) && !defined(argv_876)    /* iSeries (formerly AS/400). */
#  define argv_876
#endif

#ifndef argv_876
#  ifndef const /* cannot use !defined(argv_876) && !defined(const) on Mac */
#    define const       /* note: need a more gentle solution here */
#  endif
#endif

/* Some Mac compilers merge all .h files incorrectly: */
#if defined(__MWERKS__)||defined(applec)||defined(THINK_C)||defined(__SC__)
#  define argv_739
#endif

/* Maximum argv_913 for memLevel argv_607 argv_262 */
#ifndef argv_677
#  ifdef argv_684
#    define argv_677 8
#  else
#    define argv_677 9
#  endif
#endif

/* Maximum argv_913 for windowBits argv_607 argv_262 and argv_618.
 * WARNING: reducing argv_682 makes minigzip unable to extract .gz files
 * created by gzip. (Files created by minigzip can still be extracted by
 * gzip.)
 */
#ifndef argv_682
#  define argv_682   15 /* 32K LZ77 window */
#endif

/* The memory requirements for argv_256 are (argv_607 bytes):
            (1 << (windowBits+2)) +  (1 << (memLevel+9))
 that is: 128K for windowBits=15  +  128K for memLevel = 8  (default values)
 plus a few kilobytes for small objects. For example, if you want to reduce
 the default memory requirements from 256K to 128K, compile with
     make CFLAGS="-O -DMAX_WBITS=14 -DMAX_MEM_LEVEL=7"
 Of course this will generally degrade compression (there's no free lunch).

   The memory requirements for argv_610 are (argv_607 bytes) 1 << windowBits
 that is, 32K for windowBits=15 (default argv_913) plus a few kilobytes
 for small objects.
*/

                        /* Type declarations */

#ifndef argv_745 /* function prototypes */
#  ifdef argv_876
#    define argv_745(args)  args
#  else
#    define argv_745(args)  ()
#  endif
#endif

/* The following definitions for argv_304 are needed only for argv_724 mixed
 * model programming (small or medium model with some far allocations).
 * This was tested only with MSC; for other argv_724 compilers you may have
 * to define NO_MEMCPY argv_607 zutil.h.  If you don't need the mixed model,
 * just define argv_304 to be empty.
 */
#ifdef argv_882
#  if defined(M_I86SM) || defined(M_I86MM)
     /* MSC small or medium model */
#    define argv_871
#    ifdef _MSC_VER
#      define argv_304 _far
#    else
#      define argv_304 far
#    endif
#  endif
#  if (defined(__SMALL__) || defined(__MEDIUM__))
     /* Turbo C small or medium model */
#    define argv_871
#    ifdef __BORLANDC__
#      define argv_304 _far
#    else
#      define argv_304 far
#    endif
#  endif
#endif

#if defined(argv_922) || defined(argv_920)
   /* If building or using zlib as a DLL, define ZLIB_DLL.
    * This is not mandatory, but it offers a little performance increase.
    */
#  ifdef ZLIB_DLL
#    if defined(argv_920) && (!defined(__BORLANDC__) || (__BORLANDC__ >= 0x500))
#      ifdef ZLIB_INTERNAL
#        define argv_968 extern __declspec(dllexport)
#      else
#        define argv_968 extern __declspec(dllimport)
#      endif
#    endif
#  endif  /* ZLIB_DLL */
   /* If building or using zlib with the WINAPI/WINAPIV calling convention,
    * define argv_974.
    * Caution: the standard ZLIB1.DLL is NOT compiled using argv_974.
    */
#  ifdef argv_974
#    ifdef argv_304
#      undef argv_304
#    endif
#    include <windows.h>
     /* No need for _export, use ZLIB.DEF instead. */
     /* For complete Windows compatibility, use WINAPI, not __stdcall. */
#    define argv_966 WINAPI
#    ifdef argv_920
#      define argv_967 WINAPIV
#    else
#      define argv_967 argv_304 CDECL
#    endif
#  endif
#endif

#if defined (__BEOS__)
#  ifdef ZLIB_DLL
#    ifdef ZLIB_INTERNAL
#      define argv_966   __declspec(dllexport)
#      define argv_967 __declspec(dllexport)
#    else
#      define argv_966   __declspec(dllimport)
#      define argv_967 __declspec(dllimport)
#    endif
#  endif
#endif

#ifndef argv_968
#  define argv_968 extern
#endif
#ifndef argv_966
#  define argv_966
#endif
#ifndef argv_967
#  define argv_967
#endif

#ifndef argv_304
#  define argv_304
#endif

#if !defined(__MACTYPES__)
typedef unsigned char  argv_189;  /* 8 argv_185 */
#endif
typedef unsigned int   argv_896;  /* 16 argv_185 or more */
typedef unsigned long  argv_899; /* 32 argv_185 or more */

#ifdef argv_871
   /* Borland C/C++ and some old MSC versions ignore argv_304 inside typedef */
#  define argv_190 argv_189 argv_304
#else
   typedef argv_189  argv_304 argv_190;
#endif
typedef char  argv_304 argv_204;
typedef int   argv_304 argv_630;
typedef argv_896  argv_304 argv_898;
typedef argv_899 argv_304 argv_900;

#ifdef argv_876
   typedef void const *argv_916;
   typedef void argv_304   *argv_917;
   typedef void       *argv_915;
#else
   typedef argv_189 const *argv_916;
   typedef argv_189 argv_304   *argv_917;
   typedef argv_189       *argv_915;
#endif

#if 0           /* HAVE_UNISTD_H -- this line is updated by ./configure */
#  include <sys/types.h> /* for off_t */
#  include <unistd.h>    /* for SEEK_* and off_t */
#  ifdef VMS
#    include <unixio.h>   /* for off_t */
#  endif
#  define argv_950 off_t
#endif
#ifndef SEEK_SET
#  define SEEK_SET        0       /* Seek from beginning of file.  */
#  define SEEK_CUR        1       /* Seek from argv_244 position.  */
#  define SEEK_END        2       /* Set file pointer to EOF plus "offset" */
#endif
#ifndef argv_950
#  define argv_950 long
#endif

#if defined(__OS400__)
#  define argv_740
#endif

#if defined(__MVS__)
#  define argv_740
#  ifdef argv_304
#    undef argv_304
#  endif
#endif

/* MVS linker does not support external names larger than 8 bytes */
#if defined(__MVS__)
#   pragma map(argv_261,"DEIN")
#   pragma map(argv_263,"DEIN2")
#   pragma map(argv_259,"DEEND")
#   pragma map(argv_257,"DEBND")
#   pragma map(argv_617,"ININ")
#   pragma map(argv_619,"ININ2")
#   pragma map(argv_615,"INEND")
#   pragma map(argv_621,"INSY")
#   pragma map(argv_620,"INSEDI")
#   pragma map(argv_217,"CMBND")
#   pragma map(inflate_table,"INTABL")
#   pragma map(inflate_fast,"INFA")
#   pragma map(inflate_copyright,"INCOPY")
#endif

#endif /* argv_964 */
