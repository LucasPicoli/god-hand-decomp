/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cEm00.h"
#include "godhand/motion.h"
#include "godhand/cOmWeapon.h"
#include "godhand/cCamera.h"
#include "godhand/cGameObj.h"

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void *Getplayer(void);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern int Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08(void *a0);

/* sn-2.95.3-136 matched TU. */





















__attribute__((section(".text.func_00233248")))
void func_00233248(void *arg0)
{
    cGameObj *s1 = arg0;
    float fv = 0.0f;

    *(char *)((char *)s1 + 0x186A) = 2;
    *(int *)((char *)s1 + 0x16D4) |= 0x400;
    CheckSlotsShort2FEAndSetByte1864_262A10(arg0);
    switch (s1->step) {
    case 0: {
        int gb;
        int a1v, a2v;
        int st;

        *(char *)((char *)s1 + 0x1864) = 0;
        gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s1) & 0xFFFF;
        *(int *)((char *)s1 + 0x5F4) = 0;
        *(int *)((char *)s1 + 0x5FC) = 0;
        *(int *)((char *)s1 + 0x5F0) = 0xF;
        *(float *)((char *)s1 + 0x608) = 1.0f;
        StoreMotionParamsBoth_2609A8(arg0, 0x14, 0, 0x37, -1, 0);
        st = s1->emNo;
        *(float *)((char *)s1 + 0x604) = fv;
        *(float *)((char *)s1 + 0x60C) = fv;
        if (st >= 0x250) {
            if (st < 0x252) goto lb;
            if (st == 0x260) goto lc;
        }
        {
            char *pa;
            StoreMotionParamsBoth_2609A8(arg0, 0x14, 3, 0x37, -1, 0);
            pa = s1->pack;
            a1v = *(int *)(pa + 0x390) + (int)pa;
            a2v = *(int *)(pa + 0x394) + (int)pa;
        }
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            char *v1 = s1->pack;
            a2v = *(int *)(v1 + 0x398) + (int)v1;
        }
        fv = 2.0f;
        goto lmerge;
    lb:
        {
            char *pb;
            StoreMotionParamsBoth_2609A8(arg0, 0x1E, 0x1B, 0x45, -1, 0);
            pb = s1->pack;
            a1v = *(int *)(pb + 0x19E8) + (int)pb;
            a2v = *(int *)(pb + 0x19EC) + (int)pb;
        }
        if (cCoreSave_getGameLevel(&D_00569B70) == 5) {
            char *v1 = s1->pack;
            a2v = *(int *)(v1 + 0x19F0) + (int)v1;
        }
        *(float *)((char *)s1 + 0x604) = 20.0f;
        fv = 3.0f;
        goto lmerge;
    lc:
        {
            char *pc;
            StoreMotionParamsBoth_2609A8(arg0, 0x46, 0x1B, 0x45, -1, 0);
            pc = s1->pack;
            a1v = *(int *)(pc + 0x30D8) + (int)pc;
            a2v = *(int *)(pc + 0x30DC) + (int)pc;
        }
        *(float *)((char *)s1 + 0x604) = 20.0f;
        fv = 3.0f;
    lmerge:
        switch (cCoreSave_getGameLevel(&D_00569B70)) {
        case 1: default: *(int *)((char *)s1 + 0x5F0) = (int)((float)*(int *)((char *)s1 + 0x5F0) * 0.75f); break;
        case 2: *(int *)((char *)s1 + 0x5F0) = (int)((float)*(int *)((char *)s1 + 0x5F0) * 0.8f); break;
        case 3: case 4: *(int *)((char *)s1 + 0x5F0) = (int)((float)*(int *)((char *)s1 + 0x5F0) * 0.9f); break;
        case 5: break;
        }
        func_002A8578(s1, a1v, a2v, 5, fv, gb, 0);
        {
            void *p = *(void **)((char *)s1 + 0x6F0);
            if (p != 0) {
                Obj1D00_ClearState_6(p);
            }
            p = *(void **)((char *)s1 + 0x708);
            if (p != 0) {
                Obj1D00_ClearState_7(p);
            }
        }
        s1->hitFlash = 5.0f;
        *(float *)((char *)s1 + 0x600) = s1->rot.y;
        s1->step += 1;
    }
        /* fallthrough */
    case 1:
        if (*(float *)((char *)s1 + 0x604) > 0.0f) {
            *(int *)((char *)s1 + 0x16D0) |= 0x800000;
            *(float *)((char *)s1 + 0x604) -= s1->speedRate;
        }
        if (*(int *)((char *)s1 + 0x5F0) != 0) {
            float *tgt;
            char *o;
            float d;
            *(int *)((char *)s1 + 0x5F0) -= 1;
            tgt = *(float **)((char *)s1 + 0xF0);
            o = (char *)Getplayer();
            d = Turn_dest(tgt, *(float *)((char *)s1 + 0x600), *(void **)(o + 0xF0),
                          s1->speedRate * 0.19634955f);
            *(float *)((char *)s1 + 0x600) += d;
            *(float *)((char *)s1 + 0x600) = Adjust_theta(*(float *)((char *)s1 + 0x600));
            s1->rot.y += d;
            s1->rot.y = Adjust_theta(s1->rot.y);
        }
        if (moveMotion(s1) != 0) {
            cObjBase_addNullSpeed_Rotation(s1, 1.0f);
            cObjBase_addNullSpeed(s1, 1.0f);
            func_002705D8(s1);
            return;
        }
        s1->nullSpeed.z = s1->nullSpeed.z * *(float *)((char *)s1 + 0x608);
        cObjBase_addNullSpeed_Rotation(s1, 1.0f);
        cObjBase_addNullSpeed(s1, 1.0f);
        break;
    }
    if (s1->emNo == 0x222) {
        unsigned short fl = s1->seqFlags;
        if (fl & 2) {
            s1->seqFlags = fl & 0xFFFD;
            *(char *)((char *)s1 + 0x1865) = 2;
            *(float *)((char *)s1 + 0x17D4) = 6.0f;
        }
    }
    if (s1->emNo == 0x208) {
        void *p = *(void **)((char *)s1 + 0x700);
        if (p != 0 && Obj1D00_IsSet_Byte_2F4_EqFour_Byte_2F5_1D0B08(p) == 0) {
            *(int *)((char *)s1 + 0x16D0) |= 0x80000000;
        }
    }
    func_00260B30(arg0);
    if (cCoreSave_getGameLevel(&D_00569B70) >= 3 && func_0026F1D8(s1) == 0 &&
        (s1->seqFlags & 0x10) != 0 &&
        *(unsigned char *)((char *)s1 + 0x1864) == 0 && func_00262AA8(arg0) != 0) {
        return;
    }
    if (*(int *)((char *)s1 + 0x5FC) != 0) {
        *(int *)((char *)s1 + 0x16D4) &= 0xFFFFFBFF;
    }
}
