/* sn-2.95.3-136 matched TU. */

extern void cModel_calcParts(void *m);
extern void cOmBase_setMeshColorFromLayer(void *a0, int a1, float r, float g, float b);
extern float fRand0_1(void);
extern float DoubleFloatMinusHalf_31D020(void);

/* sn-2.95.3-136 */



static inline int GetLayerObj(char *a0, int *frame, int idx)
{
    int b;

    *frame = b = *(unsigned char *)(a0 + 0x2B4);
    if (idx >= 0 && idx < b) {
        return *(int *)(*(int *)(a0 + 0x278) + idx * 4);
    }
    return 0;
}

__attribute__((section(".text.func_001D0140")))
void func_001D0140(char *p, float *pos, int a2)
{
    unsigned char frame[0x10];
    char *m;
    float *d;
    char *e;

    m = *(char **)(p + 0x600);
    if (m != 0) {
        m = *(char **)(m + 0xF0);
        d = (float *)(p + 0x490);
        if (d != (float *)m) { d[0] = ((float *)m)[0]; d[1] = ((float *)m)[1]; d[2] = ((float *)m)[2]; }
    }
    *(float *)(p + 0x24C) = 1.0f;
    *(int *)(p + 0x250) = *(int *)(p + 0x250) & 0xFFFFFFEF;
    *(int *)(p + 0x600) = 0;
    *(int *)(p + 0x630) = 0;
    e = (char *)GetLayerObj(p, (int *)frame, 0);
    if (e != 0) {
        *(int *)(e + 0x148) = (int)p;
        *(int *)(e + 0x100) = 0;
        *(int *)(e + 0x104) = 0;
        *(int *)(e + 0x108) = 0;
        cModel_calcParts(p);
        *(int *)(p + 0x670) = a2;
        {
            float *d2 = (float *)(p + 0x640);
            if (d2 != pos) { d2[0] = pos[0]; d2[1] = pos[1]; d2[2] = pos[2]; }
        }
        *(unsigned char *)(p + 0x2F4) = 0;
        *(unsigned char *)(p + 0x2F5) = 0x11;
        *(unsigned char *)(p + 0x2F6) = 0;
        *(unsigned char *)(p + 0x2F7) = 0;
    }
}

/* sn-2.95.3-136 */



__attribute__((section(".text.func_001D0240")))
void func_001D0240(char *p, float *pos, int a2)
{
    unsigned char frame[0x10];
    char *m;
    float *d;
    char *e;

    m = *(char **)(p + 0x600);
    if (m != 0) {
        m = *(char **)(m + 0xF0);
        d = (float *)(p + 0x490);
        if (d != (float *)m) { d[0] = ((float *)m)[0]; d[1] = ((float *)m)[1]; d[2] = ((float *)m)[2]; }
    }
    *(float *)(p + 0x24C) = 1.0f;
    *(int *)(p + 0x250) = *(int *)(p + 0x250) & 0xFFFFFFEF;
    *(int *)(p + 0x600) = 0;
    *(int *)(p + 0x630) = 0;
    e = (char *)GetLayerObj(p, (int *)frame, 0);
    if (e != 0) {
        *(int *)(e + 0x148) = (int)p;
        *(int *)(e + 0x100) = 0;
        *(int *)(e + 0x104) = 0;
        *(int *)(e + 0x108) = 0;
        cModel_calcParts(p);
        *(int *)(p + 0x670) = a2;
        {
            float *d2 = (float *)(p + 0x640);
            if (d2 != pos) { d2[0] = pos[0]; d2[1] = pos[1]; d2[2] = pos[2]; }
        }
        *(unsigned char *)(p + 0x2F4) = 0;
        *(unsigned char *)(p + 0x2F5) = 0x12;
        *(unsigned char *)(p + 0x2F6) = 0;
        *(unsigned char *)(p + 0x2F7) = 0;
    }
}

/* sn-2.95.3-136 */



__attribute__((section(".text.func_001D0340")))
void func_001D0340(char *p)
{
    unsigned char frame[0x10];
    char *m;
    float *d;
    char *e;

    m = *(char **)(p + 0x600);
    if (m != 0) {
        m = *(char **)(m + 0xF0);
        d = (float *)(p + 0x490);
        if (d != (float *)m) { d[0] = ((float *)m)[0]; d[1] = ((float *)m)[1]; d[2] = ((float *)m)[2]; }
    }
    *(float *)(p + 0x24C) = 1.0f;
    *(int *)(p + 0x250) = *(int *)(p + 0x250) & 0xFFFFFFEF;
    *(int *)(p + 0x600) = 0;
    *(int *)(p + 0x630) = 0;
    e = (char *)GetLayerObj(p, (int *)frame, 0);
    if (e != 0) {
        *(int *)(e + 0x148) = (int)p;
        *(int *)(e + 0x100) = 0;
        *(int *)(e + 0x104) = 0;
        *(int *)(e + 0x108) = 0;
        cModel_calcParts(p);
        *(int *)(p + 0x670) = 0;
        *(unsigned char *)(p + 0x2F4) = 0;
        *(unsigned char *)(p + 0x2F5) = 0x14;
        *(unsigned char *)(p + 0x2F6) = 0;
        *(unsigned char *)(p + 0x2F7) = 0;
    }
}

/* sn-2.95.3-136 */



__attribute__((section(".text.func_001D0408")))
void func_001D0408(char *p)
{
    unsigned char frame[0x10];
    char *m;
    float *d;
    char *e;

    m = *(char **)(p + 0x600);
    if (m != 0) {
        m = *(char **)(m + 0xF0);
        d = (float *)(p + 0x490);
        if (d != (float *)m) { d[0] = ((float *)m)[0]; d[1] = ((float *)m)[1]; d[2] = ((float *)m)[2]; }
    }
    *(float *)(p + 0x24C) = 1.0f;
    *(int *)(p + 0x250) = *(int *)(p + 0x250) & 0xFFFFFFEF;
    *(int *)(p + 0x600) = 0;
    *(int *)(p + 0x630) = 0;
    e = (char *)GetLayerObj(p, (int *)frame, 0);
    if (e != 0) {
        *(int *)(e + 0x148) = (int)p;
        *(int *)(e + 0x100) = 0;
        *(int *)(e + 0x104) = 0;
        *(int *)(e + 0x108) = 0;
        cModel_calcParts(p);
        *(int *)(p + 0x670) = 0;
        *(unsigned char *)(p + 0x2F4) = 0;
        *(unsigned char *)(p + 0x2F5) = 0x15;
        *(unsigned char *)(p + 0x2F6) = 0;
        *(unsigned char *)(p + 0x2F7) = 0;
    }
}

__attribute__((section(".text.func_001AD818")))
void func_001AD818(char *p)
{
    unsigned char frame[0x10];

    if (GetLayerObj(p, (int *)frame, 1) != 0) {
        int e1 = GetLayerObj(p, (int *)frame, 1);
        *(int *)(e1 + 0x104) = 0;
    }
    if (GetLayerObj(p, (int *)frame, 2) != 0) {
        int e2 = GetLayerObj(p, (int *)frame, 2);
        *(int *)(e2 + 0x104) = 0;
    }
}

__attribute__((section(".text.func_002F53A8")))
int func_002F53A8(char *p)
{
    unsigned char frame[0x10];
    char *c;
    char *q;
    char *q2;
    int b1, b2;
    int obj1, obj2;
    int idx1, idx2;
    unsigned char ok2;

    c = *(char **)(p + 0x110);
    q = *(char **)(p + 0x114);
    *(int *)(p + 0x2B0) = *(char *)(c + 0x18C);
    if (q == 0) return 0;
    idx1 = *(char *)(c + 0xBE);
    if (idx1 < 0) return 0;
    *(int *)frame = b1 = *(unsigned char *)(q + 0x2B4);
    if (idx1 < b1) obj1 = *(int *)(*(int *)(q + 0x278) + idx1 * 4); else obj1 = 0;
    if (obj1 == 0) return 0;
    q2 = *(char **)(p + 0x114);
    idx2 = *(int *)(p + 0x2B0);
    ok2 = ((*(int *)frame = b2 = *(unsigned char *)(q2 + 0x2B4)), (idx2 >= 0 && idx2 < b2));
    if (ok2) obj2 = *(int *)(*(int *)(q2 + 0x278) + idx2 * 4); else obj2 = 0;
    return obj2 != 0;
}

__attribute__((section(".text.func_001B54E8")))
void func_001B54E8(char *p)
{
    unsigned char frame[0x10];
    int obj;
    long fl;
    int t;
    float d;

    fl = *(unsigned int *)(p + 0x600);
    if (((fl >> 4) & 1) == 0) {
        return;
    }
    t = *(short *)(p + 0x644);
    if (t == 0) {
        cOmBase_setMeshColorFromLayer(p, 0, 1.0f, 1.0f, 1.0f);
        *(int *)(p + 0x600) = *(int *)(p + 0x600) & -0x11;
    } else {
        d = 0.10471976f;
        t = *(unsigned short *)(p + 0x644);
        if (t & 1) {
            d = -d;
        }
        obj = GetLayerObj(p, (int *)frame, 0);
        *(float *)(obj + 0x104) = *(float *)(obj + 0x104) + d;
        *(unsigned short *)(p + 0x644) = *(unsigned short *)(p + 0x644) - 1;
    }
}

__attribute__((section(".text.func_001CFD60")))
void func_001CFD60(char *p, int a1)
{
    unsigned char frame[0x10];
    char *m;
    float *d;
    char *e;
    float f;

    m = *(char **)(p + 0x600);
    if (m != 0) {
        m = *(char **)(m + 0xF0);
        d = (float *)(p + 0x490);
        if (d != (float *)m) { d[0] = ((float *)m)[0]; d[1] = ((float *)m)[1]; d[2] = ((float *)m)[2]; }
    }
    *(float *)(p + 0x24C) = 1.0f;
    *(int *)(p + 0x250) = *(int *)(p + 0x250) & 0xFFFFFFEF;
    *(int *)(p + 0x600) = 0;
    *(int *)(p + 0x630) = 0;
    e = (char *)GetLayerObj(p, (int *)frame, 0);
    if (e != 0) {
        *(int *)(e + 0x148) = (int)p;
        *(int *)(e + 0x100) = 0;
        *(int *)(e + 0x104) = 0;
        *(int *)(e + 0x108) = 0;
        cModel_calcParts(p);
        *(int *)(p + 0x690) = a1;
        *(int *)(p + 0x6A0) = 0;
        *(float *)(p + 0x6A4) = fRand0_1() * 2.0f + 2.0f;
        *(float *)(p + 0x6A8) = fRand0_1() * 2.0f + 7.0f;
        f = DoubleFloatMinusHalf_31D020();
        *(unsigned char *)(p + 0x2F5) = 0xC;
        *(unsigned char *)(p + 0x2F7) = 0;
        *(unsigned char *)(p + 0x2F4) = 0;
        *(unsigned char *)(p + 0x2F6) = 0;
        *(float *)(p + 0x694) = f * 3.14159274f;
    }
}
