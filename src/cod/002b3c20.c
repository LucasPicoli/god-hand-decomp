#include "godhand/cObjBase.h"
typedef struct {
    unsigned short unk0;
    unsigned short lo;
    unsigned short hi;
    unsigned short no;
    char data[1];
} EffCmd;

typedef struct {
    char pad[0x8C];
    EffCmd *cmd;
} EffCmdObj;

extern void *func_002B4690(EffCmdObj *o, void *p);

__attribute__((section(".text.func_002B3C20")))
int func_002B3C20(EffCmdObj *o)
{
    void *p = func_002B4690(o, o->cmd->data);
    int no = o->cmd->no + 1;
    unsigned int tag = (o->cmd->hi << 16) | o->cmd->lo;

    switch (tag) {
    case 0x45524F43:
    case 0x65726F63:
        SetEffect(0, no, p, 0, -1, EFFECT_FOLLOW_OWNER);
        break;
    case 0x4D4F4F52:
    case 0x6D6F6F72:
        SetEffect(1, no, p, 0, -1, EFFECT_FOLLOW_OWNER);
        break;
    }
    return 0;
}
