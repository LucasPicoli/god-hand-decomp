/* sn-2.95.3-136 matched TU. */

extern void cRoomSave_setEmDeadFlag(void *a0, int a1);
extern char D_005E8658;

__attribute__((section(".text.func_0028FB08")))
void func_0028FB08(void *a0)
{
    unsigned short id;
    id = *(unsigned short *)((char *)a0 + 0x640);
    if (id != 0xFF) {
        cRoomSave_setEmDeadFlag(&D_005E8658, id);
    }
}
