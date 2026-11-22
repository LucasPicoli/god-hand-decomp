/* cygnus-2.96 matched TU. */

extern void UTY_MemsetDword(int *a0, int a1, int a2);
extern void sfply_InitFlowCnt(int *a0);

/* MATCH via cygnus-2.96. */



__attribute__((section(".text.sfply_InitPlyInf")))
void sfply_InitPlyInf(int *a0)
{
    UTY_MemsetDword(a0, 0, 0x2A);
    a0[0] = 0;
    a0[1] = 0;
    a0[2] = 0;
    a0[3] = 0;
    a0[4] = 0;
    a0[6] = 0;
    a0[7] = 0;
    a0[8] = 0;
    a0[9] = 0;
    a0[0xA] = 0;
    a0[0xB] = 0;
    a0[0xC] = 0;
    sfply_InitFlowCnt(a0 + 0xE);
    sfply_InitFlowCnt(a0 + 0x14);
    sfply_InitFlowCnt(a0 + 0x1A);
    sfply_InitFlowCnt(a0 + 0x20);
}
