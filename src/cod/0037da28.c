/* sn-2.95.3-136 matched TU. */

/* sn-2.95.3-136 candidate. */

typedef unsigned int size_t;

typedef struct Rep {
    size_t len;
    size_t res;
    size_t ref;
    int selfish;
} Rep;

typedef struct String {
    char *dat;
} String;

extern char D_003BB168[];   /* basic_string<char>::nilRep */
extern char D_0045C130[];
extern void *D_003F2878[];

extern char *func_003BB058(void *);            /* Rep::clone */
extern void *func_003A52F0(void *, int, int);   /* memset */
extern void *func_0030F550(int);               /* operator new */


__attribute__((section(".text.func_0037DA28")))
char *func_0037DA28(char *self)
{
    int i;
    short *b0;
    short *b1;
    short *b2;
    short *b3;
    short *b4;
    short *b5;

    {
        String *cur = (String *)(self + 0x14);
        for (i = 9; i != -1; --i) {
            Rep *r = (Rep *)D_003BB168;
            char *dat;
            if (r->selfish) {
                dat = func_003BB058(r);
            } else {
                dat = (char *)r + 16;
                r->ref = r->ref + 1;
            }
            cur->dat = dat;
            ++cur;
        }
    }
    {
        Rep *r = (Rep *)D_003BB168;
        String *d = (String *)(self + 0x3C);
        char *dat;
        if (r->selfish) {
            dat = func_003BB058(r);
        } else {
            dat = (char *)r + 16;
            r->ref = r->ref + 1;
        }
        d->dat = dat;
    }
    {
        Rep *r = (Rep *)D_003BB168;
        String *d = (String *)(self + 0x40);
        char *dat;
        if (r->selfish) {
            dat = func_003BB058(r);
        } else {
            dat = (char *)r + 16;
            r->ref = r->ref + 1;
        }
        d->dat = dat;
    }
    {
        Rep *r = (Rep *)D_003BB168;
        String *d = (String *)(self + 0x44);
        char *dat;
        if (r->selfish) {
            dat = func_003BB058(r);
        } else {
            dat = (char *)r + 16;
            r->ref = r->ref + 1;
        }
        d->dat = dat;
    }

    func_003A52F0(self, 0, 0x10);
    *(void **)(self + 0x10) =
        func_00385A68(func_0030F550(0x24), D_0045C130, 4, D_003F2878);
    func_003A52F0(self + 0x48, 0, 0x2D0);
    func_003A52F0(self + 0x318, 0, 0x58);
    func_003A52F0(self + 0x370, 0, 0x100);
    func_003A52F0(self + 0x470, 0, 0x88);

    b0 = (short *)(self + 0x326);
    b1 = (short *)(self + 0x330);
    b2 = (short *)(self + 0x33A);
    b3 = (short *)(self + 0x382);
    b4 = (short *)(self + 0x38C);
    b5 = (short *)(self + 0x396);

    for (i = 0; i < 10; ++i) {
        *(short *)(self + i * 0x48 + 0x4E) = 127;
        *(short *)(self + i * 0x48 + 0x50) = -128;
        *(short *)(self + i * 0x48 + 0x52) = -128;
    }

    *(short *)(self + 0x476) = 127;
    *(short *)(self + 0x478) = -128;
    *(short *)(self + 0x47A) = -128;

    {
        int k;
        for (k = 0; k < 5; ++k) {
            b0[k] = 127;
            b1[k] = -128;
            b2[k] = -128;
            b3[k] = 127;
            b4[k] = -128;
            b5[k] = -128;
        }
    }

    return self;
}
