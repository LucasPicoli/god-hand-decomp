extern unsigned char D_0044A870[];

__attribute__((section(".text.cEmWrap_SetVitalMax")))
void cEmWrap_SetVitalMax(void *a0, int a1) {
    if (FindResolveActor_295978(a0, a1)) {
        *(short*)(*(char**)((char*)a0 + 4) + 0x548) = (short)a1;
    }
}

