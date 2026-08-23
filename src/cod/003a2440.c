/* ee-2.9-991111 matched TU. */

/* LANE X1 repair, wave 18.
 * CAUSE 1: the merged TU holds three fdlibm wrappers that each define
 *          `struct exception`, which is a REDEFINITION and gives cc1 exit 33.
 * REPAIR 1: the tag carries a per-function suffix. No byte changes.
 * sqrtf emits no .rodata; the tag rename is its whole repair. */
/* ee-2.9-991111 matched TU. */

extern float func_003A3B48(float);		/* __ieee754_sqrtf */

struct exc_sqrtf {
	int type;
	char *name;
	double arg1;
	double arg2;
	double retval;
	int err;
};

#define DOMAIN		1
#define SING		2
#define OVERFLOW	3
#define UNDERFLOW	4
#define TLOSS		5
#define PLOSS		6

#define _IEEE_	(-1)
#define _SVID_	0
#define _XOPEN_	1
#define _POSIX_	2

#define EDOM	33
#define ERANGE	34

extern const int D_0045F024;		/* _LIB_VERSION */
#define _LIB_VERSION D_0045F024

extern int *Obj0000_Get_D_003FA62C_3A4FB8(void);	/* __errno */
#define errno (*Obj0000_Get_D_003FA62C_3A4FB8())

extern int func_003A4AC8(void *e);	/* matherr */
extern int func_003A4E00(float);		/* isnanf  */

extern char D_0045EAB8[];		/* "sqrtf" */
extern const double D_0045EAC0;		/* nan */

__attribute__((section(".text.sqrtf")))
float sqrtf(float x)			/* wrapper sqrtf */
{
	float z;
	struct exc_sqrtf exc;
	z = func_003A3B48(x);
	if(_LIB_VERSION == _IEEE_ || func_003A4E00(x)) return z;
	if(x<(float)0.0) {
	    /* sqrtf(negative) */
	    exc.type = DOMAIN;
	    exc.name = D_0045EAB8;
	    exc.err = 0;
	    exc.arg1 = exc.arg2 = (double)x;
	    if (_LIB_VERSION == _SVID_)
	        exc.retval = 0.0;
	    else
	        exc.retval = D_0045EAC0;
	    if(_LIB_VERSION == _POSIX_)
	      errno = EDOM;
	    else if (!func_003A4AC8(&exc)) {
	      errno = EDOM;
	    }
	    if (exc.err != 0)
	      errno = exc.err;
	    return (float)exc.retval;
	} else
	    return z;
}
