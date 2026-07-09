/* sn-2.95.3-136 matched TU. */

extern unsigned int D_00747A24;
extern unsigned char D_005CAC90;
extern int D_00752C00[];
extern void func_002A5B00(void *a0);
extern void func_002A6CA8(void *a0);
extern void func_002A6DA8(void *a0);
extern void func_002A5B18(void *a0);
extern void func_002A5BB8(void *a0);
extern void func_002A5D40(void *a0);
extern void func_002A5EC0(void *a0);
extern void cGame_gameLoop(void *a0);
extern void func_002A67D0(void *a0);
extern void SetFieldsCESignalSemaSleep_2D5AA0(int a0, int a1);
extern void cTaskWork_exit(int a0);

/* sn-2.95.3-136 matched TU. */
















__attribute__((section(".text.func_002A5998")))
void func_002A5998(void) {
    D_00747A24 = D_00747A24 | 0x80000000;
    func_002A5B00(&D_005CAC90);
    while (D_00747A24 & 0x80000000) {
        func_002A6CA8(&D_005CAC90);
        func_002A6DA8(&D_005CAC90);
        switch (D_005CAC90) {
        case 0: func_002A5B18(&D_005CAC90); break;
        case 1: func_002A5BB8(&D_005CAC90); break;
        case 2: func_002A5D40(&D_005CAC90); break;
        case 3: func_002A5EC0(&D_005CAC90); break;
        case 4: cGame_gameLoop(&D_005CAC90); break;
        case 5: func_002A67D0(&D_005CAC90); break;
        default: break;
        }
        SetFieldsCESignalSemaSleep_2D5AA0(D_00752C00[1], 1);
    }
    cTaskWork_exit(D_00752C00[1]);
}
