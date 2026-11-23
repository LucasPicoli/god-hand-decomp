/* cygnus-2.96 matched TU. */
#include "godhand/sftim.h"

extern int D_003EE2C4[];

/* cygnus-2.96 */
__attribute__((section(".text.sfbuf_InitBufData")))
void sfbuf_InitBufData(char *p, int a, int b)
{
    *(int *)(p + 0x0) = a;
    *(int *)(p + 0x4) = b;
    *(int *)(p + 0x8) = 0;
    *(int *)(p + 0xC) = 0;
    *(int *)(p + 0x4C) = 9;
    *(int *)(p + 0x50) = 9;
}

__attribute__((section(".text.SFBUF_AddRtotSj")))
void SFBUF_AddRtotSj(SftimHn *hn, int ch, int n) {
    SfdBufCh *buf = &hn->track[ch].buf;
    int v = buf->rtotSj;

    if (v >= 0) {
        buf->rtotSj = v + n;
    }
}

__attribute__((section(".text.sfmps_IsZero")))
int sfmps_IsZero(unsigned char *p,int n){int i;for(i=0;i<n;i++){if(*p++!=0)return 0;}return 1;}

__attribute__((section(".text.SFMPVF_SearchFrmObjFromId")))
void *SFMPVF_SearchFrmObjFromId(int a0,int a1){int i;char *p=(char*)(*(int*)(a0+0x1FC0)+0x180);for(i=0;i<0x10;i++){if(*(int*)(p+0x58)==a1)return p;p+=0xF0;}return 0;}

/* cygnus-2.96 */
__attribute__((section(".text.SFMPVF_StbyFrm")))
void SFMPVF_StbyFrm(int *p)
{
    if (p) {
        *p = 2;
    }
}

/* cygnus-2.96 */
__attribute__((section(".text.SFMPVF_RefStbyFrm")))
void SFMPVF_RefStbyFrm(int *p)
{
    if (p) {
        *p = 4;
    }
}

/* cygnus-2.96 */
__attribute__((section(".text.sfmpvf_IsChkFirst")))
int sfmpvf_IsChkFirst(char *a, char *b)
{
    if (a == 0) {
        return 1;
    }
    return *(int *)(a + 0x38) > *(int *)(b + 0x38);
}

__attribute__((section(".text.SFMPVF_IssueFrmId")))
int SFMPVF_IssueFrmId(char *self)
{
    int old = *(int *)(self + 0x5C);
    int next = old + 1;
    if (next < 0) {
        next = 0;
    }
    *(int *)(self + 0x5C) = next;
    return old;
}

__attribute__((section(".text.sfply_StatStop")))
int sfply_StatStop(char *p) {
    int v = *(int *)(p + 0x4C);
    int r = *(int *)(p + 0x48);
    switch (v) {
    case 2:
    case 3:
    case 4:
    case 6:
        r = 2;
        break;
    }
    return r;
}

__attribute__((section(".text.sfply_SearchFreeHn")))
int sfply_SearchFreeHn(void){int i;for(i=0;i<8;i++){if(D_003EE2C4[i]==0)return i;}return -1;}

__attribute__((section(".text.SFPTS_IsPtsQueFull")))
int SFPTS_IsPtsQueFull(int a0,int a1){int p=a0+a1*0x74+0x1348;if(*(int*)p==0)return 0;return *(int*)(p+8)>=*(int*)(p+4);}

__attribute__((section(".text.SFX_GetTagInf")))
void SFX_GetTagInf(char *base, int *o1, int *o2) {
    int *p = (int *)(base + 0x14);
    if (p[0] == 1) {
        int u = p[1];
        *o2 = p[2];
        *o1 = u;
    } else {
        *o1 = 0;
        *o2 = 0;
    }
}

/* cygnus-2.96 */
__attribute__((section(".text.func_0035FE20")))
void func_0035FE20(char *p, int n, int k)
{
    *(int *)(p + 0x8) = *(int *)(p + 0x8) - n;
    *(int *)(p + 0x0) = *(int *)(p + 0x0) + n * *(int *)(p + 0x4) + k;
}
