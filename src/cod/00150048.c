/* sn-2.95.3-136 matched TU. */

extern void func_003182D8(int a, int b);
extern void func_0031CE90(int a, int b);
extern unsigned char D_0045F039[];
extern int D_00466470;
extern void ForwardFieldNeg20_002A9680_30F5A0();
extern int D_00462FC0[];
extern void cCollisionSolidManage_ReleaseUnit(void *a0, void *a1);
extern void EmitterAllKill(void);
extern void EspAllKill(void);
extern void func_00386D70(void);
extern void func_0037BE98(void);
extern void FlushCache(int mode);
extern int sceIpuStopDMA(int chan);
extern int sceIpuRestartDMA(int chan);
extern int D_003FA62C;
extern void Obj0000_Get_D_0045FB80_3AD118(int a);
extern void Deci2Call(int a, int *b);
extern void func_002CDA48(void *a);
extern void cIDParam_initialize(void *a);
extern void Setup_00309028_309028(void *a0);
extern void func_00329EA8(void *p);
extern void func_0032B300(void *p, int b);
extern void func_0032A6D0(void *p);
extern void func_00336D08(void *p);
extern void func_0032DB70(void *p);
extern void func_0032E040(void *p, int b);
extern int D_0076DF10;
extern unsigned char D_0041ECA0[];
extern unsigned char D_0042C4D8[];
extern unsigned char D_0044AEF8[];
extern char D_0044B310[];
extern char D_0044BAB0[];
extern char D_0044D1C8[];
extern char D_0044D388[];
extern int D_00450080;
extern int D_00451288;

__attribute__((section(".text.func_003184C0")))
void func_003184C0(void) {
    func_003182D8(1, 0xFFFF);
}

__attribute__((section(".text.func_0031CE98")))
void func_0031CE98(void) {
    func_0031CE90(1, 0xFFFF);
}

__attribute__((section(".text.func_0034AA00")))
int func_0034AA00(int a0, int a1) {
    return func_0034C390(a0, *(int *)((char *)a0 + 0x200C), a1);
}

__attribute__((section(".text.func_003545D8")))
int func_003545D8(int a0, int a1) {
    return func_0034C390(a0, *(int*)((char*)a0 + 0x1FC8), a1);
}

int func_003757A0(int a0, int a1);

__attribute__((section(".text.func_00375840")))
int func_00375840(void) {
    return func_003757A0(1, 0xFFFF);
}

int func_003A6020(int a0, int a1, int a2, int a3);
int func_003A6830(int a0, void *a1);

__attribute__((section(".text.func_003A6290")))
int func_003A6290(int a0) {
    return func_003A6830(a0, func_003A6020);
}

__attribute__((section(".text.func_003AD0F8")))
int func_003AD0F8(int a0) {
    return (D_0045F039[a0] & 1) ? (a0 + 0x20) : a0;
}

int func_001504B0(int *a0, int a1);

__attribute__((section(".text.func_00150098")))
int func_00150098(int a0) {
    return func_001504B0(&D_00466470, a0);
}

int func_001505A8(int *a0, int a1);

__attribute__((section(".text.func_00150100")))
int func_00150100(int a0) {
    return func_001505A8(&D_00466470, a0);
}

__attribute__((section(".text.func_001F8A60")))
void func_001F8A60(int a0, int a1) {
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0();
    }
}

__attribute__((section(".text.cCollisionSolidManage_ReleaseUnit_277540")))
void cCollisionSolidManage_ReleaseUnit_277540(void *a0) {
    cCollisionSolidManage_ReleaseUnit(D_00462FC0, a0);
}

__attribute__((section(".text.cCollisionSolidManage_ReleaseUnit_278368")))
void cCollisionSolidManage_ReleaseUnit_278368(void *a0) {
    cCollisionSolidManage_ReleaseUnit(D_00462FC0, a0);
}

__attribute__((section(".text.cCollisionSolidManage_ReleaseUnit_27E088")))
void cCollisionSolidManage_ReleaseUnit_27E088(void *a0) {
    cCollisionSolidManage_ReleaseUnit(D_00462FC0, a0);
}

__attribute__((section(".text.cCollisionSolidManage_ReleaseUnit_281940")))
void cCollisionSolidManage_ReleaseUnit_281940(void *a0) {
    cCollisionSolidManage_ReleaseUnit(D_00462FC0, a0);
}

__attribute__((section(".text.cCollisionSolidManage_ReleaseUnit_289E10")))
void cCollisionSolidManage_ReleaseUnit_289E10(void *a0) {
    cCollisionSolidManage_ReleaseUnit(D_00462FC0, a0);
}

__attribute__((section(".text.func_00305B90")))
void func_00305B90(void) {
    EmitterAllKill();
    EspAllKill();
}

__attribute__((section(".text.func_00386D48")))
void func_00386D48(void) {
    func_00386D70();
    func_0037BE98();
}

__attribute__((section(".text.func_00395180")))
void func_00395180(void) {
    FlushCache(0);
    FlushCache(2);
}

__attribute__((section(".text.func_0039AE50")))
int func_0039AE50(char *a0) {
    sceIpuStopDMA(*(int *)(a0 + 0x40) + 0x68);
    return 1;
}

__attribute__((section(".text.func_0039AE78")))
int func_0039AE78(char *a0) {
    sceIpuRestartDMA(*(int *)(a0 + 0x40) + 0x68);
    return 1;
}

__attribute__((section(".text.func_003A62B0")))
void func_003A62B0(void) {
    func_003A6290(D_003FA62C);
}

__attribute__((section(".text.func_003AD130")))
void func_003AD130(void) {
    Obj0000_Get_D_0045FB80_3AD118(D_003FA62C);
}

__attribute__((section(".text.func_003B7AA8")))
void func_003B7AA8(int a0) {
    int local;
    local = a0;
    Deci2Call(0x10, &local);
}

__attribute__((section(".text.func_002CDA08")))
void *func_002CDA08(void *a0) {
    func_002CDA48(a0);
    return a0;
}

__attribute__((section(".text.func_00308F18")))
void *func_00308F18(void *a0) {
    cIDParam_initialize(a0);
    return a0;
}

__attribute__((section(".text.func_00309000")))
void *func_00309000(void *a0)
{
    Setup_00309028_309028(a0);
    return a0;
}

__attribute__((section(".text.func_00373F78")))
void func_00373F78(void **a0)
{
	if (*a0) {
		func_00329EA8(*a0);
	}
}

__attribute__((section(".text.func_00373FC8")))
void func_00373FC8(void **a0)
{
	if (*a0) {
		func_0032B300(*a0, 0);
	}
}

__attribute__((section(".text.func_00374120")))
void func_00374120(void **a0)
{
	if (*a0) {
		func_0032A6D0(*a0);
	}
}

__attribute__((section(".text.func_00374148")))
void func_00374148(void **a0)
{
	if (*a0) {
		func_00336D08(*a0);
	}
}

__attribute__((section(".text.func_00374548")))
void func_00374548(void **a0)
{
	if (*a0) {
		func_0032DB70(*a0);
	}
}

__attribute__((section(".text.func_00374598")))
void func_00374598(void **a0)
{
	if (*a0) {
		func_0032E040(*a0, 0);
	}
}

void func_0032DDF8(int *p);
__attribute__((section(".text.func_00374958")))
void func_00374958(int *a0) {
	int *p = *(int **)a0;
	if (p) {
		func_0032DDF8(p);
	}
}

void func_003A52F0(int *p, int b, int c);
__attribute__((section(".text.func_00377D58")))
void func_00377D58(void) {
	func_003A52F0(&D_0076DF10, 0, 0x600);
}

int deci2Putchar(int c);
__attribute__((section(".text.func_003B1E40")))
int func_003B1E40(int a0, int a1, int a2) {
	if (a2) {
		deci2Putchar(a2);
	}
	return 1;
}

int func_003B0E30(int c);
__attribute__((section(".text.func_003B1E68")))
int func_003B1E68(int a0, int a1, int a2) {
	if (a2) {
		func_003B0E30(a2);
	}
	return 1;
}

void func_001661D8(void *a0);
void cIDBase_trans(void *a0);

__attribute__((section(".text.func_00165E88")))
void func_00165E88(void *a0) {
    func_001661D8(a0);
    cIDBase_trans(a0);
}

void func_002BE028(void *a0);
void func_002BE0F0(void *a0);

__attribute__((section(".text.func_002BDFF8")))
void func_002BDFF8(void *a0) {
    func_002BE028(a0);
    func_002BE0F0(a0);
}

void func_002D9C10(void *a0);
void func_002D9CA8(void *a0);

__attribute__((section(".text.func_002D9BE0")))
void func_002D9BE0(void *a0) {
    func_002D9C10(a0);
    func_002D9CA8(a0);
}

__attribute__((section(".text.func_003A8FE0")))
int func_003A8FE0(int a0, int a1) {
    return func_003A80E8(D_003FA62C, a0, a1);
}

__attribute__((section(".text.func_00150048")))
void func_00150048(int *a0, int a1) {
    *(int *)((char *)a0 + 0x214) = (int)D_0041ECA0;
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0(a0);
    }
}

__attribute__((section(".text.func_001FCE80")))
void func_001FCE80(int *a0, int a1) {
    *(int *)((char *)a0 + 0x50) = (int)D_0042C4D8;
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0(a0);
    }
}

__attribute__((section(".text.func_001FD418")))
void func_001FD418(int *a0, int a1) {
    *(int *)((char *)a0 + 0x50) = (int)D_0042C4D8;
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0(a0);
    }
}

__attribute__((section(".text.func_001FE500")))
void func_001FE500(int *a0, int a1) {
    *(int *)((char *)a0 + 0x50) = (int)D_0042C4D8;
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0(a0);
    }
}

__attribute__((section(".text.func_002A98D8")))
void func_002A98D8(int *a0, int a1) {
    *(int *)((char *)a0 + 0x18) = (int)D_0044AEF8;
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0(a0);
    }
}

__attribute__((section(".text.func_002B6568")))
void func_002B6568(void *a0, int a1)
{
    *(char **)((char *)a0 + 0xF0) = D_0044B310;
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0(a0);
    }
}

__attribute__((section(".text.func_002B8B20")))
void func_002B8B20(void *a0, int a1)
{
    *(char **)((char *)a0 + 0x18) = D_0044BAB0;
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0(a0);
    }
}

__attribute__((section(".text.func_002D5C38")))
void func_002D5C38(void *a0, int a1)
{
    *(char **)((char *)a0 + 0x30) = D_0044D1C8;
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0(a0);
    }
}

__attribute__((section(".text.func_002D9E30")))
void func_002D9E30(void *a0, int a1)
{
    *(char **)((char *)a0 + 0x0) = D_0044D388;
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0(a0);
    }
}

__attribute__((section(".text.func_002FBDD8")))
void func_002FBDD8(void *a0, int a1)
{
    *(char **)((char *)a0 + 0xF0) = D_0044B310;
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0(a0);
    }
}

__attribute__((section(".text.func_003028E8")))
void func_003028E8(void *a0, int a1)
{
    *(char **)((char *)a0 + 0xF0) = D_0044B310;
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0(a0);
    }
}

__attribute__((section(".text.func_00305A38")))
void func_00305A38(void *a0, int a1)
{
    *(int **)((char *)a0 + 0x424) = &D_00450080;
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0(a0);
    }
}

__attribute__((section(".text.func_0031F330")))
void func_0031F330(void *a0, int a1)
{
    *(int **)a0 = &D_00451288;
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0(a0);
    }
}

__attribute__((section(".text.func_0031F3C8")))
void func_0031F3C8(void *a0, int a1)
{
    *(int **)a0 = &D_00451288;
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0(a0);
    }
}

__attribute__((section(".text.func_00321818")))
void func_00321818(void *a0, int a1)
{
    *(int **)a0 = &D_00451288;
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0(a0);
    }
}

__attribute__((section(".text.func_003218B0")))
void func_003218B0(void *a0, int a1)
{
    *(int **)a0 = &D_00451288;
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0(a0);
    }
}
