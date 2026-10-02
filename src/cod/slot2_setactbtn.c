/* Slot2_SetActBtn — register the action-button handler Slot2_actBtnHandler for slot 2
 * (table D_00568288, fields 4/0x15) with the object a0.  sn-2.95.3-136. */

extern void cActionButton_set(void *, int, int, int, void *, void *, int);
extern char D_00568288;
extern void Slot2_actBtnHandler(void);

__attribute__((section(".text.Slot2_SetActBtn")))
void Slot2_SetActBtn(void *a0) {
    cActionButton_set(&D_00568288, 4, 0x15, 0, (void *)&Slot2_actBtnHandler, a0, 0);
}
