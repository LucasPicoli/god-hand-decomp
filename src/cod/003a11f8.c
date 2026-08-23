/* ee-2.9-991111 matched TU. */

extern void sceSifInitRpc(int mode);
extern void func_003B1F28(const char *fmt);
extern void FlushCache(int mode);
extern unsigned char D_0077C900[];
extern char D_0045E998[];
extern int D_003FA300;
extern int D_003FA304;

typedef struct {
	char	pad[0x24];
	int	server;		/* 0x24 */
} Cd;






__attribute__((section(".text.func_003A11F8")))
int func_003A11F8(void)
{
	int i;

	sceSifInitRpc(0);
	while (1) {
		if (func_003B2F48(D_0077C900, 0x80000701, 0) < 0) {
			func_003B1F28(D_0045E998);
			return -1;
		}
		for (i = 10000; i != -1; i--)
			;
		if (((Cd *)D_0077C900)->server != 0)
			break;
	}
	D_003FA300 = 0;
	D_003FA304 = 0;
	FlushCache(0);
	return 0;
}
