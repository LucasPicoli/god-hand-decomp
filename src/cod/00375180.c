extern int SeqCmd_findStartByMask(int, int);
extern unsigned char D_0076A7B4;

__attribute__((section(".text.func_00375180")))
int func_00375180(void)
{
    if (SeqCmd_findStartByMask(1, 0))
        return 1;
    return D_0076A7B4 != 0;
}
