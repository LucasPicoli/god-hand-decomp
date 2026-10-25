/* cygnus-2.96 matched TU. */

/* cygnus-2.96 */
#include "godhand/sjFeedCtl.h"


extern void func_0033ACA0(SjChunk *ck, int len, SjChunk *head, SjChunk *tail);


extern void func_003BA550(SjFeedCtl *feed);

extern void func_003BA6C0(void *src, int len);
extern int SjFeed_writeAll(SjFeedCtl *feed);

/* Advance the feed one step: move to running, stop when the source has
 * ended and nothing is waiting, and at state 2 pass one block through. */
__attribute__((section(".text.func_003BA148")))
void func_003BA148(SjFeedCtl *feed)
{
    SjChunk ck;
    SjChunk tail;

    if (feed->state == SJFEED_START)
        feed->state = SJFEED_RUN;
    if (feed->final == 1) {
        if (feed->in->vt->getNumData(feed->in, SJ_LANE_FULL) <= 0)
            feed->state = SJFEED_DRAINED;
    }
    if (feed->state != SJFEED_RUN)
        return;
    if (feed->out->vt->getNumData(feed->out, SJ_LANE_FREE) < SJFEED_BLOCK)
        return;
    feed->in->vt->getChunk(feed->in, SJ_LANE_FULL, SJFEED_BIG, &ck);
    func_0033ACA0(&ck, func_003BA370(ck.data, ck.len), &ck, &tail);
    feed->in->vt->putChunk(feed->in, SJ_LANE_FREE, &ck);
    feed->in->vt->ungetChunk(feed->in, SJ_LANE_FULL, &tail);
    feed->in->vt->getChunk(feed->in, SJ_LANE_FULL, SJFEED_HDR_LEN, &ck);
    if (ck.len < SJFEED_HDR_LEN) {
        feed->in->vt->ungetChunk(feed->in, SJ_LANE_FULL, &ck);
        return;
    }
    if (func_003BA3D8(feed, ck.data) < 0 || func_003BA4F8(feed, ck.data + 4) < 0) {
        feed->state = SJFEED_ERROR;
        return;
    }
    feed->in->vt->ungetChunk(feed->in, SJ_LANE_FULL, &ck);
    if (feed->in->vt->getNumData(feed->in, SJ_LANE_FULL) < feed->step)
        return;
    func_003BA550(feed);
    if (func_003BA5A0(feed) < 0) {
        feed->state = SJFEED_ERROR;
        return;
    }
    if (feed->copyMode == 1)
        func_003BA6C0(feed->src, SJFEED_BLOCK);
    if (SjFeed_writeAll(feed) < 0) {
        feed->state = SJFEED_ERROR;
        return;
    }
    feed->pos += feed->step;
    feed->sent += SJFEED_BLOCK;
}
