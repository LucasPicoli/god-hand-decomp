/* ee-2.9-991111 matched TU. */

extern int D_786758;
extern char D_0045D370[];
extern char D_00460DB8[];
extern void func_0038C128();
extern void SetField_0_4_8_31EEA8(void *a, void *b, void *c);

/* clone */






__attribute__((section(".text.func_0038C0D8")))
void *func_0038C0D8(void) {
    int *s0 = &D_786758;
    if (!*s0) {
        func_0038C128();
        SetField_0_4_8_31EEA8(s0, &D_0045D370, &D_00460DB8);
    }
    return s0;
}
