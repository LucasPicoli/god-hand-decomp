/* cygnus-2.96 matched TU. */

extern char D_00747A78[];
extern char D_0076A7B8[];

typedef struct {
    char b[24];
} T24;

__attribute__((section(".text.SetField_1C_2009B0")))
void SetField_1C_2009B0(char *dst, char *src) {
    *(T24 *)(dst + 0x1C) = *(T24 *)src;
}

/* cygnus-2.96 | as sn */
typedef struct {
    char b[8];
} T8;



__attribute__((section(".text.func_002BF800")))
void func_002BF800(char *p)
{
    *(T8 *)D_00747A78 = *(T8 *)(p + 0x74);
}

typedef struct {
    char b[16];
} T16;



__attribute__((section(".text.func_00375600")))
void func_00375600(void *dst) {
    *(T16 *)dst = *(T16 *)D_0076A7B8;
}
