/* cygnus-2.96: MWSFPLY_RecordFname, copy a file name into the handle's name buffer, truncating
 * (with an error) when it is longer than the buffer. */
#include "godhand/globals.h"
typedef struct {
    char pad000[0x1A4];
    char *name;
    int nameMax;
} MwsfNameHn;

extern unsigned int strlen(const char *s);
extern void MWSFSVM_Error(const char *msg);
extern void func_003A5DA0(char *dst, const char *src, int n);
extern char *func_003A57C4(char *dst, const char *src);

__attribute__((section(".text.MWSFPLY_RecordFname")))
void MWSFPLY_RecordFname(MwsfNameHn *h, const char *fname)
{
    if (h->nameMax < (int)strlen(fname)) {
        MWSFSVM_Error(&D_00458147[1]);
        func_003A5DA0(h->name, fname, h->nameMax);
    } else {
        func_003A57C4(h->name, fname);
    }
}
