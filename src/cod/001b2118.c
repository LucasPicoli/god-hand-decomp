/* sn-2.95.3-136 matched TU. */

extern void cOmBase_setTexChange(char *obj, int mode);

__attribute__((section(".text.cOm71__SetTexColor")))
void cOm71__SetTexColor(char *obj, unsigned short color)
{
    if (color < 5) {
        *(unsigned short *)(obj + 0x604) = color;
        switch (*(unsigned short *)(obj + 0x604)) {
        case 1:
            cOmBase_setTexChange(obj, 0);
            break;
        case 2:
            cOmBase_setTexChange(obj, 1);
            break;
        case 3:
            cOmBase_setTexChange(obj, 2);
            break;
        case 4:
            cOmBase_setTexChange(obj, 3);
            break;
        case 0:
        default:
            break;
        }
    }
}
