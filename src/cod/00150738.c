/* cygnus-2.96 matched TU. */

extern int D_00747A0C;
extern char *D_005FEE00[];
extern void func_002D5AD8(void);
extern char D_00468CF0[];
extern unsigned char D_003D9DD0[];
extern int D_003D9DD4;

/* cygnus-2.96 */
__attribute__((section(".text.CasinoWork_SetWarmUpRoom")))
void CasinoWork_SetWarmUpRoom(char *p, int a, short b, short c, float f)
{
    *(int *)(p + 0x4) = a;
    *(float *)(p + 0x8) = f;
    *(short *)(p + 0xC) = b;
    *(short *)(p + 0xE) = c;
    *(int *)(p + 0x0) |= 1;
}

/* cygnus-2.96 */
__attribute__((section(".text.cCoreSave_setGameDifficulty")))
void cCoreSave_setGameDifficulty(char *p, int d)
{
    char *q = *(char **)p;

    if (q != 0) {
        if ((unsigned int)d < 3) {
            *(unsigned char *)(q + 0x1F) = d;
        }
    }
}

/* cygnus-2.96 */
__attribute__((section(".text.cObjSimple_SetPackIndex")))
void cObjSimple_SetPackIndex(char *p, int i)
{
    if (i >= 0) {
        *(int *)(p + 0x4D4) = i;
        *(unsigned char *)(p + 0x4D0) = 1;
    }
}

/* cygnus-2.96 */
__attribute__((section(".text.cOl40_setVitalMax")))
void cOl40_setVitalMax(char *p, int v)
{
    *(short *)(p + 0x62C) = v;
    *(short *)(p + 0x61E) = v;
    *(short *)(p + 0x62E) = v;
    *(short *)(p + 0x620) = v;
    *(short *)(p + 0x630) = v;
    *(short *)(p + 0x622) = v;
    *(short *)(p + 0x632) = v;
    *(short *)(p + 0x624) = v;
}

/* cygnus-2.96 */
__attribute__((section(".text.cOm1f_setMoveRange")))
void cOm1f_setMoveRange(char *p, float x, float y, float z, float w)
{
    *(float *)(p + 0xAF8) = x;
    *(float *)(p + 0xAFC) = y;
    *(float *)(p + 0xB00) = z;
    *(float *)(p + 0xB04) = w;
}

/* cygnus-2.96 */
__attribute__((section(".text.cOmb3_SetNextPoint")))
void cOmb3_SetNextPoint(char *p, unsigned short n)
{
    if (n < *(unsigned short *)(p + 0x608)) {
        *(unsigned short *)(p + 0x60A) = n;
    }
}

/* cygnus-2.96 */
__attribute__((section(".text.cSceAtManager_AtDataReset")))
void cSceAtManager_AtDataReset(int n, char *p)
{
    unsigned char v;

    if (p != 0) {
        v = *(unsigned char *)(p + 0x4E);
        if (v != 0) {
            *(unsigned char *)(p + 0x3B) = v;
            *(unsigned char *)(p + 0x4E) = 0;
        }
        *(unsigned char *)(p + 0x44) = 0;
        *(int *)(p + 0x3C) = 0;
    }
}

/* cygnus-2.96 */
__attribute__((section(".text.cSnd_SetBgmLevel")))
void cSnd_SetBgmLevel(char *p, float lv, int a, int b, int c)
{
    *(int *)(p + 0x118) = a;
    *(int *)(p + 0x11C) = b;
    *(int *)(p + 0x120) = c;
    *(float *)(p + 0x124) = lv;
}

__attribute__((section(".text.func_00150738")))
void func_00150738(float *d,float *a,float *b){d[0]=a[0]+b[0];d[1]=a[1]+b[1];d[2]=a[2]+b[2];d[3]=1.0f;}

__attribute__((section(".text.func_00150778")))
void func_00150778(float *d,float *a,float *b){d[0]=a[0]-b[0];d[1]=a[1]-b[1];d[2]=a[2]-b[2];d[3]=1.0f;}

__attribute__((section(".text.func_001F8A88")))
void func_001F8A88(float *o,float a,float b,float c,float d,float e,float f){float hb=(b-a)*0.5f;float hd=(d-c)*0.5f;float hf=(f-e)*0.5f;o[0]=hb+a;o[3]=hb;o[1]=hd+c;o[4]=hd;o[2]=hf+e;o[5]=hf;}

/* cygnus-2.96 */
__attribute__((section(".text.func_0026EB00")))
void func_0026EB00(char *p)
{
    *(int *)(p + 0x24C) = 0;
    *(float *)(p + 0x1704) = 1.0f;
    *(int *)(p + 0x250) |= 0x10;
}

/* cygnus-2.96 */
__attribute__((section(".text.func_002A96C0")))
int func_002A96C0(int a, int b, int c)
{
    int t = a + 7;

    t += c;
    do {
    } while (0);
    t &= -c;
    return t * b;
}

/* cygnus-2.96 */


__attribute__((section(".text.func_002B12D8")))
float func_002B12D8(void)
{
    float r = 26.0f;

    if (D_00747A0C != 0) {
        r = 32.0f;
    }
    return r;
}

/* cygnus-2.96 */
__attribute__((section(".text.func_002B4598")))
void func_002B4598(char *p)
{
    if (*(int *)(p + 0xB8) != 1) {
        *(int *)(p + 0xB8) = 1;
    }
}

/* cygnus-2.96 */
__attribute__((section(".text.func_002C53A8")))
char *func_002C53A8(char *p)
{
    *(int *)(p + 0x0) = 0;
    *(float *)(p + 0x10) = 1.0f;
    *(unsigned char *)(p + 0x4) = 0;
    *(unsigned char *)(p + 0x5) = 0;
    return p;
}

/* cygnus-2.96 */


__attribute__((section(".text.func_002CC5C0")))
void func_002CC5C0(char *p)
{
    *(char **)(p + 0x88) = D_005FEE00[6];
    if (D_005FEE00[6] != 0) {
        *(char **)(D_005FEE00[6] + 0x84) = p;
    }
    D_005FEE00[6] = p;
}

__attribute__((section(".text.func_002CD740")))
void func_002CD740(int a0){*(int*)(*(int*)(a0+0x380)+8)=0;*(int*)(*(int*)(a0+0x380)+4)=0;*(int*)(*(int*)(a0+0x380)+0x18)=0;*(int*)(*(int*)(a0+0x380)+0xC)=*(int*)(a0+0x384);*(int*)(*(int*)(a0+0x380))=a0;*(int*)(*(int*)(a0+0x380)+0x10)=0;*(int*)(*(int*)(a0+0x380)+0x14)=0;}

/* cygnus-2.96 */


__attribute__((section(".text.func_002CE3C0")))
void func_002CE3C0(char *p)
{
    *(char **)(p + 0x4) = D_005FEE00[7];
    if (D_005FEE00[7] != 0) {
        *(char **)(D_005FEE00[7] + 0x0) = p;
    }
    D_005FEE00[7] = p;
}

__attribute__((section(".text.func_002CF2D0")))
char *func_002CF2D0(char *p) {
    *(int *)(p + 0x0) = 0;
    *(int *)(p + 0x4) = 0;
    *(int *)(p + 0x10) = 0;
    *(int *)(p + 0x14) = 0;
    *(int *)(p + 0x18) = 0;
    *(int *)(p + 0x1C) = 0;
    *(int *)(p + 0x20) = 0;
    *(int *)(p + 0x24) = 0;
    *(int *)(p + 0x28) = -1;
    *(int *)(p + 0x3C) = -1;
    return p;
}

__attribute__((section(".text.func_002D5918")))
void func_002D5918(char *p) {
    /* SWEEP-BEGIN */
    *(short *)(p + 0xC) = 2;
    *(void **)(p + 0x24) = (void *)func_002D5AD8;
    *(int *)(p + 0x28) = *(int *)(p + 0x10);
    *(int *)(p + 0x2C) = *(int *)(p + 0x8);
    *(int *)(p + 0x34) = *(unsigned short *)(p + 0x1C);
    *(char **)(p + 0x30) = D_00468CF0;
/* SWEEP-END */
}

/* cygnus-2.96 */
__attribute__((section(".text.func_002D65D0")))
void func_002D65D0(char *p, float *out)
{
    char *q = *(char **)(p + 0x4);

    if (q != 0) {
        if (out != 0) {
            *out = *(float *)(q + 0x6C);
        }
    }
}

/* cygnus-2.96 */
__attribute__((section(".text.func_002DF938")))
void func_002DF938(void *a, char *b)
{
    if (a != 0) {
        if (b != 0) {
            *(void **)(b + 0x58) = a;
        }
    }
}

/* cygnus-2.96 */
__attribute__((section(".text.func_00318440")))
int func_00318440(char *p)
{
    *(int *)(p + 0x254) |= 0x8000000;
    *(int *)(p + 0x4A8) |= 0x10000000;
    return 1;
}

/* cygnus-2.96 */
__attribute__((section(".text.func_00328178")))
int func_00328178(char *p)
{
    if (*(int *)(p + 0x8) == 0) {
        return 0;
    }
    return *(int *)(p + 0x58);
}

/* cygnus-2.96 */
__attribute__((section(".text.func_00328488")))
void func_00328488(char *p, int v)
{
    if (v >= 0) {
        *(int *)(p + 0x30) = v;
    } else {
        *(int *)(p + 0x30) = *(int *)(p + 0x14);
    }
}

__attribute__((section(".text.func_0032F538")))
int func_0032F538(char *p) {
    int n = *(int *)(p + 0x2B0);
    int sum = 0;
    int *q;

    if (n > 0) {
        q = (int *)(p + 0x2BC);
        do {
            sum += *q;
            q += 4;
        } while (--n != 0);
    }
    return sum;
}

__attribute__((section(".text.func_00333438")))
int func_00333438(char c) {
    char r = c;

    if ((unsigned int)(c - 0x61) < 0x1A) {
        r = c - 0x20;
    }
    return (c == 0x5C) ? 0x2F : r;
}

/* cygnus-2.96 */



__attribute__((section(".text.func_00333E68")))
void func_00333E68(int a, int b, int c, int d)
{
    D_003D9DD4 = d;
    D_003D9DD0[0] = a;
    D_003D9DD0[1] = b;
    D_003D9DD0[2] = c;
}

/* cygnus-2.96 */
__attribute__((section(".text.func_00334B38")))
int func_00334B38(char *p)
{
    unsigned long a = (long)*(int *)(p + 0x28) << 11;
    unsigned long b = *(unsigned long *)(p + 0x8);

    if (b < a) {
        a = b;
    }
    return (long)a >> 32;
}

__attribute__((section(".text.func_00340700")))
void func_00340700(int a0){int i;int *p=*(int**)(a0+8);int *q=*(int**)(a0+0xC);for(i=0;i<0x60;i++){p[i]=0;q[i]=0;}*(int*)(a0+0x14)=0;*(int*)(a0+0x18)=0x40;}

__attribute__((section(".text.func_00342958")))
int func_00342958(int *a, int *b, int *c) {
    *a = 0x249E4;
    *b = 0x9C40;
    *c = 0x800;
    return *a + *b + *c;
}

/* cygnus-2.96 */
__attribute__((section(".text.func_00342B78")))
char *func_00342B78(char *p, unsigned int i)
{
    if (i < 0x8C) {
        return 0;
    }
    *(int *)p = 1;
    return p;
}

__attribute__((section(".text.func_00344D50")))
void func_00344D50(int a0,int a1){int t=*(int*)(a1+0x3C);a0+=0x88;*(int*)(a0+0)=*(int*)(a1+0x58);*(int*)(a0+4)=*(int*)(a1+0x5C);*(int*)(a0+8)=*(signed char*)(a1+0x6C);*(int*)(a0+0xC)=*(signed char*)(a1+0x6D);*(int*)(a0+0x10)=*(signed char*)(a1+0x6E);*(int*)(a0+0x14)=t;*(int*)(a0+0x18)=*(int*)(a1+0x40);*(int*)(a0+0x1C)=0;}

__attribute__((section(".text.func_00348210")))
int func_00348210(int *a, int *b, int *c) {
    *a = 0x249E4;
    *b = 0x9C40;
    *c = 0x800;
    return *a + *b + *c;
}
