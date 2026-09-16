/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 */
typedef struct Vec { float x, y, z, w; } Vec;

typedef struct P {
    char pad0[0x17D4];
    int **h1[5];              /* 0x17D4 */
    int **h2[5];              /* 0x17E8 */
    unsigned short n1;        /* 0x17FC */
    unsigned short n2;        /* 0x17FE */
    int f1800;
    int f1804;
    int state;                /* 0x1808 */
    int timer;                /* 0x180C */
    int f1810;
    int f1814;
} P;

extern void func_001D6D20(P *, int);
extern void SetLinkedObjField2B_1D6D68(P *, int);
extern void CustomIDWork_SetNumber_1D5760(P *, int);
extern int  cSnd_SeCall_2CBA48(void *, int, int, int, int, int, int, int);
extern void func_001D6030(P *, int);
extern void func_001D60F8(P *, int);
extern void func_001D61C0(P *, int);
extern void func_001D5C38(P *, int);
extern void func_001D5D20(P *, int);
extern void func_001D5E08(P *, int);
extern void func_001D5F50(P *, int);

extern char D_005FEE00[];
extern Vec  D_005680F0[];
extern Vec  D_00568080[];

__attribute__((section(".text.func_001D4258")))
void func_001D4258(P *p)
{
    float r;
    float k;
    int i;

    switch (p->state) {
    case 0:
        func_001D6D20(p, 0);
        SetLinkedObjField2B_1D6D68(p, 0);
        p->f1814 = 0;
        CustomIDWork_SetNumber_1D5760(p, 0);
        p->timer = 0x14;
        cSnd_SeCall_2CBA48(D_005FEE00, 2, 0, *(int *)p->h1[0], 0, 0, 0, 0);
        p->state++;
    case 1:
        k = -1.0f;
        r = (20.0f - (float)p->timer) / 20.0f;
        i = 0;
        if (p->n1 != 0) {
            float s = -r;
            Vec *t = D_005680F0;
            int ***q = &p->h1[0];
            do {
                int **o = *q;
                i++;
                q++;
                *(float *)((int *)(*o)[0x3C]) = s + t->x;
                t++;
            } while (i < p->n1);
        }
        i = 0;
        if (p->n2 != 0) {
            float s = r * k;
            Vec *t = D_00568080;
            int ***q = &p->h2[0];
            do {
                int **o = *q;
                i++;
                q++;
                *(float *)((int *)(*o)[0x3C]) = s + t->x;
                t++;
            } while (i < p->n2);
        }
        if (p->timer != 0) {
            p->timer--;
            break;
        }
        func_001D6030(p, 3);
        func_001D60F8(p, 3);
        func_001D61C0(p, 3);
        p->timer = 0x1E;
        p->state++;
        break;
    case 2:
        if (p->timer != 0) {
            p->timer--;
            break;
        }
        func_001D5C38(p, 2);
        func_001D5D20(p, 2);
        func_001D5E08(p, 2);
        func_001D5F50(p, 2);
        p->timer = 0x1E;
        p->state++;
        break;
    case 3:
        if (p->timer == 0) {
            p->state++;
        } else {
            p->timer--;
        }
        break;
    case 4:
        p->f1804 = 0;
        p->state = 0;
        break;
    }
}
