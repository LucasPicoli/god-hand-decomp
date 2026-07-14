/* sn-2.95.3-136 matched TU. */

extern void SetSlotField98_1FC170(void *obj, int idx, int val);

typedef struct SlotObj {
    int base;
} SlotObj;

__attribute__((section(".text.func_001FC278")))
void func_001FC278(SlotObj *obj) {
    unsigned int i;

    if (obj->base != 0) {
        for (i = 0; i < 10; i++) {
            *(unsigned char *)(obj->base + i + 0x98) = 0x1F;
        }
        SetSlotField98_1FC170(obj, 0, 1);
        SetSlotField98_1FC170(obj, 1, 2);
        SetSlotField98_1FC170(obj, 2, 3);
        SetSlotField98_1FC170(obj, 3, 7);
        SetSlotField98_1FC170(obj, 4, 0xE);
        SetSlotField98_1FC170(obj, 5, 0x17);
    }
}
