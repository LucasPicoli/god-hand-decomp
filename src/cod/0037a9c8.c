/* sn-2.95.3-136 matched TU. */

/* MATCH via sn-2.95.3-136. leaf switch on (signed char)(f25-1) over sub-struct a0+0x9C; case 8 falls into 9. */
__attribute__((section(".text.func_0037A9C8")))
void func_0037A9C8(void *arg){ char *p=(char*)arg; char *a1=p+0x9C;
 switch((signed char)(*(unsigned char*)(p+0x25)-1)){
 case 0:
  if(*(signed char*)(a1+0x1E)==-1) *(unsigned short*)(a1+0xE)|=1;
  else *(unsigned short*)(a1+0xE)&=0xFFFE;
  break;
 case 1: break;
 case 2: break;
 case 3: break;
 case 4: break;
 case 5: break;
 case 6:
  if(*(short*)(a1+0x18)>*(short*)(a1+0x1A)) *(unsigned short*)(a1+0x1A)=*(unsigned short*)(a1+0x18);
  break;
 case 7:
  if(*(short*)(a1+0x1A)<*(short*)(a1+0x18)) *(unsigned short*)(a1+0x18)=*(unsigned short*)(a1+0x1A);
  break;
 case 8:
  if((signed char)a1[6]+(signed char)a1[7]>=0x30) a1[7]=0x2F-*(unsigned char*)(a1+6);
 case 9:
  if((signed char)a1[6]+(signed char)a1[7]>=0x30) a1[6]=0x2F-*(unsigned char*)(a1+7);
  break; }
}
