/* Byte-identical to RE4 PS2 (SLUS-21134) 0x002C11E8 — shared engine code.
 * Virtual dispatch with an inserted argument: calls (*a0)->vtable[0x18] as
 * fn(a0, 0, a1, a2). */

__attribute__((section(".text.sfadxt_GetFreeChunk")))
void sfadxt_GetFreeChunk(void *a0, int a1, int a2) {
    void (*fn)(void *, int, int, int) =
        *(void (**)(void *, int, int, int))((char *)*(void **)a0 + 0x18);
    fn(a0, 0, a1, a2);
}
