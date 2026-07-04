/* sn-2.95.3-136 matched TU. */

extern void func_001D69A0(void *, int);
extern void func_001D6BC0(void *, int);
extern void func_001D6BE0(void *, int);
extern void func_001D6C28(void *, int);

__attribute__((section(".text.func_001D49E0")))
void func_001D49E0(void *obj, unsigned char n)
{
    func_001D69A0(obj, 0);
    func_001D6BC0(obj, 0);
    func_001D6BE0(obj, 0);
    func_001D6C28(obj, 0);
    switch (n) {
    case 1:
        func_001D69A0(obj, 1);
        break;
    case 2:
        func_001D6BC0(obj, 1);
        break;
    case 3:
        func_001D6BE0(obj, 1);
        break;
    case 4:
        func_001D6C28(obj, 1);
        break;
    case 0:
    default:
        break;
    }
}
