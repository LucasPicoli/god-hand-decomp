typedef struct SfdSync {
    char pad0[0xBB0];
    int audioPos;
    int videoPos;
} SfdSync;

typedef struct SfdSyncCond {
    int pad0;
    int sys;
    int video;
    int audio;
    char pad10[0x10];
    int usr;
} SfdSyncCond;

extern void Obj35C0_Set_a1_0_a2_C140(SfdSync *sfd, int a, int b);
extern void sftrn_BuildSystem(SfdSync *sfd, SfdSyncCond *c);
extern int sftrn_BuildVideo(SfdSync *sfd, SfdSyncCond *c);
extern void sftrn_BuildAudio(SfdSync *sfd, SfdSyncCond *c);
extern void sftrn_BuildUsr(SfdSync *sfd, SfdSyncCond *c);
extern void SFSET_SetCond(SfdSync *sfd, int tr, int v);

__attribute__((section(".text.sftrn_BuildAll")))
int sftrn_BuildAll(SfdSync *sfd, SfdSyncCond *c)
{
    if (c->sys != 0) {
        Obj35C0_Set_a1_0_a2_C140(sfd, 0, 0);
        sftrn_BuildSystem(sfd, c);
    } else if (c->video != 0) {
        Obj35C0_Set_a1_0_a2_C140(sfd, 0, 1);
        sftrn_BuildVideo(sfd, c);
        SFSET_SetCond(sfd, 6, 0);
        sfd->videoPos = 0;
    } else if (c->audio != 0) {
        Obj35C0_Set_a1_0_a2_C140(sfd, 0, 2);
        sftrn_BuildAudio(sfd, c);
        SFSET_SetCond(sfd, 5, 0);
        sfd->audioPos = 0;
    } else if (c->usr != 0) {
        Obj35C0_Set_a1_0_a2_C140(sfd, 0, 7);
        sftrn_BuildUsr(sfd, c);
        SFSET_SetCond(sfd, 6, 0);
        SFSET_SetCond(sfd, 5, 0);
        sfd->videoPos = 0;
        sfd->audioPos = 0;
    } else {
        return -1;
    }
    return 0;
}
