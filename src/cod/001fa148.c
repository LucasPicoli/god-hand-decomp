/* sn-2.95.3-136 matched TU. */

extern unsigned short D_003BF178[];

typedef struct GameLevelObj {
    char pad[0x1C];
    unsigned short f1c;
    char f1e;
} GameLevelObj;

__attribute__((section(".text.cCoreSave_setGameLevel")))
void cCoreSave_setGameLevel(GameLevelObj **arg0, int arg1) {
    GameLevelObj *p = *arg0;
    int lvl = arg1;

    if (p != 0) {
        arg1 = 2;
        lvl = lvl - 1;
        if (lvl < 0) {
            lvl = 0;
        }
        if (lvl >= 5) {
            lvl = 4;
        }
        p->f1c = D_003BF178[lvl * 2];
        (*arg0)->f1e = arg1;
    }
}
