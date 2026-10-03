/* sn-2.95.3-136 matched TU. */

extern void UpdateObjByIndexedOp_2FBE50(void *slot);
extern int ClearField5B4IfFlagUnset_1B76B0(int a0);
extern int cDamageManage_CkHitStop(void *mgr);
extern void func_001B1860(void *a0);
extern void func_001B1938(void *a0);
extern void func_001B1630(void *a0);
extern void func_001B76D8(void *a0);
extern float cEmManage_GetSpeedRate(void *a0);
extern char D_005864F0[];
extern char D_00574380[];

extern int D_0071B7C0[];                /* bit set: slot in use */
extern int D_0071B840[];                /* bit set: slot paused */
extern int D_0071B8C0[];                /* bit set: slot hidden */
extern unsigned char D_0061B7C0[];      /* the 0x400 effect slots, 0x400 bytes each */


#define ESP_SLOT_NUM     0x400
#define ESP_SLOT_SIZE    0x400
#define ESP_SLOT_GROUPS  0x104          /* offset of the slot's group mask word */

/* Run the kill handler of every effect slot that is in use, neither paused nor hidden, and whose group mask has a bit of mask. */
__attribute__((section(".text.func_002FB7B0")))
void func_002FB7B0(int mask) {
    unsigned char *p;
    int i;
    unsigned int bit;
    int w;

    for (i = 0; i < ESP_SLOT_NUM; i++) {
        w = (unsigned int)i >> 5;
        bit = 0x80000000u >> (i & 0x1F);
        if ((D_0071B7C0[w] & bit) == 0) goto next;
        if ((D_0071B840[w] & bit) != 0) goto next;
        if ((D_0071B8C0[w] & bit) != 0) goto next;
        p = D_0061B7C0 + i * ESP_SLOT_SIZE;
        if ((*(int *)(p + ESP_SLOT_GROUPS) & mask) == 0) goto next;
        UpdateObjByIndexedOp_2FBE50(p);
next: ;
    }
}

/* One row of the mode table: this adjust, method index (or -1), table offset in the object, or the inline handler. */
struct Entry_func_001B0F70 { short f0; short f2; short f4; short f6; };
struct Table_func_001B0F70 { struct Entry_func_001B0F70 e[1]; };

extern struct Table_func_001B0F70 D_003BDCC0;

/* Mode tick: unless a hit stop is running, refresh the speed rate, run the handler of the mode's table row, then the shared post-update steps. */
__attribute__((section(".text.func_001B0F70")))
void func_001B0F70(void *a0)
{
    char *s0 = (char *)a0;
    char *e;
    int i8;
    int f0;
    float rate;
    int type; int arg; int (*fp)(int); long entry;
    if (ClearField5B4IfFlagUnset_1B76B0((int)s0) == 0) return;
    if (cDamageManage_CkHitStop(D_00574380) != 0) return;
    func_001B1860(s0);
    rate = cEmManage_GetSpeedRate(D_005864F0);
    *(float *)(s0 + 0x5A8) = rate;
    i8 = *(unsigned char *)(s0 + 0x2F4) * 8;
    e = (char *)&D_003BDCC0 + i8;
    type = *(short *)(e + 2);
    if (type >= 0) {
        int base = *(int *)(s0 + *(short *)(e + 4));
        entry = *(long *)(base + type * 8 - 8);
        fp = (int (*)(int))(int)(entry >> 32);
    } else {
        fp = *(int (**)(int))((char *)&D_003BDCC0 + i8 + 4);
    }
    f0 = D_003BDCC0.e[*(unsigned char *)(s0 + 0x2F4)].f0;
    if (type >= 0)
        arg = (short)entry + f0;
    else
        arg = f0;
    fp((int)(s0 + arg));
    func_001B1938(s0);
    func_001B1630(s0);
    func_001B76D8(s0);
}
