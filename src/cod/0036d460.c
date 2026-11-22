/* cygnus-2.96 matched TU. */

extern void M2VHDEC_InitHn(void *);
extern void m2vlib_InitPicAtr(void *);
extern void *memcpy(void *, const void *, unsigned int);
extern char D_0076A590;

__attribute__((section(".text.m2vlib_InitHn")))
void *m2vlib_InitHn(char *o) {
    memcpy(o + 0x18, &D_0076A590, 0x40);
    M2VHDEC_InitHn(o);
    m2vlib_InitPicAtr(o + 0x58);
    *(int *)(o + 0x118) = 0;
    *(int *)(o + 0x0) = 2;
    return o;
}
