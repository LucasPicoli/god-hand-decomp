/* ee-2.9-991111 matched TU. */

extern char D_00569B80[];
extern char D_0056C380[];

__attribute__((section(".text.func_001FE1E0")))
char *func_001FE1E0(char *base) {
    char *p = base;
    char *end = base + 0x3C00;

    for (;;) {
        if (*(unsigned char *)(p + 0x4A) == 0) {
            return p;
        }
        p += 0x60;
        if (!(p < end)) {
            break;
        }
    }
    do {
    } while (0);
    return base + 0xAC00;
}

__attribute__((section(".text.func_001FE5A8")))
char *func_001FE5A8(void) {
    char *p = D_00569B80;
    unsigned int i = 0;

    do {
        if (*(unsigned char *)(p + 0x2E) == 0) {
            return p;
        }
        i++;
        p += 0x40;
    } while (i < 0xA0);
    return 0;
}

__attribute__((section(".text.func_001FE660")))
char *func_001FE660(void) {
    char *p = D_0056C380;
    unsigned int i = 0;

    do {
        if (*(unsigned char *)(p + 0x2E) == 0) {
            return p;
        }
        i++;
        p += 0x40;
    } while (i < 0x200);
    return 0;
}

__attribute__((section(".text.func_00283378")))
void func_00283378(int a0,unsigned char a1){switch(a1){case 0:*(unsigned char*)(a0+0x2F4)=0;*(unsigned char*)(a0+0x2F5)=0xC;*(unsigned char*)(a0+0x2F6)=0;*(unsigned char*)(a0+0x2F7)=0;break;case 1:*(unsigned char*)(a0+0x2F4)=0;*(unsigned char*)(a0+0x2F5)=0xC;*(unsigned char*)(a0+0x2F6)=2;*(unsigned char*)(a0+0x2F7)=0;break;default:*(unsigned char*)(a0+0x2F4)=0;*(unsigned char*)(a0+0x2F5)=0xC;*(unsigned char*)(a0+0x2F6)=0;*(unsigned char*)(a0+0x2F7)=0;break;}}

__attribute__((section(".text.func_00295660")))
char *func_00295660(char *base) {
    char *q = base + 0x10;
    char *f = base + 0x23;
    unsigned int i = 0;

    do {
        if (*(unsigned char *)f == 0) {
            return q;
        }
        i++;
        q += 0x18;
        f += 0x18;
    } while (i < 2);
    return 0;
}

__attribute__((section(".text.func_002A9648")))
char *func_002A9648(void *unused, char *p, unsigned int n) {
    char *h = p - 0x20;
    unsigned int sz = n + 0x20;
    unsigned int cur = *(unsigned int *)(h + 0x10);

    if (cur < sz) {
        return 0;
    }
    *(unsigned int *)(h + 0x10) = sz;
    *(char **)(h + 0xC) = *(char **)(h + 0xC) + (cur - sz);
    return p;
}

__attribute__((section(".text.func_002B4FE8")))
char *func_002B4FE8(char *base, int key) {
    char *p = base + 0x1C;
    char *q = base + 0x1C;
    int i = 0;

    do {
        if (*(int *)p == key) {
            return q;
        }
        i++;
        q += 8;
        p += 8;
    } while (i < 0x40);
    return 0;
}

__attribute__((section(".text.func_002C9060")))
int func_002C9060(int a0,unsigned int a1){int p=*(int*)a0;if(p==0)return 0;{unsigned int n=*(unsigned int*)(a0+0xC);if(n==0)return 0;if(a1<n)return p+a1*0x24;return 0;}}

__attribute__((section(".text.func_002CD8F8")))
char *func_002CD8F8(char *self, int key) {
    char *p = *(char **)(self + 0x380) + 0x1C;
    int i = 1;

    do {
        if (*(int *)(p + 0x14) == key) {
            return p;
        }
        i++;
        p += 0x1C;
    } while (i < 0x20);
    return 0;
}

__attribute__((section(".text.func_002CD930")))
char *func_002CD930(char *self) {
    char *p = *(char **)(self + 0x380) + 0x1C;
    int i = 1;

    do {
        if (*(int *)(p + 0x14) == 0) {
            return p;
        }
        i++;
        p += 0x1C;
    } while (i < 0x20);
    return 0;
}

__attribute__((section(".text.func_00306F88")))
char *func_00306F88(char *base) {
    char *p = base;
    char *end = base + 0x300;

    for (;;) {
        if (*(unsigned char *)(p + 0x8) == 0) {
            *(unsigned char *)(p + 0x8) = 1;
            return p;
        }
        p += 0x18;
        if (!(p < end)) {
            return 0;
        }
    }
}

__attribute__((section(".text.func_003078E0")))
int func_003078E0(unsigned int a) {
    int t;

    if (a == 0) {
        return -1;
    }
    t = a & 0xFF00;
    if (t == 0x500) {
        return -1;
    }
    if (t < 0x601) {
        return a | 0x40000000;
    }
    return -1;
}
