/* sn-2.95.3-136 matched TU. */

/* Advance the angle by step, clamp it against limit (above it for a positive limit, below it otherwise), then apply it. */
typedef struct TurnObj {
    char unk00[0xB8];
    float angle;                        /* 0xB8 */
} TurnObj;

extern void func_001E8F78(TurnObj *self, float angle);

__attribute__((section(".text.func_001E9028")))
void func_001E9028(TurnObj *self, float step, float limit)
{
    self->angle += step;
    if (limit > 0.0f) {
        if (self->angle > limit) {
            self->angle = limit;
        }
    } else {
        if (self->angle < limit) {
            self->angle = limit;
        }
    }
    func_001E8F78(self, self->angle);
}
