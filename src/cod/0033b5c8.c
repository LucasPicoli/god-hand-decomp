/* cygnus-2.96 matched TU. */

extern void PrintfErrorReport(char *fmt, ...);
extern void func_0036D7C0(void);
extern void func_0036DCE8(void);
extern void func_0036D238(void);
extern void func_00366D18(void);
extern void func_00368AA0(void);

/* svm lock release. Fixed type tables are not named yet, so the hook slot stays a local record. */
struct FnEntry {
    void (*fn)(int);    /* 0x0 unlock hook, 0 when none is registered */
    int arg;            /* 0x4 hook argument */
};

extern struct FnEntry D_007588A8;
extern volatile int D_003E9948;     /* lock nesting depth */
extern volatile int D_003E994C;     /* lock owner type */

extern char D_00455E78[];           /* "...(type org=%d, type now=%d)" */

/* Leave one nesting level; at the outermost, report an owner mismatch (org, now), clear the owner, then call the unlock hook. */
__attribute__((section(".text.svm_unlock")))
void svm_unlock(int owner)
{
    void (*fn)(int);

    fn = D_007588A8.fn;
    if (fn) {
        D_003E9948--;
        if (D_003E9948 == 0) {
            if (D_003E994C != owner)
                PrintfErrorReport(D_00455E78, D_003E994C, owner);
            D_003E994C = 0;
        }
        D_007588A8.fn(D_007588A8.arg);
    }
}

extern unsigned char D_0045A514;                /* decoder build tag, must read 4 */
extern unsigned char D_0045A478[];              /* entry table */
extern unsigned char *volatile D_0076A588;      /* entry table pointer, volatile keeps retail's lui+addiu address */





/* Set up the entry pool of the decoder: hang the table pointer, run both init steps, size the pool, then mark the entries. */
__attribute__((section(".text.cri_InitEntryPool")))
void cri_InitEntryPool(int n, int work, unsigned int size)
{
    /* barrier: keeps the tag load after the prologue saves, as retail has it */
    do { } while (0);
    if (D_0045A514 != 4) {
        while (1) {
            ((void (*)(void))(unsigned int)-1)();
        }
    }
    D_0076A588 = D_0045A478;
    func_0036D7C0();
    func_0036DCE8();
    func_0036D280(n, work, size);
    func_0036D238();
}

extern unsigned char D_0045A370;                /* build tag, must read 4 */
extern char D_0045A320[];                       /* mode table */
extern char *volatile D_00766CD4;               /* active mode table, volatile keeps retail's lui+addiu address */
extern int func_00368D60(int a, int b);         /* pool setup: entry count, work area; defined in 0032d3a8.c */



/* Select the mode table, then run the pool setup; spin on a bad jump if the build tag is not 4.
   The two arguments only pass through to the setup, which is why retail keeps $a0/$a1 untouched. */
__attribute__((section(".text.sfd_InitPool")))
int sfd_InitPool(int a, int b)
{
    int r;

    D_00766CD4 = D_0045A320;
    if (D_0045A370 != 4) {
        for (;;) {
            ((void (*)(void))-1)();
        }
    }
    r = func_00368D60(a, b);
    if (r != 0) {
        return r;
    }
    func_00366D18();
    func_00368AA0();
    return 0;
}
