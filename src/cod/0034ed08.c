/* cygnus-2.96 matched TU. */

typedef struct Mv {
    char pad0[0x24];
    int f24;
    int f28;
    int f2C;
    int f30;
    int f34;
} Mv;

typedef struct Sub {
    int f0;
    int f4;
    Mv *f8;
    int fC;
    int f10;
    int f14;
} Sub;

extern int GetArrayElemA0C_35A1C8(void *hn, int id);
extern int sfmps_AutoVchPlay(void *hn, int t);


extern void func_00356928(void *hn, int n);
extern void func_00356C68(void *hn, char *data, int n);

__attribute__((section(".text.func_0034ED08")))
int func_0034ED08(void *hn, int t, char *data, int len, void *ctx)
{
    Sub *sub;
    Mv *mv;
    int vch;
    int cur;
    int r;

    if (GetArrayElemA0C_35A1C8(hn, 5) == 0) return 1;
    sub = (Sub *)((char *)hn + 0x1F74);
    mv = sub->f8;
    if (mv->f34 == -1) {
        mv->f34 = sfmps_AutoVchPlay(hn, t);
    }
    if (mv->f2C == -1) {
        mv->f2C = t;
    }
    vch = GetArrayElemA0C_35A1C8(hn, 0x1D);
    if (vch != -1) {
        if (GetArrayElemA0C_35A1C8(hn, 0x37) != 0) {
            cur = mv->f34;
            if (t >= mv->f24) goto store;
        } else {
            cur = mv->f34;
            if (t != mv->f2C) goto store;
        }
        if (cur != vch && len >= 4 && data[0] == 0 && data[1] == 0
            && (unsigned char)data[2] == 1
            && ((unsigned char)data[3] == 0xB3 || (unsigned char)data[3] == 0xB8)) {
            mv->f34 = vch;
            cur = vch;
        }
    } else {
        cur = mv->f34;
    }
store:
    mv->f24 = t;
    if (cur != t) return 1;
    len = func_003568B8(hn, data, len);
    if (len <= 0) return 0;
    r = func_0034F200(hn, sub->f14, data, len, ctx);
    if (r != 1) {
        func_00356928(hn, len);
    } else {
        func_00356C68(hn, data, len);
    }
    return r;
}
