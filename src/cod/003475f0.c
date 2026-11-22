/* cygnus-2.96: mwsftag_GetSFXinfFromAinf, searches the stored chunk at +0x194 for the tag and hands the result to
 * SFX_SetTagInf. */
#include "godhand/criSj.h"
typedef struct {
    char pad0[0xA8];
    void *taghn; /* 0xA8 */
    char padAC[0x194 - 0xAC];
    SjTagRec rec; /* 0x194 */
} SfxWork;
extern Sint8 D_00458CE0[];
extern Sint8 D_00458CE8[];
extern void SFX_SetTagInf(void *hn, Sint8 *data, Sint32 len);

__attribute__((section(".text.mwsftag_GetSFXinfFromAinf")))
void mwsftag_GetSFXinfFromAinf(SfxWork *w)
{
    SjTagRec *rec = &w->rec;
    SjChunk ck;
    SjChunk tag;
    void *hn;

    hn = w->taghn;
    if (rec->ck.data == 0) {
        SFX_SetTagInf(hn, 0, 0);
        return;
    }
    ck.data = rec->ck.data;
    ck.len = rec->ck.len;
    if (SJ_SearchTag(&ck, D_00458CE0, D_00458CE8, &tag) == 0)
        SFX_SetTagInf(hn, 0, 0);
    else
        SFX_SetTagInf(hn, tag.data, tag.len);
}
