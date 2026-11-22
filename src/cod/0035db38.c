/* cygnus-2.96: SFH_AnlyHdrToolVer, reports the newer of the stream header version and the tool version string. */
typedef struct {
    char unk0[0x18];
    unsigned char major;
    unsigned char minor;
} StmVer;

typedef struct {
    int unk0;
    char *hdr;
} StmHdrHn;

extern int SFH_AnlyHdrToolInf(StmHdrHn *hn, char *out);
extern int getToolVer(char *str, int *maj, int *min);

__attribute__((section(".text.SFH_AnlyHdrToolVer")))
int SFH_AnlyHdrToolVer(StmHdrHn *hn, int *maj, int *min)
{
    char buf[0x30];
    int tmaj;
    int tmin;
    StmVer *v;
    int hmaj;
    int hmin;

    *maj = 0;
    v = (StmVer *)(hn->hdr + 0x20);
    *min = 0;
    if (SFH_AnlyHdrToolInf(hn, buf) == 0)
        return 0;
    hmaj = v->major;
    hmin = v->minor;
    if (getToolVer(buf, &tmaj, &tmin) == 0)
        return 0;
    if (hmaj * 100 + hmin >= tmaj * 100 + tmin) {
        *maj = hmaj;
        *min = hmin;
    } else {
        *maj = tmaj;
        *min = tmin;
    }
    return 1;
}
