/* sn-2.95.3-136 matched TU. */

#include "godhand/cSnd.h"

extern void func_0030A538(float *pos, int mtx);
extern void func_002CE3E8(cSndSeVoice *v);
extern int D_0044CE48[];
extern cSndSeEntry *GetIndexedEntry_2CC4B8(cSnd *self, int idx);

/* Starts a free voice with the given key pair and ids, at the global origin. */
__attribute__((section(".text.cSndSeVoice_StartAtOrigin")))
int cSndSeVoice_StartAtOrigin(cSndSeVoice *v, short key0, short key1, short idA, short idB, int a5, int a6)
{
    if (func_002CDA38(v) == 1)
        return 0;
    v->idA = idA;
    v->idB = idB;
    v->obj = 0;
    v->part = 0;
    v->kind = 0;
    v->pos[0] = 0;
    v->pos[1] = 0;
    v->pos[2] = 0;
    v->scale = 1.0f;
    return func_002CDFF0(v, key0, key1, a5, a6);
}

#define OBJ_MTX_OFFSET 0xF0



/* Detaches a voice from the object it follows, first copying the object's position unless the voice is live (flag 1).
   The flag byte is read as ((unsigned char)flags ^ 1) & 1; the plain !(flags & 1) gives different bytes. */
__attribute__((section(".text.cSndSeVoice_Detach")))
void cSndSeVoice_Detach(cSndSeVoice *v, char *obj)
{
    if (func_002CDA38(v) == 0)
        return;
    if (v->obj != obj)
        return;
    if (((unsigned char)v->flags ^ 1) & 1) {
        if (v->part == 0)
            func_0030A538(v->pos, *(int *)(obj + OBJ_MTX_OFFSET));
        else
            func_0030A538(v->pos, *(int *)((char *)v->part + OBJ_MTX_OFFSET));
    }
    v->obj = 0;
    v->part = 0;
}

/* Releases a voice with this key. With mode 1 a voice that has a live handle is left alone. */
__attribute__((section(".text.cSndSeVoice_Release")))
void cSndSeVoice_Release(cSndSeVoice *v, short key, int mode)
{
    if (func_002CDA38(v) == 0)
        return;
    if (v->key0 != key)
        return;
    if (mode == 1) {
        if (v->flags & 1)
            return;
    }
    func_002CE3E8(v);
}

/* Returns the first slot id in the D_0044CE48 table whose entry has no owner, or -1. */
__attribute__((section(".text.cSnd_FindFreeSe")))
int cSnd_FindFreeSe(cSnd *self)
{
    int *p = D_0044CE48;
    unsigned int i;
    for (i = 0; i < 0xC; i++, p++) {
        if (GetIndexedEntry_2CC4B8(self, *p)->owner == -1)
            return *p;
    }
    return -1;
}
