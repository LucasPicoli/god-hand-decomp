/* sn-2.95.3-136 matched TU. */

extern int D_003C2FB0;
extern int D_003C2F84;
extern int D_003C23A4;
extern int D_003BD6E8;
extern int D_003BD930;
extern void Trans_Clipmatrix_set(void);
extern void cScrSpriteDraw_drawInit(int);
extern void ObjTrans(void);
extern void func_002C3818(int);
extern void func_002AF028(int);
extern void TransEsp(void);
extern void func_001410A8(int);
extern void func_00160B90(int);
extern unsigned char D_005E8658[];
extern void func_002BECB0(void *, long);
extern unsigned char D_0071B940[];
extern unsigned char D_00741940[];
extern unsigned char D_00741960[];
extern unsigned char D_00741980[];
extern void func_003A52F0(void *, int, int);

__attribute__((section(".text.func_00302930")))
void func_00302930(void *a0, int a1, int a2) {
    a1 = a1 & 0xFFFF;
    if (*(unsigned short*)((char*)a0 + 0x224) == 0) {
        *(unsigned short*)((char*)a0 + 0x224) = a1;
        return;
    }
    {
        int iv = (int)(*(float*)((char*)a0 + 0x228));
        unsigned short cur = *(unsigned short*)((char*)a0 + 0x224);
        int diff = (int)cur - (iv & 0xFFFF);
        if (a2 == 1 || (a2 == 0 && diff < a1)) {
            *(unsigned short*)((char*)a0 + 0x224) = a1 + iv;
        }
    }
}

__attribute__((section(".text.Trans")))
void Trans(void) {
    Trans_Clipmatrix_set();
    cScrSpriteDraw_drawInit(D_003C2FB0);
    ObjTrans();
    func_002C3818(D_003C2F84);
    func_002AF028(D_003C23A4);
    TransEsp();
    func_001410A8(D_003BD6E8);
    func_00160B90(D_003BD930);
}

__attribute__((section(".text.cScenario_setOmBreak")))
void cScenario_setOmBreak(int a0, signed char *a1) {
    unsigned char *p = D_005E8658;
    long acc = 0;
    int i = 0;
    if (*a1 != 0) {
        do {
            long c = *a1;
            acc |= c << (i * 8);
            i++;
            a1++;
        } while (i < 8 && *a1 != 0);
    }
    func_002BECB0(p, acc);
}

__attribute__((section(".text.InitEmitterWork")))
void InitEmitterWork(void) {
    func_003A52F0(D_0071B940, 0, 0x26000);
    func_003A52F0(D_00741940, 0, 0x20);
    func_003A52F0(D_00741960, 0, 0x20);
    func_003A52F0(D_00741980, 0, 0x20);
}
