/* ee-2.9-991111 matched TU. */

extern char D_0077C0C0[];
extern int D_0077C300[];
extern int D_003FAEF4;
extern char D_007817C0[];
extern int D_00781800;
extern int D_00781840;

__attribute__((section(".text.scePadGetModVersion")))
int scePadGetModVersion(void)
{
    D_0077C300[0] = 0x12;
    if (func_003B3128(D_0077C0C0, 1, 0, D_0077C300, 0x80, D_0077C300, 0x80, 0, 0) < 0) {
        return 0;
    }
    return D_0077C300[3];
}

__attribute__((section(".text.sceSifAllocIopHeap")))
int sceSifAllocIopHeap(int size)
{
    if (D_003FAEF4 < 0) {
        return 0;
    }
    D_00781840 = size;
    if (func_003B3128(D_007817C0, 1, 0, &D_00781840, 4, &D_00781800, 4, 0, 0) < 0) {
        return 0;
    }
    return D_00781800;
}
