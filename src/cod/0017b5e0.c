/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.cOl1b_setCloseFix")))
void cOl1b_setCloseFix(unsigned char *p)
{
    char hold[16];
    char *e1;
    int cnt;

    if (p[0x601] != 1) {
        return;
    }
    cnt = *((unsigned char *) (p + 0x2B4));
    *((int *) hold) = cnt;
    if (cnt != 0) {
        e1 = *((char **) *((char **) (p + 0x278)));
    } else {
        e1 = 0;
    }
    if (e1 != 0) {
        char *e2;
        int c2;
        int *q;

        c2 = *((unsigned char *) (p + 0x2B4));
        *((int *) hold) = c2;
        if (c2 != 0) {
            e2 = *((char **) *((char **) (p + 0x278)));
        } else {
            e2 = 0;
        }
        q = (int *) (e2 + 0x100);
        *((float *) (e2 + 0x100)) = 1.3962633609771729f;
        q[1] = 0;
        q[2] = 0;
    }
    {
        char *e3;
        int c3;
        int i3;

        c3 = *((unsigned char *) (p + 0x2B4));
        *((int *) hold) = c3;
        i3 = 2;
        if (i3 < c3) {
            e3 = (char *) *((int *) (*((int *) (p + 0x278)) + 8));
        } else {
            e3 = 0;
        }
        if (e3 != 0) {
            char *e4;
            int c4;
            int i4;
            int *q;

            c4 = *((unsigned char *) (p + 0x2B4));
            *((int *) hold) = c4;
            i4 = 2;
            if (i4 < c4) {
                e4 = (char *) *((int *) (*((int *) (p + 0x278)) + 8));
            } else {
                e4 = 0;
            }
            q = (int *) (e4 + 0x100);
            *((float *) (e4 + 0x100)) = 1.3962633609771729f;
            q[1] = 0;
            q[2] = 0;
        }
    }
    p[0x601] = 0;
    p[0x600] = 0;
    p[0x2F4] = 0;
    p[0x2F5] = 0;
    p[0x2F6] = 0;
    p[0x2F7] = 0;
}

__attribute__((section(".text.cOm4f_setOpenCloseRot")))
void cOm4f_setOpenCloseRot(unsigned char *p, float a, float b)
{
    char hold[16];
    char *e1;
    int cnt;

    *((float *) (p + 0x794)) = a;
    *((float *) (p + 0x798)) = b;
    if (p[0x761] == 1) {
        cnt = *((unsigned char *) (p + 0x2B4));
        *((int *) hold) = cnt;
        if (cnt != 0) {
            e1 = *((char **) *((char **) (p + 0x278)));
        } else {
            e1 = 0;
        }
        if (e1 != 0) {
            char *e2;
            int c2;
            int *q;

            c2 = *((unsigned char *) (p + 0x2B4));
            *((int *) hold) = c2;
            if (c2 != 0) {
                e2 = *((char **) *((char **) (p + 0x278)));
            } else {
                e2 = 0;
            }
            q = (int *) (e2 + 0x100);
            *((float *) (e2 + 0x100)) = *((float *) (p + 0x794));
            q[1] = 0;
            q[2] = 0;
        }
    } else {
        cnt = *((unsigned char *) (p + 0x2B4));
        *((int *) hold) = cnt;
        if (cnt != 0) {
            e1 = *((char **) *((char **) (p + 0x278)));
        } else {
            e1 = 0;
        }
        if (e1 != 0) {
            char *e2;
            int c2;
            int *q;

            c2 = *((unsigned char *) (p + 0x2B4));
            *((int *) hold) = c2;
            if (c2 != 0) {
                e2 = *((char **) *((char **) (p + 0x278)));
            } else {
                e2 = 0;
            }
            q = (int *) (e2 + 0x100);
            *((float *) (e2 + 0x100)) = *((float *) (p + 0x798));
            q[1] = 0;
            q[2] = 0;
        }
    }
}

__attribute__((section(".text.func_0017B5E0")))
void func_0017B5E0(unsigned char *p)
{
    char hold[16];
    char *e1;
    int cnt;

    if (p[0x602] == 1) {
        return;
    }
    if (p[0x601] != 0) {
        return;
    }
    cnt = *((unsigned char *) (p + 0x2B4));
    *((int *) hold) = cnt;
    if (cnt != 0) {
        e1 = *((char **) *((char **) (p + 0x278)));
    } else {
        e1 = 0;
    }
    if (e1 != 0) {
        char *e2;
        int c2;
        int *q;

        c2 = *((unsigned char *) (p + 0x2B4));
        *((int *) hold) = c2;
        if (c2 != 0) {
            e2 = *((char **) *((char **) (p + 0x278)));
        } else {
            e2 = 0;
        }
        q = (int *) (e2 + 0x100);
        *((float *) (e2 + 0x100)) = -1.3962633609771729f;
        q[1] = 0;
        q[2] = 0;
    }
    {
        char *e3;
        int c3;
        int i3;

        c3 = *((unsigned char *) (p + 0x2B4));
        *((int *) hold) = c3;
        i3 = 2;
        if (i3 < c3) {
            e3 = (char *) *((int *) (*((int *) (p + 0x278)) + 8));
        } else {
            e3 = 0;
        }
        if (e3 != 0) {
            char *e4;
            int c4;
            int i4;
            int *q;

            c4 = *((unsigned char *) (p + 0x2B4));
            *((int *) hold) = c4;
            i4 = 2;
            if (i4 < c4) {
                e4 = (char *) *((int *) (*((int *) (p + 0x278)) + 8));
            } else {
                e4 = 0;
            }
            q = (int *) (e4 + 0x100);
            *((float *) (e4 + 0x100)) = -1.3962633609771729f;
            q[1] = 0;
            q[2] = 0;
        }
    }
    p[0x601] = 1;
    p[0x600] = 0;
    p[0x2F4] = 0;
    p[0x2F5] = 0;
    p[0x2F6] = 0;
    p[0x2F7] = 0;
}
