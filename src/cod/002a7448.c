/* ee-2.9-991111 matched TU. */

extern int IsTargetVisible_14B470();

__attribute__((section(".text.cGameObj_isClip")))
int cGameObj_isClip(void *a0) {
    long f = *(unsigned int *)((char *)a0 + 0x5A0);
    long t;
    t = f & 1;
    if (t != 0) {
        return 1;
    }
    t = (f >> 1) & 1;
    if (t != 0) {
        return 1;
    }
    return IsTargetVisible_14B470(a0) != 0;
}
