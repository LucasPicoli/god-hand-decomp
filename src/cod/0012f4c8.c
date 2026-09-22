/* sn-2.95.3-136 matched TU. */

extern void func_002D4C20(void *a0, int a1, int a2, int a3);
extern void func_001E87E0(void *dst, void *a, void *b, int n);
extern void InitClearStructAndSet_1E79A8(int *a0, int a1);
extern void func_001E67A8(void *a0, int a1);
extern void cOmBase_setMeshDispFromLayer(int a0, int a1, int a2);
extern void cSnd_SeCall_2CBA48(void *a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern void SetEffect(int a0, int a1, int a2, int a3, int a4, unsigned int a5);
extern void func_00186038(int a0, int a1);
extern int D_005FEE00;
extern int D_00569B70;
extern int cCoreSave_getSkill(void *a0, int a1);
extern void cCoreSave_setSkill(void *a0, int a1, int a2);
extern void func_0012F600(void *this, void *p, int arg);
extern int cSnd_GetBgmData(int a0, int a1);
extern int cBgmData_GetHeadPtr(int *a0);
extern int cBgmData_GetTblPtr(int *a0, int a1);
extern int cSnd_BgmEvSet(int a0, int a1, int a2);
extern int cSnd_BgmEvStart(int a0, int a1, int a2, int a3);

/* sn-2.95.3-136 */



__attribute__((section(".text.func_002D4B08")))
void func_002D4B08(void *a0, int a1, int a2, int a3, int t0, int t1)
{
    int nx;
    int ny;
    int i;
    int j;
    int base;
    int off;
    int step;

    nx = a2 / 16;
    ny = a3 / 16;
    for (i = 0; i < nx; i++) {
        step = a3 * 64;
        base = t0 + i * 64;
        off = a1 + step * i;
        for (j = 0; j < ny; j++) {
            func_002D4C20(a0, base, off, a2);
            off += 0x400;
            base += t1 * 16;
        }
    }
}

/* sn-2.95.3-136 */





__attribute__((section(".text.Slot2_Initialize")))
void Slot2_Initialize(void *this, unsigned short id, void *p0, void *p1,
                      void *p2, void *p3, void *p4, void *p5,
                      unsigned short n, int last)
{
    if (p0 == 0) return;
    if (p2 == 0) return;
    if (p4 == 0) return;
    if (p1 == 0) return;
    if (p3 == 0) return;
    if (p5 == 0) return;
    if (last == 0) return;
    if (n >= 0x16) return;
    func_001E87E0((char *)this + 0x58, p0, p1, n);
    func_001E87E0((char *)this + 0x140, p2, p3, n);
    func_001E87E0((char *)this + 0x228, p4, p5, n);
    InitClearStructAndSet_1E79A8((int *)((char *)this + 0x310), last);
    *(short *)((char *)this + 0x3D0) = id;
    func_001E67A8(this, 0);
    *(short *)((char *)this + 0x3E0) = 0;
    *(short *)((char *)this + 0x3E2) = 0;
    *(short *)((char *)this + 0x3E4) = 0;
    *(short *)((char *)this + 0x3E6) = 0;
    *(short *)((char *)this + 0x3E8) = 0;
    *(char *)((char *)this + 0x3D8) = 0;
}

/* sn-2.95.3-136 */







__attribute__((section(".text.func_001851C0")))
void func_001851C0(int arg0, unsigned int arg1)
{
    cOmBase_setMeshDispFromLayer(arg0, 0, 0);
    cOmBase_setMeshDispFromLayer(arg0, 0x80, 0);
    switch (arg1) {
    case 0:
        cOmBase_setMeshDispFromLayer(arg0, 0, 1);
        break;
    case 4:
        func_00186038(arg0, 0x10);
        func_00186038(arg0, 0x11);
        func_00186038(arg0, 0x12);
        func_00186038(arg0, 0x13);
        cOmBase_setMeshDispFromLayer(arg0, 0x80, 1);
        SetEffect(0x298, 1, arg0, 0, -1, 0xFFFFFFFF);
        cSnd_SeCall_2CBA48(&D_005FEE00, 2, 0x116, arg0, 0, 0, 0, 0);
        cSnd_SeCall_2CBA48(&D_005FEE00, 0, 2, arg0, 0, 0, 0, 0);
        break;
    }
}

/* sn-2.95.3-136 */





__attribute__((section(".text.func_002C9818")))
void func_002C9818(char *a0, int a1, int *a2, int a3, unsigned char t0)
{
    if ((*(int *)(*(int *)a0 + a1 * 0x24 + 0xC) & 1) != 0) {
        if (cCoreSave_getSkill(&D_00569B70, a1) == -1) {
            cCoreSave_setSkill(&D_00569B70, a1, 0);
        }
    }
    if (t0 == 1) {
        if (cCoreSave_getSkill(&D_00569B70, a1) < 0) return;
        if ((*(int *)(*(int *)a0 + a1 * 0x24 + 0xC) & a3) == 0) return;
    } else {
        if (cCoreSave_getSkill(&D_00569B70, a1) < 0) return;
        if ((*(int *)(*(int *)a0 + a1 * 0x24 + 0xC) & a3) != 0) return;
    }
    do { *(char *)(a0 + *a2 + 0x14) = a1; *a2 = *a2 + 1; } while (0);
}

/* sn-2.95.3-136 */



__attribute__((section(".text.func_0012F4C8")))
void func_0012F4C8(char *this, unsigned int y0, unsigned int y1,
                   unsigned int z0, unsigned int z1,
                   unsigned int x0, unsigned int x1, int arg)
{
    unsigned int y;
    unsigned int z;
    unsigned int x;
    unsigned int b[4];
    char *p;

    for (y = y0; y <= y1; y++) {
        b[0] = y * *(unsigned int *)(this + 0x64) * *(unsigned int *)(this + 0x68);
        for (z = z0; z <= z1; z++) {
            b[1] = z * *(unsigned int *)(this + 0x68) + b[0];
            for (x = x0; x <= x1; x++) {
                p = *(char **)(this + 0x18) + (b[1] + x) * 8;
                if (*(unsigned int *)p != 0xFFFFFFFFu) {
                    func_0012F600(this, p, arg);
                }
            }
        }
    }
}

/* sn-2.95.3-136 */








__attribute__((section(".text.cSnd_BgmEvCutSet")))
void cSnd_BgmEvCutSet(int a0, int a1)
{
    unsigned int i;
    int *hd;
    unsigned char *e;

    if (func_002CFF68((int *)cSnd_GetBgmData(a0, 1)) == 0) {
        return;
    }
    hd = (int *)cBgmData_GetHeadPtr((int *)cSnd_GetBgmData(a0, 1));
    for (i = 0; i < *(unsigned int *)hd; i++) {
        e = (unsigned char *)cBgmData_GetTblPtr((int *)cSnd_GetBgmData(a0, 1), i);
        if (e == 0) continue;
        if (e[0xB] == 0x80) continue;
        if (e[0x11] == a1) {
            cSnd_BgmEvStart(a0, 1, i, 0);
        } else if (e[0x12] == 0) {
            if (e[0x11] == a1 + 1) {
                cSnd_BgmEvSet(a0, 1, i);
            }
        } else {
            if (e[0x12] == a1) {
                cSnd_BgmEvSet(a0, 1, i);
            }
        }
    }
}
