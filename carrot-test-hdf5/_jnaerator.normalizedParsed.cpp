

























/// Convenience types.
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
/// Fixed-size types, underlying types depend on word size and compiler.
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long long int __int64_t;
typedef unsigned long long int __uint64_t;
typedef long long int __quad_t;
typedef unsigned long long int __u_quad_t;

typedef __u_quad_t __dev_t; /* Type of device numbers.  */
typedef unsigned int __uid_t; /* Type of user identifications.  */
typedef unsigned int __gid_t; /* Type of group identifications.  */
typedef unsigned long int __ino_t; /* Type of file serial numbers.  */
typedef __u_quad_t __ino64_t; /* Type of file serial numbers (LFS).*/
typedef unsigned int __mode_t; /* Type of file attribute bitmasks.  */
typedef unsigned int __nlink_t; /* Type of file link counts.  */
typedef long int __off_t; /* Type of file sizes and offsets.  */
typedef __quad_t __off64_t; /* Type of file sizes and offsets (LFS).  */
typedef int __pid_t; /* Type of process identifications.  */
typedef struct __fsid_t {
	int[2] __val;
} __fsid_t; /* Type of file system IDs.  */
typedef long int __clock_t; /* Type of CPU usage counts.  */
typedef unsigned long int __rlim_t; /* Type for resource measurement.  */
typedef __u_quad_t __rlim64_t; /* Type for resource measurement (LFS).  */
typedef unsigned int __id_t; /* General type for IDs.  */
typedef long int __time_t; /* Seconds since the Epoch.  */
typedef unsigned int __useconds_t; /* Count of microseconds.  */
typedef long int __suseconds_t; /* Signed count of microseconds.  */
typedef int __daddr_t; /* The type of a disk address.  */
typedef long int __swblk_t; /* Type of a swap block maybe?  */
typedef int __key_t; /* Type of an IPC key.  */
/// Clock ID used in clock and timer functions.
typedef int __clockid_t;
/// Timer ID returned by `timer_create'.
typedef void* __timer_t;
/// Type to represent block size.
typedef long int __blksize_t;
/// Type to count number of disk blocks.
typedef long int __blkcnt_t;
typedef __quad_t __blkcnt64_t;
/// Type to count file system blocks.
typedef unsigned long int __fsblkcnt_t;
typedef __u_quad_t __fsblkcnt64_t;
/// Type to count file system nodes.
typedef unsigned long int __fsfilcnt_t;
typedef __u_quad_t __fsfilcnt64_t;
typedef int __ssize_t; /* Type of a byte count, or error.  */
/**
 * These few don't really vary by system, they always correspond<br>
 * to one of the other defined types.
 */
typedef __off64_t __loff_t; /* Type of file sizes and offsets (LFS).  */
typedef __quad_t* __qaddr_t;
typedef char* __caddr_t;
/// Duplicates info from stdint.h but this is used in unistd.h.
typedef int __intptr_t;
/// Duplicate info from sys/socket.h.
typedef unsigned int __socklen_t;
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


/// Returned by `clock'.
typedef __clock_t clock_t;

/// Returned by `time'.
typedef __time_t time_t;

/// Clock ID used in clock and timer functions.
typedef __clockid_t clockid_t;

/// Timer ID returned by `timer_create'.
typedef __timer_t timer_t;

/// Old compatibility names for C types.
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef char int8_t;
typedef short int int16_t;
typedef int int32_t;
typedef long long int int64_t;
/// But these were defined by ISO C without the first `_'.
typedef unsigned char u_int8_t;
typedef unsigned short int u_int16_t;
typedef unsigned int u_int32_t;
typedef unsigned long long int u_int64_t;
typedef int register_t;



















typedef int __sig_atomic_t;
typedef struct __sigset_t {
	unsigned long int[(1024 / (8 * sizeof(unsigned long int)))] __val;
} __sigset_t;
typedef __sigset_t sigset_t;




/**
 * A time value that is accurate to the nearest<br>
 * microsecond but also has a range of years.
 */
struct timeval {
	__time_t tv_sec; /* Seconds.  */
	__suseconds_t tv_usec; /* Microseconds.  */
};
typedef __suseconds_t suseconds_t;
/// The fd_set member is required to be an array of longs.
typedef long int __fd_mask;
/// fd_set for select and pselect.
typedef struct fd_set {
	__fd_mask[1024 / (8 * (int)sizeof(__fd_mask))] __fds_bits;
} fd_set;
/// Sometimes the fd_set member is assumed to have this type.
typedef __fd_mask fd_mask;
/**
 * Check the first NFDS descriptors each in READFDS (if not NULL) for read<br>
 * readiness, in WRITEFDS (if not NULL) for write readiness, and in EXCEPTFDS<br>
 * (if not NULL) for exceptional conditions.  If TIMEOUT is not NULL, time out<br>
 * after waiting the interval specified therein.  Returns the number of ready<br>
 * descriptors, or -1 for errors.<br>
 * This function is a cancellation point and therefore not marked with<br>
 * __THROW.<br>
 * Original signature : <code>int select(int, fd_set*, fd_set*, fd_set*, timeval*)</code>
 */
extern int select(int __nfds, fd_set* __readfds, fd_set* __writefds, fd_set* __exceptfds, timeval* __timeout);
/**
 * Same as above only that the TIMEOUT value is given with higher<br>
 * resolution and a sigmask which is been set temporarily.  This version<br>
 * should be used.<br>
 * This function is a cancellation point and therefore not marked with<br>
 * __THROW.<br>
 * Original signature : <code>int pselect(int, fd_set*, fd_set*, fd_set*, timespec*, const __sigset_t*)</code>
 */
extern int pselect(int __nfds, fd_set* __readfds, fd_set* __writefds, fd_set* __exceptfds, timespec* __timeout, const __sigset_t* __sigmask);



/// Original signature : <code>int gnu_dev_major(unsigned long long int)</code>
extern unsigned int gnu_dev_major(unsigned long long int __dev);
/// Original signature : <code>int gnu_dev_minor(unsigned long long int)</code>
extern unsigned int gnu_dev_minor(unsigned long long int __dev);
/// Original signature : <code>int gnu_dev_makedev(unsigned int, unsigned int)</code>
extern unsigned long long int gnu_dev_makedev(unsigned int __major, unsigned int __minor);
typedef __blksize_t blksize_t;
typedef __blkcnt_t blkcnt_t; /* Type to count number of disk blocks.  */
typedef __fsblkcnt_t fsblkcnt_t; /* Type to count file system blocks.  */
typedef __fsfilcnt_t fsfilcnt_t; /* Type to count file system inodes.  */


/**
 * Thread identifiers.  The structure of the attribute type is not<br>
 * exposed on purpose.
 */
typedef unsigned long int pthread_t;
typedef union  pthread_attr_t {
	char[36] __size;
	long int __align;
} pthread_attr_t;
typedef struct __pthread_slist_t {
	__pthread_internal_slist* __next;
} __pthread_internal_slist;
/**
 * Data structures for mutex handling.  The structure of the attribute<br>
 * type is not exposed on purpose.
 */
typedef union  pthread_mutex_t {
	__pthread_mutex_s __data;
	char[24] __size;
	long int __align;
	struct __pthread_mutex_s {
		int __lock;
		unsigned int __count;
		int __owner;
		/**
		 * KIND must stay at this position in the structure to maintain<br>
		 * binary compatibility.
		 */
		int __kind;
		unsigned int __nusers;
		union {
			int __spins;
			__pthread_slist_t __list;
		};
	};
} pthread_mutex_t;
typedef union  pthread_mutexattr_t {
	char[4] __size;
	int __align;
} pthread_mutexattr_t;
/**
 * Data structure for conditional variable handling.  The structure of<br>
 * the attribute type is not exposed on purpose.
 */
typedef union  pthread_cond_t {
	__data_struct __data;
	char[48] __size;
	long long int __align;
	struct __data_struct {
		int __lock;
		unsigned int __futex;
		unsigned long long int __total_seq;
		unsigned long long int __wakeup_seq;
		unsigned long long int __woken_seq;
		void* __mutex;
		unsigned int __nwaiters;
		unsigned int __broadcast_seq;
	};
} pthread_cond_t;
typedef union  pthread_condattr_t {
	char[4] __size;
	int __align;
} pthread_condattr_t;
/// Keys for thread-specific data
typedef unsigned int pthread_key_t;
/// Once-only execution
typedef int pthread_once_t;
/**
 * Data structure for read-write lock variable handling.  The<br>
 * structure of the attribute type is not exposed on purpose.
 */
typedef union  pthread_rwlock_t {
	__data_struct __data;
	char[32] __size;
	long int __align;
	struct __data_struct {
		int __lock;
		unsigned int __nr_readers;
		unsigned int __readers_wakeup;
		unsigned int __writer_wakeup;
		unsigned int __nr_readers_queued;
		unsigned int __nr_writers_queued;
		/**
		 * FLAGS must stay at this position in the structure to maintain<br>
		 * binary compatibility.
		 */
		unsigned char __flags;
		unsigned char __shared;
		unsigned char __pad1;
		unsigned char __pad2;
		int __writer;
	};
} pthread_rwlock_t;
typedef union  pthread_rwlockattr_t {
	char[8] __size;
	long int __align;
} pthread_rwlockattr_t;
/// POSIX spinlock data type.
typedef volatile int pthread_spinlock_t;
/**
 * POSIX barriers data type.  The structure of the type is<br>
 * deliberately not exposed.
 */
typedef union  pthread_barrier_t {
	char[20] __size;
	long int __align;
} pthread_barrier_t;
typedef union  pthread_barrierattr_t {
	char[4] __size;
	int __align;
} pthread_barrierattr_t;
























/// Unsigned.
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long int uint64_t;
/// Signed.
typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;
typedef long long int int_least64_t;
/// Unsigned.
typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;
typedef unsigned long long int uint_least64_t;
/// Signed.
typedef signed char int_fast8_t;
typedef int int_fast16_t;
typedef int int_fast32_t;
typedef long long int int_fast64_t;
/// Unsigned.
typedef unsigned char uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;
typedef unsigned long long int uint_fast64_t;
typedef int intptr_t;
typedef unsigned int uintptr_t;
typedef long long int intmax_t;
typedef unsigned long long int uintmax_t;






typedef wchar_t __gwchar_t;
/// We have to define the `uintmax_t' type using `lldiv_t'.
typedef struct imaxdiv_t {
	long long int quot; /* Quotient.  */
	long long int rem; /* Remainder.  */
} imaxdiv_t;
/**
 * Compute absolute value of N.<br>
 * Original signature : <code>intmax_t imaxabs(intmax_t)</code>
 */
extern intmax_t imaxabs(intmax_t __n);
/**
 * Return the `imaxdiv_t' representation of the value of NUMER over DENOM.<br>
 * Original signature : <code>imaxdiv_t imaxdiv(intmax_t, intmax_t)</code>
 */
extern imaxdiv_t imaxdiv(intmax_t __numer, intmax_t __denom);
/**
 * Like `strtol' but convert to `intmax_t'.<br>
 * Original signature : <code>intmax_t strtoimax(__const char*, char**, int)</code>
 */
extern intmax_t strtoimax(__const char* __nptr, char** __endptr, int __base);
/**
 * Like `strtoul' but convert to `uintmax_t'.<br>
 * Original signature : <code>uintmax_t strtoumax(__const char*, char**, int)</code>
 */
extern uintmax_t strtoumax(__const char* __nptr, char** __endptr, int __base);
/**
 * Like `wcstol' but convert to `intmax_t'.<br>
 * Original signature : <code>intmax_t wcstoimax(__const __gwchar_t*, __gwchar_t**, int)</code>
 */
extern intmax_t wcstoimax(__const __gwchar_t* __nptr, __gwchar_t** __endptr, int __base);
/**
 * Like `wcstoul' but convert to `uintmax_t'.<br>
 * Original signature : <code>uintmax_t wcstoumax(__const __gwchar_t*, __gwchar_t**, int)</code>
 */
extern uintmax_t wcstoumax(__const __gwchar_t* __nptr, __gwchar_t** __endptr, int __base);



/**
 * Status return values.  Failed integer functions in HDF5 result almost<br>
 * always in a negative value (unsigned failing functions sometimes return<br>
 * zero for failure) while successfull return is non-negative (often zero).<br>
 * The negative failure value is most commonly -1, but don't bet on it.  The<br>
 * proper way to detect failure is something like:<br>
 * * 	if((dset = H5Dopen2(file, name)) < 0)<br>
 *     fprintf(stderr, "unable to open the requested dataset\n");
 */
typedef int herr_t;
/**
 * Boolean type.  Successful return values are zero (false) or positive<br>
 * (true). The typical true value is 1 but don't bet on it.  Boolean<br>
 * functions cannot fail.  Functions that return `htri_t' however return zero<br>
 * (false), positive (true), or negative (failure). The proper way to test<br>
 * for truth from a htri_t function is:<br>
 * * 	if ((retval = H5Tcommitted(type))>0) {<br>
 *     printf("data type is committed\n");<br>
 * } else if (!retval) {<br>
 * 	    printf("data type is not committed\n");<br>
 * } else {<br>
 * 	    printf("error determining whether data type is committed\n");<br>
 * }
 */
typedef unsigned int hbool_t;
typedef int htri_t;
typedef unsigned long long hsize_t;
typedef signed long long hssize_t;
typedef uint64_t haddr_t;
/// Common iteration orders
typedef enum H5_iter_order_t {
	H5_ITER_UNKNOWN = -1 /* Unknown order */,
	H5_ITER_INC,
	H5_ITER_DEC,
	H5_ITER_NATIVE,
	H5_ITER_N /* Number of iteration orders */
} H5_iter_order_t;
/**
 * The types of indices on links in groups/attributes on objects.<br>
 * Primarily used for "<do> <foo> by index" routines and for iterating over<br>
 * links in groups/attributes on objects.
 */
typedef enum H5_index_t {
	H5_INDEX_UNKNOWN = -1 /* Unknown index type			*/,
	H5_INDEX_NAME /* Index on names 			*/,
	H5_INDEX_CRT_ORDER /* Index on creation order 		*/,
	H5_INDEX_N /* Number of indices defined 		*/
} H5_index_t;
/// Storage info struct used by H5O_info_t and H5F_info_t
typedef struct H5_ih_info_t {
	hsize_t index_size; /* btree and/or list */
	hsize_t heap_size;
} H5_ih_info_t;
/**
 * Functions in H5.c<br>
 * Original signature : <code>herr_t H5open()</code>
 */
herr_t H5open();
/// Original signature : <code>herr_t H5close()</code>
herr_t H5close();
/// Original signature : <code>herr_t H5dont_atexit()</code>
herr_t H5dont_atexit();
/// Original signature : <code>herr_t H5garbage_collect()</code>
herr_t H5garbage_collect();
/// Original signature : <code>herr_t H5set_free_list_limits(int, int, int, int, int, int)</code>
herr_t H5set_free_list_limits(int reg_global_lim, int reg_list_lim, int arr_global_lim, int arr_list_lim, int blk_global_lim, int blk_list_lim);
/// Original signature : <code>herr_t H5get_libversion(unsigned*, unsigned*, unsigned*)</code>
herr_t H5get_libversion(unsigned* majnum, unsigned* minnum, unsigned* relnum);
/// Original signature : <code>herr_t H5check_version(unsigned, unsigned, unsigned)</code>
herr_t H5check_version(unsigned majnum, unsigned minnum, unsigned relnum);



enum H5C_cache_incr_mode {
	H5C_incr__off,
	H5C_incr__threshold
};
enum H5C_cache_flash_incr_mode {
	H5C_flash_incr__off,
	H5C_flash_incr__add_space
};
enum H5C_cache_decr_mode {
	H5C_decr__off,
	H5C_decr__threshold,
	H5C_decr__age_out,
	H5C_decr__age_out_with_threshold
};





typedef struct H5AC_cache_config_t {
	/// general configuration fields:
	int version;
	hbool_t rpt_fcn_enabled;
	hbool_t open_trace_file;
	hbool_t close_trace_file;
	char[1024 + 1] trace_file_name;
	hbool_t evictions_enabled;
	hbool_t set_initial_size;
	size_t initial_size;
	double min_clean_fraction;
	size_t max_size;
	size_t min_size;
	long int epoch_length;
	/// size increase control fields:
	H5C_cache_incr_mode incr_mode;
	double lower_hr_threshold;
	double increment;
	hbool_t apply_max_increment;
	size_t max_increment;
	H5C_cache_flash_incr_mode flash_incr_mode;
	double flash_multiple;
	double flash_threshold;
	/// size decrease control fields:
	H5C_cache_decr_mode decr_mode;
	double upper_hr_threshold;
	double decrement;
	hbool_t apply_max_decrement;
	size_t max_decrement;
	int epochs_before_eviction;
	hbool_t apply_empty_reserve;
	double empty_reserve;
	/// parallel configuration fields:
	int dirty_bytes_threshold;
	enum H5C_cache_incr_mode {
	};
	enum H5C_cache_flash_incr_mode {
	};
	enum H5C_cache_decr_mode {
	};
} H5AC_cache_config_t;



/**
 * Library type values.  Start with `1' instead of `0' because it makes the<br>
 * tracing output look better when hid_t values are large numbers.  Change the<br>
 * TYPE_BITS in H5I.c if the MAXID gets larger than 32 (an assertion will<br>
 * fail otherwise).<br>
 * * When adding types here, add a section to the 'misc19' test in test/tmisc.c<br>
 * to verify that the H5I{inc|dec|get}_ref() routines work correctly with in.
 */
typedef enum H5I_type_t {
	H5I_UNINIT = (-2) /*uninitialized type			    */,
	H5I_BADID = (-1) /*invalid Type				    */,
	H5I_FILE = 1 /*type ID for File objects		    */,
	H5I_GROUP /*type ID for Group objects		    */,
	H5I_DATATYPE /*type ID for Datatype objects		    */,
	H5I_DATASPACE /*type ID for Dataspace objects		    */,
	H5I_DATASET /*type ID for Dataset objects		    */,
	H5I_ATTR /*type ID for Attribute objects		    */,
	H5I_REFERENCE /*type ID for Reference objects		    */,
	H5I_VFL /*type ID for virtual file layer	    */,
	H5I_GENPROP_CLS /*type ID for generic property list classes */,
	H5I_GENPROP_LST /*type ID for generic property lists        */,
	H5I_ERROR_CLASS /*type ID for error classes		    */,
	H5I_ERROR_MSG /*type ID for error messages		    */,
	H5I_ERROR_STACK /*type ID for error stacks		    */,
	H5I_NTYPES /*number of library types, MUST BE LAST!    */
} H5I_type_t;
/// Type of atoms to return to users
typedef int hid_t;
/**
 * Function for freeing objects. This function will be called with an object<br>
 * ID type number and a pointer to the object. The function should free the<br>
 * object and return non-negative to indicate that the object<br>
 * can be removed from the ID type. If the function returns negative<br>
 * (failure) then the object will remain in the ID type.
 */
typedef (*herr_t)(void* voidPtr1);
/// Type of the function to compare objects & keys
typedef int (*H5I_search_func_t)(void* obj, hid_t id, void* key);
/// Original signature : <code>hid_t H5Iregister(H5I_type_t, const void*)</code>
hid_t H5Iregister(H5I_type_t type, const void* object);
/// Original signature : <code>void* H5Iobject_verify(hid_t, H5I_type_t)</code>
void* H5Iobject_verify(hid_t id, H5I_type_t id_type);
/// Original signature : <code>void* H5Iremove_verify(hid_t, H5I_type_t)</code>
void* H5Iremove_verify(hid_t id, H5I_type_t id_type);
/// Original signature : <code>H5I_type_t H5Iget_type(hid_t)</code>
H5I_type_t H5Iget_type(hid_t id);
/// Original signature : <code>hid_t H5Iget_file_id(hid_t)</code>
hid_t H5Iget_file_id(hid_t id);
/**
 * out<br>
 * Original signature : <code>ssize_t H5Iget_name(hid_t, char*, size_t)</code><br>
 * @param id out<br>
 * @param name out
 */
ssize_t H5Iget_name(hid_t id, char* name, size_t size);
/// Original signature : <code>int H5Iinc_ref(hid_t)</code>
int H5Iinc_ref(hid_t id);
/// Original signature : <code>int H5Idec_ref(hid_t)</code>
int H5Idec_ref(hid_t id);
/// Original signature : <code>int H5Iget_ref(hid_t)</code>
int H5Iget_ref(hid_t id);
/// Original signature : <code>H5I_type_t H5Iregister_type(size_t, unsigned, H5I_free_t)</code>
H5I_type_t H5Iregister_type(size_t hash_size, unsigned reserved, H5I_free_t free_func);
/// Original signature : <code>herr_t H5Iclear_type(H5I_type_t, hbool_t)</code>
herr_t H5Iclear_type(H5I_type_t type, hbool_t force);
/// Original signature : <code>herr_t H5Idestroy_type(H5I_type_t)</code>
herr_t H5Idestroy_type(H5I_type_t type);
/// Original signature : <code>int H5Iinc_type_ref(H5I_type_t)</code>
int H5Iinc_type_ref(H5I_type_t type);
/// Original signature : <code>int H5Idec_type_ref(H5I_type_t)</code>
int H5Idec_type_ref(H5I_type_t type);
/// Original signature : <code>int H5Iget_type_ref(H5I_type_t)</code>
int H5Iget_type_ref(H5I_type_t type);
/// Original signature : <code>void* H5Isearch(H5I_type_t, H5I_search_func_t, void*)</code>
void* H5Isearch(H5I_type_t type, H5I_search_func_t func, void* key);
/// Original signature : <code>herr_t H5Inmembers(H5I_type_t, hsize_t*)</code>
herr_t H5Inmembers(H5I_type_t type, hsize_t* num_members);
/// Original signature : <code>htri_t H5Itype_exists(H5I_type_t)</code>
htri_t H5Itype_exists(H5I_type_t type);
/// Original signature : <code>htri_t H5Iis_valid(hid_t)</code>
htri_t H5Iis_valid(hid_t id);
/// The difference between a single file and a set of mounted files
typedef enum H5F_scope_t {
	H5F_SCOPE_LOCAL = 0 /*specified file handle only		*/,
	H5F_SCOPE_GLOBAL = 1 /*entire virtual file			*/
} H5F_scope_t;
/**
 * How does file close behave?<br>
 * H5F_CLOSE_DEFAULT - Use the degree pre-defined by underlining VFL<br>
 * H5F_CLOSE_WEAK    - file closes only after all opened objects are closed<br>
 * H5F_CLOSE_SEMI    - if no opened objects, file is close; otherwise, file<br>
 * close fails<br>
 * H5F_CLOSE_STRONG  - if there are opened objects, close them first, then<br>
 * close file
 */
typedef enum H5F_close_degree_t {
	H5F_CLOSE_DEFAULT = 0,
	H5F_CLOSE_WEAK = 1,
	H5F_CLOSE_SEMI = 2,
	H5F_CLOSE_STRONG = 3
} H5F_close_degree_t;
/// (just size info currently)
typedef struct H5F_info_t {
	hsize_t super_ext_size; /* Superblock extension size */
	sohm_struct sohm;
	struct sohm_struct {
		hsize_t hdr_size; /* Shared object header message header size */
		H5_ih_info_t msgs_info; /* Shared object header message index & heap size */
	};
} H5F_info_t;
/**
 * Types of allocation requests. The values larger than H5FD_MEM_DEFAULT<br>
 * should not change other than adding new types to the end. These numbers<br>
 * might appear in files.
 */
typedef enum H5F_mem_t {
	H5FD_MEM_NOLIST = -1 /*must be negative*/,
	H5FD_MEM_DEFAULT = 0 /*must be zero*/,
	H5FD_MEM_SUPER = 1,
	H5FD_MEM_BTREE = 2,
	H5FD_MEM_DRAW = 3,
	H5FD_MEM_GHEAP = 4,
	H5FD_MEM_LHEAP = 5,
	H5FD_MEM_OHDR = 6,
	H5FD_MEM_NTYPES /*must be last*/
} H5F_mem_t;
/// Library's file format versions
typedef enum H5F_libver_t {
	H5F_LIBVER_EARLIEST /* Use the earliest possible format for storing objects */,
	H5F_LIBVER_LATEST /* Use the latest possible format available for storing objects*/
} H5F_libver_t;
/**
 * Functions in H5F.c<br>
 * Original signature : <code>htri_t H5Fis_hdf5(const char*)</code>
 */
htri_t H5Fis_hdf5(const char* filename);
/// Original signature : <code>hid_t H5Fcreate(const char*, unsigned, hid_t, hid_t)</code>
hid_t H5Fcreate(const char* filename, unsigned flags, hid_t create_plist, hid_t access_plist);
/// Original signature : <code>hid_t H5Fopen(const char*, unsigned, hid_t)</code>
hid_t H5Fopen(const char* filename, unsigned flags, hid_t access_plist);
/// Original signature : <code>hid_t H5Freopen(hid_t)</code>
hid_t H5Freopen(hid_t file_id);
/// Original signature : <code>herr_t H5Fflush(hid_t, H5F_scope_t)</code>
herr_t H5Fflush(hid_t object_id, H5F_scope_t scope);
/// Original signature : <code>herr_t H5Fclose(hid_t)</code>
herr_t H5Fclose(hid_t file_id);
/// Original signature : <code>hid_t H5Fget_create_plist(hid_t)</code>
hid_t H5Fget_create_plist(hid_t file_id);
/// Original signature : <code>hid_t H5Fget_access_plist(hid_t)</code>
hid_t H5Fget_access_plist(hid_t file_id);
/// Original signature : <code>herr_t H5Fget_intent(hid_t, unsigned*)</code>
herr_t H5Fget_intent(hid_t file_id, unsigned* intent);
/// Original signature : <code>ssize_t H5Fget_obj_count(hid_t, unsigned)</code>
ssize_t H5Fget_obj_count(hid_t file_id, unsigned types);
/// Original signature : <code>ssize_t H5Fget_obj_ids(hid_t, unsigned, size_t, hid_t*)</code>
ssize_t H5Fget_obj_ids(hid_t file_id, unsigned types, size_t max_objs, hid_t* obj_id_list);
/// Original signature : <code>herr_t H5Fget_vfd_handle(hid_t, hid_t, void**)</code>
herr_t H5Fget_vfd_handle(hid_t file_id, hid_t fapl, void** file_handle);
/// Original signature : <code>herr_t H5Fmount(hid_t, const char*, hid_t, hid_t)</code>
herr_t H5Fmount(hid_t loc, const char* name, hid_t child, hid_t plist);
/// Original signature : <code>herr_t H5Funmount(hid_t, const char*)</code>
herr_t H5Funmount(hid_t loc, const char* name);
/// Original signature : <code>hssize_t H5Fget_freespace(hid_t)</code>
hssize_t H5Fget_freespace(hid_t file_id);
/// Original signature : <code>herr_t H5Fget_filesize(hid_t, hsize_t*)</code>
herr_t H5Fget_filesize(hid_t file_id, hsize_t* size);
/// Original signature : <code>herr_t H5Fget_mdc_config(hid_t, H5AC_cache_config_t*)</code>
herr_t H5Fget_mdc_config(hid_t file_id, H5AC_cache_config_t* config_ptr);
/// Original signature : <code>herr_t H5Fset_mdc_config(hid_t, H5AC_cache_config_t*)</code>
herr_t H5Fset_mdc_config(hid_t file_id, H5AC_cache_config_t* config_ptr);
/// Original signature : <code>herr_t H5Fget_mdc_hit_rate(hid_t, double*)</code>
herr_t H5Fget_mdc_hit_rate(hid_t file_id, double* hit_rate_ptr);
/// Original signature : <code>herr_t H5Fget_mdc_size(hid_t, size_t*, size_t*, size_t*, int*)</code>
herr_t H5Fget_mdc_size(hid_t file_id, size_t* max_size_ptr, size_t* min_clean_size_ptr, size_t* cur_size_ptr, int* cur_num_entries_ptr);
/// Original signature : <code>herr_t H5Freset_mdc_hit_rate_stats(hid_t)</code>
herr_t H5Freset_mdc_hit_rate_stats(hid_t file_id);
/// Original signature : <code>ssize_t H5Fget_name(hid_t, char*, size_t)</code>
ssize_t H5Fget_name(hid_t obj_id, char* name, size_t size);
/// Original signature : <code>herr_t H5Fget_info(hid_t, H5F_info_t*)</code>
herr_t H5Fget_info(hid_t obj_id, H5F_info_t* bh_info);




/// If this goes over 16 types (0-15), the file format will need to change)
typedef enum H5T_class_t {
	H5T_NO_CLASS = -1 /*error                                      */,
	H5T_INTEGER = 0 /*integer types                              */,
	H5T_FLOAT = 1 /*floating-point types                       */,
	H5T_TIME = 2 /*date and time types                        */,
	H5T_STRING = 3 /*character string types                     */,
	H5T_BITFIELD = 4 /*bit field types                            */,
	H5T_OPAQUE = 5 /*opaque types                               */,
	H5T_COMPOUND = 6 /*compound types                             */,
	H5T_REFERENCE = 7 /*reference types                            */,
	H5T_ENUM = 8 /*enumeration types                          */,
	H5T_VLEN = 9 /*Variable-Length types                      */,
	H5T_ARRAY = 10 /*Array types                                */,
	H5T_NCLASSES /*this must be last                          */
} H5T_class_t;
/// Byte orders
typedef enum H5T_order_t {
	H5T_ORDER_ERROR = -1 /*error                                      */,
	H5T_ORDER_LE = 0 /*little endian                              */,
	H5T_ORDER_BE = 1 /*bit endian                                 */,
	H5T_ORDER_VAX = 2 /*VAX mixed endian                           */,
	H5T_ORDER_NONE = 3 /*no particular order (strings, bits,..)     */
} H5T_order_t;
/// Types of integer sign schemes
typedef enum H5T_sign_t {
	H5T_SGN_ERROR = -1 /*error                                      */,
	H5T_SGN_NONE = 0 /*this is an unsigned type                   */,
	H5T_SGN_2 = 1 /*two's complement                           */,
	H5T_NSGN = 2 /*this must be last!                         */
} H5T_sign_t;
/// Floating-point normalization schemes
typedef enum H5T_norm_t {
	H5T_NORM_ERROR = -1 /*error                                      */,
	H5T_NORM_IMPLIED = 0 /*msb of mantissa isn't stored, always 1     */,
	H5T_NORM_MSBSET = 1 /*msb of mantissa is always 1                */,
	H5T_NORM_NONE = 2 /*not normalized                             */
} H5T_norm_t;
/**
 * Character set to use for text strings.  Do not change these values since<br>
 * they appear in HDF5 files!
 */
typedef enum H5T_cset_t {
	H5T_CSET_ERROR = -1 /*error                                      */,
	H5T_CSET_ASCII = 0 /*US ASCII                                   */,
	H5T_CSET_UTF8 = 1 /*UTF-8 Unicode encoding		     */,
	H5T_CSET_RESERVED_2 = 2 /*reserved for later use		     */,
	H5T_CSET_RESERVED_3 = 3 /*reserved for later use		     */,
	H5T_CSET_RESERVED_4 = 4 /*reserved for later use		     */,
	H5T_CSET_RESERVED_5 = 5 /*reserved for later use		     */,
	H5T_CSET_RESERVED_6 = 6 /*reserved for later use		     */,
	H5T_CSET_RESERVED_7 = 7 /*reserved for later use		     */,
	H5T_CSET_RESERVED_8 = 8 /*reserved for later use		     */,
	H5T_CSET_RESERVED_9 = 9 /*reserved for later use		     */,
	H5T_CSET_RESERVED_10 = 10 /*reserved for later use		     */,
	H5T_CSET_RESERVED_11 = 11 /*reserved for later use		     */,
	H5T_CSET_RESERVED_12 = 12 /*reserved for later use		     */,
	H5T_CSET_RESERVED_13 = 13 /*reserved for later use		     */,
	H5T_CSET_RESERVED_14 = 14 /*reserved for later use		     */,
	H5T_CSET_RESERVED_15 = 15 /*reserved for later use		     */
} H5T_cset_t;
/**
 * Type of padding to use in character strings.  Do not change these values<br>
 * since they appear in HDF5 files!
 */
typedef enum H5T_str_t {
	H5T_STR_ERROR = -1 /*error                                      */,
	H5T_STR_NULLTERM = 0 /*null terminate like in C                   */,
	H5T_STR_NULLPAD = 1 /*pad with nulls                             */,
	H5T_STR_SPACEPAD = 2 /*pad with spaces like in Fortran            */,
	H5T_STR_RESERVED_3 = 3 /*reserved for later use		     */,
	H5T_STR_RESERVED_4 = 4 /*reserved for later use		     */,
	H5T_STR_RESERVED_5 = 5 /*reserved for later use		     */,
	H5T_STR_RESERVED_6 = 6 /*reserved for later use		     */,
	H5T_STR_RESERVED_7 = 7 /*reserved for later use		     */,
	H5T_STR_RESERVED_8 = 8 /*reserved for later use		     */,
	H5T_STR_RESERVED_9 = 9 /*reserved for later use		     */,
	H5T_STR_RESERVED_10 = 10 /*reserved for later use		     */,
	H5T_STR_RESERVED_11 = 11 /*reserved for later use		     */,
	H5T_STR_RESERVED_12 = 12 /*reserved for later use		     */,
	H5T_STR_RESERVED_13 = 13 /*reserved for later use		     */,
	H5T_STR_RESERVED_14 = 14 /*reserved for later use		     */,
	H5T_STR_RESERVED_15 = 15 /*reserved for later use		     */
} H5T_str_t;
/// Type of padding to use in other atomic types
typedef enum H5T_pad_t {
	H5T_PAD_ERROR = -1 /*error                                      */,
	H5T_PAD_ZERO = 0 /*always set to zero                         */,
	H5T_PAD_ONE = 1 /*always set to one                          */,
	H5T_PAD_BACKGROUND = 2 /*set to background value                    */,
	H5T_NPAD = 3 /*THIS MUST BE LAST                          */
} H5T_pad_t;
/// Commands sent to conversion functions
typedef enum H5T_cmd_t {
	H5T_CONV_INIT = 0 /*query and/or initialize private data	     */,
	H5T_CONV_CONV = 1 /*convert data from source to dest datatype */,
	H5T_CONV_FREE = 2 /*function is being removed from path	     */
} H5T_cmd_t;
/// How is the `bkg' buffer used by the conversion function?
typedef enum H5T_bkg_t {
	H5T_BKG_NO = 0 /*background buffer is not needed, send NULL */,
	H5T_BKG_TEMP = 1 /*bkg buffer used as temp storage only       */,
	H5T_BKG_YES = 2 /*init bkg buf with data before conversion   */
} H5T_bkg_t;
/// Type conversion client data
typedef struct H5T_cdata_t {
	H5T_cmd_t command; /*what should the conversion function do?    */
	H5T_bkg_t need_bkg; /*is the background buffer needed?	     */
	hbool_t recalc; /*recalculate private data		     */
	void* priv; /*private data				     */
} H5T_cdata_t;
/// Conversion function persistence
typedef enum H5T_pers_t {
	H5T_PERS_DONTCARE = -1 /*wild card				     */,
	H5T_PERS_HARD = 0 /*hard conversion function		     */,
	H5T_PERS_SOFT = 1 /*soft conversion function		     */
} H5T_pers_t;
/// The order to retrieve atomic native datatype
typedef enum H5T_direction_t {
	H5T_DIR_DEFAULT = 0 /*default direction is inscendent            */,
	H5T_DIR_ASCEND = 1 /*in inscendent order                        */,
	H5T_DIR_DESCEND = 2 /*in descendent order                        */
} H5T_direction_t;
/// The exception type passed into the conversion callback function
typedef enum H5T_conv_except_t {
	H5T_CONV_EXCEPT_RANGE_HI = 0 /*source value is greater than destination's range */,
	H5T_CONV_EXCEPT_RANGE_LOW = 1 /*source value is less than destination's range    */,
	H5T_CONV_EXCEPT_PRECISION = 2 /*source value loses precision in destination      */,
	H5T_CONV_EXCEPT_TRUNCATE = 3 /*source value is truncated in destination         */,
	H5T_CONV_EXCEPT_PINF = 4 /*source value is positive infinity(floating number) */,
	H5T_CONV_EXCEPT_NINF = 5 /*source value is negative infinity(floating number) */,
	H5T_CONV_EXCEPT_NAN = 6 /*source value is NaN(floating number)             */
} H5T_conv_except_t;
/// The return value from conversion callback function H5T_conv_except_func_t
typedef enum H5T_conv_ret_t {
	H5T_CONV_ABORT = -1 /*abort conversion                           */,
	H5T_CONV_UNHANDLED = 0 /*callback function failed to handle the exception      */,
	H5T_CONV_HANDLED = 1 /*callback function handled the exception successfully  */
} H5T_conv_ret_t;
/// (This is only used for VL sequences, not VL strings, which are stored in char *'s)
typedef struct hvl_t {
	size_t len; /* Length of VL data (in base type units) */
	void* p; /* Pointer to VL data */
} hvl_t;
/// All datatype conversion functions are...
typedef (*herr_t)(hid_t src_id, hid_t dst_id, H5T_cdata_t* cdata, size_t nelmts, size_t buf_stride, size_t bkg_stride, void* buf, void* bkg, hid_t dset_xfer_plist);
/**
 * Exception handler.  If an exception like overflow happenes during conversion,<br>
 * this function is called if it's registered through H5Pset_type_conv_cb.
 */
typedef H5T_conv_ret_t (*H5T_conv_except_func_t)(H5T_conv_except_t except_type, hid_t src_id, hid_t dst_id, void* src_buf, void* dst_buf, void* user_data);
extern hid_t H5T_IEEE_F32BE_g;
extern hid_t H5T_IEEE_F32LE_g;
extern hid_t H5T_IEEE_F64BE_g;
extern hid_t H5T_IEEE_F64LE_g;
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
extern hid_t H5T_UNIX_D32BE_g;
extern hid_t H5T_UNIX_D32LE_g;
extern hid_t H5T_UNIX_D64BE_g;
extern hid_t H5T_UNIX_D64LE_g;
extern hid_t H5T_C_S1_g;
extern hid_t H5T_FORTRAN_S1_g;
extern hid_t H5T_VAX_F32_g;
extern hid_t H5T_VAX_F64_g;
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
/**
 * Operations defined on all datatypes<br>
 * Original signature : <code>hid_t H5Tcreate(H5T_class_t, size_t)</code>
 */
hid_t H5Tcreate(H5T_class_t type, size_t size);
/// Original signature : <code>hid_t H5Tcopy(hid_t)</code>
hid_t H5Tcopy(hid_t type_id);
/// Original signature : <code>herr_t H5Tclose(hid_t)</code>
herr_t H5Tclose(hid_t type_id);
/// Original signature : <code>htri_t H5Tequal(hid_t, hid_t)</code>
htri_t H5Tequal(hid_t type1_id, hid_t type2_id);
/// Original signature : <code>herr_t H5Tlock(hid_t)</code>
herr_t H5Tlock(hid_t type_id);
/// Original signature : <code>herr_t H5Tcommit2(hid_t, const char*, hid_t, hid_t, hid_t, hid_t)</code>
herr_t H5Tcommit2(hid_t loc_id, const char* name, hid_t type_id, hid_t lcpl_id, hid_t tcpl_id, hid_t tapl_id);
/// Original signature : <code>hid_t H5Topen2(hid_t, const char*, hid_t)</code>
hid_t H5Topen2(hid_t loc_id, const char* name, hid_t tapl_id);
/// Original signature : <code>herr_t H5Tcommit_anon(hid_t, hid_t, hid_t, hid_t)</code>
herr_t H5Tcommit_anon(hid_t loc_id, hid_t type_id, hid_t tcpl_id, hid_t tapl_id);
/// Original signature : <code>hid_t H5Tget_create_plist(hid_t)</code>
hid_t H5Tget_create_plist(hid_t type_id);
/// Original signature : <code>htri_t H5Tcommitted(hid_t)</code>
htri_t H5Tcommitted(hid_t type_id);
/// Original signature : <code>herr_t H5Tencode(hid_t, void*, size_t*)</code>
herr_t H5Tencode(hid_t obj_id, void* buf, size_t* nalloc);
/// Original signature : <code>hid_t H5Tdecode(const void*)</code>
hid_t H5Tdecode(const void* buf);
/**
 * Operations defined on compound datatypes<br>
 * Original signature : <code>herr_t H5Tinsert(hid_t, const char*, size_t, hid_t)</code>
 */
herr_t H5Tinsert(hid_t parent_id, const char* name, size_t offset, hid_t member_id);
/// Original signature : <code>herr_t H5Tpack(hid_t)</code>
herr_t H5Tpack(hid_t type_id);
/**
 * Operations defined on enumeration datatypes<br>
 * Original signature : <code>hid_t H5Tenum_create(hid_t)</code>
 */
hid_t H5Tenum_create(hid_t base_id);
/// Original signature : <code>herr_t H5Tenum_insert(hid_t, const char*, const void*)</code>
herr_t H5Tenum_insert(hid_t type, const char* name, const void* value);
/**
 * out<br>
 * Original signature : <code>herr_t H5Tenum_nameof(hid_t, const void*, char*, size_t)</code><br>
 * @param type out<br>
 * @param value out<br>
 * @param name out
 */
herr_t H5Tenum_nameof(hid_t type, const void* value, char* name, size_t size);
/**
 * Original signature : <code>herr_t H5Tenum_valueof(hid_t, const char*, void*)</code><br>
 * @param value out
 */
herr_t H5Tenum_valueof(hid_t type, const char* name, void* value);
/**
 * Operations defined on variable-length datatypes<br>
 * Original signature : <code>hid_t H5Tvlen_create(hid_t)</code>
 */
hid_t H5Tvlen_create(hid_t base_id);
/**
 * Operations defined on array datatypes<br>
 * Original signature : <code>hid_t H5Tarray_create2(hid_t, unsigned, const hsize_t[])</code><br>
 * @param dim ndims
 */
hid_t H5Tarray_create2(hid_t base_id, unsigned ndims, const hsize_t dim[]);
/// Original signature : <code>int H5Tget_array_ndims(hid_t)</code>
int H5Tget_array_ndims(hid_t type_id);
/// Original signature : <code>int H5Tget_array_dims2(hid_t, hsize_t[])</code>
int H5Tget_array_dims2(hid_t type_id, hsize_t dims[]);
/**
 * Operations defined on opaque datatypes<br>
 * Original signature : <code>herr_t H5Tset_tag(hid_t, const char*)</code>
 */
herr_t H5Tset_tag(hid_t type, const char* tag);
/// Original signature : <code>char* H5Tget_tag(hid_t)</code>
char* H5Tget_tag(hid_t type);
/**
 * Querying property values<br>
 * Original signature : <code>hid_t H5Tget_super(hid_t)</code>
 */
hid_t H5Tget_super(hid_t type);
/// Original signature : <code>H5T_class_t H5Tget_class(hid_t)</code>
H5T_class_t H5Tget_class(hid_t type_id);
/// Original signature : <code>htri_t H5Tdetect_class(hid_t, H5T_class_t)</code>
htri_t H5Tdetect_class(hid_t type_id, H5T_class_t cls);
/// Original signature : <code>size_t H5Tget_size(hid_t)</code>
size_t H5Tget_size(hid_t type_id);
/// Original signature : <code>H5T_order_t H5Tget_order(hid_t)</code>
H5T_order_t H5Tget_order(hid_t type_id);
/// Original signature : <code>size_t H5Tget_precision(hid_t)</code>
size_t H5Tget_precision(hid_t type_id);
/// Original signature : <code>int H5Tget_offset(hid_t)</code>
int H5Tget_offset(hid_t type_id);
/**
 * out<br>
 * Original signature : <code>herr_t H5Tget_pad(hid_t, H5T_pad_t*, H5T_pad_t*)</code><br>
 * @param type_id out<br>
 * @param lsb out<br>
 * @param msb out
 */
herr_t H5Tget_pad(hid_t type_id, H5T_pad_t* lsb, H5T_pad_t* msb);
/// Original signature : <code>H5T_sign_t H5Tget_sign(hid_t)</code>
H5T_sign_t H5Tget_sign(hid_t type_id);
/**
 * out<br>
 * Original signature : <code>herr_t H5Tget_fields(hid_t, size_t*, size_t*, size_t*, size_t*, size_t*)</code><br>
 * @param type_id out<br>
 * @param spos out<br>
 * @param epos out<br>
 * @param esize out<br>
 * @param mpos out<br>
 * @param msize out
 */
herr_t H5Tget_fields(hid_t type_id, size_t* spos, size_t* epos, size_t* esize, size_t* mpos, size_t* msize);
/// Original signature : <code>size_t H5Tget_ebias(hid_t)</code>
size_t H5Tget_ebias(hid_t type_id);
/// Original signature : <code>H5T_norm_t H5Tget_norm(hid_t)</code>
H5T_norm_t H5Tget_norm(hid_t type_id);
/// Original signature : <code>H5T_pad_t H5Tget_inpad(hid_t)</code>
H5T_pad_t H5Tget_inpad(hid_t type_id);
/// Original signature : <code>H5T_str_t H5Tget_strpad(hid_t)</code>
H5T_str_t H5Tget_strpad(hid_t type_id);
/// Original signature : <code>int H5Tget_nmembers(hid_t)</code>
int H5Tget_nmembers(hid_t type_id);
/// Original signature : <code>char* H5Tget_member_name(hid_t, unsigned)</code>
char* H5Tget_member_name(hid_t type_id, unsigned membno);
/// Original signature : <code>int H5Tget_member_index(hid_t, const char*)</code>
int H5Tget_member_index(hid_t type_id, const char* name);
/// Original signature : <code>size_t H5Tget_member_offset(hid_t, unsigned)</code>
size_t H5Tget_member_offset(hid_t type_id, unsigned membno);
/// Original signature : <code>H5T_class_t H5Tget_member_class(hid_t, unsigned)</code>
H5T_class_t H5Tget_member_class(hid_t type_id, unsigned membno);
/// Original signature : <code>hid_t H5Tget_member_type(hid_t, unsigned)</code>
hid_t H5Tget_member_type(hid_t type_id, unsigned membno);
/**
 * out<br>
 * Original signature : <code>herr_t H5Tget_member_value(hid_t, unsigned, void*)</code><br>
 * @param type_id out<br>
 * @param membno out<br>
 * @param value out
 */
herr_t H5Tget_member_value(hid_t type_id, unsigned membno, void* value);
/// Original signature : <code>H5T_cset_t H5Tget_cset(hid_t)</code>
H5T_cset_t H5Tget_cset(hid_t type_id);
/// Original signature : <code>htri_t H5Tis_variable_str(hid_t)</code>
htri_t H5Tis_variable_str(hid_t type_id);
/// Original signature : <code>hid_t H5Tget_native_type(hid_t, H5T_direction_t)</code>
hid_t H5Tget_native_type(hid_t type_id, H5T_direction_t direction);
/**
 * Setting property values<br>
 * Original signature : <code>herr_t H5Tset_size(hid_t, size_t)</code>
 */
herr_t H5Tset_size(hid_t type_id, size_t size);
/// Original signature : <code>herr_t H5Tset_order(hid_t, H5T_order_t)</code>
herr_t H5Tset_order(hid_t type_id, H5T_order_t order);
/// Original signature : <code>herr_t H5Tset_precision(hid_t, size_t)</code>
herr_t H5Tset_precision(hid_t type_id, size_t prec);
/// Original signature : <code>herr_t H5Tset_offset(hid_t, size_t)</code>
herr_t H5Tset_offset(hid_t type_id, size_t offset);
/// Original signature : <code>herr_t H5Tset_pad(hid_t, H5T_pad_t, H5T_pad_t)</code>
herr_t H5Tset_pad(hid_t type_id, H5T_pad_t lsb, H5T_pad_t msb);
/// Original signature : <code>herr_t H5Tset_sign(hid_t, H5T_sign_t)</code>
herr_t H5Tset_sign(hid_t type_id, H5T_sign_t sign);
/// Original signature : <code>herr_t H5Tset_fields(hid_t, size_t, size_t, size_t, size_t, size_t)</code>
herr_t H5Tset_fields(hid_t type_id, size_t spos, size_t epos, size_t esize, size_t mpos, size_t msize);
/// Original signature : <code>herr_t H5Tset_ebias(hid_t, size_t)</code>
herr_t H5Tset_ebias(hid_t type_id, size_t ebias);
/// Original signature : <code>herr_t H5Tset_norm(hid_t, H5T_norm_t)</code>
herr_t H5Tset_norm(hid_t type_id, H5T_norm_t norm);
/// Original signature : <code>herr_t H5Tset_inpad(hid_t, H5T_pad_t)</code>
herr_t H5Tset_inpad(hid_t type_id, H5T_pad_t pad);
/// Original signature : <code>herr_t H5Tset_cset(hid_t, H5T_cset_t)</code>
herr_t H5Tset_cset(hid_t type_id, H5T_cset_t cset);
/// Original signature : <code>herr_t H5Tset_strpad(hid_t, H5T_str_t)</code>
herr_t H5Tset_strpad(hid_t type_id, H5T_str_t strpad);
/**
 * Type conversion database<br>
 * Original signature : <code>herr_t H5Tregister(H5T_pers_t, const char*, hid_t, hid_t, H5T_conv_t)</code>
 */
herr_t H5Tregister(H5T_pers_t pers, const char* name, hid_t src_id, hid_t dst_id, H5T_conv_t func);
/// Original signature : <code>herr_t H5Tunregister(H5T_pers_t, const char*, hid_t, hid_t, H5T_conv_t)</code>
herr_t H5Tunregister(H5T_pers_t pers, const char* name, hid_t src_id, hid_t dst_id, H5T_conv_t func);
/// Original signature : <code>H5T_conv_t H5Tfind(hid_t, hid_t, H5T_cdata_t**)</code>
H5T_conv_t H5Tfind(hid_t src_id, hid_t dst_id, H5T_cdata_t** pcdata);
/// Original signature : <code>htri_t H5Tcompiler_conv(hid_t, hid_t)</code>
htri_t H5Tcompiler_conv(hid_t src_id, hid_t dst_id);
/// Original signature : <code>herr_t H5Tconvert(hid_t, hid_t, size_t, void*, void*, hid_t)</code>
herr_t H5Tconvert(hid_t src_id, hid_t dst_id, size_t nelmts, void* buf, void* background, hid_t plist_id);
/**
 * Function prototypes<br>
 * Original signature : <code>herr_t H5Tcommit1(hid_t, const char*, hid_t)</code>
 */
herr_t H5Tcommit1(hid_t loc_id, const char* name, hid_t type_id);
/// Original signature : <code>hid_t H5Topen1(hid_t, const char*)</code>
hid_t H5Topen1(hid_t loc_id, const char* name);
/**
 * Original signature : <code>hid_t H5Tarray_create1(hid_t, int, const hsize_t[], const int[])</code><br>
 * @param dim ndims<br>
 * @param perm ndims
 */
hid_t H5Tarray_create1(hid_t base_id, int ndims, const hsize_t dim[], const int perm[]);
/// Original signature : <code>int H5Tget_array_dims1(hid_t, hsize_t[], int[])</code>
int H5Tget_array_dims1(hid_t type_id, hsize_t dims[], int perm[]);
/// Original signature : <code>hid_t H5PTcreate_fl(hid_t, const char*, hid_t, hsize_t, int)</code>
hid_t H5PTcreate_fl(hid_t loc_id, const char* dset_name, hid_t dtype_id, hsize_t chunk_size, int compression);
/// Original signature : <code>hid_t H5PTopen(hid_t, const char*)</code>
hid_t H5PTopen(hid_t loc_id, const char* dset_name);
/// Original signature : <code>herr_t H5PTclose(hid_t)</code>
herr_t H5PTclose(hid_t table_id);
/// Original signature : <code>herr_t H5PTappend(hid_t, size_t, const void*)</code>
herr_t H5PTappend(hid_t table_id, size_t nrecords, const void* data);
/// Original signature : <code>herr_t H5PTget_next(hid_t, size_t, void*)</code>
herr_t H5PTget_next(hid_t table_id, size_t nrecords, void* data);
/// Original signature : <code>herr_t H5PTread_packets(hid_t, hsize_t, size_t, void*)</code>
herr_t H5PTread_packets(hid_t table_id, hsize_t start, size_t nrecords, void* data);
/// Original signature : <code>herr_t H5PTget_num_packets(hid_t, hsize_t*)</code>
herr_t H5PTget_num_packets(hid_t table_id, hsize_t* nrecords);
/// Original signature : <code>herr_t H5PTis_valid(hid_t)</code>
herr_t H5PTis_valid(hid_t table_id);
/// Original signature : <code>herr_t H5PTcreate_index(hid_t)</code>
herr_t H5PTcreate_index(hid_t table_id);
/// Original signature : <code>herr_t H5PTset_index(hid_t, hsize_t)</code>
herr_t H5PTset_index(hid_t table_id, hsize_t pt_index);
/// Original signature : <code>herr_t H5PTget_index(hid_t, hsize_t*)</code>
herr_t H5PTget_index(hid_t table_id, hsize_t* pt_index);
