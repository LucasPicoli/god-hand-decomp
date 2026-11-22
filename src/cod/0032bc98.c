/* cygnus-2.96: func_0032BC98, starts a handle on a named file range: stops it, copies the file name and
 * sets the sector range, then kicks playback. */
#include "godhand/globals.h"
typedef struct {
    char pad0;
    signed char stat; /* 0x01 */
    signed char f2; /* 0x02 */
    char pad3[0xAC - 0x3];
    signed char named; /* 0xAC */
    char padAD[3];
    char *fname; /* 0xB0 */
    char *cur; /* 0xB4 */
    int ofs; /* 0xB8 */
    int start; /* 0xBC */
    int nsct; /* 0xC0 */
} AdxFnameHn;
extern void func_0033F130(char *msg);
extern void ADXT_Stop(AdxFnameHn *hn);
extern char *func_003A57C4(char *d, const char *s);
extern void ADXT_SetLnkSw(AdxFnameHn *hn, int a);

__attribute__((section(".text.func_0032BC98")))
void func_0032BC98(AdxFnameHn *hn, const char *fname, int start, int nsct)
{
    if (hn == 0 || fname == 0) {
        func_0033F130(D_004527A0);
        return;
    }
    ADXT_Stop(hn);
    func_003A57C4(hn->fname, fname);
    hn->cur = hn->fname;
    hn->start = start;
    hn->nsct = nsct;
    hn->ofs = 0;
    hn->stat = 1;
    hn->named = 1;
    hn->f2 = 0;
    ADXT_SetLnkSw(hn, 0);
}
