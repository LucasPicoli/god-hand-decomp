/* sn-2.95.3-136 matched TU. */

extern int D_005FEE00;
extern void cSnd_SeDetachObj(int *arg0, void *arg1);

__attribute__((section(".text.ReleaseObj")))
void ReleaseObj(char *arg0) {
    if (arg0 != 0) {
        unsigned int hi = 0x80000000;

        if ((*(unsigned int *)(arg0 + 0x250) & hi) == 0) {
            char *v;

            cSnd_SeDetachObj(&D_005FEE00, arg0);
            v = *(char **)(arg0 + 0x214);
            (**(void (**)(char *))(v + 0x4C))(arg0 + *(short *)(v + 0x48));
            *(unsigned int *)(arg0 + 0x250) = (*(unsigned int *)(arg0 + 0x250) | hi) | 2;
        }
    }
}
