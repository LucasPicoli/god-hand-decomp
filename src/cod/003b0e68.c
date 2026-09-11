/* ee-2.9-991111 matched TU. */

extern int iSignalSema(int semid);
extern void func_003B2B70(int a0);

/* ee-2.9-991111 */
#include "godhand/gp.h"

typedef struct client {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    int f14;
    void *f18;
    void (*f1C)(void *);
    void *f20;
    int f24;
} Client;

typedef struct pkt {
    char pad0[0x1C];
    Client *client;
    unsigned int cmd;
    int f24;
    int f28;
} Pkt;




__attribute__((section(".text._request_end")))
void _request_end(Pkt *pkt)
{
    Client *c;

    switch (pkt->cmd) {
    case 0x8000000A:
        c = pkt->client;
        if (c->f1C != 0) {
            void *oldgp = SetGp(c->f18);
            c->f1C(c->f20);
            SetGp(oldgp);
            c = pkt->client;
        }
        break;
    case 0x80000009:
        c = pkt->client;
        c->f24 = pkt->f24;
        c->f14 = pkt->f28;
        break;
    case 0x8000000B:
    default:
        c = pkt->client;
        break;
    }
    if (c->f8 >= 0)
        iSignalSema(c->f8);
    func_003B2B70(c->f0);
    c->f0 = 0;
}

/* ee-2.9-991111 */

typedef unsigned long long unsigned long long;
typedef long long long long;

__attribute__((section(".text.func_003B0E68")))
int func_003B0E68(unsigned long long d)
{
    long long e;

    e = (long long)((d << 1) >> 53);
    e = e - 0x433;
    if (e < -0x35)
        return 0;
    if (e >= 0xD)
        return 0x270F;
    d = (d << 12) >> 12;
    d = d | ((unsigned long long)0x8000 << 37);
    if (e < 0) {
        e = -e;
        d = d >> (e - 2);
        if ((d & 3) == 3)
            d = (d >> 2) + 1;
        else
            d = d >> 2;
    } else {
        d = d << e;
    }
    return (int)d;
}
