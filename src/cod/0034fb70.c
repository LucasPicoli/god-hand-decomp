typedef struct {
    int busy; /* 0x00 */
    int rate; /* 0x04 */
    int f8; /* 0x08 */
    int fC; /* 0x0C */
    int f10; /* 0x10 */
    int pad14;
    long long time; /* 0x18 */
    long long clock; /* 0x20 */
    int f28; /* 0x28 */
    int f2C; /* 0x2C */
} PlyInfo;
typedef struct {
    int pad0;
    int f4; /* 0x04 */
    int f8; /* 0x08 */
    int padC;
    long long clock; /* 0x10 */
    long long now; /* 0x18 */
    char pad20[0x2C - 0x20];
    int f2C; /* 0x2C */
    int f30; /* 0x30 */
} StmClock;
typedef struct {
    char pad0[0x18];
    int fps; /* 0x18 */
    int f1C; /* 0x1C */
} PicInf;
typedef struct {
    char pad0[0x150];
    long long time; /* 0x150 */
    long long lat; /* 0x158 */
} TimBlk;
typedef struct {
    char pad0[0x90C];
    PicInf pic; /* 0x90C */
    char pad92C[0xD30 - 0x92C];
    TimBlk tim; /* 0xD30 */
    char padE90[0x1F7C - 0xE90];
    StmClock *clk; /* 0x1F7C */
} SfdObj;
extern PlyInfo *sfmps_GetHd(SfdObj *obj);

__attribute__((section(".text.sfmps_SetMpsHd")))
void sfmps_SetMpsHd(SfdObj *obj)
{
    PlyInfo *inf = sfmps_GetHd(obj);
    TimBlk *tim = &obj->tim;
    StmClock *clk;
    PicInf *pic;
    long long now;

    if (inf != 0) {
        clk = obj->clk;
        now = clk->now;
        if (now != 0x7FFFFFFFFFFFFFFFLL) {
            pic = &obj->pic;
            tim->lat = now - inf->clock;
            if (inf->busy == 0) {
                inf->time = tim->time;
                inf->rate = pic->fps * 50;
                inf->clock = clk->clock;
                inf->f8 = pic->f1C;
                inf->fC = clk->f4;
                inf->f10 = clk->f8;
                inf->f28 = clk->f2C;
                inf->f2C = clk->f30;
            }
        }
    }
}
