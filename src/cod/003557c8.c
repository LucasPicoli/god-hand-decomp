/* cygnus-2.96 matched TU. */

__attribute__((section(".text.getFIFOindex")))
int getFIFOindex(void *a0, int addr) {
    char *f = (char *)a0;
    int end = ((*(int *)(f + 0x8) << 4) + *(int *)(f + 0x4) + 0x10) & 0x0FFFFFFF;
    if (addr == end) return 0;
    return (addr - *(int *)(f + 0x0)) / 0x800;
}
