/* ee-2.9-991111 matched TU. */

typedef struct { char b[0xFC]; } T252;

typedef struct {
    int  size;         /* 0x000 */
    int  result;       /* 0x004 */
    char name[0xFC];   /* 0x008 */
    char args[0x1FC];  /* 0x104 */
} LoadReq;







extern LoadReq D_00781980;
extern char    D_00781B80[];

__attribute__((section(".text.func_003B5E78")))
int func_003B5E78(char *path, int arglen, char *args, int *modres, int fno)
{
    if (func_003B5A80() < 0) {
        return 0xFFFF0000;
    }
    if (func_003B5B80() != 0) {
        return 0xFFFEFFFC;
    }
    func_003A5DA0(D_00781980.name, path, 0xFC);
    D_00781980.name[0xFB] = 0;
    if (args != 0) {
        if (arglen >= 0xFD) {
            *(T252 *)D_00781980.args = *(T252 *)args;
            D_00781980.size = 0xFC;
        } else {
            func_003A5148(D_00781980.args, args, arglen);
            D_00781980.size = arglen;
        }
    } else {
        D_00781980.args[0] = 0;
        D_00781980.size = 0;
    }
    if (func_003B3128(D_00781B80, fno, 0, &D_00781980, 0x200,
                      &D_00781980, 8, 0, 0) < 0) {
        return 0xFFFEFFFF;
    }
    {
        int res = D_00781980.result;
        int sz  = D_00781980.size;
        *modres = res;
        return sz;
    }
}
