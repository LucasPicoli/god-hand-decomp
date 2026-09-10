/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 */

typedef struct { unsigned char cmd; unsigned char arg; } Ent;
typedef struct { int idx; int pad; Ent ent[512]; } Ring;

extern int WaitSema(int id);
extern int WakeupThread(int id);
extern int RotateThreadReadyQueue(int id);
extern int SuspendThread(int id);
extern void func_003B1FA8(char *msg);
extern int D_0077DF90;
extern char D_0045FDFF[];

__attribute__((section(".text.topThread")))
void topThread(Ring *r)
{
    int i;

    for (;;) {
        WaitSema(D_0077DF90);
        i = r->idx & 0x1FF;
        r->idx = i + 1;
        switch (r->ent[i].cmd) {
        case 0:
            WakeupThread(r->ent[i].arg);
            break;
        case 1:
            RotateThreadReadyQueue(r->ent[i].arg);
            break;
        case 2:
            SuspendThread(r->ent[i].arg);
            break;
        default:
            func_003B1FA8(D_0045FDFF + 1);
            break;
        }
    }
}
