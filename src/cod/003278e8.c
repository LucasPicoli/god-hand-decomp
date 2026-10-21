struct AsyncCall;
extern int Obj33C8_GetField_CC(struct AsyncCall *self);
extern short Obj33C8_GetShortArrayE2_idx(struct AsyncCall *self, int ch);

/* AINF pan offset of one channel while the stream prepares or plays; -128 otherwise or without AINF. */
__attribute__((section(".text.func_003278E8")))
int func_003278E8(char *a0, int idx) {
    if (Obj33C8_GetField_CC(*(struct AsyncCall **)(a0 + 4)) <= 0) {
        return -0x80;
    }
    if ((unsigned int)(*(unsigned char*)(a0 + 1) - 2) < 2) {
        return Obj33C8_GetShortArrayE2_idx(*(struct AsyncCall **)(a0 + 4), idx);
    }
    return -0x80;
}
