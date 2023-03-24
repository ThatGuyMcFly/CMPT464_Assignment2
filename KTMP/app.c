# 1 "/usr/include/newlib/sys/config.h"



# 41 "/usr/include/newlib/machine/_default_types.h"
typedef signed char __int8_t;

typedef unsigned char __uint8_t;











typedef short int __int16_t;

typedef short unsigned int __uint16_t;
# 77 "/usr/include/newlib/machine/_default_types.h"
typedef long int __int32_t;

typedef long unsigned int __uint32_t;
# 103 "/usr/include/newlib/machine/_default_types.h"
typedef long long int __int64_t;

typedef long long unsigned int __uint64_t;
# 134 "/usr/include/newlib/machine/_default_types.h"
typedef signed char __int_least8_t;

typedef unsigned char __uint_least8_t;
# 160 "/usr/include/newlib/machine/_default_types.h"
typedef short int __int_least16_t;

typedef short unsigned int __uint_least16_t;
# 182 "/usr/include/newlib/machine/_default_types.h"
typedef long int __int_least32_t;

typedef long unsigned int __uint_least32_t;















typedef long long int __int_least64_t;

typedef long long unsigned int __uint_least64_t;











typedef long long int __intmax_t;







typedef long long unsigned int __uintmax_t;







typedef int __intptr_t;

typedef unsigned int __uintptr_t;
# 46 "/usr/include/newlib/sys/cdefs.h"

# 143 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h"
typedef int ptrdiff_t;
# 209 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h"
typedef unsigned int size_t;
# 321 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h"
typedef unsigned int wchar_t;
# 350 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stddef.h"
typedef unsigned int wint_t;
# 25 "/usr/include/newlib/sys/_types.h"





typedef long __blkcnt_t;



typedef long __blksize_t;



typedef __uint64_t __fsblkcnt_t;



typedef __uint32_t __fsfilcnt_t;



typedef long _off_t;





typedef int __pid_t;



typedef short __dev_t;



typedef unsigned short __uid_t;


typedef unsigned short __gid_t;



typedef __uint32_t __id_t;







typedef unsigned short __ino_t;














typedef __uint32_t __mode_t;





__extension__ typedef long long _off64_t;





typedef _off_t __off_t;


typedef _off64_t __loff_t;


typedef long __key_t;







typedef long _fpos_t;














typedef unsigned int __size_t;















typedef signed int _ssize_t;










typedef _ssize_t __ssize_t;



typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    unsigned char __wchb[4];
  } __value;
} _mbstate_t;




typedef void *_iconv_t;






typedef unsigned long __clock_t;






typedef __int_least64_t __time_t;





typedef unsigned long __clockid_t;


typedef unsigned long __timer_t;


typedef __uint8_t __sa_family_t;



typedef __uint32_t __socklen_t;


typedef int __nl_item;
typedef unsigned short __nlink_t;
typedef long __suseconds_t;
typedef unsigned long __useconds_t;







typedef __builtin_va_list __va_list;
# 16 "/usr/include/newlib/sys/reent.h"






typedef unsigned long __ULong;
# 11 "/usr/include/newlib/sys/lock.h"
typedef int _LOCK_T;
typedef int _LOCK_RECURSIVE_T;
# 35 "/usr/include/newlib/sys/reent.h"
typedef _LOCK_RECURSIVE_T _flock_t;







struct _reent;

struct __locale_t;






struct _Bigint
{
  struct _Bigint *_next;
  int _k, _maxwds, _sign, _wds;
  __ULong _x[1];
};


struct __tm
{
  int __tm_sec;
  int __tm_min;
  int __tm_hour;
  int __tm_mday;
  int __tm_mon;
  int __tm_year;
  int __tm_wday;
  int __tm_yday;
  int __tm_isdst;
};







struct _on_exit_args {
 void * _fnargs[32];
 void * _dso_handle[32];

 __ULong _fntypes;


 __ULong _is_cxa;
};










struct _atexit {
 struct _atexit *_next;
 int _ind;

 void (*_fns[32])(void);
        struct _on_exit_args _on_exit_args;
};
# 122 "/usr/include/newlib/sys/reent.h"
struct __sbuf {
 unsigned char *_base;
 int _size;
};
# 186 "/usr/include/newlib/sys/reent.h"
struct __sFILE {
  unsigned char *_p;
  int _r;
  int _w;
  short _flags;
  short _file;
  struct __sbuf _bf;
  int _lbfsize;






  void * _cookie;

  int (*_read) (struct _reent *, void *,
        char *, int);
  int (*_write) (struct _reent *, void *,
         const char *,
         int);
  _fpos_t (*_seek) (struct _reent *, void *, _fpos_t, int);
  int (*_close) (struct _reent *, void *);


  struct __sbuf _ub;
  unsigned char *_up;
  int _ur;


  unsigned char _ubuf[3];
  unsigned char _nbuf[1];


  struct __sbuf _lb;


  int _blksize;
  _off_t _offset;


  struct _reent *_data;



  _flock_t _lock;

  _mbstate_t _mbstate;
  int _flags2;
};
# 292 "/usr/include/newlib/sys/reent.h"
typedef struct __sFILE __FILE;



struct _glue
{
  struct _glue *_next;
  int _niobs;
  __FILE *_iobs;
};
# 324 "/usr/include/newlib/sys/reent.h"
struct _rand48 {
  unsigned short _seed[3];
  unsigned short _mult[3];
  unsigned short _add;




};
# 613 "/usr/include/newlib/sys/reent.h"
struct _reent
{
  int _errno;




  __FILE *_stdin, *_stdout, *_stderr;

  int _inc;
  char _emergency[25];


  int _unspecified_locale_info;
  struct __locale_t *_locale;

  int __sdidinit;

  void (*__cleanup) (struct _reent *);


  struct _Bigint *_result;
  int _result_k;
  struct _Bigint *_p5s;
  struct _Bigint **_freelist;


  int _cvtlen;
  char *_cvtbuf;

  union
    {
      struct
        {
          unsigned int _unused_rand;
          char * _strtok_last;
          char _asctime_buf[26];
          struct __tm _localtime_buf;
          int _gamma_signgam;
          __extension__ unsigned long long _rand_next;
          struct _rand48 _r48;
          _mbstate_t _mblen_state;
          _mbstate_t _mbtowc_state;
          _mbstate_t _wctomb_state;
          char _l64a_buf[8];
          char _signal_buf[24];
          int _getdate_err;
          _mbstate_t _mbrlen_state;
          _mbstate_t _mbrtowc_state;
          _mbstate_t _mbsrtowcs_state;
          _mbstate_t _wcrtomb_state;
          _mbstate_t _wcsrtombs_state;
   int _h_errno;
        } _reent;



      struct
        {

          unsigned char * _nextf[30];
          unsigned int _nmalloc[30];
        } _unused;
    } _new;



  struct _atexit *_atexit;
  struct _atexit _atexit0;



  void (**(_sig_func))(int);




  struct _glue __sglue;

  __FILE __sf[3];

};
# 819 "/usr/include/newlib/sys/reent.h"
extern struct _reent *_impure_ptr ;
extern struct _reent *const _global_impure_ptr ;

void _reclaim_reent (struct _reent *);
# 13 "/usr/include/newlib/time.h"






# 28 "/usr/include/newlib/sys/types.h"
typedef __uint8_t u_int8_t;


typedef __uint16_t u_int16_t;


typedef __uint32_t u_int32_t;


typedef __uint64_t u_int64_t;

typedef __intptr_t register_t;






# 20 "/usr/include/newlib/sys/_stdint.h"
typedef __int8_t int8_t ;



typedef __uint8_t uint8_t ;







typedef __int16_t int16_t ;



typedef __uint16_t uint16_t ;







typedef __int32_t int32_t ;



typedef __uint32_t uint32_t ;







typedef __int64_t int64_t ;



typedef __uint64_t uint64_t ;






typedef __intmax_t intmax_t;




typedef __uintmax_t uintmax_t;




typedef __intptr_t intptr_t;




typedef __uintptr_t uintptr_t;
# 97 "/usr/include/newlib/sys/types.h"
typedef __blkcnt_t blkcnt_t;




typedef __blksize_t blksize_t;




typedef unsigned long clock_t;





typedef __int_least64_t time_t;





typedef long daddr_t;



typedef char * caddr_t;




typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;




typedef __id_t id_t;




typedef __ino_t ino_t;
# 157 "/usr/include/newlib/sys/types.h"
typedef __off_t off_t;



typedef __dev_t dev_t;



typedef __uid_t uid_t;



typedef __gid_t gid_t;




typedef __pid_t pid_t;




typedef __key_t key_t;




typedef _ssize_t ssize_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __clockid_t clockid_t;





typedef __timer_t timer_t;





typedef __useconds_t useconds_t;




typedef __suseconds_t suseconds_t;



typedef __int64_t sbintime_t;


# 47 "/usr/include/newlib/sys/_timespec.h"
struct timespec {
 time_t tv_sec;
 long tv_nsec;
};
# 58 "/usr/include/newlib/sys/timespec.h"
struct itimerspec {
 struct timespec it_interval;
 struct timespec it_value;
};
# 30 "/usr/include/newlib/time.h"







struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;






};

clock_t clock (void);
double difftime (time_t _time2, time_t _time1);
time_t mktime (struct tm *_timeptr);
time_t time (time_t *_timer);

char *asctime (const struct tm *_tblock);
char *ctime (const time_t *_time);
struct tm *gmtime (const time_t *_timer);
struct tm *localtime (const time_t *_timer);

size_t strftime (char *restrict _s,
        size_t _maxsize, const char *restrict _fmt,
        const struct tm *restrict _t);







char *asctime_r (const struct tm *restrict,
     char *restrict);
char *ctime_r (const time_t *, char *);
struct tm *gmtime_r (const time_t *restrict,
     struct tm *restrict);
struct tm *localtime_r (const time_t *restrict,
     struct tm *restrict);


# 103 "/usr/include/newlib/time.h"
void _tzset_r (struct _reent *);

typedef struct __tzrule_struct
{
  char ch;
  int m;
  int n;
  int d;
  int s;
  time_t change;
  long offset;
} __tzrule_type;

typedef struct __tzinfo_struct
{
  int __tznorth;
  int __tzyear;
  __tzrule_type __tzrule[2];
} __tzinfo_type;

__tzinfo_type *__gettzinfo (void);
# 37 "/usr/include/newlib/stdio.h"



# 40 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stdarg.h"
typedef __builtin_va_list __gnuc_va_list;
# 63 "/usr/include/newlib/stdio.h"



typedef __FILE FILE;






typedef _fpos_t fpos_t;





# 186 "/usr/include/newlib/stdio.h"
FILE * tmpfile (void);
char * tmpnam (char *);



int fclose (FILE *);
int fflush (FILE *);
FILE * freopen (const char *restrict, const char *restrict, FILE *restrict);
void setbuf (FILE *restrict, char *restrict);
int setvbuf (FILE *restrict, char *restrict, int, size_t);
int fprintf (FILE *restrict, const char *restrict, ...)
               __attribute__ ((__format__ (__printf__, 2, 3)));
int fscanf (FILE *restrict, const char *restrict, ...)
               __attribute__ ((__format__ (__scanf__, 2, 3)));
int printf (const char *restrict, ...)
               __attribute__ ((__format__ (__printf__, 1, 2)));
int scanf (const char *restrict, ...)
               __attribute__ ((__format__ (__scanf__, 1, 2)));
int sscanf (const char *restrict, const char *restrict, ...)
               __attribute__ ((__format__ (__scanf__, 2, 3)));
int vfprintf (FILE *restrict, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 2, 0)));
int vprintf (const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 1, 0)));
int vsprintf (char *restrict, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 2, 0)));
int fgetc (FILE *);
char * fgets (char *restrict, int, FILE *restrict);
int fputc (int, FILE *);
int fputs (const char *restrict, FILE *restrict);
int getc (FILE *);
int getchar (void);
char * gets (char *);
int putc (int, FILE *);
int putchar (int);
int puts (const char *);
int ungetc (int, FILE *);
size_t fread (void *restrict, size_t _size, size_t _n, FILE *restrict);
size_t fwrite (const void *restrict , size_t _size, size_t _n, FILE *);



int fgetpos (FILE *restrict, fpos_t *restrict);

int fseek (FILE *, long, int);



int fsetpos (FILE *, const fpos_t *);

long ftell ( FILE *);
void rewind (FILE *);
void clearerr (FILE *);
int feof (FILE *);
int ferror (FILE *);
void perror (const char *);

FILE * fopen (const char *restrict _name, const char *restrict _type);
int sprintf (char *restrict, const char *restrict, ...)
               __attribute__ ((__format__ (__printf__, 2, 3)));
int remove (const char *);
int rename (const char *, const char *);
# 266 "/usr/include/newlib/stdio.h"
int snprintf (char *restrict, size_t, const char *restrict, ...)
               __attribute__ ((__format__ (__printf__, 3, 4)));
int vsnprintf (char *restrict, size_t, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 3, 0)));
int vfscanf (FILE *restrict, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__scanf__, 2, 0)));
int vscanf (const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__scanf__, 1, 0)));
int vsscanf (const char *restrict, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__scanf__, 2, 0)));
# 396 "/usr/include/newlib/stdio.h"
int _asiprintf_r (struct _reent *, char **, const char *, ...)
               __attribute__ ((__format__ (__printf__, 3, 4)));
char * _asniprintf_r (struct _reent *, char *, size_t *, const char *, ...)
               __attribute__ ((__format__ (__printf__, 4, 5)));
char * _asnprintf_r (struct _reent *, char *restrict, size_t *restrict, const char *restrict, ...)
               __attribute__ ((__format__ (__printf__, 4, 5)));
int _asprintf_r (struct _reent *, char **restrict, const char *restrict, ...)
               __attribute__ ((__format__ (__printf__, 3, 4)));
int _diprintf_r (struct _reent *, int, const char *, ...)
               __attribute__ ((__format__ (__printf__, 3, 4)));
int _dprintf_r (struct _reent *, int, const char *restrict, ...)
               __attribute__ ((__format__ (__printf__, 3, 4)));
int _fclose_r (struct _reent *, FILE *);
int _fcloseall_r (struct _reent *);
FILE * _fdopen_r (struct _reent *, int, const char *);
int _fflush_r (struct _reent *, FILE *);
int _fgetc_r (struct _reent *, FILE *);
int _fgetc_unlocked_r (struct _reent *, FILE *);
char * _fgets_r (struct _reent *, char *restrict, int, FILE *restrict);
char * _fgets_unlocked_r (struct _reent *, char *restrict, int, FILE *restrict);




int _fgetpos_r (struct _reent *, FILE *, fpos_t *);
int _fsetpos_r (struct _reent *, FILE *, const fpos_t *);

int _fiprintf_r (struct _reent *, FILE *, const char *, ...)
               __attribute__ ((__format__ (__printf__, 3, 4)));
int _fiscanf_r (struct _reent *, FILE *, const char *, ...)
               __attribute__ ((__format__ (__scanf__, 3, 4)));
FILE * _fmemopen_r (struct _reent *, void *restrict, size_t, const char *restrict);
FILE * _fopen_r (struct _reent *, const char *restrict, const char *restrict);
FILE * _freopen_r (struct _reent *, const char *restrict, const char *restrict, FILE *restrict);
int _fprintf_r (struct _reent *, FILE *restrict, const char *restrict, ...)
               __attribute__ ((__format__ (__printf__, 3, 4)));
int _fpurge_r (struct _reent *, FILE *);
int _fputc_r (struct _reent *, int, FILE *);
int _fputc_unlocked_r (struct _reent *, int, FILE *);
int _fputs_r (struct _reent *, const char *restrict, FILE *restrict);
int _fputs_unlocked_r (struct _reent *, const char *restrict, FILE *restrict);
size_t _fread_r (struct _reent *, void *restrict, size_t _size, size_t _n, FILE *restrict);
size_t _fread_unlocked_r (struct _reent *, void *restrict, size_t _size, size_t _n, FILE *restrict);
int _fscanf_r (struct _reent *, FILE *restrict, const char *restrict, ...)
               __attribute__ ((__format__ (__scanf__, 3, 4)));
int _fseek_r (struct _reent *, FILE *, long, int);
int _fseeko_r (struct _reent *, FILE *, _off_t, int);
long _ftell_r (struct _reent *, FILE *);
_off_t _ftello_r (struct _reent *, FILE *);
void _rewind_r (struct _reent *, FILE *);
size_t _fwrite_r (struct _reent *, const void *restrict, size_t _size, size_t _n, FILE *restrict);
size_t _fwrite_unlocked_r (struct _reent *, const void *restrict, size_t _size, size_t _n, FILE *restrict);
int _getc_r (struct _reent *, FILE *);
int _getc_unlocked_r (struct _reent *, FILE *);
int _getchar_r (struct _reent *);
int _getchar_unlocked_r (struct _reent *);
char * _gets_r (struct _reent *, char *);
int _iprintf_r (struct _reent *, const char *, ...)
               __attribute__ ((__format__ (__printf__, 2, 3)));
int _iscanf_r (struct _reent *, const char *, ...)
               __attribute__ ((__format__ (__scanf__, 2, 3)));
FILE * _open_memstream_r (struct _reent *, char **, size_t *);
void _perror_r (struct _reent *, const char *);
int _printf_r (struct _reent *, const char *restrict, ...)
               __attribute__ ((__format__ (__printf__, 2, 3)));
int _putc_r (struct _reent *, int, FILE *);
int _putc_unlocked_r (struct _reent *, int, FILE *);
int _putchar_unlocked_r (struct _reent *, int);
int _putchar_r (struct _reent *, int);
int _puts_r (struct _reent *, const char *);
int _remove_r (struct _reent *, const char *);
int _rename_r (struct _reent *,
      const char *_old, const char *_new);
int _scanf_r (struct _reent *, const char *restrict, ...)
               __attribute__ ((__format__ (__scanf__, 2, 3)));
int _siprintf_r (struct _reent *, char *, const char *, ...)
               __attribute__ ((__format__ (__printf__, 3, 4)));
int _siscanf_r (struct _reent *, const char *, const char *, ...)
               __attribute__ ((__format__ (__scanf__, 3, 4)));
int _sniprintf_r (struct _reent *, char *, size_t, const char *, ...)
               __attribute__ ((__format__ (__printf__, 4, 5)));
int _snprintf_r (struct _reent *, char *restrict, size_t, const char *restrict, ...)
               __attribute__ ((__format__ (__printf__, 4, 5)));
int _sprintf_r (struct _reent *, char *restrict, const char *restrict, ...)
               __attribute__ ((__format__ (__printf__, 3, 4)));
int _sscanf_r (struct _reent *, const char *restrict, const char *restrict, ...)
               __attribute__ ((__format__ (__scanf__, 3, 4)));
char * _tempnam_r (struct _reent *, const char *, const char *);
FILE * _tmpfile_r (struct _reent *);
char * _tmpnam_r (struct _reent *, char *);
int _ungetc_r (struct _reent *, int, FILE *);
int _vasiprintf_r (struct _reent *, char **, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 3, 0)));
char * _vasniprintf_r (struct _reent*, char *, size_t *, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 4, 0)));
char * _vasnprintf_r (struct _reent*, char *, size_t *, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 4, 0)));
int _vasprintf_r (struct _reent *, char **, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 3, 0)));
int _vdiprintf_r (struct _reent *, int, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 3, 0)));
int _vdprintf_r (struct _reent *, int, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 3, 0)));
int _vfiprintf_r (struct _reent *, FILE *, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 3, 0)));
int _vfiscanf_r (struct _reent *, FILE *, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__scanf__, 3, 0)));
int _vfprintf_r (struct _reent *, FILE *restrict, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 3, 0)));
int _vfscanf_r (struct _reent *, FILE *restrict, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__scanf__, 3, 0)));
int _viprintf_r (struct _reent *, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 2, 0)));
int _viscanf_r (struct _reent *, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__scanf__, 2, 0)));
int _vprintf_r (struct _reent *, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 2, 0)));
int _vscanf_r (struct _reent *, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__scanf__, 2, 0)));
int _vsiprintf_r (struct _reent *, char *, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 3, 0)));
int _vsiscanf_r (struct _reent *, const char *, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__scanf__, 3, 0)));
int _vsniprintf_r (struct _reent *, char *, size_t, const char *, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 4, 0)));
int _vsnprintf_r (struct _reent *, char *restrict, size_t, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 4, 0)));
int _vsprintf_r (struct _reent *, char *restrict, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__printf__, 3, 0)));
int _vsscanf_r (struct _reent *, const char *restrict, const char *restrict, __gnuc_va_list)
               __attribute__ ((__format__ (__scanf__, 3, 0)));



int fpurge (FILE *);
ssize_t __getdelim (char **, size_t *, int, FILE *);
ssize_t __getline (char **, size_t *, FILE *);
# 577 "/usr/include/newlib/stdio.h"
int __srget_r (struct _reent *, FILE *);
int __swbuf_r (struct _reent *, int, FILE *);
# 687 "/usr/include/newlib/stdio.h"
static __inline__ int __sputc_r(struct _reent *_ptr, int _c, FILE *_p) {




 if (--_p->_w >= 0 || (_p->_w >= _p->_lbfsize && (char)_c != '\n'))
  return (*_p->_p++ = _c);
 else
  return (__swbuf_r(_ptr, _c, _p));
}
# 741 "/usr/include/newlib/stdio.h"
static __inline int
_getchar_unlocked(void)
{
 struct _reent *_ptr;

 _ptr = _impure_ptr;
 return ((--(((_ptr)->_stdin))->_r < 0 ? __srget_r(_ptr, ((_ptr)->_stdin)) : (int)(*(((_ptr)->_stdin))->_p++)));
}

static __inline int
_putchar_unlocked(int _c)
{
 struct _reent *_ptr;

 _ptr = _impure_ptr;
 return (__sputc_r(_ptr, _c, ((_ptr)->_stdout)));
}
# 797 "/usr/include/newlib/stdio.h"

# 11 "/usr/include/newlib/stdlib.h"
























typedef struct
{
  int quot;
  int rem;
} div_t;

typedef struct
{
  long quot;
  long rem;
} ldiv_t;


typedef struct
{
  long long int quot;
  long long int rem;
} lldiv_t;




typedef int (*__compar_fn_t) (const void *, const void *);







int __locale_mb_cur_max (void);



void abort (void) __attribute__ ((__noreturn__));
int abs (int);





int atexit (void (*__func)(void));
double atof (const char *__nptr);



int atoi (const char *__nptr);
int _atoi_r (struct _reent *, const char *__nptr);
long atol (const char *__nptr);
long _atol_r (struct _reent *, const char *__nptr);
void * bsearch (const void *__key,
         const void *__base,
         size_t __nmemb,
         size_t __size,
         __compar_fn_t _compar);
void *calloc(size_t, size_t) __attribute__((__malloc__)) __attribute__((__warn_unused_result__))
      __attribute__((__alloc_size__(1, 2))) ;
div_t div (int __numer, int __denom);
void exit (int __status) __attribute__ ((__noreturn__));
void free (void *) ;
char * getenv (const char *__string);
char * _getenv_r (struct _reent *, const char *__string);



char * _findenv (const char *, int *);
char * _findenv_r (struct _reent *, const char *, int *);




long labs (long);
ldiv_t ldiv (long __numer, long __denom);
void *malloc(size_t) __attribute__((__malloc__)) __attribute__((__warn_unused_result__)) __attribute__((__alloc_size__(1))) ;
int mblen (const char *, size_t);
int _mblen_r (struct _reent *, const char *, size_t, _mbstate_t *);
int mbtowc (wchar_t *restrict, const char *restrict, size_t);
int _mbtowc_r (struct _reent *, wchar_t *restrict, const char *restrict, size_t, _mbstate_t *);
int wctomb (char *, wchar_t);
int _wctomb_r (struct _reent *, char *, wchar_t, _mbstate_t *);
size_t mbstowcs (wchar_t *restrict, const char *restrict, size_t);
size_t _mbstowcs_r (struct _reent *, wchar_t *restrict, const char *restrict, size_t, _mbstate_t *);
size_t wcstombs (char *restrict, const wchar_t *restrict, size_t);
size_t _wcstombs_r (struct _reent *, char *restrict, const wchar_t *restrict, size_t, _mbstate_t *);
# 137 "/usr/include/newlib/stdlib.h"
char * _mkdtemp_r (struct _reent *, char *);
int _mkostemp_r (struct _reent *, char *, int);
int _mkostemps_r (struct _reent *, char *, int, int);
int _mkstemp_r (struct _reent *, char *);
int _mkstemps_r (struct _reent *, char *, int);
char * _mktemp_r (struct _reent *, char *) __attribute__ ((__deprecated__("the use of `mktemp' is dangerous; use `mkstemp' instead")));
void qsort (void *__base, size_t __nmemb, size_t __size, __compar_fn_t _compar);
int rand (void);
void *realloc(void *, size_t) __attribute__((__warn_unused_result__)) __attribute__((__alloc_size__(2))) ;













void srand (unsigned __seed);
double strtod (const char *restrict __n, char **restrict __end_PTR);
double _strtod_r (struct _reent *,const char *restrict __n, char **restrict __end_PTR);

float strtof (const char *restrict __n, char **restrict __end_PTR);







long strtol (const char *restrict __n, char **restrict __end_PTR, int __base);
long _strtol_r (struct _reent *,const char *restrict __n, char **restrict __end_PTR, int __base);
unsigned long strtoul (const char *restrict __n, char **restrict __end_PTR, int __base);
unsigned long _strtoul_r (struct _reent *,const char *restrict __n, char **restrict __end_PTR, int __base);
















int system (const char *__string);










void _Exit (int __status) __attribute__ ((__noreturn__));




int _putenv_r (struct _reent *, char *__string);
void * _reallocf_r (struct _reent *, void *, size_t);



int _setenv_r (struct _reent *, const char *__string, const char *__value, int __overwrite);











char * __itoa (int, char *, int);
char * __utoa (unsigned, char *, int);
# 263 "/usr/include/newlib/stdlib.h"
long long atoll (const char *__nptr);

long long _atoll_r (struct _reent *, const char *__nptr);

long long llabs (long long);
lldiv_t lldiv (long long __numer, long long __denom);
long long strtoll (const char *restrict __n, char **restrict __end_PTR, int __base);

long long _strtoll_r (struct _reent *, const char *restrict __n, char **restrict __end_PTR, int __base);

unsigned long long strtoull (const char *restrict __n, char **restrict __end_PTR, int __base);

unsigned long long _strtoull_r (struct _reent *, const char *restrict __n, char **restrict __end_PTR, int __base);








int _unsetenv_r (struct _reent *, const char *__string);







char * _dtoa_r (struct _reent *, double, int, int, int *, int*, char**);

void * _malloc_r (struct _reent *, size_t) ;
void * _calloc_r (struct _reent *, size_t, size_t) ;
void _free_r (struct _reent *, void *) ;
void * _realloc_r (struct _reent *, void *, size_t) ;
void _mstats_r (struct _reent *, char *);

int _system_r (struct _reent *, const char *);

void __eprintf (const char *, const char *, unsigned int, const char *);
# 322 "/usr/include/newlib/stdlib.h"
extern long double _strtold_r (struct _reent *, const char *restrict, char **restrict);

extern long double strtold (const char *restrict, char **restrict);















# 4 "app.cc"

# 1 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/mach.h"







# 34 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stdint.h"
typedef signed char int8_t;


typedef short int int16_t;


typedef long int int32_t;


typedef long long int int64_t;


typedef unsigned char uint8_t;


typedef short unsigned int uint16_t;


typedef long unsigned int uint32_t;


typedef long long unsigned int uint64_t;




typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef long int int_least32_t;
typedef long long int int_least64_t;
typedef unsigned char uint_least8_t;
typedef short unsigned int uint_least16_t;
typedef long unsigned int uint_least32_t;
typedef long long unsigned int uint_least64_t;



typedef int int_fast8_t;
typedef int int_fast16_t;
typedef int int_fast32_t;
typedef long long int int_fast64_t;
typedef unsigned int uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;
typedef long long unsigned int uint_fast64_t;




typedef int intptr_t;


typedef unsigned int uintptr_t;




typedef long long int intmax_t;
typedef long long unsigned int uintmax_t;
# 99 "/usr/lib/gcc/arm-none-eabi/9.2.1/include/stdarg.h"
typedef __gnuc_va_list va_list;
# 63 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"

# 45 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/inc/hw_types.h"






typedef void (* FPTR_VOID_VOID_T) (void);
typedef void (* FPTR_VOID_UINT8_T) (uint8_t);
















typedef unsigned int __UINT32;
# 69 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"

# 57 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/debug.h"
extern void __error__(char *pcFilename, uint32_t ui32Line);
# 106 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/cpu.h"
extern uint32_t NOROM_CPUcpsid(void);













extern uint32_t NOROM_CPUprimask(void);











extern uint32_t NOROM_CPUcpsie(void);
# 173 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/cpu.h"
static inline void __attribute__((always_inline))
CPUwfi(void)
{



    __asm("    wfi\n");
}
# 222 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/cpu.h"
static inline void __attribute__((always_inline))
CPUwfe(void)
{



    __asm("    wfe\n");
}
# 271 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/cpu.h"
static inline void __attribute__((always_inline))
CPUsev(void)
{



    __asm("    sev\n");
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wattributes"
# 325 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/cpu.h"
static inline void __attribute__ ((naked))
CPUbasepriSet(uint32_t ui32NewBasepri)
{



   __asm("    msr     BASEPRI, r0\n"
         "    bx      lr\n");
}
#pragma GCC diagnostic pop












extern uint32_t NOROM_CPUbasepriGet(void);
















extern void NOROM_CPUdelay(uint32_t ui32Count);
# 382 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/cpu.h"
static inline void
CPU_WriteBufferDisable( void )
{
    (*((volatile unsigned long *)(((unsigned long)(0xE000E000 + 0x00000008) & 0xF0000000) | 0x02000000 | (((unsigned long)(0xE000E000 + 0x00000008) & 0x000FFFFF) << 5) | ((1) << 2)))) = 1;
}













static inline void
CPU_WriteBufferEnable( void )
{
    (*((volatile unsigned long *)(((unsigned long)(0xE000E000 + 0x00000008) & 0xF0000000) | 0x02000000 | (((unsigned long)(0xE000E000 + 0x00000008) & 0x000FFFFF) << 5) | ((1) << 2)))) = 0;
}
# 66 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/rom.h"
typedef uint32_t (* FPTR_CRC32_T) ( uint8_t* ,
                                                     uint32_t ,
                                                     uint32_t );

typedef uint32_t (* FPTR_GETFLSIZE_T) ( void );

typedef uint32_t (* FPTR_GETCHIPID_T) ( void );

typedef uint32_t (* FPTR_RESERVED1_T) ( uint32_t );

typedef uint32_t (* FPTR_RESERVED2_T) ( void );

typedef uint32_t (* FPTR_RESERVED3_T) ( uint8_t* ,
                                                     uint32_t ,
                                                     uint32_t );
typedef void (* FPTR_RESETDEV_T) ( void );

typedef uint32_t (* FPTR_FLETCHER32_T) ( uint16_t* ,
                                                     uint16_t ,
                                                     uint16_t );

typedef uint32_t (* FPTR_MINVAL_T) ( uint32_t* ,
                                                     uint32_t );

typedef uint32_t (* FPTR_MAXVAL_T) ( uint32_t* ,
                                                     uint32_t );

typedef uint32_t (* FPTR_MEANVAL_T) ( uint32_t* ,
                                                     uint32_t );

typedef uint32_t (* FPTR_STDDVAL_T) ( uint32_t* ,
                                                     uint32_t );

typedef void (* FPTR_HFSOURCESAFESWITCH_T) ( void );

typedef void (* FPTR_RESERVED4_T) ( uint32_t );

typedef void (* FPTR_RESERVED5_T) ( uint32_t );

typedef void (* FPTR_COMPAIN_T) ( uint8_t );

typedef void (* FPTR_COMPAREF_T) ( uint8_t );

typedef void (* FPTR_ADCCOMPBIN_T) ( uint8_t );

typedef void (* FPTR_COMPBREF_T) ( uint8_t );

extern uint32_t MemBusWrkAroundHapiProgramFlash(uint8_t *pui8DataBuffer,
                                                uint32_t ui32Address,
                                                uint32_t ui32Count);

extern uint32_t MemBusWrkAroundHapiEraseSector(uint32_t ui32Address);




typedef struct
{
    FPTR_CRC32_T Crc32;
    FPTR_GETFLSIZE_T FlashGetSize;
    FPTR_GETCHIPID_T GetChipId;
    FPTR_RESERVED1_T ReservedLocation1;
    FPTR_RESERVED2_T ReservedLocation2;
    FPTR_RESERVED3_T ReservedLocation3;
    FPTR_RESETDEV_T ResetDevice;
    FPTR_FLETCHER32_T Fletcher32;
    FPTR_MINVAL_T MinValue;
    FPTR_MAXVAL_T MaxValue;
    FPTR_MEANVAL_T MeanValue;
    FPTR_STDDVAL_T StandDeviationValue;
    FPTR_RESERVED4_T ReservedLocation4;
    FPTR_RESERVED5_T ReservedLocation5;
    FPTR_HFSOURCESAFESWITCH_T HFSourceSafeSwitch;
    FPTR_COMPAIN_T SelectCompAInput;
    FPTR_COMPAREF_T SelectCompARef;
    FPTR_ADCCOMPBIN_T SelectADCCompBInput;
    FPTR_COMPBREF_T SelectCompBRef;
} HARD_API_T;









extern void SafeHapiVoid( FPTR_VOID_VOID_T fPtr );
extern void SafeHapiAuxAdiSelect( FPTR_VOID_UINT8_T fPtr, uint8_t ut8Signal );
# 136 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
static inline 
# 136 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
               _Bool
IntMasterEnable(void)
{



    return(NOROM_CPUcpsie());
}














static inline 
# 158 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
               _Bool
IntMasterDisable(void)
{



    return(NOROM_CPUcpsid());
}
# 192 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
extern void NOROM_IntRegister(uint32_t ui32Interrupt, void (*pfnHandler)(void));
# 210 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
extern void NOROM_IntUnregister(uint32_t ui32Interrupt);
# 228 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
extern void NOROM_IntPriorityGroupingSet(uint32_t ui32Bits);











extern uint32_t NOROM_IntPriorityGroupingGet(void);
# 274 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
extern void NOROM_IntPrioritySet(uint32_t ui32Interrupt, uint8_t ui8Priority);
# 296 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
extern int32_t NOROM_IntPriorityGet(uint32_t ui32Interrupt);














extern void NOROM_IntEnable(uint32_t ui32Interrupt);














extern void NOROM_IntDisable(uint32_t ui32Interrupt);
# 345 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
extern void NOROM_IntPendSet(uint32_t ui32Interrupt);
# 366 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
extern 
# 366 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
      _Bool 
# 366 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
           NOROM_IntPendGet(uint32_t ui32Interrupt);















extern void NOROM_IntPendClear(uint32_t ui32Interrupt);
# 407 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
static inline void
IntPriorityMaskSet(uint32_t ui32PriorityMask)
{
    CPUbasepriSet(ui32PriorityMask);
}
# 433 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/interrupt.h"
static inline uint32_t
IntPriorityMaskGet(void)
{
    return(NOROM_CPUbasepriGet());
}
# 267 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern void NOROM_PRCMInfClockConfigureSet(uint32_t ui32ClkDiv,
                                     uint32_t ui32PowerMode);
# 291 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern uint32_t NOROM_PRCMInfClockConfigureGet(uint32_t ui32PowerMode);













static inline void
PRCMMcuPowerOff(void)
{



    (*((volatile unsigned long *)(((unsigned long)(0x40082000 + 0x0000000C) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40082000 + 0x0000000C) & 0x000FFFFF) << 5) | ((2) << 2)))) = 1;
}














static inline void
PRCMMcuPowerOffCancel(void)
{



    (*((volatile unsigned long *)(((unsigned long)(0x40082000 + 0x0000000C) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40082000 + 0x0000000C) & 0x000FFFFF) << 5) | ((2) << 2)))) = 0;
}
# 359 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
static inline void
PRCMMcuUldoConfigure(uint32_t ui32Enable)
{

    (*((volatile unsigned long *)(((unsigned long)(0x40082000 + 0x0000000C) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40082000 + 0x0000000C) & 0x000FFFFF) << 5) | ((0) << 2)))) = ui32Enable;
}
# 397 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
static inline void
PRCMGPTimerClockDivisionSet( uint32_t clkDiv )
{
    ;

    (*((volatile unsigned long *)(0x40082000 + 0x000000CC))) = clkDiv;
}
# 425 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
static inline uint32_t
PRCMGPTimerClockDivisionGet( void )
{
    return ( (*((volatile unsigned long *)(0x40082000 + 0x000000CC))));
}











static inline void
PRCMAudioClockEnable(void)
{

    (*((volatile unsigned long *)(((unsigned long)(0x40082000 + 0x000000D0) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40082000 + 0x000000D0) & 0x000FFFFF) << 5) | ((0) << 2)))) = 1;
}










static inline void
PRCMAudioClockDisable(void)
{

    (*((volatile unsigned long *)(((unsigned long)(0x40082000 + 0x000000D0) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40082000 + 0x000000D0) & 0x000FFFFF) << 5) | ((0) << 2)))) = 0;
}
# 495 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern void NOROM_PRCMAudioClockConfigSet(uint32_t ui32ClkConfig,
                                    uint32_t ui32SampleRate);
# 523 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern void NOROM_PRCMAudioClockConfigSetOverride(uint32_t ui32ClkConfig, uint32_t ui32MstDiv,
                        uint32_t ui32BitDiv, uint32_t ui32WordDiv);
# 553 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
static inline void
PRCMLoadSet(void)
{



    (*((volatile unsigned long *)(0x60082000 + 0x00000028))) = 0x00000001;
}












static inline 
# 573 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
               _Bool
PRCMLoadGet(void)
{



    return (((*((volatile unsigned long *)(0x40082000 + 0x00000028))) & 0x00000002) ?
           1 
# 580 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
                : 
# 580 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
                  0
# 580 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
                       );
}
# 603 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
static inline void
PRCMDomainEnable(uint32_t ui32Domains)
{



   
                                            ;




    if(ui32Domains & 0x00000001)
    {
        (*((volatile unsigned long *)(0x40082000 + 0x0000002C))) = 0x00000001;
    }
    if(ui32Domains & 0x00000010)
    {
        (*((volatile unsigned long *)(0x40082000 + 0x00000030))) = 0x00000003;
    }
}
# 646 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
static inline void
PRCMDomainDisable(uint32_t ui32Domains)
{



   
                                            ;




    if(ui32Domains & 0x00000001)
    {
        (*((volatile unsigned long *)(0x40082000 + 0x0000002C))) = 0x0;
    }
    if(ui32Domains & 0x00000010)
    {
        (*((volatile unsigned long *)(0x40082000 + 0x00000030))) = 0x0;
    }
}
# 718 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern void NOROM_PRCMPowerDomainOn(uint32_t ui32Domains);
# 743 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern void NOROM_PRCMPowerDomainOff(uint32_t ui32Domains);












static inline void
PRCMRfPowerDownWhenIdle(void)
{

    (*((volatile unsigned long *)(((unsigned long)(0x40082000 + 0x00000130) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40082000 + 0x00000130) & 0x000FFFFF) << 5) | ((0) << 2)))) = 0;
}
# 806 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern void NOROM_PRCMPeripheralRunEnable(uint32_t ui32Peripheral);
# 848 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern void NOROM_PRCMPeripheralRunDisable(uint32_t ui32Peripheral);
# 888 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern void NOROM_PRCMPeripheralSleepEnable(uint32_t ui32Peripheral);
# 929 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern void NOROM_PRCMPeripheralSleepDisable(uint32_t ui32Peripheral);
# 969 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern void NOROM_PRCMPeripheralDeepSleepEnable(uint32_t ui32Peripheral);
# 1012 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern void NOROM_PRCMPeripheralDeepSleepDisable(uint32_t ui32Peripheral);
# 1033 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
extern uint32_t NOROM_PRCMPowerDomainStatus(uint32_t ui32Domains);














static inline 
# 1048 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
               _Bool
PRCMRfReady(void)
{



    return (((*((volatile unsigned long *)(0x40082000 + 0x0000019C))) &
             0x00000001) ? 
# 1055 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
                                  1 
# 1055 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
                                       : 
# 1055 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
                                         0
# 1055 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/prcm.h"
                                              );
}
















static inline void
PRCMSleep(void)
{



    CPUwfi();
}















extern void NOROM_PRCMDeepSleep(void);










static inline void
PRCMCacheRetentionEnable( void )
{
   (*((volatile unsigned long *)(0x40082000 + 0x00000224))) |= 0x00000003;
}










static inline void
PRCMCacheRetentionDisable( void )
{
   (*((volatile unsigned long *)(0x40082000 + 0x00000224))) &= ~0x00000003;
}
# 163 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/gpio.h"
static inline uint32_t
GPIO_readDio( uint32_t dioNumber )
{



    ;




    return (( (*((volatile unsigned long *)(0x40022000 + 0x000000C0))) >> dioNumber ) & 1 );
}
# 197 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/gpio.h"
static inline uint32_t
GPIO_readMultiDio( uint32_t dioMask )
{



    ;




    return ( (*((volatile unsigned long *)(0x40022000 + 0x000000C0))) & dioMask );
}















static inline void
GPIO_writeDio( uint32_t dioNumber, uint32_t value )
{



    ;
    ;




    (*((volatile unsigned char *)(0x40022000 + dioNumber))) = value;
}
# 261 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/gpio.h"
static inline void
GPIO_writeMultiDio( uint32_t dioMask, uint32_t bitVectoredValue )
{



    ;

    (*((volatile unsigned long *)(0x40022000 + 0x00000080))) =
        ( (*((volatile unsigned long *)(0x40022000 + 0x00000080))) & ~dioMask ) |
        ( bitVectoredValue & dioMask );
}












static inline void
GPIO_setDio( uint32_t dioNumber )
{



    ;




    (*((volatile unsigned long *)(0x40022000 + 0x00000090))) = ( 1 << dioNumber );
}
















static inline void
GPIO_setMultiDio( uint32_t dioMask )
{



    ;




    (*((volatile unsigned long *)(0x40022000 + 0x00000090))) = dioMask;
}












static inline void
GPIO_clearDio( uint32_t dioNumber )
{



    ;




    (*((volatile unsigned long *)(0x40022000 + 0x000000A0))) = ( 1 << dioNumber );
}
















static inline void
GPIO_clearMultiDio( uint32_t dioMask )
{



    ;




    (*((volatile unsigned long *)(0x40022000 + 0x000000A0))) = dioMask;
}












static inline void
GPIO_toggleDio( uint32_t dioNumber )
{



    ;




    (*((volatile unsigned long *)(0x40022000 + 0x000000B0))) = ( 1 << dioNumber );
}
















static inline void
GPIO_toggleMultiDio( uint32_t dioMask )
{



    ;




    (*((volatile unsigned long *)(0x40022000 + 0x000000B0))) = dioMask;
}
# 452 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/gpio.h"
static inline uint32_t
GPIO_getOutputEnableDio( uint32_t dioNumber )
{



    ;




    return (( (*((volatile unsigned long *)(0x40022000 + 0x000000D0))) >> dioNumber ) & 1 );
}
# 486 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/gpio.h"
static inline uint32_t
GPIO_getOutputEnableMultiDio( uint32_t dioMask )
{



    ;




    return ( (*((volatile unsigned long *)(0x40022000 + 0x000000D0))) & dioMask );
}
# 517 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/gpio.h"
static inline void
GPIO_setOutputEnableDio( uint32_t dioNumber, uint32_t outputEnableValue )
{



    ;
   
                                                            ;




    (*((volatile unsigned long *)(((unsigned long)(0x40022000 + 0x000000D0) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40022000 + 0x000000D0) & 0x000FFFFF) << 5) | ((dioNumber) << 2)))) = outputEnableValue;
}
# 557 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/gpio.h"
static inline void
GPIO_setOutputEnableMultiDio( uint32_t dioMask, uint32_t bitVectoredOutputEnable )
{



    ;

    (*((volatile unsigned long *)(0x40022000 + 0x000000D0))) =
        ( (*((volatile unsigned long *)(0x40022000 + 0x000000D0))) & ~dioMask ) |
        ( bitVectoredOutputEnable & dioMask );
}














static inline uint32_t
GPIO_getEventDio( uint32_t dioNumber )
{



    ;




    return (( (*((volatile unsigned long *)(0x40022000 + 0x000000E0))) >> dioNumber ) & 1 );
}
# 618 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/gpio.h"
static inline uint32_t
GPIO_getEventMultiDio( uint32_t dioMask )
{



    ;




    return ( (*((volatile unsigned long *)(0x40022000 + 0x000000E0))) & dioMask );
}












static inline void
GPIO_clearEventDio( uint32_t dioNumber )
{



    ;




    (*((volatile unsigned long *)(0x40022000 + 0x000000E0))) = ( 1 << dioNumber );
}
# 673 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/gpio.h"
static inline void
GPIO_clearEventMultiDio( uint32_t dioMask )
{



    ;




    (*((volatile unsigned long *)(0x40022000 + 0x000000E0))) = dioMask;
}
# 235 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
static inline void
UARTParityModeSet(uint32_t ui32Base, uint32_t ui32Parity)
{



    ;
   



                                                ;




    (*((volatile unsigned long *)(ui32Base + 0x0000002C))) = (((*((volatile unsigned long *)(ui32Base + 0x0000002C))) &
                                      ~(0x00000080 | 0x00000004 |
                                        0x00000002)) | ui32Parity);
}
# 273 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
static inline uint32_t
UARTParityModeGet(uint32_t ui32Base)
{



    ;




    return((*((volatile unsigned long *)(ui32Base + 0x0000002C))) &
           (0x00000080 | 0x00000004 | 0x00000002));
}
# 312 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
static inline void
UARTFIFOLevelSet(uint32_t ui32Base, uint32_t ui32TxLevel,
                 uint32_t ui32RxLevel)
{



    ;
   



                                            ;
   



                                            ;




    (*((volatile unsigned long *)(ui32Base + 0x00000034))) = ui32TxLevel | ui32RxLevel;
}
# 363 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
extern void NOROM_UARTFIFOLevelGet(uint32_t ui32Base, uint32_t *pui32TxLevel,
                             uint32_t *pui32RxLevel);
# 401 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
extern void NOROM_UARTConfigSetExpClk(uint32_t ui32Base, uint32_t ui32UARTClk,
                                uint32_t ui32Baud, uint32_t ui32Config);
# 426 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
extern void NOROM_UARTConfigGetExpClk(uint32_t ui32Base, uint32_t ui32UARTClk,
                                uint32_t *pui32Baud, uint32_t *pui32Config);













static inline void
UARTEnable(uint32_t ui32Base)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x0000002C))) |= 0x00000010;




    (*((volatile unsigned long *)(ui32Base + 0x00000030))) |= (0x00000001 | 0x00000100 |
                                     0x00000200);
}













extern void NOROM_UARTDisable(uint32_t ui32Base);












static inline void
UARTFIFOEnable(uint32_t ui32Base)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x0000002C))) |= 0x00000010;
}












static inline void
UARTFIFODisable(uint32_t ui32Base)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x0000002C))) &= ~(0x00000010);
}















static inline 
# 539 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
               _Bool
UARTCharsAvail(uint32_t ui32Base)
{



    ;




    return(((*((volatile unsigned long *)(ui32Base + 0x00000018))) & 0x00000010) ? 
# 550 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                                                         0 
# 550 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                                                               : 
# 550 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                                                                 1
# 550 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                                                                     );
}















static inline 
# 567 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
               _Bool
UARTSpaceAvail(uint32_t ui32Base)
{



    ;




    return(((*((volatile unsigned long *)(ui32Base + 0x00000018))) & 0x00000020) ? 
# 578 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                                                         0 
# 578 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                                                               : 
# 578 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                                                                 1
# 578 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                                                                     );
}
# 600 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
extern int32_t NOROM_UARTCharGetNonBlocking(uint32_t ui32Base);















extern int32_t NOROM_UARTCharGet(uint32_t ui32Base);
# 635 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
extern 
# 635 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
      _Bool 
# 635 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
           NOROM_UARTCharPutNonBlocking(uint32_t ui32Base, uint8_t ui8Data);















extern void NOROM_UARTCharPut(uint32_t ui32Base, uint8_t ui8Data);
# 669 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
static inline 
# 669 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
               _Bool
UARTBusy(uint32_t ui32Base)
{



    ;




    return(((*((volatile unsigned long *)(ui32Base + 0x00000018))) & 0x00000008) ?
           0x00000001 : 0x00000000);
}
















static inline void
UARTBreakCtl(uint32_t ui32Base, 
# 700 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                               _Bool 
# 700 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                                    bBreakState)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x0000002C))) =
         (bBreakState ?
         ((*((volatile unsigned long *)(ui32Base + 0x0000002C))) | 0x00000001) :
         ((*((volatile unsigned long *)(ui32Base + 0x0000002C))) & ~(0x00000001)));
}
# 735 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
extern void NOROM_UARTIntRegister(uint32_t ui32Base, void (*pfnHandler)(void));
# 754 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
extern void NOROM_UARTIntUnregister(uint32_t ui32Base);
# 779 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
static inline void
UARTIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000038))) |= ui32IntFlags;
}
# 815 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
static inline void
UARTIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000038))) &= ~(ui32IntFlags);
}
# 853 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
static inline uint32_t
UARTIntStatus(uint32_t ui32Base, 
# 854 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                                _Bool 
# 854 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
                                     bMasked)
{



    ;





    if(bMasked)
    {
        return((*((volatile unsigned long *)(ui32Base + 0x00000040))));
    }
    else
    {
        return((*((volatile unsigned long *)(ui32Base + 0x0000003C))));
    }
}
# 912 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
static inline void
UARTIntClear(uint32_t ui32Base, uint32_t ui32IntFlags)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000044))) = ui32IntFlags;
}
# 947 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
static inline void
UARTDMAEnable(uint32_t ui32Base, uint32_t ui32DMAFlags)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000048))) |= ui32DMAFlags;
}
# 978 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
static inline void
UARTDMADisable(uint32_t ui32Base, uint32_t ui32DMAFlags)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000048))) &= ~ui32DMAFlags;
}
# 1011 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/uart.h"
static inline uint32_t
UARTRxErrorGet(uint32_t ui32Base)
{



    ;




    return((*((volatile unsigned long *)(ui32Base + 0x00000004))) & 0x0000000F);
}















static inline void
UARTRxErrorClear(uint32_t ui32Base)
{



    ;





    (*((volatile unsigned long *)(ui32Base + 0x00000004))) = 0;
}












static inline void
UARTHwFlowControlEnable( uint32_t ui32Base )
{



    ;

    (*((volatile unsigned long *)(ui32Base + 0x00000030))) |= ( 0x00008000 | 0x00004000 );
}












static inline void
UARTHwFlowControlDisable( uint32_t ui32Base )
{



    ;

    (*((volatile unsigned long *)(ui32Base + 0x00000030))) &= ~( 0x00008000 | 0x00004000 );
}
# 196 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
extern void NOROM_I2CMasterInitExpClk(uint32_t ui32Base, uint32_t ui32I2CClk,
                               _Bool 
# 197 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                    bFast);
# 223 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
static inline void
I2CMasterControl(uint32_t ui32Base, uint32_t ui32Cmd)
{



    ;
   








                                                                ;




    (*((volatile unsigned long *)(0x40002000 + 0x00000804))) = ui32Cmd;





    NOROM_CPUdelay(2);
}
# 272 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
static inline void
I2CMasterSlaveAddrSet(uint32_t ui32Base, uint8_t ui8SlaveAddr,
                     _Bool 
# 274 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                          bReceive)
{



    ;
    ;




    (*((volatile unsigned long *)(0x40002000 + 0x00000800))) = (ui8SlaveAddr << 1) | bReceive;
}












static inline void
I2CMasterEnable(uint32_t ui32Base)
{

    ;


    (*((volatile unsigned long *)(((unsigned long)(0x40002000 + 0x00000820) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40002000 + 0x00000820) & 0x000FFFFF) << 5) | ((4) << 2)))) = 1;


    (*((volatile unsigned long *)(0x40002000 + 0x00000804))) = 0x00000001;
}












static inline void
I2CMasterDisable(uint32_t ui32Base)
{

    ;


    (*((volatile unsigned long *)(0x40002000 + 0x00000804))) = 0;


    (*((volatile unsigned long *)(((unsigned long)(0x40002000 + 0x00000820) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40002000 + 0x00000820) & 0x000FFFFF) << 5) | ((4) << 2)))) = 0;
}















static inline 
# 350 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
               _Bool
I2CMasterBusy(uint32_t ui32Base)
{



    ;




    if((*((volatile unsigned long *)(0x40002000 + 0x00000804))) & 0x00000001)
    {
        return(
# 363 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
              1
# 363 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                  );
    }
    else
    {
        return(
# 367 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
              0
# 367 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                   );
    }
}
















static inline 
# 386 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
               _Bool
I2CMasterBusBusy(uint32_t ui32Base)
{



    ;




    if((*((volatile unsigned long *)(0x40002000 + 0x00000804))) & 0x00000040)
    {
        return(
# 399 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
              1
# 399 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                  );
    }
    else
    {
        return(
# 403 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
              0
# 403 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                   );
    }
}













static inline uint32_t
I2CMasterDataGet(uint32_t ui32Base)
{



    ;




    return((*((volatile unsigned long *)(0x40002000 + 0x00000808))));
}













static inline void
I2CMasterDataPut(uint32_t ui32Base, uint8_t ui8Data)
{



    ;




    (*((volatile unsigned long *)(0x40002000 + 0x00000808))) = ui8Data;
}
# 475 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
extern uint32_t NOROM_I2CMasterErr(uint32_t ui32Base);












static inline void
I2CMasterIntEnable(uint32_t ui32Base)
{



    ;




    (*((volatile unsigned long *)(0x40002000 + 0x00000810))) = 0x00000001;
}












static inline void
I2CMasterIntDisable(uint32_t ui32Base)
{



    ;




    (*((volatile unsigned long *)(0x40002000 + 0x00000810))) = 0;
}
# 555 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
static inline void
I2CMasterIntClear(uint32_t ui32Base)
{



    ;




    (*((volatile unsigned long *)(0x40002000 + 0x0000081C))) = 0x00000001;
}
# 587 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
static inline 
# 587 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
               _Bool
I2CMasterIntStatus(uint32_t ui32Base, 
# 588 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                     _Bool 
# 588 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                          bMasked)
{



    ;





    if(bMasked)
    {
        return(((*((volatile unsigned long *)(0x40002000 + 0x00000818)))) ? 
# 601 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                                1 
# 601 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                                     : 
# 601 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                                       0
# 601 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                                            );
    }
    else
    {
        return(((*((volatile unsigned long *)(0x40002000 + 0x00000814)))) ? 
# 605 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                                1 
# 605 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                                     : 
# 605 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                                       0
# 605 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                                            );
    }
}












static inline void
I2CSlaveEnable(uint32_t ui32Base)
{

    ;


    (*((volatile unsigned long *)(((unsigned long)(0x40002000 + 0x00000820) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40002000 + 0x00000820) & 0x000FFFFF) << 5) | ((5) << 2)))) = 1;


    (*((volatile unsigned long *)(0x40002000 + 0x00000004))) = 0x00000001;
}
# 650 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
static inline void
I2CSlaveInit(uint32_t ui32Base, uint8_t ui8SlaveAddr)
{



    ;
    ;




    I2CSlaveEnable(0x40002000);




    (*((volatile unsigned long *)(0x40002000 + 0x00000000))) = ui8SlaveAddr;
}













static inline void
I2CSlaveAddressSet(uint32_t ui32Base, uint8_t ui8SlaveAddr)
{



    ;
    ;




    (*((volatile unsigned long *)(0x40002000 + 0x00000000))) = ui8SlaveAddr;
}












static inline void
I2CSlaveDisable(uint32_t ui32Base)
{

    ;


    (*((volatile unsigned long *)(0x40002000 + 0x00000004))) = 0x0;


    (*((volatile unsigned long *)(((unsigned long)(0x40002000 + 0x00000820) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40002000 + 0x00000820) & 0x000FFFFF) << 5) | ((5) << 2)))) = 0;
}
# 737 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
static inline uint32_t
I2CSlaveStatus(uint32_t ui32Base)
{



    ;




    return((*((volatile unsigned long *)(0x40002000 + 0x00000004))));
}













static inline uint32_t
I2CSlaveDataGet(uint32_t ui32Base)
{



    ;




    return((*((volatile unsigned long *)(0x40002000 + 0x00000008))));
}













static inline void
I2CSlaveDataPut(uint32_t ui32Base, uint8_t ui8Data)
{



    ;




    (*((volatile unsigned long *)(0x40002000 + 0x00000008))) = ui8Data;
}
# 821 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
static inline void
I2CSlaveIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    uint32_t ui32Val;




    ;
   
                                               ;




    ui32Val = (*((volatile unsigned long *)(0x40002000 + 0x0000000C)));
    ui32Val |= ui32IntFlags;
    (*((volatile unsigned long *)(0x40002000 + 0x0000000C))) = ui32Val;
}
# 859 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
static inline void
I2CSlaveIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags)
{
    uint32_t ui32Val;




    ;
   
                                               ;




    ui32Val = (*((volatile unsigned long *)(0x40002000 + 0x0000000C)));
    ui32Val &= ~ui32IntFlags;
    (*((volatile unsigned long *)(0x40002000 + 0x0000000C))) = ui32Val;
}
# 912 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
static inline void
I2CSlaveIntClear(uint32_t ui32Base, uint32_t ui32IntFlags)
{



    ;




    (*((volatile unsigned long *)(0x40002000 + 0x00000018))) = ui32IntFlags;
}
# 946 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
static inline uint32_t
I2CSlaveIntStatus(uint32_t ui32Base, 
# 947 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                    _Bool 
# 947 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
                                         bMasked)
{



    ;





    if(bMasked)
    {
        return((*((volatile unsigned long *)(0x40002000 + 0x00000014))));
    }
    else
    {
        return((*((volatile unsigned long *)(0x40002000 + 0x00000010))));
    }
}
# 989 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
extern void NOROM_I2CIntRegister(uint32_t ui32Base, void (*pfnHandler)(void));
# 1007 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/i2c.h"
extern void NOROM_I2CIntUnregister(uint32_t ui32Base);
# 225 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
extern void NOROM_SSIConfigSetExpClk(uint32_t ui32Base, uint32_t ui32SSIClk,
                               uint32_t ui32Protocol, uint32_t ui32Mode,
                               uint32_t ui32BitRate, uint32_t ui32DataWidth);













static inline void
SSIEnable(uint32_t ui32Base)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000004))) |= 0x00000002;
}












static inline void
SSIDisable(uint32_t ui32Base)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000004))) &= ~(0x00000002);
}
# 298 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
extern void NOROM_SSIDataPut(uint32_t ui32Base, uint32_t ui32Data);
# 319 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
extern int32_t NOROM_SSIDataPutNonBlocking(uint32_t ui32Base, uint32_t ui32Data);
# 342 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
extern void NOROM_SSIDataGet(uint32_t ui32Base, uint32_t *pui32Data);
# 366 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
extern int32_t NOROM_SSIDataGetNonBlocking(uint32_t ui32Base, uint32_t *pui32Data);
# 384 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
static inline 
# 384 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
               _Bool
SSIBusy(uint32_t ui32Base)
{



    ;




    return(((*((volatile unsigned long *)(ui32Base + 0x0000000C))) & 0x00000010) ? 
# 395 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
                                                      1 
# 395 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
                                                           : 
# 395 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
                                                             0
# 395 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
                                                                  );
}
# 415 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
static inline uint32_t
SSIStatus(uint32_t ui32Base)
{



    ;




    return ((*((volatile unsigned long *)(ui32Base + 0x0000000C))) & 0x0000000F);
}
# 449 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
extern void NOROM_SSIIntRegister(uint32_t ui32Base, void (*pfnHandler)(void));
# 467 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
extern void NOROM_SSIIntUnregister(uint32_t ui32Base);
# 487 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
static inline void
SSIIntEnable(uint32_t ui32Base, uint32_t ui32IntFlags)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000014))) |= ui32IntFlags;
}
# 517 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
static inline void
SSIIntDisable(uint32_t ui32Base, uint32_t ui32IntFlags)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000014))) &= ~(ui32IntFlags);
}
# 563 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
static inline void
SSIIntClear(uint32_t ui32Base, uint32_t ui32IntFlags)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000020))) = ui32IntFlags;
}
# 597 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
static inline uint32_t
SSIIntStatus(uint32_t ui32Base, 
# 598 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
                               _Bool 
# 598 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
                                    bMasked)
{



    ;





    if(bMasked)
    {
        return((*((volatile unsigned long *)(ui32Base + 0x0000001C))));
    }
    else
    {
        return((*((volatile unsigned long *)(ui32Base + 0x00000018))));
    }
}
# 638 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
static inline void
SSIDMAEnable(uint32_t ui32Base, uint32_t ui32DMAFlags)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000024))) |= ui32DMAFlags;
}
# 668 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ssi.h"
static inline void
SSIDMADisable(uint32_t ui32Base, uint32_t ui32DMAFlags)
{



    ;




    (*((volatile unsigned long *)(ui32Base + 0x00000024))) &= ~ui32DMAFlags;
}
# 419 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCPortConfigureSet(uint32_t ui32IOId, uint32_t ui32PortId,
                                uint32_t ui32IOConfig);
# 440 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern uint32_t NOROM_IOCPortConfigureGet(uint32_t ui32IOId);
# 460 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCIOShutdownSet(uint32_t ui32IOId, uint32_t ui32IOShutdown);
# 484 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCIOModeSet(uint32_t ui32IOId, uint32_t ui32IOMode);
# 508 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCIOIntSet(uint32_t ui32IOId, uint32_t ui32Int,
                        uint32_t ui32EdgeDet);
# 529 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCIOPortPullSet(uint32_t ui32IOId, uint32_t ui32Pull);
# 548 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCIOHystSet(uint32_t ui32IOId, uint32_t ui32Hysteresis);
# 567 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCIOInputSet(uint32_t ui32IOId, uint32_t ui32Input);
# 586 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCIOSlewCtrlSet(uint32_t ui32IOId, uint32_t ui32SlewEnable);
# 624 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCIODrvStrengthSet(uint32_t ui32IOId, uint32_t ui32IOCurrent,
                                uint32_t ui32DrvStrength);
# 681 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCIOPortIdSet(uint32_t ui32IOId, uint32_t ui32PortId);
# 701 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
static inline void
IOCIntRegister(void (*pfnHandler)(void))
{



    NOROM_IntRegister(16, pfnHandler);




    ((void (*)(uint32_t ui32Interrupt)) ((uint32_t*) (((uint32_t *) 0x10000180)[12]))[4])(16);
}














static inline void
IOCIntUnregister(void)
{



    ((void (*)(uint32_t ui32Interrupt)) ((uint32_t*) (((uint32_t *) 0x10000180)[12]))[5])(16);




    NOROM_IntUnregister(16);
}














extern void NOROM_IOCIntEnable(uint32_t ui32IOId);
# 773 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCIntDisable(uint32_t ui32IOId);
# 806 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
static inline void
IOCIntClear(uint32_t ui32IOId)
{



    ;




    GPIO_clearEventDio(ui32IOId);
}













static inline uint32_t
IOCIntStatus(uint32_t ui32IOId)
{



    ;




    return (GPIO_getEventDio(ui32IOId));
}
# 874 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCPinTypeGpioInput(uint32_t ui32IOId);
# 903 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCPinTypeGpioOutput(uint32_t ui32IOId);
# 942 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCPinTypeUart(uint32_t ui32Base, uint32_t ui32Rx,
                           uint32_t ui32Tx, uint32_t ui32Cts,
                           uint32_t ui32Rts);
# 975 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCPinTypeSsiMaster(uint32_t ui32Base, uint32_t ui32Rx,
                                uint32_t ui32Tx, uint32_t ui32Fss,
                                uint32_t ui32Clk);
# 1004 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCPinTypeSsiSlave(uint32_t ui32Base, uint32_t ui32Rx,
                               uint32_t ui32Tx, uint32_t ui32Fss,
                               uint32_t ui32Clk);
# 1027 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCPinTypeI2c(uint32_t ui32Base, uint32_t ui32Data,
                          uint32_t ui32Clk);
# 1051 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ioc.h"
extern void NOROM_IOCPinTypeAux(uint32_t ui32IOId);
# 75 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/sys_ctrl.h"







# 71 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/pwr_ctrl.h"


# 68 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"


# 136 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
static inline void
AuxAdiDdiSafeWrite(uint32_t nAddr, uint32_t nData, uint32_t nSize)
{

   _Bool 
# 140 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
        bIrqEnabled = !NOROM_CPUcpsid();

    while (!(*((volatile unsigned long *)(0x400C8000 + 0x00000000))));
    switch (nSize) {
    case 1: (*((volatile unsigned char *)(nAddr))) = (uint8_t)nData; break;
    case 2: (*((volatile unsigned short *)(nAddr))) = (uint16_t)nData; break;
    case 4: default: (*((volatile unsigned long *)(nAddr))) = nData; break;
    }
    (*((volatile unsigned long *)(0x400C8000 + 0x00000000))) = 1;

    if (bIrqEnabled) {
        NOROM_CPUcpsie();
    }
}














static inline uint32_t
AuxAdiDdiSafeRead(uint32_t nAddr, uint32_t nSize)
{
    uint32_t nRet;

   _Bool 
# 173 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
        bIrqEnabled = !NOROM_CPUcpsid();

    while (!(*((volatile unsigned long *)(0x400C8000 + 0x00000000))));
    switch (nSize) {
    case 1: nRet = (*((volatile unsigned char *)(nAddr))); break;
    case 2: nRet = (*((volatile unsigned short *)(nAddr))); break;
    case 4: default: nRet = (*((volatile unsigned long *)(nAddr))); break;
    }
    (*((volatile unsigned long *)(0x400C8000 + 0x00000000))) = 1;

    if (bIrqEnabled) {
        NOROM_CPUcpsie();
    }
    return nRet;
}
# 230 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
static inline uint32_t
DDI32RegRead(uint32_t ui32Base, uint32_t ui32Reg)
{



    ;
    ;




    return AuxAdiDdiSafeRead(ui32Base + ui32Reg, 4);
}
# 267 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
static inline void
DDI32BitsSet(uint32_t ui32Base, uint32_t ui32Reg, uint32_t ui32Val)
{
    uint32_t ui32RegOffset;




    ;
    ;





    ui32RegOffset = 0x00000040;




    AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset + ui32Reg, ui32Val, 4);
}
# 307 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
static inline void
DDI32BitsClear(uint32_t ui32Base, uint32_t ui32Reg,
               uint32_t ui32Val)
{
    uint32_t ui32RegOffset;




    ;
    ;





    ui32RegOffset = 0x00000080;




    AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset + ui32Reg, ui32Val, 4);
}
# 358 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
static inline void
DDI8SetValBit(uint32_t ui32Base, uint32_t ui32Reg, uint32_t ui32Byte,
              uint16_t ui16Mask, uint16_t ui16Val)
{
    uint32_t ui32RegOffset;




    ;
    ;
    ;
    ;





    ui32RegOffset = 0x00000180 + (ui32Reg << 1) + (ui32Byte << 1);




    AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset, (ui16Mask << 8) | ui16Val, 2);
}
# 411 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
static inline void
DDI16SetValBit(uint32_t ui32Base, uint32_t ui32Reg, 
# 412 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
                                                   _Bool 
# 412 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
                                                        bWriteHigh,
               uint32_t ui32Mask, uint32_t ui32Val)
{
    uint32_t ui32RegOffset;




    ;
    ;
    ;
    ;





    ui32RegOffset = 0x00000200 + (ui32Reg << 1) + (bWriteHigh ? 4 : 0);




    AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset, (ui32Mask << 16) | ui32Val, 4);
}
# 458 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
extern void NOROM_DDI32RegWrite(uint32_t ui32Base, uint32_t ui32Reg, uint32_t ui32Val);
# 479 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
extern void NOROM_DDI16BitWrite(uint32_t ui32Base, uint32_t ui32Reg,
                          uint32_t ui32Mask, uint32_t ui32WrData);
# 502 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
extern void NOROM_DDI16BitfieldWrite(uint32_t ui32Base, uint32_t ui32Reg,
                               uint32_t ui32Mask, uint32_t ui32Shift,
                               uint16_t ui32Data);















extern uint16_t NOROM_DDI16BitRead(uint32_t ui32Base, uint32_t ui32Reg,
                             uint32_t ui32Mask);
# 541 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/ddi.h"
extern uint16_t NOROM_DDI16BitfieldRead(uint32_t ui32Base, uint32_t ui32Reg,
                                  uint32_t ui32Mask, uint32_t ui32Shift);
# 149 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
static inline void
OSCXHfPowerModeSet(uint32_t ui32Mode)
{



   
                                         ;




    ((void (*)(uint32_t ui32Base, uint32_t ui32Reg, uint32_t ui32Mask, uint32_t ui32WrData)) ((uint32_t*) (((uint32_t *) 0x10000180)[9]))[0])(0x400CA000, 0x00000000, 0x00000800,
                  ui32Mode);
}
















static inline void
OSCClockLossEventEnable( void )
{
    ((void (*)(uint32_t ui32Base, uint32_t ui32Reg, uint32_t ui32Mask, uint32_t ui32Shift, uint16_t ui32Data)) ((uint32_t*) (((uint32_t *) 0x10000180)[9]))[1])( 0x400CA000, 0x00000000,
        0x00000200,
        9, 1 );
}
















static inline void
OSCClockLossEventDisable( void )
{
    ((void (*)(uint32_t ui32Base, uint32_t ui32Reg, uint32_t ui32Mask, uint32_t ui32Shift, uint16_t ui32Data)) ((uint32_t*) (((uint32_t *) 0x10000180)[9]))[1])( 0x400CA000, 0x00000000,
        0x00000200,
        9, 0 );
}
# 249 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
extern void NOROM_OSCClockSourceSet(uint32_t ui32SrcClk, uint32_t ui32Osc);
# 272 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
extern uint32_t NOROM_OSCClockSourceGet(uint32_t ui32SrcClk);
















static inline 
# 289 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
               _Bool
OSCHfSourceReady(void)
{



    return (((uint16_t (*)(uint32_t ui32Base, uint32_t ui32Reg, uint32_t ui32Mask, uint32_t ui32Shift)) ((uint32_t*) (((uint32_t *) 0x10000180)[9]))[3])(0x400CA000, 0x00000034,
                              0x00000001,
                              0)) ?
       1 
# 298 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
            : 
# 298 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
              0
# 298 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
                   ;
}
# 319 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
static inline void
OSCHfSourceSwitch(void)
{



    SafeHapiVoid( ((HARD_API_T*) 0x10000048)->HFSourceSafeSwitch );
}
# 347 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
static inline void
OSCInterfaceEnable(void)
{
}
# 370 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
static inline void
OSCInterfaceDisable(void)
{
}














extern uint32_t NOROM_OSCHF_GetStartupTime( uint32_t timeUntilWakeupInMs );












extern void NOROM_OSCHF_TurnOnXosc( void );















extern 
# 417 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
      _Bool 
# 417 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
           NOROM_OSCHF_AttemptToSwitchToXosc( void );












extern void NOROM_OSCHF_SwitchToRcOscTurnOffXosc( void );
# 450 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
extern uint32_t NOROM_OSCHF_DebugGetCrystalAmplitude( void );
















extern uint32_t NOROM_OSCHF_DebugGetExpectedAverageCrystalAmplitude( void );
# 498 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
extern int32_t NOROM_OSC_HPOSCRelativeFrequencyOffsetGet( int32_t tempDegC );
# 526 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/osc.h"
extern int16_t NOROM_OSC_HPOSCRelativeFrequencyOffsetToRFCoreFormatConvert( int32_t HPOSC_RelFreqOffset );
# 74 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/pwr_ctrl.h"


# 133 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_ioc.h"
static inline void
AONIOCDriveStrengthSet(uint32_t ui32DriveLevel, uint32_t ui32DriveStrength)
{
   

                                                  ;
   






                                                   ;




    (*((volatile unsigned long *)(0x40094000 + ui32DriveLevel))) = ui32DriveStrength;
}
# 182 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_ioc.h"
static inline uint32_t
AONIOCDriveStrengthGet(uint32_t ui32DriveLevel)
{



   

                                                  ;




    return( (*((volatile unsigned long *)(0x40094000 + ui32DriveLevel))) );
}
















static inline void
AONIOCFreezeEnable(void)
{



    (*((volatile unsigned long *)(0x40094000 + 0x0000000C))) = 0x0;
}















static inline void
AONIOCFreezeDisable(void)
{



    (*((volatile unsigned long *)(0x40094000 + 0x0000000C))) = 0x00000001;
}














static inline void
AONIOC32kHzOutputDisable(void)
{



    (*((volatile unsigned long *)(0x40094000 + 0x00000010))) = 0x00000001;
}














static inline void
AONIOC32kHzOutputEnable(void)
{



    (*((volatile unsigned long *)(0x40094000 + 0x00000010))) = 0x0;
}
# 148 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI8RegWrite(uint32_t ui32Base, uint32_t ui32Reg, uint8_t ui8Val)
{



    ;
    ;




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + ui32Reg, ui8Val, 1);
    } else {
        (*((volatile unsigned char *)(ui32Base + ui32Reg))) = ui8Val;
    }
}
# 197 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI16RegWrite(uint32_t ui32Base, uint32_t ui32Reg,
              uint16_t ui16Val)
{



    ;
    ;




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + (ui32Reg & 0xFE), ui16Val, 2);
    } else {
        (*((volatile unsigned short *)(ui32Base + (ui32Reg & 0xFE)))) = ui16Val;
    }
}
# 247 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI32RegWrite(uint32_t ui32Base, uint32_t ui32Reg, uint32_t ui32Val)
{



    ;
    ;




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + (ui32Reg & 0xFC), ui32Val, 4);
    } else {
        (*((volatile unsigned long *)(ui32Base + (ui32Reg & 0xFC)))) = ui32Val;
    }
}
# 287 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline uint32_t
ADI8RegRead(uint32_t ui32Base, uint32_t ui32Reg)
{



    ;
    ;




    if (ui32Base==0x400CB000) {
        return AuxAdiDdiSafeRead(ui32Base + ui32Reg, 1);
    } else {
        return((*((volatile unsigned char *)(ui32Base + ui32Reg))));
    }
}
# 330 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline uint32_t
ADI16RegRead(uint32_t ui32Base, uint32_t ui32Reg)
{



    ;
    ;




    if (ui32Base==0x400CB000) {
        return AuxAdiDdiSafeRead(ui32Base + (ui32Reg & 0xFE), 2);
    } else {
        return((*((volatile unsigned short *)(ui32Base + (ui32Reg & 0xFE)))));
    }
}
# 371 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline uint32_t
ADI32RegRead(uint32_t ui32Base, uint32_t ui32Reg)
{



    ;
    ;




    if (ui32Base==0x400CB000) {
        return AuxAdiDdiSafeRead(ui32Base + (ui32Reg & 0xFC), 4);
    } else {
        return((*((volatile unsigned long *)(ui32Base + (ui32Reg & 0xFC)))));
    }
}
# 420 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI8BitsSet(uint32_t ui32Base, uint32_t ui32Reg, uint8_t ui8Val)
{
    uint32_t ui32RegOffset;




    ;
    ;





    ui32RegOffset = 0x00000010;




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset + ui32Reg, ui8Val, 1);
    } else {
        (*((volatile unsigned char *)(ui32Base + ui32RegOffset + ui32Reg))) = ui8Val;
    }
}
# 477 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI16BitsSet(uint32_t ui32Base, uint32_t ui32Reg, uint16_t ui16Val)
{
    uint32_t ui32RegOffset;




    ;
    ;





    ui32RegOffset = 0x00000010;




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset + (ui32Reg & 0xFE), ui16Val, 2);
    } else {
        (*((volatile unsigned short *)(ui32Base + ui32RegOffset + (ui32Reg & 0xFE)))) = ui16Val;
    }
}
# 534 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI32BitsSet(uint32_t ui32Base, uint32_t ui32Reg, uint32_t ui32Val)
{
    uint32_t ui32RegOffset;




    ;
    ;





    ui32RegOffset = 0x00000010;




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset + (ui32Reg & 0xFC), ui32Val, 4);
    } else {
        (*((volatile unsigned long *)(ui32Base + ui32RegOffset + (ui32Reg & 0xFC)))) = ui32Val;
    }
}
# 591 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI8BitsClear(uint32_t ui32Base, uint32_t ui32Reg, uint8_t ui8Val)
{
    uint32_t ui32RegOffset;




    ;
    ;





    ui32RegOffset = 0x00000020;




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset + ui32Reg, ui8Val, 1);
    } else {
        (*((volatile unsigned char *)(ui32Base + ui32RegOffset + ui32Reg))) = ui8Val;
    }
}
# 648 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI16BitsClear(uint32_t ui32Base, uint32_t ui32Reg, uint16_t ui16Val)
{
    uint32_t ui32RegOffset;




    ;
    ;





    ui32RegOffset = 0x00000020;




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset + (ui32Reg & 0xFE), ui16Val, 2);
    } else {
        (*((volatile unsigned short *)(ui32Base + ui32RegOffset + (ui32Reg & 0xFE)))) = ui16Val;
    }
}
# 705 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI32BitsClear(uint32_t ui32Base, uint32_t ui32Reg, uint32_t ui32Val)
{
    uint32_t ui32RegOffset;




    ;
    ;





    ui32RegOffset = 0x00000020;




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset + (ui32Reg & 0xFC), ui32Val, 4);
    } else {
        (*((volatile unsigned long *)(ui32Base + ui32RegOffset + (ui32Reg & 0xFC)))) = ui32Val;
    }
}
# 765 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI4SetValBit(uint32_t ui32Base, uint32_t ui32Reg, 
# 766 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
                                                  _Bool 
# 766 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
                                                       bWriteHigh,
              uint8_t ui8Mask, uint8_t ui8Val)
{
    uint32_t ui32RegOffset;




    ;
    ;
    ;
    ;





    ui32RegOffset = 0x00000040 + (ui32Reg << 1) + (bWriteHigh ? 1 : 0);




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset, (ui8Mask << 4) | ui8Val, 1);
    } else {
        (*((volatile unsigned char *)(ui32Base + ui32RegOffset))) = (ui8Mask << 4) | ui8Val;
    }
}
# 823 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI8SetValBit(uint32_t ui32Base, uint32_t ui32Reg, uint16_t ui16Mask,
              uint16_t ui16Val)
{
    uint32_t ui32RegOffset;




    ;
    ;
    ;
    ;





    ui32RegOffset = 0x00000060 + (ui32Reg << 1);




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset, (ui16Mask << 8) | ui16Val, 2);
    } else {
        (*((volatile unsigned short *)(ui32Base + ui32RegOffset))) = (ui16Mask << 8) | ui16Val;
    }
}
# 882 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/adi.h"
static inline void
ADI16SetValBit(uint32_t ui32Base, uint32_t ui32Reg, uint32_t ui32Mask,
               uint32_t ui32Val)
{
    uint32_t ui32RegOffset;




    ;
    ;
    ;
    ;





    ui32RegOffset = 0x00000080 + ((ui32Reg << 1) & 0xFC);




    if (ui32Base==0x400CB000) {
        AuxAdiDdiSafeWrite(ui32Base + ui32RegOffset, (ui32Mask << 16) | ui32Val, 4);
    } else {
        (*((volatile unsigned long *)(ui32Base + ui32RegOffset))) = (ui32Mask << 16) | ui32Val;
    }
}
# 161 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/pwr_ctrl.h"
extern void NOROM_PowerCtrlSourceSet(uint32_t ui32PowerConfig);
# 179 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/pwr_ctrl.h"
static inline uint32_t
PowerCtrlSourceGet(void)
{
    uint32_t ui32PowerConfig;




    ui32PowerConfig = (*((volatile unsigned long *)(0x40090000 + 0x00000000)));
    if(ui32PowerConfig & 0x00000004)
    {
        return (0x00000001);
    }
    else
    {
        return (0x00000000);
    }
}
# 221 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/pwr_ctrl.h"
static inline uint32_t
PowerCtrlResetSourceGet(void)
{



    return (( (*((volatile unsigned long *)(0x40090000 + 0x00000004))) &
        0x0000000E ) >>
        1 ) ;
}














static inline void
PowerCtrlIOFreezeEnable(void)
{



    AONIOCFreezeEnable();
    (*((volatile unsigned long *)(0x40090000 + 0x00000008))) = 0;
    (*((volatile unsigned long *)(0x40092000 + 0x0000002C)));
}















static inline void
PowerCtrlIOFreezeDisable(void)
{



    AONIOCFreezeDisable();
    (*((volatile unsigned long *)(0x40090000 + 0x00000008))) = 1;
    (*((volatile unsigned long *)(0x40092000 + 0x0000002C)));
}
# 83 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/sys_ctrl.h"


# 155 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_wuc.h"
extern void NOROM_AUXWUCClockEnable(uint32_t ui32Clocks);
# 182 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_wuc.h"
extern void NOROM_AUXWUCClockDisable(uint32_t ui32Clocks);
# 209 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_wuc.h"
extern uint32_t NOROM_AUXWUCClockStatus(uint32_t ui32Clocks);
# 231 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_wuc.h"
static inline void
AUXWUCClockFreqReq(uint32_t ui32ClockFreq)
{



   
                                                   ;




    (*((volatile unsigned long *)(0x400C6000 + 0x00000010))) = ui32ClockFreq;
}
















extern void NOROM_AUXWUCPowerCtrl(uint32_t ui32PowerMode);
















static inline void
AUXWUCFreezeEnable(void)
{



    (*((volatile unsigned long *)(0x400C6000 + 0x00000054))) = 0x0;
}
# 303 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_wuc.h"
static inline void
AUXWUCFreezeDisable(void)
{



    (*((volatile unsigned long *)(0x400C6000 + 0x00000054))) = 0x00000001;
}
# 225 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
static inline void
AONWUCMcuPowerDownConfig(uint32_t ui32ClkSrc)
{
    uint32_t ui32Reg;




   
                                               ;




    ui32Reg = (*((volatile unsigned long *)(0x40091000 + 0x00000000)));
    ui32Reg &= ~0x00000003;
    (*((volatile unsigned long *)(0x40091000 + 0x00000000))) = ui32Reg |
                                             (ui32ClkSrc <<
                                              0);
}
# 264 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
static inline void
AONWUCMcuPowerOffConfig(uint32_t ui32Mode)
{

   
                                                ;


    (*((volatile unsigned long *)(((unsigned long)(0x40091000 + 0x00000008) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40091000 + 0x00000008) & 0x000FFFFF) << 5) | ((17) << 2)))) = (ui32Mode != 0);
}
# 293 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
static inline void
AONWUCMcuWakeUpConfig(uint32_t ui32WakeUp)
{

   
                                             ;


    (*((volatile unsigned long *)(((unsigned long)(0x40091000 + 0x00000008) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40091000 + 0x00000008) & 0x000FFFFF) << 5) | ((16) << 2)))) = (ui32WakeUp != 0);
}
# 330 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
static inline void
AONWUCMcuSRamConfig(uint32_t ui32Retention)
{
    uint32_t ui32Reg;




    ;
    ;




    ui32Reg = (*((volatile unsigned long *)(0x40091000 + 0x00000008))) & ~0x0000000F;
    ui32Reg |= ui32Retention;
    (*((volatile unsigned long *)(0x40091000 + 0x00000008))) = ui32Reg;
}
# 370 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
static inline uint32_t
AONWUCAuxClockConfigGet(void)
{



    return (((*((volatile unsigned long *)(0x40091000 + 0x00000004))) &
             0x00000700) >>
             8);
}
# 399 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
static inline void
AONWUCAuxPowerDownConfig(uint32_t ui32ClkSrc)
{
    uint32_t ui32Reg;




   
                                               ;




    ui32Reg = (*((volatile unsigned long *)(0x40091000 + 0x00000004)));
    ui32Reg &= ~0x00001800;
    (*((volatile unsigned long *)(0x40091000 + 0x00000004))) = ui32Reg |
                                             (ui32ClkSrc <<
                                              11);
}
# 440 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
static inline void
AONWUCAuxSRamConfig(uint32_t ui32Retention)
{

    (*((volatile unsigned long *)(((unsigned long)(0x40091000 + 0x0000000C) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40091000 + 0x0000000C) & 0x000FFFFF) << 5) | ((0) << 2)))) = ui32Retention;
}
# 475 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
static inline void
AONWUCAuxWakeupEvent(uint32_t ui32Mode)
{

   
                                                ;


    (*((volatile unsigned long *)(((unsigned long)(0x40091000 + 0x00000010) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40091000 + 0x00000010) & 0x000FFFFF) << 5) | ((0) << 2)))) = ui32Mode;
}
















extern void NOROM_AONWUCAuxReset(void);











static inline void
AONWUCAuxImageValid(void)
{

    (*((volatile unsigned long *)(((unsigned long)(0x40091000 + 0x00000010) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40091000 + 0x00000010) & 0x000FFFFF) << 5) | ((2) << 2)))) = 1;
}











static inline void
AONWUCAuxImageInvalid(void)
{

    (*((volatile unsigned long *)(((unsigned long)(0x40091000 + 0x00000010) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40091000 + 0x00000010) & 0x000FFFFF) << 5) | ((2) << 2)))) = 0;
}
# 555 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
static inline uint32_t
AONWUCPowerStatusGet(void)
{



    return ((*((volatile unsigned long *)(0x40091000 + 0x00000014))));
}
# 580 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
static inline void
AONWUCShutDownEnable(void)
{


    (*((volatile unsigned long *)(0x40091000 + 0x00000040))) = 0;


    (*((volatile unsigned long *)(((unsigned long)(0x40091000 + 0x00000020) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40091000 + 0x00000020) & 0x000FFFFF) << 5) | ((8) << 2)))) = 0;
    (*((volatile unsigned long *)(0x40091000 + 0x00000018))) = 0x00000001;
}













static inline void
AONWUCDomainPowerDownEnable(void)
{


    (*((volatile unsigned long *)(0x40091000 + 0x00000040))) = 0;


    (*((volatile unsigned long *)(((unsigned long)(0x40091000 + 0x00000020) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40091000 + 0x00000020) & 0x000FFFFF) << 5) | ((8) << 2)))) = 0;
}












static inline void
AONWUCDomainPowerDownDisable(void)
{

    (*((volatile unsigned long *)(((unsigned long)(0x40091000 + 0x00000020) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40091000 + 0x00000020) & 0x000FFFFF) << 5) | ((8) << 2)))) = 1;
}
# 655 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
static inline void
AONWUCMcuResetClear(uint32_t ui32Status)
{



   
                                                ;




    (*((volatile unsigned long *)(0x40091000 + 0x00000024))) = ui32Status;
}










static inline uint32_t
AONWUCMcuResetStatusGet(void)
{



    return ((*((volatile unsigned long *)(0x40091000 + 0x00000024))));
}
# 741 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
extern void NOROM_AONWUCRechargeCtrlConfigSet(
# 741 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
                                       _Bool 
# 741 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
                                            bAdaptEnable,
                                        uint32_t ui32AdaptRate,
                                        uint32_t ui32Period,
                                        uint32_t ui32MaxPeriod);










static inline uint32_t
AONWUCRechargeCtrlConfigGet(void)
{



    return((*((volatile unsigned long *)(0x40091000 + 0x00000030))));
}
# 798 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_wuc.h"
extern void NOROM_AONWUCOscConfig(uint32_t ui32Period);
















static inline void
AONWUCJtagPowerOff(void)
{



    (*((volatile unsigned long *)(0x40091000 + 0x00000040))) = 0;
}
# 87 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/sys_ctrl.h"



# 150 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/vims.h"
extern void NOROM_VIMSConfigure(uint32_t ui32Base, 
# 150 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/vims.h"
                                            _Bool 
# 150 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/vims.h"
                                                 bRoundRobin,
                         _Bool 
# 151 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/vims.h"
                              bPrefetch);
# 207 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/vims.h"
extern void NOROM_VIMSModeSet(uint32_t ui32Base, uint32_t ui32Mode);
# 226 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/vims.h"
extern uint32_t NOROM_VIMSModeGet(uint32_t ui32Base);
# 280 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/vims.h"
extern void NOROM_VIMSModeSafeSet( uint32_t ui32Base ,
                             uint32_t ui32NewMode ,
                            _Bool 
# 282 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/vims.h"
                                     blocking );















static inline void
VIMSLineBufDisable(uint32_t ui32Base)
{



    (*((volatile unsigned long *)(ui32Base + 0x00000004))) |= 0x00000020 |
                                        0x00000010;
}















static inline void
VIMSLineBufEnable(uint32_t ui32Base)
{



    (*((volatile unsigned long *)(ui32Base + 0x00000004))) &= ~(0x00000020 |
                                          0x00000010);
}
# 158 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/sys_ctrl.h"
extern void NOROM_SysCtrlPowerEverything(void);













static inline uint32_t
SysCtrlClockGet( void )
{



    return( 48000000 );
}















static inline void
SysCtrlAonSync(void)
{



    (*((volatile unsigned long *)(0x40092000 + 0x0000002C)));
}
# 222 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/sys_ctrl.h"
static inline void
SysCtrlAonUpdate(void)
{




    (*((volatile unsigned long *)(0x40092000 + 0x0000002C))) = 1;
    (*((volatile unsigned long *)(0x40092000 + 0x0000002C)));
}
# 257 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/sys_ctrl.h"
extern void NOROM_SysCtrlSetRechargeBeforePowerDown( uint32_t xoscPowerMode );
# 279 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/sys_ctrl.h"
extern void NOROM_SysCtrlAdjustRechargeAfterPowerDown( void );
# 297 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/sys_ctrl.h"
extern void NOROM_SysCtrl_DCDC_VoltageConditionalControl( void );
# 322 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/sys_ctrl.h"
extern uint32_t NOROM_SysCtrlResetSourceGet( void );








static inline void
SysCtrlSystemReset( void )
{

   NOROM_CPUcpsid();

   (*((volatile unsigned long *)(((unsigned long)(0x40090000 + 0x00000004) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40090000 + 0x00000004) & 0x000FFFFF) << 5) | ((31) << 2)))) = 1;

   while ( 1 ) {

   }
}
# 361 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/sys_ctrl.h"
static inline void
SysCtrlClockLossResetEnable(void)
{



    (*((volatile unsigned long *)(((unsigned long)(0x40090000 + 0x00000004) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40090000 + 0x00000004) & 0x000FFFFF) << 5) | ((4) << 2)))) = 1;
}














static inline void
SysCtrlClockLossResetDisable(void)
{



    (*((volatile unsigned long *)(((unsigned long)(0x40090000 + 0x00000004) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40090000 + 0x00000004) & 0x000FFFFF) << 5) | ((4) << 2)))) = 0;
}
# 173 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline void
AONRTCEnable(void)
{



    (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000000) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000000) & 0x000FFFFF) << 5) | ((0) << 2)))) = 1;
}















static inline void
AONRTCDisable(void)
{



    (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000000) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000000) & 0x000FFFFF) << 5) | ((0) << 2)))) = 0;
}










static inline void
AONRTCReset(void)
{



    (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000000) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000000) & 0x000FFFFF) << 5) | ((7) << 2)))) = 1;
}










static inline 
# 232 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
               _Bool
AONRTCActive(void)
{

    return((*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000000) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000000) & 0x000FFFFF) << 5) | ((0) << 2)))));
}
















static inline 
# 254 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
               _Bool
AONRTCChannelActive(uint32_t ui32Channel)
{
    uint32_t uint32Status = 0;

    if(ui32Channel & 0x1)
    {
        uint32Status = (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((0) << 2))));
    }

    if(ui32Channel & 0x2)
    {
        uint32Status = (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((8) << 2))));
    }

    if(ui32Channel & 0x4)
    {
        uint32Status = (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((16) << 2))));
    }

    return(uint32Status);
}
# 307 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline void
AONRTCDelayConfig(uint32_t ui32Delay)
{
    uint32_t ui32Cfg;




    ;


    ui32Cfg = (*((volatile unsigned long *)(0x40092000 + 0x00000000)));
    ui32Cfg &= ~(0x00000F00);
    ui32Cfg |= (ui32Delay << 8);

    (*((volatile unsigned long *)(0x40092000 + 0x00000000))) = ui32Cfg;
}
# 344 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline void
AONRTCCombinedEventConfig(uint32_t ui32Channels)
{
    uint32_t ui32Cfg;




   
                                               ;

    ui32Cfg = (*((volatile unsigned long *)(0x40092000 + 0x00000000)));
    ui32Cfg &= ~(0x00070000);
    ui32Cfg |= (ui32Channels << 16);

    (*((volatile unsigned long *)(0x40092000 + 0x00000000))) = ui32Cfg;
}
















static inline void
AONRTCEventClear(uint32_t ui32Channel)
{

   

                                        ;

    if(ui32Channel & 0x1)
    {
        (*((volatile unsigned long *)(0x40092000 + 0x00000004))) = 0x00000001;
    }

    if(ui32Channel & 0x2)
    {
        (*((volatile unsigned long *)(0x40092000 + 0x00000004))) = 0x00000100;
    }

    if(ui32Channel & 0x4)
    {
        (*((volatile unsigned long *)(0x40092000 + 0x00000004))) = 0x00010000;
    }
}
# 418 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline 
# 418 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
               _Bool
AONRTCEventGet(uint32_t ui32Channel)
{
    uint32_t uint32Event = 0;


   

                                        ;

    if(ui32Channel & 0x1)
    {
        uint32Event = (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000004) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000004) & 0x000FFFFF) << 5) | ((0) << 2))));
    }

    if(ui32Channel & 0x2)
    {
        uint32Event = (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000004) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000004) & 0x000FFFFF) << 5) | ((8) << 2))));
    }

    if(ui32Channel & 0x4)
    {
        uint32Event = (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000004) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000004) & 0x000FFFFF) << 5) | ((16) << 2))));
    }

    return(uint32Event);
}
# 466 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline uint32_t
AONRTCSecGet(void)
{




    return((*((volatile unsigned long *)(0x40092000 + 0x00000008))));
}
# 496 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline uint32_t
AONRTCFractionGet(void)
{








    return((*((volatile unsigned long *)(0x40092000 + 0x0000000C))));
}
# 528 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline uint32_t
AONRTCSubSecIncrGet(void)
{
    return((*((volatile unsigned long *)(0x40092000 + 0x00000010))));
}
# 554 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline void
AONRTCModeCh1Set(uint32_t ui32Mode)
{

   
                                                  ;

    (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((9) << 2)))) = ui32Mode;
}
















static inline uint32_t
AONRTCModeCh1Get(void)
{
    return((*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((9) << 2)))));
}
# 608 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline void
AONRTCModeCh2Set(uint32_t ui32Mode)
{

   
                                                        ;

    (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((18) << 2)))) = ui32Mode;
}
# 636 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline uint32_t
AONRTCModeCh2Get(void)
{
    return((*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((18) << 2)))));
}
# 661 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline void
AONRTCChannelEnable(uint32_t ui32Channel)
{

   

                                        ;

    if(ui32Channel & 0x1)
    {
        (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((0) << 2)))) = 1;
    }

    if(ui32Channel & 0x2)
    {
        (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((8) << 2)))) = 1;
    }

    if(ui32Channel & 0x4)
    {
        (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((16) << 2)))) = 1;
    }
}
# 704 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline void
AONRTCChannelDisable(uint32_t ui32Channel)
{

   

                                        ;

    if(ui32Channel & 0x1)
    {
        (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((0) << 2)))) = 0;
    }

    if(ui32Channel & 0x2)
    {
        (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((8) << 2)))) = 0;
    }

    if(ui32Channel & 0x4)
    {
        (*((volatile unsigned long *)(((unsigned long)(0x40092000 + 0x00000014) & 0xF0000000) | 0x02000000 | (((unsigned long)(0x40092000 + 0x00000014) & 0x000FFFFF) << 5) | ((16) << 2)))) = 0;
    }
}
# 751 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline void
AONRTCCompareValueSet(uint32_t ui32Channel, uint32_t ui32CompValue)
{

   

                                        ;

    if(ui32Channel & 0x1)
    {
        (*((volatile unsigned long *)(0x40092000 + 0x00000018))) = ui32CompValue;
    }

    if(ui32Channel & 0x2)
    {
        (*((volatile unsigned long *)(0x40092000 + 0x0000001C))) = ui32CompValue;
    }

    if(ui32Channel & 0x4)
    {
        (*((volatile unsigned long *)(0x40092000 + 0x00000020))) = ui32CompValue;
    }
}
















static inline uint32_t
AONRTCCompareValueGet(uint32_t ui32Channel)
{
    uint32_t ui32Value = 0;


   

                                        ;

    if(ui32Channel & 0x1)
    {
        ui32Value = (*((volatile unsigned long *)(0x40092000 + 0x00000018)));
    }

    if(ui32Channel & 0x2)
    {
        ui32Value = (*((volatile unsigned long *)(0x40092000 + 0x0000001C)));
    }

    if(ui32Channel & 0x4)
    {
        ui32Value = (*((volatile unsigned long *)(0x40092000 + 0x00000020)));
    }

    return(ui32Value);
}
# 837 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
extern uint32_t NOROM_AONRTCCurrentCompareValueGet(void);













extern uint64_t NOROM_AONRTCCurrent64BitValueGet(void);
# 869 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline void
AONRTCIncValueCh2Set(uint32_t ui32IncValue)
{
    (*((volatile unsigned long *)(0x40092000 + 0x00000024))) = ui32IncValue;
}
# 891 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_rtc.h"
static inline uint32_t
AONRTCIncValueCh2Get(void)
{
    return((*((volatile unsigned long *)(0x40092000 + 0x00000024))));
}













static inline uint32_t
AONRTCCaptureValueCh1Get(void)
{
    return((*((volatile unsigned long *)(0x40092000 + 0x00000028))));
}
# 218 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_event.h"
extern void NOROM_AONEventMcuWakeUpSet(uint32_t ui32MCUWUEvent,
                                 uint32_t ui32EventSrc);
# 267 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_event.h"
extern uint32_t NOROM_AONEventMcuWakeUpGet(uint32_t ui32MCUWUEvent);
# 318 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_event.h"
extern void NOROM_AONEventAuxWakeUpSet(uint32_t ui32AUXWUEvent,
                                 uint32_t ui32EventSrc);
# 366 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_event.h"
extern uint32_t NOROM_AONEventAuxWakeUpGet(uint32_t ui32AUXWUEvent);
# 421 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_event.h"
extern void NOROM_AONEventMcuSet(uint32_t ui32MCUEvent, uint32_t ui32EventSrc);
# 469 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_event.h"
extern uint32_t NOROM_AONEventMcuGet(uint32_t ui32MCUEvent);
# 512 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_event.h"
static inline void
AONEventRtcSet(uint32_t ui32EventSrc)
{
    uint32_t ui32Ctrl;




    ;

    ui32Ctrl = (*((volatile unsigned long *)(0x40093000 + 0x0000000C)));
    ui32Ctrl &= ~(0x0000003F);
    ui32Ctrl |= (ui32EventSrc & 0x3f) << 0;

    (*((volatile unsigned long *)(0x40093000 + 0x0000000C))) = ui32Ctrl;
}
# 568 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_event.h"
static inline uint32_t
AONEventRtcGet(void)
{
    uint32_t ui32EventSrc;




    ui32EventSrc = (*((volatile unsigned long *)(0x40093000 + 0x0000000C)));

    return ((ui32EventSrc & 0x0000003F) >>
            0);
}
# 122 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
static inline void
AONBatMonEnable(void)
{



    (*((volatile unsigned long *)(0x40095000 + 0x00000000))) =
        0x00000002 |
        0x00000001;
}











static inline void
AONBatMonDisable(void)
{



    (*((volatile unsigned long *)(0x40095000 + 0x00000000))) = 0;
}
# 170 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
extern int32_t NOROM_AONBatMonTemperatureGetDegC( void );
# 190 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
static inline uint32_t
AONBatMonBatteryVoltageGet(void)
{
    uint32_t ui32CurrentBattery;

    ui32CurrentBattery = (*((volatile unsigned long *)(0x40095000 + 0x00000028)));




    return (ui32CurrentBattery >> 0);
}
# 223 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
static inline 
# 223 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
               _Bool
AONBatMonNewBatteryMeasureReady(void)
{
   _Bool 
# 226 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
        bStatus;




    bStatus = (*((volatile unsigned long *)(0x40095000 + 0x0000002C))) &
              0x00000001 ? 
# 232 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
                                      1 
# 232 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
                                           : 
# 232 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
                                             0
# 232 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
                                                  ;




    if(bStatus)
    {
        (*((volatile unsigned long *)(0x40095000 + 0x0000002C))) = 1;
    }




    return (bStatus);
}
# 268 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
static inline 
# 268 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
               _Bool
AONBatMonNewTempMeasureReady(void)
{
   _Bool 
# 271 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
        bStatus;




    bStatus = (*((volatile unsigned long *)(0x40095000 + 0x00000034))) &
              0x00000001 ? 
# 277 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
                                       1 
# 277 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
                                            : 
# 277 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
                                              0
# 277 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aon_batmon.h"
                                                   ;




    if(bStatus)
    {
        (*((volatile unsigned long *)(0x40095000 + 0x00000034))) = 1;
    }




    return (bStatus);
}
# 68 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"

# 181 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"
extern void NOROM_AUXADCDisable(void);
# 214 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"
extern void NOROM_AUXADCEnableAsync(uint32_t refSource, uint32_t trigger);
# 263 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"
extern void NOROM_AUXADCEnableSync(uint32_t refSource, uint32_t sampleTime, uint32_t trigger);
















extern void NOROM_AUXADCDisableInputScaling(void);










extern void NOROM_AUXADCFlushFifo(void);









static inline void
AUXADCGenManualTrigger(void)
{
    (*((volatile unsigned long *)(0x400C9000 + 0x0000001C))) = 0;
}
# 323 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"
static inline uint32_t
AUXADCGetFifoStatus(void)
{
    return (*((volatile unsigned long *)(0x400C9000 + 0x00000014)));
}















extern uint32_t NOROM_AUXADCReadFifo(void);













extern uint32_t NOROM_AUXADCPopFifo(void);
# 380 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"
static inline void
AUXADCSelectInput(uint32_t input)
{
    SafeHapiAuxAdiSelect( ((HARD_API_T*) 0x10000048)->SelectADCCompBInput, input );
}
# 404 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"
extern int32_t NOROM_AUXADCGetAdjustmentGain(uint32_t refSource);
# 425 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"
extern int32_t NOROM_AUXADCGetAdjustmentOffset(uint32_t refSource);
# 446 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"
extern int32_t NOROM_AUXADCValueToMicrovolts(int32_t fixedRefVoltage, int32_t adcValue);
# 467 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"
extern int32_t NOROM_AUXADCMicrovoltsToValue(int32_t fixedRefVoltage, int32_t microvolts);
# 487 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"
extern int32_t NOROM_AUXADCAdjustValueForGainAndOffset(int32_t adcValue, int32_t gain, int32_t offset);
# 509 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/CC13XXWARE/driverlib/aux_adc.h"
extern int32_t NOROM_AUXADCUnadjustValueForGainAndOffset(int32_t adcValue, int32_t gain, int32_t offset);
# 28 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/arch.h"



#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpacked"
#pragma GCC diagnostic ignored "-Wattributes"
# 57 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
  struct __attribute__((packed)) T_UINT32 { uint32_t v; };
#pragma GCC diagnostic pop
# 80 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __enable_irq(void)
{
  __asm volatile ("cpsie i" : : : "memory");
}







__attribute__((always_inline)) static inline void __disable_irq(void)
{
  __asm volatile ("cpsid i" : : : "memory");
}







__attribute__((always_inline)) static inline uint32_t __get_CONTROL(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, control" : "=r" (result) );
  return(result);
}
# 132 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_CONTROL(uint32_t control)
{
  __asm volatile ("MSR control, %0" : : "r" (control) : "memory");
}
# 156 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __get_IPSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, ipsr" : "=r" (result) );
  return(result);
}







__attribute__((always_inline)) static inline uint32_t __get_APSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, apsr" : "=r" (result) );
  return(result);
}







__attribute__((always_inline)) static inline uint32_t __get_xPSR(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, xpsr" : "=r" (result) );
  return(result);
}







__attribute__((always_inline)) static inline uint32_t __get_PSP(void)
{
  register uint32_t result;

  __asm volatile ("MRS %0, psp" : "=r" (result) );
  return(result);
}
# 228 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_PSP(uint32_t topOfProcStack)
{
  __asm volatile ("MSR psp, %0" : : "r" (topOfProcStack) : "sp");
}
# 252 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __get_MSP(void)
{
  register uint32_t result;

  __asm volatile ("MRS %0, msp" : "=r" (result) );
  return(result);
}
# 282 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_MSP(uint32_t topOfMainStack)
{
  __asm volatile ("MSR msp, %0" : : "r" (topOfMainStack) : "sp");
}
# 306 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __get_PRIMASK(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, primask" : "=r" (result) );
  return(result);
}
# 336 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_PRIMASK(uint32_t priMask)
{
  __asm volatile ("MSR primask, %0" : : "r" (priMask) : "memory");
}
# 363 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __enable_fault_irq(void)
{
  __asm volatile ("cpsie f" : : : "memory");
}







__attribute__((always_inline)) static inline void __disable_fault_irq(void)
{
  __asm volatile ("cpsid f" : : : "memory");
}







__attribute__((always_inline)) static inline uint32_t __get_BASEPRI(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, basepri" : "=r" (result) );
  return(result);
}
# 415 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_BASEPRI(uint32_t basePri)
{
  __asm volatile ("MSR basepri, %0" : : "r" (basePri) : "memory");
}
# 440 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_BASEPRI_MAX(uint32_t basePri)
{
  __asm volatile ("MSR basepri_max, %0" : : "r" (basePri) : "memory");
}







__attribute__((always_inline)) static inline uint32_t __get_FAULTMASK(void)
{
  uint32_t result;

  __asm volatile ("MRS %0, faultmask" : "=r" (result) );
  return(result);
}
# 481 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __set_FAULTMASK(uint32_t faultMask)
{
  __asm volatile ("MSR faultmask, %0" : : "r" (faultMask) : "memory");
}
# 735 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline void __ISB(void)
{
  __asm volatile ("isb 0xF":::"memory");
}







__attribute__((always_inline)) static inline void __DSB(void)
{
  __asm volatile ("dsb 0xF":::"memory");
}







__attribute__((always_inline)) static inline void __DMB(void)
{
  __asm volatile ("dmb 0xF":::"memory");
}








__attribute__((always_inline)) static inline uint32_t __REV(uint32_t value)
{

  return __builtin_bswap32(value);






}








__attribute__((always_inline)) static inline uint32_t __REV16(uint32_t value)
{
  uint32_t result;

  __asm volatile ("rev16 %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}








__attribute__((always_inline)) static inline int32_t __REVSH(int32_t value)
{

  return (short)__builtin_bswap16(value);






}









__attribute__((always_inline)) static inline uint32_t __ROR(uint32_t op1, uint32_t op2)
{
  return (op1 >> op2) | (op1 << (32U - op2));
}
# 845 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __RBIT(uint32_t value)
{
  uint32_t result;




   __asm volatile ("rbit %0, %1" : "=r" (result) : "r" (value) );












  return(result);
}
# 888 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint8_t __LDREXB(volatile uint8_t *addr)
{
    uint32_t result;


   __asm volatile ("ldrexb %0, %1" : "=r" (result) : "Q" (*addr) );






   return ((uint8_t) result);
}








__attribute__((always_inline)) static inline uint16_t __LDREXH(volatile uint16_t *addr)
{
    uint32_t result;


   __asm volatile ("ldrexh %0, %1" : "=r" (result) : "Q" (*addr) );






   return ((uint16_t) result);
}








__attribute__((always_inline)) static inline uint32_t __LDREXW(volatile uint32_t *addr)
{
    uint32_t result;

   __asm volatile ("ldrex %0, %1" : "=r" (result) : "Q" (*addr) );
   return(result);
}










__attribute__((always_inline)) static inline uint32_t __STREXB(uint8_t value, volatile uint8_t *addr)
{
   uint32_t result;

   __asm volatile ("strexb %0, %2, %1" : "=&r" (result), "=Q" (*addr) : "r" ((uint32_t)value) );
   return(result);
}










__attribute__((always_inline)) static inline uint32_t __STREXH(uint16_t value, volatile uint16_t *addr)
{
   uint32_t result;

   __asm volatile ("strexh %0, %2, %1" : "=&r" (result), "=Q" (*addr) : "r" ((uint32_t)value) );
   return(result);
}










__attribute__((always_inline)) static inline uint32_t __STREXW(uint32_t value, volatile uint32_t *addr)
{
   uint32_t result;

   __asm volatile ("strex %0, %2, %1" : "=&r" (result), "=Q" (*addr) : "r" (value) );
   return(result);
}






__attribute__((always_inline)) static inline void __CLREX(void)
{
  __asm volatile ("clrex" ::: "memory");
}
# 1047 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/cmsis_gcc.h"
__attribute__((always_inline)) static inline uint32_t __RRX(uint32_t value)
{
  uint32_t result;

  __asm volatile ("rrx %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}








__attribute__((always_inline)) static inline uint8_t __LDRBT(volatile uint8_t *ptr)
{
    uint32_t result;


   __asm volatile ("ldrbt %0, %1" : "=r" (result) : "Q" (*ptr) );






   return ((uint8_t) result);
}








__attribute__((always_inline)) static inline uint16_t __LDRHT(volatile uint16_t *ptr)
{
    uint32_t result;


   __asm volatile ("ldrht %0, %1" : "=r" (result) : "Q" (*ptr) );






   return ((uint16_t) result);
}








__attribute__((always_inline)) static inline uint32_t __LDRT(volatile uint32_t *ptr)
{
    uint32_t result;

   __asm volatile ("ldrt %0, %1" : "=r" (result) : "Q" (*ptr) );
   return(result);
}








__attribute__((always_inline)) static inline void __STRBT(uint8_t value, volatile uint8_t *ptr)
{
   __asm volatile ("strbt %1, %0" : "=Q" (*ptr) : "r" ((uint32_t)value) );
}








__attribute__((always_inline)) static inline void __STRHT(uint16_t value, volatile uint16_t *ptr)
{
   __asm volatile ("strht %1, %0" : "=Q" (*ptr) : "r" ((uint32_t)value) );
}








__attribute__((always_inline)) static inline void __STRT(uint32_t value, volatile uint32_t *ptr)
{
   __asm volatile ("strt %1, %0" : "=Q" (*ptr) : "r" (value) );
}
#pragma GCC diagnostic pop
# 32 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/arch.h"






typedef uint8_t Boolean;
typedef uint16_t word;
typedef int32_t sint;
typedef int16_t wint;
typedef int32_t lint;
typedef uint8_t byte;
typedef uint32_t lword;
typedef uint32_t aword;
typedef word *address;



typedef struct {

 byte pdmode:1,
  evntpn:1,
  fstblk:1,
  ledblk:1,
  ledsts:4;

 byte ledblc,

  reqpdm,
  effpdm;

 lword ondmns;

} systat_t;

extern volatile systat_t __pi_systat;

extern char *__bss_start__, *__bss_end__;
# 121 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/arch.h"
void __pi_release () __attribute__ ((noreturn));
# 116 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/mach.h"
void tci_run_delay_timer ();
void tci_run_auxiliary_timer ();
word tci_update_delay_ticks (Boolean);
# 1 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/uart_def.h"







# 137 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/mach.h"






typedef struct {
 uint32_t base;
 word rate;
 volatile byte flags;
} uart_t;





extern uart_t __pi_uart [];







word __pi_uart_getrate (const uart_t*);

Boolean __pi_uart_setrate (word, uart_t*);
# 1 "/home/martin/Desktop/OLSONET/PICOS/PicOS/PLibs/IO/pins.h"







# 1 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/pins_sys.h"












# 1 "/home/martin/Desktop/OLSONET/PICOS/PicOS/PLibs/Sensors/analog_sensor.h"







# 11 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/sensors_sys.h"
typedef struct {

 lword W [3];

} i_sensdesc_t;

typedef struct {

 byte tp,
  dummy;
 word nsamples;
 word adcpars [4];

} a_sensdesc_t;

typedef struct {

 byte tp, num, dummy [2];
 void (*fun_val) (word, const byte*, address);
 void (*fun_ini) ();

} d_sensdesc_t;
# 74 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/sensors_sys.h"
void __pi_batmon (word, const byte*, address);
# 12 "/home/martin/Desktop/OLSONET/PICOS/PicOS/PLibs/Sensors/sensors.h"

void read_sensor (word, sint, address);



void wait_sensor (sint, word);
# 9 "/home/martin/Desktop/OLSONET/PICOS/PicOS/PLibs/Sensors/analog_sensor.h"



void analog_sensor_read (word, const a_sensdesc_t*, address);
# 1 "/home/martin/Desktop/OLSONET/PICOS/PicOS/PLibs/Sensors/pin_sensor.h"














void pin_sensor_init ();
void pin_sensor_read (word, const byte*, address);
# 86 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/pins_sys.h"
Boolean __pi_pin_available (word);
Boolean __pi_pin_adc_available (word);
word __pi_pin_ivalue (word);
word __pi_pin_ovalue (word);
Boolean __pi_pin_adc (word);
Boolean __pi_pin_output (word);
void __pi_pin_set (word);
void __pi_pin_clear (word);
void __pi_pin_set_input (word);
void __pi_pin_set_output (word);
void __pi_pin_set_adc (word);
# 145 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/pins_sys.h"
typedef struct {

 byte pnum:7,
  edge:1;

} piniod_t;





extern const piniod_t __input_pins [];
void __pinlist_setirq (int);
# 9 "/home/martin/Desktop/OLSONET/PICOS/PicOS/PLibs/IO/pins.h"


# 1 "/home/martin/Desktop/OLSONET/PICOS/PicOS/PLibs/IO/buttons.h"







# 1 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/buttons_sys.h"





extern const word __button_list [];
# 29 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/buttons_sys.h"
void __buttons_setirq (int);
# 9 "/home/martin/Desktop/OLSONET/PICOS/PicOS/PLibs/IO/buttons.h"



void buttons_action (void (*action)(word));
# 193 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/mach.h"
extern void __pi_ondomain (lword), __pi_offdomain (lword);

extern lword system_event_count;
# 364 "/home/martin/Desktop/OLSONET/PICOS/PicOS/sysio.h"
void root (word state);

typedef void (*fsmcode)(word);

void __pi_wait (aword, word);
void __pi_trigger (aword), __pi_ptrigger (aword, aword);
aword __pi_fork (fsmcode func, aword data);
aword __pi_join (aword, word);
void reset (void) __attribute__ ((noreturn)) ;
void halt (void) __attribute__ ((noreturn)) ;

int __pi_strlen (const char*);
void __pi_strcpy (char*, const char*);
void __pi_strncpy (char*, const char*, int);
void __pi_strcat (char*, const char*);
void __pi_strncat (char*, const char*, int);
void __pi_memcpy (char *dest, const char *src, int);
void __pi_memset (char *dest, char c, int);

extern const char __pi_hex_enc_table [];


extern const lword host_id;



aword *__pi_malloc (word);
void __pi_free (aword*);
void __pi_waitmem (word);


word __pi_memfree (address);
word __pi_maxfree (address);
# 423 "/home/martin/Desktop/OLSONET/PICOS/PicOS/sysio.h"
word __pi_stackfree (void);







void __pi_syserror (word, const char*) __attribute__ ((noreturn)) ;
# 547 "/home/martin/Desktop/OLSONET/PICOS/PicOS/sysio.h"
void diag (const char *, ...);







lword lrnd (void);
# 575 "/home/martin/Desktop/OLSONET/PICOS/PicOS/sysio.h"
sint io (word, word, word, char*, word);








void unwait (void);


void delay (word, word);
word dleft (aword);





void kill (aword);

void killall (fsmcode);






aword running (fsmcode);
word crunning (fsmcode);

fsmcode getcode (aword);

void proceed (word);

void setpowermode (word);



void utimer_add (address), utimer_delete (address);


void __pi_utimer_set (address, word);






void udelay (word);
void mdelay (word);
# 667 "/home/martin/Desktop/OLSONET/PICOS/PicOS/sysio.h"
void __pi_badstate (void);
# 1 "/home/martin/Desktop/OLSONET/PICOS/PicOS/PLibs/VNetI/tcv_defs.h"







typedef struct {






 word head,
  tail;
} tcvadp_t;




typedef struct {
 int (*tcv_ope) (int, int, va_list);
 int (*tcv_clo) (int, int);
 int (*tcv_rcv) (int, address, int, int*, tcvadp_t*);
 int (*tcv_frm) (address, tcvadp_t*);
 int (*tcv_out) (address);
 int (*tcv_xmt) (address);
 int (*tcv_tmt) (address);
 int tcv_info;
} tcvplug_t;




struct __tcv_qitem_s {
 struct __tcv_qitem_s *next,
    *prev;
};

typedef struct __tcv_qitem_s __tcv_qitem_t;
typedef struct __tcv_qitem_s __tcv_qhead_t;




struct __tcv_titem_s {

 struct __tcv_titem_s *next,
    *prev;
 word value;
};

typedef struct __tcv_titem_s __tcv_titem_t;

typedef struct {
 __tcv_titem_t *next,
    *prev;
} __tcv_thead_t;

typedef union {
 word value;
 struct {
  word queued:1,
   outgoing:1,
   urgent:1,
   session:7,
   plugin:3,
   phys:3;
 } b;
} __tcv_battr_t;




struct __tcv_hblock_s {



    union {
 __tcv_qitem_t bqueue;
 tcvadp_t pointers;





    } u;










 word length;




 __tcv_battr_t attributes;












};



typedef struct __tcv_hblock_s __tcv_hblock_t;

typedef struct {



 __tcv_qhead_t rqueue;



 __tcv_battr_t attpattern;














} __tcv_sesdesc_t;
# 168 "/home/martin/Desktop/OLSONET/PICOS/PicOS/PLibs/VNetI/tcv_defs.h"
int tcv_plug (int, const tcvplug_t*);
int tcv_open (word, int, int, ...);
int tcv_close (word, int);
address tcv_rnp (word, int);
address tcv_wnps (word, int, int, Boolean);
int tcv_qsize (int, int);
int tcv_erase (int, int);
int tcv_read (address, byte*, int);
int tcv_write (address, const byte*, int);
void tcv_endp (address);
void tcv_drop (address);
int tcv_control (int, int, address);
# 728 "/home/martin/Desktop/OLSONET/PICOS/PicOS/sysio.h"
extern lword entropy;
# 771 "/home/martin/Desktop/OLSONET/PICOS/PicOS/sysio.h"
typedef struct {



 word State;
 aword Event;
} __pi_event_t;

struct __pi_pcb_s {








 word Status;
 word Timer;
 fsmcode code;
 aword data;
 __pi_event_t Events [4];
 struct __pi_pcb_s *Next;
};

typedef struct __pi_pcb_s __pi_pcb_t;

extern __pi_pcb_t *__pi_curr;
# 12 "/home/martin/Desktop/OLSONET/PICOS/PicOS/PLibs/Serial/ser.h"
int ser_out (word, const char*);
int ser_in (word, char*, int);
int ser_outb (word, const char*);
# 1 "/home/martin/Desktop/OLSONET/PICOS/PicOS/PLibs/Serial/serf.h"







# 11 "/home/martin/Desktop/OLSONET/PICOS/PicOS/PLibs/Serial/form.h"
word __pi_vfparse (char*, word, const char*, va_list);
char *vform (char*, const char*, va_list);
int vscan (const char*, const char*, va_list);
char *form (char*, const char*, ...);
word fsize (const char*, ...);
int scan (const char*, const char*, ...);
# 9 "/home/martin/Desktop/OLSONET/PICOS/PicOS/PLibs/Serial/serf.h"



int ser_outf (word, const char*, ...);
int ser_inf (word, const char*, ...);
# 16 "/home/martin/Desktop/OLSONET/PICOS/PicOS/kernel/kernel.h"


void __pi_set_release (void);
void update_n_wake (word, Boolean);


void __pi_init_sensors (void);






extern word __pi_mintk;
extern volatile word __pi_old, __pi_new;

extern void tcv_init (void);

extern __pi_pcb_t *__PCB;
# 67 "/home/martin/Desktop/OLSONET/PICOS/PicOS/kernel/kernel.h"
typedef void (*devinitfun_t)(int param);
typedef int (*devreqfun_t)(int, char*, int);

typedef struct {



 devinitfun_t init;
 int param;
} devinit_t;

void adddevfunc (devreqfun_t, int);
# 9 "app.cc"

# 10 "/home/martin/Desktop/OLSONET/PICOS/PicOS/CC13XX/phys_cc1350.h"
void phys_cc1350 (int, int);
# 12 "/home/martin/Desktop/OLSONET/PICOS/PicOS/VLibs/PlugNull/plug_null.h"
extern const tcvplug_t plug_null;
# 12 "app.cc"






typedef enum {DISCOVERY_REQUEST, DISCOVERY_RESPONSE, CREATE_RECORD, DELETE_RECORD, RETRIEVE_RECORD, RESPONSE, IDLE = -1} protocol;

typedef struct {
    short senderGroupId;
    char messageType;
    char requestNumber;
    char senderId;
    char destinationId;
    char messageRecord[20];
    char recordIndex;
    char status;
} message;

typedef struct {
    time_t timeStamp;
    char ownerId;
    char recordMessage[20];
} record;

record database[40];

char neighbours[26];

char nodeId;
short groupId;

int recordCount;
int neighbourCount;

char currentRequestNumber;

protocol currentProtocol;

message * messagePtr;

int sfd = -1;










char * assembleMessage(message * messagePtr) {
    char * p;

    switch(messagePtr->messageType)
    {
    case DISCOVERY_REQUEST:
    case DISCOVERY_RESPONSE:
        p = (char*)((address)__pi_malloc (6));
        break;

    case RETRIEVE_RECORD:
    case DELETE_RECORD:
        p = (char*)((address)__pi_malloc (8));

        p[6] = messagePtr->recordIndex;
        p[7] = 0x00;
        break;

    case CREATE_RECORD:
        p = (char*)((address)__pi_malloc (26));
        __pi_strcpy (p + 6, messagePtr->messageRecord);
        break;

    case RESPONSE:
        p = (char*)((address)__pi_malloc (28));
        p[6] = messagePtr->status;
        p[7] = 0x00;
        __pi_strcpy (p + 8, messagePtr->messageRecord);
        break;
    }

    p[0] = messagePtr->senderGroupId;
    p[2] = messagePtr->messageType;
    p[3] = messagePtr->requestNumber;
    p[4] = messagePtr->senderId;
    p[5] = messagePtr->destinationId;

    return p;
}










int getPacketSize(char messageType) {
    int size = 0;

    switch(messageType)
    {
    case DISCOVERY_REQUEST:
    case DISCOVERY_RESPONSE:
        size = 6;
        break;

    case RETRIEVE_RECORD:
    case DELETE_RECORD:
        size = 8;
        break;

    case CREATE_RECORD:
        size = 26;
        break;

    case RESPONSE:
        size = 28;
        break;
    }

    return size + 4;
}





#define Transmit_Message 0
#define Confirm_Transmission 1
# 143 "app.cc"
void transmitter (word __pi_st) { message * messagePtr = (message *)(__pi_curr->data); switch (__pi_st) { 
# 143 "app.cc"

    case Transmit_Message : __stlab_Transmit_Message: {

        char * assembledMessage = assembleMessage(messagePtr);

        address spkt;


        spkt = tcv_wnps (Transmit_Message, sfd, getPacketSize(messagePtr->messageType), 0);
        spkt [0] = 0;
        char * p = (char*)(spkt + 1);
        __pi_strcpy (p, assembledMessage);

        tcv_endp (spkt);

    } case Confirm_Transmission : __stlab_Confirm_Transmission: {
        kill (0);
break; } default: __pi_badstate (); } }
#undef Transmit_Message
#undef Confirm_Transmission





char randomNumber() {
   time_t t;


   srand((unsigned) time(&t));

   return (char)rand();
}

void resetNeighbours(){
    for (int i = 0; i < 26; i ++) {
        neighbours[i] = 0;
    }
}





#define Initialize 0
#define Send_Discovery_Request 1
#define Wait 2
#define Display_Neighbours 3
#define Display_Neighbour 4
# 186 "app.cc"
void find (word __pi_st) { switch (__pi_st) { 
# 186 "app.cc"

    static int sendCount;
    static int i;

    case Initialize : __stlab_Initialize: {
        i = 0;
        sendCount = 0;
        currentRequestNumber = randomNumber();

        messagePtr -> senderGroupId = groupId;
        messagePtr -> messageType = 0;
        messagePtr -> requestNumber = currentRequestNumber;
        messagePtr -> senderId = nodeId;
        messagePtr -> destinationId = 0;

    } case Send_Discovery_Request : __stlab_Send_Discovery_Request: {
        if(sendCount == 2) {
            proceed (Display_Neighbours);
        }

        do { if (__pi_join (__pi_fork (transmitter, (aword)(messagePtr )), Wait )) __pi_release (); } while (0);
        sendCount++;

    } case Wait : __stlab_Wait: {
        delay(3*1024, Send_Discovery_Request);

    } case Display_Neighbours : __stlab_Display_Neighbours: {
        ser_outf(Display_Neighbours, "Neighbours:");

    } case Display_Neighbour : __stlab_Display_Neighbour: {
        if (neighbours[i] == 1) {
            ser_outf(Display_Neighbour, " %d", i);
        }

        i++;

        if(i < 26) {
            proceed (Display_Neighbour);
        }

        kill (0);

break; } default: __pi_badstate (); } }
#undef Initialize
#undef Send_Discovery_Request
#undef Wait
#undef Display_Neighbours
#undef Display_Neighbour
# 228 "app.cc"











Boolean isValidNodeId(byte node) {
    if (node < 1 || node > 25) {
        return 0;
    }

    return 1;
}


#define Initialize 0
#define Menu_Header 1
#define Options 2
#define Get_Choice 3
#define Set_Group_ID 4
#define Get_Group_ID 5
#define Set_Node_ID 6
#define Get_Node_ID 7
#define Find_Neighbours 8
#define Create_Record 9
#define Get_Receiver_Node 10
#define Get_Message 11
#define Delete_Record 12
#define Retrieve_Record 13
#define Prompt_Recieving_Node 14
#define Get_Receiving_Node 15
#define Prompt_Record_Index 16
#define Get_Record_Index 17
#define Transmit_Message 18
# 247 "app.cc"
void root (word __pi_st) { switch (__pi_st) { 
# 247 "app.cc"


    static char *menu="(G)roup ID\r\n""(N)ew device ID\r\n""(F)ind neighbors\r\n""(C)reate record on neighbor\r\n""(D)elete record on neighbor\r\n""(R)etrieve record from neighbor\r\n""(S)how local records\r\n""R(e)set local storage\r\n\r\n""Selection: ";









    static char receiverId;

    case Initialize : __stlab_Initialize: {
        recordCount = 0;

        nodeId = 1;
        groupId = 1;

        messagePtr = (message *) ((address)__pi_malloc (sizeof(message)));


        phys_cc1350(0, 250);


        tcv_plug(0, &plug_null);


        sfd = tcv_open(((word)(-1)), 0, 0);
  tcv_control(sfd, 4, 
# 277 "app.cc"
                              ((void *)0)
# 277 "app.cc"
                                  );


  if (sfd < 0) {
   diag("Cannot open tcv interface");
   halt();
  }

    } case Menu_Header : __stlab_Menu_Header: {
        currentProtocol = IDLE;
        ser_outf(Menu_Header, "\r\nGroup %d Device #%d (%d/%d records)\r\n", groupId, nodeId, recordCount, 40);

    } case Options : __stlab_Options: {
        ser_outf(Options, menu);

    } case Get_Choice : __stlab_Get_Choice: {
        char choice;

        ser_inf(Get_Choice, "%c", &choice);

        switch (choice)
        {
        case 'g':
        case 'G':
            proceed (Set_Group_ID);
            break;

        case 'n':
        case 'N':
            proceed (Set_Node_ID);
            break;

        case 'f':
        case 'F':
            proceed (Find_Neighbours);
            break;

        case 'c':
        case 'C':
            proceed (Create_Record);
            break;

        case 'd':
        case 'D':
            proceed (Delete_Record);
            break;

        case 'r':
        case 'R':
            proceed (Retrieve_Record);
            break;

        case 's':
        case 'S':
            diag("Show Local Records");
            break;

        case 'e':
        case 'E':
            diag("Reset Local Storage");
            break;

        }

        proceed (Menu_Header);


    } case Set_Group_ID : __stlab_Set_Group_ID: {
        ser_outf(Set_Group_ID, "New Group ID: ");
    } case Get_Group_ID : __stlab_Get_Group_ID: {
        ser_inf(Get_Group_ID, "%d", &groupId);

        proceed (Menu_Header);


    } case Set_Node_ID : __stlab_Set_Node_ID: {
        ser_outf(Set_Node_ID, "New node ID (1-25):");

    } case Get_Node_ID : __stlab_Get_Node_ID: {
        ser_inf(Get_Node_ID, "%d", &nodeId);

        if (!isValidNodeId(nodeId)) {
            proceed (Set_Node_ID);
        }

        proceed (Menu_Header);


    } case Find_Neighbours : __stlab_Find_Neighbours: {
        do { if (__pi_join (__pi_fork (find, (aword)(0)), Menu_Header )) __pi_release (); } while (0);





    } case Create_Record : __stlab_Create_Record: {
        currentProtocol = CREATE_RECORD;
        ser_outf(Create_Record, "Receiver node ID (1-25):");

    } case Get_Receiver_Node : __stlab_Get_Receiver_Node: {
        ser_inf(Get_Receiver_Node, "%d", &receiverId);

        if(!isValidNodeId(receiverId)) {
            proceed (Create_Record);
        }

    } case Get_Message : __stlab_Get_Message: {
        ser_in(Get_Message, messagePtr->messageRecord, 20);

        if(__pi_strlen (messagePtr->messageRecord) >= 20) {

            messagePtr->messageRecord[20 - 1] = '/0';
        }

        proceed (Transmit_Message);



    } case Delete_Record : __stlab_Delete_Record: {
        currentProtocol = DELETE_RECORD;
        ser_outf(Retrieve_Record, "Delete Record from Neighbour:\n\r");
        proceed (Get_Receiving_Node);

    } case Retrieve_Record : __stlab_Retrieve_Record: {
        currentProtocol = RETRIEVE_RECORD;
        ser_outf(Retrieve_Record, "Retrieve Record from Neighbour:\n\r");

    } case Prompt_Recieving_Node : __stlab_Prompt_Recieving_Node: {
        ser_outf(Prompt_Recieving_Node, "Neighbour node ID (1-25):");

    } case Get_Receiving_Node : __stlab_Get_Receiving_Node: {
        ser_inf(Get_Receiving_Node, "%d", &receiverId);

        if(!isValidNodeId(receiverId)) {
            proceed (Prompt_Recieving_Node);
        }

    } case Prompt_Record_Index : __stlab_Prompt_Record_Index: {
        ser_outf(Prompt_Record_Index, "Record index:");

    } case Get_Record_Index : __stlab_Get_Record_Index: {
        char desiredRecordIndex = -1;
        ser_inf(Get_Record_Index, "%d", &desiredRecordIndex);
        messagePtr->recordIndex = desiredRecordIndex;

        proceed (Transmit_Message);


    } case Transmit_Message : __stlab_Transmit_Message: {
        messagePtr -> senderGroupId = groupId;
        messagePtr -> messageType = currentProtocol;
        messagePtr -> requestNumber = randomNumber();
        messagePtr -> senderId = nodeId;
        messagePtr -> destinationId = receiverId;

        do { if (__pi_join (__pi_fork (transmitter, (aword)(messagePtr )), Menu_Header )) __pi_release (); } while (0);
break; } default: __pi_badstate (); } }
#undef Initialize
#undef Menu_Header
#undef Options
#undef Get_Choice
#undef Set_Group_ID
#undef Get_Group_ID
#undef Set_Node_ID
#undef Get_Node_ID
#undef Find_Neighbours
#undef Create_Record
#undef Get_Receiver_Node
#undef Get_Message
#undef Delete_Record
#undef Retrieve_Record
#undef Prompt_Recieving_Node
#undef Get_Receiving_Node
#undef Prompt_Record_Index
#undef Get_Record_Index
#undef Transmit_Message
# 433 "app.cc"

