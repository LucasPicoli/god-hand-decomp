/* include/godhand/sfxalp.h - the SFX alpha-plane handle pool (sfxalp_*, cygnus code).
 *
 * One 0x128-byte work block at D_003F1EC8: a count of handles in use, the
 * number of handles (func_0036CA68 sets 8), then the handles themselves.
 * sfxalp_SearchFreeHn returns the first handle whose used word is 0.
 * Names are ours; unnamed fields stay as unkNN padding.
 */
#ifndef GODHAND_SFXALP_H
#define GODHAND_SFXALP_H

#define SFXALP_HN_NUM  8                /* handles in the pool */

typedef struct SfxAlpHn {
    int used;                           /* 0x00 nonzero while the handle is taken */
    char unk04[0x24 - 0x04];
} SfxAlpHn;                             /* 0x24 */

typedef struct SfxAlpWork {
    int nUsed;                          /* 0x00 handles in use */
    int nHn;                            /* 0x04 handles in the pool */
    SfxAlpHn hn[SFXALP_HN_NUM];         /* 0x08 */
} SfxAlpWork;                           /* 0x128 */

typedef char SfxAlpHn_size_check[sizeof(SfxAlpHn) == 0x24 ? 1 : -1];
typedef char SfxAlpWork_size_check[sizeof(SfxAlpWork) == 0x128 ? 1 : -1];

#endif
