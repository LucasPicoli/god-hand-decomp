/* sn-2.95.3-136 matched TU. */

extern void func_0014EAD8(unsigned char *);
extern void func_0014EB90(unsigned char *);
extern void func_0014EC88(unsigned char *);
extern void func_0014ED60(unsigned char *);
extern void func_0014EE60(unsigned char *);

__attribute__((section(".text.cObjBase_R0_scenario")))
void cObjBase_R0_scenario(unsigned char *obj) {
    switch (obj[0x2F5]) {
    case 1:
        func_0014EAD8(obj);
        break;
    case 2:
        func_0014EB90(obj);
        break;
    case 3:
        func_0014EC88(obj);
        break;
    case 4:
        func_0014ED60(obj);
        break;
    case 5:
        func_0014EE60(obj);
        break;
    case 0:
    case 0xF:
    default:
        break;
    }
}
