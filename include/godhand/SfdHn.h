/* include/godhand/SfdHn.h - the Sofdec stream handle as the condition setters see it.
 *
 * Only the pointer to the Sofdec core handle is named: every SFD_SetCond
 * call takes that, not the wrapper. Names are ours. Offsets are exact. A
 * field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_SFDHN_H
#define GODHAND_SFDHN_H

typedef struct SfdHn {
    char unk00[0x3C];
    void *sfd;                  /* 0x3C the Sofdec handle the conditions go to */
} SfdHn;

#endif /* GODHAND_SFDHN_H */
