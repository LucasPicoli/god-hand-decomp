/* cygnus-2.96 matched TU. */

extern void *GetArrayElemA0C_35A1C8(void *h, int n);
extern int sfaoap_OutputServer(void *h);
extern void func_0035C2D0(void *h, int a, int b, int c, int d);

__attribute__((section(".text.SFAOAP_ExecServer")))
int SFAOAP_ExecServer(void *h)
{
    if (GetArrayElemA0C_35A1C8(h, 6) == 0) return 0;
    return sfaoap_OutputServer(h);
}

__attribute__((section(".text.SFAOAP_Pause")))
void SFAOAP_Pause(void *h, int flag)
{
    if (GetArrayElemA0C_35A1C8(h, 6) != 0) {
        func_0035C2D0(h, 3, 8, flag, 0);
        do { } while (0);
    }
}
