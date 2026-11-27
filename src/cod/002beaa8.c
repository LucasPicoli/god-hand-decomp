/* ee-2.9-991111 matched TU. */

#include "godhand/cDoor.h"

/* The room jump table cRoomJump.tbl points at: a count, then count 4-byte records. */
typedef struct RoomJumpRec {
    unsigned short id;                  /* 0x00 jump point id */
    unsigned short unk02;
} RoomJumpRec;                          /* 0x04 */

typedef struct RoomJumpTbl {
    unsigned int count;                 /* 0x00 */
    char unk04[0xC];
    RoomJumpRec rec[1];                 /* 0x10 count records */
} RoomJumpTbl;

/* Find the record of jump point id in the room's jump table; 0 if there is none. */
__attribute__((section(".text.cRoomJump_findRecord")))
RoomJumpRec *cRoomJump_findRecord(cRoomJump *self, unsigned short id)
{
    RoomJumpTbl *tbl = (RoomJumpTbl *)self->tbl;
    RoomJumpRec *p;
    RoomJumpRec *rec;
    unsigned int i;

    if (tbl != 0) {
        i = 0;
        if (tbl->count != 0) {
            p = tbl->rec;
            rec = tbl->rec;
            do {
                if (p->id == id) {
                    return rec;
                }
                i++;
                rec++;
                p++;
            } while (i < tbl->count);
        }
    }
    return 0;
}
