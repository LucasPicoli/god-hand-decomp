#include "godhand/cObj.h"
/* sn-2.95.3-136 matched TU. */

__attribute__((section(".text.func_00173E60")))
void func_00173E60(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0x654) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0x654) - 1;
    *(short *)((char *)p + 0x654) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_00174C28")))
void func_00174C28(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0x654) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0x654) - 1;
    *(short *)((char *)p + 0x654) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_00175ED8")))
void func_00175ED8(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0xD34) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0xD34) - 1;
    *(short *)((char *)p + 0xD34) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_00177560")))
void func_00177560(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0xD34) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0xD34) - 1;
    *(short *)((char *)p + 0xD34) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_0017A180")))
void func_0017A180(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0x654) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0x654) - 1;
    *(short *)((char *)p + 0x654) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_0017CA90")))
void func_0017CA90(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0x654) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0x654) - 1;
    *(short *)((char *)p + 0x654) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_00181C98")))
void func_00181C98(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0x654) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0x654) - 1;
    *(short *)((char *)p + 0x654) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_00186E08")))
void func_00186E08(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0x654) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0x654) - 1;
    *(short *)((char *)p + 0x654) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_00188190")))
void func_00188190(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0x600) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0x600) - 1;
    *(short *)((char *)p + 0x600) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_001897B8")))
void func_001897B8(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0xCD0) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0xCD0) - 1;
    *(short *)((char *)p + 0xCD0) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_0018AA00")))
void func_0018AA00(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0x604) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0x604) - 1;
    *(short *)((char *)p + 0x604) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_0018B718")))
void func_0018B718(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0x654) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0x654) - 1;
    *(short *)((char *)p + 0x654) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_0018C520")))
void func_0018C520(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0x654) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0x654) - 1;
    *(short *)((char *)p + 0x654) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_0018D310")))
void func_0018D310(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0x654) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0x654) - 1;
    *(short *)((char *)p + 0x654) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_0018E0C8")))
void func_0018E0C8(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0x654) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0x654) - 1;
    *(short *)((char *)p + 0x654) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_00190CC8")))
void func_00190CC8(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0xF84) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0xF84) - 1;
    *(short *)((char *)p + 0xF84) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_001926A0")))
void func_001926A0(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0x600) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0x600) - 1;
    *(short *)((char *)p + 0x600) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_00196978")))
void func_00196978(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0x9D4) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0x9D4) - 1;
    *(short *)((char *)p + 0x9D4) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_00197FA0")))
void func_00197FA0(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0x9D4) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0x9D4) - 1;
    *(short *)((char *)p + 0x9D4) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_00199440")))
void func_00199440(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0x654) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0x654) - 1;
    *(short *)((char *)p + 0x654) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_0019C9F8")))
void func_0019C9F8(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0x654) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0x654) - 1;
    *(short *)((char *)p + 0x654) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_0019F528")))
void func_0019F528(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0x654) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0x654) - 1;
    *(short *)((char *)p + 0x654) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_001A1768")))
void func_001A1768(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0xD94) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0xD94) - 1;
    *(short *)((char *)p + 0xD94) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_001A2E28")))
void func_001A2E28(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0xD98) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0xD98) - 1;
    *(short *)((char *)p + 0xD98) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}

__attribute__((section(".text.func_001BC6E8")))
void func_001BC6E8(cObj *p)
{
    unsigned char c;
    int t;
    c = p->phase;
    if (c == 0) goto init;
    if (c == 1) goto tick;
    return;
init:
    *(short *)((char *)p + 0x62C) = 0xF;
    p->phase = 1;
    p->step = 0;
    p->stepArg = 0;
tick:
    t = *(unsigned short *)((char *)p + 0x62C) - 1;
    *(short *)((char *)p + 0x62C) = t;
    if ((short)t > 0) return;
    p->mode = 0;
    p->phase = 0;
    p->step = 0;
    p->stepArg = 0;
}
