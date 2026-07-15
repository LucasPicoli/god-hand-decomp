/* sn-2.95.3-136 matched TU. */

extern void *cModel_getMeshPtr(void *a0, int a1);
extern void func_00149220(void *a0, float f);

__attribute__((section(".text.cModel_ScrollTexture")))
void cModel_ScrollTexture(void *a0, float f) {
    char *p = (char *)cModel_getMeshPtr(a0, 0);
    if (p != 0) {
        do {
            func_00149220(p, f);
            p = *(char **)(p + 0x404);
        } while (p != 0);
    }
}
