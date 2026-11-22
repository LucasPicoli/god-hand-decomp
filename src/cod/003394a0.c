/* cygnus-2.96 matched TU. */

extern void SJCRS_Init(void);
extern void Forward33B658_3389F8(void);
extern void ResetBufferOnFirstEnterB(void);
extern void Forward33B670_338A10(void);
extern void func_00339550(void);
extern void SJCRS_Finish(void);

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.SJRBF_Init")))
void SJRBF_Init(void) {
    SJCRS_Init();
    Forward33B658_3389F8();
    ResetBufferOnFirstEnterB();
    Forward33B670_338A10();
}

/* sn-2.95.3-136 matched TU. */




__attribute__((section(".text.SJRBF_Finish")))
void SJRBF_Finish(void) {
    Forward33B658_3389F8();
    func_00339550();
    Forward33B670_338A10();
    SJCRS_Finish();
}
