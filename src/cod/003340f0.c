/* cygnus-2.96 matched TU. */

extern int Forward33B568_33B688(void *a0);
extern void func_00331070(void *a0);
extern int Forward33B5C8_33B6B8(void);

/* MATCH via cygnus-2.96 +drop-freorder. twin of func_00332890 (state ptr f2C; caseB uses f24/f1C/f28). */




__attribute__((section(".text.func_003340F0")))
void func_003340F0(void *a0){ char *s0=(char*)a0;
 if(*(int*)(s0+0x2C)==0) return;
 Forward33B568_33B688(s0);
 switch(func_003312B0(*(void**)(s0+0x2C))){
 case 9: *(char*)(s0+0x2)=3;
  func_00331070(*(void**)(s0+0x2C)); *(int*)(s0+0x2C)=0; break;
 case 8: break;
 case 7: break;
 case 6: break;
 case 5: break;
 case 4: break;
 case 3: *(int*)(s0+0x28)=*(int*)(s0+0x24); *(int*)(s0+0x1C)+=*(int*)(s0+0x24); *(char*)(s0+0x2)=1;
  func_00331070(*(void**)(s0+0x2C)); *(int*)(s0+0x2C)=0; break;
 case 2: break;
 case 1: break;
 case 0: *(char*)(s0+0x2)=0;
  func_00331070(*(void**)(s0+0x2C)); *(int*)(s0+0x2C)=0; break; }
 Forward33B5C8_33B6B8(); }
