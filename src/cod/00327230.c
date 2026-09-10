/* cygnus-2.96 matched TU. */

extern void Obj3290_Tramp_0033E678_9028(void);
extern void Obj3290_Tramp_0033E690_9040(void);
extern int Obj33C8_GetField_18(void *sj);

typedef struct SJ SJ;
struct SJVT { char pad[0x24]; int (*f24)(SJ *, int); };
struct SJ { struct SJVT *vt; };
struct STM { char pad0[4]; SJ *f4; char pad8[0x10]; int f18; int f1C;
             char pad20[0x20]; int f40; };




__attribute__((section(".text.ADXSTM_SetSj")))
void ADXSTM_SetSj(struct STM *stm, SJ *sj)
{
    int n;
    stm->f4 = sj;
    Obj3290_Tramp_0033E678_9028();
    n = sj->vt->f24(sj, 0);
    n = n + sj->vt->f24(sj, 1);
    stm->f40 = n;
    Obj3290_Tramp_0033E690_9040();
    stm->f18 = stm->f40;
    stm->f1C = stm->f40;
}

struct SJD { char pad0[4]; void *f4; char pad8[0x24]; int f2C; int f30; int f34; };




__attribute__((section(".text.func_00327230")))
void func_00327230(struct SJD *hn)
{
    void *sj;
    int a, b, c, n;
    sj = hn->f4;
    a = Obj33C8_GetField_18(sj);
    b = func_0033D2B8(sj);
    c = func_0033D2C0(sj);
    n = a - hn->f34;
    if (c < n) n = c;
    hn->f2C = hn->f2C + n;
    hn->f30 = hn->f30 + b;
    hn->f34 = hn->f34 + n;
}
