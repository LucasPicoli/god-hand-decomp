/* ee-2.9-991111 matched TU. */

extern struct AlarmS { struct AlarmS *next_00783C40; int pad[3]; } D_00783C40[64];
extern struct AlarmS *D_00784040;

__attribute__((section(".text._InitAlarm")))
int _InitAlarm(void) {
    int i;
    D_00784040 = D_00783C40;
    for (i = 63; i >= 0; i--) {
        D_00783C40[i].next_00783C40 = &D_00783C40[i + 1];
    }
    D_00783C40[63].next_00783C40 = 0;
    return 0;
}
