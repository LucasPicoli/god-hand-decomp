/* include/godhand/cSceAtUnit.h - cSceAtUnit, one scenario attack/trigger area.
 *
 * A unit is a 0x9C-byte record. The cArea at 0x04 holds its shape and centre.
 * cSceAtUnit_AtInit clears the record and fills the header bytes at
 * 0x34..0x3B; cSceAtManager hands out units by id. flags bit 0 is
 * "enabled" (cSceAtUnit_SetEnable / SetDisable toggle it, and notify
 * func_002C0E20 / func_002C0E60 when the unit type is 9).
 * Offsets are exact; unknown spans stay unkNNN.
 */
#ifndef GODHAND_CSCEATUNIT_H
#define GODHAND_CSCEATUNIT_H

#define SCEATUNIT_SIZE        0x9C
#define SCEATUNIT_ENABLED     0x01
#define SCEATUNIT_FLAGS_INIT  0x03      /* enabled plus one more bit */
#define SCEATUNIT_TYPE_NOTIFY 9
#define SCEATUNIT_NO_ID       0xFFFF

typedef struct cSceAtUnit {
    int unk00;
    char area[0x30];            /* 0x04 cArea: shape and centre */
    unsigned char flags;        /* 0x34 SCEATUNIT_* */
    unsigned char type;         /* 0x35 */
    unsigned short id;          /* 0x36 SCEATUNIT_NO_ID until registered */
    unsigned char param38;      /* 0x38 */
    unsigned char unk39;        /* 0x39 set to 8 at init */
    unsigned char actType;      /* 0x3A cSceAtUnit_ActTypeSet */
    unsigned char param3B;      /* 0x3B */
    char unk3C[0x18];
    unsigned char actArg;       /* 0x54 cSceAtUnit_ActTypeSet, 0x31 at init */
    char unk55[SCEATUNIT_SIZE - 0x55];
} cSceAtUnit;

#endif
