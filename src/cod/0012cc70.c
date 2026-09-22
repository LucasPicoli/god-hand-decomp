/* sn-2.95.3-136 matched TU. */

extern int SetEffect(int a0, int a1, void *a2, int a3, int t0, unsigned t1);
extern void func_001E7E68(void *dst, void *a, void *b, int n);
extern void InitClearStructAndSet_1E79A8(int *a0, int a1);
extern void func_001E3240(void *a0, int a1);
extern unsigned char D_0076CF20[];
extern void func_0037C5C8(void *slot, void *obj, int bit);
extern void func_0037C6A0(void *slot);
extern void func_0037C5F8(void *slot, void *obj, int bit);
extern void func_0037C618(void *slot, void *obj, int bit);
extern int *D_003C2384;
extern int D_003C2388;
extern void func_002AA1E0(int a0, int a1, int a2);
extern void func_002AA480(int a0);
extern void func_001EF978(void *a0);
extern void cEmSetParam_setEm(void *a0, int a1);
extern void cEmWrap_StartAction(void *a0);
extern char D_00586AB0[];
extern int D_007476B0;
extern unsigned char D_00754C80[];
extern void *cModel_getMeshPtr(void *this, int idx);
extern void func_0031A600(void *a0, int a1, int a2, int a3);
extern void func_0031A650(void *a0, int a1, int a2, int a3, int t0);

/* sn-2.95.3-136 */



__attribute__((section(".text.func_0012CC70")))
void func_0012CC70(void *this)
{
    void *q;
    void *e;

    if (*(int *)((char *)this + 0x644) != 0) {
        return;
    }
    q = *(void **)((char *)this + 0x640);
    if (q == 0) {
        return;
    }
    *(void **)((char *)this + 0x644) = q;
    *(int *)((char *)this + 0x15F4) |= 0x800000;
    if (*(int *)((char *)q + 0x564) != 0x26A) {
        SetEffect(0, 0x61, q, 0, 6, 0xFFFFFFFFu);
        return;
    }
    SetEffect(0, 0x79, q, 0, 6, 0xFFFFFFFFu);
    e = *(void **)((char *)this + 0x644);
    if (*(void **)((char *)e + 0x748) != 0) {
        SetEffect(0, 0x79, *(void **)((char *)e + 0x748), 0, 6, 0xFFFFFFFFu);
    }
    if (*(void **)((char *)e + 0x74C) != 0) {
        SetEffect(0, 0x79, *(void **)((char *)e + 0x74C), 0, 6, 0xFFFFFFFFu);
    }
    if (*(void **)((char *)e + 0x750) != 0) {
        SetEffect(0, 0x79, *(void **)((char *)e + 0x750), 0, 6, 0xFFFFFFFFu);
    }
}

/* sn-2.95.3-136 */





__attribute__((section(".text.Slot1_Initialize")))
void Slot1_Initialize(void *this, unsigned short id, void *p0, void *p1,
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
    func_001E7E68((char *)this + 0x58, p0, p1, n);
    func_001E7E68((char *)this + 0x160, p2, p3, n);
    func_001E7E68((char *)this + 0x268, p4, p5, n);
    InitClearStructAndSet_1E79A8((int *)((char *)this + 0x370), last);
    *(short *)((char *)this + 0x48C) = id;
    func_001E3240(this, 0);
}

/* sn-2.95.3-136 */







__attribute__((section(".text.func_0037C4C0")))
void func_0037C4C0(void *obj)
{
    char *p;
    int i;
    unsigned short f;

    p = (char *)D_0076CF20;
    for (i = 0x32; i >= 0; i--, p += 0x50) {
        if (*(unsigned short *)(p + 0x0) == 0) continue;
        if ((*(unsigned char *)(p + 0x5) & *(unsigned char *)((char *)obj + 0xD)) == 0) continue;
        if (*(int *)(p + 0x10) != *(int *)((char *)obj + 0x4)) continue;
        f = *(unsigned short *)((char *)obj + 0x2A);
        if (f & 1) {
            func_0037C5C8(p, obj, 1);
        }
        if (f & 2) {
            func_0037C5C8(p, obj, 2);
        }
        if (*(unsigned char *)((char *)obj + 0xD) & 8) {
            if (f & 3) {
                func_0037C6A0(p);
            }
        }
        if (f & 4) {
            func_0037C5F8(p, obj, 4);
        }
        if (f & 8) {
            func_0037C618(p, obj, 8);
        }
    }
}

/* sn-2.95.3-136 */







__attribute__((section(".text.cIDBase_setWorkFromData")))
int cIDBase_setWorkFromData(int a0, int a1)
{
    unsigned int i;
    int q;
    int r;

    if (*(int *)a1 != 0x504449) {
        goto ng;
    }
    *(int *)(a0 + 0xC) = 0;
    q = a1 + 0x10;
    if (*D_003C2384 == D_003C2388) {
        for (i = 0; i < *(unsigned int *)(a1 + 4); i++) {
            if ((*(int *)(a1 + 0x14 + i * 0x2E0) & 0x200) == 0) {
                *(int *)(a0 + 0xC) += 1;
            }
        }
    } else {
        *(int *)(a0 + 0xC) = *(int *)(a1 + 4);
    }
    if (*(int *)(a0 + 0xC) == 0) {
        goto ng;
    }
    if (*(int *)(a0 + 4) == 0) {
        r = func_002ACE48(*D_003C2384, *(int *)(a0 + 0xC), *(int *)(a0 + 0x14),
                          *(int *)(a0 + 0x10));
        *(int *)(a0 + 4) = r;
        if (r == 0) {
            goto ng;
        }
    }
    func_002AA1E0(a0, q, *(int *)(a0 + 0xC));
    func_002AA480(a0);
    return 1;
ng:
    return 0;
}

/* sn-2.95.3-136 */







__attribute__((section(".text.func_001F2428")))
void func_001F2428(void *a0) {
    char *s0 = (char *)a0;
    char buf[0x10];
    int st;

    st = *(int *)(s0 + 0xB94);
    switch (st) {
    case 0:
        func_001EF978(s0);
        *(int *)(s0 + 0xB94) = *(int *)(s0 + 0xB94) + 1;
        break;
    case 1:
        if (func_001EF8B8(s0) != 0) break;
        buf[0] = st;
        cEmSetParam_setEm(D_00586AB0, 1);
        cEmWrap_StartAction(buf);
        *(int *)(s0 + 0xB8C) = *(int *)(s0 + 0xB8C) + 1;
        *(int *)(s0 + 0xB94) = *(int *)(s0 + 0xB94) + 1;
        break;
    case 2:
        if (func_001EF8B8(s0) != 0) break;
        buf[0] = st;
        cEmSetParam_setEm(D_00586AB0, 2);
        cEmWrap_StartAction(buf);
        *(int *)(s0 + 0xB8C) = *(int *)(s0 + 0xB8C) + 1;
        *(int *)(s0 + 0xB94) = *(int *)(s0 + 0xB94) + 1;
        break;
    case 3:
        if (func_001EF8B8(s0) != 0) break;
        buf[0] = st;
        cEmSetParam_setEm(D_00586AB0, 3);
        cEmWrap_StartAction(buf);
        *(int *)(s0 + 0xB8C) = *(int *)(s0 + 0xB8C) + 1;
        *(int *)(s0 + 0xB94) = *(int *)(s0 + 0xB94) + 1;
        break;
    }
}

/* sn-2.95.3-136 */







__attribute__((section(".text.func_0014C5A0")))
void func_0014C5A0(void *a0, short a1)
{
    char *this = (char *)a0;
    char *mesh;
    int bit;
    int flags;
    char *arr;
    int p;
    int q;

    bit = D_007476B0 & 1;
    mesh = (char *)cModel_getMeshPtr(this, 0);
    flags = *(int *)(mesh + 0x380);
    arr = this + 0x220;
    arr += bit * 4;
    p = *(int *)arr;
    q = p + 0x70;
    if (*(int *)(this + 0x2C0) == 0xA) {
        if ((flags & 0x4080) != 0) {
            if (q == 0) {
                func_0031A600(D_00754C80, 2, a1, p);
            } else {
                func_0031A650(D_00754C80, 2, a1, p, q);
            }
        } else {
            if (q == 0) {
                func_0031A600(D_00754C80, 1, 0xD, p);
            } else {
                func_0031A650(D_00754C80, 1, 0xD, p, q);
            }
        }
    } else {
        if (q == 0) {
            func_0031A600(D_00754C80, *(int *)(this + 0x2C0),
                          *(short *)(this + 0x2AC), p);
        } else {
            func_0031A650(D_00754C80, *(int *)(this + 0x2C0),
                          *(short *)(this + 0x2AC), p, q);
        }
    }
}
