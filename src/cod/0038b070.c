/* ee-2.9-991111 matched TU. */

extern int _IO_switch_to_get_mode(void);
extern int _IO_default_uflow(void);
extern int _IO_default_doallocate(void *a0);
extern int _IO_sungetc(void *a0);
extern int _IO_flush_all(void);
extern int _IO_flush_all_linebuffered(void);
extern int _IO_file_doallocate(void);
extern int _IO_file_sync(void);

__attribute__((section(".text.func_0038B070")))
int func_0038B070(void)
{
    return _IO_switch_to_get_mode();
}

__attribute__((section(".text.func_0038B090")))
int func_0038B090(void)
{
    return func_0038C3A0();
}

__attribute__((section(".text.func_0038B0E0")))
int func_0038B0E0(void)
{
    return _IO_default_uflow();
}

__attribute__((section(".text.func_0038B1F8")))
int func_0038B1F8(void)
{
    return func_0038D168();
}

__attribute__((section(".text.func_0038B328")))
int func_0038B328(void)
{
    return func_0038E490();
}

__attribute__((section(".text.func_0038B348")))
int func_0038B348(void)
{
    return func_0038C768();
}

__attribute__((section(".text.Tramp__IO_default_doallocate_38B368")))
int Tramp__IO_default_doallocate_38B368(void *a0) {
    return _IO_default_doallocate(a0);
}

__attribute__((section(".text.func_0038B388")))
int func_0038B388(void *a0) {
    return func_0038C7F0(a0);
}

__attribute__((section(".text.func_0038B440")))
int func_0038B440(void *a0) {
    return func_0038E3F0(a0);
}

__attribute__((section(".text.Tramp__IO_sungetc_38B480")))
int Tramp__IO_sungetc_38B480(void *a0) {
    return _IO_sungetc(a0);
}

__attribute__((section(".text.Tramp__IO_flush_all_38B4F0")))
int Tramp__IO_flush_all_38B4F0(void) {
    return _IO_flush_all();
}

__attribute__((section(".text.Tramp__IO_flush_all_linebuffered_38B510")))
int Tramp__IO_flush_all_linebuffered_38B510(void) {
    return _IO_flush_all_linebuffered();
}

__attribute__((section(".text.func_0038EF20")))
int func_0038EF20(void) {
    return func_00392830();
}

__attribute__((section(".text.func_0038EF40")))
int func_0038EF40(void) {
    return func_00392998();
}

__attribute__((section(".text.Tramp__IO_file_doallocate_38EF80")))
int Tramp__IO_file_doallocate_38EF80(void) {
    return _IO_file_doallocate();
}

__attribute__((section(".text.func_0038EFA0")))
int func_0038EFA0(void) {
    return func_00392CD0();
}

__attribute__((section(".text.func_0038EFC0")))
int func_0038EFC0(void) {
    return func_00392BA0();
}

__attribute__((section(".text.Tramp__IO_file_sync_38EFE0")))
int Tramp__IO_file_sync_38EFE0(void) {
    return _IO_file_sync();
}
