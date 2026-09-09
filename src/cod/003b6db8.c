/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 matched TU. */

typedef struct _timer_alarm sceTimerAlarm;

struct _timer_alarm {
    sceTimerAlarm *next;      /* 0x00 */
    sceTimerAlarm *prev;      /* 0x04 */
    unsigned char  pad08[0x8];
    unsigned long  interval;  /* 0x10 */
    unsigned long  elapsed;   /* 0x18 */
    unsigned long  start;     /* 0x20 */
};

typedef struct _timer_ctl {
    unsigned long  ovf;       /* 0x00 */
    unsigned char  pad08[0x10];
    sceTimerAlarm *alarms;    /* 0x18 */
} sceTimerCtl;

extern sceTimerCtl D_003FBE90;

__attribute__((section(".text.func_003B6DB8")))
void func_003B6DB8(sceTimerAlarm *a)
{
    sceTimerAlarm *prev;
    sceTimerAlarm *cur;
    unsigned long t;

    t = (a->start + a->interval) - a->elapsed;
    prev = 0;
    cur = D_003FBE90.alarms;
    while (cur != 0) {
        if (t < (cur->start + cur->interval) - cur->elapsed) {
            break;
        }
        prev = cur;
        cur = prev->next;
    }
    a->prev = prev;
    a->next = cur;
    if (cur != 0) {
        cur->prev = a;
    }
    if (prev != 0) {
        prev->next = a;
    } else {
        D_003FBE90.alarms = a;
    }
}
