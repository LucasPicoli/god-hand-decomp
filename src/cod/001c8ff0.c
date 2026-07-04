/* sn-2.95.3-136 matched TU. */

extern void cOmBase_setTexChange(char *obj, int mode);

__attribute__((section(".text.cOmTrump_Initialize")))
int cOmTrump_Initialize(char *obj, int arg1)
{
    func_001B6FB8(obj);
    switch (*(unsigned short *)(obj + 0x2FE)) {
    case 0x3E4:
        *(int *)(obj + 0x600) = 4;
        cOmBase_setTexChange(obj, 0);
        break;
    case 0x3E5:
        *(int *)(obj + 0x600) = 0;
        cOmBase_setTexChange(obj, arg1);
        break;
    case 0x3E6:
        *(int *)(obj + 0x600) = 1;
        cOmBase_setTexChange(obj, arg1);
        break;
    case 0x3E7:
        *(int *)(obj + 0x600) = 2;
        cOmBase_setTexChange(obj, arg1);
        break;
    case 0x3E8:
        *(int *)(obj + 0x600) = 3;
        cOmBase_setTexChange(obj, arg1);
        break;
    default:
        return 0;
    }
    *(int *)(obj + 0x604) = arg1;
    return 1;
}
