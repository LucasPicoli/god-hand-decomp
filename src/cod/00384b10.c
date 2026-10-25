/* sn-2.95.3-136: func_00384B10, run the active track: bit 0 of +3 picks the sub-track at +0xA4 (else the
 * stream at +0x34); when that one is idle, bit 1 picks the sub-track at +0xCC, else the base stream at +0x8C. */
typedef struct {
    char pad00[0x20];
    int active;
} TrackState;

typedef struct {
    char pad00[0x20];
    int data;
    char pad24[0x30 - 0x24];
    int active;
} SubTrack;

extern void MenuSndTest_printMuteRow(int ctx, char *self, TrackState *t);
extern void func_00384B98(int ctx, int data);

__attribute__((section(".text.func_00384B10")))
void func_00384B10(int ctx, char *self)
{
    TrackState *t = (TrackState *)(self + 0xA4);
    SubTrack *st;

    if (self[3] & 1) {
        if (t->active != 0) {
            MenuSndTest_printMuteRow(ctx, self, t);
            return;
        }
    } else {
        st = (SubTrack *)(self + 0x34);
        if (st->active != 0) {
            func_00384B98(ctx, st->data);
            return;
        }
    }
    if (self[3] & 2)
        MenuSndTest_printMuteRow(ctx, self, (TrackState *)(self + 0xCC));
    else
        func_00384B98(ctx, *(int *)(self + 0x8C));
}
