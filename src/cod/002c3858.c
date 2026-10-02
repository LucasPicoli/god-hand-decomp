/* SN ProDG ee-gcc 2.95.3 matched TU. */
#include "godhand/cScenario.h"

extern void func_002D56A8(cTaskManager *task);
extern void SetFieldsCESignalSemaSleep_2D5AA0(cTaskWork *work, int a1);
extern unsigned int D_00747A78;
extern char D_00463050[];
extern void cCamManager_setMotCamera(void *a0, int a1);
extern void cMotCamera_setMotion(void *a0, int a1, int a2, int a3, float f12, int t0, int t1);
extern void cCamera_move(void *a0);
extern void cPlCamera_setCamUpdate(void *a0, int a1);
extern void cCamManager_setPlCamera(void *a0, int a1);
extern void ClearField15F4Bit1_124F60(int a0, int a1, int a2);
extern int D_003C23A4;
extern void cMessage_deleteMessNo(int a0, int a1);
extern void setPlayerPos(void *p, float w);
extern int SearchCameraData(const char *name);

__attribute__((section(".text.cScenario_release")))
/* Run both exit callbacks, then release the task pool. */
void cScenario_release(cScenario *self) {
    cScenario_runExitFunc(self);
    cScenario_runRoomExitFunc(self);
    func_002D56A8(&self->task);
}

__attribute__((section(".text.cScenario_startCamMotion")))
/* Play camera data on the motion camera. 0 when there is no data. */
int cScenario_startCamMotion(cScenario *self, int camData) {
    char *s0;
    if (camData == 0) {
        return 0;
    }
    D_00747A78 = D_00747A78 | 0x200000;
    s0 = D_00463050;
    cCamManager_setMotCamera(s0, 0);
    s0 = D_00463050 + 0x530;
    cMotCamera_setMotion(s0, camData, 0, 0, 0.0f, 0, 0);
    *(float *)(s0 + 0x3A8) = 0.0f;
    cCamera_move(s0);
    self->camOn = 1;
    return 1;
}

__attribute__((section(".text.cScenario_resetCam")))
/* Give the camera back to the player. */
void cScenario_resetCam(cScenario *self) {
    char *s0;
    D_00747A78 = D_00747A78 & 0xFFDFFFFF;
    s0 = D_00463050;
    if (s0) {
        cPlCamera_setCamUpdate(s0, 0);
    }
    cCamManager_setPlCamera(s0, 0);
    ClearField15F4Bit1_124F60(Obj0000_Get_D_00747A94_2DB6B0(), 0, 1);
    self->camOn = 0;
}

__attribute__((section(".text.cScenario_waitCam")))
/* Sleep the script task until the camera move is over. */
void cScenario_waitCam(cScenario *self) {
    while (cScenario_isCamEnd(self) == 0) {
        SetFieldsCESignalSemaSleep_2D5AA0(D_003C2F84->task.cur, 1);
    }
}

__attribute__((section(".text.cScenario_execUpCut")))
/* Play close-up cut `no` with the named camera, or with none. */
void cScenario_execUpCut(cScenario *self, unsigned short no, const char *camName, int asTask,
                         unsigned char arg, int slot) {
    int camData;
    if (camName != 0) {
        camData = SearchCameraData(camName);
    } else {
        camData = 0;
    }
    cScenario_execUpCutData(self, no, camData, asTask, arg, slot);
}

__attribute__((section(".text.cScenario_setMess")))
/* Put message `mess` up, closing the one already shown. */
void cScenario_setMess(cScenario *self, unsigned int mess) {
    if (self->messNo != SCENARIO_NO_MESS) {
        cScenario_endMess(self);
    }
    if (cMessage_create(D_003C23A4, mess, 0, 0, 0) != 0xFFFF) {
        self->messNo = mess;
    }
}

__attribute__((section(".text.cScenario_endMess")))
/* Close the message this scenario put up, if any. */
void cScenario_endMess(cScenario *self) {
    if (self->messNo != SCENARIO_NO_MESS) {
        cMessage_deleteMessNo(D_003C23A4, self->messNo);
        self->messNo = SCENARIO_NO_MESS;
    }
}

__attribute__((section(".text.cScenario_moveObjPos")))
/* Place a game object at (x, y, z) facing `angle`; the player goes
 * through setPlayerPos. */
void cScenario_moveObjPos(cScenario *self, char *gameObj, float x, float y, float z, float angle) {
    typedef struct { float a, b, c, d; } Vec4;
    char *obj = gameObj;
    Vec4 s1;
    if ((*(unsigned short*)(obj + 0x2FE) ^ 0x100) != 0) {
        char *vt;
        s1.d = 1.0f;
        vt = *(char**)(obj + 0x214);
        s1.a = x; s1.b = y; s1.c = z;
        (*(void(**)(char*, Vec4*))(vt + 0x74))(obj + *(short*)(vt + 0x70), &s1);
        {
            Vec4 s2;
            Vec4 *q = &s2;
            char *vt2 = *(char**)(obj + 0x214);
            void (*fp2)(char*, Vec4*);
            char *arg2;
            arg2 = obj + *(short*)(vt2 + 0x78);
            s2.b = angle;
            s2.a = 0;
            s2.c = 0;
            q->d = 1.0f;
            fp2 = *(void(**)(char*, Vec4*))(vt2 + 0x7C);
            fp2(arg2, q);
        }
    } else {
        s1.a = x; s1.b = y; s1.c = z; s1.d = 1.0f;
        setPlayerPos(&s1, angle);
    }
}

__attribute__((section(".text.cScenario_waitMess")))
/* Sleep the script task while the message is up, then close it. */
void cScenario_waitMess(cScenario *self) {
    while (cScenario_isMessOn(self) == 1) {
        SetFieldsCESignalSemaSleep_2D5AA0(D_003C2F84->task.cur, 1);
    }
    cScenario_endMess(self);
}
