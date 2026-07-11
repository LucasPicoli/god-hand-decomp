#include "godhand/vu0.h"

/* func_002B4690 — look up an object id from a scenario string; if not found
 * (0xFFFF) return 0, otherwise copy the vector at (*D_005CAFF0)+0x210 into a
 * stack buffer and forward it to func_002DB0D0(id, &vec, -1.0f).  sn-2.95.3-136. */

extern void *D_003C2F84;
extern void *D_005CAFF0;
extern int cScenario_getObjIdFromStr(void *);
extern int func_002DB0D0(int, void *, float);

__attribute__((section(".text.func_002B4690")))
int func_002B4690(void) {
    unsigned char buf[16] __attribute__((aligned(16)));
    void *p;
    int id = cScenario_getObjIdFromStr(D_003C2F84);
    if (id == 0xFFFF)
        return 0;
    p = (char *)D_005CAFF0 + 0x210;
    VU0_LQC2(4, p, 0);
    VU0_SQC2(4, buf, 0);
    return func_002DB0D0(id, buf, -1.0f);
}
