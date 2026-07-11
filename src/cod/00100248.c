/* ee-2.9-991111 matched TU. */

extern void func_003B6820(void);
extern void func_00320280(void);
extern void func_003B1F28(char *fmt, ...);
extern char D_0045E630[];
extern void func_0039EC20(char *a0, unsigned int a1);
extern void func_0039C390(int a0, int a1);
extern char s__sequenceScalableExtension___is_n_0045e8b0[];
extern char s_Unknown_Extension_0045e8e0[];
extern char s__pictureSpatialScalableExtension_0045e8f8[];
extern char s__pictureTemporalScalableExtensio_0045e930[];
extern void func_003A0E20(char *a0, unsigned int a1);
extern void func_003B7C18(void);
extern void SetT2(unsigned int a0, void *a1);
extern void func_003224D0(void *a0, void *a1);
extern void *D_003FC9B4;
extern char D_007854B0[];

__attribute__((section(".text.func_00100248")))
void func_00100248(void) { func_003B6820(); }

__attribute__((section(".text.func_0031DE70")))
void func_0031DE70(void) { func_00320280(); }

__attribute__((section(".text.func_0039C218")))
void func_0039C218(void *a0) { func_003B1F28(D_0045E630, a0); }

__attribute__((section(".text.func_0039ECF0")))
void func_0039ECF0(char *a0, unsigned int a1) { func_0039EC20(a0, a1); }

__attribute__((section(".text.func_003A09F0")))
void func_003A09F0(int a0) { func_0039C390(a0, (int)s__sequenceScalableExtension___is_n_0045e8b0); }

__attribute__((section(".text.func_003A0A00")))
void func_003A0A00(int a0) { func_0039C390(a0, (int)s_Unknown_Extension_0045e8e0); }

__attribute__((section(".text.func_003A0BF8")))
void func_003A0BF8(int a0) { func_0039C390(a0, (int)s__pictureSpatialScalableExtension_0045e8f8); }

__attribute__((section(".text.func_003A0C08")))
void func_003A0C08(int a0) { func_0039C390(a0, (int)s__pictureTemporalScalableExtensio_0045e930); }

__attribute__((section(".text.func_003A0E20")))
void func_003A0E20(char *a0, unsigned int a1) { func_0039EC20(a0, a1); }

__attribute__((section(".text.func_003A0F80")))
void func_003A0F80(char *a0) { func_003A0E20(a0, 0x20); }

__attribute__((section(".text.func_003B6818")))
void func_003B6818(void) { func_003B7C18(); }

__attribute__((section(".text.func_003B6A00")))
void func_003B6A00(void *a0) { SetT2(0xB0001000, a0); }

__attribute__((section(".text.func_003B6A10")))
void func_003B6A10(void *a0) { SetT2(0xB0001010, a0); }

__attribute__((section(".text.func_003B6A20")))
void func_003B6A20(void *a0) { SetT2(0xB0001020, a0); }

__attribute__((section(".text.func_003BAFB8")))
void func_003BAFB8(void) { func_003224D0(&D_003FC9B4, D_007854B0); }
