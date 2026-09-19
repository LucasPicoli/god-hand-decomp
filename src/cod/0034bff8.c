/* cygnus-2.96 matched TU. */

/* cygnus-2.96 */

typedef struct SupInfo { int f0; int f4; } SupInfo;

extern int sfbuf_ChkSupSj(SupInfo *q);

extern int Obj35C0_IsIndexedSet_1F3C_C380(void *hn, int f);


__attribute__((section(".text.SFBUF_SetSupplySj")))
int SFBUF_SetSupplySj(void *hn, SupInfo *q)
{
    int no;

    if (sfbuf_ChkSupSj(q) != 0) {
        return func_0034DD70(hn, 0xFF000408U);
    }
    if (Obj35C0_IsIndexedSet_1F3C_C380(hn, 1) != 0) {
        no = 0;
    } else if (Obj35C0_IsIndexedSet_1F3C_C380(hn, 2) != 0) {
        no = 1;
    } else if (Obj35C0_IsIndexedSet_1F3C_C380(hn, 3) != 0) {
        no = 2;
    } else {
        no = 0;
    }
    return func_0034C0E8(hn, q, no);
}
