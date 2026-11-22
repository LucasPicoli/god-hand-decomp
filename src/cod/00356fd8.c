extern int func_00357068(char *hn, int mode);

__attribute__((section(".text.SFPL2_Pause")))
int SFPL2_Pause(char *hn, unsigned int mode)
{
    int r = 0;

    switch (mode) {
    case 2:
        if (*(int *)(hn + 0x48) == 4)
            r = func_00357068(hn, mode);
        break;
    case 1:
        if (++*(int *)(hn + 0x54) == mode)
            r = func_00357068(hn, mode);
        break;
    case 0:
        if (--*(int *)(hn + 0x54) == 0)
            r = func_00357068(hn, 0);
        break;
    }
    return r;
}
