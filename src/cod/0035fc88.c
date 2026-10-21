/* cygnus-2.96: func_0035FC88, records the tag chunk at +0x14 of the handle and forwards the found tag to
 * SFXZ_SetTagInf. */
#include "godhand/sfxlib.h"
typedef struct {
    char pad0[0x14];
    SjTagRec rec; /* 0x14 */
    char pad20[4];
    SfxZmvTagState *sfxz;       /* 0x24 */
} TagHn;
extern Sint8 D_0045A050[];
extern Sint8 D_0045A058[];

__attribute__((section(".text.func_0035FC88")))
void func_0035FC88(TagHn *hn, Sint8 *data, Sint32 len)
{
    SjTagRec *rec = &hn->rec;
    SjChunk ck;
    SjChunk tag;
    SfxZmvTagState *sfxz;

    rec->ck.data = data;
    rec->ck.len = len;
    sfxz = hn->sfxz;
    ck.data = data;
    ck.len = len;
    if (SJ_SearchTag(&ck, D_0045A050, D_0045A058, &tag) == 0)
        SFXZ_SetTagInf(sfxz, 0, 0);
    else
        SFXZ_SetTagInf(sfxz, tag.data, tag.len);
    rec->set = SJ_TAG_SET;
}
