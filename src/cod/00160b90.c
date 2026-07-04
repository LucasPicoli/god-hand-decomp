/* sn-2.95.3-136 matched TU. */

extern int D_00747A2C;
extern void func_00160D50(char *);
extern char *Obj0000_Call_func_0015FD18_Field_48_161288(char *);

__attribute__((section(".text.func_00160B90")))
void func_00160B90(char *arg)
{
    int *base;
    char *obj;
    short t;
    int v;
    void (*fn)(char *);

    base = &D_00747A2C;
    if (base[0] < 0) {
        return;
    }
    if (base[0x14] & 0x100000) {
        return;
    }
    func_00160D50(arg);
    obj = Obj0000_Call_func_0015FD18_Field_48_161288(arg);
    if (obj == 0) {
        return;
    }
    if (*(unsigned char *)(obj + 0x59) != 0) {
        return;
    }
    t = *(unsigned short *)(arg + 0x50) - 4;
    switch (t) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 6:
    case 10:
    case 13:
        v = *(int *)(obj + 0x70);
        fn = *(void (**)(char *))(v + 0x34);
        fn(obj + *(short *)(v + 0x30));
        break;
    }
}
