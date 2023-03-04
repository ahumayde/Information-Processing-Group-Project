/*
	locale.h
	Values appropriate for the formatting of monetary and other
	numberic quantities.
*/

#ifndef _LOCALE_H_
#define _LOCALE_H_

#include "_ansi.h"
#include <sys/cdefs.h>
#include <sys/_locale.h>

  /* Indicate that we honor AEABI portability if requested.  */
#if defined _AEABI_PORTABILITY_LEVEL && _AEABI_PORTABILITY_LEVEL != 0 && !defined _AEABI_PORTABLE
# define _AEABI_PORTABLE
#endif

#define __need_NULL
#include <stddef.h>

_BEGIN_STD_C

#ifdef _AEABI_PORTABLE

extern const int __aeabi_LC_COLLATE;
extern const int __aeabi_LC_CTYPE;
extern const int __aeabi_LC_MONETARY;
extern const int __aeabi_LC_NUMERIC;
extern const int __aeabi_LC_TIME;
extern const int __aeabi_LC_ALL;

#define LC_COLLATE (__aeabi_LC_COLLATE)
#define LC_CTYPE (__aeabi_LC_CTYPE)
#define LC_MONETARY (__aeabi_LC_MONETARY)
#define LC_NUMERIC (__aeabi_LC_NUMERIC)
#define LC_TIME (__aeabi_LC_TIME)
#define LC_ALL (__aeabi_LC_ALL)

struct __aeabi_lconv {
  char *decimal_point;
  char *thousands_sep;
  char *grouping;
  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;
  char *mon_grouping;
  char *positive_sign;
  char *negative_sign;
  char int_frac_digits;
  char frac_digits;
  char p_cs_precedes;
  char p_sep_by_space;
  char n_cs_precedes;
  char n_sep_by_space;
  char p_sign_posn;
  char n_sign_posn;

  /* The following fields are added by C99.  */
  char int_p_cs_precedes;
  char int_n_cs_precedes;
  char int_p_sep_by_space;
  char int_n_sep_by_space;
  char int_p_sign_posn;
  char int_n_sign_posn;
};
#else

#define LC_ALL	    0
#define LC_COLLATE  1
#define LC_CTYPE    2
#define LC_MONETARY 3
#define LC_NUMERIC  4
#define LC_TIME     5
#define LC_MESSAGES 6

#if __POSIX_VISIBLE >= 200809 || defined (_COMPILING_NEWLIB)

#include <sys/_locale.h>

#define LC_ALL_MASK		(1 << LC_ALL)
#define LC_COLLATE_MASK		(1 << LC_COLLATE)
#define LC_CTYPE_MASK		(1 << LC_CTYPE)
#define LC_MONETARY_MASK	(1 << LC_MONETARY)
#define LC_NUMERIC_MASK		(1 << LC_NUMERIC)
#define LC_TIME_MASK		(1 << LC_TIME)
#define LC_MESSAGES_MASK	(1 << LC_MESSAGES)

#define LC_GLOBAL_LOCALE	((struct __locale_t *) -1)

#endif /* __POSIX_VISIBLE >= 200809 */

struct lconv
{
  char *decimal_point;
  char *thousands_sep;
  char *grouping;
  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;
  char *mon_grouping;
  char *positive_sign;
  char *negative_sign;
  char int_frac_digits;
  char frac_digits;
  char p_cs_precedes;
  char p_sep_by_space;
  char n_cs_precedes;
  char n_sep_by_space;
  char p_sign_posn;
  char n_sign_posn;
  char int_n_cs_precedes;
  char int_n_sep_by_space;
  char int_n_sign_posn;
  char int_p_cs_precedes;
  char int_p_sep_by_space;
  char int_p_sign_posn;
};
#endif /* _AEABI_PORTABLE */

struct _reent;
char *_setlocale_r (struct _reent *, int, const char *);
struct lconv *_localeconv_r (struct _reent *);

struct __locale_t *_newlocale_r (struct _reent *, int, const char *,
				 struct __locale_t *);
void _freelocale_r (struct _reent *, struct __locale_t *);
struct __locale_t *_duplocale_r (struct _reent *, struct __locale_t *);
struct __locale_t *_uselocale_r (struct _reent *, struct __locale_t *);

#ifndef _REENT_ONLY

char *setlocale (int, const char *);
# ifdef _AEABI_PORTABLE
struct __aeabi_lconv *__aeabi_localeconv (void);
# else
struct lconv *localeconv (void);
# endif

#if __POSIX_VISIBLE >= 200809
locale_t newlocale (int, const char *, locale_t);
void freelocale (locale_t);
locale_t duplocale (locale_t);
locale_t uselocale (locale_t);
#endif /* __POSIX_VISIBLE >= 200809 */

#endif /* _REENT_ONLY */

_END_STD_C

#endif /* _LOCALE_H_ */
