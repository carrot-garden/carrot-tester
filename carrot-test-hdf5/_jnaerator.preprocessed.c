
#line 1 "/usr/include/H5Fpublic.h" 1
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright by The HDF Group.                                               *
 * Copyright by the Board of Trustees of the University of Illinois.         *
 * All rights reserved.                                                      *
 *                                                                           *
 * This file is part of HDF5.  The full HDF5 copyright notice, including     *
 * terms governing use, modification, and redistribution, is contained in    *
 * the files COPYING and Copyright.html.  COPYING can be found at the root   *
 * of the source code distribution tree; Copyright.html can be found at the  *
 * root level of an installed copy of the electronic HDF5 document set and   *
 * is linked from the top-level documents page.  It can also be found at     *
 * http://hdfgroup.org/HDF5/doc/Copyright.html.  If you do not have          *
 * access to either file, you may request a copy from help@hdfgroup.org.     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
 * This file contains public declarations for the H5F module.
 */



/* Public header files needed by this file */

#line 1 "/usr/include/H5public.h" 1
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright by The HDF Group.                                               *
 * Copyright by the Board of Trustees of the University of Illinois.         *
 * All rights reserved.                                                      *
 *                                                                           *
 * This file is part of HDF5.  The full HDF5 copyright notice, including     *
 * terms governing use, modification, and redistribution, is contained in    *
 * the files COPYING and Copyright.html.  COPYING can be found at the root   *
 * of the source code distribution tree; Copyright.html can be found at the  *
 * root level of an installed copy of the electronic HDF5 document set and   *
 * is linked from the top-level documents page.  It can also be found at     *
 * http://hdfgroup.org/HDF5/doc/Copyright.html.  If you do not have          *
 * access to either file, you may request a copy from help@hdfgroup.org.     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
 * This file contains public declarations for the HDF5 module.
 */



/* Include files for public use... */
/*
 * Since H5pubconf.h is a generated header file, it is messy to try
 * to put a #ifndef _H5pubconf_H ... #endif guard in it.
 * HDF5 has set an internal rule that it is being included here.
 * Source files should NOT include H5pubconf.h directly but include
 * it via H5public.h.  The #ifndef _H5public_H guard above would
 * prevent repeated include.
 */

#line 1 "/usr/include/H5pubconf.h" 1
/* src/H5config.h.  Generated from H5config.h.in by configure.  */
/* src/H5config.h.in.  Generated from configure.in by autoheader.  */

/* Define if building universal (internal helper macro) */
/* #undef H5_AC_APPLE_UNIVERSAL_BUILD */

/* Define if your system generates wrong code for log2 routine. */
/* #undef H5_BAD_LOG2_CODE_GENERATED */

/* Define if the memory buffers being written to disk should be cleared before
   writing. */


/* Define if your system can handle converting denormalized floating-point
   values. */


/* Define if C++ compiler recognizes offsetof */


/* Define the default virtual file driver to compile */


/* Define if `dev_t' is a scalar */


/* Define to dummy `main' function (if any) required to link to the Fortran
   libraries. */
/* #undef H5_FC_DUMMY_MAIN */

/* Define if F77 and FC dummy `main' functions are identical. */
/* #undef H5_FC_DUMMY_MAIN_EQ_F77 */

/* Define to a macro mangling the given C identifier (in lower and upper
   case), which must not contain underscores, for linking with Fortran. */


/* As FC_FUNC, but for C identifiers containing underscores. */


/* Define if your system can handle overflow converting floating-point to
   integer values. */


/* Define if your system roundup accurately converting floating-point to
   unsigned long long values. */


/* Define if your system has right maximum convert floating-point to unsigned
   long long values. */
/* #undef H5_FP_TO_ULLONG_RIGHT_MAXIMUM */

/* Define if gettimeofday() populates the tz pointer passed in */


/* Define to 1 if you have the `alarm' function. */


/* Define if the __attribute__(()) extension is present */


/* Define to 1 if you have the `BSDgettimeofday' function. */
/* #undef H5_HAVE_BSDGETTIMEOFDAY */

/* Define if the compiler understands C99 designated initialization of structs
   and unions */


/* Define if the compiler understands the __func__ keyword */


/* Define if the function stack tracing code is to be compiled in */
/* #undef H5_HAVE_CODESTACK */

/* Define to 1 if you have the declaration of `tzname', and to 0 if you don't.
   */
/* #undef H5_HAVE_DECL_TZNAME */

/* Define to 1 if you have the `difftime' function. */


/* Define if the direct I/O virtual file driver should be compiled */
/* #undef H5_HAVE_DIRECT */

/* Define to 1 if you have the <dlfcn.h> header file. */


/* Define to 1 if you have the <dmalloc.h> header file. */
/* #undef H5_HAVE_DMALLOC_H */

/* Define if library information should be embedded in the executables */


/* Define to 1 if you have the <features.h> header file. */


/* Define if support for deflate (zlib) filter is enabled */


/* Define if support for Fletcher32 checksum is enabled */


/* Define if support for nbit filter is enabled */


/* Define if support for scaleoffset filter is enabled */


/* Define if support for shuffle filter is enabled */


/* Define if support for szip filter is enabled */
/* #undef H5_HAVE_FILTER_SZIP */

/* Define to 1 if you have the `fork' function. */


/* Define to 1 if you have the `frexpf' function. */


/* Define to 1 if you have the `frexpl' function. */


/* Define to 1 if you have the `fseek64' function. */
/* #undef H5_HAVE_FSEEK64 */

/* Define to 1 if you have the `fseeko' function. */


/* Define to 1 if you have the `fstat64' function. */


/* Define to 1 if you have the `ftello' function. */


/* Define to 1 if you have the `ftruncate64' function. */


/* Define if the compiler understands the __FUNCTION__ keyword */


/* Define to 1 if you have the `GetConsoleScreenBufferInfo' function. */
/* #undef H5_HAVE_GETCONSOLESCREENBUFFERINFO */

/* Define to 1 if you have the `gethostname' function. */


/* Define to 1 if you have the `getpwuid' function. */


/* Define to 1 if you have the `getrusage' function. */


/* Define to 1 if you have the `gettextinfo' function. */
/* #undef H5_HAVE_GETTEXTINFO */

/* Define to 1 if you have the `gettimeofday' function. */


/* Define to 1 if you have the `get_fpc_csr' function. */
/* #undef H5_HAVE_GET_FPC_CSR */

/* Define if we have GPFS support */
/* #undef H5_HAVE_GPFS */

/* Define to 1 if you have the <gpfs.h> header file. */
/* #undef H5_HAVE_GPFS_H */

/* Define if library will contain instrumentation to detect correct
   optimization operation */
/* #undef H5_HAVE_INSTRUMENTED_LIBRARY */

/* Define to 1 if you have the <inttypes.h> header file. */


/* Define to 1 if you have the `ioctl' function. */


/* Define to 1 if you have the <io.h> header file. */
/* #undef H5_HAVE_IO_H */

/* Define to 1 if you have the `dmalloc' library (-ldmalloc). */
/* #undef H5_HAVE_LIBDMALLOC */

/* Define to 1 if you have the `lmpe' library (-llmpe). */
/* #undef H5_HAVE_LIBLMPE */

/* Define to 1 if you have the `m' library (-lm). */


/* Define to 1 if you have the `mpe' library (-lmpe). */
/* #undef H5_HAVE_LIBMPE */

/* Define to 1 if you have the `mpi' library (-lmpi). */
/* #undef H5_HAVE_LIBMPI */

/* Define to 1 if you have the `mpich' library (-lmpich). */
/* #undef H5_HAVE_LIBMPICH */

/* Define to 1 if you have the `mpio' library (-lmpio). */
/* #undef H5_HAVE_LIBMPIO */

/* Define to 1 if you have the `nsl' library (-lnsl). */
/* #undef H5_HAVE_LIBNSL */

/* Define to 1 if you have the `pthread' library (-lpthread). */


/* Define to 1 if you have the `socket' library (-lsocket). */
/* #undef H5_HAVE_LIBSOCKET */

/* Define to 1 if you have the `sz' library (-lsz). */
/* #undef H5_HAVE_LIBSZ */

/* Define to 1 if you have the `z' library (-lz). */


/* Define to 1 if you have the `longjmp' function. */


/* Define to 1 if you have the `lseek64' function. */


/* Define to 1 if you have the <memory.h> header file. */


/* Define if we have MPE support */
/* #undef H5_HAVE_MPE */

/* Define to 1 if you have the <mpe.h> header file. */
/* #undef H5_HAVE_MPE_H */

/* Define if MPI_File_get_size works correctly */
/* #undef H5_HAVE_MPI_GET_SIZE */

/* Define if `MPI_Comm_c2f' and `MPI_Comm_f2c' exists */
/* #undef H5_HAVE_MPI_MULTI_LANG_Comm */

/* Define if `MPI_Info_c2f' and `MPI_Info_f2c' exists */
/* #undef H5_HAVE_MPI_MULTI_LANG_Info */

/* Define if we have parallel support */
/* #undef H5_HAVE_PARALLEL */

/* Define to 1 if you have the <pthread.h> header file. */


/* Define to 1 if you have the `random' function. */


/* Define to 1 if you have the `rand_r' function. */


/* Define to 1 if you have the <setjmp.h> header file. */


/* Define to 1 if you have the `setsysinfo' function. */
/* #undef H5_HAVE_SETSYSINFO */

/* Define to 1 if you have the `sigaction' function. */


/* Define to 1 if you have the `siglongjmp' function. */


/* Define to 1 if you have the `signal' function. */


/* Define to 1 if you have the `snprintf' function. */


/* Define to 1 if you have the `srandom' function. */


/* Define to 1 if you have the `stat64' function. */


/* Define if `struct stat' has the `st_blocks' field */


/* Define to 1 if you have the <stddef.h> header file. */


/* Define to 1 if you have the <stdint.h> header file. */


/* Define to 1 if you have the <stdlib.h> header file. */


/* Define to 1 if you have the `strdup' function. */


/* Define to 1 if you have the <strings.h> header file. */


/* Define to 1 if you have the <string.h> header file. */


/* Define if `struct text_info' is defined */
/* #undef H5_HAVE_STRUCT_TEXT_INFO */

/* Define if `struct timezone' is defined */


/* Define to 1 if `tm_zone' is a member of `struct tm'. */


/* Define if `struct videoconfig' is defined */
/* #undef H5_HAVE_STRUCT_VIDEOCONFIG */

/* Define to 1 if you have the `system' function. */


/* Define to 1 if you have the <sys/fpu.h> header file. */
/* #undef H5_HAVE_SYS_FPU_H */

/* Define to 1 if you have the <sys/ioctl.h> header file. */


/* Define to 1 if you have the <sys/proc.h> header file. */
/* #undef H5_HAVE_SYS_PROC_H */

/* Define to 1 if you have the <sys/resource.h> header file. */


/* Define to 1 if you have the <sys/socket.h> header file. */


/* Define to 1 if you have the <sys/stat.h> header file. */


/* Define to 1 if you have the <sys/sysinfo.h> header file. */
/* #undef H5_HAVE_SYS_SYSINFO_H */

/* Define to 1 if you have the <sys/timeb.h> header file. */


/* Define to 1 if you have the <sys/time.h> header file. */


/* Define to 1 if you have the <sys/types.h> header file. */


/* Define to 1 if you have the <szlib.h> header file. */
/* #undef H5_HAVE_SZLIB_H */

/* Define if we have thread safe support */


/* Define if `timezone' is a global variable */
/* #undef H5_HAVE_TIMEZONE */

/* Define if the ioctl TIOCGETD is defined */


/* Define if the ioctl TIOGWINSZ is defined */


/* Define to 1 if you have the `tmpfile' function. */


/* Define if `tm_gmtoff' is a member of `struct tm' */


/* Define to 1 if your `struct tm' has `tm_zone'. Deprecated, use
   `HAVE_STRUCT_TM_TM_ZONE' instead. */


/* Define to 1 if you don't have `tm_zone' but do have the external array
   `tzname'. */
/* #undef H5_HAVE_TZNAME */

/* Define to 1 if you have the <unistd.h> header file. */


/* Define to 1 if you have the `vasprintf' function. */


/* Define to 1 if you have the `vsnprintf' function. */


/* Define to 1 if you have the `waitpid' function. */


/* Define if your system has window style path name. */
/* #undef H5_HAVE_WINDOW_PATH */

/* Define to 1 if you have the <winsock.h> header file. */
/* #undef H5_HAVE_WINSOCK_H */

/* Define to 1 if you have the <zlib.h> header file. */


/* Define to 1 if you have the `_getvideoconfig' function. */
/* #undef H5_HAVE__GETVIDEOCONFIG */

/* Define to 1 if you have the `_scrsize' function. */
/* #undef H5_HAVE__SCRSIZE */

/* Define if `__tm_gmtoff' is a member of `struct tm' */
/* #undef H5_HAVE___TM_GMTOFF */

/* Define if your system can't handle converting floating-point values to long
   long. */
/* #undef H5_HW_FP_TO_LLONG_NOT_WORKS */

/* Define if HDF5's high-level library headers should be included in hdf5.h */


/* Define if your system can accurately convert from integers to long double
   values. */


/* Define if your system can convert long double to integers accurately. */


/* Define if your system can convert from long double to integer values. */


/* Define if your system can convert long double to (unsigned) long long
   values correctly. */


/* Define if your system can convert long double to unsigned int values
   correctly. */


/* Define if your system can compile long long to floating-point casts. */


/* Define if your system can convert (unsigned) long long to long double
   values correctly. */


/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */


/* Define if the metadata trace file code is to be compiled in */
/* #undef H5_METADATA_TRACE_FILE */

/* Define if your system can handle complicated MPI derived datatype
   correctly. */
/* #undef H5_MPI_COMPLEX_DERIVED_DATATYPE_WORKS */

/* Define if your system's `MPI_File_set_size' function works for files over
   2GB. */
/* #undef H5_MPI_FILE_SET_SIZE_BIG */

/* Define if your system can handle special collective IO properly. */
/* #undef H5_MPI_SPECIAL_COLLECTIVE_IO_WORKS */

/* Define if we can violate pointer alignment restrictions */


/* Define if deprecated public API symbols are disabled */
/* #undef H5_NO_DEPRECATED_SYMBOLS */

/* Define if shared writing must be disabled (CodeWarrior only) */
/* #undef H5_NO_SHARED_WRITING */

/* Name of package */


/* Define to the address where bug reports for this package should be sent. */


/* Define to the full name of this package. */


/* Define to the full name and version of this package. */


/* Define to the one symbol short name of this package. */


/* Define to the home page for this package. */


/* Define to the version of this package. */


/* Width for printf() for type `long long' or `__int64', use `ll' */


/* The size of `char', as computed by sizeof. */


/* The size of `double', as computed by sizeof. */


/* The size of `float', as computed by sizeof. */


/* The size of `int', as computed by sizeof. */


/* The size of `int16_t', as computed by sizeof. */


/* The size of `int32_t', as computed by sizeof. */


/* The size of `int64_t', as computed by sizeof. */


/* The size of `int8_t', as computed by sizeof. */


/* The size of `int_fast16_t', as computed by sizeof. */


/* The size of `int_fast32_t', as computed by sizeof. */


/* The size of `int_fast64_t', as computed by sizeof. */


/* The size of `int_fast8_t', as computed by sizeof. */


/* The size of `int_least16_t', as computed by sizeof. */


/* The size of `int_least32_t', as computed by sizeof. */


/* The size of `int_least64_t', as computed by sizeof. */


/* The size of `int_least8_t', as computed by sizeof. */


/* The size of `long', as computed by sizeof. */


/* The size of `long double', as computed by sizeof. */


/* The size of `long long', as computed by sizeof. */


/* The size of `off64_t', as computed by sizeof. */


/* The size of `off_t', as computed by sizeof. */


/* The size of `short', as computed by sizeof. */


/* The size of `size_t', as computed by sizeof. */


/* The size of `ssize_t', as computed by sizeof. */


/* The size of `uint16_t', as computed by sizeof. */


/* The size of `uint32_t', as computed by sizeof. */


/* The size of `uint64_t', as computed by sizeof. */


/* The size of `uint8_t', as computed by sizeof. */


/* The size of `uint_fast16_t', as computed by sizeof. */


/* The size of `uint_fast32_t', as computed by sizeof. */


/* The size of `uint_fast64_t', as computed by sizeof. */


/* The size of `uint_fast8_t', as computed by sizeof. */


/* The size of `uint_least16_t', as computed by sizeof. */


/* The size of `uint_least32_t', as computed by sizeof. */


/* The size of `uint_least64_t', as computed by sizeof. */


/* The size of `uint_least8_t', as computed by sizeof. */


/* The size of `unsigned', as computed by sizeof. */


/* The size of `__int64', as computed by sizeof. */


/* Define to 1 if you have the ANSI C header files. */


/* Define if strict file format checks are enabled */
/* #undef H5_STRICT_FORMAT_CHECKS */

/* Define if your system supports pthread_attr_setscope(&attribute,
   PTHREAD_SCOPE_SYSTEM) call. */


/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. */


/* Define to 1 if your <sys/time.h> declares `struct tm'. */
/* #undef H5_TM_IN_SYS_TIME */

/* Define if your system can compile unsigned long long to floating-point
   casts. */


/* Define if your system can convert unsigned long long to long double with
   correct precision. */


/* Define if your system accurately converting unsigned long to float values.
   */


/* Define if your system can accurately convert unsigned (long) long values to
   floating-point values. */


/* Define using v1.6 public API symbols by default */


/* Define if a memory checking tool will be used on the library, to cause
   library to be very picky about memory operations and also disable the
   internal free list manager code. */
/* #undef H5_USING_MEMCHECKER */

/* Version number of package */


/* Define if vsnprintf() returns the correct value for formatted strings that
   don't fit into size allowed */


/* Data accuracy is prefered to speed during data conversions */


/* Check exception handling functions during data conversions */


/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */






/* #  undef WORDS_BIGENDIAN */



/* Define to empty if `const' does not conform to ANSI C. */
/* #undef H5_const */

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */

/* #undef H5_inline */


/* Define to `long int' if <sys/types.h> does not define. */
/* #undef H5_off_t */

/* Define to `unsigned long' if <sys/types.h> does not define. */
/* #undef H5_size_t */

/* Define to `long' if <sys/types.h> does not define. */
/* #undef H5_ssize_t */

#line 31 "/usr/include/H5public.h" 2

/* API Version macro wrapper definitions */

#line 1 "/usr/include/H5version.h" 1
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright by The HDF Group.                                               *
 * Copyright by the Board of Trustees of the University of Illinois.         *
 * All rights reserved.                                                      *
 *                                                                           *
 * This file is part of HDF5.  The full HDF5 copyright notice, including     *
 * terms governing use, modification, and redistribution, is contained in    *
 * the files COPYING and Copyright.html.  COPYING can be found at the root   *
 * of the source code distribution tree; Copyright.html can be found at the  *
 * root level of an installed copy of the electronic HDF5 document set and   *
 * is linked from the top-level documents page.  It can also be found at     *
 * http://hdfgroup.org/HDF5/doc/Copyright.html.  If you do not have          *
 * access to either file, you may request a copy from help@hdfgroup.org.     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* Generated automatically by bin/make_vers -- do not edit */
/* Add new versioned symbols to H5vers.txt file */





/* Issue error if contradicting macros have been defined. */





/* If a particular "global" version of the library's interfaces is chosen,
 *      set the versions for the API symbols affected.
 *
 * Note: If an application has already chosen a particular version for an
 *      API symbol, the individual API version macro takes priority.
 */






/*************/
/* Functions */
/*************/





















































































/************/
/* Typedefs */
/************/












/* Choose the correct version of each API symbol, defaulting to the latest
 *      version of each.  The "best" name for API parameters/data structures
 *      that have changed definitions is also set.  An error is issued for
 *      specifying an invalid API version.
 */

/*************/
/* Functions */
/*************/














































































































































































































































/************/
/* Typedefs */
/************/



























#line 34 "/usr/include/H5public.h" 2



#line 1 "/usr/include/features.h" 1
/* Copyright (C) 1991-1993,1995-2007,2009,2010,2011
   Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */




/* These are defined by the user (or the compiler)
   to specify the desired environment:

   __STRICT_ANSI__	ISO Standard C.
   _ISOC99_SOURCE	Extensions to ISO C89 from ISO C99.
   _POSIX_SOURCE	IEEE Std 1003.1.
   _POSIX_C_SOURCE	If ==1, like _POSIX_SOURCE; if >=2 add IEEE Std 1003.2;
			if >=199309L, add IEEE Std 1003.1b-1993;
			if >=199506L, add IEEE Std 1003.1c-1995;
			if >=200112L, all of IEEE 1003.1-2004
			if >=200809L, all of IEEE 1003.1-2008
   _XOPEN_SOURCE	Includes POSIX and XPG things.  Set to 500 if
			Single Unix conformance is wanted, to 600 for the
			sixth revision, to 700 for the seventh revision.
   _XOPEN_SOURCE_EXTENDED XPG things and X/Open Unix extensions.
   _LARGEFILE_SOURCE	Some more functions for correct standard I/O.
   _LARGEFILE64_SOURCE	Additional functionality from LFS for large files.
   _FILE_OFFSET_BITS=N	Select default filesystem interface.
   _BSD_SOURCE		ISO C, POSIX, and 4.3BSD things.
   _SVID_SOURCE		ISO C, POSIX, and SVID things.
   _ATFILE_SOURCE	Additional *at interfaces.
   _GNU_SOURCE		All of the above, plus GNU extensions.
   _REENTRANT		Select additionally reentrant object.
   _THREAD_SAFE		Same as _REENTRANT, often used by other systems.
   _FORTIFY_SOURCE	If set to numeric value > 0 additional security
			measures are defined, according to level.

   The `-ansi' switch to the GNU C compiler defines __STRICT_ANSI__.
   If none of these are defined, the default is to have _SVID_SOURCE,
   _BSD_SOURCE, and _POSIX_SOURCE set to one and _POSIX_C_SOURCE set to
   200112L.  If more than one of these are defined, they accumulate.
   For example __STRICT_ANSI__, _POSIX_SOURCE and _POSIX_C_SOURCE
   together give you ISO C, 1003.1, and 1003.2, but nothing else.

   These are defined by this file and are used by the
   header files to decide what to declare or define:

   __USE_ISOC99		Define ISO C99 things.
   __USE_ISOC95		Define ISO C90 AMD1 (C95) things.
   __USE_POSIX		Define IEEE Std 1003.1 things.
   __USE_POSIX2		Define IEEE Std 1003.2 things.
   __USE_POSIX199309	Define IEEE Std 1003.1, and .1b things.
   __USE_POSIX199506	Define IEEE Std 1003.1, .1b, .1c and .1i things.
   __USE_XOPEN		Define XPG things.
   __USE_XOPEN_EXTENDED	Define X/Open Unix things.
   __USE_UNIX98		Define Single Unix V2 things.
   __USE_XOPEN2K        Define XPG6 things.
   __USE_XOPEN2KXSI     Define XPG6 XSI things.
   __USE_XOPEN2K8XSI    Define XPG7 XSI things.
   __USE_LARGEFILE	Define correct standard I/O things.
   __USE_LARGEFILE64	Define LFS things with separate names.
   __USE_FILE_OFFSET64	Define 64bit interface as default.
   __USE_BSD		Define 4.3BSD things.
   __USE_SVID		Define SVID things.
   __USE_MISC		Define things common to BSD and System V Unix.
   __USE_ATFILE		Define *at interfaces and AT_* constants for them.
   __USE_GNU		Define GNU extensions.
   __USE_REENTRANT	Define reentrant/thread-safe *_r functions.
   __USE_FORTIFY_LEVEL	Additional security measures used, according to level.
   __FAVOR_BSD		Favor 4.3BSD things in cases of conflict.

   The macros `__GNU_LIBRARY__', `__GLIBC__', and `__GLIBC_MINOR__' are
   defined by this file unconditionally.  `__GNU_LIBRARY__' is provided
   only for compatibility.  All new code should use the other symbols
   to test for features.

   All macros listed above as possibly being defined by this file are
   explicitly undefined if they are not explicitly defined.
   Feature-test macros that are not defined by the user or compiler
   but are implied by the other feature-test macros defined (or by the
   lack of any definitions) are defined by the file.  */


/* Undefine everything, so we get a clean slate.  */


























/* Suppress kernel-name space pollution unless user expressedly asks
   for it.  */




/* Always use ISO C things.  */


/* Convenience macros to test the versions of glibc and gcc.
   Use them like this:
   #if __GNUC_PREREQ (2,8)
   ... code requiring gcc 2.8 or later ...
   #endif
   Note - they won't work for gcc1 or glibc1, since the _MINOR macros
   were not defined then.  */








/* If _BSD_SOURCE was defined by the user, favor BSD over POSIX.  */






/* If _GNU_SOURCE was defined by the user, turn on all the other features.  */























/* If nothing (other than _GNU_SOURCE) is defined,
   define _BSD_SOURCE and _SVID_SOURCE.  */







/* This is to enable the ISO C99 extension.  Also recognize the old macro
   which was used prior to the standard acceptance.  This macro will
   eventually go away and the features enabled by default once the ISO C99
   standard is widely adopted.  */





/* This is to enable the ISO C90 Amendment 1:1995 extension.  */





/* If none of the ANSI/POSIX macros are defined, use POSIX.1 and POSIX.2
   (and IEEE Std 1003.1b-1993 unless _XOPEN_SOURCE is defined).  */






















































































































/* Define __STDC_IEC_559__ and other similar macros.  */

#line 1 "/usr/include/bits/predefs.h" 1
/* Copyright (C) 2005 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */








/* We do support the IEC 559 math functionality, real and complex.  */





#line 159 "/usr/include/features.h" 2

/* wchar_t uses ISO 10646-1 (2nd ed., published 2000-09-15) / Unicode 3.1.  */


/* This macro indicates that the installed library is the GNU C Library.
   For historic reasons the value now is 6 and this will stay from now
   on.  The use of this variable is deprecated.  Use __GLIBC__ and
   __GLIBC_MINOR__ now (see below) when you want to test for a specific
   GNU C library version and use the values in <gnu/lib-names.h> to get
   the sonames of the shared libraries.  */



/* Major and minor version number of the GNU C library package.  Use
   these macros to test for features in specific releases.  */






/* Decide whether a compiler supports the long long datatypes.  */







/* This is here only because every header file already includes this one.  */



#line 1 "/usr/include/sys/cdefs.h" 1
/* Copyright (C) 1992-2001, 2002, 2004, 2005, 2006, 2007, 2009
   Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */




/* We are almost always included from features.h. */




/* The GNU libc does not support any K&R compilers or the traditional mode
   of ISO C compilers anymore.  Check for some of the combinations not
   anymore supported.  */




/* Some user header file might have defined this before.  */





/* GCC can always grok prototypes.  For C++ programs we add throw()
   to help it optimize the function calls.  But this works only with
   gcc 2.8.x and egcs.  For gcc 3.2 and up we even mark C functions
   as non-throwing using a function attribute since programs can use
   the -fexceptions options for C code as well.  */


























/* These two macros are not used in glibc anymore.  They are kept here
   only because some other projects expect the macros to be defined.  */



/* For these things, GCC behaves the ANSI way normally,
   and the non-ANSI way under -traditional.  */




/* This is not a typedef so `const __ptr_t' does the right thing.  */




/* C++ needs to know that types and declarations are C, not C++.  */









/* The standard library needs the functions from the ISO C90 standard
   in the std namespace.  At the same time we want to be safe for
   future changes and we include the ISO C99 code in the non-standard
   namespace __c99.  The C++ wrapper header take case of adding the
   definitions to the global namespace.  */








/* For compatibility we do not add the declarations into any
   namespace.  They will end up in the global namespace which is what
   old code expects.  */









/* Support for bounded pointers.  */







/* Fortify support.  */















/* Support for flexible arrays.  */

















/* __asm__ ("xyz") is used throughout the headers to rename functions
   at the assembly language level.  This is wrapped by the __REDIRECT
   macro, in order to support compilers that can do this some other
   way.  When compilers don't support asm-names at all, we have to do
   preprocessor tricks instead (which don't have exactly the right
   semantics, but it's the best we can do).

   Example:
   int __REDIRECT(setpgrp, (__pid_t pid, __pid_t pgrp), setpgid); */






















/* GCC has various useful declarations that can be made with the
   `__attribute__' syntax.  All of the ways we use this do fine if
   they are omitted for compilers that don't understand it. */




/* At some point during the gcc 2.96 development the `malloc' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.  */






/* At some point during the gcc 2.96 development the `pure' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.  */






/* At some point during the gcc 3.1 development the `used' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.  */








/* gcc allows marking deprecated functions.  */






/* At some point during the gcc 2.8 development the `format_arg' attribute
   for functions was introduced.  We don't want to use it unconditionally
   (although this would be possible) since it generates warnings.
   If several `format_arg' attributes are given for the same function, in
   gcc-3.0 and older, all but the last one are ignored.  In newer gccs,
   all designated arguments are considered.  */






/* At some point during the gcc 2.97 development the `strfmon' format
   attribute for functions was introduced.  We don't want to use it
   unconditionally (although this would be possible) since it
   generates warnings.  */







/* The nonull function attribute allows to mark pointer parameters which
   must not be NULL.  */






/* If fortification mode, we warn about unused results of certain
   function calls which can lead to problems.  */













/* Forces a function to be always inlined.  */






/* GCC 4.3 and above with -std=c99 or -std=gnu99 implements ISO C99
   inline semantics, unless -fgnu89-inline is used.  */





















/* GCC 4.3 and above allow passing all anonymous arguments of an
   __extern_always_inline function to some other vararg function.  */





/* It is possible to compile containing GCC extensions even if GCC is
   run in pedantic mode if the uses are carefully marked using the
   `__extension__' keyword.  But this is not generally available before
   version 2.8.  */




/* __restrict is known in EGCS 1.2 and above. */




/* ISO C99 also allows to declare arrays as non-overlapping.  The syntax is
     array_name[restrict]
   GCC 3.1 supports this.  */
















#line 1 "/usr/include/bits/wordsize.h" 1
/* Determine the wordsize from the preprocessor defines.  */








#line 245 "/usr/include/sys/cdefs.h" 2



































#line 183 "/usr/include/features.h" 2


/* If we don't have __REDIRECT, prototypes will be missing if
   __USE_FILE_OFFSET64 but not __USE_LARGEFILE[64]. */







/* Decide whether we can define 'extern inline' functions in headers.  */






/* There are some functions that must be declared 'extern inline' even with
   -Os when building LIBC, or they'll end up undefined.  */







/* This is here only because every header file already includes this one.
   Get the definitions of all the appropriate `__stub_FUNCTION' symbols.
   <gnu/stubs.h> contains `#define __stub_FUNCTION' when FUNCTION is a stub
   that will always return failure (and set errno to ENOSYS).  */

#line 1 "/usr/include/gnu/stubs.h" 1
/* This file selects the right generated file of `__stub_FUNCTION' macros
   based on the architecture being compiled for.  */


#line 1 "/usr/include/bits/wordsize.h" 1

#line 6 "/usr/include/gnu/stubs.h" 2



#line 1 "/usr/include/gnu/stubs.h" 1






#line 204 "/usr/include/features.h" 2




#line 36 "/usr/include/H5public.h" 2



#line 1 "/usr/include/sys/types.h" 1
/* Copyright (C) 1991,1992,1994-2002,2006,2010 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

/*
 *	POSIX Standard: 2.6 Primitive System Data Types	<sys/types.h>
 */





#line 1 "/usr/include/features.h" 1

#line 26 "/usr/include/sys/types.h" 2




#line 1 "/usr/include/bits/types.h" 1
/* bits/types.h -- definitions of __*_t types underlying *_t types.
   Copyright (C) 2002, 2003, 2004, 2005, 2007 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

/*
 * Never include this file directly; use <sys/types.h> instead.
 */





#line 1 "/usr/include/features.h" 1

#line 27 "/usr/include/bits/types.h" 2

#line 1 "/usr/include/bits/wordsize.h" 1

#line 28 "/usr/include/bits/types.h" 2

/* Convenience types.  */
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;

/* Fixed-size types, underlying types depend on word size and compiler.  */
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;




 typedef signed long long int __int64_t;
 typedef unsigned long long int __uint64_t;


/* quad_t is also 64 bits.  */




 typedef long long int __quad_t;
 typedef unsigned long long int __u_quad_t;



  



  




/* The machine-dependent file <bits/typesizes.h> defines __*_T_TYPE
   macros for each of the OS types we define below.  The definitions
   of those macros must use the following macros for underlying types.
   We define __S<SIZE>_TYPE and __U<SIZE>_TYPE for the signed and unsigned
   variants of each of the following integer types on this machine.

	16		-- "natural" 16-bit type (always short)
	32		-- "natural" 32-bit type (always int)
	64		-- "natural" 64-bit type (long or long long)
	LONG32		-- 32-bit type, traditionally long
	QUAD		-- 64-bit type, always long long
	WORD		-- natural type of __WORDSIZE bits (int or long)
	LONGWORD	-- type of __WORDSIZE bits, traditionally long

   We distinguish WORD/LONGWORD, 32/LONG32, and 64/QUAD so that the
   conventional uses of `long' or `long long' type modifiers match the
   types we define, even when a less-adorned type would be the same size.
   This matters for (somewhat) portably writing printf/scanf formats for
   these types, where using the appropriate l or ll format modifiers can
   make the typedefs and the formats match up across all GNU platforms.  If
   we used `long' when it's 64 bits where `long long' is expected, then the
   compiler would warn about the formats not matching the argument types,
   and the programmer changing them to shut up the compiler would break the
   program's portability.

   Here we assume what is presently the case in all the GCC configurations
   we support: long long is always 64 bits, long is always word/address size,
   and int is always 32 bits.  */
















/* We want __extension__ before typedef's that use nonstandard base types
   such as `long long' in C89 mode.  */
















#line 1 "/usr/include/bits/typesizes.h" 1
/* bits/typesizes.h -- underlying types for *_t.  Generic version.
   Copyright (C) 2002, 2003 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */








/* See <bits/types.h> for the meaning of these macros.  This file exists so
   that <bits/types.h> need not vary across different GNU platforms.  */

































/* Number of descriptors that can fit in an `fd_set'.  */





#line 93 "/usr/include/bits/types.h" 2


 typedef __u_quad_t __dev_t;	/* Type of device numbers.  */
 typedef unsigned int __uid_t;	/* Type of user identifications.  */
 typedef unsigned int __gid_t;	/* Type of group identifications.  */
 typedef unsigned long int __ino_t;	/* Type of file serial numbers.  */
 typedef __u_quad_t __ino64_t;	/* Type of file serial numbers (LFS).*/
 typedef unsigned int __mode_t;	/* Type of file attribute bitmasks.  */
 typedef unsigned int __nlink_t;	/* Type of file link counts.  */
 typedef long int __off_t;	/* Type of file sizes and offsets.  */
 typedef __quad_t __off64_t;	/* Type of file sizes and offsets (LFS).  */
 typedef int __pid_t;	/* Type of process identifications.  */
 typedef struct { int __val[2]; } __fsid_t;	/* Type of file system IDs.  */
 typedef long int __clock_t;	/* Type of CPU usage counts.  */
 typedef unsigned long int __rlim_t;	/* Type for resource measurement.  */
 typedef __u_quad_t __rlim64_t;	/* Type for resource measurement (LFS).  */
 typedef unsigned int __id_t;		/* General type for IDs.  */
 typedef long int __time_t;	/* Seconds since the Epoch.  */
 typedef unsigned int __useconds_t; /* Count of microseconds.  */
 typedef long int __suseconds_t; /* Signed count of microseconds.  */

 typedef int __daddr_t;	/* The type of a disk address.  */
 typedef long int __swblk_t;	/* Type of a swap block maybe?  */
 typedef int __key_t;	/* Type of an IPC key.  */

/* Clock ID used in clock and timer functions.  */
 typedef int __clockid_t;

/* Timer ID returned by `timer_create'.  */
 typedef void * __timer_t;

/* Type to represent block size.  */
 typedef long int __blksize_t;

/* Types from the Large File Support interface.  */

/* Type to count number of disk blocks.  */
 typedef long int __blkcnt_t;
 typedef __quad_t __blkcnt64_t;

/* Type to count file system blocks.  */
 typedef unsigned long int __fsblkcnt_t;
 typedef __u_quad_t __fsblkcnt64_t;

/* Type to count file system nodes.  */
 typedef unsigned long int __fsfilcnt_t;
 typedef __u_quad_t __fsfilcnt64_t;

 typedef int __ssize_t; /* Type of a byte count, or error.  */

/* These few don't really vary by system, they always correspond
   to one of the other defined types.  */
typedef __off64_t __loff_t;	/* Type of file sizes and offsets (LFS).  */
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;

/* Duplicates info from stdint.h but this is used in unistd.h.  */
 typedef int __intptr_t;

/* Duplicate info from sys/socket.h.  */
 typedef unsigned int __socklen_t;






#line 29 "/usr/include/sys/types.h" 2



typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;




typedef __loff_t loff_t;



typedef __ino_t ino_t;











typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;











typedef __pid_t pid_t;





typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;










#line 1 "/usr/include/time.h" 1
/* Copyright (C) 1991-2003,2006,2009 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

/*
 *	ISO C99 Standard: 7.23 Date and time	<time.h>
 */



































#line 1 "/usr/include/bits/types.h" 1

#line 42 "/usr/include/time.h" 2


/* Returned by `clock'.  */
typedef __clock_t clock_t;












#line 1 "/usr/include/bits/types.h" 1

#line 52 "/usr/include/time.h" 2


/* Returned by `time'.  */
typedef __time_t time_t;













#line 1 "/usr/include/bits/types.h" 1

#line 63 "/usr/include/time.h" 2

/* Clock ID used in clock and timer functions.  */
typedef __clockid_t clockid_t;









#line 1 "/usr/include/bits/types.h" 1

#line 73 "/usr/include/time.h" 2

/* Timer ID returned by `timer_create'.  */
typedef __timer_t timer_t;
















  
    
    
  










  
  
  
  
  
  
  
  
  


  
  

  
  











  
    
    
  
























     









			
			






		       
     








			  
			  
			  




			 
			 

















			    




			       

















			



		      

























































		      










     







			    
			    








			 
			 






			  
			  



     










































		      








#line 71 "/usr/include/sys/types.h" 2














#line 1 "/usr/include/sys/types.h" 1


/* Old compatibility names for C types.  */
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;


/* These size-specific names are used by some of the inet code.  */



/* These types are defined by the ISO C99 header <inttypes.h>. */


typedef	char int8_t;
typedef	short int int16_t;
typedef	int int32_t;



 typedef long long int int64_t;



/* But these were defined by ISO C without the first `_'.  */
typedef	unsigned char u_int8_t;
typedef	unsigned short int u_int16_t;
typedef	unsigned int u_int32_t;



 typedef unsigned long long int u_int64_t;


typedef int register_t;
































/* In BSD <sys/types.h> is expected to define BYTE_ORDER.  */

#line 1 "/usr/include/endian.h" 1
/* Copyright (C) 1992, 1996, 1997, 2000, 2008 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */





#line 1 "/usr/include/features.h" 1

#line 22 "/usr/include/endian.h" 2

/* Definitions for byte order, according to significance of bytes,
   from low addresses to high addresses.  The value is what you get by
   putting '4' in the most significant byte, '3' in the second most
   significant byte, '2' in the second least significant byte, and '1'
   in the least significant byte, and then writing down one digit for
   each byte, starting with the byte at the lowest address at the left,
   and proceeding to the byte with the highest address at the right.  */





/* This file defines `__BYTE_ORDER' for the particular machine.  */

#line 1 "/usr/include/bits/endian.h" 1
/* x86_64 is little-endian.  */







#line 34 "/usr/include/endian.h" 2

/* Some machines may need to use a different endianness for floating point
   values.  */



















/* Conversion interfaces.  */

#line 1 "/usr/include/bits/byteswap.h" 1
/* Macros to swap the order of bytes in integer values.
   Copyright (C) 1997, 1998, 2000, 2002, 2003, 2007, 2008, 2010
   Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */









#line 1 "/usr/include/bits/wordsize.h" 1

#line 26 "/usr/include/bits/byteswap.h" 2

/* Swap bytes in 16 bit value.  */
















/* This is better than nothing.  */







/* Swap bytes in 32 bit value.  */



















































































#line 43 "/usr/include/endian.h" 2




































#line 128 "/usr/include/sys/types.h" 2

/* It also defines `fd_set' and the FD_* macros for `select'.  */

#line 1 "/usr/include/sys/select.h" 1
/* `fd_set' type and related macros, and `select'/`pselect' declarations.
   Copyright (C) 1996-2003, 2009 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

/*	POSIX 1003.1g: 6.2 Select from File Descriptor Sets <sys/select.h>  */





#line 1 "/usr/include/features.h" 1

#line 25 "/usr/include/sys/select.h" 2

/* Get definition of needed basic types.  */

#line 1 "/usr/include/bits/types.h" 1

#line 28 "/usr/include/sys/select.h" 2

/* Get __FD_* definitions.  */

#line 1 "/usr/include/bits/select.h" 1
/* Copyright (C) 1997-1999,2001,2008,2009,2011 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */






#line 1 "/usr/include/bits/wordsize.h" 1

#line 23 "/usr/include/bits/select.h" 2























/* We don't use `memset' because this would require a prototype and
   the array isn't too big.  */

















#line 31 "/usr/include/sys/select.h" 2

/* Get __sigset_t.  */

#line 1 "/usr/include/bits/sigset.h" 1
/* __sig_atomic_t, __sigset_t, and related definitions.  Linux version.
   Copyright (C) 1991, 1992, 1994, 1996, 1997, 2007
   Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */




typedef int __sig_atomic_t;

/* A `sigset_t' has a bit for each signal.  */


typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;




/* We only want to define these functions if <signal.h> was actually
   included; otherwise we were included just to define the types.  Since we
   are namespace-clean, it wouldn't hurt to define extra macros.  But
   trouble can be caused by functions being defined (e.g., any global
   register vars declared later will cause compilation errors).  */






















































































#line 34 "/usr/include/sys/select.h" 2



typedef __sigset_t sigset_t;


/* Get definition of timer specification structures.  */



#line 1 "/usr/include/time.h" 1

#line 39 "/usr/include/sys/select.h" 2


#line 1 "/usr/include/bits/time.h" 1
/* System-dependent timing definitions.  Generic version.
   Copyright (C) 1996,1997,1999-2002,2003,2010 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

/*
 * Never include this file directly; use <time.h> instead.
 */

















































#line 1 "/usr/include/bits/types.h" 1

#line 50 "/usr/include/bits/time.h" 2

/* A time value that is accurate to the nearest
   microsecond but also has a range of years.  */
struct timeval
  {
    __time_t tv_sec;		/* Seconds.  */
    __suseconds_t tv_usec;	/* Microseconds.  */
  };



#line 40 "/usr/include/sys/select.h" 2


typedef __suseconds_t suseconds_t;




/* The fd_set member is required to be an array of longs.  */
typedef long int __fd_mask;

/* Some versions of <linux/posix_types.h> define these macros.  */



/* It's easier to assume 8-bit bytes than to get CHAR_BIT.  */




/* fd_set for select and pselect.  */
typedef struct
  {
    /* XPG4.2 requires this member name.  Otherwise avoid the name
       from the global namespace.  */

    


    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];


  } fd_set;

/* Maximum number of file descriptors in `fd_set'.  */



/* Sometimes the fd_set member is assumed to have this type.  */
typedef __fd_mask fd_mask;

/* Number of bits per word of `fd_set' (some code assumes this is 32).  */




/* Access macros for `fd_set'.  */








/* Check the first NFDS descriptors each in READFDS (if not NULL) for read
   readiness, in WRITEFDS (if not NULL) for write readiness, and in EXCEPTFDS
   (if not NULL) for exceptional conditions.  If TIMEOUT is not NULL, time out
   after waiting the interval specified therein.  Returns the number of ready
   descriptors, or -1 for errors.

   This function is a cancellation point and therefore not marked with
   __THROW.  */
extern int select (int __nfds, fd_set * __readfds,
		   fd_set * __writefds,
		   fd_set * __exceptfds,
		   struct timeval * __timeout);


/* Same as above only that the TIMEOUT value is given with higher
   resolution and a sigmask which is been set temporarily.  This version
   should be used.

   This function is a cancellation point and therefore not marked with
   __THROW.  */
extern int pselect (int __nfds, fd_set * __readfds,
		    fd_set * __writefds,
		    fd_set * __exceptfds,
		    const struct timespec * __timeout,
		    const __sigset_t * __sigmask);






#line 131 "/usr/include/sys/types.h" 2

/* BSD defines these symbols, so we follow.  */

#line 1 "/usr/include/sys/sysmacros.h" 1
/* Definitions of macros to access `dev_t' values.
   Copyright (C) 1996, 1997, 1999, 2003, 2004, 2007
   Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */





#line 1 "/usr/include/features.h" 1

#line 24 "/usr/include/sys/sysmacros.h" 2

/* If the compiler does not know long long it is out of luck.  We are
   not going to hack weird hacks to support the dev_t representation
   they need.  */


extern unsigned int gnu_dev_major (unsigned long long int __dev)
     ;

extern unsigned int gnu_dev_minor (unsigned long long int __dev)
     ;

extern unsigned long long int gnu_dev_makedev (unsigned int __major,
					       unsigned int __minor)
     ;





  





  





  
	  
	  




/* Access the functions with their traditional names.  */







#line 134 "/usr/include/sys/types.h" 2





typedef __blksize_t blksize_t;



/* Types from the Large File Support interface.  */


typedef __blkcnt_t blkcnt_t;	 /* Type to count number of disk blocks.  */



typedef __fsblkcnt_t fsblkcnt_t; /* Type to count file system blocks.  */



typedef __fsfilcnt_t fsfilcnt_t; /* Type to count file system inodes.  */
























/* Now add the thread types.  */


#line 1 "/usr/include/bits/pthreadtypes.h" 1
/* Copyright (C) 2002,2003,2004,2005,2006,2007 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ulrich Drepper <drepper@redhat.com>, 2002.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */





#line 1 "/usr/include/bits/wordsize.h" 1

#line 23 "/usr/include/bits/pthreadtypes.h" 2
























/* Thread identifiers.  The structure of the attribute type is not
   exposed on purpose.  */
typedef unsigned long int pthread_t;


typedef union
{
  char __size[36];
  long int __align;
} pthread_attr_t;





  
  


typedef struct __pthread_internal_slist
{
  struct __pthread_internal_slist *__next;
} __pthread_slist_t;



/* Data structures for mutex handling.  The structure of the attribute
   type is not exposed on purpose.  */
typedef union
{
  struct __pthread_mutex_s
  {
    int __lock;
    unsigned int __count;
    int __owner;

    

    /* KIND must stay at this position in the structure to maintain
       binary compatibility.  */
    int __kind;

    
    


    unsigned int __nusers;
     union
    {
      int __spins;
      __pthread_slist_t __list;
    };

  } __data;
  char __size[24];
  long int __align;
} pthread_mutex_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;


/* Data structure for conditional variable handling.  The structure of
   the attribute type is not exposed on purpose.  */
typedef union
{
  struct
  {
    int __lock;
    unsigned int __futex;
     unsigned long long int __total_seq;
     unsigned long long int __wakeup_seq;
     unsigned long long int __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[48];
   long long int __align;
} pthread_cond_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;


/* Keys for thread-specific data */
typedef unsigned int pthread_key_t;


/* Once-only execution */
typedef int pthread_once_t;



/* Data structure for read-write lock variable handling.  The
   structure of the attribute type is not exposed on purpose.  */
typedef union
{

  
  
    
    
    
    
    
    
    
    
    
    
    

    
  

  struct
  {
    int __lock;
    unsigned int __nr_readers;
    unsigned int __readers_wakeup;
    unsigned int __writer_wakeup;
    unsigned int __nr_readers_queued;
    unsigned int __nr_writers_queued;
    /* FLAGS must stay at this position in the structure to maintain
       binary compatibility.  */
    unsigned char __flags;
    unsigned char __shared;
    unsigned char __pad1;
    unsigned char __pad2;
    int __writer;
  } __data;

  char __size[32];
  long int __align;
} pthread_rwlock_t;

typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;




/* POSIX spinlock data type.  */
typedef volatile int pthread_spinlock_t;


/* POSIX barriers data type.  The structure of the type is
   deliberately not exposed.  */
typedef union
{
  char __size[20];
  long int __align;
} pthread_barrier_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;




/* Extra attributes for the cleanup functions.  */





#line 155 "/usr/include/sys/types.h" 2






#line 37 "/usr/include/H5public.h" 2



#line 1 "/usr/include/limits.h" 1
/* Copyright (C) 1991, 1992, 1996, 1997, 1998, 1999, 2000, 2005
   Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

/*
 *	ISO C99 Standard: 7.10/5.2.4.2.1 Sizes of integer types	<limits.h>
 */





#line 1 "/usr/include/features.h" 1

#line 27 "/usr/include/limits.h" 2


/* Maximum length of any multibyte character in any locale.
   We define this value here since the gcc header does not define
   the correct value.  */



/* If we are not using GNU CC we have to define all the symbols ourself.
   Otherwise use gcc's definitions (see below).  */


/* We only protect from multiple inclusion here, because all the other
   #include's protect themselves, and in GCC 2 we may #include_next through
   multiple copies of this file before we get to GCC's.  */




#line 1 "/usr/include/bits/wordsize.h" 1

#line 42 "/usr/include/limits.h" 2

/* We don't have #include_next.
   Define ANSI <limits.h> for standard 32-bit words.  */

/* These assume 8-bit `char's, 16-bit `short int's,
   and 32-bit `int's and `long int's.  */

/* Number of bits in a `char'.	*/


/* Minimum and maximum values a `signed char' can hold.  */



/* Maximum value an `unsigned char' can hold.  (Minimum is 0.)  */


/* Minimum and maximum values a `char' can hold.  */








/* Minimum and maximum values a `signed short int' can hold.  */



/* Maximum value an `unsigned short int' can hold.  (Minimum is 0.)  */


/* Minimum and maximum values a `signed int' can hold.  */



/* Maximum value an `unsigned int' can hold.  (Minimum is 0.)  */


/* Minimum and maximum values a `signed long int' can hold.  */







/* Maximum value an `unsigned long int' can hold.  (Minimum is 0.)  */








/* Minimum and maximum values a `signed long long int' can hold.  */



/* Maximum value an `unsigned long long int' can hold.  (Minimum is 0.)  */









 /* Get the compiler's limits.h, which defines almost all the ISO constants.

    We put this #include_next outside the double inclusion check because
    it should be possible to include this file more than once and still get
    the definitions from gcc's header.  */

/* `_GCC_LIMITS_H_' is what GCC's file defines.  */

#line 1 "/usr/include/limits.h" 1

#line 92 "/usr/include/limits.h" 2


/* The <limits.h> files in some gcc versions don't define LLONG_MIN,
   LLONG_MAX, and ULLONG_MAX.  Instead only the values gcc defined for
   ages are available.  */













/* POSIX adds things to <limits.h>.  */

#line 1 "/usr/include/bits/posix1_lim.h" 1
/* Copyright (C) 1991-1993,96,98,2000-2003,2004 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

/*
 *	POSIX Standard: 2.9.2 Minimum Values	Added to <limits.h>
 *
 *	Never include this file directly; use <limits.h> instead.
 */





/* These are the standard-mandated minimum values.  */

/* Minimum number of operations in one list I/O call.  */


/* Minimal number of outstanding asynchronous I/O operations.  */


/* Maximum length of arguments to `execve', including environment.  */


/* Maximum simultaneous processes per real user ID.  */






/* Minimal number of timer expiration overruns.  */


/* Maximum length of a host name (not including the terminating null)
   as returned from the GETHOSTNAME function.  */


/* Maximum link count of a file.  */


/* Maximum length of login name.  */


/* Number of bytes in a terminal canonical input queue.  */


/* Number of bytes for which space will be
   available in a terminal input queue.  */


/* Maximum number of message queues open for a process.  */


/* Maximum number of supported message priorities.  */


/* Number of bytes in a filename.  */


/* Number of simultaneous supplementary group IDs per process.  */






/* Number of files one process can have open at once.  */












/* Number of bytes in a pathname.  */


/* Number of bytes than can be written atomically to a pipe.  */


/* The number of repeated occurrences of a BRE permitted by the
   REGEXEC and REGCOMP functions when using the interval notation.  */


/* Minimal number of realtime signals reserved for the application.  */


/* Number of semaphores a process can have.  */


/* Maximal value of a semaphore.  */


/* Number of pending realtime signals.  */


/* Largest value of a `ssize_t'.  */


/* Number of streams a process can have open at once.  */


/* The number of bytes in a symbolic link.  */


/* The number of symbolic links that can be traversed in the
   resolution of a pathname in the absence of a loop.  */


/* Number of timer for a process.  */


/* Maximum number of characters in a tty name.  */


/* Maximum length of a timezone name (element of `tzname').  */














/* Maximum clock resolution in nanoseconds.  */



/* Get the implementation-specific values for the above.  */

#line 1 "/usr/include/bits/local_lim.h" 1
/* Minimum guaranteed maximum values for system limits.  Linux version.
   Copyright (C) 1993-1998,2000,2002-2004,2008 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation; either version 2.1 of the
   License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* The kernel header pollutes the namespace with the NR_OPEN symbol
   and defines LINK_MAX although filesystems have different maxima.  A
   similar thing is true for OPEN_MAX: the limit can be changed at
   runtime and therefore the macro must not be defined.  Remove this
   after including the header if necessary.  */













/* The kernel sources contain a file with all the needed information.  */

#line 1 "/usr/include/linux/limits.h" 1





















#line 29 "/usr/include/bits/local_lim.h" 2

/* Have to remove NR_OPEN?  */




/* Have to remove LINK_MAX?  */




/* Have to remove OPEN_MAX?  */




/* Have to remove ARG_MAX?  */





/* The number of data keys per process.  */

/* This is the value this implementation supports.  */


/* Controlling the iterations of destructors for thread-specific data.  */

/* Number of iterations this implementation does.  */


/* The number of threads per process.  */

/* We have no predefined limit on the number of threads.  */


/* Maximum amount by which a process can descrease its asynchronous I/O
   priority level.  */


/* Minimum size for a thread.  We are free to choose a reasonable value.  */


/* Maximum number of timer expiration overruns.  */


/* Maximum tty name length.  */


/* Maximum login name length.  This is arbitrary.  */


/* Maximum host name length.  */


/* Maximum message queue priority level.  */


/* Maximum value the semaphore can have.  */


#line 106 "/usr/include/bits/posix1_lim.h" 2







/* This value is a guaranteed minimum maximum.
   The current maximum can be got from `sysconf'.  */







#line 101 "/usr/include/limits.h" 2




#line 1 "/usr/include/bits/posix2_lim.h" 1
/* Copyright (C) 1991, 1996, 1999, 2000, 2001 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

/*
 * Never include this file directly; include <limits.h> instead.
 */





/* The maximum `ibase' and `obase' values allowed by the `bc' utility.  */


/* The maximum number of elements allowed in an array by the `bc' utility.  */


/* The maximum `scale' value allowed by the `bc' utility.  */


/* The maximum length of a string constant accepted by the `bc' utility.  */


/* The maximum number of weights that can be assigned to an entry of
   the LC_COLLATE `order' keyword in the locale definition file.  */


/* The maximum number of expressions that can be nested
   within parentheses by the `expr' utility.  */


/* The maximum length, in bytes, of an input line.  */


/* The maximum number of repeated occurrences of a regular expression
   permitted when using the interval notation `\{M,N\}'.  */


/* The maximum number of bytes in a character class name.  We have no
   fixed limit, 2048 is a high number.  */



/* These values are implementation-specific,
   and may vary within the implementation.
   Their precise values can be obtained from sysconf.  */


























/* This value is defined like this in regex.h.  */




#line 103 "/usr/include/limits.h" 2






#line 38 "/usr/include/H5public.h" 2




#line 1 "/usr/include/stdint.h" 1
/* Copyright (C) 1997,1998,1999,2000,2001,2006 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

/*
 *	ISO C99: 7.18 Integer types <stdint.h>
 */





#line 1 "/usr/include/features.h" 1

#line 26 "/usr/include/stdint.h" 2

#line 1 "/usr/include/bits/wchar.h" 1
/* wchar_t type related definitions.
   Copyright (C) 2000 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */




/* Use GCC's __WCHAR_MAX__ when available.  */






/* GCC may also define __WCHAR_UNSIGNED__.
   Use L'\0' to give the expression the correct (unsigned) type.  */













#line 27 "/usr/include/stdint.h" 2

#line 1 "/usr/include/bits/wordsize.h" 1

#line 28 "/usr/include/stdint.h" 2

/* Exact integral types.  */

/* Signed.  */

/* There is some amount of overlap with <sys/types.h> as known by inet code */













/* Unsigned.  */
typedef unsigned char		uint8_t;
typedef unsigned short int	uint16_t;

typedef unsigned int		uint32_t;






typedef unsigned long long int	uint64_t;



/* Small types.  */

/* Signed.  */
typedef signed char		int_least8_t;
typedef short int		int_least16_t;
typedef int			int_least32_t;




typedef long long int		int_least64_t;


/* Unsigned.  */
typedef unsigned char		uint_least8_t;
typedef unsigned short int	uint_least16_t;
typedef unsigned int		uint_least32_t;




typedef unsigned long long int	uint_least64_t;



/* Fast types.  */

/* Signed.  */
typedef signed char		int_fast8_t;





typedef int			int_fast16_t;
typedef int			int_fast32_t;

typedef long long int		int_fast64_t;


/* Unsigned.  */
typedef unsigned char		uint_fast8_t;





typedef unsigned int		uint_fast16_t;
typedef unsigned int		uint_fast32_t;

typedef unsigned long long int	uint_fast64_t;



/* Types for `void *' pointers.  */








typedef int			intptr_t;


typedef unsigned int		uintptr_t;



/* Largest integral types.  */





typedef long long int		intmax_t;

typedef unsigned long long int	uintmax_t;



/* The ISO C99 standard specifies that in C++ implementations these
   macros should only be defined if explicitly requested.  */










/* Limits of integral types.  */

/* Minimum of signed integral types.  */




/* Maximum of signed integral types.  */





/* Maximum of unsigned integral types.  */






/* Minimum of signed integral types having a minimum size.  */




/* Maximum of signed integral types having a minimum size.  */





/* Maximum of unsigned integral types having a minimum size.  */






/* Minimum of fast signed integral types having a minimum size.  */









/* Maximum of fast signed integral types having a minimum size.  */










/* Maximum of fast unsigned integral types having a minimum size.  */











/* Values to test for integral types holding `void *' pointer.  */











/* Minimum for largest signed integral type.  */

/* Maximum for largest signed integral type.  */


/* Maximum for largest unsigned integral type.  */



/* Limits of other integer types.  */

/* Limits of `ptrdiff_t' type.  */








/* Limits of `sig_atomic_t'.  */



/* Limit of `size_t' type.  */






/* Limits of `wchar_t'.  */

/* These constants might also be defined in <wchar.h>.  */




/* Limits of `wint_t'.  */






/* The ISO C99 standard specifies that in C++ implementations these
   should only be defined if explicitly requested.  */


/* Signed.  */









/* Unsigned.  */









/* Maximal type.  */












#line 39 "/usr/include/H5public.h" 2




#line 1 "/usr/include/inttypes.h" 1
/* Copyright (C) 1997-2001, 2004, 2007 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

/*
 *	ISO C99: 7.8 Format conversion of integer types	<inttypes.h>
 */





#line 1 "/usr/include/features.h" 1

#line 26 "/usr/include/inttypes.h" 2
/* Get the type definitions.  */

#line 1 "/usr/include/stdint.h" 1

#line 28 "/usr/include/inttypes.h" 2

/* Get a definition for wchar_t.  But we must not define wchar_t itself.  */








#line 1 "/usr/include/inttypes.h" 1
typedef wchar_t __gwchar_t;





/* The ISO C99 standard specifies that these macros must only be
   defined if explicitly requested.  */










/* Macros for printing format specifiers.  */

/* Decimal notation.  */































/* Octal notation.  */















/* Unsigned integers.  */















/* lowercase hexadecimal notation.  */















/* UPPERCASE hexadecimal notation.  */
















/* Macros for printing `intmax_t' and `uintmax_t'.  */








/* Macros for printing `intptr_t' and `uintptr_t'.  */








/* Macros for scanning format specifiers.  */

/* Signed decimal notation.  */















/* Signed decimal notation.  */















/* Unsigned decimal notation.  */















/* Octal notation.  */















/* Hexadecimal notation.  */
















/* Macros for scanning `intmax_t' and `uintmax_t'.  */






/* Macros for scaning `intptr_t' and `uintptr_t'.  */















  
    
    
  



/* We have to define the `uintmax_t' type using `lldiv_t'.  */
typedef struct
  {
    long long int quot;		/* Quotient.  */
    long long int rem;		/* Remainder.  */
  } imaxdiv_t;




/* Compute absolute value of N.  */
extern intmax_t imaxabs (intmax_t __n)  ;

/* Return the `imaxdiv_t' representation of the value of NUMER over DENOM. */
extern imaxdiv_t imaxdiv (intmax_t __numer, intmax_t __denom)
       ;

/* Like `strtol' but convert to `intmax_t'.  */
extern intmax_t strtoimax (__const char * __nptr,
			   char ** __endptr, int __base) ;

/* Like `strtoul' but convert to `uintmax_t'.  */
extern uintmax_t strtoumax (__const char * __nptr,
			    char **  __endptr, int __base) ;

/* Like `wcstol' but convert to `intmax_t'.  */
extern intmax_t wcstoimax (__const __gwchar_t * __nptr,
			   __gwchar_t ** __endptr, int __base)
     ;

/* Like `wcstoul' but convert to `uintmax_t'.  */
extern uintmax_t wcstoumax (__const __gwchar_t * __nptr,
			    __gwchar_t **  __endptr, int __base)
     ;






				   
				   
  



		  

  



					     
					     
					     
  



		  

  



				   
				   
  



		  

  



					     
					     
					     
					     
  



		  

  






					 
					 
  



		  

  




						   
						   
						   
						   
						   
  



		  

  




					 
					 
					 
  



		  

  





						   
						   
						   
						   
						   
  



		  

  









#line 40 "/usr/include/H5public.h" 2



#line 1 "/usr/include/H5public.h" 1






/* Include the Windows API adapter header early */

#line 1 "/usr/include/H5api_adpt.h" 1
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright by The HDF Group.                                               *
 * Copyright by the Board of Trustees of the University of Illinois.         *
 * All rights reserved.                                                      *
 *                                                                           *
 * This file is part of HDF5.  The full HDF5 copyright notice, including     *
 * terms governing use, modification, and redistribution, is contained in    *
 * the files COPYING and Copyright.html.  COPYING can be found at the root   *
 * of the source code distribution tree; Copyright.html can be found at the  *
 * root level of an installed copy of the electronic HDF5 document set and   *
 * is linked from the top-level documents page.  It can also be found at     *
 * http://hdfgroup.org/HDF5/doc/Copyright.html.  If you do not have          *
 * access to either file, you may request a copy from help@hdfgroup.org.     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
 * H5api_adpt.h
 * Used for the HDF5 dll project
 * Created by Patrick Lu on 1/12/99
 */

















































































/* Added to export or to import C++ APIs - BMR (02-15-2002) */


























#line 45 "/usr/include/H5public.h" 2





/* Version numbers */




				/* Empty string for real releases.           */





/*
 * Status return values.  Failed integer functions in HDF5 result almost
 * always in a negative value (unsigned failing functions sometimes return
 * zero for failure) while successfull return is non-negative (often zero).
 * The negative failure value is most commonly -1, but don't bet on it.  The
 * proper way to detect failure is something like:
 *
 * 	if((dset = H5Dopen2(file, name)) < 0)
 *	    fprintf(stderr, "unable to open the requested dataset\n");
 */
typedef int herr_t;


/*
 * Boolean type.  Successful return values are zero (false) or positive
 * (true). The typical true value is 1 but don't bet on it.  Boolean
 * functions cannot fail.  Functions that return `htri_t' however return zero
 * (false), positive (true), or negative (failure). The proper way to test
 * for truth from a htri_t function is:
 *
 * 	if ((retval = H5Tcommitted(type))>0) {
 *	    printf("data type is committed\n");
 *	} else if (!retval) {
 * 	    printf("data type is not committed\n");
 *	} else {
 * 	    printf("error determining whether data type is committed\n");
 *	}
 */
typedef unsigned int hbool_t;
typedef int htri_t;

/* Define the ssize_t type if it not is defined */

















/*
 * The sizes of file objects have their own types defined here, use a 64-bit
 * type.
 */

typedef unsigned long long 	hsize_t;
typedef signed long long	hssize_t;






/*
 * File addresses have their own types.
 */

    typedef uint64_t                haddr_t;






    






    






    



















/* uint32_t type is used for creation order field for messages.  It may be
 * defined in Posix.1g, otherwise it is defined here.
 */


    



    



    






/* int64_t type is used for creation order field for links.  It may be
 * defined in Posix.1g, otherwise it is defined here.
 */


    



    



    






/* uint64_t type is used for fields for H5O_info_t.  It may be
 * defined in Posix.1g, otherwise it is defined here.
 */


    



    



    






/* Default value for all property list classes */


/* Common iteration orders */
typedef enum {
    H5_ITER_UNKNOWN = -1,       /* Unknown order */
    H5_ITER_INC,                /* Increasing order */
    H5_ITER_DEC,                /* Decreasing order */
    H5_ITER_NATIVE,             /* No particular order, whatever is fastest */
    H5_ITER_N		        /* Number of iteration orders */
} H5_iter_order_t;

/* Iteration callback values */
/* (Actually, any postive value will cause the iterator to stop and pass back
 *      that positive value to the function that called the iterator)
 */




/*
 * The types of indices on links in groups/attributes on objects.
 * Primarily used for "<do> <foo> by index" routines and for iterating over
 * links in groups/attributes on objects.
 */
typedef enum H5_index_t {
    H5_INDEX_UNKNOWN = -1,	/* Unknown index type			*/
    H5_INDEX_NAME,		/* Index on names 			*/
    H5_INDEX_CRT_ORDER,		/* Index on creation order 		*/
    H5_INDEX_N			/* Number of indices defined 		*/
} H5_index_t;

/*
 * Storage info struct used by H5O_info_t and H5F_info_t
 */
typedef struct H5_ih_info_t {
    hsize_t     index_size;     /* btree and/or list */
    hsize_t     heap_size;
} H5_ih_info_t;

/* Functions in H5.c */
 herr_t H5open(void);
 herr_t H5close(void);
 herr_t H5dont_atexit(void);
 herr_t H5garbage_collect(void);
 herr_t H5set_free_list_limits (int reg_global_lim, int reg_list_lim,
                int arr_global_lim, int arr_list_lim, int blk_global_lim,
                int blk_list_lim);
 herr_t H5get_libversion(unsigned *majnum, unsigned *minnum,
				unsigned *relnum);
 herr_t H5check_version(unsigned majnum, unsigned minnum,
			       unsigned relnum);







#line 23 "/usr/include/H5Fpublic.h" 2

#line 1 "/usr/include/H5Cpublic.h" 1
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright by The HDF Group.                                               *
 * Copyright by the Board of Trustees of the University of Illinois.         *
 * All rights reserved.                                                      *
 *                                                                           *
 * This file is part of HDF5.  The full HDF5 copyright notice, including     *
 * terms governing use, modification, and redistribution, is contained in    *
 * the files COPYING and Copyright.html.  COPYING can be found at the root   *
 * of the source code distribution tree; Copyright.html can be found at the  *
 * root level of an installed copy of the electronic HDF5 document set and   *
 * is linked from the top-level documents page.  It can also be found at     *
 * http://hdfgroup.org/HDF5/doc/Copyright.html.  If you do not have          *
 * access to either file, you may request a copy from help@hdfgroup.org.     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*-------------------------------------------------------------------------
 *
 * Created:	H5Cproto.h
 *              June 4, 2005
 *              John Mainzer
 *
 * Purpose:     Public include file for cache functions.
 *
 * Modifications:
 *
 *-------------------------------------------------------------------------
 */



/* Public headers needed by this file */

#line 1 "/usr/include/H5public.h" 1

#line 32 "/usr/include/H5Cpublic.h" 2





enum H5C_cache_incr_mode
{
    H5C_incr__off,
    H5C_incr__threshold
};

enum H5C_cache_flash_incr_mode
{
    H5C_flash_incr__off,
    H5C_flash_incr__add_space
};

enum H5C_cache_decr_mode
{
    H5C_decr__off,
    H5C_decr__threshold,
    H5C_decr__age_out,
    H5C_decr__age_out_with_threshold
};






#line 24 "/usr/include/H5Fpublic.h" 2

#line 1 "/usr/include/H5ACpublic.h" 1
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright by The HDF Group.                                               *
 * Copyright by the Board of Trustees of the University of Illinois.         *
 * All rights reserved.                                                      *
 *                                                                           *
 * This file is part of HDF5.  The full HDF5 copyright notice, including     *
 * terms governing use, modification, and redistribution, is contained in    *
 * the files COPYING and Copyright.html.  COPYING can be found at the root   *
 * of the source code distribution tree; Copyright.html can be found at the  *
 * root level of an installed copy of the electronic HDF5 document set and   *
 * is linked from the top-level documents page.  It can also be found at     *
 * http://hdfgroup.org/HDF5/doc/Copyright.html.  If you do not have          *
 * access to either file, you may request a copy from help@hdfgroup.org.     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*-------------------------------------------------------------------------
 *
 * Created:             H5ACpublic.h
 *                      Jul 10 1997
 *                      Robb Matzke <matzke@llnl.gov>
 *
 * Purpose:             Public include file for cache functions.
 *
 * Modifications:
 *
 *-------------------------------------------------------------------------
 */



/* Public headers needed by this file */

#line 1 "/usr/include/H5public.h" 1

#line 32 "/usr/include/H5ACpublic.h" 2

#line 1 "/usr/include/H5Cpublic.h" 1

#line 33 "/usr/include/H5ACpublic.h" 2







/****************************************************************************
 *
 * structure H5AC_cache_config_t
 *
 * H5AC_cache_config_t is a public structure intended for use in public APIs.
 * At least in its initial incarnation, it is basicaly a copy of struct
 * H5C_auto_size_ctl_t, minus the report_fcn field, and plus the
 * dirty_bytes_threshold field.
 *
 * The report_fcn field is omitted, as including it would require us to
 * make H5C_t structure public.
 *
 * The dirty_bytes_threshold field does not appear in H5C_auto_size_ctl_t,
 * as synchronization between caches on different processes is handled at
 * the H5AC level, not at the level of H5C.  Note however that there is
 * considerable interaction between this value and the other fields in this
 * structure.
 *
 * Similarly, the open_trace_file, close_trace_file, and trace_file_name
 * fields do not appear in H5C_auto_size_ctl_t, as most trace file
 * issues are handled at the H5AC level.  The one exception is storage of
 * the pointer to the trace file, which is handled by H5C.
 *
 * The structure is in H5ACpublic.h as we may wish to allow different
 * configuration options for metadata and raw data caches.
 *
 * The fields of the structure are discussed individually below:
 *
 * version: Integer field containing the version number of this version
 *      of the H5AC_cache_config_t structure.  Any instance of
 *      H5AC_cache_config_t passed to the cache must have a known
 *      version number, or an error will be flagged.
 *
 * rpt_fcn_enabled: Boolean field used to enable and disable the default
 *	reporting function.  This function is invoked every time the
 *	automatic cache resize code is run, and reports on its activities.
 *
 *	This is a debugging function, and should normally be turned off.
 *
 * open_trace_file: Boolean field indicating whether the trace_file_name
 * 	field should be used to open a trace file for the cache.
 *
 * 	The trace file is a debuging feature that allow the capture of
 * 	top level metadata cache requests for purposes of debugging and/or
 * 	optimization.  This field should normally be set to FALSE, as
 * 	trace file collection imposes considerable overhead.
 *
 * 	This field should only be set to TRUE when the trace_file_name
 * 	contains the full path of the desired trace file, and either
 * 	there is no open trace file on the cache, or the close_trace_file
 * 	field is also TRUE.
 *
 * close_trace_file: Boolean field indicating whether the current trace
 * 	file (if any) should be closed.
 *
 * 	See the above comments on the open_trace_file field.  This field
 * 	should be set to FALSE unless there is an open trace file on the
 * 	cache that you wish to close.
 *
 * trace_file_name: Full path of the trace file to be opened if the
 * 	open_trace_file field is TRUE.
 *
 * 	In the parallel case, an ascii representation of the mpi rank of
 * 	the process will be appended to the file name to yield a unique
 * 	trace file name for each process.
 *
 * 	The length of the path must not exceed H5AC__MAX_TRACE_FILE_NAME_LEN
 * 	characters.
 *
 * evictions_enabled:  Boolean field used to either report the current
 * 	evictions enabled status of the cache, or to set the cache's
 *	evictions enabled status.
 *
 * 	In general, the metadata cache should always be allowed to
 * 	evict entries.  However, in some cases it is advantageous to
 * 	disable evictions briefly, and thereby postpone metadata
 * 	writes.  However, this must be done with care, as the cache
 * 	can grow quickly.  If you do this, re-enable evictions as
 * 	soon as possible and monitor cache size.
 *
 * 	At present, evictions can only be disabled if automatic
 * 	cache resizing is also disabled (that is, ( incr_mode ==
 *	H5C_incr__off ) && ( decr_mode == H5C_decr__off )).  There
 *	is no logical reason why this should be so, but it simplifies
 *	implementation and testing, and I can't think of any reason
 *	why it would be desireable.  If you can think of one, I'll
 *	revisit the issue.
 *
 * set_initial_size: Boolean flag indicating whether the size of the
 *      initial size of the cache is to be set to the value given in
 *      the initial_size field.  If set_initial_size is FALSE, the
 *      initial_size field is ignored.
 *
 * initial_size: If enabled, this field contain the size the cache is
 *      to be set to upon receipt of this structure.  Needless to say,
 *      initial_size must lie in the closed interval [min_size, max_size].
 *
 * min_clean_fraction: double in the range 0 to 1 indicating the fraction
 *      of the cache that is to be kept clean.  This field is only used
 *      in parallel mode.  Typical values are 0.1 to 0.5.
 *
 * max_size: Maximum size to which the cache can be adjusted.  The
 *      supplied value must fall in the closed interval
 *      [MIN_MAX_CACHE_SIZE, MAX_MAX_CACHE_SIZE].  Also, max_size must
 *      be greater than or equal to min_size.
 *
 * min_size: Minimum size to which the cache can be adjusted.  The
 *      supplied value must fall in the closed interval
 *      [H5C__MIN_MAX_CACHE_SIZE, H5C__MAX_MAX_CACHE_SIZE].  Also, min_size
 *      must be less than or equal to max_size.
 *
 * epoch_length: Number of accesses on the cache over which to collect
 *      hit rate stats before running the automatic cache resize code,
 *      if it is enabled.
 *
 *      At the end of an epoch, we discard prior hit rate data and start
 *      collecting afresh.  The epoch_length must lie in the closed
 *      interval [H5C__MIN_AR_EPOCH_LENGTH, H5C__MAX_AR_EPOCH_LENGTH].
 *
 *
 * Cache size increase control fields:
 *
 * incr_mode: Instance of the H5C_cache_incr_mode enumerated type whose
 *      value indicates how we determine whether the cache size should be
 *      increased.  At present there are two possible values:
 *
 *      H5C_incr__off:  Don't attempt to increase the size of the cache
 *              automatically.
 *
 *              When this increment mode is selected, the remaining fields
 *              in the cache size increase section ar ignored.
 *
 *      H5C_incr__threshold: Attempt to increase the size of the cache
 *              whenever the average hit rate over the last epoch drops
 *              below the value supplied in the lower_hr_threshold
 *              field.
 *
 *              Note that this attempt will fail if the cache is already
 *              at its maximum size, or if the cache is not already using
 *              all available space.
 *
 *      Note that you must set decr_mode to H5C_incr__off if you
 *      disable metadata cache entry evictions.
 *
 * lower_hr_threshold: Lower hit rate threshold.  If the increment mode
 *      (incr_mode) is H5C_incr__threshold and the hit rate drops below the
 *      value supplied in this field in an epoch, increment the cache size by
 *      size_increment.  Note that cache size may not be incremented above
 *      max_size, and that the increment may be further restricted by the
 *      max_increment field if it is enabled.
 *
 *      When enabled, this field must contain a value in the range [0.0, 1.0].
 *      Depending on the incr_mode selected, it may also have to be less than
 *      upper_hr_threshold.
 *
 * increment:  Double containing the multiplier used to derive the new
 *      cache size from the old if a cache size increment is triggered.
 *      The increment must be greater than 1.0, and should not exceed 2.0.
 *
 *      The new cache size is obtained my multiplying the current max cache
 *      size by the increment, and then clamping to max_size and to stay
 *      within the max_increment as necessary.
 *
 * apply_max_increment:  Boolean flag indicating whether the max_increment
 *      field should be used to limit the maximum cache size increment.
 *
 * max_increment: If enabled by the apply_max_increment field described
 *      above, this field contains the maximum number of bytes by which the
 *      cache size can be increased in a single re-size.
 *
 * flash_incr_mode:  Instance of the H5C_cache_flash_incr_mode enumerated
 *      type whose value indicates whether and by which algorithm we should
 *      make flash increases in the size of the cache to accomodate insertion
 *      of large entries and large increases in the size of a single entry.
 *
 *      The addition of the flash increment mode was occasioned by performance
 *      problems that appear when a local heap is increased to a size in excess
 *      of the current cache size.  While the existing re-size code dealt with
 *      this eventually, performance was very bad for the remainder of the
 *      epoch.
 *
 *      At present, there are two possible values for the flash_incr_mode:
 *
 *      H5C_flash_incr__off:  Don't perform flash increases in the size of
 *              the cache.
 *
 *      H5C_flash_incr__add_space:  Let x be either the size of a newly
 *              newly inserted entry, or the number of bytes by which the
 *              size of an existing entry has been increased.
 *
 *              If
 *                      x > flash_threshold * current max cache size,
 *
 *              increase the current maximum cache size by x * flash_multiple
 *              less any free space in the cache, and star a new epoch.  For
 *              now at least, pay no attention to the maximum increment.
 *
 *      In both of the above cases, the flash increment pays no attention to
 *      the maximum increment (at least in this first incarnation), but DOES
 *      stay within max_size.
 *
 *      With a little thought, it should be obvious that the above flash
 *      cache size increase algorithm is not sufficient for all circumstances --
 *      for example, suppose the user round robins through
 *      (1/flash_threshold) +1 groups, adding one data set to each on each
 *      pass.  Then all will increase in size at about the same time, requiring
 *      the max cache size to at least double to maintain acceptable
 *      performance, however the above flash increment algorithm will not be
 *      triggered.
 *
 *      Hopefully, the add space algorithms detailed above will be sufficient
 *      for the performance problems encountered to date.  However, we should
 *      expect to revisit the issue.
 *
 * flash_multiple: Double containing the multiple described above in the
 *      H5C_flash_incr__add_space section of the discussion of the
 *      flash_incr_mode section.  This field is ignored unless flash_incr_mode
 *      is H5C_flash_incr__add_space.
 *
 * flash_threshold: Double containing the factor by which current max cache size
 *      is multiplied to obtain the size threshold for the add_space flash
 *      increment algorithm.  The field is ignored unless flash_incr_mode is
 *      H5C_flash_incr__add_space.
 *
 *
 *
 * Cache size decrease control fields:
 *
 * decr_mode: Instance of the H5C_cache_decr_mode enumerated type whose
 *      value indicates how we determine whether the cache size should be
 *      decreased.  At present there are four possibilities.
 *
 *      H5C_decr__off:  Don't attempt to decrease the size of the cache
 *              automatically.
 *
 *              When this increment mode is selected, the remaining fields
 *              in the cache size decrease section are ignored.
 *
 *      H5C_decr__threshold: Attempt to decrease the size of the cache
 *              whenever the average hit rate over the last epoch rises
 *              above the value supplied in the upper_hr_threshold
 *              field.
 *
 *      H5C_decr__age_out:  At the end of each epoch, search the cache for
 *              entries that have not been accessed for at least the number
 *              of epochs specified in the epochs_before_eviction field, and
 *              evict these entries.  Conceptually, the maximum cache size
 *              is then decreased to match the new actual cache size.  However,
 *              this reduction may be modified by the min_size, the
 *              max_decrement, and/or the empty_reserve.
 *
 *      H5C_decr__age_out_with_threshold:  Same as age_out, but we only
 *              attempt to reduce the cache size when the hit rate observed
 *              over the last epoch exceeds the value provided in the
 *              upper_hr_threshold field.
 *
 *      Note that you must set decr_mode to H5C_decr__off if you
 *      disable metadata cache entry evictions.
 *
 * upper_hr_threshold: Upper hit rate threshold.  The use of this field
 *      varies according to the current decr_mode:
 *
 *      H5C_decr__off or H5C_decr__age_out:  The value of this field is
 *              ignored.
 *
 *      H5C_decr__threshold:  If the hit rate exceeds this threshold in any
 *              epoch, attempt to decrement the cache size by size_decrement.
 *
 *              Note that cache size may not be decremented below min_size.
 *
 *              Note also that if the upper_threshold is 1.0, the cache size
 *              will never be reduced.
 *
 *      H5C_decr__age_out_with_threshold:  If the hit rate exceeds this
 *              threshold in any epoch, attempt to reduce the cache size
 *              by evicting entries that have not been accessed for more
 *              than the specified number of epochs.
 *
 * decrement: This field is only used when the decr_mode is
 *      H5C_decr__threshold.
 *
 *      The field is a double containing the multiplier used to derive the
 *      new cache size from the old if a cache size decrement is triggered.
 *      The decrement must be in the range 0.0 (in which case the cache will
 *      try to contract to its minimum size) to 1.0 (in which case the
 *      cache will never shrink).
 *
 * apply_max_decrement:  Boolean flag used to determine whether decrements
 *      in cache size are to be limited by the max_decrement field.
 *
 * max_decrement: Maximum number of bytes by which the cache size can be
 *      decreased in a single re-size.  Note that decrements may also be
 *      restricted by the min_size of the cache, and (in age out modes) by
 *      the empty_reserve field.
 *
 * epochs_before_eviction:  Integer field used in H5C_decr__age_out and
 *      H5C_decr__age_out_with_threshold decrement modes.
 *
 *      This field contains the number of epochs an entry must remain
 *      unaccessed before it is evicted in an attempt to reduce the
 *      cache size.  If applicable, this field must lie in the range
 *      [1, H5C__MAX_EPOCH_MARKERS].
 *
 * apply_empty_reserve:  Boolean field controlling whether the empty_reserve
 *      field is to be used in computing the new cache size when the
 *      decr_mode is H5C_decr__age_out or H5C_decr__age_out_with_threshold.
 *
 * empty_reserve:  To avoid a constant racheting down of cache size by small
 *      amounts in the H5C_decr__age_out and H5C_decr__age_out_with_threshold
 *      modes, this field allows one to require that any cache size
 *      reductions leave the specified fraction of unused space in the cache.
 *
 *      The value of this field must be in the range [0.0, 1.0].  I would
 *      expect typical values to be in the range of 0.01 to 0.1.
 *
 *
 * Parallel Configuration Fields:
 *
 * In PHDF5, all operations that modify metadata must be executed collectively.
 * We used to think that this was enough to ensure consistency across the
 * metadata caches, but since we allow processes to read metadata individually,
 * the order of dirty entries in the LRU list can vary across processes,
 * which can result in inconsistencies between the caches.
 *
 * To prevent this, only the metadata cache on process 0 is allowed to write
 * to file, and then only after synchronizing with the other caches.  After
 * it writes entries to file, it sends the base addresses of the now clean
 * entries to the other caches, so they can mark these entries clean as well.
 *
 * The different caches know when to synchronize caches by counting the
 * number of bytes of dirty metadata created by the collective operations
 * modifying metadata.  Whenever this count exceeds a user specified
 * threshold (see below), process 0 flushes down to its minimum clean size,
 * and then sends the list of newly cleaned entries to the other caches.
 *
 * dirty_bytes_threshold:  Threshold of dirty byte creation used to
 * 	synchronize updates between caches. (See above for outline and
 *	motivation.)
 *
 *	This value MUST be consistant across all processes accessing the
 *	file.  This field is ignored unless HDF5 has been compiled for
 *	parallel.
 *
 ****************************************************************************/



typedef struct H5AC_cache_config_t
{
    /* general configuration fields: */
    int                      version;

    hbool_t		     rpt_fcn_enabled;

    hbool_t		     open_trace_file;
    hbool_t                  close_trace_file;
    char                     trace_file_name[1024 + 1];

    hbool_t                  evictions_enabled;

    hbool_t                  set_initial_size;
    size_t                   initial_size;

    double                   min_clean_fraction;

    size_t                   max_size;
    size_t                   min_size;

    long int                 epoch_length;


    /* size increase control fields: */
    enum H5C_cache_incr_mode incr_mode;

    double                   lower_hr_threshold;

    double                   increment;

    hbool_t                  apply_max_increment;
    size_t                   max_increment;

    enum H5C_cache_flash_incr_mode      flash_incr_mode;
    double                              flash_multiple;
    double                              flash_threshold;


    /* size decrease control fields: */
    enum H5C_cache_decr_mode decr_mode;

    double                   upper_hr_threshold;

    double                   decrement;

    hbool_t                  apply_max_decrement;
    size_t                   max_decrement;

    int                      epochs_before_eviction;

    hbool_t                  apply_empty_reserve;
    double                   empty_reserve;


    /* parallel configuration fields: */
    int                      dirty_bytes_threshold;

} H5AC_cache_config_t;







#line 25 "/usr/include/H5Fpublic.h" 2

#line 1 "/usr/include/H5Ipublic.h" 1
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright by The HDF Group.                                               *
 * Copyright by the Board of Trustees of the University of Illinois.         *
 * All rights reserved.                                                      *
 *                                                                           *
 * This file is part of HDF5.  The full HDF5 copyright notice, including     *
 * terms governing use, modification, and redistribution, is contained in    *
 * the files COPYING and Copyright.html.  COPYING can be found at the root   *
 * of the source code distribution tree; Copyright.html can be found at the  *
 * root level of an installed copy of the electronic HDF5 document set and   *
 * is linked from the top-level documents page.  It can also be found at     *
 * http://hdfgroup.org/HDF5/doc/Copyright.html.  If you do not have          *
 * access to either file, you may request a copy from help@hdfgroup.org.     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
 * This file contains function prototypes for each exported function in
 * the H5I module.
 */



/* Public headers needed by this file */

#line 1 "/usr/include/H5public.h" 1

#line 24 "/usr/include/H5Ipublic.h" 2

/*
 * Library type values.  Start with `1' instead of `0' because it makes the
 * tracing output look better when hid_t values are large numbers.  Change the
 * TYPE_BITS in H5I.c if the MAXID gets larger than 32 (an assertion will
 * fail otherwise).
 *
 * When adding types here, add a section to the 'misc19' test in test/tmisc.c
 * to verify that the H5I{inc|dec|get}_ref() routines work correctly with in.
 *
 */
typedef enum H5I_type_t {
    H5I_UNINIT		= (-2), /*uninitialized type			    */
    H5I_BADID		= (-1),	/*invalid Type				    */
    H5I_FILE		= 1,	/*type ID for File objects		    */
    H5I_GROUP,		        /*type ID for Group objects		    */
    H5I_DATATYPE,	        /*type ID for Datatype objects		    */
    H5I_DATASPACE,	        /*type ID for Dataspace objects		    */
    H5I_DATASET,	        /*type ID for Dataset objects		    */
    H5I_ATTR,		        /*type ID for Attribute objects		    */
    H5I_REFERENCE,	        /*type ID for Reference objects		    */
    H5I_VFL,			/*type ID for virtual file layer	    */
    H5I_GENPROP_CLS,            /*type ID for generic property list classes */
    H5I_GENPROP_LST,            /*type ID for generic property lists        */
    H5I_ERROR_CLASS,            /*type ID for error classes		    */
    H5I_ERROR_MSG,              /*type ID for error messages		    */
    H5I_ERROR_STACK,            /*type ID for error stacks		    */
    H5I_NTYPES		        /*number of library types, MUST BE LAST!    */
} H5I_type_t;

/* Type of atoms to return to users */
typedef int hid_t;


/* An invalid object ID. This is also negative for error return. */


/*
 * Function for freeing objects. This function will be called with an object
 * ID type number and a pointer to the object. The function should free the
 * object and return non-negative to indicate that the object
 * can be removed from the ID type. If the function returns negative
 * (failure) then the object will remain in the ID type.
 */
typedef herr_t (*H5I_free_t)(void*);

/* Type of the function to compare objects & keys */
typedef int (*H5I_search_func_t)(void *obj, hid_t id, void *key);





/* Public API functions */

 hid_t H5Iregister(H5I_type_t type, const void *object);
 void *H5Iobject_verify(hid_t id, H5I_type_t id_type);
 void *H5Iremove_verify(hid_t id, H5I_type_t id_type);
 H5I_type_t H5Iget_type(hid_t id);
 hid_t H5Iget_file_id(hid_t id);
 ssize_t H5Iget_name(hid_t id, char *name/*out*/, size_t size);
 int H5Iinc_ref(hid_t id);
 int H5Idec_ref(hid_t id);
 int H5Iget_ref(hid_t id);
 H5I_type_t H5Iregister_type(size_t hash_size, unsigned reserved, H5I_free_t free_func);
 herr_t H5Iclear_type(H5I_type_t type, hbool_t force);
 herr_t H5Idestroy_type(H5I_type_t type);
 int H5Iinc_type_ref(H5I_type_t type);
 int H5Idec_type_ref(H5I_type_t type);
 int H5Iget_type_ref(H5I_type_t type);
 void *H5Isearch(H5I_type_t type, H5I_search_func_t func, void *key);
 herr_t H5Inmembers(H5I_type_t type, hsize_t *num_members);
 htri_t H5Itype_exists(H5I_type_t type);
 htri_t H5Iis_valid(hid_t id);







#line 26 "/usr/include/H5Fpublic.h" 2

/* When this header is included from a private header, don't make calls to H5check() */







/*
 * These are the bits that can be passed to the `flags' argument of
 * H5Fcreate() and H5Fopen(). Use the bit-wise OR operator (|) to combine
 * them as needed.  As a side effect, they call H5check_version() to make sure
 * that the application is compiled with a version of the hdf5 header files
 * which are compatible with the library to which the application is linked.
 * We're assuming that these constants are used rather early in the hdf5
 * session.
 *
 */







/* Value passed to H5Pset_elink_acc_flags to cause flags to be taken from the
 * parent file. */


/* Flags for H5Fget_obj_count() & H5Fget_obj_ids() calls */







                                        /* (as opposed to objects opened through any file ID accessing this file) */













/* The difference between a single file and a set of mounted files */
typedef enum H5F_scope_t {
    H5F_SCOPE_LOCAL	= 0,	/*specified file handle only		*/
    H5F_SCOPE_GLOBAL	= 1 	/*entire virtual file			*/
} H5F_scope_t;

/* Unlimited file size for H5Pset_external() */


/* How does file close behave?
 * H5F_CLOSE_DEFAULT - Use the degree pre-defined by underlining VFL
 * H5F_CLOSE_WEAK    - file closes only after all opened objects are closed
 * H5F_CLOSE_SEMI    - if no opened objects, file is close; otherwise, file
		       close fails
 * H5F_CLOSE_STRONG  - if there are opened objects, close them first, then
		       close file
 */
typedef enum H5F_close_degree_t {
    H5F_CLOSE_DEFAULT   = 0,
    H5F_CLOSE_WEAK      = 1,
    H5F_CLOSE_SEMI      = 2,
    H5F_CLOSE_STRONG    = 3
} H5F_close_degree_t;

/* Current "global" information about file */
/* (just size info currently) */
typedef struct H5F_info_t {
    hsize_t		super_ext_size;	/* Superblock extension size */
    struct {
	hsize_t		hdr_size;       /* Shared object header message header size */
	H5_ih_info_t	msgs_info;      /* Shared object header message index & heap size */
    } sohm;
} H5F_info_t;

/*
 * Types of allocation requests. The values larger than H5FD_MEM_DEFAULT
 * should not change other than adding new types to the end. These numbers
 * might appear in files.
 */
typedef enum H5F_mem_t {
    H5FD_MEM_NOLIST	= -1,			/*must be negative*/
    H5FD_MEM_DEFAULT	= 0,			/*must be zero*/
    H5FD_MEM_SUPER      = 1,
    H5FD_MEM_BTREE      = 2,
    H5FD_MEM_DRAW       = 3,
    H5FD_MEM_GHEAP      = 4,
    H5FD_MEM_LHEAP      = 5,
    H5FD_MEM_OHDR       = 6,

    H5FD_MEM_NTYPES				/*must be last*/
} H5F_mem_t;

/* Library's file format versions */
typedef enum H5F_libver_t {
    H5F_LIBVER_EARLIEST,        /* Use the earliest possible format for storing objects */
    H5F_LIBVER_LATEST           /* Use the latest possible format available for storing objects*/
} H5F_libver_t;





/* Functions in H5F.c */
 htri_t H5Fis_hdf5(const char *filename);
 hid_t  H5Fcreate(const char *filename, unsigned flags,
		  	  hid_t create_plist, hid_t access_plist);
 hid_t  H5Fopen(const char *filename, unsigned flags,
		        hid_t access_plist);
 hid_t  H5Freopen(hid_t file_id);
 herr_t H5Fflush(hid_t object_id, H5F_scope_t scope);
 herr_t H5Fclose(hid_t file_id);
 hid_t  H5Fget_create_plist(hid_t file_id);
 hid_t  H5Fget_access_plist(hid_t file_id);
 herr_t H5Fget_intent(hid_t file_id, unsigned * intent);
 ssize_t H5Fget_obj_count(hid_t file_id, unsigned types);
 ssize_t H5Fget_obj_ids(hid_t file_id, unsigned types, size_t max_objs, hid_t *obj_id_list);
 herr_t H5Fget_vfd_handle(hid_t file_id, hid_t fapl, void **file_handle);
 herr_t H5Fmount(hid_t loc, const char *name, hid_t child, hid_t plist);
 herr_t H5Funmount(hid_t loc, const char *name);
 hssize_t H5Fget_freespace(hid_t file_id);
 herr_t H5Fget_filesize(hid_t file_id, hsize_t *size);
 herr_t H5Fget_mdc_config(hid_t file_id,
				H5AC_cache_config_t * config_ptr);
 herr_t H5Fset_mdc_config(hid_t file_id,
				H5AC_cache_config_t * config_ptr);
 herr_t H5Fget_mdc_hit_rate(hid_t file_id, double * hit_rate_ptr);
 herr_t H5Fget_mdc_size(hid_t file_id,
                              size_t * max_size_ptr,
                              size_t * min_clean_size_ptr,
                              size_t * cur_size_ptr,
                              int * cur_num_entries_ptr);
 herr_t H5Freset_mdc_hit_rate_stats(hid_t file_id);
 ssize_t H5Fget_name(hid_t obj_id, char *name, size_t size);
 herr_t H5Fget_info(hid_t obj_id, H5F_info_t *bh_info);







#line 1 "/usr/include/H5Tpublic.h" 1
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright by The HDF Group.                                               *
 * Copyright by the Board of Trustees of the University of Illinois.         *
 * All rights reserved.                                                      *
 *                                                                           *
 * This file is part of HDF5.  The full HDF5 copyright notice, including     *
 * terms governing use, modification, and redistribution, is contained in    *
 * the files COPYING and Copyright.html.  COPYING can be found at the root   *
 * of the source code distribution tree; Copyright.html can be found at the  *
 * root level of an installed copy of the electronic HDF5 document set and   *
 * is linked from the top-level documents page.  It can also be found at     *
 * http://hdfgroup.org/HDF5/doc/Copyright.html.  If you do not have          *
 * access to either file, you may request a copy from help@hdfgroup.org.     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
 * This file contains public declarations for the H5T module.
 */



/* Public headers needed by this file */

#line 1 "/usr/include/H5public.h" 1

#line 23 "/usr/include/H5Tpublic.h" 2

#line 1 "/usr/include/H5Ipublic.h" 1

#line 24 "/usr/include/H5Tpublic.h" 2



/* These are the various classes of datatypes */
/* If this goes over 16 types (0-15), the file format will need to change) */
typedef enum H5T_class_t {
    H5T_NO_CLASS         = -1,  /*error                                      */
    H5T_INTEGER          = 0,   /*integer types                              */
    H5T_FLOAT            = 1,   /*floating-point types                       */
    H5T_TIME             = 2,   /*date and time types                        */
    H5T_STRING           = 3,   /*character string types                     */
    H5T_BITFIELD         = 4,   /*bit field types                            */
    H5T_OPAQUE           = 5,   /*opaque types                               */
    H5T_COMPOUND         = 6,   /*compound types                             */
    H5T_REFERENCE        = 7,   /*reference types                            */
    H5T_ENUM		 = 8,	/*enumeration types                          */
    H5T_VLEN		 = 9,	/*Variable-Length types                      */
    H5T_ARRAY	         = 10,	/*Array types                                */

    H5T_NCLASSES                /*this must be last                          */
} H5T_class_t;

/* Byte orders */
typedef enum H5T_order_t {
    H5T_ORDER_ERROR      = -1,  /*error                                      */
    H5T_ORDER_LE         = 0,   /*little endian                              */
    H5T_ORDER_BE         = 1,   /*bit endian                                 */
    H5T_ORDER_VAX        = 2,   /*VAX mixed endian                           */
    H5T_ORDER_NONE       = 3    /*no particular order (strings, bits,..)     */
    /*H5T_ORDER_NONE must be last */
} H5T_order_t;

/* Types of integer sign schemes */
typedef enum H5T_sign_t {
    H5T_SGN_ERROR        = -1,  /*error                                      */
    H5T_SGN_NONE         = 0,   /*this is an unsigned type                   */
    H5T_SGN_2            = 1,   /*two's complement                           */

    H5T_NSGN             = 2    /*this must be last!                         */
} H5T_sign_t;

/* Floating-point normalization schemes */
typedef enum H5T_norm_t {
    H5T_NORM_ERROR       = -1,  /*error                                      */
    H5T_NORM_IMPLIED     = 0,   /*msb of mantissa isn't stored, always 1     */
    H5T_NORM_MSBSET      = 1,   /*msb of mantissa is always 1                */
    H5T_NORM_NONE        = 2    /*not normalized                             */
    /*H5T_NORM_NONE must be last */
} H5T_norm_t;

/*
 * Character set to use for text strings.  Do not change these values since
 * they appear in HDF5 files!
 */
typedef enum H5T_cset_t {
    H5T_CSET_ERROR       = -1,  /*error                                      */
    H5T_CSET_ASCII       = 0,   /*US ASCII                                   */
    H5T_CSET_UTF8        = 1,   /*UTF-8 Unicode encoding		     */
    H5T_CSET_RESERVED_2  = 2,   /*reserved for later use		     */
    H5T_CSET_RESERVED_3  = 3,   /*reserved for later use		     */
    H5T_CSET_RESERVED_4  = 4,   /*reserved for later use		     */
    H5T_CSET_RESERVED_5  = 5,   /*reserved for later use		     */
    H5T_CSET_RESERVED_6  = 6,   /*reserved for later use		     */
    H5T_CSET_RESERVED_7  = 7,   /*reserved for later use		     */
    H5T_CSET_RESERVED_8  = 8,   /*reserved for later use		     */
    H5T_CSET_RESERVED_9  = 9,   /*reserved for later use		     */
    H5T_CSET_RESERVED_10 = 10,  /*reserved for later use		     */
    H5T_CSET_RESERVED_11 = 11,  /*reserved for later use		     */
    H5T_CSET_RESERVED_12 = 12,  /*reserved for later use		     */
    H5T_CSET_RESERVED_13 = 13,  /*reserved for later use		     */
    H5T_CSET_RESERVED_14 = 14,  /*reserved for later use		     */
    H5T_CSET_RESERVED_15 = 15   /*reserved for later use		     */
} H5T_cset_t;


/*
 * Type of padding to use in character strings.  Do not change these values
 * since they appear in HDF5 files!
 */
typedef enum H5T_str_t {
    H5T_STR_ERROR        = -1,  /*error                                      */
    H5T_STR_NULLTERM     = 0,   /*null terminate like in C                   */
    H5T_STR_NULLPAD      = 1,   /*pad with nulls                             */
    H5T_STR_SPACEPAD     = 2,   /*pad with spaces like in Fortran            */
    H5T_STR_RESERVED_3   = 3,   /*reserved for later use		     */
    H5T_STR_RESERVED_4   = 4,   /*reserved for later use		     */
    H5T_STR_RESERVED_5   = 5,   /*reserved for later use		     */
    H5T_STR_RESERVED_6   = 6,   /*reserved for later use		     */
    H5T_STR_RESERVED_7   = 7,   /*reserved for later use		     */
    H5T_STR_RESERVED_8   = 8,   /*reserved for later use		     */
    H5T_STR_RESERVED_9   = 9,   /*reserved for later use		     */
    H5T_STR_RESERVED_10  = 10,  /*reserved for later use		     */
    H5T_STR_RESERVED_11  = 11,  /*reserved for later use		     */
    H5T_STR_RESERVED_12  = 12,  /*reserved for later use		     */
    H5T_STR_RESERVED_13  = 13,  /*reserved for later use		     */
    H5T_STR_RESERVED_14  = 14,  /*reserved for later use		     */
    H5T_STR_RESERVED_15  = 15   /*reserved for later use		     */
} H5T_str_t;


/* Type of padding to use in other atomic types */
typedef enum H5T_pad_t {
    H5T_PAD_ERROR        = -1,  /*error                                      */
    H5T_PAD_ZERO         = 0,   /*always set to zero                         */
    H5T_PAD_ONE          = 1,   /*always set to one                          */
    H5T_PAD_BACKGROUND   = 2,   /*set to background value                    */

    H5T_NPAD             = 3    /*THIS MUST BE LAST                          */
} H5T_pad_t;

/* Commands sent to conversion functions */
typedef enum H5T_cmd_t {
    H5T_CONV_INIT	= 0,	/*query and/or initialize private data	     */
    H5T_CONV_CONV	= 1, 	/*convert data from source to dest datatype */
    H5T_CONV_FREE	= 2	/*function is being removed from path	     */
} H5T_cmd_t;

/* How is the `bkg' buffer used by the conversion function? */
typedef enum H5T_bkg_t {
    H5T_BKG_NO		= 0, 	/*background buffer is not needed, send NULL */
    H5T_BKG_TEMP	= 1,	/*bkg buffer used as temp storage only       */
    H5T_BKG_YES		= 2	/*init bkg buf with data before conversion   */
} H5T_bkg_t;

/* Type conversion client data */
typedef struct H5T_cdata_t {
    H5T_cmd_t		command;/*what should the conversion function do?    */
    H5T_bkg_t		need_bkg;/*is the background buffer needed?	     */
    hbool_t		recalc;	/*recalculate private data		     */
    void		*priv;	/*private data				     */
} H5T_cdata_t;

/* Conversion function persistence */
typedef enum H5T_pers_t {
    H5T_PERS_DONTCARE	= -1, 	/*wild card				     */
    H5T_PERS_HARD	= 0,	/*hard conversion function		     */
    H5T_PERS_SOFT	= 1 	/*soft conversion function		     */
} H5T_pers_t;

/* The order to retrieve atomic native datatype */
typedef enum H5T_direction_t {
    H5T_DIR_DEFAULT     = 0,    /*default direction is inscendent            */
    H5T_DIR_ASCEND      = 1,    /*in inscendent order                        */
    H5T_DIR_DESCEND     = 2     /*in descendent order                        */
} H5T_direction_t;

/* The exception type passed into the conversion callback function */
typedef enum H5T_conv_except_t {
    H5T_CONV_EXCEPT_RANGE_HI       = 0,   /*source value is greater than destination's range */
    H5T_CONV_EXCEPT_RANGE_LOW      = 1,   /*source value is less than destination's range    */
    H5T_CONV_EXCEPT_PRECISION      = 2,   /*source value loses precision in destination      */
    H5T_CONV_EXCEPT_TRUNCATE       = 3,   /*source value is truncated in destination         */
    H5T_CONV_EXCEPT_PINF           = 4,   /*source value is positive infinity(floating number) */
    H5T_CONV_EXCEPT_NINF           = 5,   /*source value is negative infinity(floating number) */
    H5T_CONV_EXCEPT_NAN            = 6    /*source value is NaN(floating number)             */
} H5T_conv_except_t;

/* The return value from conversion callback function H5T_conv_except_func_t */
typedef enum H5T_conv_ret_t {
    H5T_CONV_ABORT      = -1,   /*abort conversion                           */
    H5T_CONV_UNHANDLED  = 0,    /*callback function failed to handle the exception      */
    H5T_CONV_HANDLED    = 1     /*callback function handled the exception successfully  */
} H5T_conv_ret_t;

/* Variable Length Datatype struct in memory */
/* (This is only used for VL sequences, not VL strings, which are stored in char *'s) */
typedef struct {
    size_t len; /* Length of VL data (in base type units) */
    void *p;    /* Pointer to VL data */
} hvl_t;

/* Variable Length String information */


/* Opaque information */

                                        /* This could be raised without too much difficulty */





/* All datatype conversion functions are... */
typedef herr_t (*H5T_conv_t) (hid_t src_id, hid_t dst_id, H5T_cdata_t *cdata,
      size_t nelmts, size_t buf_stride, size_t bkg_stride, void *buf,
      void *bkg, hid_t dset_xfer_plist);

/* Exception handler.  If an exception like overflow happenes during conversion,
 * this function is called if it's registered through H5Pset_type_conv_cb.
 */
typedef H5T_conv_ret_t (*H5T_conv_except_func_t)(H5T_conv_except_t except_type,
    hid_t src_id, hid_t dst_id, void *src_buf, void *dst_buf, void *user_data);

/* When this header is included from a private header, don't make calls to H5open() */







/*
 * The IEEE floating point types in various byte orders.
 */




extern hid_t H5T_IEEE_F32BE_g;
extern hid_t H5T_IEEE_F32LE_g;
extern hid_t H5T_IEEE_F64BE_g;
extern hid_t H5T_IEEE_F64LE_g;

/*
 * These are "standard" types.  For instance, signed (2's complement) and
 * unsigned integers of various sizes and byte orders.
 */


























extern hid_t H5T_STD_I8BE_g;
extern hid_t H5T_STD_I8LE_g;
extern hid_t H5T_STD_I16BE_g;
extern hid_t H5T_STD_I16LE_g;
extern hid_t H5T_STD_I32BE_g;
extern hid_t H5T_STD_I32LE_g;
extern hid_t H5T_STD_I64BE_g;
extern hid_t H5T_STD_I64LE_g;
extern hid_t H5T_STD_U8BE_g;
extern hid_t H5T_STD_U8LE_g;
extern hid_t H5T_STD_U16BE_g;
extern hid_t H5T_STD_U16LE_g;
extern hid_t H5T_STD_U32BE_g;
extern hid_t H5T_STD_U32LE_g;
extern hid_t H5T_STD_U64BE_g;
extern hid_t H5T_STD_U64LE_g;
extern hid_t H5T_STD_B8BE_g;
extern hid_t H5T_STD_B8LE_g;
extern hid_t H5T_STD_B16BE_g;
extern hid_t H5T_STD_B16LE_g;
extern hid_t H5T_STD_B32BE_g;
extern hid_t H5T_STD_B32LE_g;
extern hid_t H5T_STD_B64BE_g;
extern hid_t H5T_STD_B64LE_g;
extern hid_t H5T_STD_REF_OBJ_g;
extern hid_t H5T_STD_REF_DSETREG_g;

/*
 * Types which are particular to Unix.
 */




extern hid_t H5T_UNIX_D32BE_g;
extern hid_t H5T_UNIX_D32LE_g;
extern hid_t H5T_UNIX_D64BE_g;
extern hid_t H5T_UNIX_D64LE_g;

/*
 * Types particular to the C language.  String types use `bytes' instead
 * of `bits' as their size.
 */

extern hid_t H5T_C_S1_g;

/*
 * Types particular to Fortran.
 */

extern hid_t H5T_FORTRAN_S1_g;

/*
 * These types are for Intel CPU's.  They are little endian with IEEE
 * floating point.
 */















/*
 * These types are for DEC Alpha CPU's.  They are little endian with IEEE
 * floating point.
 */















/*
 * These types are for MIPS cpu's commonly used in SGI systems. They are big
 * endian with IEEE floating point.
 */















/*
 * The VAX floating point types (i.e. in VAX byte order)
 */


extern hid_t H5T_VAX_F32_g;
extern hid_t H5T_VAX_F64_g;

/*
 * The predefined native types. These are the types detected by H5detect and
 * they violate the naming scheme a little.  Instead of a class name,
 * precision and byte order as the last component, they have a C-like type
 * name.  If the type begins with `U' then it is the unsigned version of the
 * integer type; other integer types are signed.  The type LLONG corresponds
 * to C's `long long' and LDOUBLE is `long double' (these types might be the
 * same as `LONG' and `DOUBLE' respectively).
 */


























extern hid_t H5T_NATIVE_SCHAR_g;
extern hid_t H5T_NATIVE_UCHAR_g;
extern hid_t H5T_NATIVE_SHORT_g;
extern hid_t H5T_NATIVE_USHORT_g;
extern hid_t H5T_NATIVE_INT_g;
extern hid_t H5T_NATIVE_UINT_g;
extern hid_t H5T_NATIVE_LONG_g;
extern hid_t H5T_NATIVE_ULONG_g;
extern hid_t H5T_NATIVE_LLONG_g;
extern hid_t H5T_NATIVE_ULLONG_g;
extern hid_t H5T_NATIVE_FLOAT_g;
extern hid_t H5T_NATIVE_DOUBLE_g;

extern hid_t H5T_NATIVE_LDOUBLE_g;

extern hid_t H5T_NATIVE_B8_g;
extern hid_t H5T_NATIVE_B16_g;
extern hid_t H5T_NATIVE_B32_g;
extern hid_t H5T_NATIVE_B64_g;
extern hid_t H5T_NATIVE_OPAQUE_g;
extern hid_t H5T_NATIVE_HADDR_g;
extern hid_t H5T_NATIVE_HSIZE_g;
extern hid_t H5T_NATIVE_HSSIZE_g;
extern hid_t H5T_NATIVE_HERR_g;
extern hid_t H5T_NATIVE_HBOOL_g;

/* C9x integer types */






extern hid_t H5T_NATIVE_INT8_g;
extern hid_t H5T_NATIVE_UINT8_g;
extern hid_t H5T_NATIVE_INT_LEAST8_g;
extern hid_t H5T_NATIVE_UINT_LEAST8_g;
extern hid_t H5T_NATIVE_INT_FAST8_g;
extern hid_t H5T_NATIVE_UINT_FAST8_g;







extern hid_t H5T_NATIVE_INT16_g;
extern hid_t H5T_NATIVE_UINT16_g;
extern hid_t H5T_NATIVE_INT_LEAST16_g;
extern hid_t H5T_NATIVE_UINT_LEAST16_g;
extern hid_t H5T_NATIVE_INT_FAST16_g;
extern hid_t H5T_NATIVE_UINT_FAST16_g;







extern hid_t H5T_NATIVE_INT32_g;
extern hid_t H5T_NATIVE_UINT32_g;
extern hid_t H5T_NATIVE_INT_LEAST32_g;
extern hid_t H5T_NATIVE_UINT_LEAST32_g;
extern hid_t H5T_NATIVE_INT_FAST32_g;
extern hid_t H5T_NATIVE_UINT_FAST32_g;







extern hid_t H5T_NATIVE_INT64_g;
extern hid_t H5T_NATIVE_UINT64_g;
extern hid_t H5T_NATIVE_INT_LEAST64_g;
extern hid_t H5T_NATIVE_UINT_LEAST64_g;
extern hid_t H5T_NATIVE_INT_FAST64_g;
extern hid_t H5T_NATIVE_UINT_FAST64_g;

/* Operations defined on all datatypes */
 hid_t H5Tcreate(H5T_class_t type, size_t size);
 hid_t H5Tcopy(hid_t type_id);
 herr_t H5Tclose(hid_t type_id);
 htri_t H5Tequal(hid_t type1_id, hid_t type2_id);
 herr_t H5Tlock(hid_t type_id);
 herr_t H5Tcommit2(hid_t loc_id, const char *name, hid_t type_id,
    hid_t lcpl_id, hid_t tcpl_id, hid_t tapl_id);
 hid_t H5Topen2(hid_t loc_id, const char *name, hid_t tapl_id);
 herr_t H5Tcommit_anon(hid_t loc_id, hid_t type_id, hid_t tcpl_id, hid_t tapl_id);
 hid_t H5Tget_create_plist(hid_t type_id);
 htri_t H5Tcommitted(hid_t type_id);
 herr_t H5Tencode(hid_t obj_id, void *buf, size_t *nalloc);
 hid_t H5Tdecode(const void *buf);

/* Operations defined on compound datatypes */
 herr_t H5Tinsert(hid_t parent_id, const char *name, size_t offset,
			 hid_t member_id);
 herr_t H5Tpack(hid_t type_id);

/* Operations defined on enumeration datatypes */
 hid_t H5Tenum_create(hid_t base_id);
 herr_t H5Tenum_insert(hid_t type, const char *name, const void *value);
 herr_t H5Tenum_nameof(hid_t type, const void *value, char *name/*out*/,
			     size_t size);
 herr_t H5Tenum_valueof(hid_t type, const char *name,
			      void *value/*out*/);

/* Operations defined on variable-length datatypes */
 hid_t H5Tvlen_create(hid_t base_id);

/* Operations defined on array datatypes */
 hid_t H5Tarray_create2(hid_t base_id, unsigned ndims,
            const hsize_t dim[/* ndims */]);
 int H5Tget_array_ndims(hid_t type_id);
 int H5Tget_array_dims2(hid_t type_id, hsize_t dims[]);

/* Operations defined on opaque datatypes */
 herr_t H5Tset_tag(hid_t type, const char *tag);
 char *H5Tget_tag(hid_t type);

/* Querying property values */
 hid_t H5Tget_super(hid_t type);
 H5T_class_t H5Tget_class(hid_t type_id);
 htri_t H5Tdetect_class(hid_t type_id, H5T_class_t cls);
 size_t H5Tget_size(hid_t type_id);
 H5T_order_t H5Tget_order(hid_t type_id);
 size_t H5Tget_precision(hid_t type_id);
 int H5Tget_offset(hid_t type_id);
 herr_t H5Tget_pad(hid_t type_id, H5T_pad_t *lsb/*out*/,
			  H5T_pad_t *msb/*out*/);
 H5T_sign_t H5Tget_sign(hid_t type_id);
 herr_t H5Tget_fields(hid_t type_id, size_t *spos/*out*/,
			     size_t *epos/*out*/, size_t *esize/*out*/,
			     size_t *mpos/*out*/, size_t *msize/*out*/);
 size_t H5Tget_ebias(hid_t type_id);
 H5T_norm_t H5Tget_norm(hid_t type_id);
 H5T_pad_t H5Tget_inpad(hid_t type_id);
 H5T_str_t H5Tget_strpad(hid_t type_id);
 int H5Tget_nmembers(hid_t type_id);
 char *H5Tget_member_name(hid_t type_id, unsigned membno);
 int H5Tget_member_index(hid_t type_id, const char *name);
 size_t H5Tget_member_offset(hid_t type_id, unsigned membno);
 H5T_class_t H5Tget_member_class(hid_t type_id, unsigned membno);
 hid_t H5Tget_member_type(hid_t type_id, unsigned membno);
 herr_t H5Tget_member_value(hid_t type_id, unsigned membno, void *value/*out*/);
 H5T_cset_t H5Tget_cset(hid_t type_id);
 htri_t H5Tis_variable_str(hid_t type_id);
 hid_t H5Tget_native_type(hid_t type_id, H5T_direction_t direction);

/* Setting property values */
 herr_t H5Tset_size(hid_t type_id, size_t size);
 herr_t H5Tset_order(hid_t type_id, H5T_order_t order);
 herr_t H5Tset_precision(hid_t type_id, size_t prec);
 herr_t H5Tset_offset(hid_t type_id, size_t offset);
 herr_t H5Tset_pad(hid_t type_id, H5T_pad_t lsb, H5T_pad_t msb);
 herr_t H5Tset_sign(hid_t type_id, H5T_sign_t sign);
 herr_t H5Tset_fields(hid_t type_id, size_t spos, size_t epos,
			     size_t esize, size_t mpos, size_t msize);
 herr_t H5Tset_ebias(hid_t type_id, size_t ebias);
 herr_t H5Tset_norm(hid_t type_id, H5T_norm_t norm);
 herr_t H5Tset_inpad(hid_t type_id, H5T_pad_t pad);
 herr_t H5Tset_cset(hid_t type_id, H5T_cset_t cset);
 herr_t H5Tset_strpad(hid_t type_id, H5T_str_t strpad);

/* Type conversion database */
 herr_t H5Tregister(H5T_pers_t pers, const char *name, hid_t src_id,
			   hid_t dst_id, H5T_conv_t func);
 herr_t H5Tunregister(H5T_pers_t pers, const char *name, hid_t src_id,
			     hid_t dst_id, H5T_conv_t func);
 H5T_conv_t H5Tfind(hid_t src_id, hid_t dst_id, H5T_cdata_t **pcdata);
 htri_t H5Tcompiler_conv(hid_t src_id, hid_t dst_id);
 herr_t H5Tconvert(hid_t src_id, hid_t dst_id, size_t nelmts,
			  void *buf, void *background, hid_t plist_id);

/* Symbols defined for compatibility with previous versions of the HDF5 API.
 *
 * Use of these symbols is deprecated.
 */


/* Macros */


/* Typedefs */


/* Function prototypes */
 herr_t H5Tcommit1(hid_t loc_id, const char *name, hid_t type_id);
 hid_t H5Topen1(hid_t loc_id, const char *name);
 hid_t H5Tarray_create1(hid_t base_id, int ndims,
            const hsize_t dim[/* ndims */],
            const int perm[/* ndims */]);
 int H5Tget_array_dims1(hid_t type_id, hsize_t dims[], int perm[]);









#line 1 "/usr/include/H5PTpublic.h" 1
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Copyright by The HDF Group.                                               *
 * Copyright by the Board of Trustees of the University of Illinois.         *
 * All rights reserved.                                                      *
 *                                                                           *
 * This file is part of HDF5.  The full HDF5 copyright notice, including     *
 * terms governing use, modification, and redistribution, is contained in    *
 * the files COPYING and Copyright.html.  COPYING can be found at the root   *
 * of the source code distribution tree; Copyright.html can be found at the  *
 * root level of an installed copy of the electronic HDF5 document set and   *
 * is linked from the top-level documents page.  It can also be found at     *
 * http://hdfgroup.org/HDF5/doc/Copyright.html.  If you do not have          *
 * access to either file, you may request a copy from help@hdfgroup.org.     *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */









/*-------------------------------------------------------------------------
 *
 * Create/Open/Close functions
 *
 *-------------------------------------------------------------------------
 */

 hid_t H5PTcreate_fl ( hid_t loc_id,
                      const char *dset_name,
                      hid_t dtype_id,
                      hsize_t chunk_size,
                      int compression );



                      
                      


 hid_t H5PTopen( hid_t loc_id,
                const char *dset_name );

 herr_t  H5PTclose( hid_t table_id );


/*-------------------------------------------------------------------------
 *
 * Write functions
 *
 *-------------------------------------------------------------------------
 */

 herr_t  H5PTappend( hid_t table_id,
                   size_t nrecords,
                   const void * data );

/*-------------------------------------------------------------------------
 *
 * Read functions
 *
 *-------------------------------------------------------------------------
 */


 herr_t  H5PTget_next( hid_t table_id,
                     size_t nrecords,
                     void * data );

 herr_t  H5PTread_packets( hid_t table_id,
                         hsize_t start,
                         size_t nrecords,
                         void *data );

/*-------------------------------------------------------------------------
 *
 * Inquiry functions
 *
 *-------------------------------------------------------------------------
 */


 herr_t  H5PTget_num_packets( hid_t table_id,
                            hsize_t *nrecords );

 herr_t  H5PTis_valid( hid_t table_id );





/*-------------------------------------------------------------------------
 *
 * Packet Table "current index" functions
 *
 *-------------------------------------------------------------------------
 */

 herr_t  H5PTcreate_index( hid_t table_id );

 herr_t  H5PTset_index( hid_t table_id,
                             hsize_t pt_index );

 herr_t  H5PTget_index( hid_t table_id,
                             hsize_t *pt_index );

/*-------------------------------------------------------------------------
 *
 * Memory Management functions
 *
 *-------------------------------------------------------------------------
 */



                               
                               








