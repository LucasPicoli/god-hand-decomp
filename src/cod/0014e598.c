/* sn-2.95.3-136 matched TU. */

extern void flush__7ostream(void *a0);
extern void __as__22_IO_ostream_withassignR7ostream(void *a0, void *a1);
extern void __as__22_IO_istream_withassignR7istream(void *a0, void *a1);
extern int D_003BAFE0[];
extern void ForwardFieldNeg20_002A9680_30F5A0(void);
extern void func_003B9DE0(void *);
extern int D_00460AA8;
extern void func_001495A0(void *);
extern int D_0041EAF0;
extern void func_001BD580(void *);
extern int D_00420D68;
extern int D_00421C80;
extern int D_00422178;
extern void func_001BFAC8(void *);
extern int D_00422B48;
extern int D_00423C70;
extern int D_00425AC0;
extern void func_0014E990(void *);
extern int D_00450C38;
extern int D_003FA62C;
extern int D_003FBEA8;

__attribute__((section(".text.Tramp_flush__7ostream_3892C0")))
void Tramp_flush__7ostream_3892C0(void *a0) {
    flush__7ostream(a0);
}

__attribute__((section(".text.Tramp___as__22_IO_ostream_withassignR7ostream_389808")))
void Tramp___as__22_IO_ostream_withassignR7ostream_389808(void *a0, void *a1) {
    __as__22_IO_ostream_withassignR7ostream(a0, a1);
}

__attribute__((section(".text.Tramp___as__22_IO_istream_withassignR7istream_389960")))
void Tramp___as__22_IO_istream_withassignR7istream_389960(void *a0, void *a1) {
    __as__22_IO_istream_withassignR7istream(a0, a1);
}

__attribute__((section(".text.func_00372C80")))
void func_00372C80(int *a0, int a1) {
    *(int **)((char *)a0 + 0x80) = D_003BAFE0;
    if (a1 & 1) {
        ForwardFieldNeg20_002A9680_30F5A0();
    }
}

__attribute__((section(".text.func_003AB158")))
int func_003AB158(void *a0, void *a1, void *a2) {
    return func_003AB188(*(int *)((char *)a0 + 0x54), a0, a1, a2);
}

__attribute__((section(".text.func_003BA800")))
int func_003BA800(int *a0) {
    if (a0) {
        return *(int *)((char *)a0 + 4);
    }
    func_003B9DE0(&D_00460AA8);
    return -1;
}

__attribute__((section(".text.func_0014E598")))
void *func_0014E598(void *a0){
  func_001495A0(a0);
  *(int**)((char*)a0+0x214) = &D_0041EAF0;
  return a0;
}

__attribute__((section(".text.func_00171B10")))
void *func_00171B10(void *a0){
  func_001BD580(a0);
  *(int**)((char*)a0+0x214) = &D_00420D68;
  return a0;
}

__attribute__((section(".text.func_0017C4A8")))
void *func_0017C4A8(void *a0){
  func_001BD580(a0);
  *(int**)((char*)a0+0x214) = &D_00421C80;
  return a0;
}

__attribute__((section(".text.func_0017EA98")))
void *func_0017EA98(void *a0){
  func_001BD580(a0);
  *(int**)((char*)a0+0x214) = &D_00422178;
  return a0;
}

__attribute__((section(".text.func_00183348")))
void *func_00183348(void *a0){
  func_001BFAC8(a0);
  *(int**)((char*)a0+0x214) = &D_00422B48;
  return a0;
}

__attribute__((section(".text.func_0018EC98")))
void *func_0018EC98(void *a0){
  func_001BFAC8(a0);
  *(int**)((char*)a0+0x214) = &D_00423C70;
  return a0;
}

__attribute__((section(".text.func_0019C118")))
void *func_0019C118(void *a0){
  func_001BFAC8(a0);
  *(int**)((char*)a0+0x214) = &D_00425AC0;
  return a0;
}

__attribute__((section(".text.func_003184E0")))
void *func_003184E0(void *a0){
  func_0014E990(a0);
  *(int**)((char*)a0+0x214) = &D_00450C38;
  return a0;
}

__attribute__((section(".text.func_003A9228")))
int func_003A9228(int a0, int a1, int a2) {
    return func_003A9018(D_003FA62C, a0, a1, a2);
}

__attribute__((section(".text.func_003AD0C0")))
int func_003AD0C0(int a0, int a1, int a2) {
    return func_003ACE90(D_003FA62C, a0, a1, a2);
}

__attribute__((section(".text.func_003B6E40")))
int func_003B6E40(int *a0)
{
    int *next;
    int *prev;

    next = (int *)a0[1];
    prev = (int *)a0[0];
    if (next != 0) {
        next[0] = (int)prev;
    } else {
        D_003FBEA8 = (int)prev;
    }
    if (prev != 0) {
        prev[1] = a0[1];
        a0[1] = 0;
    } else {
        a0[1] = 0;
    }
    return (int)prev;
}
