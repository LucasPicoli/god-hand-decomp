/* cygnus-2.96 matched TU. */

__attribute__((section(".text.dvci_getnumtr_upper")))
int dvci_getnumtr_upper(char *a0) {
    return (int)(((long)*(int *)(a0 + 0x14) << 11) >> 32);
}

struct S_353060 { int f0, f4, f8, fC, f10, f14; int pad[2]; int f20; };
struct T_353060 { int f0, f4, f8, fC, f10; };
__attribute__((section(".text.sfmpv_SetMvInf")))
void sfmpv_SetMvInf(struct S_353060 *a0, int a1, struct T_353060 *a2, int a3) {
    int t = a2->f10;
    a0->f0 = a2->f0;
    a0->f4 = a2->f4;
    a0->f8 = a2->f8;
    a0->fC = a2->fC;
    a0->f14 = t;
    a0->f10 = a1;
    a0->f20 = a3;
}

struct S_35BB60 { long f0; long f8; long f10; int f18; };
__attribute__((section(".text.func_0035BB60")))
void func_0035BB60(struct S_35BB60 *a0, long a1) {
    a0->f0 += a1;
    a0->f8 = (a1 < a0->f8) ? a1 : a0->f8;
    a0->f10 = (a0->f10 < a1) ? a1 : a0->f10;
    a0->f18++;
}

__attribute__((section(".text.convAsciiToDigit")))
char *convAsciiToDigit(char *a0, int *a1)
{
	int n;
	int c;

	n = 0;
	c = *a0;
	if (c == '.')
		goto out;
	if (c == ' ' || c == 0 || (unsigned int)(c - '0') >= 0xA)
		goto out;
	for (;;) {
		n = n * 10 + c - '0';
		c = *++a0;
		if (c == '.')
			goto out;
		if (c == ' ' || c == 0 || (unsigned int)(c - '0') >= 0xA)
			goto out;
	}
out:
	*a1 = n;
	return a0;
}

typedef struct {
    void **vtbl;
} ObjVT;

__attribute__((section(".text.func_0036BDA0")))
int func_0036BDA0(ObjVT *obj, int a1, int a2) {
    int local[2];
    int s1 = (unsigned int)a1 < 1U;
    ((void (*)(ObjVT *, int, int, int *))obj->vtbl[6])(obj, a1, a2, local);
    ((void (*)(ObjVT *, int, int *))obj->vtbl[8])(obj, s1, local);
    return local[1];
}
