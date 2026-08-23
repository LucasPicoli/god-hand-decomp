/* sn-2.95.3-136 matched TU. */

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_001AE630")))
int func_001AE630(char *o) {
    char *p;
    char *q;
    int n;
    int f;
    int g;
    n = 0;
    p = *(char **)(o + 0x604);
    if (p == 0) goto one;
    f = *(int *)(p + 0x9D0);
    if (f < 0) goto one;
    if (f & 0x40000000) return 1;
    goto next;
one:
    n = 1;
next:
    q = *(char **)(o + 0x608);
    if (q == 0) n++;
    else {
        g = *(int *)(q + 0x9D0);
        if (g < 0) n++;
        else if (g & 0x40000000) return 1;
    }
    return n >= 2;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_00381E30")))
void func_00381E30(char *o, char *e) {
    char *c;
    c = o + 0x348;
    o = o + 0x318;
    if (*(int *)(c + 8) <= 0) return;
    if (*(int *)(e + 0x38) & 4) {
        if (*(unsigned char *)(o + 2) == 0) *(unsigned char *)(o + 2) = *(int *)(c + 8);
        else *(unsigned char *)(o + 2) = *(unsigned char *)(o + 2) - 1;
    }
    if (*(int *)(e + 0x38) & 8) {
        if (*(unsigned char *)(o + 2) < *(int *)(c + 8)) *(unsigned char *)(o + 2) = *(unsigned char *)(o + 2) + 1;
        else *(unsigned char *)(o + 2) = 0;
    }
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_002B2B08")))
int func_002B2B08(char *p) {
    unsigned short v;
    *(unsigned char *)(p + 0x70) = 2;
    *(unsigned char *)(p + 0xA4) = 3;
    *(int *)(p + 0x18) = 0;
    *(unsigned char *)(p + 0x3C) = 0;
    v = *(unsigned short *)(*(char **)(p + 0x8C) + 0x2);
    if (v != 0xFFFF) *(unsigned short *)(p + 0x62) = v;
    else *(unsigned short *)(p + 0x62) = 0;
    v = *(unsigned short *)(*(char **)(p + 0x8C) + 0x4);
    if (v == 0xFFFF) *(unsigned short *)(p + 0xA6) = 0x100;
    else *(unsigned short *)(p + 0xA6) = v;
    v = *(unsigned short *)(*(char **)(p + 0x8C) + 0x6);
    if (v == 0xFFFF) *(unsigned short *)(p + 0xA8) = 0xE0;
    else *(unsigned short *)(p + 0xA8) = v;
    return 0;
}

/* compiler: sn-2.95.3-136 ; extra keys: none */
__attribute__((section(".text.func_002D93E8")))
unsigned int func_002D93E8(char *base) {
    unsigned int id;
    int n;
    int i;
    int free;
    n = *(int *)(base + 0x78);
    id = 0xFFFF;
    do {
        free = 1;
        for (i = 0; i < n; i++) {
            if (*(unsigned short *)(base + i * 0x70 + 0x82) == id) { free = 0; break; }
        }
        if (free) break;
        id = (id - 1) & 0xFFFF;
    } while (id != 0);
    return id;
}

__attribute__((section(".text.func_001D48B0")))
int func_001D48B0(char *p)
{
    char *a;
    char *b;
    int va;
    int vb;

    if (*(unsigned short *)(p + 0x17FC) != 2) {
        return 0;
    }
    a = *(char **)(*(char **)(p + 0x17D4));
    b = *(char **)(*(char **)(p + 0x17D8));
    va = *(int *)(a + 0x604);
    vb = *(int *)(b + 0x604);
    if (va == 0) {
        if ((unsigned int)(vb - 9) < 4) {
            goto ret1;
        }
    }
    if (vb != 0) {
        goto ret0;
    }
    if ((unsigned int)(va - 9) >= 4) {
        goto ret0;
    }
ret1:
    return 1;
ret0:
    return 0;
}
