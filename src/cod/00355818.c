/* cygnus-2.96 matched TU. */

/* cygnus-2.96 matched TU. */

extern void func_003B63A0(void);
extern void func_003B63F0(void);

#define D_ENABLER (*(volatile unsigned int *) 0x1000F520)
#define D_ENABLEW (*(volatile unsigned int *) 0x1000F590)

__attribute__((section(".text.setD3_CHCR")))
void setD3_CHCR(unsigned int chcr) {
    func_003B63A0();
    D_ENABLEW = D_ENABLER | 0x00010000;
    *(volatile unsigned int *) 0x1000B000 = chcr;
    D_ENABLEW = D_ENABLER & 0xFFFEFFFF;
    func_003B63F0();
}
