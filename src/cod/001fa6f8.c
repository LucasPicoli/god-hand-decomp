/* cygnus-2.96 matched TU. */

__attribute__((section(".text.cCoreSave_setGold")))
void cCoreSave_setGold(void *a0, int a1) {
    void *p = *(void **)a0;
    if (p) *(int *)((char *)p + 0x20) = a1;
}

__attribute__((section(".text.cCoreSave_SetOliviaCostumeNo")))
void cCoreSave_SetOliviaCostumeNo(void *a0, int a1) {
    void *p = *(void **)a0;
    if (p) *(int *)((char *)p + 0xBC0) = a1;
}

__attribute__((section(".text.cPadVib_stopSeq")))
void cPadVib_stopSeq(char *a0) {
    *(int *)(a0 + 0x4) = 0;
}

__attribute__((section(".text.cRoomJump_setTblAddr")))
void cRoomJump_setTblAddr(int *arg0, int arg1) { *((int *)((char *)arg0 + 0x0)) = arg1; }

__attribute__((section(".text.cSnd_SetBgmState")))
void cSnd_SetBgmState(int *arg0, int arg1) { *((int *)((char *)arg0 + 0x13C)) = arg1; }
