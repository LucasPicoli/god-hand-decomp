/* sn-2.95.3-136 matched TU. */

extern void func_0030A650(void *dst, void *src, float a);
extern void func_0030A7B8(void *dst, void *src, float a);
extern void func_0030A700(void *dst, void *src, float a);

__attribute__((section(".text.sceVu0RotMatrix")))
void sceVu0RotMatrix(void *dst, void *src, float *ang) {
    func_0030A650(dst, src, ang[2]);
    func_0030A7B8(dst, dst, ang[1]);
    func_0030A700(dst, dst, ang[0]);
}
