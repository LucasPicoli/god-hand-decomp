#include "godhand/cOm53.h"

/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text._IO_switch_to_backup_area")))
void _IO_switch_to_backup_area(int *fp) {
    int tmp;
    fp[0] = fp[0] | 0x100;
    tmp = fp[2];
    fp[2] = fp[11];
    fp[11] = tmp;
    tmp = fp[3];
    fp[3] = fp[9];
    fp[9] = tmp;
    fp[1] = fp[2];
}

/* Count n more riders as off the lift. 0 when nobody rides or n is 0. */
__attribute__((section(".text.cOm53_setGetOffEm")))
int cOm53_setGetOffEm(cOm53 *self, int n) {
    if (self->riderNum == 0) {
        return 0;
    }
    if (n == 0) {
        return 0;
    }
    self->getOffNum = self->getOffNum + n;
    return 1;
}

__attribute__((section(".text.func_001FE310")))
unsigned char *func_001FE310(unsigned char *p) {
    unsigned int i = 0;
    unsigned char *q = p + 0x3C00;
loop:
    if (q[0x4A] == 0) {
        return q;
    }
    i++;
    if (i < 0x100) {
        q = q + 0x70;
        goto loop;
    }
    return p + 0xAC60;
}

__attribute__((section(".text._IO_switch_to_main_get_area")))
void _IO_switch_to_main_get_area(int *fp) {
    int tmp;
    fp[0] = fp[0] & ~0x100;
    tmp = fp[2];
    fp[2] = fp[11];
    fp[11] = tmp;
    tmp = fp[3];
    fp[3] = fp[9];
    fp[9] = tmp;
    fp[1] = fp[3];
}
