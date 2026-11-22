typedef struct { char c[32]; } Name32;

extern int isEffectiveObj(char *hn);
extern void *func_003A52F0(void *d, int c, unsigned int n);

__attribute__((section(".text.SFH_AnlyHdrToolInf")))
int SFH_AnlyHdrToolInf(char *hn, char *out)
{
    Name32 *name;

    out[0] = 0;
    name = (Name32 *)(*(char **)(hn + 4) + 0x60);
    if (isEffectiveObj(hn) == 0)
        return 0;
    func_003A52F0(out, 0, 0x21);
    *(Name32 *)out = *name;
    return 1;
}
