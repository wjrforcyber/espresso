/*
 * Revision Control Information
 *
 * $Source: /vol/opua/opua2/sis/sis-1.2/common/src/utility/RCS/utility.h,v $
 * $Author: sis $
 * $Revision: 1.4 $
 * $Date: 1994/07/15 22:55:23 $
 *
 */
#ifndef UTILITY_H
#define UTILITY_H

/*
 *  assumes the memory manager is libmm.a
 *	- allows malloc(0) or realloc(obj, 0)
 *	- catches out of memory (and calls MMout_of_memory())
 *	- catch free(0) and realloc(0, size) in the macros
 */
#define NIL(type)		((type *) 0)
#define ALLOC(type, num)	\
    ((type *) malloc(sizeof(type) * (num)))
#define REALLOC(type, obj, num)	\
    (obj) ? ((type *) realloc((char *) obj, sizeof(type) * (num))) : \
	    ((type *) malloc(sizeof(type) * (num)))
#define FREE(obj)		\
    if ((obj)) { (void) free((char *) (obj)); (obj) = 0; }

#include "ansi.h"
#include <stdio.h>

EXTERN long  util_cpu_time
	NULLARGS;
EXTERN char *util_path_search
	ARGS((char *));
EXTERN char *util_file_search
	ARGS((char *, char *, char *));
EXTERN int   util_pipefork
	ARGS((char **, FILE **, FILE **, int *));
EXTERN int   util_csystem
	ARGS((char *));
EXTERN char *util_print_time
	ARGS((long));
EXTERN char *util_strsav
	ARGS((char *));
EXTERN char *util_tilde_expand
	ARGS((char *));
EXTERN char *util_tilde_compress
	ARGS((char *));
EXTERN void util_register_user
	ARGS((char *, char *));

#ifndef NIL_FN
#define NIL_FN(type) ((type (*)()) 0)
#endif /* NIL_FN */

#ifndef MAX
#define MAX(a,b)	((a) > (b) ? (a) : (b))
#endif /* MAX */
#ifndef MIN
#define MIN(a,b)	((a) < (b) ? (a) : (b))
#endif /* MIN */
#ifndef ABS
#define ABS(a)		((a) > 0 ? (a) : -(a))
#endif /* ABS */


#ifdef lint
#undef ALLOC			/* allow for lint -h flag */
#undef REALLOC
#define ALLOC(type, num)	(((type *) 0) + (num))
#define REALLOC(type, obj, num)	((obj) + (num))
#endif /* lint */

#endif

