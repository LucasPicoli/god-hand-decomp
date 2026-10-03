/* sn-2.95.3-136 matched TU. */

/* A screen element: state bytes at 0xC to 0xF, panel state at 0xA4. */
typedef struct ScrElem {
    unsigned char unk00[0xC];
    unsigned char mode;                 /* 0x0C */
    unsigned char modeStep;             /* 0x0D */
    unsigned char modeWait;             /* 0x0E */
    unsigned char modeArg;              /* 0x0F */
    char unk10[0xA4 - 0x10];
    unsigned char state;                /* 0xA4 */
} ScrElem;

/* Pick the mode for the element's panel state, clear its step bytes, and report state 2. */
__attribute__((section(".text.ScrElem_selectModeByState")))
int ScrElem_selectModeByState(ScrElem *self) {
    switch (self->state) {
    case 0:
    default:
        self->modeArg = 0;
        self->mode = 3;
        self->modeStep = 0;
        break;
    case 1:
        self->modeArg = 0;
        self->mode = 3;
        self->modeStep = 0;
        break;
    case 2:
        self->modeArg = 0;
        self->mode = 3;
        self->modeStep = 0;
        break;
    case 3:
        self->modeArg = 0;
        self->mode = 3;
        self->modeStep = 0;
        break;
    case 4:
        self->modeArg = 0;
        self->mode = 4;
        self->modeStep = 0;
        break;
    case 5:
        self->modeArg = 0;
        self->mode = 5;
        self->modeStep = 0;
        break;
    }
    self->modeWait = 0;
    return 2;
}
