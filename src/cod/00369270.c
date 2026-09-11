/* cygnus-2.96 matched TU. */

extern int MPV_CheckDelim(char *p);

__attribute__((section(".text.MPV_BsearchDelim")))
char *MPV_BsearchDelim(char *ptr, int n, int mask)
{
    char *p;
    char *lim;
    unsigned int state;
    int c;

    state = 0;
    p = ptr;
    lim = ptr - n;
    while (lim < p) {
        p--;
        c = *p;
        switch (state) {
        case 0:
            state = 1;
            break;
        case 1:
            if (c == 1) state = 2;
            break;
        case 2:
            if (c == 0) {
                state = 3;
            } else if (c != 1) {
                state = 1;
            }
            break;
        case 3:
            if (c == 0) {
                if (mask & MPV_CheckDelim(p)) return p;
                state = 0;
            } else {
                state = (c != 1) ? 1 : 2;
            }
            break;
        }
    }
    return 0;
}
