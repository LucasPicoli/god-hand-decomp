/* include/godhand/drawPrim.h - the screen-space primitive drawers (sn code at 0x15B880..0x15F2D8). */
#ifndef GODHAND_DRAWPRIM_H
#define GODHAND_DRAWPRIM_H

/* Queue a four-vertex polygon packet; returns the packet, or 0 when the queue is full. */
extern void *Gp_draw_poly4(void *v, int color, int count, void *ctx, int a5, int a6);

/* Draw one flat quad from four screen-space vertices. */
extern void Draw_Poly_sc(void *v, int color);

/* A textured four-point polygon into the packet (assembly); returns the next packet position. */
void *Gp_draw_polyFT4(void *v, unsigned int col, int n, void *tex,
                      int t0, int t1, void *cfg, int t3, int extra);

#endif /* GODHAND_DRAWPRIM_H */
