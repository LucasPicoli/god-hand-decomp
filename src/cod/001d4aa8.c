/* sn-2.95.3-136 matched TU. */

extern void func_001D69E8(char *, int);
extern void func_001D6C70(char *, int);
extern void func_001D6C90(char *, int);
extern void func_001D6CD8(char *, int);

__attribute__((section(".text.func_001D4AA8")))
void func_001D4AA8(char *arg, unsigned char mode)
{
    func_001D69E8(arg, 0);
    func_001D6C70(arg, 0);
    func_001D6C90(arg, 0);
    func_001D6CD8(arg, 0);
    switch (mode) {
    case 1:
        func_001D69E8(arg, 1);
        break;
    case 2:
        func_001D6C70(arg, 1);
        break;
    case 3:
        func_001D6C90(arg, 1);
        break;
    case 4:
        func_001D6CD8(arg, 1);
        break;
    case 0:
    default:
        break;
    }
}
