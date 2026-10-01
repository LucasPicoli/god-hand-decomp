/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern unsigned char D_0044A870[];
extern void cEm00_setGoto(void*, int, int, int, float);
extern void func_0026E7A8(int a0, int a1);
extern void func_00297660(void *a0);
extern int D_00569B70;

__attribute__((section(".text.cEmWrap_SetVital")))
void cEmWrap_SetVital(void *a0, int a1) {
    if (FindResolveActor_295978(a0)) {
        char *p = *(char **)((char *)a0 + 4);
        if (a1 >= *(short *)(p + 0x548)) {
            *(short *)(p + 0x54A) = *(unsigned short *)(p + 0x548);
        } else {
            *(short *)(p + 0x54A) = (short)a1;
        }
    }
}

__attribute__((section(".text.cEmWrap_SetRaderType")))
void cEmWrap_SetRaderType(void *a0, char a1) {
    if (FindResolveActor_295978(a0)) {
        *(char *)(*(char **)((char *)a0 + 4) + 0x531) = a1;
    }
}

__attribute__((section(".text.cEmWrap_setGoto")))
void cEmWrap_setGoto(void *a0,int a1,int a2,int a3,float f){
 if(FindResolveActor_295978(a0)){
  char *p=*(char**)((char*)a0+4);
  if(*(short*)(p+0x54A)>0){
   if(func_003A5678(D_0044A870,*(int*)(p+0x4AC))==0){
    cEm00_setGoto(*(void**)((char*)a0+4),a1,a2,a3,f);
   }
  }
 }
}

__attribute__((section(".text.ResetObjectState_2962B0")))
void ResetObjectState_2962B0(void *a0) {
    *(int *)((char *)a0 + 0x38) = cCoreSave_getBlock180(&D_00569B70);
    func_00297660(a0);
    *(char *)((char *)a0 + 0x34) = 0;
    *(int *)((char *)a0 + 0) = 0;
}
