/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_00293760")))
void func_00293760(char *a0, void *a1) {
    if (a1 == 0) {
        return;
    }
    switch (*(int *)((char *)a1 + 0x564)) {
    case 0x270:
        *(void **)(a0 + 0x578) = a1;
        break;
    case 0x271:
        *(void **)(a0 + 0x57C) = a1;
        break;
    case 0x272:
        *(void **)(a0 + 0x580) = a1;
        break;
    case 0x273:
        *(void **)(a0 + 0x584) = a1;
        break;
    case 0x274:
        *(void **)(a0 + 0x574) = a1;
        break;
    }
}
