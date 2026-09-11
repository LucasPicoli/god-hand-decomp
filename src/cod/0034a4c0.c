/* cygnus-2.96 matched TU. */

extern int ADXT_IsEndcode(char *p, int n, int *loc);


__attribute__((section(".text.sfadxt_SearchAlign")))
char *sfadxt_SearchAlign(void *hn, char *buf, int n)
{
    char *p;
    char *q;
    char *best;
    char *bestbase;
    int found;
    int loc;
    char *end;

    found = 0;
    best = 0;
    bestbase = 0;
    end = buf + n;
    p = buf;
    while (p < buf + 0x24) {
        found = 0;
        q = p;
        while (q < end) {
            if (*q < 0) {
                found = 1;
                if (ADXT_IsEndcode(q, 0x12, &loc) != 0 && best < q) {
                    best = q;
                    bestbase = p;
                }
                break;
            }
            q += 0x12;
        }
        if (found == 0) return p;
        p += 2;
    }
    if (found == 0) goto ret_p;
    if (bestbase == 0) {
        func_0034DD70(hn, 0xFF000C0AU);
        return buf;
    }
    p = bestbase;
ret_p:
    return p;
}
