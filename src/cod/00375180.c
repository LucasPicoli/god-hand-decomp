#include "godhand/globals.h"
extern int SeqCmd_findStartByMask(int, int);

__attribute__((section(".text.SdeIssEndCheck")))
int SdeIssEndCheck(void)
{
    if (SeqCmd_findStartByMask(1, 0))
        return 1;
    return D_0076A7B4 != 0;
}
