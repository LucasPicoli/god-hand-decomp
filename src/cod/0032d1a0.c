/* cygnus-2.96 matched TU. */

extern void func_00324950(void);
extern void func_0032F230(void);
extern void func_003A52F0(void *dst, int val, int len);
extern void func_0032D170(void);
extern void func_0032D198(void);
extern volatile int D_003D1470;
extern int D_003D1474;
extern int D_003D1478;
extern char D_003D1488[];
extern char D_00452980[];
extern char D_00452990[];
extern float func_003A1DF0(float x);
extern void func_0032B488(void *target, int whole, int rest);
extern int D_003D844C;
extern int D_003D8450;
extern int D_003D8454;
extern void Forward33B568_33B6A0(void);
extern void Forward33B5C8_33B6D0(void);
extern void func_00331400(void);

/* Reference-counted start: the first caller resets the module state and registers two handlers, every caller bumps the count. */
__attribute__((section(".text.ModuleStart_refCounted")))
void ModuleStart_refCounted(void)
{
    (void)D_003D1470;
    if (D_003D1474 == 0) {
        func_00324950();
        func_0032F230();
        func_003A52F0(D_003D1488, 0, 0x9E0);
        func_0033BA10(2, 0, (void *)func_0032D170, 0, D_00452980);
        D_003D1478 = func_0033B810(5, (void *)func_0032D198, 0, D_00452990);
    }
    D_003D1474 = D_003D1474 + 1;
}

typedef struct TargetRef {
    void *target;               /* 0x00 */
} TargetRef;

typedef struct TargetOwner {
    char unk00[0x2004];
    TargetRef *ref;             /* 0x2004 */
} TargetOwner;

/* Converts a value `n` on a log scale to a whole part and a remainder in hundredths and passes both to the target; 1000 is the neutral point. */
__attribute__((section(".text.TargetOwner_setLogScaleValue")))
void TargetOwner_setLogScaleValue(TargetOwner *owner, int n)
{
    void *target = owner->ref->target;
    int whole;
    int rest;
    float v;
    int fine;

    if (target == 0) {
        return;
    }
    if (n == 1000) {
        whole = 0;
        rest = 0;
    } else {
        v = (func_003A1DF0((float)n) - 6.9077549f) * 1731.23401f;
        fine = (int)v;
        whole = (int)(v * 0.01f);
        rest = fine - whole * 100;
    }
    func_0032B488(target, whole, rest);
}

typedef signed char Sint8;
typedef struct srd_obj {
    Sint8 used;
    Sint8 devtype;              /* 0x01 1 or 2 selects the channel */
    Sint8 stat;
    char rsv;
    int pad[0x10];
} SRD_OBJ;

extern SRD_OBJ D_003D8410;



extern volatile int D_003D8488;   /* volatile: keeps retail's separate address add before the load */



extern void func_00331718(SRD_OBJ *srd);
extern void func_00331900(SRD_OBJ *srd);


/* Shuts the pending read down: runs the cleanup for the object's device type, taking the lock around it when the channel is active, then clears the busy word. */
__attribute__((section(".text.CdSrd_finishRead")))
void CdSrd_finishRead(void)
{
    SRD_OBJ *srd = &D_003D8410;

    if (func_0033BF18(&D_003D844C) == 0) {
        return;
    }
    if (srd->devtype == 1) {
        if (D_003D8450 == 1) {
            Forward33B568_33B6A0();
        }
        func_00331718(srd);
        if (D_003D8450 == 1) {
            Forward33B5C8_33B6D0();
        }
    }
    if (srd->devtype == 2) {
        if (D_003D8454 == 1) {
            Forward33B568_33B6A0();
        }
        func_00331900(srd);
        if (D_003D8454 == 1) {
            Forward33B5C8_33B6D0();
        }
    }
    if (D_003D8488 != 0) {
        func_00331400();
    }
    D_003D844C = 0;
}
