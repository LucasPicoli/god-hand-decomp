/* ee-2.9-991111 matched TU. */

/* ee-2.9-991111 matched TU. */

typedef struct _ee_sema {
    int            count;        /* 0x00 */
    int            max_count;    /* 0x04 */
    int            init_count;   /* 0x08 */
    int            wait_threads; /* 0x0C */
    unsigned int   attr;         /* 0x10 */
    unsigned int   option;       /* 0x14 */
} sceFsSemaParam;

extern int  D_003FAEE8;
extern int  D_003FAEEC;
extern unsigned char D_00460080;
extern unsigned char D_00460090;
extern int  CreateSema(sceFsSemaParam *sp);

__attribute__((section(".text.func_003B3858")))
void func_003B3858(void)
{
    sceFsSemaParam sp;

    if (D_003FAEE8 == -1) {
        sp.option = (unsigned int)&D_00460080;
        sp.init_count = 1;
        sp.max_count = 1;
        D_003FAEE8 = CreateSema(&sp);
        sp.option = (unsigned int)&D_00460090;
        D_003FAEEC = CreateSema(&sp);
    }
}
