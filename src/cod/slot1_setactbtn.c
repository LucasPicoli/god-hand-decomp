/* Slot1_SetActBtn — register the action-button handler func_001DFD90 for slot 1
 * (table D_00568288, fields 4/0x15) with the object a0, via
 * cActionButton_set.  sn-2.95.3-136. */

extern void cActionButton_set(void *, int, int, int, void *, void *, int);
extern char D_00568288;
extern void func_001DFD90(void);

__attribute__((section(".text.Slot1_SetActBtn")))
void Slot1_SetActBtn(void *a0) {
    cActionButton_set(&D_00568288, 4, 0x15, 0, (void *)&func_001DFD90, a0, 0);
}
