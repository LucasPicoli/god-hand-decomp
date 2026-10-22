/* sn-2.95.3-136 matched TU. */
#include "godhand/cMovie.h"

__attribute__((section(".text.cMovie_GetStatus")))
int cMovie_GetStatus(void *mgr, int handle) {  /* callers pass the movie manager and handle; neither is read */
    int h;

    h = func_002B4F98();
    if (h == 0) {
        return 0;
    }
    switch (func_002D4210(h)) {
    case 1:
        return 1;
    case 2:
        return 2;
    case 0:
    case 3:
    case 4:
    case 5:
        return 3;
    }
    return 0;
}
