/* include/godhand/FileLoadRec.h - FileLoadRec, one object file load in flight.
 *
 * A record is started with an object id: it converts the id (func_003078E0),
 * builds the file name (FileNameFromObjId) and asks cDvd_ReadAlloc to read the
 * file into a buffer it allocates. `handle` is what cDvd_ReadAlloc returned and
 * `data` receives the buffer. The record is at least 0x24 bytes.
 *
 * Field names are ours, taken from the functions that read and write them.
 * Offsets are exact. A field we can't name yet stays as unkNN padding.
 */
#ifndef GODHAND_FILELOADREC_H
#define GODHAND_FILELOADREC_H

#define FILELOAD_STATE_READING   1      /* state: the read was started */
#define FILELOAD_FLAG_STARTED    1      /* flags bit 0 */

typedef struct FileLoadRec {
    int state;                          /* 0x00 FILELOAD_STATE_* */
    int unk04;
    unsigned int flags;                 /* 0x08 FILELOAD_FLAG_* */
    int result;                         /* 0x0C func_003078E0(objId) */
    void *data;                         /* 0x10 the buffer the read fills */
    int arg;                            /* 0x14 passed on to cDvd_ReadAlloc */
    char unk18[4];
    int handle;                         /* 0x1C cDvd_ReadAlloc's handle, 0 if it failed */
    int objId;                          /* 0x20 */
} FileLoadRec;

extern int func_003078E0(unsigned int a);   /* the converted object id, -1 when there is none */

#endif
