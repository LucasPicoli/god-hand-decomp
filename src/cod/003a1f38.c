/* ee-2.9-991111 matched TU. */

/* MATCH (exact), 1288 B.  Wave 23 lane G, 2026-09-07.
 * newlib libm wf_pow.c -- powf.  Donor: sce_crt_libm/wf_pow.o.
 *
 *   compiler:         ee-2.9-991111
 *   assembler:        ee (default)
 *   fp_hazard_rules:  "libm-mtc1"
 *
 *   python3 .private/scripts/score_candidate.py func_003A1F38 <this file> \
 *           --compiler ee-2.9-991111 --fp-hazard-rules libm-mtc1
 *   -> MATCH (exact)
 *
 * TWO changes from worker D3's parked body.
 *  1. The wrapper.  `_libm_compare_slot_is_empty` now reads the slot state
 *     ee-as produces, so `libm`'s empty-slot half fires at retail insn 62
 *     (0x003A202C) where retail leaves the compare unpadded, and still keeps
 *     the pad at insn 64 where the slot holds work.  One body, both shapes.
 *     That alone took 97.8% / +1 word to LENGTH EXACT, 99.7%, IMM 1.
 *  2. The SOURCE.  The last word was a branch target one insn late.  Upstream
 *     newlib writes ONE test -- `if (_LIB_VERSION == _IEEE_ || isnanf(y))
 *     return z;` -- and D3's body split it into two `if`s with two `return z;`
 *     statements.  Two exit sites let gcc thread the first branch past the
 *     `mov.s $f0,$f21` at 0x003A2410; one `||` and one `return z;` do not.
 * `libm` and `libm-mtc1` both match here: the object has no FTOI->mfc1 pair.
 */
struct exception {
	int type;
	char *name;
	double arg1;
	double arg2;
	double retval;
	int err;
};

extern float func_003A2ED8(float x, float y);		/* __ieee754_powf */
extern int func_003A4E00(float x);			/* isnanf */
extern int func_003A4CF0(float x);			/* finitef */
extern double func_003A4AF0(double x);			/* rint */
extern int func_003A4AC8(struct exception *e);		/* matherr */
extern int *Obj0000_Get_D_003FA62C_3A4FB8(void);	/* __errno */
extern const int D_0045F024;				/* _LIB_VERSION */
extern char D_0045EA98[];				/* "powf" */
extern const double D_0045EA00;				/* HUGE_VAL */
extern const double D_0045EAA0;				/* NaN */

__attribute__((section(".text.func_003A1F38")))
float func_003A1F38(float x, float y)
{
	float z;
	struct exception exc;

	z = func_003A2ED8(x, y);
	if (D_0045F024 == -1 || func_003A4E00(y))
		return z;
	if (func_003A4E00(x)) {
		if (y == (float)0.0) {
			exc.type = 1;
			exc.name = D_0045EA98;
			exc.err = 0;
			exc.arg1 = (double)x;
			exc.arg2 = (double)y;
			exc.retval = (double)x;
			if (D_0045F024 == 2)
				exc.retval = 1.0;
			else if (func_003A4AC8(&exc) == 0)
				*Obj0000_Get_D_003FA62C_3A4FB8() = 33;
			if (exc.err != 0)
				*Obj0000_Get_D_003FA62C_3A4FB8() = exc.err;
			return (float)exc.retval;
		} else
			return z;
	}
	if (x == (float)0.0) {
		if (y == (float)0.0) {
			exc.type = 1;
			exc.name = D_0045EA98;
			exc.err = 0;
			exc.arg1 = (double)x;
			exc.arg2 = (double)y;
			exc.retval = 0.0;
			if (D_0045F024 != 0)
				exc.retval = 1.0;
			else if (func_003A4AC8(&exc) == 0)
				*Obj0000_Get_D_003FA62C_3A4FB8() = 33;
			if (exc.err != 0)
				*Obj0000_Get_D_003FA62C_3A4FB8() = exc.err;
			return (float)exc.retval;
		}
		if (func_003A4CF0(y) && y < (float)0.0) {
			exc.type = 1;
			exc.name = D_0045EA98;
			exc.err = 0;
			exc.arg1 = (double)x;
			exc.arg2 = (double)y;
			if (D_0045F024 == 0)
				exc.retval = 0.0;
			else
				exc.retval = -D_0045EA00;
			if (D_0045F024 == 2)
				*Obj0000_Get_D_003FA62C_3A4FB8() = 33;
			else if (func_003A4AC8(&exc) == 0)
				*Obj0000_Get_D_003FA62C_3A4FB8() = 33;
			if (exc.err != 0)
				*Obj0000_Get_D_003FA62C_3A4FB8() = exc.err;
			return (float)exc.retval;
		}
		return z;
	}
	if (func_003A4CF0(z) == 0) {
		if (func_003A4CF0(x) && func_003A4CF0(y)) {
			if (func_003A4E00(z)) {
				exc.type = 1;
				exc.name = D_0045EA98;
				exc.err = 0;
				exc.arg1 = (double)x;
				exc.arg2 = (double)y;
				if (D_0045F024 == 0)
					exc.retval = 0.0;
				else
					exc.retval = D_0045EAA0;
				if (D_0045F024 == 2 || func_003A4AC8(&exc) == 0)
					*Obj0000_Get_D_003FA62C_3A4FB8() = 33;
			} else {
				exc.type = 3;
				exc.name = D_0045EA98;
				exc.err = 0;
				exc.arg1 = (double)x;
				exc.arg2 = (double)y;
				if (D_0045F024 == 0) {
					exc.retval = 3.4028234663852886e+38;
					y = y * 0.5;
					if (x < 0.0 && func_003A4AF0(y) != y)
						exc.retval = -3.4028234663852886e+38;
				} else {
					exc.retval = D_0045EA00;
					y = y * 0.5;
					if (x < 0.0 && func_003A4AF0(y) != y)
						exc.retval = -D_0045EA00;
				}
				if (D_0045F024 == 2)
					*Obj0000_Get_D_003FA62C_3A4FB8() = 34;
				else if (func_003A4AC8(&exc) == 0)
					*Obj0000_Get_D_003FA62C_3A4FB8() = 34;
			}
			if (exc.err != 0)
				*Obj0000_Get_D_003FA62C_3A4FB8() = exc.err;
			return (float)exc.retval;
		}
	}
	if (z == (float)0.0 && func_003A4CF0(x) && func_003A4CF0(y)) {
		exc.type = 4;
		exc.name = D_0045EA98;
		exc.err = 0;
		exc.arg1 = (double)x;
		exc.arg2 = (double)y;
		exc.retval = 0.0;
		if (D_0045F024 == 2)
			*Obj0000_Get_D_003FA62C_3A4FB8() = 34;
		else if (func_003A4AC8(&exc) == 0)
			*Obj0000_Get_D_003FA62C_3A4FB8() = 34;
		if (exc.err != 0)
			*Obj0000_Get_D_003FA62C_3A4FB8() = exc.err;
		return (float)exc.retval;
	}
	return z;
}
