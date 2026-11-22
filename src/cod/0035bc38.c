/* cygnus-2.96 matched TU. */

extern void mpvlib_InitObj(void *);
extern void UTY_MemcpyDword(void *, void *, int);
extern void func_00369E80(void *);
extern void mpvlib_InitPicAtr(void *);
extern void Obj0000_Set_Field_3BC_Triple(unsigned char *, int, int, int, int);
extern void MPV_SetPicUsrBuf(char *, int, int);
extern int D_00766CE8;
extern void sftrn_CallTrEntry(int, int);

__attribute__((section(".text.mpvlib_InitHn")))
void *mpvlib_InitHn(char *o) {
    int i;
    mpvlib_InitObj(o);
    *(int *)(o + 0x18C) = 0;
    UTY_MemcpyDword(o + 0x190, &D_00766CE8, 0x10);
    func_00369E80(o + 0x250);
    mpvlib_InitPicAtr(o + 0x1D0);
    *(int *)(o + 0x384) = 0;
    *(int *)(o + 0x3A8) = *(int *)(o + 0x1AC);
    *(int *)(o + 0x388) = 0;
    *(int *)(o + 0x35C) = 0;
    *(int *)(o + 0x360) = 0;
    *(int *)(o + 0x364) = 0;
    *(int *)(o + 0x368) = 0;
    *(int *)(o + 0x398) = 0;
    for (i = 0; i < 4; i++)
        Obj0000_Set_Field_3BC_Triple((unsigned char *)o, i, 0, 0, 0);
    MPV_SetPicUsrBuf(o, 0, 0);
    *(int *)(o + 0x408) = 0;
    *(int *)(o + 0x188) = 2;
    return o;
}

__attribute__((section(".text.sftrn_CallTrEntry1_35BC38")))
void sftrn_CallTrEntry1_35BC38(int a0, int a1) {
    sftrn_CallTrEntry(a0, 1);
}
