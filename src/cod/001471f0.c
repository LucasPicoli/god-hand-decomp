/* sn-2.95.3-136 matched TU. */

extern void cIDBase_restartAnim(void *a0);
extern void cIDBase_move(void *a0);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001471F0")))
void func_001471F0(char *s0) {
    char st;

    if (*(int *)(s0 + 0xB0) != 0) {
        st = *(unsigned char *)(s0 + 0xB8) - 1;
        switch (st) {
        case 0:
            cIDBase_restartAnim(s0);
            s0[0x1C] = 1;
            s0[0xB8] = 2;
        case 1:
            {
            char *p1 = *(char **)(s0 + 0x90);
            char *p2;
            char *p3;
            char *q;
            *(float *)(p1 + 0x40) = *(float *)(p1 + 0x40) + 0.1f;
            p2 = *(char **)(s0 + 0x90);
            *(float *)(p2 + 0x44) = *(float *)(p2 + 0x44) + 0.1f;
            p3 = *(char **)(s0 + 0x90);
            q = *(char **)(p3 + 0x1C);
            if (*(float *)(q + 0x28) < *(float *)(p3 + 0x40)) {
                char *r;
                char *rq;
                char *t1;
                char *t2;
                *(float *)(p3 + 0x40) = *(float *)(q + 0x28);
                r = *(char **)(s0 + 0x90);
                rq = *(char **)(r + 0x1C);
                *(float *)(r + 0x44) = *(float *)(rq + 0x2C);
                t1 = *(char **)(s0 + 0x94);
                *(unsigned short *)(t1 + 0x90) = *(unsigned short *)(s0 + 0xAC);
                t2 = *(char **)(s0 + 0x98);
                *(unsigned short *)(t2 + 0x90) = *(unsigned short *)(s0 + 0xAC);
                s0[0xB8] = 3;
            }
            }
            break;
        case 2:
            {
            char *a = *(char **)(s0 + 0x94);
            char *b;
            *(int *)(a + 0x2C) = *(int *)(a + 0x2C) & 0xF7FFFFFFU;
            b = *(char **)(s0 + 0x98);
            *(int *)(b + 0x2C) = *(int *)(b + 0x2C) & 0xF7FFFFFFU;
            switch (*(unsigned short *)(s0 + 0xAC)) {
            case 0x2000:
                *(short *)(*(char **)(s0 + 0x9C) + 0x90) = 0x2006;
                *(short *)(*(char **)(s0 + 0xA0) + 0x90) = 0x2006;
                *(int *)(*(char **)(s0 + 0xA4) + 0x2C) =
                    *(int *)(*(char **)(s0 + 0xA4) + 0x2C) & 0xF7FFFFFFU;
                break;
            case 0x2001:
                *(short *)(*(char **)(s0 + 0x9C) + 0x90) = 0x2007;
                *(short *)(*(char **)(s0 + 0xA0) + 0x90) = 0x2007;
                break;
            case 0x2002:
                *(short *)(*(char **)(s0 + 0x9C) + 0x90) = 0x2008;
                *(short *)(*(char **)(s0 + 0xA0) + 0x90) = 0x2008;
                break;
            case 0x2003:
                *(short *)(*(char **)(s0 + 0x9C) + 0x90) = 0x2009;
                *(short *)(*(char **)(s0 + 0xA0) + 0x90) = 0x2009;
                break;
            case 0x2004:
                *(short *)(*(char **)(s0 + 0x9C) + 0x90) = 0x200A;
                *(short *)(*(char **)(s0 + 0xA0) + 0x90) = 0x200A;
                *(int *)(*(char **)(s0 + 0xA8) + 0x2C) =
                    *(int *)(*(char **)(s0 + 0xA8) + 0x2C) & 0xF7FFFFFFU;
                break;
            case 0x2005:
                *(short *)(*(char **)(s0 + 0x9C) + 0x90) = 0x200B;
                *(short *)(*(char **)(s0 + 0xA0) + 0x90) = 0x200B;
                break;
            }
            }
            break;
        case 3:
            {
            char *c = *(char **)(s0 + 0x94);
            char *d;
            char *e1;
            char *e2;
            char *e3;
            *(int *)(c + 0x2C) = *(int *)(c + 0x2C) | 0x8000000;
            d = *(char **)(s0 + 0x98);
            *(int *)(d + 0x2C) = *(int *)(d + 0x2C) | 0x8000000;
            e1 = *(char **)(s0 + 0x90);
            *(float *)(e1 + 0x40) = *(float *)(e1 + 0x40) - 0.1f;
            e2 = *(char **)(s0 + 0x90);
            *(float *)(e2 + 0x44) = *(float *)(e2 + 0x44) - 0.1f;
            e3 = *(char **)(s0 + 0x90);
            if (*(float *)(e3 + 0x40) < 0.0f) {
                char *f1;
                *(float *)(e3 + 0x40) = 0.0f;
                f1 = *(char **)(s0 + 0x90);
                *(float *)(f1 + 0x44) = 0.0f;
                s0[0xB8] = 5;
            }
            }
            break;
        case 4:
            s0[0xB8] = 0;
            *(unsigned short *)(s0 + 0xAC) = 0xFFFF;
            break;
        }
        cIDBase_move(s0);
    }
}
