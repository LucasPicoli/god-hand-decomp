/* sn-2.95.3-136 */
#include "godhand/mdlPkt.h"

#define DMA_ADDR(p)  ((unsigned long)((unsigned int)(p) & 0x0FFFFFFF) << 32)

/* Build the packet for record idx into packet buffer buf: a TEX0 set-up
 * (the record's texture, or one of two fixed TEX0 values when flag 0x800
 * or 0x8000 is set), the vertex body, and a closing tag that jumps back
 * to the fourth qword. Returns the qword after the packet. */
__attribute__((section(".text.func_00155678")))
PktQw *func_00155678(MdlObj *self, PktQw *q, int idx, int buf)
{
    PackRef r;
    PktQw *top;

    self->pkt[buf][idx] = q;
    q->s.lo = 0x10000002;
    q->s.w8 = 0x11000000;
    q->s.wC = 0x50000002;
    q[1].s.lo = 0x1000000000008001L;
    q[1].s.w8 = 0xE;
    q[1].s.wC = 0;
    r.base = self->pack;
    r.rec = (MdlRec *)(r.base->ofs[idx] + (int)r.base);
    q[2].ad.data = D_00747BB8[self->texBank + r.rec->texNo].q[0];
    q[2].ad.addr = 6;
    top = q;
    if (self->flags & 0x800) {
        q[2].ad.data = 0x620011400L;
    }
    if (self->flags & 0x8000) {
        q[2].ad.data = 0x2003B80665423B20L;
    }
    q += 4;
    top->s.lo = DMA_ADDR(q) | 0x20000002;
    q = func_00155800(self, q, idx, buf);
    q[-1].all = 0;
    q[-1].s.lo = DMA_ADDR(&top[3]) | 0x20000000;
    q[-1].s.w8 = 0;
    q[-1].s.wC = 0;
    return q;
}
