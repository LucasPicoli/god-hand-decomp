/* cygnus-2.96 matched TU. */

extern const char D_004549F8[];
extern struct FL_htci D_003D9DC0;
extern struct FL_htci2 D_003DA380;

struct B4_htci { char b[4]; };

__attribute__((section(".text.htci_is_bgn_host")))
int htci_is_bgn_host(char *fname)
{
    char buf[6];

    func_003A52F0(buf, 0, 6);
    *(struct B4_htci *)buf = *(struct B4_htci *)fname;
    buf[5] = 0;
    return func_003A5678(buf, D_004549F8) == 0;
}

struct FL_htci { char *tbl; int num; int f8; int fC; };


__attribute__((section(".text.func_00333A10")))
void func_00333A10(int *out, char *name, char *tbl, int num)
{
    int i;

    for (i = 0; i < num; i++) {
        if (func_003334C8(name, tbl + ((D_003D9DC0.f8 << 3) + (D_003D9DC0.fC * i + i))) == 0) {
            out[0] = ((int *)tbl)[i * 2];
            out[1] = ((int *)tbl)[i * 2 + 1];
            return;
        }
    }
    out[0] = 0;
    out[1] = 0;
}

struct FL_htci2 { char *tbl; int num; int f8; int fC; };


__attribute__((section(".text.func_003350F0")))
void func_003350F0(int *out, char *name, char *tbl, int num)
{
    int i;

    for (i = 0; i < num; i++) {
        if (func_00334EF0(name, tbl + ((D_003DA380.f8 << 3) + (D_003DA380.fC * i + i))) == 0) {
            out[0] = ((int *)tbl)[i * 2];
            out[1] = ((int *)tbl)[i * 2 + 1];
            return;
        }
    }
    out[0] = 0;
    out[1] = 0;
}
