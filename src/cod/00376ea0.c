/* sn-2.95.3-136 matched TU. */

#include "godhand/SndReq.h"
#include "godhand/MixChannel.h"

/* sn-2.95.3-136 */





/* Runs every queued sound-channel request (a command or a start) and frees its slot. */
__attribute__((section(".text.func_00376EA0")))
void func_00376EA0(void)
{
    SndReq *r;
    int i;

    for (i = 0; i < SNDREQ_NUM; i++) {
        r = &D_0076E590[i];
        if (r->used != 0) {
            if (r->flags & SNDREQ_F_COMMAND) {
                func_003772D8(r);
            } else {
                func_00376F18(r);
            }
            r->used = 0;
        }
    }
}

#define MIXCHANNEL_LEVELC_OFFSET 0xBC
__attribute__((section(".text.func_00384138")))
int func_00384138(void *owner, MixChannel *mix) {
    unsigned char *level;
    int i;
    int next;

    for (i = 0; i < mix->chCount; i = next) {
        level = (unsigned char *)mix + MIXCHANNEL_LEVELC_OFFSET;
        next = i + 1;
        if (i != mix->sel - 1) {
            if (level[next] != level[mix->sel]) {
                return 0;
            }
        }
    }
    return 1;
}

typedef struct StepCtx {
    char unk00[7];
    signed char mode;           /* 0x07 which update runs */
} StepCtx;

typedef struct StepNode {
    void *value;                /* 0x00 the value cell: a byte when width is 0, a halfword when 1 */
    char unk04[4];
    signed char width;          /* 0x08 */
} StepNode;


extern void func_0037A9C8(StepCtx *ctx, StepNode *node);
extern void func_0037AAB0(StepCtx *ctx, StepNode *node);
extern void func_0037AB00(StepCtx *ctx, StepNode *node);

/* Rewrites the node's value cell through func_0037A8F8 (byte or halfword by width), then runs the update chosen by ctx->mode. */
__attribute__((section(".text.func_0037A818")))
void func_0037A818(StepCtx *ctx, StepNode *node)
{
    if (node->width == 0) {
        *(signed char *)node->value = func_0037A8F8(ctx, node, *(signed char *)node->value);
    }
    if (node->width == 1) {
        *(short *)node->value = func_0037A8F8(ctx, node, *(short *)node->value);
    }
    switch (ctx->mode) {
    case 0:
        func_0037A9C8(ctx, node);
        break;
    case 1:
        func_0037AAB0(ctx, node);
        break;
    case 2:
        func_0037AB00(ctx, node);
        break;
    }
}
