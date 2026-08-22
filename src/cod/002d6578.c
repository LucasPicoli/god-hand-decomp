/* cygnus-2.96 matched TU. */

/* cygnus-2.96 | fp_hazard_rules mtc1 */
__attribute__((section(".text.CustomIDWork_SetLocalPosX")))
void CustomIDWork_SetLocalPosX(char *p, int v)
{
    char *q = *(char **)(p + 0x4);

    if (q != 0) {
        *(int *)(p + 0x8) = 0;
        *(float *)(q + 0x38) = (float)v;
    }
}

/* cygnus-2.96 | fp_hazard_rules mtc1 */
__attribute__((section(".text.CustomIDWork_SetLocalPosY")))
void CustomIDWork_SetLocalPosY(char *p, int v)
{
    char *q = *(char **)(p + 0x4);

    if (q != 0) {
        *(int *)(p + 0x8) = 0;
        *(float *)(q + 0x3C) = (float)v;
    }
}

/* cygnus-2.96 | fp_hazard_rules mtc1 */
__attribute__((section(".text.CustomIDWork_SetOffsetPosX")))
void CustomIDWork_SetOffsetPosX(char *p, int v)
{
    char *q = *(char **)(p + 0x4);

    if (q != 0) {
        *(int *)(p + 0x28) = 0;
        *(float *)(q + 0x30) = (float)v;
    }
}

/* cygnus-2.96 | fp_hazard_rules mtc1 */
__attribute__((section(".text.CustomIDWork_SetOffsetPosY")))
void CustomIDWork_SetOffsetPosY(char *p, int v)
{
    char *q = *(char **)(p + 0x4);

    if (q != 0) {
        *(int *)(p + 0x28) = 0;
        *(float *)(q + 0x34) = (float)v;
    }
}

/* cygnus-2.96 | fp_hazard_rules mtc1 */
__attribute__((section(".text.func_002D6578")))
void func_002D6578(char *p, int v)
{
    char *q = *(char **)(p + 0x4);

    if (q != 0) {
        *(float *)(q + 0x68) = (float)v;
    }
}

/* cygnus-2.96 | fp_hazard_rules mtc1 */
__attribute__((section(".text.func_002D65A0")))
void func_002D65A0(char *p, int v)
{
    char *q = *(char **)(p + 0x4);

    if (q != 0) {
        *(float *)(q + 0x6C) = (float)v;
    }
}
