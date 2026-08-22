/* cygnus-2.96 matched TU. */

extern int D_00766CE8[];
extern int D_0076A590[];

__attribute__((section(".text.func_00366918")))
int func_00366918(int a0,int a1,int a2,int a3){if((long)a0*(long)a3<=(long)a2*(long)a1)return 1;return 0;}

/* cygnus-2.96 */
__attribute__((section(".text.func_0036A3C0")))
void func_0036A3C0(char *p, int *a, int *b)
{
    char *q = p + 0x3EC;

    if (a != 0) {
        *a = *(int *)(q + 0x0);
    }
    if (b != 0) {
        *b = *(int *)(q + 0x8);
    }
}

__attribute__((section(".text.func_0036C038")))
void func_0036C038(void){int i;int n=D_00766CE8[0x15];char *p=(char*)D_00766CE8[0x16];for(i=0;i<n;i++){*(int*)(p+0x188)=1;p+=0x440;}}

__attribute__((section(".text.func_0036D238")))
void func_0036D238(void){int i;int n=D_0076A590[0x10];char *p=(char*)D_0076A590[0x11];for(i=0;i<n;i++){*(int*)(p+0x0)=1;p+=0x640;}}

/* cygnus-2.96 */
__attribute__((section(".text.func_0036DDD8")))
void func_0036DDD8(char *p, int *a, int *b)
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
__attribute__((section(".text.func_003766E0")))
int func_003766E0(char *p)
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

__attribute__((section(".text.func_003BA6C0")))
void func_003BA6C0(unsigned char *p,unsigned int len){unsigned int i;for(i=8;i<len;i+=2){unsigned char a=p[i];unsigned char b=p[i+1];p[i+1]=a;p[i]=b;}}
