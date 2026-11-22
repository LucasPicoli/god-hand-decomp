/* sn-2.95.3-136: func_0030A200, when entry n is ready, sync and send its two GIF packets (+0x8, +0xC). */
typedef struct {
    unsigned char pad0;
    unsigned char ready;
    char pad2[0x08 - 0x02];
    void *pkt0;
    void *pkt1;
    char pad10[0xB0 - 0x10];
} GifPktEnt;

extern GifPktEnt D_00747BA0[];
extern int sceDmaSync(void *chan, int mode, int timeout);
extern void sceDmaSend(void *chan, void *tag);

__attribute__((section(".text.func_0030A200")))
void func_0030A200(int n)
{
    GifPktEnt *e = &D_00747BA0[n];

    if (e->ready == 1) {
        sceDmaSync((void *)0x1000A000, 0, 0);
        sceDmaSend((void *)0x1000A000, e->pkt0);
        sceDmaSync((void *)0x1000A000, 0, 0);
        sceDmaSend((void *)0x1000A000, e->pkt1);
    }
}
