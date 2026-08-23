/* ee-2.9-991111 matched TU. */

extern void func_003A0DE8(void *v);

/* IPU bitstream: skip to the next byte boundary. */




#define IPU_BP (*(volatile unsigned int *)0x10002020)

__attribute__((section(".text.flushByteBoundary")))
void flushByteBoundary(void *v)
{
	int n;

	func_003A0DE8(v);
	n = (-(int)(IPU_BP & 7)) & 7;
	if (n != 0)
		func_003A0E20(v, n);
}
