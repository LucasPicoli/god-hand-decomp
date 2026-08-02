/* cygnus-2.96 matched TU. */

extern char D_004511B8[];
extern char D_00451188[];
extern char D_00451178[];
extern char D_00451168[];
extern char D_00451158[];

/* clone */


__attribute__((section(".text.func_0031FA20")))
void func_0031FA20(int *a0, int a1, int a2) {
    if (a0 == 0) {
        return;
    }
    *(int*)((char*)a0 + 8) = a2;
    *(int*)((char*)a0 + 0) = a1;
    *(int*)((char*)a0 + 4) = (int)D_004511B8;
}

/* clone */


__attribute__((section(".text.func_0031FA68")))
void func_0031FA68(int *a0, int a1)
{
	if (a0) {
		a0[0] = a1;
		a0[1] = (int)&D_00451188;
	}
}

/* clone */


__attribute__((section(".text.func_0031FA88")))
void func_0031FA88(int *a0, int a1)
{
	if (a0) {
		a0[0] = a1;
		a0[1] = (int)&D_00451178;
	}
}

/* clone */


__attribute__((section(".text.func_0031FAA8")))
void func_0031FAA8(int *a0, int a1)
{
	if (a0) {
		a0[0] = a1;
		a0[1] = (int)&D_00451168;
	}
}

/* clone */


__attribute__((section(".text.func_0031FAC8")))
void func_0031FAC8(int *a0, int a1)
{
	if (a0) {
		a0[0] = a1;
		a0[1] = (int)&D_00451158;
	}
}
