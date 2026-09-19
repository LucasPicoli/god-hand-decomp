/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 candidate: _sceSifLoadModuleBuffer (libkernl eeloadfile.c) */

typedef struct { char b[0xFC]; } T252;

typedef struct {
    void *ptr;         /* 0x000 */
    int  result;       /* 0x004 */
    char name[0xFC];   /* 0x008 */
    char args[0x1FC];  /* 0x104 */
} LoadReq;



extern void *func_003A5148(void *d, const void *s, unsigned int n);   /* memcpy */


extern LoadReq D_00781980;
extern char    D_00781B80[];

__attribute__((section(".text._sceSifLoadModuleBuffer")))
int _sceSifLoadModuleBuffer(void *ptr, int arglen, char *args, int *modres)
{
    if (func_003B5A80() < 0) {
        return 0xFFFF0000;
    }
    if (func_003B5B80() != 0) {
        return 0xFFFEFFFC;
    }
    D_00781980.ptr = ptr;
    if (args != 0) {
        if (arglen >= 0xFD) {
            *(T252 *)D_00781980.args = *(T252 *)args;
            D_00781980.result = 0xFC;
        } else {
            func_003A5148(D_00781980.args, args, arglen);
            D_00781980.result = arglen;
        }
    } else {
        D_00781980.result = 0;
    }
    if (func_003B3128(D_00781B80, 6, 0, &D_00781980, 0x200,
                      &D_00781980, 8, 0, 0) < 0) {
        return 0xFFFEFFFF;
    }
    {
        int res = D_00781980.result;
        int sz  = (int)D_00781980.ptr;
        *modres = res;
        return sz;
    }
}
