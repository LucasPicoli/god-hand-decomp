extern int MWSFD_IsColAdjFile(void *, int);
extern int SUD_AnalyTypeCcs(char *, int);

__attribute__((section(".text.MWSFD_IsColAdjFrame")))
int MWSFD_IsColAdjFrame(void *table, char *object)
{
    int ok;
    char *ccs;
    ok = MWSFD_IsColAdjFile(table, *(int *)(object + 0x30)) == 1;
    ccs = *(char **)(object + 0x88);
    if (ccs != 0)
        ok = SUD_AnalyTypeCcs(ccs, *(int *)(object + 0x8C)) == 1;
    return ok;
}
