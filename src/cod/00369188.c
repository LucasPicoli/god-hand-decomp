/* cygnus-2.96 matched TU. */

extern int MPSLIB_CheckHn(int *h);
extern int MPSLIB_SetErr(int a, int b);

__attribute__((section(".text.MPS_Destroy")))
int MPS_Destroy(int *h)
{
    if (MPSLIB_CheckHn(h) != 0) {
        return MPSLIB_SetErr(0, 0xFF020103);
    }
    *h = 1;
}
