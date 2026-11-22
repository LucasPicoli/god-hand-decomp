/* cygnus-2.96: SFD video time marks: record the first and last time stamps and the mark, then hand the
 * data on. */
#include "godhand/sftim.h"

typedef struct {
    char pad0[0x10];
    long tmin0;
    long tmin1;
    char pad20[8];
    int last;
    char pad2C[4];
    int first;
    char pad34[4];
    int mark;
} SfdVideoTime;

typedef struct {
    char pad0[8];
    SfdVideoTime *tm;
    char padC[0xC];
    int video;
} SfdVideoCh;

typedef struct {
    char pad0[0x1F74];
    SfdVideoCh ch;
} SfdVideoView;

extern int sfmps_CopyDstBuft(void *w, int ch, char *src, int len, long pts);

__attribute__((section(".text.sfmps_CopyAudio")))
int sfmps_CopyAudio(SfdVideoView *s, int t, char *src, int len, long pts)
{
    SfdVideoCh *ch;
    SfdVideoTime *tm;
    int v;

    if (GetArrayElemA0C_35A1C8(s, 6) == 0) {
        return 1;
    }
    ch = &s->ch;
    tm = ch->tm;
    if (tm->mark == -1) {
        tm->mark = t;
    }
    if (tm->first == -1) {
        tm->first = t;
    }
    v = GetArrayElemA0C_35A1C8(s, 0x1E);
    if (v != -1) {
        if (GetArrayElemA0C_35A1C8(s, 0x37) != 0 ? t < tm->last : t == tm->first) {
            tm->mark = v;
        }
    }
    tm->last = t;
    if (tm->mark != t) {
        return 1;
    }
    if (pts >= 0) {
        tm->tmin0 = (pts < tm->tmin0) ? pts : tm->tmin0;
        tm->tmin1 = (pts < tm->tmin1) ? pts : tm->tmin1;
    }
    return sfmps_CopyDstBuft(s, ch->video, src, len, pts);
}
