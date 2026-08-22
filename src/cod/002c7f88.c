/* sn-2.95.3-136 matched TU. */

extern unsigned char D_0061B289;
extern int D_003C118C;

__attribute__((section(".text.func_002C7F88")))
int func_002C7F88(unsigned char *p){unsigned int v;if(p==0)return 0;v=p[0]|(p[1]<<8)|(p[2]<<16)|(p[3]<<24);return (v^0x514553)==0;}

__attribute__((section(".text.func_002CD968")))
char *func_002CD968(char *a0, unsigned int key) {
    char *p = *(char **)(a0 + 0x380);

    while (p != 0) {
        if (*(unsigned int *)(p + 0xC) >= key) {
            return p;
        }
        p = *(char **)(p + 0x8);
    }
    return 0;
}

__attribute__((section(".text.func_002D22B0")))
void *func_002D22B0(int a0,int a1,int a2){int p=*(int*)(a0+0x18);while(p!=0){if(*(int*)(p+0x8C)-0x80==a1&&*(int*)(p+0x90)==a2)return (void*)p;p=*(int*)(p+0x88);}return 0;}

/* sn-2.95.3-136 */
__attribute__((section(".text.func_002D42B0")))
int func_002D42B0(char *p)
{
    if (*(int *)p == 0) {
        return 0;
    }
    return *(int *)(*(char **)(p + 0x8) + 0x24);
}

__attribute__((section(".text.func_002D65F8")))
void func_002D65F8(char *a0, float x, float y, float z, float w) {
    if (*(int *)(a0 + 0x4) != 0) {
        *(float *)(*(int *)(a0 + 0x4) + 0x70) = x;
        *(float *)(*(int *)(a0 + 0x4) + 0x74) = y;
        *(float *)(*(int *)(a0 + 0x4) + 0x78) = z;
        *(float *)(*(int *)(a0 + 0x4) + 0x7C) = w;
    }
}

__attribute__((section(".text.func_002D69A8")))
void func_002D69A8(int a0,unsigned short a1,float f12,float f13){int p=*(int*)(a0+4);if(p==0)return;*(int*)(a0+0x5C)=3;*(float*)(a0+0x64)=f12;*(float*)(a0+0x68)=f13;*(float*)(a0+0x6C)=*(float*)(p+0x44);*(float*)(a0+0x70)=*(float*)(p+0x44);*(short*)(a0+0x74)=a1;if(a1==0)*(short*)(a0+0x74)=1;*(short*)(a0+0x76)=0;}

/* sn-2.95.3-136 */
__attribute__((section(".text.func_002D9000")))
char *func_002D9000(char *p, int i)
{
    return p + (i * 0x70 + 0x80);
}

__attribute__((section(".text.func_002E0AE0")))
int func_002E0AE0(int x) {
    int m = D_0061B289;

    if (x < -m) {
        return 1;
    }
    return (D_003C118C * 2 + m) < x;
}

/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_002E16D8")))
int func_002E16D8(char *this) {
    char *p = *(char **)(this + 0x110);

    *(float *)(this + 0x2B0) = *(float *)(p + 0x13C);
    *(float *)(this + 0x2B4) = *(float *)(p + 0x140);
    *(float *)(this + 0x2B8) = *(float *)(p + 0x144);
    *(float *)(this + 0x2BC) = *(float *)(p + 0x148);
    *(int *)(this + 0x2C0) = *(int *)(p + 0x16C);
    return 1;
}
