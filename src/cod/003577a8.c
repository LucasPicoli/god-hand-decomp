/* cygnus-2.96: sfply_AdjustEtrg, derives element 0x19 of the A0C array from the two enable flags
 * (1 = first only, 2 = second only, both = keep a set value or pick 3, neither = 3). */
typedef struct {
    char pad0[0x14];
    int on2; /* 0x14 */
    int on1; /* 0x18 */
} ElemEnableFlags;
typedef struct {
    char pad0[0xA0C];
    ElemEnableFlags flags; /* 0xA0C */
} ElemArrayOwner;
extern int GetArrayElemA0C_35A1C8(ElemArrayOwner *p, int idx);
extern int Obj0000_Get_D_003EEA70_LT_2_360C40(void);
extern void SFSET_SetCond(ElemArrayOwner *p, int idx, int val);

__attribute__((section(".text.sfply_AdjustEtrg")))
void sfply_AdjustEtrg(ElemArrayOwner *p)
{
    ElemEnableFlags *f = &p->flags;
    unsigned int st;
    int val;

    st = 0;
    if (f->on1 == 1)
        st = 1;
    if (f->on2 == 1)
        st |= 2;
    switch (st) {
    case 1:
        val = 1;
        break;
    case 2:
        val = 2;
        break;
    case 3:
        val = GetArrayElemA0C_35A1C8(p, 0x19);
        if (val == 0) {
            if (Obj0000_Get_D_003EEA70_LT_2_360C40() != 0 || GetArrayElemA0C_35A1C8(p, 0x48) == 0)
                val = 3;
        }
        break;
    default:
        val = 3;
        break;
    }
    SFSET_SetCond(p, 0x19, val);
}
