/* cygnus-2.96 matched TU. */

extern void Forward33B658_3389F8(void);
extern void func_00339108(void *a0, int a1, int a2);
extern void Forward33B670_338A10(void);
extern void func_003391F8(void *a0, int a1, int a2);
extern void func_003398F8(void *a0, int a1, int a2, int a3);
extern void SjRbf_putChunk(void *a0, int a1, int a2);
extern void SjRbf_ungetChunk(void *a0, int a1, int a2);
extern void func_0033A468(void *a0, int a1, int a2);

__attribute__((section(".text.SJMEM_PutChunk")))
void SJMEM_PutChunk(void *a0, int a1, int a2) {
    Forward33B658_3389F8();
    func_00339108(a0, a1, a2);
    Forward33B670_338A10();
}

__attribute__((section(".text.SJMEM_UngetChunk")))
void SJMEM_UngetChunk(void *a0, int a1, int a2) {
    Forward33B658_3389F8();
    func_003391F8(a0, a1, a2);
    Forward33B670_338A10();
}

__attribute__((section(".text.SJRBF_GetChunk")))
void SJRBF_GetChunk(void *a0, int a1, int a2, int a3) {
    Forward33B658_3389F8();
    func_003398F8(a0, a1, a2, a3);
    Forward33B670_338A10();
}

__attribute__((section(".text.SJRBF_PutChunk")))
void SJRBF_PutChunk(void *a0, int a1, int a2) {
    Forward33B658_3389F8();
    SjRbf_putChunk(a0, a1, a2);
    Forward33B670_338A10();
}

__attribute__((section(".text.SJRBF_UngetChunk")))
void SJRBF_UngetChunk(void *a0, int a1, int a2) {
    Forward33B658_3389F8();
    SjRbf_ungetChunk(a0, a1, a2);
    Forward33B670_338A10();
}

__attribute__((section(".text.SJUNI_EntryErrFunc")))
void SJUNI_EntryErrFunc(void *a0, int a1, int a2) {
    Forward33B658_3389F8();
    func_0033A468(a0, a1, a2);
    Forward33B670_338A10();
}
