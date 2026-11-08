/* include/godhand/ScenarioStep.h - the step record a scenario script handler gets.
 *
 * func_002BF2D0 switches on byte 0 (the step kind) and passes the record to
 * the handler for that kind. The first four bytes are a ScenarioCursor, which
 * every handler clears when it takes the step over.
 *
 * Field names are ours, taken from the handlers that read and write them.
 * Offsets are exact: every body that uses this header builds byte-identical
 * to retail. A field nobody has named yet stays as unkNNN padding.
 */
#ifndef GODHAND_SCENARIOSTEP_H
#define GODHAND_SCENARIOSTEP_H

#include "godhand/ScenarioCursor.h"

#define SCENARIOSTEP_MODE_JUMP  1       /* kind 5: leave through a room jump */

typedef struct ScenarioStep {
    unsigned char kind;                 /* 0x00 step kind, the handler selector */
    unsigned char step;                 /* 0x01 ScenarioCursor.step */
    unsigned char unk02;                /* 0x02 */
    unsigned char unk03;                /* 0x03 */
    char unk04[6];
    unsigned char state;                /* 0x0A cleared when the step starts */
    char unk0B;
    unsigned char mode;                 /* 0x0C SCENARIOSTEP_MODE_* */
} ScenarioStep;

typedef char ScenarioStep_size_check[(sizeof(ScenarioStep) == 0xD) ? 1 : -1];

#endif
