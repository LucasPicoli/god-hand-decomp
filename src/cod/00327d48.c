/* cygnus-2.96 matched TU. */

extern void func_0034F658(void *hn, int *out);
extern int (*D_00459680[])(void *hn, int a1, void *dst, int n, long long first);

/* func_0034E9B0 cygnus-2.96 drop-freorder: 90/94 length-exact, only prologue save/copy order differs (s3,s4,s2 first in retail). permuter 400s: no gain */






typedef struct StreamInfo {
    long long unk00;
    char pad08[8];
    int kind;           /* 0x10 selects the reader */
    int mode;           /* 0x14 selects the callback */
    int arg;            /* 0x18 passed to the callback */
    char pad1C[8];
    int length;         /* 0x24 */
} StreamInfo;

/* Reads one block of the stream into dst; *outLen gets the length read, *outStatus the reader's status. */
__attribute__((section(".text.func_0034E9B0")))
int func_0034E9B0(char *hn, void *dst, int max, int *outLen, int *outStatus)
{
    StreamInfo info;
    int *tbl;
    int ret = 0;
    int n;
    int st;
    int kind;
    int mode;
    int arg;
    long long first;

    *outLen = 0;
    *outStatus = 0;
    /* read as int, not int *: same alias set as the two status stores above, so the load stays below them */
    tbl = (int *)*(int *)(hn + 0x1F7C);
    if (func_00368C60(tbl[0], &info) != 0)
        ret = func_0034DD70(hn, 0xFF000D06);
    n = info.length;
    kind = info.kind;
    mode = info.mode;
    arg = info.arg;
    first = info.unk00;
    if (n < 0)
        return func_0034DD70(hn, 0xFF000D0E);
    if (n == 0) {
        *outLen = 0;
        *outStatus = 1;
        return 0;
    }
    if (max < n) {
        func_0034F658(hn, 0);
        return 0;
    }
    if (*(int *)(kind * 4 + (int)tbl - 0x2B0) != 0)
        *outStatus = func_0034EB28(*(int *)(kind * 4 + (int)tbl - 0x2B0), tbl[0x150 / 4], tbl[0x154 / 4], kind, (int)dst, n);
    else
        *outStatus = D_00459680[mode](hn, arg, dst, n, first);
    st = *outStatus;
    if (st != 0) {
        if (st == 1)
            *outLen = n;
        else
            ret = st;
    }
    return ret;
}

/* Forwards x to the small-size or the large-size allocator by n (threshold 0x100), zero for the other three arguments.
   The long return type is what keeps the two calls non-tail under cygnus-2.96 (void and int both sibcall). */



__attribute__((section(".text.func_00327D48")))
long func_00327D48(int x, int n)
{
    if (n < 0x100)
        func_00327B58(0, 0, 0, x);
    else
        func_00327C30(0, 0, 0, x);
}
