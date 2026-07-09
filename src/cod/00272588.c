/* sn-2.95.3-136 matched TU. */

extern void *func_002DDAB0(void *a0, int a1, float f);
extern void *Obj0000_Get_D_00747A94_2DB6B0(void);
extern float capVu0MagnitudeSqXZ(void *a0, void *a1);
extern void func_001D0AD0(void *a0);
extern void cEm00_setGoto(void *a0, int a1, int a2, int a3, float f);

__attribute__((section(".text.func_00272588")))
int func_00272588(char *a0) {
    char *s1 = a0;
    if (*(int *)(s1 + 0x6EC) != 0) {
        return 0;
    }
    if (*(int *)(s1 + 0x6F0) != 0) {
        return 0;
    }
    switch (*(int *)(s1 + 0x564)) {
    case 0x200: case 0x201: case 0x202: case 0x203: case 0x216:
    case 0x227: case 0x228: case 0x229: case 0x22A: case 0x22B:
    case 0x23A: case 0x240: case 0x24A: case 0x24B:
    {
        char *s0 = (char *)func_002DDAB0(*(void **)(s1 + 0xF0), 0, 10.0f);
        if (s0 == 0) {
            return 0;
        }
        {
            void *o = Obj0000_Get_D_00747A94_2DB6B0();
            if (capVu0MagnitudeSqXZ(*(void **)((char *)o + 0xF0), *(void **)(s0 + 0xF0)) < 6.25f) {
                return 0;
            }
        }
        func_001D0AD0(s0);
        cEm00_setGoto(s1, *(int *)(s0 + 0xF0), 8, 0, 300.0f);
        *(char *)(s1 + 0x2F7) = 0;
        *(char *)(s1 + 0x2F4) = 0;
        *(char *)(s1 + 0x2F6) = 0;
        *(char *)(s1 + 0x2F5) = 0x13;
        return 1;
    }
    default:
        return 0;
    }
}
