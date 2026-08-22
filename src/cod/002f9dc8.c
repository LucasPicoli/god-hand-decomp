/* sn-2.95.3-136 matched TU. */

extern void UpdateObjByIndexedOp_2FBE50(void *a0);
extern void cNode_setLocalTranslation(void *self, void *v);
extern void func_002FBED0(void *self);
extern void Tramp_func_0030A548_00147528(void *a, void *b);
extern int D_0076B580[];

/* sn-2.95.3-136 */





__attribute__((section(".text.func_002F9DC8")))
void func_002F9DC8(char *p)
{
    unsigned char frame[0x20] __attribute__((aligned(16)));
    char *o;
    int idx;
    int b;
    int obj;
    unsigned char ok;
    float *v;
    float fa;

    o = *(char **)(p + 0x114);
    if (o == 0) {
        UpdateObjByIndexedOp_2FBE50(p);
        return;
    }
    idx = *(int *)(p + 0x2B4);
    ok = ((*(int *)frame = b = *(unsigned char *)(o + 0x2B4)), (idx >= 0 && idx < b));
    if (ok) obj = *(int *)(*(int *)(o + 0x278) + idx * 4); else obj = 0;
    if (obj == 0) {
        UpdateObjByIndexedOp_2FBE50(p);
        return;
    }
    v = (float *)(frame + 0x10);
    *(float *)(frame + 0x10) = 0.0f;
    *(float *)(frame + 0x14) = 0.0f;
    *(float *)(frame + 0x18) = 0.0f;
    fa = 1.0f;
    v[3] = fa;
    cNode_setLocalTranslation(p, v);
    func_002FBED0(p);
}

__attribute__((section(".text.func_00302988")))
void func_00302988(char *p, char *q) {
    unsigned short t;
    int b;

    *(char **)(p + 0x100) = q;
    *(short *)(p + 0x186) =
        *(unsigned short *)(q + 0xC0) + *(unsigned char *)(p + 0x1ED);
    t = *(unsigned short *)(q + 0xC2);
    *(short *)(p + 0x188) = t;
    if ((short)t > 0) {
        b = *(unsigned char *)(p + 0x1ED);
        *(short *)(p + 0x188) = t + b;
    }
}

/* sn-2.95.3-136 */
__attribute__((section(".text.func_00305BC0")))
void func_00305BC0(char *p)
{
    *(int *)(p + 0x400) = 0;
    *(int *)(p + 0x404) = 0;
    *(unsigned int *)(p + 0x408) = 0xFFFFFFFF;
    *(unsigned int *)(p + 0x40C) = 0xFFFFFFFF;
    *(int *)(p + 0x414) = 0;
}

__attribute__((section(".text.func_003069A8")))
int func_003069A8(int a0,unsigned int a1,int *a2){*a2=0;if(a1>=*(unsigned int*)(a0+4))return 0;{int o=*(int*)(a0+(a1<<2)+0x10);if(o==0)return 0;*a2=a0+o;return 1;}}

/* sn-2.95.3-136 */
__attribute__((section(".text.func_003069E8")))
int func_003069E8(char *p, int n, char **a, char **b)
{
    *a = p + *(int *)(p + 0x4);
    *b = p + *(int *)(p + 0x8);
    return 1;
}

__attribute__((section(".text.func_00306A48")))
int func_00306A48(int a0,unsigned int a1,int *a2){*a2=0;if(a1>=*(unsigned int*)(a0+4))return 0;{int o=*(int*)(a0+(a1<<2)+0x10);if(o==0)return 0;*a2=a0+o;return 1;}}

__attribute__((section(".text.func_00306AA8")))
void func_00306AA8(int a0){unsigned int i;int *p=(int*)(a0+0x100);for(i=0;i<0x4E2;i++){*p=0;p++;}{int *q=(int*)a0;unsigned int j;for(j=0;j<0x40;j++){*q=0;q++;}}}

__attribute__((section(".text.func_003089F0")))
int func_003089F0(int a0,int a1){int i;for(i=0;i<0x20;i++){int v=*(int*)a0;if(v==a1)return 1;if(v==0){*(int*)a0=a1;return 1;}a0+=4;}return 0;}

__attribute__((section(".text.func_00308D68")))
int func_00308D68(int a0,int a1){int i;for(i=0;i<0x20;i++){int v=*(int*)a0;if(v==0)return 0;if(v==a1)return 1;a0+=4;}return 0;}

/* sn-2.95.3-136 matched TU. */



__attribute__((section(".text.func_00318700")))
void func_00318700(char *this, char *other) {
    int i;
    char *a;
    char *b;

    b = *(char **)(other + 0x144);
    a = *(char **)(this + 0x144);
    for (i = 0; i < *(unsigned char *)(this + 0x2B4); i++) {
        Tramp_func_0030A548_00147528(a, b);
        *(int *)(a + 0x154) |= 8;
        a = *(char **)(a + 0x144);
        b = *(char **)(b + 0x144);
    }
}

__attribute__((section(".text.func_003754A8")))
void func_003754A8(int a0){*(int*)(a0+0xA8)=D_0076B580[0];*(int*)(a0+0xAC)=D_0076B580[1];*(int*)(a0+0xB0)=D_0076B580[2];*(int*)(a0+0xB4)=D_0076B580[3];*(int*)(a0+0xB8)=D_0076B580[4];*(int*)(a0+0xBC)=D_0076B580[5];*(int*)(a0+0xC0)=D_0076B580[6];}

__attribute__((section(".text.func_003761D0")))
void func_003761D0(char *p) {
    char *q = p + 0x40;
    int i;
    for (i = 0; i < 8; i++) {
        *(short *)(q + 0x2) = i;
        *(short *)(q + 0x0) = 0;
        *(int *)(q + 0x4) = 0;
        *(short *)(q + 0x12) = 0;
        q += 0x14;
    }
}

__attribute__((section(".text.func_003780B0")))
short func_003780B0(short a0,short a1){int t=a0;int u=t<<8;if(t==0x80)u=0x7FFF;return (short)((u*(int)a1)/0x7F00);}

__attribute__((section(".text.func_0037C5C8")))
void func_0037C5C8(char *a, char *b, unsigned short m) {
    if (m == 2) {
        *(short *)(a + 0x3A) = *(unsigned short *)(b + 0x32);
    } else {
        *(short *)(a + 0x38) = *(unsigned short *)(b + 0x30);
    }
    *(unsigned short *)(a + 0x6) |= 9;
}
