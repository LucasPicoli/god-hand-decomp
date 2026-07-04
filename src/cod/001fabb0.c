/* sn-2.95.3-136 matched TU. */

struct save_s {
    volatile unsigned char items_pad[0xA8];
    volatile unsigned char items[6];
    unsigned char pad2[0xA8];
    unsigned char count;
};

__attribute__((section(".text.cCoreSave_getGodItemNum")))
int cCoreSave_getGodItemNum(struct save_s **pp) {
    unsigned int i;
    int n;

    n = 0;
    for (i = 0; (i < 6) && (i < (*pp)->count); i++) {
        if ((*pp)->items[i] != 0) {
            n++;
        }
    }
    return n;
}
