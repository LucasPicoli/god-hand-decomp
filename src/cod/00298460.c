/* sn-2.95.3-136 matched TU. */

extern int cModel_setMeshDisplay(void *model, char *name, int on);
extern char D_0044AA10[];
extern char D_0044AA18[];
extern char D_0044AA20[];
extern char D_0044AA28[];
extern char D_0044AA30[];
extern char D_0044AA38[];
extern char D_0044AA40[];
extern char D_0044AA48[];

/* sn-2.95.3-136 matched TU. */












__attribute__((section(".text.func_00298460")))
void func_00298460(void *a0, int a1, int a2) {
    char *s3 = (char *)a0;

    if (s3 == 0) {
        return;
    }
    switch (*(unsigned short *)(s3 + 0x2FE)) {
    case 0x600:
        cModel_setMeshDisplay(s3, D_0044AA10, 1);
        cModel_setMeshDisplay(s3, D_0044AA18, 1);
        cModel_setMeshDisplay(s3, D_0044AA20, 0);
        if (a2 < 0xB) {
            return;
        }
        cModel_setMeshDisplay(s3, D_0044AA10, 0);
        cModel_setMeshDisplay(s3, D_0044AA18, 0);
        cModel_setMeshDisplay(s3, D_0044AA20, 1);
        cModel_setMeshDisplay(s3, D_0044AA28, 0);
        cModel_setMeshDisplay(s3, D_0044AA30, 1);
        break;
    case 0x602:
        cModel_setMeshDisplay(s3, D_0044AA10, 1);
        cModel_setMeshDisplay(s3, D_0044AA20, 0);
        if (a2 < 0xB) {
            return;
        }
        cModel_setMeshDisplay(s3, D_0044AA10, 0);
        cModel_setMeshDisplay(s3, D_0044AA20, 1);
        cModel_setMeshDisplay(s3, D_0044AA28, 0);
        cModel_setMeshDisplay(s3, D_0044AA30, 1);
        break;
    case 0x625:
        if (a2 < 2) {
            cModel_setMeshDisplay(s3, D_0044AA28, 0);
            cModel_setMeshDisplay(s3, D_0044AA30, 1);
            cModel_setMeshDisplay(s3, D_0044AA38, 0);
        } else {
            cModel_setMeshDisplay(s3, D_0044AA28, 1);
            cModel_setMeshDisplay(s3, D_0044AA30, 0);
            cModel_setMeshDisplay(s3, D_0044AA38, 0);
        }
        if (a2 < 8) {
            return;
        }
        cModel_setMeshDisplay(s3, D_0044AA28, 0);
        cModel_setMeshDisplay(s3, D_0044AA30, 0);
        cModel_setMeshDisplay(s3, D_0044AA38, 1);
        break;
    case 0x626:
        cModel_setMeshDisplay(s3, D_0044AA40, 0);
        cModel_setMeshDisplay(s3, D_0044AA48, 0);
        break;
    case 0x627:
        if (a2 < 2) {
            cModel_setMeshDisplay(s3, D_0044AA28, 0);
            cModel_setMeshDisplay(s3, D_0044AA30, 1);
        } else {
            cModel_setMeshDisplay(s3, D_0044AA28, 1);
            cModel_setMeshDisplay(s3, D_0044AA30, 0);
        }
        if (a2 < 8) {
            return;
        }
        cModel_setMeshDisplay(s3, D_0044AA28, 0);
        cModel_setMeshDisplay(s3, D_0044AA30, 0);
        break;
    }
}
