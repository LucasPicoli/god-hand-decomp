/* cygnus-2.96 matched TU. */
#include "godhand/MpvHandle.h"

extern int D_00766CE8[];
extern int D_0076A590[];

__attribute__((section(".text.UTY_CmpTime")))
int UTY_CmpTime(int a0,int a1,int a2,int a3){if((long)a0*(long)a3<=(long)a2*(long)a1)return 1;return 0;}

/* cygnus-2.96 */
__attribute__((section(".text.MPV_GetPicUsr")))
void MPV_GetPicUsr(MpvHandle *hn, char **buf, int *len)
{
    MpvPicUsr *usr = &hn->usr;

    if (buf != 0) {
        *buf = usr->buf;
    }
    if (len != 0) {
        *len = usr->len;
    }
}

__attribute__((section(".text.mpvlib_InitObjTbl")))
void mpvlib_InitObjTbl(void){int i;int n=D_00766CE8[0x15];char *p=(char*)D_00766CE8[0x16];for(i=0;i<n;i++){*(int*)(p+0x188)=1;p+=0x440;}}

__attribute__((section(".text.m2vlib_InitObjTbl")))
void m2vlib_InitObjTbl(void){int i;int n=D_0076A590[0x10];char *p=(char*)D_0076A590[0x11];for(i=0;i<n;i++){*(int*)(p+0x0)=1;p+=0x640;}}

/* cygnus-2.96 */
__attribute__((section(".text.m2v_GetPicUsr")))
void m2v_GetPicUsr(char *p, int *a, int *b)
{
    char *q = p + 0x14C;

    if (a != 0) {
        *a = *(int *)(q + 0x0);
    }
    if (b != 0) {
        *b = *(int *)(q + 0x8);
    }
}

/* cygnus-2.96 */
__attribute__((section(".text.ssqPodLoopTop")))
int ssqPodLoopTop(char *p)
{
    int t = *(int *)(p + 0x30) + 0x10;

    *(int *)(p + 0x30) = t;
    *(int *)(p + 0x34) = t;
    return 1;
}

/* cygnus-2.96 */
__attribute__((section(".text.func_0037C5F8")))
void func_0037C5F8(char *p, char *q)
{
    *(unsigned short *)(p + 0x40) = *(unsigned short *)(q + 0x34);
    *(unsigned short *)(p + 0x42) = *(unsigned short *)(q + 0x36);
    *(unsigned short *)(p + 0x6) |= 0xA;
}

__attribute__((section(".text.func_003AE8C0")))
void func_003AE8C0(char *self, char *node) {
    int i;

    if (node != 0) {
        i = *(int *)(node + 0x4) << 2;
        *(int *)(node + 0x0) = *(int *)(i + *(int *)(self + 0x4C));
        *(int *)(i + *(int *)(self + 0x4C)) = (int)node;
    }
}

__attribute__((section(".text.ac3cnv_switch_endian")))
void ac3cnv_switch_endian(unsigned char *p,unsigned int len){unsigned int i;for(i=8;i<len;i+=2){unsigned char a=p[i];unsigned char b=p[i+1];p[i+1]=a;p[i]=b;}}
