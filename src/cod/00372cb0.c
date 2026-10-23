/* sn-2.95.3-136 */

/* A sound sequence node: one stream, or two blended tracks when count is 2. */
typedef struct SeqTrk {
    int stream;                 /* 0x00 */
    char pad04[0x10];
    union {
        struct {
            float cur;          /* 0x14 current volume */
            float vol;          /* 0x18 */
            float steps;        /* 0x1C frames left in the fade */
            float target;       /* 0x20 */
            char pad24[8];
            float level;        /* 0x2C */
            float levelTarget;  /* 0x30 */
        } one;
        struct {
            float cur[2];       /* 0x14 */
            float vol[2];       /* 0x1C */
            float steps[2];     /* 0x24 */
            float target[2];    /* 0x2C */
            char pad34[8];
            float level;        /* 0x3C */
            float levelTarget;  /* 0x40 */
        } two;
    } u;
    char pad44[4];
    int handle;                 /* 0x48 */
    int flags;                  /* 0x4C */
    int wait;                   /* 0x50 frames before the fade runs */
    int mode;                   /* 0x54 */
    int count;                  /* 0x58 tracks */
    char pad5C[0x78 - 0x5C];
    int entry;                  /* 0x78 */
} SeqTrk;

extern int func_00373A50(void *node);
extern int func_00373B20(void *node);
extern int func_003748A8(int *node);
extern int func_00374170(int *node);
extern void ResetNodeData_3733C8(void *node);
extern void UpdateSequenceNode_373430(void *node);
extern void UpdateSequenceNodeSetFlag_373488(void *node);
extern void UpdateStateAndClearFlag_3734F0(void *node);
extern void UpdateSequenceNodeWeighted_373560(void *node, int track, float weight);
extern int UpdateSequenceEntry_373298(void *node, int entry);

/* Per-frame update of a sequence node: step its level and volume fades, push the
 * volumes to the tracks, pause or resume on silence, and recycle a finished stream. */
__attribute__((section(".text.func_00372CB0")))
void func_00372CB0(SeqTrk *self)
{
    int i;
    int silent;
    int r;

    if (func_00373A50(self) == 0)
        return;
    if (func_00373B20(self)) {
        if (self->stream == 0)
            return;
        if (self->wait != 0) {
            self->wait--;
            if (!(self->flags & 4))
                UpdateSequenceNodeSetFlag_373488(self);
            return;
        }
        if (self->flags & 4)
            UpdateStateAndClearFlag_3734F0(self);
        if (self->u.two.level - self->u.two.levelTarget < -0.1f)
            self->u.two.level += 0.1f;
        else if (self->u.two.level - self->u.two.levelTarget > 0.1f)
            self->u.two.level -= 0.1f;
        else
            self->u.two.level = self->u.two.levelTarget;
        for (i = 0; i < self->count; i++) {
            if (self->u.two.steps[i] > 0.0f) {
                self->u.two.cur[i] -= (self->u.two.cur[i] - self->u.two.target[i] * self->u.two.vol[i])
                                      / self->u.two.steps[i];
                self->u.two.steps[i] -= 1.0f;
            } else {
                self->u.two.cur[i] = self->u.two.target[i] * self->u.two.vol[i];
            }
            UpdateSequenceNodeWeighted_373560(self, i, self->u.two.cur[i]);
        }
        silent = 1;
        for (i = 0; i < self->count; i++) {
            if (self->u.two.cur[i] > 0.0f) {
                silent = 0;
                break;
            }
        }
        if (self->flags & 8) {
            if (silent == 1) {
                if (!(self->flags & 2))
                    UpdateSequenceNodeSetFlag_373488(self);
            } else if (self->flags & 2) {
                UpdateStateAndClearFlag_3734F0(self);
            }
        } else if (silent == 1) {
            UpdateSequenceNode_373430(self);
        }
        if (self->stream == 0) {
            if (self->flags & 1)
                UpdateSequenceEntry_373298(self, self->entry);
        } else {
            r = func_003748A8(&self->stream);
            if (r == 0 || r == 5)
                ResetNodeData_3733C8(self);
        }
    } else {
        if (self->stream == 0)
            return;
        if (self->wait != 0) {
            self->wait--;
            if (!(self->flags & 4))
                UpdateSequenceNodeSetFlag_373488(self);
            return;
        }
        if (self->flags & 4)
            UpdateStateAndClearFlag_3734F0(self);
        if (self->u.one.level - self->u.one.levelTarget < -0.1f)
            self->u.one.level += 0.1f;
        else if (self->u.one.level - self->u.one.levelTarget > 0.1f)
            self->u.one.level -= 0.1f;
        else
            self->u.one.level = self->u.one.levelTarget;
        if (self->u.one.steps > 0.0f) {
            self->u.one.cur -= (self->u.one.cur - self->u.one.target * self->u.one.vol) / self->u.one.steps;
            self->u.one.steps -= 1.0f;
        } else {
            self->u.one.cur = self->u.one.target * self->u.one.vol;
        }
        UpdateSequenceNodeWeighted_373560(self, -1, self->u.one.cur);
        if (self->flags & 8) {
            if (self->u.one.cur <= 0.0f) {
                if (!(self->flags & 2))
                    UpdateSequenceNodeSetFlag_373488(self);
            } else if (self->flags & 2) {
                UpdateStateAndClearFlag_3734F0(self);
            }
        } else if (self->u.one.cur <= 0.0f) {
            UpdateSequenceNode_373430(self);
        }
        if (self->stream == 0) {
            if (self->flags & 1)
                UpdateSequenceEntry_373298(self, self->entry);
        } else {
            r = func_00374170(&self->stream);
            if (r == 0 || r == 5)
                ResetNodeData_3733C8(self);
        }
    }
}
