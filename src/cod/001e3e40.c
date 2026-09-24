/* sn-2.95.3-136 matched TU. */

typedef struct { int w[15]; } Tbl15;
extern Tbl15 D_0042B890;
extern void displayScrollLayer(int a0, int a1);

__attribute__((section(".text.func_001E3E40")))
void func_001E3E40(char *a0, unsigned short a1, int a2, int a3)
{
    int tbl[5][3];
    int *lay;

    *(Tbl15 *)tbl = D_0042B890;
    if (a1 < 5) {
        *(unsigned short *)(a0 + 0x4AA) = a1 << 11;
        if (a3 != 0)
            *(unsigned short *)(a0 + 0x4AA) |= 0x8000;
        if (a2 != 0) {
            *(unsigned short *)(a0 + 0x4AA) |= 0x4000;
            lay = (int *)(a0 + 0x400);
            displayScrollLayer(*(int *)((char *)lay + (tbl[a1][0] << 2)), 1);
            displayScrollLayer(*(int *)((char *)lay + (tbl[a1][1] << 2)), 1);
            lay += tbl[a1][2];
            displayScrollLayer(*lay, 1);
            displayScrollLayer(*(int *)(a0 + 0x42C), 1);
        } else {
            lay = (int *)(a0 + 0x400);
            displayScrollLayer(*(int *)((char *)lay + (tbl[a1][0] << 2)), 0);
            displayScrollLayer(*(int *)((char *)lay + (tbl[a1][1] << 2)), 0);
            lay += tbl[a1][2];
            displayScrollLayer(*lay, 0);
            displayScrollLayer(*(int *)(a0 + 0x42C), 0);
        }
    }
}
