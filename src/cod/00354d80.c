/* cygnus-2.96: SFD work release hook (0x354D80). */

typedef struct SfdRef {
    void *obj;
} SfdRef;

typedef struct SfdRefView {
    char unk0000[0x1FC0];
    SfdRef *ref;                /* 0x1FC0 */
} SfdRefView;

extern void MPV_RequestStop(void *obj);

__attribute__((section(".text.SFMPV_RequestStop")))
int SFMPV_RequestStop(SfdRefView *w)
{
    if (w->ref->obj == 0) return 0;
    MPV_RequestStop(w->ref->obj);
    return 0;
}
