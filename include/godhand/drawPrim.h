/* include/godhand/drawPrim.h - the screen-space primitive drawers (sn code at 0x15B880..0x15F2D8). */
#ifndef GODHAND_DRAWPRIM_H
#define GODHAND_DRAWPRIM_H

struct cScrVtx;
struct cScrTexCfg;

/* Queue a four-vertex polygon packet; returns the packet, or 0 when the queue is full. */
extern void *Gp_draw_poly4(void *v, int color, int count, void *ctx, int a5, int a6);

/* Queue a textured quad over the two corners v[0] and v[1] from the texture image tex,
 * with the UV rectangle in cfg; returns the packet, or 0 when the queue is full.
 * cScrSpriteDraw_drawTex passes D_003C11B0 as drawMode and its own colorNo and fontNo. */
void *func_0015D168(struct cScrVtx *v, unsigned int color, int arg2, void *tex, int drawMode, int arg5,
                    struct cScrTexCfg *cfg, int colorNo, int fontNo);

/* Queue a flat sprite over the corners v[0] and v[1] in the packed colour color,
 * with cfg's texel window and TEST value when cfg asks for them; kind and prio
 * say where it is queued. Returns the packet, or 0 when the buffer is full.
 * tex is not read. */
void *func_0015DB30(struct cScrVtx *v, unsigned int color, void *tex, struct cScrTexCfg *cfg, int kind, int prio);

/* The line drawing attributes Gp_draw_line reads: flags and a TEST register value. */
typedef struct LineAttr {
    int flags;                          /* 0x00 LINE_ATTR_* */
    int pad04[11];
    long test;                          /* 0x30 TEST_1 value, used with LINE_ATTR_TEST */
    long pad38[3];
} LineAttr;                             /* 0x50 */

#define LINE_ATTR_TEST  0x20            /* the packet's TEST_1 is attr->test, not ZTST GEQUAL */

/* Queue the line from pts[0] to pts[1]; returns the packet, or 0 when the queue is full.
 * screen: nonzero when the points are already screen coordinates; 0 projects them
 * through the matrix at D_005CAFF0. list and pos say where func_0031A600 queues the
 * packet in D_00754C80. For list kinds 4 and 8 pos is used as given; for any other
 * kind it comes from the line's depth. */
extern void *Gp_draw_line(float (*pts)[4], unsigned int color, int screen, int list, int pos, LineAttr *attr);

/* Draw a screen-space polyline of count + 1 points; with depthTest 0 it draws over
 * everything (ZTST ALWAYS). */
void Draw_Line_sc(float (*pts)[4], unsigned int count, unsigned int color, int depthTest);

/* Draw a line strip through n world-space points (cVec) in one colour. */
extern void Draw_Line2(void *pts, int n, unsigned int color, int flag);

/* Draw one flat quad from four screen-space vertices. */
extern void Draw_Poly_sc(void *v, int color);

/* A textured four-point polygon into the packet (assembly); returns the next packet position. */
void *Gp_draw_polyFT4(void *v, unsigned int col, int n, void *tex,
                      int t0, int t1, void *cfg, int t3, int extra);

#endif /* GODHAND_DRAWPRIM_H */
