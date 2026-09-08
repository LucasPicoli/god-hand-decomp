/* ee-2.9-991111 matched TU. */

typedef unsigned int  u_int;
typedef unsigned long u_long;

__attribute__((section(".text.TimerBusClock2USec")))
void TimerBusClock2USec(u_long clock, u_int *sec, u_int *usec)
{
    u_int s;

    s = clock / 147456000;
    if (sec != 0) {
        *sec = s;
    }
    if (usec != 0) {
        *usec = (clock - (u_long)s * 147456000) * 1000000 / 147456000;
    }
}
