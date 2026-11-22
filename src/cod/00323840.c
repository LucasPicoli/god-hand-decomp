/* cygnus-2.96: adxf_SetAfsFileInfo, opens a sound stream by id: queries its layout, starts the voice, and records the loop points. */
typedef struct {
    char unk0[4];
    int voice;
    char unk8[4];
    int loopStart;
    int loopEnd;
    int pos;
    char unk18[0x18];
    int size;
    int addr;
    int bank;
    int size2;
    int loopStart2;
} SndStm;

extern int adxf_GetFnameRangeEx(int id, int arg, char *buf, int *addr, int *size, int *loopStart, int *loopEnd);
extern int Obj0000_Get_D_003EB308_Plus10_By_Index_324808(int id);
extern void ADXSTM_BindFile(int voice, int bank, int addr, int size, int loopStart);
extern int func_00328098(int voice);
extern void ADXSTM_ReleaseFile(int voice);

__attribute__((section(".text.adxf_SetAfsFileInfo")))
int adxf_SetAfsFileInfo(SndStm *s, int id, int arg)
{
    char buf[0x100];
    int addr;
    int size;
    int loopStart;
    int loopEnd;
    int bank;

    if (adxf_GetFnameRangeEx(id, arg, buf, &addr, &size, &loopStart, &loopEnd) < 0)
        return -3;
    s->size = size;
    s->addr = addr;
    bank = Obj0000_Get_D_003EB308_Plus10_By_Index_324808(id);
    s->pos = 0;
    s->bank = bank;
    s->loopStart2 = loopStart;
    s->size2 = size;
    ADXSTM_BindFile(s->voice, bank, s->addr, size, loopStart);
    if (func_00328098(s->voice) == 4) {
        ADXSTM_ReleaseFile(s->voice);
        return -1;
    }
    s->loopStart = loopStart;
    s->loopEnd = loopEnd;
    return 0;
}
