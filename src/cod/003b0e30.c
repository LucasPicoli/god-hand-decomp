/* ee-2.9-991111 matched TU. */

extern void kputchar(int c);
__attribute__((section(".text.serialPutchar")))
void serialPutchar(int c)
{ if (c == 10) { kputchar(13); kputchar(10); } else { kputchar(c); } }
