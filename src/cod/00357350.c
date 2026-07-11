/* cygnus-2.96 matched TU. */

extern long long func_0035BA58(void);
extern void func_00357468(void *a0);
extern void func_0035BB60(void *a0, long long a1);

/* matched TU. */










__attribute__((section(".text.func_00357350")))
void func_00357350(void *a0) {
    char *s1 = (char *)a0;
    int state = *(int *)(s1 + 0x48);
    long long t2;
    if ((unsigned)(state - 1) >= 4) return;
    if (*(int *)(s1 + 0x44) == 0) return;
    *(volatile int *)(s1 + 0x44) = 0;
    t2 = func_0035BA58();
    if ((unsigned)(state - 2) < 3) func_00357468(s1);
    state = *(int *)(s1 + 0x48);
    switch (state) {
    case 0: break;
    case 1: state = func_003574A8(s1); break;
    case 2: state = func_003574D8(s1); break;
    case 3: state = func_00357870(s1); break;
    case 4: state = func_00357910(s1); break;
    case 5: break;
    case 6: state = func_00357980(s1); break;
    }
    *(int *)(s1 + 0x48) = state;
    func_0035BB60(s1 + 0x3760, func_0035BA58() - t2);
}
