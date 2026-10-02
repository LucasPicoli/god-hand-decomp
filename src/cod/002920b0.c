/* sn-2.95.3-136 matched TU. */

#include "godhand/cCoreSave.h"
#include "godhand/cEmManage.h"

extern unsigned char D_00747A50[];
extern int irand(void);
extern int D_003C0490[];
extern int D_003C04A8[];
extern int D_003C04B8[];
extern int D_003C04D0[];
extern int D_003C04E8[];
extern int D_003C0500[];
extern int D_003C0518[];
extern int D_003C0530[];

/* Picks the item id of a skill scroll the player has not learned yet, from
 * the list for the current stage; 0x3D8 when every skill of the list is known. */
__attribute__((section(".text.func_002920B0")))
int func_002920B0(void)
{
    int list[20];
    int item = 0x3D8;
    unsigned int n = 0;
    unsigned int i;
    int skill;

    switch (D_00747A50[1]) {
    case 1:
        for (i = 0; i < 6; i++) {
            skill = D_003C0490[i];
            if (cCoreSave_getSkill(&D_00569B70, skill) < 0)
                list[n++] = skill;
        }
        break;
    case 2:
        for (i = 0; i < 4; i++) {
            skill = D_003C04A8[i];
            if (cCoreSave_getSkill(&D_00569B70, skill) < 0)
                list[n++] = skill;
        }
        break;
    case 3:
        for (i = 0; i < 5; i++) {
            skill = D_003C04B8[i];
            if (cCoreSave_getSkill(&D_00569B70, skill) < 0)
                list[n++] = skill;
        }
        break;
    case 4:
        for (i = 0; i < 5; i++) {
            skill = D_003C04D0[i];
            if (cCoreSave_getSkill(&D_00569B70, skill) < 0)
                list[n++] = skill;
        }
        break;
    case 5:
        for (i = 0; i < 5; i++) {
            skill = D_003C04E8[i];
            if (cCoreSave_getSkill(&D_00569B70, skill) < 0)
                list[n++] = skill;
        }
        break;
    case 6:
        for (i = 0; i < 5; i++) {
            skill = D_003C0500[i];
            if (cCoreSave_getSkill(&D_00569B70, skill) < 0)
                list[n++] = skill;
        }
        break;
    case 7:
        for (i = 0; i < 5; i++) {
            skill = D_003C0518[i];
            if (cCoreSave_getSkill(&D_00569B70, skill) < 0)
                list[n++] = skill;
        }
        break;
    case 8:
        for (i = 0; i < 5; i++) {
            skill = D_003C0530[i];
            if (cCoreSave_getSkill(&D_00569B70, skill) < 0)
                list[n++] = skill;
        }
        break;
    }
    if (n != 0) {
        skill = list[(unsigned int)irand() % n];
        item = skill + 0xA00;
    }
    return item;
}
