/* cygnus-2.96: SFTIM_VbIn, vblank-in: count the vblank and tick the timer of every active handle. */
typedef struct {
    int vcount;
    char pad04[0x54 - 0x04];
    void *hn[8];
} SfdLibWork;

extern SfdLibWork D_003EE270;
extern int Obj34D8_SetGlobalEE0B8_IfField48(void *hn);
extern void sftim_HnVbIn(void *hn);

__attribute__((section(".text.SFTIM_VbIn")))
void SFTIM_VbIn(void)
{
    int i;
    void *hn;

    D_003EE270.vcount++;
    for (i = 0; i < 8; i++) {
        hn = D_003EE270.hn[i];
        if (Obj34D8_SetGlobalEE0B8_IfField48(hn) != -1)
            sftim_HnVbIn(hn);
    }
}
