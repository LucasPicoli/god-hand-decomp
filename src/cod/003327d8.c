/* cygnus-2.96 matched TU. */

/* CRI MFCI (PS2EE Ver.1.15) file-system interface getter. */
extern const char *volatile D_003DECF8; /* "MFCI/PS2EE Ver.1.15 Build:..." banner pointer */
extern void *D_003DED08[];               /* MFCI function table */

/* Touches the build banner so the linker keeps it, then returns the MFCI function table. */
__attribute__((section(".text.func_00336318")))
void **func_00336318(void)
{
    (void)D_003DECF8;
    return D_003DED08;
}

/* CRI DVCI (PS2EE Ver.2.72) CD/DVD file-system interface getter. */
extern const char *volatile D_003D90D0; /* "DVCI/PS2EE Ver.2.72 Build:..." banner pointer */
extern void *D_003D90E8[];               /* DVCI function table */
extern void func_00333E88(char *dirname); /* DVCI: set the root directory */

/* Touches the build banner, resets the DVCI root directory, and returns the DVCI function table. */
__attribute__((section(".text.func_003327D8")))
void **func_003327D8(void)
{
    (void)D_003D90D0;
    func_00333E88(0);
    return D_003D90E8;
}
