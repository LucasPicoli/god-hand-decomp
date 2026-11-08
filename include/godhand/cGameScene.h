/* include/godhand/cGameScene.h - the scene's wall-check tables, as cGame's
 * per-frame step (func_002A6FF8) reads them.
 *
 * The record at 0x18C holds two tables: nodes, which name two points each,
 * and the points they refer to. One node is tested per step with a line
 * check between its two points, and its flag bit 31 records whether the line
 * is blocked. 0x1A8 is the cursor that walks the nodes.
 */
#ifndef GODHAND_CGAMESCENE_H
#define GODHAND_CGAMESCENE_H

#define SCENE_NODE_NONE   0xFFFF        /* a point index that is unset */
#define SCENE_NODE_BLOCKED 0x80000000u  /* SceneNode.flags: the line between its points is blocked */
#define SCENE_LINE_FLAGS  0x40          /* the fifth argument of the line test */
#define SCENE_STEPS       2             /* nodes tested per frame */
#define SCENE_PAUSE_FLAG  0x80000       /* D_00747A38: scene checks paused */

typedef struct ScenePoint {
    char unk00[0x20];
} ScenePoint;                           /* 0x20 */

typedef struct SceneNode {
    unsigned short pointA;              /* 0x0 index into the point table */
    unsigned short pointB;              /* 0x2 */
    char unk04[4];
    unsigned int flags;                 /* 0x8 */
} SceneNode;                            /* 0xC */

/* The same record seen from its own base: retail reads the node and point
 * tables through a pointer to 0x18C and the counts and cursor off the game. */
typedef struct SceneTables {
    int unk00;                          /* 0x00 */
    SceneNode *nodes;                   /* 0x04 */
    int nodeCount;                      /* 0x08 */
    ScenePoint *points;                 /* 0x0C */
} SceneTables;

typedef struct cGameScene {
    char unk000[0x18C];
    int unk18C;                         /* 0x18C start of the SceneTables view */
    SceneNode *nodes;                   /* 0x190 */
    int nodeCount;                      /* 0x194 */
    ScenePoint *points;                 /* 0x198 */
    int pointCount;                     /* 0x19C */
    char unk1A0[8];
    int cursor;                         /* 0x1A8 node tested next */
} cGameScene;

#define SCENE_TABLES(g) ((SceneTables *)&(g)->unk18C)

typedef char cGameScene_chk_cursor[(int)&((cGameScene *)0)->cursor == 0x1A8 ? 1 : -1];

#endif
