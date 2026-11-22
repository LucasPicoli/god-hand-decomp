/* cygnus-2.96: Sofdec picture-buffer put/advance wrappers (0x3568B8..). */

#include "godhand/sftim.h"

extern int SFMPVP_IsSceMpegUsed(SftimHn *hn);
extern int sfmpvp_PutVibuf(ViBuf *b, unsigned int src, int len);
extern int viBufUnput(ViBuf *b, int n);

__attribute__((section(".text.SFMPVP_Put")))
int SFMPVP_Put(SftimHn *hn, unsigned int src, int len)
{
    if (SFMPVP_IsSceMpegUsed(hn) == 0) {
        return len;
    }
    return sfmpvp_PutVibuf(SFD_WORK_VIBUF(hn->work), src, len);
}

__attribute__((section(".text.SFMPVP_Unput")))
int SFMPVP_Unput(SftimHn *hn, int n)
{
    if (SFMPVP_IsSceMpegUsed(hn) == 0) {
        return n;
    }
    return viBufUnput(SFD_WORK_VIBUF(hn->work), n);
}
