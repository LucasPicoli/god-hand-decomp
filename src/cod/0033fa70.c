/* cygnus-2.96 cannot reproduce these three; sn-2.95.3-136 matches all three.
 * They were carved out of src/cod/0033f8.c, which is pinned to cygnus-2.96.
 * A TU carries one compiler key, so the three live here. */

/* ── func_0033FA70 — set mode 1 if the lock at +0xC is free ─────────────── */
__attribute__((section(".text.func_0033FA70")))
int func_0033FA70(char *p, int a1, int a2, int a3, int a4) {
    if (*(int *)(p + 0xC) != 0) {
        return 0;
    }
    *(int *)(p + 0x18) = a1;
    *(int *)(p + 0x1C) = a2;
    *(int *)(p + 0x14) = 1;
    *(int *)(p + 0x20) = a3;
    *(int *)(p + 0x24) = a4;
    return 1;
}

/* ── func_0033FAA0 — same shape, mode 2 ─────────────────────────────────── */
__attribute__((section(".text.func_0033FAA0")))
int func_0033FAA0(char *p, int a1, int a2, int a3, int a4) {
    if (*(int *)(p + 0xC) != 0) {
        return 0;
    }
    *(int *)(p + 0x18) = a1;
    *(int *)(p + 0x1C) = a2;
    *(int *)(p + 0x14) = 2;
    *(int *)(p + 0x20) = a3;
    *(int *)(p + 0x24) = a4;
    return 1;
}

/* ── func_0033FAD0 — same shape, mode 1 again ───────────────────────────── */
__attribute__((section(".text.func_0033FAD0")))
int func_0033FAD0(char *p, int a1, int a2, int a3, int a4) {
    if (*(int *)(p + 0xC) != 0) {
        return 0;
    }
    *(int *)(p + 0x18) = a1;
    *(int *)(p + 0x1C) = a2;
    *(int *)(p + 0x14) = 1;
    *(int *)(p + 0x20) = a3;
    *(int *)(p + 0x24) = a4;
    return 1;
}
