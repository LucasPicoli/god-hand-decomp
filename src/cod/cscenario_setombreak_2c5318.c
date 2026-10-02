/* sn-2.95.3-136. */
#include "godhand/cScenario.h"

extern void func_002BECB0(void *list, long name);
extern char D_005E8658;

__attribute__((section(".text.cScenario_setOmBreak_2C5318")))
/* Put the object with this packed name on the break list (D_005E8658). */
void cScenario_setOmBreak_2C5318(cScenario *self, long name) {
    func_002BECB0(&D_005E8658, name);
}
