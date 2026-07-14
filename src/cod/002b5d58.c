/* sn-2.95.3-136 matched TU. */

extern void func_002B6080(void *dst, void *self);
extern void func_002B60D0(void *dst, void *self);
extern void StoreVecFromFieldB0_2B6160(void *dst, void *self);
extern void func_002B5EC0(void *self);
extern void cNode_setLocalScale(void *self, void *v);
extern void func_002B6230(void *self, void *v);
extern void cNode_setLocalTranslation(void *self, void *v);

typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;

__attribute__((section(".text.func_002B5D58")))
void func_002B5D58(void *arg, void *parent) {
    Vec4 a;
    Vec4 b;
    Vec4 c;
    char *self = (char *)arg;
    char *p;

    if (parent == 0) {
        func_002B6080(&a, self);
        func_002B60D0(&b, self);
        StoreVecFromFieldB0_2B6160(&c, self);
        func_002B5EC0(self);
        *(int *)(self + 0x4) = 0;
        cNode_setLocalScale(self, &a);
        func_002B6230(self, &b);
        cNode_setLocalTranslation(self, &c);
    } else if (func_002B5E50(self) == 0) {
        *(char **)(self + 0x4) = (char *)parent;
        if (*(char **)((char *)parent + 0x8) == 0) {
            *(char **)((char *)parent + 0x8) = self;
        } else {
            p = *(char **)((char *)parent + 0x8);
            while (*(char **)(p + 0x10) != 0) {
                p = *(char **)(p + 0x10);
            }
            *(char **)(self + 0xC) = p;
            *(char **)(p + 0x10) = self;
        }
    }
}
