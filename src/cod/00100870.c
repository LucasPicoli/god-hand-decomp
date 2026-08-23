/* sn-2.95.3-136 matched TU. */

extern int D_00569B70;
extern int cCoreSave_getCostumeNo(void *a0);
extern void func_001038E0(char *a0, char *a1, char *a2, float f12, float f13);
extern char D_003BBF80[];
extern char D_003BBFA8[];
extern char D_003BBFD0[];
extern char D_003BBFF8[];
extern char D_003BC020[];
extern char D_003BC0C0[];
extern char D_003BC160[];
extern char D_00460E00[];
extern char D_003BC200[];
extern char D_003BC218[];
extern char D_003BC230[];
extern char D_003BC248[];
extern char D_003BC260[];
extern char D_003BC2C0[];
extern char D_003BC320[];
extern char D_00461040[];
extern char D_003BC380[];
extern char D_003BC3A8[];
extern char D_003BC3D0[];
extern char D_003BC3F8[];
extern char D_003BC420[];
extern char D_003BC448[];
extern char D_003BC4D0[];
extern char D_003BC558[];
extern char D_00461250[];
extern char D_003BC5E0[];
extern char D_003BC5F8[];
extern char D_003BC610[];
extern char D_003BC628[];
extern char D_003BC640[];
extern char D_003BC690[];
extern char D_003BC6E0[];
extern char D_004613A0[];

#define BODY(k, a2054, a2058, a205C, a2068, a206C, a2078, a207C, a2080, a2084, f2090, f209C) \
    *(int *)(p + 0x2050) = (k);                                             \
    *(char **)(p + 0x2054) = (a2054);                                       \
    *(char **)(p + 0x2058) = (a2058);                                       \
    *(int *)(p + 0x205C) = (int)(a205C);                                    \
    *(int *)(p + 0x2060) = 0;                                               \
    *(int *)(p + 0x2064) = 0;                                               \
    *(char **)(p + 0x2068) = (a2068);                                       \
    *(char **)(p + 0x206C) = (a206C);                                       \
    *(int *)(p + 0x2070) = 0;                                               \
    *(int *)(p + 0x2074) = 0;                                               \
    *(char **)(p + 0x2078) = (a2078);                                       \
    *(char **)(p + 0x207C) = (a207C);                                       \
    *(char **)(p + 0x2080) = (a2080);                                       \
    *(char **)(p + 0x2084) = (a2084);                                       \
    *(int *)(p + 0x2088) = 0;                                               \
    *(int *)(p + 0x20A8) = 0;                                               \
    *(float *)(p + 0x208C) = 0.015f;                                        \
    *(float *)(p + 0x2090) = (f2090);                                       \
    *(int *)(p + 0x2094) = 1;                                               \
    *(float *)(p + 0x2098) = 0.0f;                                          \
    *(float *)(p + 0x209C) = (f209C);                                       \
    *(float *)(p + 0x20A0) = 0.5f;                                          \
    *(int *)(p + 0x20A4) = 0;                                               \
    *(int *)(p + 0x20AC) = 0x100;                                           \
    v[0] = 0.0f;                                                            \
    v[1] = 0.0f;                                                            \
    *(int *)&v[2] = 0;                                                      \
    v[3] = 1.0f;                                                            \
    dst = (volatile float *)(p + 0x20B0);                                   \
    if (dst != (volatile float *)v) {                                       \
        dst[0] = v[0];                                                      \
        dst[1] = v[1];                                                      \
        dst[2] = *(volatile float *)&v[2];                                  \
    }                                                                       \
    *(float *)(p + 0x20C0) = 1.0471976f;                                    \
    func_001038E0(p, p + 0x2050, p + 0x4D0, 0.1f, 0.0f);

__attribute__((section(".text.func_00100870")))
void func_00100870(char *p)
{
    float v[4];
    volatile float *dst;

    switch (cCoreSave_getCostumeNo(&D_00569B70)) {
    default:
    case 0:
    case 1:
        BODY(0x28, D_003BBF80, D_003BBFF8, 0, D_003BBFA8, D_003BBFD0,
             D_003BC020, D_003BC0C0, D_003BC160, D_00460E00, 0.8f, 0.8f)
        break;
    case 2:
    case 3:
        BODY(0x18, D_003BC200, D_003BC248, 0, D_003BC218, D_003BC230,
             D_003BC260, D_003BC2C0, D_003BC320, D_00461040, 0.8f, 0.8f)
        break;
    case 4:
    case 5:
        BODY(0x21, D_003BC380, D_003BC3F8, D_003BC420, D_003BC3A8, D_003BC3D0,
             D_003BC448, D_003BC4D0, D_003BC558, D_00461250, 0.5f, 1.0f)
        break;
    case 6:
    case 7:
        BODY(0x14, D_003BC5E0, D_003BC628, 0, D_003BC5F8, D_003BC610,
             D_003BC640, D_003BC690, D_003BC6E0, D_004613A0, 0.8f, 0.8f)
        break;
    }
}
