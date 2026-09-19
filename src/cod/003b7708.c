/* ee-2.9-991111 matched TU. */

typedef unsigned int u_int;
typedef unsigned short u_short;

typedef struct alarm {
    struct alarm *next;
    int f4;
    int (*fn)(int, int, void *, void *);
    void *arg;
} Alarm;

extern Alarm *volatile D_00784040;

__attribute__((section(".text.AlarmHandler")))
int AlarmHandler(int id, int time, void *common, Alarm *a)
{
    int r;

    r = a->fn((((u_int)a << 4) | (id & 0xFE)) | 1, time, common, a->arg);
    if (r == 0) {
        a->next = D_00784040;
        D_00784040 = a;
        a->f4 = 0;
        return -1;
    }
    return r;
}
