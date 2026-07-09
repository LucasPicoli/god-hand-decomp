/* sn-2.95.3-136 matched TU. */

extern void func_00378AA8(void *a0);
extern void func_00378BF8(void *a0);
extern void func_00378CE0(void *a0);
extern void func_0037B620(void *a0);
extern void func_0037AC68(void *a0);
extern void func_0037E128(void *a0, void *a1);
extern void func_0037DC88(void *a0, int a1);
extern void *D_003F21B8;

/* func_00378760 — 6-case forwarder switch on +0x5. */








__attribute__((section(".text.func_00378760")))
void func_00378760(void *a0){ char *s0=(char*)a0;
 if(*(int*)(s0+0x34)&0x800){ *(char*)(s0+4)=1;
  if(D_003F21B8!=0){ func_0037DC88(D_003F21B8,3); D_003F21B8=0; } return; }
 switch(*(char*)(s0+5)){
 case 0: func_00378AA8(s0); break;
 case 1: func_00378BF8(s0); break;
 case 2: func_00378CE0(s0); break;
 case 3: func_0037B620(s0); break;
 case 4: func_0037AC68(s0); break;
 case 5: func_0037E128(D_003F21B8,s0); break; }
 if(*(char*)(s0+4)!=0){
  if(D_003F21B8!=0){ func_0037DC88(D_003F21B8,3); D_003F21B8=0; } } }
