/* ee-2.9-991111 matched TU. */
#include "godhand/globals.h"

extern void func_003A52F0(void *, int, int);

/* ee-2.9-991111 */

extern unsigned int _sceSifSendCmd(unsigned int fid, int mode, void *pkt, int pktsize,
                                   void *src, void *dest, int size);

__attribute__((section(".text.sceSifSendCmd")))
unsigned int sceSifSendCmd(unsigned int fid, void *pkt, int pktsize,
                           void *src, void *dest, int size)
{
    return _sceSifSendCmd(fid, 0, pkt, pktsize, src, dest, size);
}

/* ee-2.9-991111 */

extern unsigned int _sceSifSendCmd(unsigned int fid, int mode, void *pkt, int pktsize,
                                   void *src, void *dest, int size);

__attribute__((section(".text.isceSifSendCmd")))
unsigned int isceSifSendCmd(unsigned int fid, void *pkt, int pktsize,
                            void *src, void *dest, int size)
{
    return _sceSifSendCmd(fid, 1, pkt, pktsize, src, dest, size);
}

/* ee-2.9-991111 */





__attribute__((section(".text.sceFsReset")))
int sceFsReset(void)
{
    D_003FAEDC = 0;
    func_003A52F0(D_007816E8, 0, 4);
    return 0;
}
