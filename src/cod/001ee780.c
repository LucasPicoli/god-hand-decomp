/* sn-2.95.3-136 matched TU. */

extern void *CreateObj(int a0, int a1);
extern void cOmBase_setTexChange(void *a0, int a1);
extern float frand(float a0, float a1);
extern int Forward30F348_31CFE0(void);

/* sn-2.95.3-136 matched TU. */






typedef struct { int a[9]; } T36;

__attribute__((section(".text.func_001EE780")))
int func_001EE780(char *s0, unsigned char n, char *s2) {
    char *obj;
    char *vt;
    int (*fp)();
    float r;
    unsigned int rem;
    char *p;
    unsigned int m;

    obj = (char *)CreateObj(0x371, 0xFFFF);
    *(char **)s0 = obj;
    if (obj == 0) {
        return 0;
    }
    vt = *(char **)(obj + 0x214);
    fp = *(int (**)())(vt + 0x44);
    fp(obj + *(short *)(vt + 0x40));
    m = n;
    s0[4] = n;
    switch (m & 0xFF) {
    case 0:
    default:
        p = *(char **)s0;
        if (p != 0) {
            cOmBase_setTexChange(p, 1);
        }
        break;
    case 1:
        p = *(char **)s0;
        if (p != 0) {
            cOmBase_setTexChange(p, 2);
        }
        break;
    case 2:
        p = *(char **)s0;
        if (p != 0) {
            cOmBase_setTexChange(p, 3);
        }
        break;
    case 3:
        p = *(char **)s0;
        if (p != 0) {
            cOmBase_setTexChange(p, 0);
        }
        break;
    case 4:
        break;
    }
    *(T36 *)(s0 + 8) = *(T36 *)s2;
    r = frand(*(float *)(s0 + 0x24), *(float *)(s0 + 0x28));
    *(float *)(s0 + 0x3C) = r;
    *(float *)(s0 + 0x10) = *(float *)(s0 + 0x10) * r;
    *(float *)(s0 + 0x18) = *(float *)(s0 + 0x18) * r;
    rem = (unsigned int)Forward30F348_31CFE0() % 100;
    if (*(unsigned int *)(s0 + 0x20) >= rem) {
        *(float *)(s0 + 0x1C) = frand(-43.0f, -25.0f);
    }
    *(int *)(s0 + 0x2C) = 11;
    *(int *)(s0 + 0x30) = 0;
    *(int *)(s0 + 0x38) = (int)(*(float *)(s0 + 0x10) * 100.0f)
                        - *(int *)(s0 + 0xC) * 10
                        + (int)(*(float *)(s0 + 0x14) * 10.0f)
                        + (int)(*(float *)(s0 + 0x18) * 100.0f);
    return 1;
}
