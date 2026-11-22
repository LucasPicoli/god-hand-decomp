/* cygnus-2.96: read up to 0x1000 bytes of a file into buf with history markers around each step (open,
 * size, rewind, read, close); 1 on success. */
extern void *func_003A52F0(void *dst, int c, int n);
extern void func_00334D68(char *name, char *path);
extern void PushGlobalD8478History_331C78(int tag);
extern int SRD_SceOpen(char *path, int mode);
extern long func_00331DB8(int fd, int ofs, int whence);
extern int func_00331FA8(int fd, void *buf, int size);
extern void SRD_SceClose(int fd);

__attribute__((section(".text.htci_load_flist")))
int htci_load_flist(char *name, void *buf)
{
    char path[0x100];
    int fd;
    long size;
    int r;

    func_003A52F0(path, 0, 0x100);
    func_00334D68(name, path);
    PushGlobalD8478History_331C78(0x6000);
    fd = SRD_SceOpen(path, 1);
    PushGlobalD8478History_331C78(0x6001);
    if (fd < 0)
        return 0;
    PushGlobalD8478History_331C78(0x6100);
    size = func_00331DB8(fd, 0, 2);
    PushGlobalD8478History_331C78(0x6101);
    if (size < 0)
        return 0;
    PushGlobalD8478History_331C78(0x6200);
    r = func_00331DB8(fd, 0, 0);
    PushGlobalD8478History_331C78(0x6201);
    if (r < 0)
        return 0;
    if (size > 0x1000)
        size = 0x1000;
    PushGlobalD8478History_331C78(0x6300);
    r = func_00331FA8(fd, buf, size);
    PushGlobalD8478History_331C78(0x6301);
    if (r < 0) {
        PushGlobalD8478History_331C78(0x6500);
        SRD_SceClose(fd);
        PushGlobalD8478History_331C78(0x6501);
        return 0;
    }
    PushGlobalD8478History_331C78(0x6400);
    SRD_SceClose(fd);
    PushGlobalD8478History_331C78(0x6401);
    return 1;
}
