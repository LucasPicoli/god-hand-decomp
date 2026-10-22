#ifndef GODHAND_EMPHASETABLE_H
#define GODHAND_EMPHASETABLE_H

/* Enemy/gimmick phase table: one pointer-to-member handler per phase, indexed by the phase byte
 * (0x2F4 or 0x2F5 in the work). index >= 0 is a virtual slot in the vtable found at tableOff;
 * otherwise the handler address sits at +4. adjust is the this-pointer delta. */
typedef struct EmPhaseEnt {
    short adjust;                       /* 0x00 */
    short index;                        /* 0x02 */
    short tableOff;                     /* 0x04 */
    short unk06;
} EmPhaseEnt;
typedef struct EmPhaseTable { EmPhaseEnt e[1]; } EmPhaseTable;

#endif /* GODHAND_EMPHASETABLE_H */
