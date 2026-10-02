/* include/godhand/cEvent.h - the cutscene (event) player.
 *
 * cEvent runs one cutscene at a time as a small state machine. The object is
 * a record that every method receives as its first argument. The record keeps
 * a state (which stage the player is in), a phase counter inside that stage,
 * and a flag word that the stages set and test. func_00296530 runs the stage.
 *
 * Method names are the game's own, from the symbol table in the retail ELF.
 * Field names are ours, taken from the methods that read and write them.
 * Offsets are exact. A field we can't name yet stays as unkNN padding.
 *
 * Retail's debug hooks were stripped and their calls link to address 0, the
 * symbol func_0. A call to func_0 in a body is one of those stripped hooks.
 */
#ifndef GODHAND_CEVENT_H
#define GODHAND_CEVENT_H

/* cEvent.state: which stage the player is in. func_00296530 dispatches on it. */
#define CEVENT_STATE_START    0   /* fade out, hide models (func_002965F0) */
#define CEVENT_STATE_CLEAR    1   /* reset the map and the managers (func_00296818) */
#define CEVENT_STATE_CREATE   2   /* load the data, create the work (func_00296958) */
#define CEVENT_STATE_PLAY     3   /* move scene (UpdateSequenceState_296C28) */
#define CEVENT_STATE_RELEASE  4   /* tear down (func_00297038) */

/* cEvent.flags bits. */
#define CEVENT_F_ACTIVE       0x1         /* a cutscene is running */
#define CEVENT_F_INITED       0x2         /* cEvent_initEnv has run */
#define CEVENT_F_MOVE_ON      0x4         /* a move scene is running */
#define CEVENT_F_MOVE_STEP    0x8         /* the move scene steps before anything else */
#define CEVENT_F_CREATED      0x10        /* the create stage has finished */
#define CEVENT_F_AUTO_END     0x20        /* leave the create stage at once */
#define CEVENT_F_END_REQ      0x40        /* the cutscene asked to end */
#define CEVENT_F_TEXT_ON      0x80        /* the display text is linked in */
#define CEVENT_F_TEXT_DATA    0x100       /* textData holds the loaded text */
#define CEVENT_F_NO_START     0x10000000  /* skip the create work */

/* Header of the display-text data the load state reads. A table of section
 * offsets follows two byte fields; an offset of 0 means the section is absent. */
typedef struct cEventTextHdr {
    char unk00;
    unsigned char kind;       /* 0x01 */
    unsigned char mode;       /* 0x02 */
    char unk03;
    int ofs[22];              /* 0x04 section offsets, from the header start */
} cEventTextHdr;
/* Section pointer for the byte offset `off` (0x04, 0x08, ... 0x58), or 0. */
#define CEVENT_TEXT_SEC(t, off) \
    ((t)->ofs[((off) - 4) / 4] != 0 ? (char *)(t) + (t)->ofs[((off) - 4) / 4] : (char *)0)

/* Byte offset of a cEvent field, for the few bodies where only the raw
 * `*(T *)((char *)self + off)` form builds the retail bytes (it carries a
 * different alias set from the typed member). */
#define CEVENT_OFFSET(field) ((int)&((struct cEvent *)0)->field)

/* Byte n of the flag word (little endian: n = 1 is bits 8..15, so
 * CEVENT_FLAG_BYTE(self, 1) & 1 tests CEVENT_F_TEXT_DATA). */
#define CEVENT_FLAG_BYTE(self, n) (((unsigned char *)&(self)->flags)[n])

typedef struct cEvent {
    void (*onLoaded)(void);   /* 0x00 callback run once the data has loaded */
    unsigned char state;      /* 0x04 CEVENT_STATE_* */
    unsigned char phase;      /* 0x05 step inside the state */
    unsigned char unk06;      /* 0x06 cleared on every state change */
    unsigned char unk07;      /* 0x07 cleared on every state change */
    int flags;                /* 0x08 CEVENT_F_* */
    int loadHandle;           /* 0x0C async read handle */
    int resData;              /* 0x10 data of the cutscene entry, 0 until read */
    cEventTextHdr *textData;  /* 0x14 data of the display text, 0 until read */
    int dataNo;               /* 0x18 cutscene number */
    char unk1C[4];
    float pos[3];             /* 0x20 player position at the start */
    char unk2C[4];
    float angle;              /* 0x30 */
    char skipOk;              /* 0x34 */
    char unk35[3];
} cEvent;

/* Offset checks. The record is at least 0x35 bytes; its real size is not
 * known, so there is no size check. */
typedef char cEvent_chk_state[CEVENT_OFFSET(state) == 0x04 ? 1 : -1];
typedef char cEvent_chk_flags[CEVENT_OFFSET(flags) == 0x08 ? 1 : -1];
typedef char cEvent_chk_loadHandle[CEVENT_OFFSET(loadHandle) == 0x0C ? 1 : -1];
typedef char cEvent_chk_textData[CEVENT_OFFSET(textData) == 0x14 ? 1 : -1];
typedef char cEvent_chk_dataNo[CEVENT_OFFSET(dataNo) == 0x18 ? 1 : -1];
typedef char cEvent_chk_pos[CEVENT_OFFSET(pos) == 0x20 ? 1 : -1];
typedef char cEvent_chk_angle[CEVENT_OFFSET(angle) == 0x30 ? 1 : -1];
typedef char cEvent_chk_skipOk[CEVENT_OFFSET(skipOk) == 0x34 ? 1 : -1];

/* Retail's debug strings were stripped and every use resolves to address 0.
 * Each name below is a distinct symbol that the linker script places at 0
 * (config/SLUS_215.03.lcf), so the compiler loads each string address again
 * instead of sharing one register across the calls, as retail does. */
#define CEVENT_NULL_SYM(n) extern char n[]
CEVENT_NULL_SYM(cEvent_nullStr00);
CEVENT_NULL_SYM(cEvent_nullStr01);
CEVENT_NULL_SYM(cEvent_nullStr02);
CEVENT_NULL_SYM(cEvent_nullStr03);
CEVENT_NULL_SYM(cEvent_nullStr04);
CEVENT_NULL_SYM(cEvent_nullStr05);
CEVENT_NULL_SYM(cEvent_nullStr06);
CEVENT_NULL_SYM(cEvent_nullStr07);
CEVENT_NULL_SYM(cEvent_nullStr08);
CEVENT_NULL_SYM(cEvent_nullStr09);
CEVENT_NULL_SYM(cEvent_nullStr10);
CEVENT_NULL_SYM(cEvent_nullStr11);
CEVENT_NULL_SYM(cEvent_nullStr12);
CEVENT_NULL_SYM(cEvent_nullStr13);
CEVENT_NULL_SYM(cEvent_nullStr14);
CEVENT_NULL_SYM(cEvent_nullStr15);

/* The stripped hook itself. It is called both as a void hook and, once, as
 * an int function, so the int form is a second name for the same address. */
extern int cEvent_nullHookI();

/* The work record retail kept at a stripped static: four of its fields are
 * read by the small accessors. Like the strings it resolves to address 0. */
typedef struct cEventWork {
    char unk00[4];
    char *cutTable;           /* 0x04 table of 16-byte cut entries */
    char unk08[8];
    int cutNo;                /* 0x10 index of the current cut */
    float cutFrame;           /* 0x14 frame inside the current cut */
} cEventWork;
extern cEventWork cEvent_work;

#endif
