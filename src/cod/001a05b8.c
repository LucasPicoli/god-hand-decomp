extern int D_00785EE8;
extern int D_00426B68;
extern int D_00785798;
extern int D_00426B80;
#include "godhand/objField.h"
extern int D_00574380;
extern int D_00785EF8;
extern int D_00426C50;
extern int D_00426C68;
extern int D_00785F08;
extern int D_00426D38;
extern int D_00426D50;
extern int D_00785F18;
extern int D_00426E20;

__attribute__((section(".text.GetTypeDescriptorD_1A05B8")))
int *GetTypeDescriptorD_1A05B8(void)
{
    if (D_00785EE8 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_00785EE8, &D_00426B68, &D_00785798);
    }
    return &D_00785EE8;
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitVu0SlotArray5B_1A0608")))
void *InitVu0SlotArray5B_1A0608(void *a0)
{
    char *p;
    int i;

    InitVtable214_429C80_1C27E8(a0);
    *(int *)((char *)a0 + 0x214) = (int)&D_00426B80;
    p = (char *)a0 + 0x620;
    for (i = 5; i != -1; i--) {
        VU0_SQC2_VF0(p, 0x00);
        VU0_SQC2_VF0(p, 0x10);
        VU0_SQC2_VF0(p, 0x20);
        VU0_SQC2_VF0(p, 0x30);
        VU0_SQC2_VF0(p, 0x40);
        Obj0000_Set_Byte_54(p, 0);
        p += 0x60;
    }
    return a0;
}

__attribute__((section(".text.FreeActorResourcesE_1A0690")))
void FreeActorResourcesE_1A0690(void *a0, void *a1)
{
    *(int *)((char *)a0 + 0x214) = (int)&D_00426B80;
    if (*(int *)((char *)a0 + 0x600) != 0) {
        ClearAndResetFields_1FE278(&D_00574380, *(int *)((char *)a0 + 0x600));
        *(int *)((char *)a0 + 0x600) = 0;
    }
    ResetField214FreeField180_1C2820(a0, a1);
}

__attribute__((section(".text.GetTypeDescriptorE_1A0830")))
void *GetTypeDescriptorE_1A0830(void)
{
	if (D_00785EF8 == 0) {
		GetOrInitGlobal785798_1C3BE8();
		SetField_0_4_8_31EEA8(&D_00785EF8, &D_00426C50, &D_00785798);
	}
	return &D_00785EF8;
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitVu0SlotArray4B_1A0880")))
void *InitVu0SlotArray4B_1A0880(void *a0)
{
	char *p;
	int i;

	InitVtable214_429C80_1C27E8(a0);
	p = (char *)a0 + 0x620;
	*(int **)((char *)a0 + 0x214) = &D_00426C68;
	for (i = 4; i != -1; i--) {
		VU0_SQC2_VF0(p, 0x00);
		VU0_SQC2_VF0(p, 0x10);
		VU0_SQC2_VF0(p, 0x20);
		VU0_SQC2_VF0(p, 0x30);
		VU0_SQC2_VF0(p, 0x40);
		Obj0000_Set_Byte_54(p, 0);
		p += 0x60;
	}
	return a0;
}

__attribute__((section(".text.FreeActorResourcesF_1A0908")))
void FreeActorResourcesF_1A0908(void *a0, void *a1)
{
	int v1;
	*(int **)((char *)a0 + 0x214) = &D_00426C68;
	v1 = *(int *)((char *)a0 + 0x600);
	if (v1 != 0) {
		ClearAndResetFields_1FE278(&D_00574380, (void *)v1);
		*(int *)((char *)a0 + 0x600) = 0;
	}
	ResetField214FreeField180_1C2820(a0, a1);
}

__attribute__((section(".text.GetTypeDescriptorF_1A0AA0")))
void *GetTypeDescriptorF_1A0AA0(void)
{
	if (D_00785F08 == 0) {
		GetOrInitGlobal785798_1C3BE8();
		SetField_0_4_8_31EEA8(&D_00785F08, &D_00426D38, &D_00785798);
	}
	return &D_00785F08;
}

#include "godhand/vu0.h"





__attribute__((section(".text.InitObjSlots_1A0AF0")))
void *InitObjSlots_1A0AF0(void *a0)
{
	char *p;
	int i;

	InitVtable214_429C80_1C27E8(a0);
	p = (char *)a0 + 0x620;
	*(int **)((char *)a0 + 0x214) = &D_00426D50;
	for (i = 5; i != -1; i--) {
		VU0_SQC2_VF0(p, 0x00);
		VU0_SQC2_VF0(p, 0x10);
		VU0_SQC2_VF0(p, 0x20);
		VU0_SQC2_VF0(p, 0x30);
		VU0_SQC2_VF0(p, 0x40);
		Obj0000_Set_Byte_54(p, 0);
		p += 0x60;
	}
	return a0;
}

__attribute__((section(".text.GetObjSingleton_1A0D18")))
void *GetObjSingleton_1A0D18(void)
{
    if (D_00785F18 == 0) {
        GetOrInitGlobal785798_1C3BE8();
        SetField_0_4_8_31EEA8(&D_00785F18, &D_00426E20, &D_00785798);
    }
    return &D_00785F18;
}
