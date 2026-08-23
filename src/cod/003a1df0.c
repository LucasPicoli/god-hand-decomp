/* LANE X1 repair, wave 18.
 * CAUSE 1: the merged TU holds three fdlibm wrappers that each define
 *          `struct exception`, which is a REDEFINITION and gives cc1 exit 33.
 * REPAIR 1: the tag carries a per-function suffix. No byte changes.
 * CAUSE 2: the literal -FLT_MAX-as-double emits a TU-local .rodata copy;
 *          retail reads it from D_0045EA90 inside the split rodata blob.
 * REPAIR 2: LANDING KEY extern_double: ["D_0045EA90"]. The C is unchanged. */
/* newlib fdlibm wf_log.c -- logf */

struct exc_3A1DF0 {
	int type;
	char *name;
	double arg1;
	double arg2;
	double retval;
	int err;
};

extern float func_003A2BB0(float x);			/* __ieee754_logf */
extern int func_003A4E00(float x);			/* isnanf */
extern int func_003A4AC8(void *e);		/* matherr */
extern int *Obj0000_Get_D_003FA62C_3A4FB8(void);	/* __errno */
extern const int D_0045F024;				/* _LIB_VERSION */
extern char D_0045EA88[];				/* "logf" */
extern const double D_0045EA90;				/* -HUGE */
extern const double D_0045EA00;				/* HUGE_VAL */

__attribute__((section(".text.func_003A1DF0")))
float func_003A1DF0(float x)
{
	struct exc_3A1DF0 exc;
	float z;

	z = func_003A2BB0(x);
	if (D_0045F024 == -1 || func_003A4E00(x) || x > (float)0.0)
		return z;
	exc.name = D_0045EA88;
	exc.err = 0;
	exc.arg1 = exc.arg2 = (double)x;
	if (D_0045F024 == 0)
		exc.retval = -3.4028234663852886e+38;
	else
		exc.retval = -D_0045EA00;
	if (x == (float)0.0) {
		exc.type = 2;
		if (D_0045F024 == 2)
			*Obj0000_Get_D_003FA62C_3A4FB8() = 34;
		else if (func_003A4AC8(&exc) == 0)
			*Obj0000_Get_D_003FA62C_3A4FB8() = 33;
	} else {
		exc.type = 1;
		if (D_0045F024 == 2)
			*Obj0000_Get_D_003FA62C_3A4FB8() = 33;
		else if (func_003A4AC8(&exc) == 0)
			*Obj0000_Get_D_003FA62C_3A4FB8() = 33;
	}
	if (exc.err != 0)
		*Obj0000_Get_D_003FA62C_3A4FB8() = exc.err;
	return (float)exc.retval;
}
