/* cygnus-2.96 matched TU. */

extern unsigned char D_0058503A;
extern int D_005E8600;
extern char *D_005FEE18;
extern int D_005FEE1C;

/* cygnus-2.96 | drop-freorder-blocks */
__attribute__((section(".text.cOmDoor_setLock")))
void cOmDoor_setLock(char *p, int on)
{
    if (on == 1) {
        *(int *)(p + 0x620) |= 2;
    } else {
        *(int *)(p + 0x620) &= ~2;
    }
}

/* cygnus-2.96 | drop-freorder-blocks */
__attribute__((section(".text.func_00201788")))
int func_00201788(char *p)
{
    int n = *(int *)(p + 0x1104) + 1;

    *(int *)(p + 0x1104) = n;
    if (n == 0) {
        *(int *)(p + 0x1104) = 1;
    }
    return *(int *)(p + 0x1104);
}

/* cygnus-2.96 | drop-freorder-blocks */


__attribute__((section(".text.func_00201F20")))
void func_00201F20(int a, int b)
{
    if (b == 0xFFFF) {
        if (a != 0) {
            D_0058503A = 0xF;
        }
    }
}

/* cygnus-2.96 | drop-freorder-blocks */
__attribute__((section(".text.func_002896B0")))
void func_002896B0(char *p)
{
    if (*(unsigned char *)(p + 0x2F4) == 0) {
        if (*(unsigned char *)(p + 0x2F5) == 8) {
            *(unsigned char *)(p + 0x2F6) = 2;
        }
    }
}

__attribute__((section(".text.func_00290048")))
void func_00290048(int a0,int a1,int a2){if(a1==0)return;if(a2<-1)return;if(*(int*)(a0+8)!=0)return;if(*(int*)(a0+0xC)!=-1)return;if(*(unsigned char*)(a0+0x10)==1)return;*(int*)(a0+8)=a1;*(int*)(a0+0xC)=a2;*(unsigned char*)(a0+0x10)=1;}

/* cygnus-2.96 | drop-freorder-blocks */
__attribute__((section(".text.func_002B45B0")))
void func_002B45B0(char *p)
{
    if (*(int *)(p + 0xB8) == 1) {
        *(int *)(p + 0xB8) = 0;
    }
}

/* cygnus-2.96 | drop-freorder-blocks */
__attribute__((section(".text.func_002B4F78")))
int func_002B4F78(char *p)
{
    int n = *(int *)(p + 0x10) + 1;

    *(int *)(p + 0x10) = n;
    if (n == 0) {
        *(int *)(p + 0x10) = 1;
    }
    return *(int *)(p + 0x10);
}

/* cygnus-2.96 | drop-freorder-blocks */


__attribute__((section(".text.func_002BE510")))
void func_002BE510(int a, int b)
{
    if (b == 0xFFFF) {
        if (a != 0) {
            D_005E8600 = 0;
        }
    }
}

__attribute__((section(".text.func_002CC5E8")))
void func_002CC5E8(char *p) {
    char *prev = *(char **)(p + 0x84);
    char *next;

    if (prev != 0) {
        *(char **)(prev + 0x88) = *(char **)(p + 0x88);
    } else {
        D_005FEE18 = *(char **)(p + 0x88);
    }
    next = *(char **)(p + 0x88);
    if (next != 0) {
        *(char **)(next + 0x84) = *(char **)(p + 0x84);
    }
    *(int *)(p + 0x94) = 0;
}

__attribute__((section(".text.func_002CE3E8")))
void func_002CE3E8(int a0){if(*(int*)(a0)!=0)*(int*)(*(int*)(a0)+4)=*(int*)(a0+4);else D_005FEE1C=*(int*)(a0+4);if(*(int*)(a0+4)!=0)*(int*)(*(int*)(a0+4))=*(int*)(a0);*(int*)(a0+0x38)=0;*(int*)(a0+0x3C)=0;*(int*)(a0+0x14)=0;}

/* cygnus-2.96 | drop-freorder-blocks */
__attribute__((section(".text.func_002D3190")))
int func_002D3190(char *p)
{
    int n = *(int *)(p + 0xC40) + 1;

    *(int *)(p + 0xC40) = n;
    if (n == 0) {
        *(int *)(p + 0xC40) = 1;
    }
    return *(int *)(p + 0xC40);
}

__attribute__((section(".text.func_002D3240")))
void func_002D3240(char *p, int a1, int a2, int a3, int t0, int t1) {
    *(int *)(p + 0x8) = a2;
    *(int *)(p + 0x0) = 1;
    *(int *)(p + 0x4) = a1;
    if (a1 == 0) {
        *(int *)(p + 0xC) = a3;
        *(int *)(p + 0x6C) = 0;
    } else {
        *(int *)(p + 0x6C) = a3;
        *(int *)(p + 0xC) = 0;
    }
    *(int *)(p + 0x80) = t1;
    *(int *)(p + 0x74) = t0;
    *(int *)(p + 0x70) = 0;
}
