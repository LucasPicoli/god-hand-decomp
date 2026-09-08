#include "include_asm.h"

/* func_0038B9F0 (bulletNum): forwards to _IO_getc(a0). sn-2.95.3-136. */
extern int _IO_getc(char *a0);

__attribute__((section(".text.func_0038B9F0")))
int func_0038B9F0(char *a0) { return _IO_getc(a0); }
