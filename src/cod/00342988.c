/* cygnus-2.96: MWADX_CreateCoreHn, allocate size - 0x1800 bytes and copy the trailing 0x1800 bytes of src there; hangs on failure. */
extern int func_00329438(int kind, int src, int size);
extern void func_003B9998(int dst, int src, int size);

__attribute__((section(".text.MWADX_CreateCoreHn")))
int MWADX_CreateCoreHn(int src, int size)
{
    int body = size - 0x1800;
    int p = func_00329438(2, src, body);

    if (p == 0) {
        for (;;)
            ;
    }
    func_003B9998(p, src + body, 0x1800);
    return p;
}
