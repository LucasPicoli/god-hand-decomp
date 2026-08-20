/* ee-2.9-991111 matched TU. */

extern float __ieee754_asinf(float);

struct exception {
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

extern int func_003A4AC8(struct exception *);	/* matherr */
extern int func_003A4E00(float);		/* isnanf  */
extern int func_003A4CF0(float);		/* finitef */
extern float func_003A19D8(float);		/* fabsf   */


extern char D_0045EA68[];		/* "asinf" */

__attribute__((section(".text.func_003A1B78")))
float func_003A1B78(float x)		/* asinf */
{
	float z;
	struct exception exc;
	z = __ieee754_asinf(x);
	if(_LIB_VERSION == _IEEE_ || func_003A4E00(x)) return z;
	if(func_003A19D8(x)>(float)1.0) {
	    /* asinf(|x|>1) */
	    exc.type = DOMAIN;
	    exc.name = D_0045EA68;
	    exc.err = 0;
	    exc.arg1 = exc.arg2 = (double)x;
	    exc.retval = 0.0;
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
