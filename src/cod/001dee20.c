/* sn-2.95.3-136 matched TU. */

extern int cIDBase_trans();
extern int CustomIDWork_SetNumber();
extern int CustomIDWork_ResetColorAnim();
extern int CustomIDWork_SetColorAnimSin();
extern char D_00463050[];
extern int cCamManager_setSubScrCamera();
extern int cCamManager_setPlCamera();
extern int CustomIDWork_SetDisp();

/* clone */


__attribute__((section(".text.func_001DEE20")))
void func_001DEE20(void *a0) { cIDBase_trans((char *)a0 + 0x10); }

/* clone */


__attribute__((section(".text.func_001DEE40")))
void func_001DEE40(void *a0) { CustomIDWork_SetNumber((char *)a0 + 0x7A4); }

/* clone */



__attribute__((section(".text.func_001DF048")))
void func_001DF048(void *a0, int a1, int a2)
{
    if (a1) {
        int b;
        int x = (((((((b & ~0xFF) | 0x60) & ~0xFF00) | 0x6000) & ~0xFF0000) | 0x600000) & ~0xFF000000) | 0x50000000;
        int y = (((((((a2 & ~0xFF) | 0xA0) & ~0xFF00) | 0xA000) & ~0xFF0000) | 0xA00000) & ~0xFF000000) | 0x80000000;
        CustomIDWork_SetColorAnimSin((char *)a0 + 0x158, x, y, 3);
    } else {
        CustomIDWork_ResetColorAnim((char *)a0 + 0x158);
    }
}

/* clone */



__attribute__((section(".text.func_001DF0F0")))
void func_001DF0F0(void *a0, int a1, int a2)
{
    if (a1) {
        int b;
        int x = (((((((b & ~0xFF) | 0x60) & ~0xFF00) | 0x6000) & ~0xFF0000) | 0x600000) & ~0xFF000000) | 0x50000000;
        int y = (((((((a2 & ~0xFF) | 0xA0) & ~0xFF00) | 0xA000) & ~0xFF0000) | 0xA00000) & ~0xFF000000) | 0x80000000;
        CustomIDWork_SetColorAnimSin((char *)a0 + 0x250, x, y, 3);
    } else {
        CustomIDWork_ResetColorAnim((char *)a0 + 0x250);
    }
}

/* clone */



__attribute__((section(".text.func_001E32E8")))
void func_001E32E8(int a0, float *a1, float *a2) {
    float *dst1;
    float *dst2;

    cCamManager_setSubScrCamera(D_00463050, 0);
    *(int *)(a0 + 0x498) = (int)(D_00463050 + 0xC90);
    dst1 = (float *)(D_00463050 + 0xEA0);
    if (a1 != dst1) {
        dst1[0] = a1[0];
        dst1[1] = a1[1];
        dst1[2] = a1[2];
    }
    dst2 = (float *)(*(int *)(a0 + 0x498) + 0x200);
    if (dst2 != a2) {
        dst2[0] = a2[0];
        dst2[1] = a2[1];
        dst2[2] = a2[2];
    }
}

/* clone */



__attribute__((section(".text.func_001E3388")))
void func_001E3388(void) {
    cCamManager_setPlCamera(D_00463050, 0);
}

/* clone */



__attribute__((section(".text.func_001E6870")))
void func_001E6870(int a0, float *a1, float *a2) {
    float *dst1;
    float *dst2;

    cCamManager_setSubScrCamera(D_00463050, 0);
    *(int *)(a0 + 0x3DC) = (int)(D_00463050 + 0xC90);
    dst1 = (float *)(D_00463050 + 0xEA0);
    if (a1 != dst1) {
        dst1[0] = a1[0];
        dst1[1] = a1[1];
        dst1[2] = a1[2];
    }
    dst2 = (float *)(*(int *)(a0 + 0x3DC) + 0x200);
    if (dst2 != a2) {
        dst2[0] = a2[0];
        dst2[1] = a2[1];
        dst2[2] = a2[2];
    }
}

/* clone */



__attribute__((section(".text.func_001E6910")))
void func_001E6910(void) {
    cCamManager_setPlCamera(D_00463050, 0);
}

/* clone */


__attribute__((section(".text.func_001E7470")))
void func_001E7470(char *a0, int a1, int a2)
{
	char *p;
	int i;

	if (a2 != 0) {
		if (a1 == 0xA) {
			p = a0 + 0x50;
			for (i = 0x9; i >= 0; i--) {
				CustomIDWork_SetDisp(p, 1);
				p += 0x7C;
			}
		} else {
			CustomIDWork_SetDisp(a0 + (a1 * 0x7C + 0x50), 1);
		}
	} else {
		if (a1 == 0xA) {
			p = a0 + 0x50;
			for (i = 0x9; i >= 0; i--) {
				CustomIDWork_SetDisp(p, 0);
				p += 0x7C;
			}
		} else {
			CustomIDWork_SetDisp(a0 + (a1 * 0x7C + 0x50), 0);
		}
	}
}

/* clone */


__attribute__((section(".text.func_001E7538")))
void func_001E7538(char *a0, int a1, int a2)
{
	char *p;
	int i;

	if (a2 != 0) {
		if (a1 == 0x2) {
			p = a0 + 0x580;
			for (i = 0x1; i >= 0; i--) {
				CustomIDWork_SetDisp(p, 1);
				p += 0x7C;
			}
		} else {
			CustomIDWork_SetDisp(a0 + (a1 * 0x7C + 0x580), 1);
		}
	} else {
		if (a1 == 0x2) {
			p = a0 + 0x580;
			for (i = 0x1; i >= 0; i--) {
				CustomIDWork_SetDisp(p, 0);
				p += 0x7C;
			}
		} else {
			CustomIDWork_SetDisp(a0 + (a1 * 0x7C + 0x580), 0);
		}
	}
}
