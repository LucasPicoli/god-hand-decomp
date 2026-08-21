/* sn-2.95.3-136 matched TU. */

extern int D_0044C238;
extern void func_002C2EB8(void *, void *);
extern void func_002C2EF8(void *, void *);
extern void func_003A6C58(void *, void *, ...);
extern int SearchCameraData(void *);

/* sn-2.95.3-136 matched TU. */









__attribute__((section(".text.func_002C2D20")))
void func_002C2D20(void *o) {
    char buf[16];
    char *p;

    p = (char *)func_002C30C0(o);
    while ((p = (char *)func_002C30C8(o, p)) != 0) {
        switch (*(unsigned char *)(p + 0x35)) {
        case 4: {
            unsigned int f = *(unsigned char *)(p + 0x3B);
            if (f & 8) {
                break;
            }
            *(unsigned char *)(p + 0x3B) = (f & 0x80) | 8;
            *(unsigned char *)(p + 0x3A) = 2;
            *(unsigned char *)(p + 0x39) = 1;
            if (*(unsigned short *)(p + 0x64) != 0) {
                func_003A6C58(buf, &D_0044C238, *(unsigned short *)(p + 0x64) - 1);
                *(int *)(p + 0x68) = SearchCameraData(buf);
            } else {
                *(int *)(p + 0x68) = 0;
            }
            break;
        }
        case 5:
            *(unsigned char *)(p + 0x3B) = 1;
            break;
        case 1: {
            unsigned int f = *(unsigned char *)(p + 0x3B);
            unsigned int g = *(unsigned char *)(p + 0x7A);
            if ((f & 8) == 0) {
                switch (g) {
                case 1:
                    break;
                case 0:
                default:
                    *(unsigned char *)(p + 0x3B) = (f & 0x80) | 8;
                    *(unsigned char *)(p + 0x3A) = 0x20;
                    *(unsigned char *)(p + 0x39) = 4;
                    goto next;
                }
            } else if (g != 1) {
                break;
            }
            *(unsigned char *)(p + 0x3B) = 0;
            *(unsigned char *)(p + 0x3A) = 0x31;
            *(unsigned char *)(p + 0x39) = 0;
            break;
        }
        case 9:
            func_002C2EB8(o, p);
            break;
        case 10: {
            unsigned int f = *(unsigned char *)(p + 0x3B);
            if (f & 8) {
                break;
            }
            *(unsigned char *)(p + 0x3B) = (f & 0x80) | 8;
            *(unsigned char *)(p + 0x3A) = 2;
            *(unsigned char *)(p + 0x39) = 4;
            break;
        }
        case 8:
            *(unsigned char *)(p + 0x3B) = 0x31;
            break;
        case 11:
            func_002C2EF8(o, p);
            break;
        }
    next:
        ;
    }
}
