/* cygnus-2.96 matched TU. */

extern int Forward33B568_33B688(void);
extern void func_00331070(void *a0);
extern int Forward33B5C8_33B6B8(void);

/* MATCH via cygnus-2.96 +drop-freorder. state dispatch on func_003312B0(f1C); cases 0/3/9 act, rest tail-call. */




__attribute__((section(".text.func_00332890")))
void func_00332890(void *a0){ char *s0=(char*)a0;
 if(*(int*)(s0+0x1C)==0) return;
 Forward33B568_33B688();
 switch(func_003312B0(*(void**)(s0+0x1C))){
 case 9: *(char*)(s0+0x2)=3;
  func_00331070(*(void**)(s0+0x1C)); *(int*)(s0+0x1C)=0; break;
 case 8: break;
 case 7: break;
 case 6: break;
 case 5: break;
 case 4: break;
 case 3: *(int*)(s0+0x14)=*(int*)(s0+0x10); *(int*)(s0+0xC)+=*(int*)(s0+0x10); *(char*)(s0+0x2)=1;
  func_00331070(*(void**)(s0+0x1C)); *(int*)(s0+0x1C)=0; break;
 case 2: break;
 case 1: break;
 case 0: *(char*)(s0+0x2)=0;
  func_00331070(*(void**)(s0+0x1C)); *(int*)(s0+0x1C)=0; break; }
 Forward33B5C8_33B6B8(); }
