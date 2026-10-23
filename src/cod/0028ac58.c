/* sn-2.95.3-136: func_0028AC58, sets up an enemy model from its data pack: looks up the model and texture blocks
 * for the character index, applies the kind's alternate textures picked by the 0x155C flags, then builds the model. */
typedef struct EmModelObj {
    char pad000[0x254];
    unsigned int flags254;              /* 0x254 */
    char pad258[0x2FE - 0x258];
    unsigned short id;                  /* 0x2FE */
    char pad300[4];
    char *pack;                         /* 0x304 */
    char pad308[0x564 - 0x308];
    int kind;                           /* 0x564 */
    char pad568[0x155C - 0x568];
    unsigned int texFlags;              /* 0x155C */
} EmModelObj;

extern char D_00448E10[];
extern char D_00448E18[];
extern int GetEm00CharIndex(int id, int kind);
extern void Obj0000_Set_Field_424_1595E8(int *self, int v);
extern void *SearchData(void *pack, char *name, int index);
extern void cModel_setTextureExchange(void *model, void *tex, void *alt, int slot);
extern int cModel_setupModel(void *model, void *mdl, void *tex, int a3, int a4);

#define TEX_EXCHANGE(o, tex, off, slot) \
    ((o)->flags254 |= 0x10000000, \
     cModel_setTextureExchange((o), (tex), (void *)(*(int *)((o)->pack + (off)) + (int)(o)->pack), (slot)))

__attribute__((section(".text.func_0028AC58")))
int func_0028AC58(EmModelObj *o)
{
    int idx;
    void *mdl;
    void *tex;

    idx = GetEm00CharIndex(o->id, o->kind);
    Obj0000_Set_Field_424_1595E8(o, 0);
    mdl = SearchData(o->pack, D_00448E10, idx);
    tex = SearchData(o->pack, D_00448E18, idx);
    switch (o->kind) {
    case 0x2A7:
        if (o->texFlags & 1)
            TEX_EXCHANGE(o, tex, 0x44, 0);
        break;
    case 0x2A9:
        if (o->texFlags & 1)
            TEX_EXCHANGE(o, tex, 0x48, 0);
        break;
    case 0x2AB:
        if (o->texFlags & 1)
            TEX_EXCHANGE(o, tex, 0x4C, 0);
        if (o->texFlags & 2)
            TEX_EXCHANGE(o, tex, 0x4C, 1);
        break;
    }
    if (tex != 0)
        return cModel_setupModel(o, mdl, tex, 0, 0);
    return 0;
}
