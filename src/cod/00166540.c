/* sn-2.95.3-136 matched TU. */

#include "godhand/cGameObj.h"
#include "godhand/cScenario.h"
#include "godhand/vu0.h"

extern void cHeap_free(int heap, int *block);
extern int cDvd_ReadAlloc(char *dvd, const char *name, void *outBuf, char *heap, int a4, int a5, int a6, int a7);
extern void cDvd_CheckWait(char *dvd, int id);
extern unsigned int D_00747A78;
extern char D_00463050[];
extern void sceVu0ApplyMatrix(void *out, void *mtx, void *vec);
extern void cCamManager_setSubScrCamera(void *cam, int mode);

/* A holder that keeps one file read in memory: the block at 0x298 and the disc job id at 0x29C. */
typedef struct FileHolder {
    char unk000[0x298];
    int *data;                          /* 0x298 loaded block, 0 when empty */
    int jobId;                          /* 0x29C disc job that filled it */
} FileHolder;

extern char D_00583F20[];               /* cDvd */
extern char D_00754230[];               /* heap the file is read into */




/* Frees the held block, reads the named file into it again and waits for the read. */
__attribute__((section(".text.FileHolder_reload")))
void FileHolder_reload(FileHolder *self, const char *name) {
    if (self->data != 0) {
        cHeap_free(self->data[-8], self->data);
    }
    self->jobId = cDvd_ReadAlloc(D_00583F20, name, &self->data, D_00754230, 0, 0, 0, 0);
    cDvd_CheckWait(D_00583F20, self->jobId);
}

/* A game object that keeps a "camera on" byte at 0x763. */
typedef struct cGameObjCam {
    cGameObj base;
    char unk5B0[0x763 - sizeof(cGameObj)];
    unsigned char camOn;                /* 0x763 */
} cGameObjCam;






#define SYSFLAG_CAMHOLD  0x10000        /* bit of D_00747A78 */

/* Starts the sub-screen camera: soft event on, then aims it at the object's lock-on point and a point 4 ahead of it, turned by the object's matrix. */
__attribute__((section(".text.cGameObjCam_startSubCamera")))
void cGameObjCam_startSubCamera(cGameObjCam *self)
{
    char buf[0x40] __attribute__((aligned(16)));
    float *v;
    float *d;
    float *mtx;
    cVec *cam;
    cVec *pos;

    if (self->camOn != 0) {
        cScenario_startSoftEvent(D_003C2F84, 0);
        D_00747A78 = D_00747A78 | SYSFLAG_CAMHOLD;
        {
            /* int-typed reads: a pointer-typed vt load would cross the D_00747A78 store */
            int vt = *(int *)((char *)self + 0x214);
            pos = ((cVec *(*)(void *))*(int *)(vt + 0x84))((char *)self + *(short *)(vt + 0x80));
        }
        VU0_LQC2(4, pos, 0x0);
        VU0_SQC2(4, buf, 0x0);
        v = (float *)(buf + 0x10);
        v[0] = 1.0f;
        v[2] = 4.0f;
        v[1] = 1.0f;
        v[3] = 1.0f;
        mtx = self->base.mtx;
        d = (float *)(buf + 0x30);
        VU0_LQC2(4, v, 0x0);
        VU0_SQC2(4, buf, 0x30);
        sceVu0ApplyMatrix(d, mtx, d);
        VU0_LQC2(4, d, 0x0);
        VU0_SQC2(4, buf, 0x20);
        {
            float x = *(float *)(buf + 0x20);
            float y = *(float *)(buf + 0x24);
            float z = *(float *)(buf + 0x28);

            *(float *)(buf + 0x10) = x;
            *(float *)(buf + 0x14) = y;
            *(float *)(buf + 0x18) = z;
        }
        cCamManager_setSubScrCamera(D_00463050, 0);
        cVec_copy3((cVec *)(D_00463050 + 0xE90), (cVec *)buf);
        cVec_copy3((cVec *)(D_00463050 + 0xEA0), (cVec *)(buf + 0x10));
    }
}
