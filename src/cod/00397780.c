/* ee-2.9-991111 matched TU. */

extern int D_003F8664;
extern void (*D_003F85D0)(int port);
extern void *D_0077C380;

#include "godhand/gp.h"

extern void (*D_0077C3C8)(void *);   /* sceCdPoffCbfunc */
extern void *D_0077C3CC;             /* its gp */
extern void *D_0077C3D0;             /* sceCdPoffCbdata */


__attribute__((section(".text._sceCd_Poff_Intr")))
void _sceCd_Poff_Intr(void)
{
    void *oldgp;

    if (D_0077C3C8 != 0) {
        if (D_003F8664 == 0) {
            GH_SWAPGP_MEM(oldgp, D_0077C3CC);
            D_0077C3C8(D_0077C3D0);
            GH_PUTGP(oldgp);
        }
    }
}

#include <godhand/gp.h>
#include <godhand/sync.h>


typedef struct {
    int f0;
    int f4;
    int f8;
    int port;
} PadDmaData;




__attribute__((section(".text._pad_intr_hdr")))
void _pad_intr_hdr(volatile PadDmaData *dd)
{
    void (*cb)(int);

    cb = D_003F85D0;
    if (cb != 0) {
        void *oldgp;
        GH_SWAPGP_MEM(oldgp, D_0077C380);
        cb(dd->port);
        GH_PUTGP(oldgp);
    }
    GH_SYNC();
    GH_EI();
}
