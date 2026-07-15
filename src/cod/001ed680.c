/* sn-2.95.3-136 matched TU. */

extern void func_001ED848(void *a0);
extern void CustomIDWork_Main(void *a0);
extern void cIDBase_move(void *a0);

__attribute__((section(".text.func_001ED680")))
void func_001ED680(void *a0) {
    char *p;
    int i;

    func_001ED848(a0);
    p = (char *)a0 + 0x60;
    for (i = 5; i >= 0; i--) {
        CustomIDWork_Main(p);
        p += 0x7C;
    }
    cIDBase_move((char *)a0 + 0x10);
}
