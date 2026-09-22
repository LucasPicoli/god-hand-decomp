/* sn-2.95.3-136 matched TU. */

extern void SetCustomIDDispOneOrAll_1F29C0(void *, int, int);
extern void *InitFields_1B6E90(void *a0);
extern int D_00428928;
extern void func_00380E88(void *, void *, void *);
extern void func_0031C900(int);
extern void cSnd_SetBgmState(void *, int);
extern void func_00144C90(void *);
extern void BuildObjEntry_387160(int, void *);

/* func_001F3260 — sn-2.95.3-136 */


__attribute__((section(".text.func_001F3260")))
void func_001F3260(char *a0) {
    SetCustomIDDispOneOrAll_1F29C0(a0, 4, 0);
    *(int *)a0 |= 4;
    *(int *)(a0 + 0x92C) = 0;
    *(int *)(a0 + 0x928) = 0;
}

#include "godhand/vu0.h"
/* func_001B6710 — sn-2.95.3-136 */



__attribute__((section(".text.func_001B6710")))
void *func_001B6710(char *a0) {
    InitFields_1B6E90(a0);
    *(int **)(a0 + 0x214) = &D_00428928;
    VU0_SQC2_VF0(a0, 0x600);
    VU0_SQC2_VF0(a0, 0x610);
    *(int *)(a0 + 0x620) = 0;
    *(int *)(a0 + 0x624) = 0;
    return a0;
}

/* func_00385A20 — sn-2.95.3-136 */



__attribute__((section(".text.func_00385A20")))
void func_00385A20(void *a0) {
    char *p = (char *)a0 + 0x470;
    func_00380E88(a0, (char *)a0 + 0x484, p);
    if (*(int *)(p + 0x84) != 0) {
        func_0031C900(*(int *)(p + 0x84));
        *(int *)(p + 0x84) = 0;
    }
}

/* func_002CA8C8 — sn-2.95.3-136 */


__attribute__((section(".text.func_002CA8C8")))
void func_002CA8C8(void *a0) {
    cSnd_SetBgmState(a0, 0);
    *(int *)((char *)a0 + 0xB0) &= 0xFFBFFFFF;
    *(int *)((char *)a0 + 0xAC) &= 0xFFBFFFFF;
}

/* func_00145410 — sn-2.95.3-136 */

__attribute__((section(".text.func_00145410")))
void func_00145410(char *a0) {
    if ((*(int *)(a0 + 0x90) & 0x40000000) != 0) {
        func_00144C90(a0);
        *(int *)(a0 + 0x90) &= 0xEFFFFFFF;
    }
}

/* func_0037AAB0 — sn-2.95.3-136 */


__attribute__((section(".text.func_0037AAB0")))
void func_0037AAB0(char *a0) {
    char *p = a0 + 0xCC;
    if (*(signed char *)(a0 + 0x25) != 7) return;
    if ((func_00387430(0) & 8) == 0) return;
    *(short *)(p + 0xA) = 1;
    BuildObjEntry_387160(0, p);
}
