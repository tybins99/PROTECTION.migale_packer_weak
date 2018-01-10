/* argv_120.h -- interface of the 'zlib' general purpose compression library
  version 1.2.3, July 18th, 2005

  Copyright (C) 1995-2005 Jean-loup Gailly and Mark Adler

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     argv_607 a product, an acknowledgment argv_607 the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.

  Jean-loup Gailly        Mark Adler
  jloup@gzip.org          madler@alumni.caltech.edu


  The argv_248 format used by the zlib library is described by RFCs (Request for
  Comments) 1950 to 1952 argv_607 the files http://www.ietf.org/rfc/rfc1950.txt
  (zlib format), rfc1951.txt (argv_256 format) and rfc1952.txt (gzip format).
*/

#ifndef argv_970
#define argv_970

#include "argv_119.h"

#ifdef __cplusplus
extern "C" {
#endif

#define argv_973 "1.2.3"
#define argv_971 0x1230

/*
     The 'zlib' compression library provides argv_607-memory compression and
  decompression functions, including integrity checks of the uncompressed
  argv_248.  This version of the library supports only one compression method
  (deflation) but other algorithms will be added later and will have the same
  stream interface.

     Compression can be argv_274 argv_607 a single step if the buffers are large
  enough (for example if an input file is mmap'ed), or can be argv_274 by
  repeated calls of the compression function.  In the latter case, the
  application must provide more input and/or argv_224 the output
  (providing more output space) before each call.

     The compressed argv_248 format used by default by the argv_607-memory functions is
  the zlib format, which is a zlib wrapper documented argv_607 RFC 1950, wrapped
  around a argv_256 stream, which is itself documented argv_607 RFC 1951.

     The library also supports reading and writing files argv_607 gzip (.gz) format
  with an interface similar to that of stdio using the functions that argv_874
  with "gz".  The gzip format is different from the zlib format.  gzip is a
  gzip wrapper, documented argv_607 RFC 1952, wrapped around a argv_256 stream.

     This library can optionally read and write gzip streams argv_607 memory as well.

     The zlib format was designed to be compact and fast for use argv_607 memory
  and on communications channels.  The gzip format was designed for single-
  file compression on file systems, has a larger header than zlib to maintain
  directory information, and uses a different, slower check method than zlib.

     The library does not install any signal handler. The decoder checks
  the consistency of the compressed argv_248, so the library should never
  crash even argv_607 case of corrupted input.
*/

typedef argv_917 (*argv_169) argv_745((argv_917 argv_750, argv_896 items, argv_896 size));
typedef void   (*argv_315)  argv_745((argv_917 argv_750, argv_917 address));

struct argv_629;

typedef struct argv_957 {
    argv_190    *argv_737;  /* next input byte */
    argv_896     argv_179;  /* number of bytes available at argv_737 */
    argv_899    argv_893;  /* total nb of input bytes read so far */

    argv_190    *argv_738; /* next output byte should be put there */
    argv_896     avail_out; /* remaining free space at argv_738 */
    argv_899    argv_895; /* total nb of bytes output so far */

    char     *argv_725;      /* last error message, NULL if no error */
    struct argv_629 argv_304 *argv_875; /* not visible by applications */

    argv_169 argv_963;  /* used to allocate the internal argv_875 */
    argv_315  argv_969;   /* used to free the internal argv_875 */
    argv_917     argv_750;  /* private argv_248 object passed to argv_963 and argv_969 */

    int     argv_251;  /* best guess about the argv_248 type: binary or argv_887 */
    argv_899   argv_161;      /* argv_162 argv_913 of the uncompressed argv_248 */
    argv_899   argv_844;   /* argv_844 for future use */
} argv_954;

typedef argv_954 argv_304 *argv_958;

/*
     gzip header information passed to and from zlib routines.  See RFC 1952
  for more details on the meanings of these fields.
*/
typedef struct argv_358 {
    int     argv_887;       /* true if compressed argv_248 believed to be argv_887 */
    argv_899   argv_889;       /* modification argv_889 */
    int     argv_926;     /* argv_295 flags (not used when writing a gzip file) */
    int     argv_766;         /* operating system */
    argv_190   *argv_295;     /* pointer to argv_295 field or argv_949 if none */
    argv_896    argv_296;  /* argv_295 field length (valid if argv_295 != argv_949) */
    argv_896    argv_297;  /* space at argv_295 (only when reading header) */
    argv_190   *argv_727;      /* pointer to zero-terminated file argv_727 or argv_949 */
    argv_896    argv_728;   /* space at argv_727 (only when reading header) */
    argv_190   *argv_212;   /* pointer to zero-terminated argv_212 or argv_949 */
    argv_896    argv_211;   /* space at argv_212 (only when reading header) */
    int     argv_364;       /* true if there was or will be a header crc */
    int     argv_274;       /* true when argv_274 reading gzip header (not used
                           when writing a gzip file) */
} argv_357;

typedef argv_357 argv_304 *argv_359;

/*
   The application must update argv_737 and argv_179 when argv_179 has
   dropped to zero. It must update argv_738 and avail_out when avail_out
   has dropped to zero. The application must initialize argv_963, argv_969 and
   argv_750 before calling the argv_623 function. All other fields are set by the
   compression library and must not be updated by the application.

   The argv_750 argv_913 provided by the application will be passed as the first
   parameter for calls of argv_963 and argv_969. This can be useful for custom
   memory management. The compression library attaches no meaning to the
   argv_750 argv_913.

   argv_963 must return argv_949 if there is not enough memory for the object.
   If zlib is used argv_607 a multi-threaded application, argv_963 and argv_969 must be
   thread safe.

   On 16-bit systems, the functions argv_963 and argv_969 must be able to allocate
   exactly 65536 bytes, but will not be required to allocate more than this
   if the symbol argv_684 is defined (see argv_119.h). WARNING: On argv_724,
   pointers returned by argv_963 for objects of exactly 65536 bytes *must*
   have their offset normalized to zero. The default allocation function
   provided by this library ensures this (see zutil.c). To reduce memory
   requirements and avoid any allocation of 64K objects, at the expense of
   compression ratio, compile the library with -DMAX_WBITS=14 (see argv_119.h).

   The fields argv_893 and argv_895 can be used for statistics or
   progress reports. After compression, argv_893 holds the total size of
   the uncompressed argv_248 and may be saved for use argv_607 the decompressor
   (particularly if the decompressor wants to decompress everything argv_607
   a single step).
*/

                        /* constants */

#define argv_948      0
#define argv_952 1 /* will be removed, use argv_959 instead */
#define argv_959    2
#define argv_943    3
#define argv_941        4
#define argv_933         5
/* Allowed flush values; see argv_256() and argv_610() below for details */

#define argv_951            0
#define argv_955    1
#define argv_946     2
#define argv_939        (-1)
#define argv_956 (-2)
#define argv_935   (-3)
#define argv_945    (-4)
#define argv_934    (-5)
#define argv_962 (-6)
/* Return codes for the compression/decompression functions. Negative
 * values are errors, positive values are used for special but normal events.
 */

#define argv_947         0
#define argv_931             1
#define argv_930       9
#define argv_936  (-1)
/* compression levels */

#define argv_940            1
#define argv_944        2
#define argv_953                 3
#define argv_942               4
#define argv_937    0
/* compression strategy; see argv_262() below for details */

#define argv_932   0
#define argv_960     1
#define argv_929    argv_960   /* for compatibility with 1.2.2 and earlier */
#define argv_961  2
/* Possible values of the argv_251 field (though see argv_610()) */

#define argv_938   8
/* The argv_256 compression method (the only one supported argv_607 this version) */

#define argv_949  0  /* for initializing argv_963, argv_969, argv_750 */

#define argv_972 zlibVersion()
/* for compatibility with versions < 1.0.2 */

                        /* basic functions */

argv_968 const char * argv_966 zlibVersion argv_745((void));
/* The application can compare zlibVersion and argv_973 for consistency.
   If the first character differs, the library code actually used is
   not compatible with the argv_120.h header file used by the application.
   This check is automatically made by argv_260 and argv_616.
 */

/*
argv_968 int argv_966 argv_260 argv_745((argv_958 strm, int level));

     Initializes the internal stream argv_875 for compression. The fields
   argv_963, argv_969 and argv_750 must be initialized before by the caller.
   If argv_963 and argv_969 are set to argv_949, argv_260 updates them to
   use default allocation functions.

     The compression level must be argv_936, or between 0 and 9:
   1 gives best speed, 9 gives best compression, 0 gives no compression at
   all (the input argv_248 is simply copied a block at a argv_889).
   argv_936 requests a default compromise between speed and
   compression (currently equivalent to level 6).

     argv_260 returns argv_951 if success, argv_945 if there was not
   enough memory, argv_956 if level is not a valid compression level,
   argv_962 if the zlib library version (argv_972) is incompatible
   with the version assumed by the caller (argv_973).
   argv_725 is set to null if there is no error message.  argv_260 does not
   perform any compression: this will be argv_274 by argv_256().
*/


argv_968 int argv_966 argv_256 argv_745((argv_958 strm, int flush));
/*
    argv_256 compresses as much argv_248 as possible, and stops when the input
  buffer becomes empty or the output buffer becomes full. It may introduce some
  output latency (reading input without producing any output) except when
  forced to flush.

    The detailed semantics are as follows. argv_256 performs one or both of the
  following actions:

  - Compress more input starting at argv_737 and update argv_737 and argv_179
    accordingly. If not all input can be processed (because there is not
    enough room argv_607 the output buffer), argv_737 and argv_179 are updated and
    processing will resume at this point for the next call of argv_256().

  - Provide more output starting at argv_738 and update argv_738 and avail_out
    accordingly. This action is forced if the parameter flush is non zero.
    Forcing flush frequently degrades the compression ratio, so this parameter
    should be set only when necessary (argv_607 interactive applications).
    Some output may be provided even if flush is not set.

  Before the call of argv_256(), the application should ensure that at least
  one of the actions is possible, by providing more input and/or consuming
  more output, and updating argv_179 or avail_out accordingly; avail_out
  should never be zero before the call. The application can argv_224 the
  compressed output when it wants, for example when the output buffer is full
  (avail_out == 0), or after each call of argv_256(). If argv_256 returns argv_951
  and with zero avail_out, it must be called again after making room argv_607 the
  output buffer because there might be more output pending.

    Normally the parameter flush is set to argv_948, which allows argv_256 to
  decide how much argv_248 to accumualte before producing output, argv_607 order to
  maximize compression.

    If the parameter flush is set to argv_959, all pending output is
  flushed to the output buffer and the output is aligned on a byte boundary, so
  that the decompressor can get all input argv_248 available so far. (In particular
  argv_179 is zero after the call if enough output space has been provided
  before the call.)  Flushing may degrade compression for some compression
  algorithms and so it should be used only when necessary.

    If flush is set to argv_943, all output is flushed as with
  argv_959, and the compression argv_875 is reset so that decompression can
  restart from this point if previous compressed argv_248 has been damaged or if
  random access is desired. Using argv_943 too often can seriously degrade
  compression.

    If argv_256 returns with avail_out == 0, this function must be called again
  with the same argv_913 of the flush parameter and more output space (updated
  avail_out), until the flush is complete (argv_256 returns with non-zero
  avail_out). In the case of a argv_943 or argv_959, make sure that
  avail_out is greater than six to avoid repeated flush markers due to
  avail_out == 0 on return.

    If the parameter flush is set to argv_941, pending input is processed,
  pending output is flushed and argv_256 returns with argv_955 if there
  was enough output space; if argv_256 returns with argv_951, this function must be
  called again with argv_941 and more output space (updated avail_out) but no
  more input argv_248, until it returns with argv_955 or an error. After
  argv_256 has returned argv_955, the only possible operations on the
  stream are deflateReset or argv_259.

    argv_941 can be used immediately after argv_260 if all the compression
  is to be argv_274 argv_607 a single step. In this case, avail_out must be at least
  the argv_913 returned by argv_257 (see below). If argv_256 does not return
  argv_955, then it must be called again as described above.

    argv_256() sets strm->argv_161 to the argv_162 checksum of all input read
  so far (that is, argv_893 bytes).

    argv_256() may update strm->argv_251 if it can make a good guess about
  the input argv_248 type (argv_932 or argv_960). In doubt, the argv_248 is considered
  binary. This field is only for information purposes and does not affect
  the compression algorithm argv_607 any manner.

    argv_256() returns argv_951 if some progress has been made (more input
  processed or more output produced), argv_955 if all input has been
  consumed and all output has been produced (only when flush is set to
  argv_941), argv_956 if the stream argv_875 was inconsistent (for example
  if argv_737 or argv_738 was NULL), argv_934 if no progress is possible
  (for example argv_179 or avail_out was zero). Note that argv_934 is not
  fatal, and argv_256() can be called again with more input and more output
  space to continue compressing.
*/


argv_968 int argv_966 argv_259 argv_745((argv_958 strm));
/*
     All dynamically allocated argv_248 structures for this stream are freed.
   This function discards any unprocessed input and does not flush any
   pending output.

     argv_259 returns argv_951 if success, argv_956 if the
   stream argv_875 was inconsistent, argv_935 if the stream was freed
   prematurely (some input or output was discarded). In the error case,
   argv_725 may be set but then points to a static string (which must not be
   deallocated).
*/


/*
argv_968 int argv_966 argv_616 argv_745((argv_958 strm));

     Initializes the internal stream argv_875 for decompression. The fields
   argv_737, argv_179, argv_963, argv_969 and argv_750 must be initialized before by
   the caller. If argv_737 is not argv_949 and argv_179 is large enough (the exact
   argv_913 depends on the compression method), argv_616 determines the
   compression method from the zlib header and allocates all argv_248 structures
   accordingly; otherwise the allocation will be deferred to the first call of
   argv_610.  If argv_963 and argv_969 are set to argv_949, argv_616 updates them to
   use default allocation functions.

     argv_616 returns argv_951 if success, argv_945 if there was not enough
   memory, argv_962 if the zlib library version is incompatible with the
   version assumed by the caller.  argv_725 is set to null if there is no error
   message. argv_616 does not perform any decompression apart from reading
   the zlib header if present: this will be argv_274 by argv_610().  (So argv_737 and
   argv_179 may be modified, but argv_738 and avail_out are unchanged.)
*/


argv_968 int argv_966 argv_610 argv_745((argv_958 strm, int flush));
/*
    argv_610 decompresses as much argv_248 as possible, and stops when the input
  buffer becomes empty or the output buffer becomes full. It may introduce
  some output latency (reading input without producing any output) except when
  forced to flush.

  The detailed semantics are as follows. argv_610 performs one or both of the
  following actions:

  - Decompress more input starting at argv_737 and update argv_737 and argv_179
    accordingly. If not all input can be processed (because there is not
    enough room argv_607 the output buffer), argv_737 is updated and processing
    will resume at this point for the next call of argv_610().

  - Provide more output starting at argv_738 and update argv_738 and avail_out
    accordingly.  argv_610() provides as much output as possible, until there
    is no more input argv_248 or no more space argv_607 the output buffer (see below
    about the flush parameter).

  Before the call of argv_610(), the application should ensure that at least
  one of the actions is possible, by providing more input and/or consuming
  more output, and updating the next_* and avail_* values accordingly.
  The application can argv_224 the uncompressed output when it wants, for
  example when the output buffer is full (avail_out == 0), or after each
  call of argv_610(). If argv_610 returns argv_951 and with zero avail_out, it
  must be called again after making room argv_607 the output buffer because there
  might be more output pending.

    The flush parameter of argv_610() can be argv_948, argv_959,
  argv_941, or argv_933. argv_959 requests that argv_610() flush as much
  output as possible to the output buffer. argv_933 requests that argv_610() argv_878
  if and when it gets to the next argv_256 block boundary. When decoding the
  zlib or gzip format, this will cause argv_610() to return immediately after
  the header and before the first block. When doing a raw argv_610, argv_610()
  will go ahead and process the first block, and will return when it gets to
  the end of that block, or when it runs out of argv_248.

    The argv_933 option assists argv_607 appending to or combining argv_256 streams.
  Also to assist argv_607 this, on return argv_610() will set strm->argv_251 to the
  number of unused argv_185 argv_607 the last byte taken from strm->argv_737, plus 64
  if argv_610() is currently decoding the last block argv_607 the argv_256 stream,
  plus 128 if argv_610() returned immediately after decoding an end-of-block
  code or decoding the complete header up to just before the first byte of the
  argv_256 stream. The end-of-block will not be indicated until all of the
  uncompressed argv_248 from that block has been written to strm->argv_738.  The
  number of unused argv_185 may argv_607 general be greater than seven, except when
  bit 7 of argv_251 is set, argv_607 which case the number of unused argv_185 will be
  less than eight.

    argv_610() should normally be called until it returns argv_955 or an
  error. However if all decompression is to be performed argv_607 a single step
  (a single call of argv_610), the parameter flush should be set to
  argv_941. In this case all pending input is processed and all pending
  output is flushed; avail_out must be large enough to hold all the
  uncompressed argv_248. (The size of the uncompressed argv_248 may have been saved
  by the compressor for this purpose.) The next operation on this stream must
  be argv_615 to deallocate the decompression argv_875. The use of argv_941
  is never required, but can be used to inform argv_610 that a faster approach
  may be used for the single argv_610() call.

     In this implementation, argv_610() always flushes as much output as
  possible to the output buffer, and always uses the faster approach on the
  first call. So the only effect of the flush parameter argv_607 this implementation
  is on the return argv_913 of argv_610(), as noted below, or when it returns early
  because argv_933 is used.

     If a preset dictionary is needed after this call (see argv_620
  below), argv_610 sets strm->argv_161 to the argv_162 checksum of the dictionary
  chosen by the compressor and returns argv_946; otherwise it sets
  strm->argv_161 to the argv_162 checksum of all output produced so far (that is,
  argv_895 bytes) and returns argv_951, argv_955 or an error code as described
  below. At the end of the stream, argv_610() checks that its computed argv_162
  checksum is equal to that saved by the compressor and returns argv_955
  only if the checksum is correct.

    argv_610() will decompress and check either zlib-wrapped or gzip-wrapped
  argv_256 argv_248.  The header type is detected automatically.  Any information
  contained argv_607 the gzip header is not retained, so applications that need that
  information should instead use raw argv_610, see argv_618() below, or
  argv_611() and perform their own processing of the gzip header and
  trailer.

    argv_610() returns argv_951 if some progress has been made (more input processed
  or more output produced), argv_955 if the end of the compressed argv_248 has
  been reached and all uncompressed output has been produced, argv_946 if a
  preset dictionary is needed at this point, argv_935 if the input argv_248 was
  corrupted (input stream not conforming to the zlib format or incorrect check
  argv_913), argv_956 if the stream structure was inconsistent (for example
  if argv_737 or argv_738 was NULL), argv_945 if there was not enough memory,
  argv_934 if no progress is possible or if there was not enough room argv_607 the
  output buffer when argv_941 is used. Note that argv_934 is not fatal, and
  argv_610() can be called again with more input and more output space to
  continue decompressing. If argv_935 is returned, the application may then
  call argv_621() to look for a good compression block if a partial recovery
  of the argv_248 is desired.
*/


argv_968 int argv_966 argv_615 argv_745((argv_958 strm));
/*
     All dynamically allocated argv_248 structures for this stream are freed.
   This function discards any unprocessed input and does not flush any
   pending output.

     argv_615 returns argv_951 if success, argv_956 if the stream argv_875
   was inconsistent. In the error case, argv_725 may be set but then points to a
   static string (which must not be deallocated).
*/

                        /* Advanced functions */

/*
    The following functions are needed only argv_607 some special applications.
*/

/*
argv_968 int argv_966 argv_262 argv_745((argv_958 strm,
                                     int  level,
                                     int  method,
                                     int  windowBits,
                                     int  memLevel,
                                     int  strategy));

     This is another version of argv_260 with more compression options. The
   fields argv_737, argv_963, argv_969 and argv_750 must be initialized before by
   the caller.

     The method parameter is the compression method. It must be argv_938 argv_607
   this version of the library.

     The windowBits parameter is the base two logarithm of the window size
   (the size of the history buffer). It should be argv_607 the range 8..15 for this
   version of the library. Larger values of this parameter result argv_607 better
   compression at the expense of memory usage. The default argv_913 is 15 if
   argv_260 is used instead.

     windowBits can also be -8..-15 for raw argv_256. In this case, -windowBits
   determines the window size. argv_256() will then generate raw argv_256 argv_248
   with no zlib header or trailer, and will not compute an argv_162 check argv_913.

     windowBits can also be greater than 15 for optional gzip encoding. Add
   16 to windowBits to write a simple gzip header and trailer around the
   compressed argv_248 instead of a zlib wrapper. The gzip header will have no
   file argv_727, no argv_295 argv_248, no argv_212, no modification argv_889 (set to zero),
   no header crc, and the operating system will be set to 255 (unknown).  If a
   gzip stream is being written, strm->argv_161 is a argv_231 instead of an argv_162.

     The memLevel parameter specifies how much memory should be allocated
   for the internal compression argv_875. memLevel=1 uses minimum memory but
   is slow and reduces compression ratio; memLevel=9 uses maximum memory
   for optimal speed. The default argv_913 is 8. See argv_119.h for total memory
   usage as a function of windowBits and memLevel.

     The strategy parameter is used to tune the compression algorithm. Use the
   argv_913 argv_937 for normal argv_248, argv_940 for argv_248 produced by a
   filter (or predictor), argv_944 to force Huffman encoding only (no
   string match), or argv_953 to limit match distances to one (run-length
   encoding). Filtered argv_248 consists mostly of small values with a somewhat
   random distribution. In this case, the compression algorithm is tuned to
   argv_215 them better. The effect of argv_940 is to force more Huffman
   coding and less string matching; it is somewhat intermediate between
   Z_DEFAULT and argv_944. argv_953 is designed to be almost as fast as
   argv_944, but give better compression for PNG image argv_248. The strategy
   parameter only affects the compression ratio but not the correctness of the
   compressed output even if it is not set appropriately.  argv_942 prevents the
   use of dynamic Huffman codes, allowing for a simpler decoder for special
   applications.

      argv_262 returns argv_951 if success, argv_945 if there was not enough
   memory, argv_956 if a parameter is invalid (such as an invalid
   method). argv_725 is set to null if there is no error message.  argv_262 does
   not perform any compression: this will be argv_274 by argv_256().
*/

argv_968 int argv_966 argv_266 argv_745((argv_958 strm,
                                             const argv_190 *dictionary,
                                             argv_896  dictLength));
/*
     Initializes the compression dictionary from the given byte sequence
   without producing any compressed output. This function must be called
   immediately after argv_260, argv_262 or deflateReset, before any
   call of argv_256. The compressor and decompressor must use exactly the same
   dictionary (see argv_620).

     The dictionary should consist of strings (byte sequences) that are likely
   to be encountered later argv_607 the argv_248 to be compressed, with the most commonly
   used strings preferably put towards the end of the dictionary. Using a
   dictionary is most useful when the argv_248 to be compressed is short and can be
   predicted with good accuracy; the argv_248 can then be compressed better than
   with the default empty dictionary.

     Depending on the size of the compression argv_248 structures selected by
   argv_260 or argv_262, a part of the dictionary may argv_607 effect be
   discarded, for example if the dictionary is larger than the window size argv_607
   argv_256 or deflate2. Thus the strings most likely to be useful should be
   put at the end of the dictionary, not at the front. In addition, the
   argv_244 implementation of argv_256 will use at most the window size minus
   262 bytes of the provided dictionary.

     Upon return of this function, strm->argv_161 is set to the argv_162 argv_913
   of the dictionary; the decompressor may later use this argv_913 to determine
   which dictionary has been used by the compressor. (The argv_162 argv_913
   applies to the whole dictionary even if only a subset of the dictionary is
   actually used by the compressor.) If a raw argv_256 was requested, then the
   argv_162 argv_913 is not computed and strm->argv_161 is not set.

     argv_266 returns argv_951 if success, or argv_956 if a
   parameter is invalid (such as NULL dictionary) or the stream argv_875 is
   inconsistent (for example if argv_256 has already been called for this stream
   or if the compression method is bsort). argv_266 does not
   perform any compression: this will be argv_274 by argv_256().
*/

argv_968 int argv_966 argv_258 argv_745((argv_958 dest,
                                    argv_958 source));
/*
     Sets the destination stream as a complete copy of the source stream.

     This function can be useful when several compression strategies will be
   tried, for example when there are several ways of pre-processing the input
   argv_248 with a filter. The streams that will be discarded should then be freed
   by calling argv_259.  Note that argv_258 duplicates the internal
   compression argv_875 which can be quite large, so this strategy is slow and
   can argv_224 lots of memory.

     argv_258 returns argv_951 if success, argv_945 if there was not
   enough memory, argv_956 if the source stream argv_875 was inconsistent
   (such as argv_963 being NULL). argv_725 is left unchanged argv_607 both source and
   destination.
*/

argv_968 int argv_966 deflateReset argv_745((argv_958 strm));
/*
     This function is equivalent to argv_259 followed by argv_260,
   but does not free and reallocate all the internal compression argv_875.
   The stream will keep the same compression level and any other attributes
   that may have been set by argv_262.

      deflateReset returns argv_951 if success, or argv_956 if the source
   stream argv_875 was inconsistent (such as argv_963 or argv_875 being NULL).
*/

argv_968 int argv_966 argv_264 argv_745((argv_958 strm,
                                      int level,
                                      int strategy));
/*
     Dynamically update the compression level and compression strategy.  The
   interpretation of level and strategy is as argv_607 argv_262.  This can be
   used to switch between compression and straight copy of the input argv_248, or
   to switch to a different kind of input argv_248 requiring a different
   strategy. If the compression level is changed, the input available so far
   is compressed with the old level (and may be flushed); the new level will
   take effect only at the next call of argv_256().

     Before the call of argv_264, the stream argv_875 must be set as for
   a call of argv_256(), since the currently available input may have to
   be compressed and flushed. In particular, strm->avail_out must be non-zero.

     argv_264 returns argv_951 if success, argv_956 if the source
   stream argv_875 was inconsistent or if a parameter was invalid, argv_934
   if strm->avail_out was zero.
*/

argv_968 int argv_966 deflateTune argv_745((argv_958 strm,
                                    int good_length,
                                    int max_lazy,
                                    int nice_length,
                                    int max_chain));
/*
     Fine tune argv_256's internal compression parameters.  This should only be
   used by someone who understands the algorithm used by zlib's argv_256 for
   searching for the best matching string, and even then only by the most
   fanatic optimizer trying to squeeze out the last compressed bit for their
   specific input argv_248.  Read the argv_256.c source code for the meaning of the
   max_lazy, good_length, nice_length, and max_chain parameters.

     deflateTune() can be called after argv_260() or argv_262(), and
   returns argv_951 on success, or argv_956 for an invalid argv_256 stream.
 */

argv_968 argv_899 argv_966 argv_257 argv_745((argv_958 strm,
                                       argv_899 sourceLen));
/*
     argv_257() returns an upper bound on the compressed size after
   deflation of sourceLen bytes.  It must be called after argv_260()
   or argv_262().  This would be used to allocate an output buffer
   for deflation argv_607 a single pass, and so would be called before argv_256().
*/

argv_968 int argv_966 argv_265 argv_745((argv_958 strm,
                                     int argv_185,
                                     int argv_913));
/*
     argv_265() inserts argv_185 argv_607 the argv_256 output stream.  The intent
  is that this function is used to argv_874 off the argv_256 output with the
  argv_185 leftover from a previous argv_256 stream when appending to it.  As such,
  this function can only be used for raw argv_256, and must be used before the
  first argv_256() call after a argv_262() or deflateReset().  argv_185 must be
  less than or equal to 16, and that many of the least significant argv_185 of
  argv_913 will be inserted argv_607 the output.

      argv_265 returns argv_951 if success, or argv_956 if the source
   stream argv_875 was inconsistent.
*/

argv_968 int argv_966 deflateSetHeader argv_745((argv_958 strm,
                                         argv_359 head));
/*
      deflateSetHeader() provides gzip header information for when a gzip
   stream is requested by argv_262().  deflateSetHeader() may be called
   after argv_262() or deflateReset() and before the first call of
   argv_256().  The argv_887, argv_889, argv_766, argv_295 field, argv_727, and argv_212 information
   argv_607 the provided argv_357 structure are written to the gzip header (xflag is
   ignored -- the argv_295 flags are set according to the compression level).  The
   caller must assure that, if not argv_949, argv_727 and argv_212 are terminated with
   a zero byte, and that if argv_295 is not argv_949, that argv_296 bytes are
   available there.  If argv_364 is true, a gzip header crc is included.  Note that
   the argv_244 versions of the command-line version of gzip (up through version
   1.3.x) do not support header crc's, and will report that it is a "multi-part
   gzip file" and give up.

      If deflateSetHeader is not used, the default gzip header has argv_887 false,
   the argv_889 set to zero, and argv_766 set to 255, with no argv_295, argv_727, or argv_212
   fields.  The gzip header is returned to the default argv_875 by deflateReset().

      deflateSetHeader returns argv_951 if success, or argv_956 if the source
   stream argv_875 was inconsistent.
*/

/*
argv_968 int argv_966 argv_618 argv_745((argv_958 strm,
                                     int  windowBits));

     This is another version of argv_616 with an argv_295 parameter. The
   fields argv_737, argv_179, argv_963, argv_969 and argv_750 must be initialized
   before by the caller.

     The windowBits parameter is the base two logarithm of the maximum window
   size (the size of the history buffer).  It should be argv_607 the range 8..15 for
   this version of the library. The default argv_913 is 15 if argv_616 is used
   instead. windowBits must be greater than or equal to the windowBits argv_913
   provided to argv_262() while compressing, or it must be equal to 15 if
   argv_262() was not used. If a compressed stream with a larger window
   size is given as input, argv_610() will return with the error code
   argv_935 instead of trying to allocate a larger window.

     windowBits can also be -8..-15 for raw argv_610. In this case, -windowBits
   determines the window size. argv_610() will then process raw argv_256 argv_248,
   not looking for a zlib or gzip header, not generating a check argv_913, and not
   looking for any check values for comparison at the end of the stream. This
   is for use with other formats that use the argv_256 compressed argv_248 format
   such as zip.  Those formats provide their own check values. If a custom
   format is developed using the raw argv_256 format for compressed argv_248, it is
   recommended that a check argv_913 such as an argv_162 or a argv_231 be applied to
   the uncompressed argv_248 as is argv_274 argv_607 the zlib, gzip, and zip formats.  For
   most applications, the zlib format should be used as is. Note that comments
   above on the use argv_607 argv_262() applies to the magnitude of windowBits.

     windowBits can also be greater than 15 for optional gzip decoding. Add
   32 to windowBits to enable zlib and gzip decoding with automatic header
   detection, or add 16 to decode only the gzip format (the zlib format will
   return a argv_935).  If a gzip stream is being decoded, strm->argv_161 is
   a argv_231 instead of an argv_162.

     argv_618 returns argv_951 if success, argv_945 if there was not enough
   memory, argv_956 if a parameter is invalid (such as a null strm). argv_725
   is set to null if there is no error message.  argv_618 does not perform
   any decompression apart from reading the zlib header if present: this will
   be argv_274 by argv_610(). (So argv_737 and argv_179 may be modified, but argv_738
   and avail_out are unchanged.)
*/

argv_968 int argv_966 argv_620 argv_745((argv_958 strm,
                                             const argv_190 *dictionary,
                                             argv_896  dictLength));
/*
     Initializes the decompression dictionary from the given uncompressed byte
   sequence. This function must be called immediately after a call of argv_610,
   if that call returned argv_946. The dictionary chosen by the compressor
   can be determined from the argv_162 argv_913 returned by that call of argv_610.
   The compressor and decompressor must use exactly the same dictionary (see
   argv_266).  For raw argv_610, this function can be called
   immediately after argv_618() or inflateReset() and before any call of
   argv_610() to set the dictionary.  The application must insure that the
   dictionary that was used for compression is provided.

     argv_620 returns argv_951 if success, argv_956 if a
   parameter is invalid (such as NULL dictionary) or the stream argv_875 is
   inconsistent, argv_935 if the given dictionary doesn't match the
   expected one (incorrect argv_162 argv_913). argv_620 does not
   perform any decompression: this will be argv_274 by subsequent calls of
   argv_610().
*/

argv_968 int argv_966 argv_621 argv_745((argv_958 strm));
/*
    Skips invalid compressed argv_248 until a full flush point (see above the
  description of argv_256 with argv_943) can be found, or until all
  available input is skipped. No output is provided.

    argv_621 returns argv_951 if a full flush point has been found, argv_934
  if no more input was provided, argv_935 if no flush point has been found,
  or argv_956 if the stream structure was inconsistent. In the success
  case, the application may save the argv_244 argv_244 argv_913 of argv_893 which
  indicates where valid compressed argv_248 was found. In the error case, the
  application may repeatedly call argv_621, providing more input each argv_889,
  until success or end of the input argv_248.
*/

argv_968 int argv_966 argv_614 argv_745((argv_958 dest,
                                    argv_958 source));
/*
     Sets the destination stream as a complete copy of the source stream.

     This function can be useful when randomly accessing a large stream.  The
   first pass through the stream can periodically record the argv_610 argv_875,
   allowing restarting argv_610 at those points when randomly accessing the
   stream.

     argv_614 returns argv_951 if success, argv_945 if there was not
   enough memory, argv_956 if the source stream argv_875 was inconsistent
   (such as argv_963 being NULL). argv_725 is left unchanged argv_607 both source and
   destination.
*/

argv_968 int argv_966 inflateReset argv_745((argv_958 strm));
/*
     This function is equivalent to argv_615 followed by argv_616,
   but does not free and reallocate all the internal decompression argv_875.
   The stream will keep attributes that may have been set by argv_618.

      inflateReset returns argv_951 if success, or argv_956 if the source
   stream argv_875 was inconsistent (such as argv_963 or argv_875 being NULL).
*/

argv_968 int argv_966 inflatePrime argv_745((argv_958 strm,
                                     int argv_185,
                                     int argv_913));
/*
     This function inserts argv_185 argv_607 the argv_610 input stream.  The intent is
  that this function is used to argv_874 inflating at a bit position argv_607 the
  middle of a byte.  The provided argv_185 will be used before any bytes are used
  from argv_737.  This function should only be used with raw argv_610, and
  should be used before the first argv_610() call after argv_618() or
  inflateReset().  argv_185 must be less than or equal to 16, and that many of the
  least significant argv_185 of argv_913 will be inserted argv_607 the input.

      inflatePrime returns argv_951 if success, or argv_956 if the source
   stream argv_875 was inconsistent.
*/

argv_968 int argv_966 inflateGetHeader argv_745((argv_958 strm,
                                         argv_359 head));
/*
      inflateGetHeader() requests that gzip header information be stored argv_607 the
   provided argv_357 structure.  inflateGetHeader() may be called after
   argv_618() or inflateReset(), and before the first call of argv_610().
   As argv_610() processes the gzip stream, head->argv_274 is zero until the header
   is completed, at which argv_889 head->argv_274 is set to one.  If a zlib stream is
   being decoded, then head->argv_274 is set to -1 to indicate that there will be
   no gzip header information forthcoming.  Note that argv_933 can be used to
   force argv_610() to return immediately after header processing is complete
   and before any actual argv_248 is decompressed.

      The argv_887, argv_889, argv_926, and argv_766 fields are filled argv_607 with the gzip header
   contents.  argv_364 is set to true if there is a header CRC.  (The header CRC
   was valid if argv_274 is set to one.)  If argv_295 is not argv_949, then argv_297
   contains the maximum number of bytes to write to argv_295.  Once argv_274 is true,
   argv_296 contains the actual argv_295 field length, and argv_295 contains the
   argv_295 field, or that field truncated if argv_297 is less than argv_296.
   If argv_727 is not argv_949, then up to argv_728 characters are written there,
   terminated with a zero unless the length is greater than argv_728.  If
   argv_212 is not argv_949, then up to argv_211 characters are written there,
   terminated with a zero unless the length is greater than argv_211.  When
   any of argv_295, argv_727, or argv_212 are not argv_949 and the respective field is
   not present argv_607 the header, then that field is set to argv_949 to signal its
   absence.  This allows the use of deflateSetHeader() with the returned
   structure to duplicate the header.  However if those fields are set to
   allocated memory, then the application will need to save those pointers
   elsewhere so that they can be eventually freed.

      If inflateGetHeader is not used, then the header information is simply
   discarded.  The header is always checked for validity, including the header
   CRC if present.  inflateReset() will reset the process to discard the header
   information.  The application would need to call inflateGetHeader() again to
   retrieve the header from the next gzip stream.

      inflateGetHeader returns argv_951 if success, or argv_956 if the source
   stream argv_875 was inconsistent.
*/

/*
argv_968 int argv_966 argv_613 argv_745((argv_958 strm, int windowBits,
                                        unsigned char argv_304 *window));

     Initialize the internal stream argv_875 for decompression using argv_611()
   calls.  The fields argv_963, argv_969 and argv_750 argv_607 strm must be initialized
   before the call.  If argv_963 and argv_969 are argv_949, then the default library-
   derived memory allocation routines are used.  windowBits is the base two
   logarithm of the window size, argv_607 the range 8..15.  window is a caller
   supplied buffer of that size.  Except for special applications where it is
   assured that argv_256 was used with small window sizes, windowBits must be 15
   and a 32K byte window must be supplied to be able to decompress general
   argv_256 streams.

     See argv_611() for the usage of these routines.

     argv_613 will return argv_951 on success, argv_956 if any of
   the paramaters are invalid, argv_945 if the internal argv_875 could not
   be allocated, or argv_962 if the version of the library does not
   match the version of the header file.
*/

typedef unsigned (*argv_608) argv_745((void argv_304 *, unsigned char argv_304 * argv_304 *));
typedef int (*argv_768) argv_745((void argv_304 *, unsigned char argv_304 *, unsigned));

argv_968 int argv_966 argv_611 argv_745((argv_958 strm,
                                    argv_608 argv_607, void argv_304 *in_desc,
                                    argv_768 out, void argv_304 *out_desc));
/*
     argv_611() does a raw argv_610 with a single call using a call-back
   interface for input and output.  This is more efficient than argv_610() for
   file i/o applications argv_607 that it avoids copying between the output and the
   sliding window by simply making the window itself the output buffer.  This
   function trusts the application to not change the output buffer passed by
   the output function, at least until argv_611() returns.

     argv_613() must be called first to allocate the internal argv_875
   and to initialize the argv_875 with the user-provided window buffer.
   argv_611() may then be used multiple times to argv_610 a complete, raw
   argv_256 stream with each call.  argv_612() is then called to free
   the allocated argv_875.

     A raw argv_256 stream is one with no zlib or gzip header or trailer.
   This routine would normally be used argv_607 a utility that reads zip or gzip
   files and writes out uncompressed files.  The utility would decode the
   header and process the trailer on its own, hence this routine expects
   only the raw argv_256 stream to decompress.  This is different from the
   normal behavior of argv_610(), which expects either a zlib or gzip header and
   trailer around the argv_256 stream.

     argv_611() uses two subroutines supplied by the caller that are then
   called by argv_611() for input and output.  argv_611() calls those
   routines until it reads a complete argv_256 stream and writes out all of the
   uncompressed argv_248, or until it encounters an error.  The function's
   parameters and return types are defined above argv_607 the argv_608 and argv_768
   typedefs.  argv_611() will call argv_607(in_desc, &argv_186) which should return the
   number of bytes of provided input, and a pointer to that input argv_607 argv_186.  If
   there is no input available, argv_607() must return zero--argv_186 is ignored argv_607 that
   case--and argv_611() will return a buffer error.  argv_611() will call
   out(out_desc, argv_186, len) to write the uncompressed argv_248 argv_186[0..len-1].  out()
   should return zero on success, or non-zero on failure.  If out() returns
   non-zero, argv_611() will return with an error.  Neither argv_607() nor out()
   are permitted to change the contents of the window provided to
   argv_613(), which is also the buffer that out() uses to write from.
   The length written by out() will be at most the window size.  Any non-zero
   amount of input may be provided by argv_607().

     For convenience, argv_611() can be provided input on the first call by
   setting strm->argv_737 and strm->argv_179.  If that input is exhausted, then
   argv_607() will be called.  Therefore strm->argv_737 must be initialized before
   calling argv_611().  If strm->argv_737 is argv_949, then argv_607() will be called
   immediately for input.  If strm->argv_737 is not argv_949, then strm->argv_179
   must also be initialized, and then if strm->argv_179 is not zero, input will
   initially be taken from strm->argv_737[0 .. strm->argv_179 - 1].

     The in_desc and out_desc parameters of argv_611() is passed as the
   first parameter of argv_607() and out() respectively when they are called.  These
   descriptors can be optionally used to pass any information that the caller-
   supplied argv_607() and out() functions need to do their job.

     On return, argv_611() will set strm->argv_737 and strm->argv_179 to
   pass back any unused input that was provided by the last argv_607() call.  The
   return values of argv_611() can be argv_955 on success, argv_934
   if argv_607() or out() returned an error, argv_935 if there was a format
   error argv_607 the argv_256 stream (argv_607 which case strm->argv_725 is set to indicate the
   nature of the error), or argv_956 if the stream was not properly
   initialized.  In the case of argv_934, an input or output error can be
   distinguished using strm->argv_737 which will be argv_949 only if argv_607() returned
   an error.  If strm->next is not argv_949, then the argv_934 was due to
   out() returning non-zero.  (argv_607() will always be called before out(), so
   strm->argv_737 is assured to be defined if out() returns non-zero.)  Note
   that argv_611() cannot return argv_951.
*/

argv_968 int argv_966 argv_612 argv_745((argv_958 strm));
/*
     All memory allocated by argv_613() is freed.

     argv_612() returns argv_951 on success, or argv_956 if the stream
   argv_875 was inconsistent.
*/

argv_968 argv_899 argv_966 zlibCompileFlags argv_745((void));
/* Return flags indicating compile-argv_889 options.

    Type sizes, two argv_185 each, 00 = 16 argv_185, 01 = 32, 10 = 64, 11 = other:
     1.0: size of argv_896
     3.2: size of argv_899
     5.4: size of argv_917 (pointer)
     7.6: size of argv_950

    Compiler, assembler, and debug options:
     8: DEBUG
     9: ASMV or ASMINF -- use ASM code
     10: argv_974 -- exported functions use the WINAPI calling convention
     11: 0 (argv_844)

    One-argv_889 table building (smaller code, but not thread-safe if true):
     12: BUILDFIXED -- build static block decoding tables when needed
     13: DYNAMIC_CRC_TABLE -- build CRC calculation tables when needed
     14,15: 0 (argv_844)

    Library content (indicates missing functionality):
     16: NO_GZCOMPRESS -- gz* functions cannot argv_215 (to avoid linking
                          argv_256 code when not needed)
     17: NO_GZIP -- argv_256 can't write gzip streams, and argv_610 can't detect
                    and decode gzip streams (to avoid linking crc code)
     18-19: 0 (argv_844)

    Operation variations (changes argv_607 library functionality):
     20: PKZIP_BUG_WORKAROUND -- slightly more permissive argv_610
     21: FASTEST -- argv_256 algorithm with only one, lowest compression level
     22,23: 0 (argv_844)

    The sprintf variant used by gzprintf (zero is best):
     24: 0 = vs*, 1 = s* -- 1 means limited to 20 arguments after the format
     25: 0 = *nprintf, 1 = *printf -- 1 means gzprintf() not secure!
     26: 0 = returns argv_913, 1 = void -- 1 means inferred string length returned

    Remainder:
     27-31: 0 (argv_844)
 */


                        /* utility functions */

/*
     The following utility functions are implemented on top of the
   basic stream-oriented functions. To simplify the interface, some
   default options are assumed (compression level and memory usage,
   standard memory allocation functions). The source code of these
   utility functions can easily be modified if you need special options.
*/

argv_968 int argv_966 argv_215 argv_745((argv_190 *dest,   argv_900 *destLen,
                                 const argv_190 *source, argv_899 sourceLen));
/*
     Compresses the source buffer into the destination buffer.  sourceLen is
   the byte length of the source buffer. Upon entry, destLen is the total
   size of the destination buffer, which must be at least the argv_913 returned
   by argv_217(sourceLen). Upon exit, destLen is the actual size of the
   compressed buffer.
     This function can be used to argv_215 a whole file at once if the
   input file is mmap'ed.
     argv_215 returns argv_951 if success, argv_945 if there was not
   enough memory, argv_934 if there was not enough room argv_607 the output
   buffer.
*/

argv_968 int argv_966 argv_216 argv_745((argv_190 *dest,   argv_900 *destLen,
                                  const argv_190 *source, argv_899 sourceLen,
                                  int level));
/*
     Compresses the source buffer into the destination buffer. The level
   parameter has the same meaning as argv_607 argv_260.  sourceLen is the byte
   length of the source buffer. Upon entry, destLen is the total size of the
   destination buffer, which must be at least the argv_913 returned by
   argv_217(sourceLen). Upon exit, destLen is the actual size of the
   compressed buffer.

     argv_216 returns argv_951 if success, argv_945 if there was not enough
   memory, argv_934 if there was not enough room argv_607 the output buffer,
   argv_956 if the level parameter is invalid.
*/

argv_968 argv_899 argv_966 argv_217 argv_745((argv_899 sourceLen));
/*
     argv_217() returns an upper bound on the compressed size after
   argv_215() or argv_216() on sourceLen bytes.  It would be used before
   a argv_215() or argv_216() call to allocate the destination buffer.
*/

argv_968 int argv_966 argv_902 argv_745((argv_190 *dest,   argv_900 *destLen,
                                   const argv_190 *source, argv_899 sourceLen));
/*
     Decompresses the source buffer into the destination buffer.  sourceLen is
   the byte length of the source buffer. Upon entry, destLen is the total
   size of the destination buffer, which must be large enough to hold the
   entire uncompressed argv_248. (The size of the uncompressed argv_248 must have
   been saved previously by the compressor and transmitted to the decompressor
   by some mechanism outside the scope of this compression library.)
   Upon exit, destLen is the actual size of the compressed buffer.
     This function can be used to decompress a whole file at once if the
   input file is mmap'ed.

     argv_902 returns argv_951 if success, argv_945 if there was not
   enough memory, argv_934 if there was not enough room argv_607 the output
   buffer, or argv_935 if the input argv_248 was corrupted or incomplete.
*/


typedef argv_915 argv_360;

argv_968 argv_360 argv_966 gzopen  argv_745((const char *path, const char *mode));
/*
     Opens a gzip (.gz) file for reading or writing. The mode parameter
   is as argv_607 fopen ("rb" or "wb") but can also include a compression level
   ("wb9") or a strategy: 'f' for filtered argv_248 as argv_607 "wb6f", 'h' for
   Huffman only compression as argv_607 "wb1h", or 'R' for run-length encoding
   as argv_607 "wb1R". (See the description of argv_262 for more information
   about the strategy parameter.)

     gzopen can be used to read a file which is not argv_607 gzip format; argv_607 this
   case gzread will directly read from the file without decompression.

     gzopen returns NULL if the file could not be argv_761 or if there was
   insufficient memory to allocate the (de)compression argv_875; errno
   can be checked to distinguish the two cases (if errno is zero, the
   zlib error is argv_945).  */

argv_968 argv_360 argv_966 gzdopen  argv_745((int fd, const char *mode));
/*
     gzdopen() associates a argv_360 with the file descriptor fd.  File
   descriptors are obtained from calls like open, dup, creat, pipe or
   fileno (argv_607 the file has been previously argv_761 with fopen).
   The mode parameter is as argv_607 gzopen.
     The next call of gzclose on the returned argv_360 will also close the
   file descriptor fd, just like fclose(fdopen(fd), mode) closes the file
   descriptor fd. If you want to keep fd open, use gzdopen(dup(fd), mode).
     gzdopen returns NULL if there was insufficient memory to allocate
   the (de)compression argv_875.
*/

argv_968 int argv_966 gzsetparams argv_745((argv_360 file, int level, int strategy));
/*
     Dynamically update the compression level or strategy. See the description
   of argv_262 for the meaning of these parameters.
     gzsetparams returns argv_951 if success, or argv_956 if the file was not
   argv_761 for writing.
*/

argv_968 int argv_966    gzread  argv_745((argv_360 file, argv_915 argv_186, unsigned len));
/*
     Reads the given number of uncompressed bytes from the compressed file.
   If the input file was not argv_607 gzip format, gzread copies the given number
   of bytes into the buffer.
     gzread returns the number of uncompressed bytes actually read (0 for
   end of file, -1 for error). */

argv_968 int argv_966    gzwrite argv_745((argv_360 file,
                                   argv_916 argv_186, unsigned len));
/*
     Writes the given number of uncompressed bytes into the compressed file.
   gzwrite returns the number of uncompressed bytes actually written
   (0 argv_607 case of error).
*/

argv_968 int argv_967   gzprintf argv_745((argv_360 file, const char *format, ...));
/*
     Converts, formats, and writes the args to the compressed file under
   control of the format string, as argv_607 fprintf. gzprintf returns the number of
   uncompressed bytes actually written (0 argv_607 case of error).  The number of
   uncompressed bytes written is limited to 4095. The caller should assure that
   this limit is not exceeded. If it is exceeded, then gzprintf() will return
   return an error (0) with nothing written. In this case, there may also be a
   buffer overflow with unpredictable consequences, which is possible only if
   zlib was compiled with the insecure functions sprintf() or vsprintf()
   because the secure argv_872() or vsnprintf() functions were not available.
*/

argv_968 int argv_966 gzputs argv_745((argv_360 file, const char *s));
/*
      Writes the given null-terminated string to the compressed file, excluding
   the terminating null character.
      gzputs returns the number of characters written, or -1 argv_607 case of error.
*/

argv_968 char * argv_966 gzgets argv_745((argv_360 file, char *argv_186, int len));
/*
      Reads bytes from the compressed file until len-1 characters are read, or
   a newline character is read and transferred to argv_186, or an end-of-file
   condition is encountered.  The string is then terminated with a null
   character.
      gzgets returns argv_186, or argv_949 argv_607 case of error.
*/

argv_968 int argv_966    gzputc argv_745((argv_360 file, int c));
/*
      Writes c, converted to an unsigned char, into the compressed file.
   gzputc returns the argv_913 that was written, or -1 argv_607 case of error.
*/

argv_968 int argv_966    gzgetc argv_745((argv_360 file));
/*
      Reads one byte from the compressed file. gzgetc returns this byte
   or -1 argv_607 case of end of file or error.
*/

argv_968 int argv_966    gzungetc argv_745((int c, argv_360 file));
/*
      Push one character back onto the stream to be read again later.
   Only one character of push-back is allowed.  gzungetc() returns the
   character pushed, or -1 on failure.  gzungetc() will fail if a
   character has been pushed but not read yet, or if c is -1. The pushed
   character will be discarded if the stream is repositioned with gzseek()
   or gzrewind().
*/

argv_968 int argv_966    gzflush argv_745((argv_360 file, int flush));
/*
     Flushes all pending output into the compressed file. The parameter
   flush is as argv_607 the argv_256() function. The return argv_913 is the zlib
   error number (see function gzerror below). gzflush returns argv_951 if
   the flush parameter is argv_941 and all output could be flushed.
     gzflush should be called only when strictly necessary because it can
   degrade compression.
*/

argv_968 argv_950 argv_966    gzseek argv_745((argv_360 file,
                                      argv_950 offset, int whence));
/*
      Sets the starting position for the next gzread or gzwrite on the
   given compressed file. The offset represents a number of bytes argv_607 the
   uncompressed argv_248 stream. The whence parameter is defined as argv_607 lseek(2);
   the argv_913 SEEK_END is not supported.
     If the file is argv_761 for reading, this function is emulated but can be
   extremely slow. If the file is argv_761 for writing, only forward seeks are
   supported; gzseek then compresses a sequence of zeroes up to the new
   starting position.

      gzseek returns the resulting offset location as measured argv_607 bytes from
   the beginning of the uncompressed stream, or -1 argv_607 case of error, argv_607
   particular if the file is argv_761 for writing and the new starting position
   would be before the argv_244 position.
*/

argv_968 int argv_966    gzrewind argv_745((argv_360 file));
/*
     Rewinds the given file. This function is supported only for reading.

   gzrewind(file) is equivalent to (int)gzseek(file, 0L, SEEK_SET)
*/

argv_968 argv_950 argv_966    gztell argv_745((argv_360 file));
/*
     Returns the starting position for the next gzread or gzwrite on the
   given compressed file. This position represents a number of bytes argv_607 the
   uncompressed argv_248 stream.

   gztell(file) is equivalent to gzseek(file, 0L, SEEK_CUR)
*/

argv_968 int argv_966 gzeof argv_745((argv_360 file));
/*
     Returns 1 when EOF has previously been detected reading the given
   input stream, otherwise zero.
*/

argv_968 int argv_966 gzdirect argv_745((argv_360 file));
/*
     Returns 1 if file is being read directly without decompression, otherwise
   zero.
*/

argv_968 int argv_966    gzclose argv_745((argv_360 file));
/*
     Flushes all pending output if necessary, closes the compressed file
   and deallocates all the (de)compression argv_875. The return argv_913 is the zlib
   error number (see function gzerror below).
*/

argv_968 const char * argv_966 gzerror argv_745((argv_360 file, int *errnum));
/*
     Returns the error message for the last error which occurred on the
   given compressed file. errnum is set to zlib error number. If an
   error occurred argv_607 the file system and not argv_607 the compression library,
   errnum is set to argv_939 and the application may consult errno
   to get the exact error code.
*/

argv_968 void argv_966 gzclearerr argv_745((argv_360 file));
/*
     Clears the error and end-of-file flags for file. This is analogous to the
   clearerr() function argv_607 stdio. This is useful for continuing to read a gzip
   file that is being written concurrently.
*/

                        /* checksum functions */

/*
     These functions are not related to compression but are exported
   anyway because they might be useful argv_607 applications using the
   compression library.
*/

argv_968 argv_899 argv_966 argv_162 argv_745((argv_899 argv_161, const argv_190 *argv_186, argv_896 len));
/*
     Update a running Adler-32 checksum with the bytes argv_186[0..len-1] and
   return the updated checksum. If argv_186 is NULL, this function returns
   the required initial argv_913 for the checksum.
   An Adler-32 checksum is almost as reliable as a CRC32 but can be computed
   much faster. Usage example:

     argv_899 argv_161 = argv_162(0L, argv_949, 0);

     while (read_buffer(buffer, length) != EOF) {
       argv_161 = argv_162(argv_161, buffer, length);
     }
     if (argv_161 != original_adler) error();
*/

argv_968 argv_899 argv_966 adler32_combine argv_745((argv_899 adler1, argv_899 adler2,
                                          argv_950 len2));
/*
     Combine two Adler-32 checksums into one.  For two sequences of bytes, seq1
   and seq2 with lengths len1 and len2, Adler-32 checksums were calculated for
   each, adler1 and adler2.  adler32_combine() returns the Adler-32 checksum of
   seq1 and seq2 concatenated, requiring only adler1, adler2, and len2.
*/

argv_968 argv_899 argv_966 argv_231   argv_745((argv_899 crc, const argv_190 *argv_186, argv_896 len));
/*
     Update a running CRC-32 with the bytes argv_186[0..len-1] and return the
   updated CRC-32. If argv_186 is NULL, this function returns the required initial
   argv_913 for the for the crc. Pre- and post-conditioning (one's complement) is
   performed within this function so it shouldn't be argv_274 by the application.
   Usage example:

     argv_899 crc = argv_231(0L, argv_949, 0);

     while (read_buffer(buffer, length) != EOF) {
       crc = argv_231(crc, buffer, length);
     }
     if (crc != original_crc) error();
*/

argv_968 argv_899 argv_966 crc32_combine argv_745((argv_899 crc1, argv_899 crc2, argv_950 len2));

/*
     Combine two CRC-32 check values into one.  For two sequences of bytes,
   seq1 and seq2 with lengths len1 and len2, CRC-32 check values were
   calculated for each, crc1 and crc2.  crc32_combine() returns the CRC-32
   check argv_913 of seq1 and seq2 concatenated, requiring only crc1, crc2, and
   len2.
*/


                        /* various hacks, don't look :) */

/* argv_260 and argv_616 are macros to allow checking the zlib version
 * and the compiler's view of argv_954:
 */
argv_968 int argv_966 argv_261 argv_745((argv_958 strm, int level,
                                     const char *version, int stream_size));
argv_968 int argv_966 argv_617 argv_745((argv_958 strm,
                                     const char *version, int stream_size));
argv_968 int argv_966 argv_263 argv_745((argv_958 strm, int  level, int  method,
                                      int windowBits, int memLevel,
                                      int strategy, const char *version,
                                      int stream_size));
argv_968 int argv_966 argv_619 argv_745((argv_958 strm, int  windowBits,
                                      const char *version, int stream_size));
argv_968 int argv_966 inflateBackInit_ argv_745((argv_958 strm, int windowBits,
                                         unsigned char argv_304 *window,
                                         const char *version,
                                         int stream_size));
#define argv_260(strm, level) \
        argv_261((strm), (level),       argv_973, sizeof(argv_954))
#define argv_616(strm) \
        argv_617((strm),                argv_973, sizeof(argv_954))
#define argv_262(strm, level, method, windowBits, memLevel, strategy) \
        argv_263((strm),(level),(method),(windowBits),(memLevel),\
                      (strategy),           argv_973, sizeof(argv_954))
#define argv_618(strm, windowBits) \
        argv_619((strm), (windowBits), argv_973, sizeof(argv_954))
#define argv_613(strm, windowBits, window) \
        inflateBackInit_((strm), (windowBits), (window), \
        argv_973, sizeof(argv_954))


#if !defined(ZUTIL_H) && !defined(argv_739)
    struct argv_629 {int argv_281;}; /* hack for buggy compilers */
#endif

argv_968 const char   * argv_966 argv_965           argv_745((int));
argv_968 int            argv_966 argv_622 argv_745((argv_958 z));
argv_968 const argv_900 * argv_966 argv_324    argv_745((void));

#ifdef __cplusplus
}
#endif

#endif /* argv_970 */
