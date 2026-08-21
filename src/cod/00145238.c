/* sn-2.95.3-136 matched TU. */

extern void func_00145410(void *a0);
extern void func_00145460(void *a0);
extern void func_00145810(void *a0);
extern void func_00145FC8(void *a0);
extern void func_00146190(void *a0);
extern void cIDBase_move(void *a0);
extern void *cIDBase_getIDWork(void *self, int idx);
extern float D_0041E898[];
extern short D_003BD70C;

/* sn-2.95.3-136 matched TU. */











__attribute__((section(".text.func_00145238")))
void func_00145238(char *a0)
{
    char *s3 = a0;
    char *w;
    void *p;
    char *x;
    unsigned short i;
    float a;
    float b;
    int n;

    switch (*(short *)(s3 + 0x41E)) {
    case 0:
        func_00145410(s3);
        break;
    case 1:
        func_00145460(s3);
        break;
    case 2:
        func_00145810(s3);
        break;
    case 3:
        func_00145FC8(s3);
        break;
    case 4:
        func_00146190(s3);
        break;
    }
    for (i = 0; i < 5; i++) {
        cIDBase_move(s3 + (i * 0x50 + 0x100));
    }
    if (*(short *)(s3 + 0x41E) != 2) return;
    n = *(unsigned short *)(s3 + 0x4D0) - 1;
    *(short *)(s3 + 0x4D0) = (short)n;
    if ((short)n < 0) {
        *(short *)(s3 + 0x4D0) = 0;
    }
    w = s3 + 0x430;
    x = s3 + 0x480;
    p = cIDBase_getIDWork(w, 0);
    a = D_0041E898[0];
    *(float *)((char *)p + 0x38) = a;
    p = cIDBase_getIDWork(w, 0);
    b = D_0041E898[1];
    *(float *)((char *)p + 0x3C) = b;
    *(float *)((char *)cIDBase_getIDWork(w, 1) + 0x48) =
        (float)*(short *)(s3 + 0x4D0) * 6.28f / (float)D_003BD70C;
    *(short *)((char *)cIDBase_getIDWork(w, 2) + 0x90) = 0x30F2;
    *(float *)((char *)cIDBase_getIDWork(x, 0) + 0x38) = a;
    *(float *)((char *)cIDBase_getIDWork(x, 0) + 0x3C) = b;
    cIDBase_move(w);
    cIDBase_move(x);
}
