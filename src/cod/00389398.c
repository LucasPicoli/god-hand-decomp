/* ee-2.9-991111 matched TU. */

extern int skip_ws__FP9streambuf(void *a0);

__attribute__((section(".text.func_00389398")))
int func_00389398(void *a0) {
    int ch = skip_ws__FP9streambuf(*(void **)*(void **)a0);
    if (ch == -1) {
        *(unsigned char *)((char *)*(void **)a0 + 0x1A) |= 3;
        return 0;
    }
    func_0038B460(*(void **)*(void **)a0, (char)ch);
    return 1;
}
