/* sn-2.95.3-136 matched TU. */

typedef struct {
    char pad0[0x80];
    char *parts[64];
} Owner;

typedef struct {
    float f[10];
} TblEnt;

typedef struct {
    TblEnt a[5];
    float b[8];
} Tbl;


extern char D_005FEC58[];
extern Tbl D_0041F250;
extern int D_00747A0C;
extern void cCamera_reset(void *self);
extern void ClearFields_1614D0(void *self);
extern void EmClothInit(int id, void *self, void *data, void *anchor);
extern void EmClothMove(int id, void *self, void *data, void *anchor);
extern void Obj0000_Clear_Fields_50_To_7C_13C5C8(void *self);
extern void SetCustomIDDispOneOrAll_1F4778(void *self, int id, int on);
extern void func_002949C8(void *self);
extern void func_002B4528(void *self, int value);
extern void func_002D5918(void *self);
extern void func_002D5990(void *self);
extern int snDllLoaded(void *value, int mode);
extern int SetEffect(
    int effect, int resource, void *owner, int arg3,
    int arg4, unsigned int arg5);

__attribute__((section(".text.func_0031AF70")))
int func_0031AF70(int value)
{
    value <<= 24;
    value -= 0x80000000;
    value >>= 24;
    if (value < 0) {
        if (value >= -63)
            value = 0;
    } else if (value <= 63) {
        value = 0;
    }
    return value;
}

__attribute__((section(".text.func_00294998")))
int func_00294998(char *self)
{
    if (*(signed char *)(self + 0x53E) == 0)
        return 0;
    func_002949C8(self);
    return 1;
}

__attribute__((section(".text.func_0016FE68")))
void func_0016FE68(void *owner)
{
    SetEffect(1, 3, owner, 0, -1, 0xFFFFFFFFU);
}

__attribute__((section(".text.func_00170150")))
void func_00170150(void *owner)
{
    SetEffect(1, 4, owner, 0, -1, 0xFFFFFFFFU);
}

__attribute__((section(".text.func_00170438")))
void func_00170438(void *owner)
{
    SetEffect(1, 5, owner, 0, -1, 0xFFFFFFFFU);
}

__attribute__((section(".text.func_002714E8")))
void func_002714E8(char *self)
{
    void *data = *(void **)(self + 0x1860);
    if (data != 0)
        EmClothMove(*(int *)(self + 0x564), self, data, self + 0x17E0);
}

__attribute__((section(".text.func_0028CEA8")))
void func_0028CEA8(char *self)
{
    void *data = *(void **)(self + 0x1630);
    if (data != 0)
        EmClothMove(*(int *)(self + 0x564), self, data, self + 0x15B0);
}

__attribute__((section(".text.func_0027EDC8")))
void func_0027EDC8(char *self)
{
    EmClothInit(
        *(int *)(self + 0x564), self, self + 0x1630, self + 0x15B0);
}

__attribute__((section(".text.func_0027EDF0")))
void func_0027EDF0(char *self)
{
    EmClothMove(
        *(int *)(self + 0x564), self, self + 0x1630, self + 0x15B0);
}

__attribute__((section(".text.func_00139090")))
void func_00139090(char *self)
{
    cCamera_reset(self);
    *(int *)(self + 0x1C0) = 0;
}

__attribute__((section(".text.func_00146EF0")))
void func_00146EF0(char *self)
{
    Obj0000_Clear_Fields_50_To_7C_13C5C8(self);
    self[0x90] = 0;
}

__attribute__((section(".text.func_0016C238")))
void func_0016C238(char *self)
{
    ClearFields_1614D0(self);
    *(int *)(self + 0x264) = 0;
}

__attribute__((section(".text.func_001F5278")))
void func_001F5278(void *self, unsigned short value, int on)
{
    if (value < 7) {
        SetCustomIDDispOneOrAll_1F4778(self, value + 0x49, on);
    }
}

__attribute__((section(".text.func_002D5890")))
void func_002D5890(char *self, int value)
{
    *(int *)(self + 0x14) = value;
    *(short *)(self + 0x1E) = 0;
    func_002D5918(self);
}

__attribute__((section(".text.func_002D5958")))
void func_002D5958(char *self, int value)
{
    *(int *)(self + 0x14) = value;
    *(short *)(self + 0x1E) = 0;
    func_002D5990(self);
}

__attribute__((section(".text.func_002B3050")))
int func_002B3050(char *self)
{
    func_002B4528(self, *(int *)(self + 0x8C) + 2);
    return 0;
}

__attribute__((section(".text.func_002BE6A0")))
int func_002BE6A0(void **self)
{
    return snDllLoaded(*self, 0) == 0;
}

__attribute__((section(".text.func_001627A0")))
void func_001627A0(char *self)
{
    ClearFields_1614D0(self);
    self[0x5A] = 0;
    self[0x5B] = 0;
    self[0x5C] = 0;
    self[0x5D] = 0;
}

__attribute__((section(".text.func_00168528")))
void func_00168528(char *self)
{
    ClearFields_1614D0(self);
    self[0x5A] = 0;
    self[0x5B] = 0;
    self[0x5C] = 0;
    self[0x5D] = 0;
}

__attribute__((section(".text.func_0016F608")))
void func_0016F608(char *self)
{
    int resource = *(int *)(self + 0x5EC);
    if (resource != 0) {
        SetEffect(
            *(int *)(self + 0x5F0), resource, self, 0,
            -1, 0xFFFFFFFFU);
    }
}

__attribute__((section(".text.func_0016F900")))
void func_0016F900(char *self)
{
    int resource = *(int *)(self + 0x5EC);
    if (resource != 0) {
        SetEffect(
            *(int *)(self + 0x5F0), resource, self, 0,
            -1, 0xFFFFFFFFU);
    }
}

__attribute__((section(".text.func_0016FBF8")))
void func_0016FBF8(char *self)
{
    int resource = *(int *)(self + 0x5EC);
    if (resource != 0) {
        SetEffect(
            *(int *)(self + 0x5F0), resource, self, 0,
            -1, 0xFFFFFFFFU);
    }
}

__attribute__((section(".text.func_002D58B8")))
void func_002D58B8(char *self, int arg1, int arg2)
{
    *(short *)(self + 0x1E) = 1;
    *(int *)(self + 0x14) = arg1;
    *(int *)(self + 0x18) = arg2;
    func_002D5918(self);
}

__attribute__((section(".text.func_002D58E8")))
void func_002D58E8(char *self, int arg1, int arg2)
{
    *(short *)(self + 0x1E) = 1;
    *(int *)(self + 0x14) = arg1;
    *(int *)(self + 0x18) = arg2;
    func_002D5918(self);
}

#define PART(bit, idv, k)                                                   \
    if ((*(int *)(t + 0xC) & (bit)) && n < 2) {                             \
        *(short *)(s->parts[n + 0x2B] + 0x90) = (idv);                      \
        *(float *)(s->parts[n + 0x2B] + 0x40) = D_0041F250.a[D_00747A0C].f[k]; \
        *(int *)(s->parts[n + 0x29] + 0x2C) &= ~0x8000000;                  \
        n++;                                                                \
    }

__attribute__((section(".text.func_0016EE10")))
void func_0016EE10(Owner *s, unsigned short a1)
{
    unsigned char n = 0;
    char *t;

    t = func_002C9060(D_005FEC58, a1);
    if (t == 0)
        return;
    PART(0x10, 0x30C7, 1)
    PART(0x20, 0x30C8, 2)
    PART(0x40, 0x30C9, 3)
    PART(0x80, 0x30CA, 4)
    PART(0x100, 0x30CB, 5)
    PART(0x200, 0x30CC, 6)
    PART(0x400, 0x30CD, 7)
    PART(0x800, 0x30CE, 8)
    PART(0x1000, 0x30CF, 9)
    PART(0x8, 0x30C6, 0)
}
