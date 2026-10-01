/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"

extern int cIDBase_release();
extern int cIDBase_trans();
extern int CustomIDWork_SetDisp();
extern int CustomIDWork_SetNumber();

/* clone */


__attribute__((section(".text.func_001ED660")))
void func_001ED660(void *a0) { cIDBase_release((char *)a0 + 0x10); }

/* clone */


__attribute__((section(".text.func_001ED6E0")))
void func_001ED6E0(void *a0) { cIDBase_trans((char *)a0 + 0x10); }

/* clone */


__attribute__((section(".text.func_001ED700")))
void func_001ED700(char *a0, int a1, int a2)
{
	char *p;
	int i;

	if (a2 != 0) {
		if (a1 == 0x6) {
			p = a0 + 0x60;
			for (i = 0x5; i >= 0; i--) {
				CustomIDWork_SetDisp(p, 1);
				p += 0x7C;
			}
		} else {
			CustomIDWork_SetDisp(a0 + (a1 * 0x7C + 0x60), 1);
		}
	} else {
		if (a1 == 0x6) {
			p = a0 + 0x60;
			for (i = 0x5; i >= 0; i--) {
				CustomIDWork_SetDisp(p, 0);
				p += 0x7C;
			}
		} else {
			CustomIDWork_SetDisp(a0 + (a1 * 0x7C + 0x60), 0);
		}
	}
}

/* clone */


__attribute__((section(".text.func_001EDF60")))
void func_001EDF60(void *a0) { cIDBase_release((char *)a0 + 0x10); }

/* clone */


__attribute__((section(".text.func_001EE2A8")))
void func_001EE2A8(void *a0) { CustomIDWork_SetNumber((char *)a0 + 0x918); }

/* clone */


__attribute__((section(".text.func_001EE2C8")))
void func_001EE2C8(void *a0) { CustomIDWork_SetNumber((char *)a0 + 0xA10); }

/* clone */


__attribute__((section(".text.func_001F46E0")))
void func_001F46E0(void *a0) { cIDBase_release((char *)a0 + 0x10); }

/* clone */


__attribute__((section(".text.func_001F4758")))
void func_001F4758(void *a0) { cIDBase_trans((char *)a0 + 0x10); }

/* clone */


__attribute__((section(".text.func_001F4B78")))
void func_001F4B78(void *a0) { CustomIDWork_SetNumber((char *)a0 + 0x158); }

/* clone */

__attribute__((section(".text.cCoreSave_addKeyCardNum")))
/* Add to the key card count, clamped to 0..9. */
void cCoreSave_addKeyCardNum(cCoreSave *self, int n) {
    if (!self->data)
        return;
    self->data->keyCardNum += n;
    if (self->data->keyCardNum >= 0xA)
        self->data->keyCardNum = 9;
    if (self->data->keyCardNum < 0)
        self->data->keyCardNum = 0;
}
