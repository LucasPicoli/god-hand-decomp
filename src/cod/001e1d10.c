/* func_001E1D10: table lookup of 3-slot equip combo into f494 (sn-2.95.3-136) */
typedef struct {
    int a;
    int b;
    int c;
} EquipCombo;

typedef struct {
    EquipCombo e[9];
} EquipComboTbl;

typedef struct {
    char pad0[4];
    int f4;
    int f8;
    int fC;
    char pad10[0x100 - 0x10];
    int a[3];
    char pad10C[0x208 - 0x10C];
    int b[3];
    char pad214[0x310 - 0x214];
    int c[3];
    char pad31C[0x48E - 0x31C];
    unsigned short kind;
    char pad490[4];
    int f494;
} EquipWork;

extern EquipComboTbl D_0042B758;

__attribute__((section(".text.func_001E1D10")))
void func_001E1D10(EquipWork *o)
{
    EquipComboTbl t;
    int i;

    t = D_0042B758;
    switch (o->kind) {
    case 3:
        for (i = 0; i < 9; i++) {
            if (o->a[0] == t.e[i].a && o->b[1] == t.e[i].b && o->c[2] == t.e[i].c) {
                o->f8 = i + 1;
                o->fC = 0;
                o->f494 = 3;
                o->f4 = 3;
                return;
            }
        }
        for (i = 0; i < 9; i++) {
            if (o->a[2] == t.e[i].a && o->b[1] == t.e[i].b && o->c[0] == t.e[i].c) {
                o->f494 = 4;
                o->f4 = 3;
                o->f8 = i + 1;
                o->fC = 0;
                return;
            }
        }
    case 2:
        for (i = 0; i < 9; i++) {
            if (o->a[0] == t.e[i].a && o->b[0] == t.e[i].b && o->c[0] == t.e[i].c) {
                o->f8 = i + 1;
                o->fC = 0;
                o->f494 = 0;
                o->f4 = 3;
                return;
            }
        }
        for (i = 0; i < 9; i++) {
            if (o->a[2] == t.e[i].a && o->b[2] == t.e[i].b && o->c[2] == t.e[i].c) {
                o->f494 = 2;
                o->f4 = 3;
                o->f8 = i + 1;
                o->fC = 0;
                return;
            }
        }
    case 1:
        for (i = 0; i < 9; i++) {
            if (o->a[1] == t.e[i].a && o->b[1] == t.e[i].b && o->c[1] == t.e[i].c) {
                o->f494 = 1;
                o->f4 = 3;
                o->f8 = i + 1;
                o->fC = 0;
                return;
            }
        }
    }
    o->f494 = -1;
    o->f4 = 3;
    o->f8 = 10;
    o->fC = 0;
}
