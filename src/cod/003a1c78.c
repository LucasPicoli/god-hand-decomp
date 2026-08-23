/* LANE X1 repair, wave 18.
 * CAUSE 1: the merged TU holds three fdlibm wrappers that each define
 *          `struct exception`, which is a REDEFINITION and gives cc1 exit 33.
 * REPAIR 1: the tag carries a per-function suffix. No byte changes.
 * CAUSE 2: the literal FLT_MAX-as-double emits a TU-local .rodata copy;
 *          retail reads it from D_0045EA80 inside the split rodata blob.
 * REPAIR 2: LANDING KEY extern_double: ["D_0045EA80"]. The C is unchanged. */
/* newlib fdlibm wf_exp.c -- expf */

struct exc_3A1C78 {
	int type;
	char *name;
	double arg1;
	double arg2;
	double retval;
	int err;
};

extern float func_003A28F8(float x);			/* __ieee754_expf */
extern int func_003A4CF0(float x);			/* finitef */
extern int func_003A4AC8(void *e);		/* matherr */
extern int *Obj0000_Get_D_003FA62C_3A4FB8(void);	/* __errno */
extern const int D_0045F024;				/* _LIB_VERSION */
extern char D_0045EA78[];				/* "expf" */
extern const double D_0045EA00;				/* HUGE_VAL */

__attribute__((section(".text.func_003A1C78")))
float func_003A1C78(float x)
{
	struct exc_3A1C78 exc;
	float z;

	z = func_003A28F8(x);
	if (D_0045F024 == -1)
		return z;
	if (func_003A4CF0(x)) {
		if (x > 88.7216796875f) {
			exc.type = 3;
			exc.name = D_0045EA78;
			exc.err = 0;
			exc.arg1 = exc.arg2 = (double)x;
			if (D_0045F024 == 0)
				exc.retval = 3.4028234663852886e+38;
			else
				exc.retval = D_0045EA00;
			if (D_0045F024 == 2)
				*Obj0000_Get_D_003FA62C_3A4FB8() = 34;
			else if (func_003A4AC8(&exc) == 0)
				*Obj0000_Get_D_003FA62C_3A4FB8() = 34;
			if (exc.err != 0)
				*Obj0000_Get_D_003FA62C_3A4FB8() = exc.err;
			return (float)exc.retval;
		} else if (x < -103.97208404541016f) {
			exc.type = 4;
			exc.name = D_0045EA78;
			exc.err = 0;
			exc.arg1 = exc.arg2 = (double)x;
			exc.retval = 0.0;
			if (D_0045F024 == 2)
				*Obj0000_Get_D_003FA62C_3A4FB8() = 34;
			else if (func_003A4AC8(&exc) == 0)
				*Obj0000_Get_D_003FA62C_3A4FB8() = 34;
			if (exc.err != 0)
				*Obj0000_Get_D_003FA62C_3A4FB8() = exc.err;
			return (float)exc.retval;
		}
	}
	return z;
}
