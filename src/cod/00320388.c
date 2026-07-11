/* cygnus-2.96 matched TU. */

extern int func_003203B0(void);
extern void *D_003C490C;
extern int D_007588C0[2];
extern int D_003DECFC;
extern int D_003DED00;
extern void (*D_007588C8[2])();
extern void (*D_003E9D18)(int);
extern void (*D_003E9D1C)(int);
extern void (*D_003E9D24)(int);
extern void (*D_003E9D2C)(int);
extern void (*D_003EC454)(int, int);
extern int D_003EC458;
extern char *GetD003EC7E0_3452B0(void);
extern void (*D_003DA4C4)(int, int);
extern int D_003DA4C8;
extern int D_003DA4CC;
extern int D_00760DB0;
extern int D_00760DB4;
extern void Forward33E6A8_324880();
extern int Forward33E6B0_324898(void);
extern int Obj0000_Get_D_003EB308_Plus10_By_Index_324808(int);
extern void Obj3290_Tramp_0033E6A8_9070(int);
extern void Obj3290_Tramp_0033E6B0_9088(void);
extern void NoOp_33E6A8(int);
extern void NoOp_33E6B0(void);
extern int ADXT_GetNumSctIbuf(int);
extern void Obj33F8_NoOp_FCA0(void);
extern int Obj33F8_NoOp_FCA8(void);
extern void func_00335CD8(int);
extern void func_00335CE0(void);
extern void Forward33B658_3389F8(int);
extern void Forward33B670_338A10(void);
extern void (*D_003EADB8)(void *, void *);
extern void *D_003EADBC;
extern char D_003EADC0[];
extern int SFD_Standby(int a0);
extern void MWSFSVM_Error();
extern char D_00457E88[];
extern int D_00457EA8;
extern int D_003EB838;
extern int D_003EB834;
extern int D_003C529C;
extern int GetArrayElemA0C_35A1C8(void *a0, int a1);
extern void func_0034B8C8(void *a0);
extern void Obj3290_Tramp_0033E678_9028();
extern void func_00328190(void *a0);
extern void Obj3290_Tramp_0033E690_9040(void);

__attribute__((section(".text.func_00320388")))
void func_00320388(void)
{
    int (*f)(void) = func_003203B0;
    D_003C490C = (void *)f;
    f();
}

__attribute__((section(".text.func_0033BFB8")))
void func_0033BFB8(void) {
    int (*fn)(int);
    fn = (int (*)(int))D_007588C0[0];
    if (fn != 0) {
        fn(D_007588C0[1]);
    }
}

__attribute__((section(".text.func_00336330")))
void func_00336330(int a0, int a1) {
    void (*fn)(int, int, int);
    fn = (void (*)(int, int, int))D_003DECFC;
    if (fn != 0) {
        fn(D_003DED00, a1, a0);
    }
}

__attribute__((section(".text.func_0033BFE8")))
void func_0033BFE8(void) {
    if (D_007588C8[0]) {
        ((void (*)(int))D_007588C8[0])((int)D_007588C8[1]);
    }
}

__attribute__((section(".text.func_0033C240")))
void func_0033C240(int *a0) {
    int v0 = *(int *)((char *)a0 + 0xC0);
    if (v0) {
        D_003E9D18(v0);
    }
}

__attribute__((section(".text.func_0033C290")))
void func_0033C290(int *a0) {
    int v0 = *(int *)((char *)a0 + 0xC0);
    if (v0) {
        D_003E9D1C(v0);
    }
}

__attribute__((section(".text.func_0033C428")))
void func_0033C428(int *a0) {
    int v0 = *(int *)((char *)a0 + 0xB4);
    if (v0) {
        D_003E9D24(v0);
    }
}

__attribute__((section(".text.func_0033C4E8")))
void func_0033C4E8(int *a0) {
    int v0 = *(int *)((char *)a0 + 0xB4);
    if (v0) {
        D_003E9D2C(v0);
    }
}

__attribute__((section(".text.func_00340450")))
void func_00340450(int a0) {
    if (D_003EC454) {
        D_003EC454(D_003EC458, a0);
    }
}

__attribute__((section(".text.func_003465B8")))
int func_003465B8(int a0, int a1, int a2)
{
    func_003A5148((void *)(0x70000000 + a2), a0, a1);
    return 0;
}

__attribute__((section(".text.func_00347370")))
void func_00347370(char *a0)
{
    int *p = *(int **)(a0 + 0x17C);
    if (p) {
        void (**vt)(int *) = *(void (***)(int *))p;
        (*(void (**)(int *))((char *)vt + 0xC))(p);
    }
}

__attribute__((section(".text.func_00347420")))
void func_00347420(char *a0)
{
    int *p = *(int **)(a0 + 0x17C);
    if (p) {
        void (**vt)(int *) = *(void (***)(int *))p;
        (*(void (**)(int *))((char *)vt + 0x14))(p);
    }
}

__attribute__((section(".text.func_003493D8")))
void func_003493D8(void)
{
    char *s = GetD003EC7E0_3452B0();
    void (*fp)(int) = *(void (**)(int))(s + 0x40);
    int arg = *(int *)(s + 0x44);
    if (fp) fp(arg);
}

__attribute__((section(".text.func_00349408")))
void func_00349408(void)
{
    char *s = GetD003EC7E0_3452B0();
    void (*fp)(int) = *(void (**)(int))(s + 0x48);
    int arg = *(int *)(s + 0x4C);
    if (fp) fp(arg);
}

__attribute__((section(".text.func_00349438")))
void func_00349438(void)
{
    char *s = GetD003EC7E0_3452B0();
    void (*fp)(int) = *(void (**)(int))(s + 0x50);
    int arg = *(int *)(s + 0x54);
    if (fp) fp(arg);
}

__attribute__((section(".text.func_00335C30")))
void func_00335C30(void) {
    if (D_003DA4C4) {
        D_003DA4C4(D_003DA4C8, D_003DA4CC);
    }
}

__attribute__((section(".text.func_00344610")))
int func_00344610(int *a0, unsigned int a1) {
    unsigned int end;
    unsigned int ret = 0;
    a0 = (int *)((char *)a0 + 0x1EC);
    end = (unsigned int)a0[3] + a1;
    if ((unsigned int)a0[1] >= end) {
        ret = (unsigned int)a0[2];
        a0[3] = end;
        a0[2] = ret + a1;
    }
    return ret;
}

__attribute__((section(".text.func_003464D8")))
int func_003464D8(int a0, int a1, int a2) {
    func_003A5148(a2, a0 + 0x70000000, a1);
    return 0;
}

__attribute__((section(".text.func_0034CC40")))
int func_0034CC40(int **a0) {
    int (*f)(void);
    int r;
    f = (int (*)(void))a0[0][4];
    r = f();
    return (r ^ D_00760DB0) == 0;
}

__attribute__((section(".text.func_0034CC78")))
int func_0034CC78(int **a0) {
    int (*f)(void);
    int r;
    f = (int (*)(void))a0[0][4];
    r = f();
    return (r ^ D_00760DB4) == 0;
}

__attribute__((section(".text.func_00368FE8")))
int func_00368FE8(void) {
    int r;
    r = func_00369020();
    if (r != 0) {
        return func_00369078(r);
    }
    return r;
}

__attribute__((section(".text.func_0036D3D8")))
int func_0036D3D8(void) {
    int r;
    r = func_0036D410();
    if (r != 0) {
        return func_0036D460(r);
    }
    return r;
}

__attribute__((section(".text.func_00324008")))
int func_00324008(int a0) {
    int r;
    Forward33E6A8_324880(a0);
    r = func_00324040(a0);
    Forward33E6B0_324898();
    return r;
}

__attribute__((section(".text.func_003243C8")))
int func_003243C8(int a0) {
    int r;
    Forward33E6A8_324880(a0);
    r = func_00324400(a0);
    Forward33E6B0_324898();
    return r;
}

__attribute__((section(".text.func_003244C8")))
int func_003244C8(int a0) {
    int r;
    Forward33E6A8_324880(a0);
    r = func_00324500(a0);
    Forward33E6B0_324898();
    return r;
}

__attribute__((section(".text.func_003247D0")))
int func_003247D0(int a0) {
    int r;
    Forward33E6A8_324880(a0);
    r = Obj0000_Get_D_003EB308_Plus10_By_Index_324808(a0);
    Forward33E6B0_324898();
    return r;
}

__attribute__((section(".text.func_00328140")))
int func_00328140(int a0) {
    int r;
    Obj3290_Tramp_0033E6A8_9070(a0);
    r = func_00328178(a0);
    Obj3290_Tramp_0033E6B0_9088();
    return r;
}

__attribute__((section(".text.func_003281C8")))
int func_003281C8(int a0) {
    int r;
    Obj3290_Tramp_0033E6A8_9070(a0);
    r = func_00328200(a0);
    Obj3290_Tramp_0033E6B0_9088();
    return r;
}

__attribute__((section(".text.func_00328D40")))
int func_00328D40(int a0) {
    int r;
    Obj3290_Tramp_0033E6A8_9070(a0);
    r = func_00328D78(a0);
    Obj3290_Tramp_0033E6B0_9088();
    return r;
}

__attribute__((section(".text.func_00328D80")))
int func_00328D80(int a0) {
    int r;
    Obj3290_Tramp_0033E6A8_9070(a0);
    r = func_00328DB8(a0);
    Obj3290_Tramp_0033E6B0_9088();
    return r;
}

__attribute__((section(".text.func_0032A648")))
int func_0032A648(int a0)
{
	int r;
	NoOp_33E6A8(a0);
	r = func_0032A680(a0);
	NoOp_33E6B0();
	return r;
}

__attribute__((section(".text.func_0032A988")))
int func_0032A988(int a0)
{
	int r;
	NoOp_33E6A8(a0);
	r = func_0032A9C0(a0);
	NoOp_33E6B0();
	return r;
}

__attribute__((section(".text.func_0032AAA0")))
int func_0032AAA0(int a0)
{
	int r;
	NoOp_33E6A8(a0);
	r = func_0032AAD8(a0);
	NoOp_33E6B0();
	return r;
}

__attribute__((section(".text.func_0032AD10")))
int func_0032AD10(int a0)
{
	int r;
	NoOp_33E6A8(a0);
	r = ADXT_GetNumSctIbuf(a0);
	NoOp_33E6B0();
	return r;
}

__attribute__((section(".text.func_0032B6E0")))
int func_0032B6E0(int a0)
{
	int r;
	NoOp_33E6A8(a0);
	r = func_0032B718(a0);
	NoOp_33E6B0();
	return r;
}

__attribute__((section(".text.func_0032D0C0")))
int func_0032D0C0(int a0)
{
	int r;
	NoOp_33E6A8(a0);
	r = func_0032D0F8(a0);
	NoOp_33E6B0();
	return r;
}

__attribute__((section(".text.func_0032E118")))
int func_0032E118(int a0) {
    int r;
    Obj33F8_NoOp_FCA0();
    r = func_0032E150(a0);
    Obj33F8_NoOp_FCA8();
    return r;
}

__attribute__((section(".text.func_0032E1F0")))
int func_0032E1F0(int a0) {
    int r;
    Obj33F8_NoOp_FCA0();
    r = func_0032E228(a0);
    Obj33F8_NoOp_FCA8();
    return r;
}

__attribute__((section(".text.func_0032E280")))
int func_0032E280(int a0) {
    int r;
    Obj33F8_NoOp_FCA0();
    r = func_0032E2B8(a0);
    Obj33F8_NoOp_FCA8();
    return r;
}

__attribute__((section(".text.func_0032E310")))
int func_0032E310(int a0) {
    int r;
    Obj33F8_NoOp_FCA0();
    r = func_0032E348(a0);
    Obj33F8_NoOp_FCA8();
    return r;
}

__attribute__((section(".text.func_003353C0")))
int func_003353C0(int a0) {
    int r;
    func_00335CD8(a0);
    r = func_003353F8(a0);
    func_00335CE0();
    return r;
}

__attribute__((section(".text.func_00335AA0")))
int func_00335AA0(int a0) {
    int r;
    func_00335CD8(a0);
    r = func_00335AD8(a0);
    func_00335CE0();
    return r;
}

__attribute__((section(".text.func_00335B08")))
int func_00335B08(int a0) {
    int r;
    func_00335CD8(a0);
    r = func_00335B40(a0);
    func_00335CE0();
    return r;
}

__attribute__((section(".text.func_00338D58")))
int func_00338D58(int a0) {
    int r;
    Forward33B658_3389F8(a0);
    r = func_00338D90(a0);
    Forward33B670_338A10();
    return r;
}

__attribute__((section(".text.func_0033A388")))
int func_0033A388(int a0) {
    int r;
    Forward33B658_3389F8(a0);
    r = func_0033A3C0(a0);
    Forward33B670_338A10();
    return r;
}

__attribute__((section(".text.func_0033F0B8")))
void func_0033F0B8(void) {
    func_003A52F0(D_003EADC0, 0, 0x100);
    D_003EADB8 = 0;
    D_003EADBC = 0;
}

__attribute__((section(".text.func_00345AF8")))
int func_00345AF8(int *a0)
{
    if (SFD_Standby(a0[0xF]) != 0) {
        func_00345750(-0x137);
        MWSFSVM_Error(D_00457E88);
        return -0x137;
    }
    return 0;
}

__attribute__((section(".text.func_00345B38")))
int func_00345B38(int *a0) {
    if (func_003588B0(a0[0xF])) {
        func_00345750(-0x133);
        MWSFSVM_Error((int)&D_00457EA8);
        return -0x133;
    }
    return 0;
}

__attribute__((section(".text.func_00322F18")))
void func_00322F18(void) {
    func_00323AA0(D_003EB838);
    D_003EB838 = 0;
    D_003EB834 = 0;
    D_003C529C = 0;
}

__attribute__((section(".text.func_0034B888")))
int func_0034B888(void *a0)
{
	int r = GetArrayElemA0C_35A1C8(a0, 6);
	if (r != 0) {
		void *p = (void *)((char *)a0 + 0x365C);
		*(void **)((char *)a0 + 0x2114) = p;
		func_0034B8C8(p);
		r = 0;
	}
	return r;
}

__attribute__((section(".text.func_00328200")))
int func_00328200(void *a0)
{
	Obj3290_Tramp_0033E678_9028(a0);
	func_00328190(a0);
	*(int *)((char *)a0 + 0x5C) = 0xFFFFF;
	Obj3290_Tramp_0033E690_9040();
	return 1;
}

__attribute__((section(".text.func_00354B98")))
int func_00354B98(int a0, int a1)
{
    if (a1 >= -3) {
        if (a1 < -1) return;
        if (a1 == 0) return;
    }
    return func_0034DD70(a0, a1);
}

__attribute__((section(".text.func_00328288")))
int func_00328288(int a0, int a1)
{
    Obj3290_Tramp_0033E678_9028();
    func_00328190(a0);
    *(int *)(a0 + 0x5C) = a1;
    Obj3290_Tramp_0033E690_9040();
    return 1;
}
