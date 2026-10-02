/* sn-2.95.3-136 matched TU. */

extern char *Getplayer(void);
extern int Obj0000_IsSet_Field_15F4_Bit_400000_10B698(void *p);
extern int cEmManage_CkPlCatched(void *p);
extern void cActionButton_set(void *a0, int a1, int a2, int a3, void *t0, void *t1, int t2);
extern void func_002DBA88();
extern int D_005864F0;
extern int D_00568288;
extern void func_002DBCA0();
extern void func_002DBB90();
extern void func_002DBF20();
extern void func_002DC2F0();
extern void func_002DC420();
extern void func_002DC548();
extern void func_002DC670();

__attribute__((section(".text.SetActionKickBomb")))
void SetActionKickBomb(void)
{
    char *r;
    char *g;

    r = Getplayer();
    if (*((short *) (r + 0x54A)) > 0) {
        if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(r) == 0) {
            g = (char *) &D_005864F0;
            if (*((int *) (g + 0x514)) <= 0) {
                if (cEmManage_CkPlCatched(g) == 0) {
                    cActionButton_set(&D_00568288, 0xB, 0x3, 0, func_002DBA88, 0, 0);
                }
            }
        }
    }
}

__attribute__((section(".text.SetActionStamp")))
void SetActionStamp(void *arg)
{
    char *s0;
    char *r;
    char *g;

    s0 = (char *) arg;
    r = Getplayer();
    if (*((short *) (r + 0x54A)) > 0) {
        if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(r) == 0) {
            g = (char *) &D_005864F0;
            if (*((int *) (g + 0x514)) <= 0) {
                if (cEmManage_CkPlCatched(g) == 0) {
                    cActionButton_set(&D_00568288, 0xA, 0x4, 0, func_002DBCA0, s0, 0);
                }
            }
        }
    }
}

__attribute__((section(".text.func_002DBB08")))
void func_002DBB08(void)
{
    char *r;
    char *g;

    r = Getplayer();
    if (*((short *) (r + 0x54A)) > 0) {
        if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(r) == 0) {
            g = (char *) &D_005864F0;
            if (*((int *) (g + 0x514)) <= 0) {
                if (cEmManage_CkPlCatched(g) == 0) {
                    cActionButton_set(&D_00568288, 0xB, 0x4, 0, func_002DBB90, 0, 0);
                }
            }
        }
    }
}

__attribute__((section(".text.func_002DBE98")))
void func_002DBE98(void)
{
    char *r;
    char *g;

    r = Getplayer();
    if (*((short *) (r + 0x54A)) > 0) {
        if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(r) == 0) {
            g = (char *) &D_005864F0;
            if (*((int *) (g + 0x514)) <= 0) {
                if (cEmManage_CkPlCatched(g) == 0) {
                    cActionButton_set(&D_00568288, 0x7, 0x6, 0, func_002DBF20, 0, 0);
                }
            }
        }
    }
}

__attribute__((section(".text.func_002DC260")))
void func_002DC260(void *arg)
{
    char *s0;
    char *r;
    char *g;

    s0 = (char *) arg;
    r = Getplayer();
    if (*((short *) (r + 0x54A)) > 0) {
        if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(r) == 0) {
            g = (char *) &D_005864F0;
            if (*((int *) (g + 0x514)) <= 0) {
                if (cEmManage_CkPlCatched(g) == 0) {
                    cActionButton_set(&D_00568288, 0xB, 0xC, 0, func_002DC2F0, s0, 0);
                }
            }
        }
    }
}

__attribute__((section(".text.func_002DC390")))
void func_002DC390(void *arg)
{
    char *s0;
    char *r;
    char *g;

    s0 = (char *) arg;
    r = Getplayer();
    if (*((short *) (r + 0x54A)) > 0) {
        if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(r) == 0) {
            g = (char *) &D_005864F0;
            if (*((int *) (g + 0x514)) <= 0) {
                if (cEmManage_CkPlCatched(g) == 0) {
                    cActionButton_set(&D_00568288, 0xB, 0x21, 0, func_002DC420, s0, 0);
                }
            }
        }
    }
}

__attribute__((section(".text.func_002DC4B8")))
void func_002DC4B8(void *arg)
{
    char *s0;
    char *r;
    char *g;

    s0 = (char *) arg;
    r = Getplayer();
    if (*((short *) (r + 0x54A)) > 0) {
        if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(r) == 0) {
            g = (char *) &D_005864F0;
            if (*((int *) (g + 0x514)) <= 0) {
                if (cEmManage_CkPlCatched(g) == 0) {
                    cActionButton_set(&D_00568288, 0xB, 0xC, 0, func_002DC548, s0, 0);
                }
            }
        }
    }
}

__attribute__((section(".text.func_002DC5E0")))
void func_002DC5E0(void *arg)
{
    char *s0;
    char *r;
    char *g;

    s0 = (char *) arg;
    r = Getplayer();
    if (*((short *) (r + 0x54A)) > 0) {
        if (Obj0000_IsSet_Field_15F4_Bit_400000_10B698(r) == 0) {
            g = (char *) &D_005864F0;
            if (*((int *) (g + 0x514)) <= 0) {
                if (cEmManage_CkPlCatched(g) == 0) {
                    cActionButton_set(&D_00568288, 0xB, 0xC, 0, func_002DC670, s0, 0);
                }
            }
        }
    }
}
