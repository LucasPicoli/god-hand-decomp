/* sn-2.95.3-136 matched TU. */

extern void FileNameFromObjId(char *buf, int id);
extern int GetBuiltPackedAddr_1FFA28(void *a0, char *a1);
extern void func_00201108(void *a0, int a1);
extern int D_00752C38[];
extern char D_00580D40[];
extern char D_00583F20[];

/* sn-2.95.3-136 candidate. */









__attribute__((section(".text.func_0030D8E0")))
void func_0030D8E0(int objid)
{
    char buf[0x10];
    int id2;
    int r;

    id2 = 0x101;
    switch (objid) {
    case 0x109:
        id2 = 0x10A;
        break;
    case 0x105:
    case 0x10F:
        id2 = 0x106;
        break;
    case 0x107:
    case 0x110:
        id2 = 0x108;
        break;
    case 0x10E:
    case 0x111:
        id2 = 0x112;
        break;
    case 0x100:
    default:
        break;
    }

    FileNameFromObjId(buf, objid);
    GetBuiltPackedAddr_1FFA28(D_00580D40, buf);
    r = func_00200B88(D_00583F20, buf, D_00752C38[0], 0, 0, 0, 0);
    func_00201108(D_00583F20, r);
    FileNameFromObjId(buf, id2);
    GetBuiltPackedAddr_1FFA28(D_00580D40, buf);
    func_00200B88(D_00583F20, buf, D_00752C38[1], r, 0, 0, 0);
    func_00201108(D_00583F20, r);
}
