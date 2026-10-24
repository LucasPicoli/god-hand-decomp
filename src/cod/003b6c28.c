/* ee-2.9-991111 TU. SetNextComp (libkernel timer): program the T2 compare register for the earliest pending alarm, or a short retry when it is already due. */
typedef unsigned int u_int;
typedef unsigned long u_long;

typedef struct Alarm {
    struct Alarm *next;           /* 0x00 */
    int f04;
    int f08;
    int f0C;
    u_long base_count;                  /* 0x10 */
    u_long base_time;                   /* 0x18 */
    u_long schedule;                    /* 0x20 */
} Alarm;

typedef struct AlarmCtl {
    char pad00[0x18];
    Alarm *head;                  /* 0x18 */
    int handling;                       /* 0x1C id of the alarm being handled, -1 = none */
} AlarmCtl;

extern AlarmCtl D_003FBE90;
extern void SetT2_B0001010_3B6A10(int mode);
extern void SetT2_B0001020_3B6A20(int comp);

#define T2_COUNT (*(volatile u_int *)0x10001000)
#define T2_MODE (*(volatile u_int *)0x10001010)

__attribute__((section(".text.SetNextComp")))
void SetNextComp(u_long now)
{
    Alarm *a;
    u_long t0;
    u_long t1;
    u_int mode;

    a = D_003FBE90.head;
    if (D_003FBE90.handling >= 0)
        return;
    mode = T2_MODE;
    if (a == 0) {
        SetT2_B0001020_3B6A20(0);
        SetT2_B0001010_3B6A10(mode & ~0x800);
        return;
    }
    t0 = a->schedule + a->base_count - a->base_time;
    for (a = a->next; a != 0; a = a->next) {
        t1 = a->schedule + a->base_count - a->base_time;
        if (t1 < t0 + 0x7333)
            t0 = t1;
        else
            break;
    }
    if ((long)(t0 - now) < 0x7333) {
        SetT2_B0001020_3B6A20(T2_COUNT + (int)(0x7333UL >> ((mode & 3) << 2)));
        SetT2_B0001010_3B6A10(mode & ~0x800);
        return;
    }
    SetT2_B0001010_3B6A10(mode & ~0x800);
    SetT2_B0001020_3B6A20((int)(t0 >> ((mode & 3) << 2)));
}
