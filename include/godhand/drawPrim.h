/* include/godhand/drawPrim.h - the screen-space primitive drawers (sn code at 0x15B880..0x15F2D8). */
#ifndef GODHAND_DRAWPRIM_H
#define GODHAND_DRAWPRIM_H

/* Queue a four-vertex polygon packet; returns the packet, or 0 when the queue is full. */
extern void *Gp_draw_poly4(void *v, int color, int count, void *ctx, int a5, int a6);

/* Draw a line strip through n world-space points (cVec) in one colour. */
extern void Draw_Line2(void *pts, int n, unsigned int color, int flag);

/* Draw one flat quad from four screen-space vertices. */
extern void Draw_Poly_sc(void *v, int color);

#endif /* GODHAND_DRAWPRIM_H */
