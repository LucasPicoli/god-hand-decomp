struct vtbl {
    char pad[0x10];
    short off;
    void (*fn)(int);
};

__attribute__((section(".text.cCamera_move")))
void cCamera_move(int a0) {
    struct vtbl *v0 = *(struct vtbl**)((char*)a0 + 0x35C);
    v0->fn(a0 + v0->off);
    func_00138558(a0);
    cCamera_update(a0);
}

__attribute__((section(".text.InitFiveSubstructs2ABA78_13D0B8")))
void InitFiveSubstructs2ABA78_13D0B8(char *a0)
{
    cIDBase_resetAnim(a0);
    cIDBase_resetAnim(a0 + 0x140);
    cIDBase_resetAnim(a0 + 0x190);
    cIDBase_resetAnim(a0 + 0xA0);
    cIDBase_resetAnim(a0 + 0xF0);
}

__attribute__((section(".text.InitFiveSubstructs2AABA0_13D100")))
void InitFiveSubstructs2AABA0_13D100(char *a0)
{
    cIDBase_stepJitter(a0);
    cIDBase_stepJitter(a0 + 0x140);
    cIDBase_stepJitter(a0 + 0x190);
    cIDBase_stepJitter(a0 + 0xA0);
    cIDBase_stepJitter(a0 + 0xF0);
}
