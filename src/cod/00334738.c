/* cygnus-2.96 matched TU. */

extern const char D_00454960[];

__attribute__((section(".text.htCiSeek")))
int htCiSeek(int *hn, int off, int mode)
{
    int pos;

    if (hn == 0) {
        func_00334008(hn, D_00454960);
        return 0;
    }
    if (mode == 0) {
        hn[7] = off;
    } else if (mode == 2) {
        hn[7] = hn[4] + off;
    } else if (mode == 1) {
        hn[7] = hn[7] + off;
    }
    hn[10] = 0;
    pos = hn[7];
    if (pos >= hn[4]) pos = hn[4];
    if (pos < 0) pos = 0;
    hn[7] = pos;
    return pos;
}
