/* cygnus-2.96 matched TU. */

extern void MPV_GoNextDelimSj(void *a0);
extern long long func_003A9228(int a0, int *buf, int size);
extern void func_00326050(char *fmt, int val);
extern char D_00454570[];
extern char D_00454588[];
extern char D_00454598[];

__attribute__((section(".text.func_0036B6D8")))
int func_0036B6D8(void *a0, void *a1) {
    int buf[4];
    void *s0;
    int *s1;
    int v1;
    int a1_part;
    int diff;
    int step;
    int next;

    s0 = a1;
    s1 = (int *)((char *)a0 + 0x38C);

    {
        void (*fn)(void *, int, int, int *) =
            *(void (**)(void *, int, int, int *))((char *)*(void **)s0 + 0x18);
        fn(s0, 1, 0x7FFFFFFF, s1);
    }

    v1 = *s1;
    a1_part = v1 & -4;
    diff = v1 - a1_part;
    step = (diff << 3) >> 3;
    next = a1_part + step + 4;
    func_0033ACA0(s1, next - v1, s1, buf);

    {
        void (*fn)(void *, int, int *) =
            *(void (**)(void *, int, int *))((char *)*(void **)s0 + 0x20);
        fn(s0, 0, s1);
    }

    {
        void (*fn)(void *, int, int *) =
            *(void (**)(void *, int, int *))((char *)*(void **)s0 + 0x1C);
        fn(s0, 1, buf);
    }

    MPV_GoNextDelimSj(s0);

    return 0;
}

__attribute__((section(".text.func_00333B40")))
int func_00333B40(int a0, int *a1, int *a2) {
    int buf[4];
    char *p;

    buf[0] = a0;
    *a1 = func_003A9228(a0, buf, 0x10);

    p = (char *)buf[0];
    if (*p) buf[0] = (int)(p + 1);

    if (a2) *a2 = func_003A9228(buf[0], buf, 0x10);

    func_00326050(D_00454570, a0);
    func_00326050(D_00454588, *a1);
    func_00326050(D_00454598, *a2);

    return 1;
}
