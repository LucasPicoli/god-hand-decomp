/* sn-2.95.3-136: left/right pad input steps the current item's value through -15..15
 * with wrap-around and pushes it to the bound object (0x3813C8). */

#define PAD_LEFT    0x8000
#define PAD_RIGHT   0x2000
#define VALUE_MIN   (-15)
#define VALUE_MAX   15
#define ITEMS_OFS   0x58        /* ValueMenu.items */

typedef struct ValueItem {
    char unk00[0x20];
    int value;                  /* 0x20 */
    char unk24[0x0C];
    void *obj;                  /* 0x30 */
    char unk34[0x48 - 0x34];
} ValueItem;

typedef struct ValueMenu {
    char unk00[5];
    unsigned char cur;          /* 0x05 */
    char unk06[0x58 - 0x06];
    ValueItem items[1];         /* 0x58 */
} ValueMenu;

typedef struct PadCtrl {
    char unk00[0x38];
    int trig;                   /* 0x38 */
} PadCtrl;

extern void ADXT_SetOutBalance(void *obj, int value);

__attribute__((section(".text.func_003813C8")))
void func_003813C8(ValueMenu *self, PadCtrl *ctrl)
{
    ValueItem *item = (ValueItem *)((char *)self + self->cur * sizeof(ValueItem) + ITEMS_OFS);
    int c;
    void *obj;

    if ((ctrl->trig & PAD_LEFT) != 0) {
        c = item->value;
        if (c < VALUE_MIN + 1)
            item->value = VALUE_MAX;
        else
            item->value = c - 1;
        obj = item->obj;
        if (obj != 0)
            ADXT_SetOutBalance(obj, item->value);
    }
    if ((ctrl->trig & PAD_RIGHT) != 0) {
        c = item->value;
        if (c < VALUE_MAX)
            item->value = c + 1;
        else
            item->value = VALUE_MIN;
        obj = item->obj;
        if (obj != 0)
            ADXT_SetOutBalance(obj, item->value);
    }
}
