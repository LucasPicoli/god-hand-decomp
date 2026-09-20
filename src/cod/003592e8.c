/* cygnus-2.96 matched TU. */

/* cygnus-2.96 matched TU. */

typedef signed char  Sint8;
typedef signed int   Sint32;

extern Sint32 Obj34D8_SetGlobalEE0B8_IfField48(void *hn);

extern void func_00359370(void *que, void *ptr, Sint32 n);

__attribute__((section(".text.func_003592E8")))
Sint32 func_003592E8(void *sfd, void *ptr, Sint32 n)
{
    if (ptr == 0 || n <= 0) return 0;
    if (Obj34D8_SetGlobalEE0B8_IfField48(sfd) != 0) {
        return func_0034DD70(0, 0xFF000165);
    }
    func_00359370((Sint8 *)sfd + 0x13BC, ptr, n);
    return 0;
}
