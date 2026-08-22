/* sn-2.95.3-136 matched TU. */

extern char D_0076C8C0[];
extern char D_0076CF20[];

/* sn-2.95.3-136 */


__attribute__((section(".text.func_0037CEE0")))
char *func_0037CEE0(char *p)
{
    int e = *(signed char *)(p + 0x6) * 32 + (int)D_0076C8C0;

    if (*(unsigned short *)e != 0) {
        return 0;
    }
    return (char *)e;
}

__attribute__((section(".text.func_0037D060")))
void *func_0037D060(int a0){int i;char *p=D_0076C8C0;for(i=0;i<0x33;i++){if(*(unsigned short*)p!=0&&*(int*)(p+0x10)==a0)return p;p+=0x20;}return 0;}

__attribute__((section(".text.func_0037D100")))
void *func_0037D100(unsigned short a0){int i;char *p=D_0076C8C0;for(i=0;i<0x33;i++){if(*(unsigned short*)p!=0&&*(short*)(p+0x1A)==a0)return p;p+=0x20;}return 0;}

/* sn-2.95.3-136 */


__attribute__((section(".text.func_0037D388")))
char *func_0037D388(signed char i)
{
    int e = i * 0x50 + (int)D_0076CF20;

    if (*(unsigned short *)e != 0) {
        return 0;
    }
    return (char *)e;
}

__attribute__((section(".text.func_0037D728")))
void func_0037D728(char *p) {
    int s;
    int t;

    s = *(unsigned short *)(p + 0x46) + *(unsigned short *)(p + 0x48);
    *(unsigned short *)(p + 0x4A) = s;
    if ((*(unsigned char *)(p + 0x5) & 1) == 0) {
        t = *(unsigned short *)(p + 0x2E);
        *(unsigned short *)(p + 0x4A) = s + t;
    }
}

/* sn-2.95.3-136 */
__attribute__((section(".text.func_003970A0")))
unsigned int func_003970A0(unsigned int x)
{
    if ((x >> 28) == 7) {
        x &= 0xFFFFFFF;
        x |= 0x80000000;
    }
    return x;
}

__attribute__((section(".text.init__3iosP9streambufP7ostream")))
void init__3iosP9streambufP7ostream(char *t,int sb,int tie){if(sb==0)t[0x1A]=4;else t[0x1A]=0;*(int*)(t+0)=sb;*(int*)(t+4)=tie;*(short*)(t+0x18)=0x20;*(long*)(t+0x10)=0x11;*(int*)(t+0x1C)=6;t[0x1B]=0;*(int*)(t+8)=0;*(int*)(t+0x20)=0;}
