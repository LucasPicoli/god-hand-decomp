/* cygnus-2.96 matched TU. */
#include "godhand/mwsfd.h"

#define SFD_ERR_CONCAT_PLAY_INVALID_HANDLE  0xFF000161
#define SFSET_COND_CONCAT_PLAY              0x31
#define SFD_CONCAT_PLAY_ENABLED             1

extern int Obj34D8_SetGlobalEE0B8_IfField48(SfdHn *sfd);

/* Enable concatenated playback on a valid Sofdec handle. */
__attribute__((section(".text.SFD_SetConcatPlay")))
int SFD_SetConcatPlay(SfdHn *sfd)
{
    if (Obj34D8_SetGlobalEE0B8_IfField48(sfd) != 0) {
        return func_0034DD70(0, SFD_ERR_CONCAT_PLAY_INVALID_HANDLE);
    }
    func_0035A000(sfd, SFSET_COND_CONCAT_PLAY, SFD_CONCAT_PLAY_ENABLED);
    return 0;
}
