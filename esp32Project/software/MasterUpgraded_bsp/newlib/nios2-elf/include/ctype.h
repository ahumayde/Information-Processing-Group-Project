#ifndef _CTYPE_H_
#define _CTYPE_H_

#include "_ansi.h"
#include <sys/cdefs.h>

#if __POSIX_VISIBLE >= 200809 || __MISC_VISIBLE || defined (_COMPILING_NEWLIB)
#include <sys/_locale.h>
#endif

_BEGIN_STD_C

  /* Indicate that we honor AEABI portability if requested.  */
#if defined _AEABI_PORTABILITY_LEVEL && _AEABI_PORTABILITY_LEVEL != 0 && !defined _AEABI_PORTABLE
# define _AEABI_PORTABLE
#endif

#if defined _AEABI_PORTABLE
extern unsigned char const __aebi_ctype_table_C[257];
extern unsigned char const __aebi_ctype_table_[257];

# ifdef _AEABI_LC_CTYPE
#  define _AEABI_CTYPE_TABLE(_X) __aebi_ctype_table_ ## _X
#  define _AEABI_CTYPE(_X) _AEABI_CTYPE_TABLE(_X)
#  define __aeabi_ctype_table _AEABI_CTYPE (_AEABI_LC_CTYPE)
# else
#  define __aeabi_ctype_table __aeabi_ctype_table_
# endif /* _AEABI_LC_CTYPE */

#define _AEABI_A	1	/* Alphabetic.  */
#define _AEABI_X	2	/* A-F a-f 0-9. */
#define _AEABI_P	4	/* Punctuation.  */
#define _AEABI_B	8	/* Printable blank.  */
#define _AEABI_S	16	/* Whitespace.  */
#define _AEABI_L	32	/* Lower case letter.  */
#define _AEABI_U	64	/* Upper case letter.  */
#define _AEABI_C	128	/* Control chars.  */

#define isspace(x)	((__aeabi_ctype_table+1)[x] & _AEABI_S)
#define isalpha(x)	((__aeabi_ctype_table+1)[x] & _AEABI_A)
#define isalnum(x)	((__aeabi_ctype_table+1)[x] << 30)
#define isprint(x)	((__aeabi_ctype_table+1)[x] << 28)
#define isupper(x)	((__aeabi_ctype_table+1)[x] & _AEABI_U)
#define islower(x)	((__aeabi_ctype_table+1)[x] & _AEABI_L)
#define isxdigit(x)	((__aeabi_ctype_table+1)[x] & _AEABI_X)
/* isblank */
#define isgraph(x)	((__aeabi_ctype_table+1)[x] << 29)
#define iscntrl(x)	((__aeabi_ctype_table+1)[x] & _AEABI_C)
#define ispunct(x)	((__aeabi_ctype_table+1)[x] & _AEABI_P)

#else

int isalnum (int __c);
int isalpha (int __c);
int iscntrl (int __c);
int isdigit (int __c);
int isgraph (int __c);
int islower (int __c);
int isprint (int __c);
int ispunct (int __c);
int isspace (int __c);
int isupper (int __c);
int isxdigit (int __c);
int tolower (int __c);
int toupper (int __c);

#if __ISO_C_VISIBLE >= 1999
int isblank (int __c);
#endif

#if __MISC_VISIBLE || __XSI_VISIBLE
int isascii (int __c);
int toascii (int __c);
#endif

#if __ISO_C_VISIBLE >= 1999 && !defined _AEABI_PORTABLE
extern int isblank (int __c);
#endif

#if (__MISC_VISIBLE || __XSI_VISIBLE) && !defined _AEABI_PORTABLE
int isascii (int __c);
int toascii (int __c);
#define _tolower(__c) ((unsigned char)(__c) - 'A' + 'a')
#define _toupper(__c) ((unsigned char)(__c) - 'a' + 'A')
#endif

#if __POSIX_VISIBLE >= 200809
extern int isalnum_l (int __c, locale_t __l);
extern int isalpha_l (int __c, locale_t __l);
extern int isblank_l (int __c, locale_t __l);
extern int iscntrl_l (int __c, locale_t __l);
extern int isdigit_l (int __c, locale_t __l);
extern int isgraph_l (int __c, locale_t __l);
extern int islower_l (int __c, locale_t __l);
extern int isprint_l (int __c, locale_t __l);
extern int ispunct_l (int __c, locale_t __l);
extern int isspace_l (int __c, locale_t __l);
extern int isupper_l (int __c, locale_t __l);
extern int isxdigit_l(int __c, locale_t __l);
extern int tolower_l (int __c, locale_t __l);
extern int toupper_l (int __c, locale_t __l);
#endif

#if __MISC_VISIBLE
extern int isascii_l (int __c, locale_t __l);
extern int toascii_l (int __c, locale_t __l);
#endif

#define	_U	01
#define	_L	02
#define	_N	04
#define	_S	010
#define _P	020
#define _C	040
#define _X	0100
#define	_B	0200

#ifdef __HAVE_LOCALE_INFO__
const char *__locale_ctype_ptr (void);
#else
#define __locale_ctype_ptr()	_ctype_
#endif

# define __CTYPE_PTR	(__locale_ctype_ptr ())

#ifndef __cplusplus
/* These macros are intentionally written in a manner that will trigger
   a gcc -Wall warning if the user mistakenly passes a 'char' instead
   of an int containing an 'unsigned char'.  Note that the sizeof will
   always be 1, which is what we want for mapping EOF to __CTYPE_PTR[0];
   the use of a raw index inside the sizeof triggers the gcc warning if
   __c was of type char, and sizeof masks side effects of the extra __c.
   Meanwhile, the real index to __CTYPE_PTR+1 must be cast to int,
   since isalpha(0x100000001LL) must equal isalpha(1), rather than being
   an out-of-bounds reference on a 64-bit machine.  */
#define __ctype_lookup(__c) ((__CTYPE_PTR+sizeof(""[__c]))[(int)(__c)])

#define	isalpha(__c)	(__ctype_lookup(__c)&(_U|_L))
#define	isupper(__c)	((__ctype_lookup(__c)&(_U|_L))==_U)
#define	islower(__c)	((__ctype_lookup(__c)&(_U|_L))==_L)
#define	isdigit(__c)	(__ctype_lookup(__c)&_N)
#define	isxdigit(__c)	(__ctype_lookup(__c)&(_X|_N))
#define	isspace(__c)	(__ctype_lookup(__c)&_S)
#define ispunct(__c)	(__ctype_lookup(__c)&_P)
#define isalnum(__c)	(__ctype_lookup(__c)&(_U|_L|_N))
#define isprint(__c)	(__ctype_lookup(__c)&(_P|_U|_L|_N|_B))
#define	isgraph(__c)	(__ctype_lookup(__c)&(_P|_U|_L|_N))
#define iscntrl(__c)	(__ctype_lookup(__c)&_C)

#if defined(__GNUC__) && __ISO_C_VISIBLE >= 1999
#define isblank(__c) \
  __extension__ ({ __typeof__ (__c) __x = (__c);		\
        (__ctype_lookup(__x)&_B) || (int) (__x) == '\t';})
#endif

#if __POSIX_VISIBLE >= 200809
#ifdef __HAVE_LOCALE_INFO__
const char *__locale_ctype_ptr_l (locale_t);
#else
#define __locale_ctype_ptr_l(l)	_ctype_
#endif
#define __ctype_lookup_l(__c,__l) ((__locale_ctype_ptr_l(__l)+sizeof(""[__c]))[(int)(__c)])

#define	isalpha_l(__c,__l)	(__ctype_lookup_l(__c,__l)&(_U|_L))
#define	isupper_l(__c,__l)	((__ctype_lookup_l(__c,__l)&(_U|_L))==_U)
#define	islower_l(__c,__l)	((__ctype_lookup_l(__c,__l)&(_U|_L))==_L)
#define	isdigit_l(__c,__l)	(__ctype_lookup_l(__c,__l)&_N)
#define	isxdigit_l(__c,__l)	(__ctype_lookup_l(__c,__l)&(_X|_N))
#define	isspace_l(__c,__l)	(__ctype_lookup_l(__c,__l)&_S)
#define ispunct_l(__c,__l)	(__ctype_lookup_l(__c,__l)&_P)
#define isalnum_l(__c,__l)	(__ctype_lookup_l(__c,__l)&(_U|_L|_N))
#define isprint_l(__c,__l)	(__ctype_lookup_l(__c,__l)&(_P|_U|_L|_N|_B))
#define	isgraph_l(__c,__l)	(__ctype_lookup_l(__c,__l)&(_P|_U|_L|_N))
#define iscntrl_l(__c,__l)	(__ctype_lookup_l(__c,__l)&_C)

#if defined(__GNUC__)
#define isblank_l(__c, __l) \
  __extension__ ({ __typeof__ (__c) __x = (__c);		\
        (__ctype_lookup_l(__x,__l)&_B) || (int) (__x) == '\t';})
#endif

#endif /* __POSIX_VISIBLE >= 200809 */

#if (__MISC_VISIBLE || __XSI_VISIBLE) && !defined _AEABI_PORTABLE
#define isascii(__c)	((unsigned)(__c)<=0177)
#define toascii(__c)	((__c)&0177)
#endif

#if __MISC_VISIBLE && !defined _AEABI_PORTABLE
#define isascii_l(__c,__l)	((__l),(unsigned)(__c)<=0177)
#define toascii_l(__c,__l)	((__l),(__c)&0177)
#endif

/* Non-gcc versions will get the library versions, and will be
   slightly slower.  These macros are not NLS-aware so they are
   disabled if the system supports the extended character sets. */
# if defined(__GNUC__)
#  if !defined (_MB_EXTENDED_CHARSETS_ISO) && !defined (_MB_EXTENDED_CHARSETS_WINDOWS)
#   define toupper(__c) \
  __extension__ ({ __typeof__ (__c) __x = (__c);	\
      islower (__x) ? (int) __x - 'a' + 'A' : (int) __x;})
#   define tolower(__c) \
  __extension__ ({ __typeof__ (__c) __x = (__c);	\
      isupper (__x) ? (int) __x - 'A' + 'a' : (int) __x;})
#  else /* _MB_EXTENDED_CHARSETS* */
/* Allow a gcc warning if the user passed 'char', but defer to the
   function.  */
#   define toupper(__c) \
  __extension__ ({ __typeof__ (__c) __x = (__c);	\
      (void) __CTYPE_PTR[__x]; (toupper) (__x);})
#   define tolower(__c) \
  __extension__ ({ __typeof__ (__c) __x = (__c);	\
      (void) __CTYPE_PTR[__x]; (tolower) (__x);})
#  endif /* _MB_EXTENDED_CHARSETS* */
# endif /* __GNUC__ */

#if __POSIX_VISIBLE >= 200809
#endif /* __POSIX_VISIBLE >= 200809 */

#endif /* !__cplusplus */

#endif /* _AEABI_PORTABLE */

/* For C++ backward-compatibility only.  */
extern	__IMPORT const char	_ctype_[];

_END_STD_C

#endif /* _CTYPE_H_ */
