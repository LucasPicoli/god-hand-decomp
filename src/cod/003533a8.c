typedef struct SfdPlySub {
    void *dec;          /* 0x00 */
    char unk4[0x70];
    int stat;           /* 0x74 */
    char unk78[0x98];
    int active;         /* 0x110 */
} SfdPlySub;

typedef struct SfdPlyFrm {
    char unk0[0x18];
    int kind;           /* 0x18 */
} SfdPlyFrm;

typedef struct SfdPly {
    char unk0[0xE48];
    int noloop;         /* 0xE48 */
    char unkE4C[0x1174];
    SfdPlySub *sub;     /* 0x1FC0 */
} SfdPly;

extern int MPV_GetLinkFlg(void *dec, int *eos, int *term);
extern int GetArrayElemA0C_35A1C8(SfdPly *ply, int idx);

__attribute__((section(".text.sfmpv_UpdateDefect")))
void sfmpv_UpdateDefect(SfdPly *ply, SfdPlyFrm *frm, int mode)
{
    SfdPlySub *s = ply->sub;
    void *dec = s->dec;
    int stat = s->stat;
    int eos, term;

    if (s->active != 0) {
        MPV_GetLinkFlg(dec, &eos, &term);
        if (eos == 1) {
            stat = 5;
        } else {
            if (ply->noloop == 0) {
                int v = GetArrayElemA0C_35A1C8(ply, 0x49);
                if (v == 1)
                    term = v;
            }
            if (term == 1)
                stat = 2;
        }
    }
    if (mode == 1) {
        if ((unsigned int)(frm->kind - 1) < 2)
            stat = 2;
    } else if (stat == 2) {
        stat = 3;
    } else if (stat == 3) {
        stat = 5;
    }
    s->stat = stat;
}
