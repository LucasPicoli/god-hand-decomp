/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

extern int GetOsdConfigParam(int *p);
extern int SetOsdConfigParam(int *p);

__attribute__((section(".text.PatchIsNeeded")))
int PatchIsNeeded(void)
{
    int old;
    int cur;

    GetOsdConfigParam(&old);
    cur = (old & 0xFFFF1FFF) | 0x2000;
    SetOsdConfigParam(&cur);
    GetOsdConfigParam(&cur);
    SetOsdConfigParam(&old);
    return (((unsigned int)cur >> 13) & 7) == 0;
}
