#include "godhand/globals.h"
__attribute__((section(".text.LoadAndWaitReady_1FFBF0")))
void LoadAndWaitReady_1FFBF0(char *a0, int a1){
	if (func_00322AF8(0, a1, 0, &D_00580D80) == 0) {
		*(char *)(a0 + 0x18) = 1;
		while (func_00323000(0) != 3) {
			sceGsSyncV(0);
		}
		*(char *)(a0 + 0x18) = 0;
	}
}
