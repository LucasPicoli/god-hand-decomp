/* ee-2.9-991111 matched TU. */

extern int D_003FAEF4;
extern int D_00781800;
extern int D_00781840;
extern char D_007817C0[];

__attribute__((section(".text.sceSifFreeSysMemory")))
int sceSifFreeSysMemory(int addr)
{
    if (D_003FAEF4 < 0) {
        return 0;
    }
    D_00781840 = addr;
    if (func_003B3128(D_007817C0, 2, 0, &D_00781840, 4, &D_00781800, 4, 0, 0) < 0) {
        return -1;
    }
    return D_00781800;
}
