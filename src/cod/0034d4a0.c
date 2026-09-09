/* cygnus-2.96 matched TU. */

typedef struct Hds {
    char pad0[0x90];
    int f90;
    char f94[4];
} Hds;

extern void *SFH_Create(void *buf, int size);
extern void sfhds_DoProcessHdr(void *h, Hds *p);
extern void SFH_Destroy(void *h);

__attribute__((section(".text.SFHDS_ProcessHdr")))
void SFHDS_ProcessHdr(Hds *p)
{
    void *h;

    h = SFH_Create(p->f94, p->f90);
    if (h == 0) return;
    sfhds_DoProcessHdr(h, p);
    SFH_Destroy(h);
}
