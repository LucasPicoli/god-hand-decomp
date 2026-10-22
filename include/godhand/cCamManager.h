/* include/godhand/cCamManager.h - cCamManager, the owner of the game cameras.
 *
 * A cCamManager holds several cameras back to back (the motion camera starts
 * at 0x530), the camera that was current before the last switch (0xFF0), and
 * a mode word (0x1028) that says which camera is current. The setXxxCamera
 * methods in camera/cCamManager.c switch the mode and publish the new camera
 * in the global D_005CAFF0.
 *
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact. A field we can't name yet stays as unkNNN padding.
 */
#ifndef GODHAND_CCAMMANAGER_H
#define GODHAND_CCAMMANAGER_H

/* Values of cCamManager.mode. */
#define CAMMGR_MODE_PLAYER   0x01       /* player camera */
#define CAMMGR_MODE_MOTION   0x04       /* motion camera, at 0x530 */
#define CAMMGR_MODE_NO_MOVE  0x04       /* with this bit set, update does not call cCamera_move */
#define CAMMGR_MODE_SUBSCR   0x80       /* sub-screen camera */

typedef struct cCamManager {
    char unk000[0xFF0];
    void *prevCamera;                   /* 0xFF0 camera that was current before the switch */
    char unkFF4[0x1028 - 0xFF4];        /* 0xFF4 state that func_00137F38 updates */
    int mode;                           /* 0x1028 CAMMGR_MODE_* */
    int prevMode;                       /* 0x102C */
} cCamManager;

struct cCamera;
extern struct cCamera *D_005CAFF0;     /* the current camera */

#endif
