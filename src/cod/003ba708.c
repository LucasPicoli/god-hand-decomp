/* cygnus-2.96 matched TU. */

#include "godhand/criSj.h"

/* A buffered source: `data` is copied into the stream joint at `sj`. */
typedef struct SjFeed {
    char unk00[8];
    Sint8 *data;                /* 0x08 */
    char unk0C[8];
    SjObj *sj;                  /* 0x14 */
} SjFeed;

#define SJ_FEED_SIZE  0x1800
#define SJ_ID_FREE    0
#define SJ_ID_FULL    1

extern void *func_003A5148(void *dst, const void *src, int n);  /* memcpy */
extern void func_003B9DE0(char *msg);
extern char D_00460A70[];

/* Copy the whole buffer into the stream joint, in up to two chunks. Returns 0, or -1 when the joint
 * could not take all of it. */
__attribute__((section(".text.SjFeed_writeAll")))
int SjFeed_writeAll(SjFeed *feed)
{
    SjChunk ck;
    int left = SJ_FEED_SIZE;
    int done;

    feed->sj->vt->getChunk(feed->sj, SJ_ID_FREE, SJ_FEED_SIZE, &ck);
    func_003A5148(ck.data, feed->data, ck.len);
    done = ck.len;
    feed->sj->vt->putChunk(feed->sj, SJ_ID_FULL, &ck);
    left -= done;
    if (left > 0) {
        feed->sj->vt->getChunk(feed->sj, SJ_ID_FREE, left, &ck);
        func_003A5148(ck.data, feed->data + done, ck.len);
        left -= ck.len;
        feed->sj->vt->putChunk(feed->sj, SJ_ID_FULL, &ck);
    }
    if (left != 0) {
        func_003B9DE0(D_00460A70);
        return -1;
    }
    return 0;
}
