/* sn-2.95.3-136 matched TU. */
#include "godhand/DogRace.h"

extern void *CreateObj(int a0, int a1);
extern void cOmBase_setTexChange(void *a0, int a1);
extern float frand(float a0, float a1);
extern int irand(void);

/* sn-2.95.3-136 matched TU. */






typedef struct { int a[9]; } T36;

/* Spawns dog `n`: creates its object, picks a colour, copies the stat record
* and rolls its speed and power. 0 if the object could not be made. */
__attribute__((section(".text.func_001EE780")))
int func_001EE780(DogRaceDog *dog, unsigned char n, DogRaceStats *stats) {
    char *obj;
    char *vt;
    int (*fp)();
    float r;
    unsigned int rem;
    char *p;
    unsigned int m;

    obj = (char *)CreateObj(0x371, 0xFFFF);
    dog->obj = obj;
    if (obj == 0) {
        return 0;
    }
    vt = *(char **)(obj + 0x214);
    fp = *(int (**)())(vt + 0x44);
    fp(obj + *(short *)(vt + 0x40));
    m = n;
    dog->no = n;
    switch (m & 0xFF) {
    case 0:
    default:
        p = dog->obj;
        if (p != 0) {
            cOmBase_setTexChange(p, 1);
        }
        break;
    case 1:
        p = dog->obj;
        if (p != 0) {
            cOmBase_setTexChange(p, 2);
        }
        break;
    case 2:
        p = dog->obj;
        if (p != 0) {
            cOmBase_setTexChange(p, 3);
        }
        break;
    case 3:
        p = dog->obj;
        if (p != 0) {
            cOmBase_setTexChange(p, 0);
        }
        break;
    case 4:
        break;
    }
    dog->stats = *stats;
    r = frand(dog->stats.rateMin, dog->stats.rateMax);
    dog->speedRate = r;
    dog->stats.speed = dog->stats.speed * r;
    dog->stats.luck = dog->stats.luck * r;
    rem = (unsigned int)irand() % 100;
    if (dog->stats.burstChance >= rem) {
        dog->stats.unk14 = frand(-43.0f, -25.0f);
    }
    dog->raceTime = 11;
    dog->unk30 = 0;
    dog->power = (int)(dog->stats.speed * 100.0f)
               - dog->stats.grade * 10
               + (int)(dog->stats.stamina * 10.0f)
               + (int)(dog->stats.luck * 100.0f);
    return 1;
}
