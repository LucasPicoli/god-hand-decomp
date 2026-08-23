/* sn-2.95.3-136 matched TU. */

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_002E6AF8")))
void func_002E6AF8(char *p) {
    char *o;
    o = p;
    if (*(int *)(o + 0x114) != 0) {
        if ((*(int *)(*(int *)(o + 0x114) + 0x250) & 2) != 0) {
            *(int *)(*(int *)(o + 0x2B0) + 0x250) |= 2;
        } else {
            *(unsigned int *)(*(int *)(o + 0x2B0) + 0x250) &= 0xFFFFFFFD;
        }
        if ((*(int *)(*(int *)(o + 0x114) + 0x250) & 0x8000) != 0) {
            *(int *)(*(int *)(o + 0x2B0) + 0x250) |= 0x8000;
        } else {
            *(unsigned int *)(*(int *)(o + 0x2B0) + 0x250) &= 0xFFFF7FFF;
        }
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_002F2758")))
void func_002F2758(char *p) {
    unsigned int *q;
    q = *(unsigned int **)(p + 0x2B0);
    if (q != 0) {
        if (*(int *)(p + 0x114) != 0) {
            if ((*(int *)(*(int *)(p + 0x114) + 0x250) & 2) != 0) {
                *(int *)((char *)q + 0x250) |= 2;
            } else {
                *(unsigned int *)((char *)q + 0x250) &= 0xFFFFFFFDU;
            }
            if ((*(int *)(*(int *)(p + 0x114) + 0x250) & 0x8000) != 0) {
                *(int *)(*(int *)(p + 0x2B0) + 0x250) |= 0x8000;
            } else {
                *(unsigned int *)(*(int *)(p + 0x2B0) + 0x250) &= 0xFFFF7FFFU;
            }
        }
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_00377428")))
void func_00377428(char *a0, char *a1) {
    if (*(unsigned short *)(a1 + 0x1A) & 1) {
        *(unsigned short *)(a0 + 0x5C) = *(unsigned short *)(a1 + 0x44);
        *(unsigned short *)(a0 + 0x10) |= 1;
    }
    if (*(unsigned short *)(a1 + 0x1A) & 2) {
        *(unsigned short *)(a0 + 0x5E) = *(unsigned short *)(a1 + 0x46);
        *(unsigned short *)(a0 + 0x10) |= 1;
    }
    if (*(unsigned short *)(a1 + 0x1A) & 4) {
        *(unsigned short *)(a0 + 0x70) = *(unsigned short *)(a1 + 0x48);
        *(unsigned short *)(a0 + 0x72) = *(unsigned short *)(a1 + 0x4A);
        *(unsigned short *)(a0 + 0x10) |= 2;
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.cEm00_setSitChair")))
void cEm00_setSitChair(void *a0, float *a1, float f12) {
    float *d = (float *)((char *)a0 + 0x490);
    float *v0;
    *(int *)((char *)a0 + 0x16D0) = *(int *)((char *)a0 + 0x16D0) & 0xDFFFFFFF;
    *(int *)((char *)a0 + 0x16EC) = 0;
    if (d != a1) {
        d[0] = a1[0];
        d[1] = a1[1];
        d[2] = a1[2];
    }
    v0 = *(float **)((char *)a0 + 0xF0);
    if (v0 != d) {
        v0[0] = *(float *)((char *)a0 + 0x490);
        v0[1] = d[1];
        v0[2] = d[2];
    }
    *(float *)((char *)a0 + 0x104) = f12;
    *(unsigned char *)((char *)a0 + 0x1650) = 5;
    *(unsigned char *)((char *)a0 + 0x2F5) = 1;
    *(unsigned char *)((char *)a0 + 0x2F4) = 0;
    *(unsigned char *)((char *)a0 + 0x2F6) = 0;
    *(unsigned char *)((char *)a0 + 0x2F7) = 0;
}
