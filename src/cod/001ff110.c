/* sn-2.95.3-136 matched TU. */

extern int UpdateStateReady_1FF238(void *a0);
extern void cDataManager_retireSlot(void *a0);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.func_001FF110")))
void func_001FF110(void *a0) {
    int *a1 = (int *)a0;

    switch (*a1) {
    case 1:
        UpdateStateReady_1FF238(a1);
        break;
    case 5:
        *a1 = 6;
        break;
    case 6:
        *a1 = 7;
        break;
    case 7:
        cDataManager_retireSlot(a1);
        break;
    case 0:
    case 2:
    case 4:
    case 8:
        break;
    }
}
