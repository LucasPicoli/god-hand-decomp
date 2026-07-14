/* sn-2.95.3-136 matched TU. */

typedef struct S3738A0 {
    char pad00[0x20];
    float f20;
    char pad24[8];
    float arr[11];
    int count;
} S3738A0;




__attribute__((section(".text.func_003738A0")))
void func_003738A0(S3738A0 *p, int idx, float val) {
    int i;

    if (func_00373A50(p, idx)) {
        if (func_00373B20(p) == 1) {
            if (idx < 0) {
                for (i = 0; i < p->count; i++) {
                    p->arr[i] = val;
                }
            } else {
                p->arr[idx] = val;
            }
        } else {
            p->f20 = val;
        }
    }
}
