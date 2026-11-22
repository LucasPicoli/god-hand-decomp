/* sn-2.95.3-136 matched TU. */
#include "godhand/StdString.h"
#include "godhand/globals.h"

/* Directory depth of a path: the number of '/' in it minus one, never below
   0. Terminates the string in place first. */
__attribute__((section(".text.StdString_pathDepth")))
int StdString_pathDepth(StdString *path) {
    char *p;
    signed char depth = -1;
    char c;

    if (STDSTRING_REP(path)->len == 0) {
        p = D_0045D008;
    } else {
        path->dat[STDSTRING_REP(path)->len] = 0;
        p = path->dat;
    }
    while ((c = *p++) != 0) {
        if (c == '/') {
            depth++;
        }
    }
    if (depth < 0) {
        depth = 0;
    }
    return depth;
}
