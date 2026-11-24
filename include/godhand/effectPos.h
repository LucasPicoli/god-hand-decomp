/* include/godhand/effectPos.h - SetEffectPos (0x306838). */
#ifndef GODHAND_EFFECTPOS_H
#define GODHAND_EFFECTPOS_H

#include "godhand/cVecType.h"

struct cObj;

/* Start effect id at pos with the default parameters and the given size. */
void SetEffectPos(int kind, int id, struct cObj *owner, const cVec *pos, float size, int handle);

#endif /* GODHAND_EFFECTPOS_H */
