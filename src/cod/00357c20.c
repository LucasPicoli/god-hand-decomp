typedef struct {
    char pad0[0x284];
    int unk284;
    int unk288;
} SfdTimer;

extern int sfply_IsAnyoneTerm(char *);
extern int GetArrayElemA0C_35A1C8(char *, int);
extern int sfply_EnoughViData(char *);
extern int sfply_EnoughAiData(char *);
extern int SFTIM_GetTime(char *, int *, int *);
extern int UTY_MulDiv(int, int, int);
extern int func_0035AEC8(int, int, int, int);

__attribute__((section(".text.sfply_IsBpaOff")))
int sfply_IsBpaOff(char *o)
{
    int t[2];
    SfdTimer *tm;
    int rate;
    int now;

    if (sfply_IsAnyoneTerm(o) != 0) {
        return 1;
    }
    if (GetArrayElemA0C_35A1C8(o, 5) == 1 && sfply_EnoughViData(o) != 0) {
        return 1;
    }
    if (GetArrayElemA0C_35A1C8(o, 6) == 1 && sfply_EnoughAiData(o) != 0) {
        return 1;
    }
    SFTIM_GetTime(o, &t[0], &t[1]);
    tm = (SfdTimer *)(o + 0xD30);
    rate = tm->unk288;
    now = tm->unk284;
    return func_0035AEC8(t[0], t[1], now - UTY_MulDiv(GetArrayElemA0C_35A1C8(o, 0x45), rate, 1000000), rate) != 0;
}
