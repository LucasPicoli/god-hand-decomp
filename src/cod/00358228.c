/* cygnus-2.96: func_00358228, creates a handle in a free slot of D_003EE2C4;
 * reports when every slot is taken. */
extern void *D_003EE2C4[8];
extern int sfply_ChkCrePara(int a0);
extern int sfply_SearchFreeHn(void);
extern void *func_00358368(int a0, int a1);
extern int func_0034DD70(int a0, int code);

__attribute__((section(".text.func_00358228")))
void *func_00358228(int a0, int a1)
{
    void **tbl = D_003EE2C4;
    void *hn;
    int i;

    if (sfply_ChkCrePara(a0) != 0)
        return 0;
    i = sfply_SearchFreeHn();
    if (i == -1) {
        func_0034DD70(0, 0xFF000206);
        return 0;
    }
    hn = func_00358368(a0, a1);
    tbl[i] = hn;
    return hn;
}
