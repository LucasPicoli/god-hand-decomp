/* ee-2.9-991111 matched TU. */

extern char D_0045DF50[];

extern int func_003B4220(const char *path, int flag);   /* sceOpen  */
extern int func_003B4868(int fd, void *buf, int nbyte); /* sceRead  */
extern int func_003B44B0(int fd);                       /* sceClose */
extern int func_003A7C48(const char *s);                /* atoi     */

__attribute__((section(".text.checkModelVersion")))
int checkModelVersion(void)
{
    char buf[256];
    char *p;
    int fd;
    int i;

    fd = func_003B4220(D_0045DF50, 1);
    if (fd < 0) {
        return -1;
    }
    for (i = 0, p = buf; (unsigned int)i < 256; p++, i++) {
        func_003B4868(fd, p, 1);
        if (*p == 0) {
            break;
        }
    }
    func_003B44B0(fd);
    return func_003A7C48(&buf[i - 9]) > 0x1315670;
}
