/* sn-2.95.3-136 matched TU. */

extern int Obj0000_Get_Byte_17C3_NZ_2_276468(void *a0);
extern void ForwardAnimParamPairByIndex_27EA50(int a0, int a1);
extern void *Getplayer(void);
extern void cGameObj_SetTgtTurn(void *a0, int a1, float a2);
extern float Turn_dest(void *a0, void *a1, float f12, float f13);
extern int moveMotion(void *a0);
extern void cObjBase_addNullSpeed_Rotation(void *a0, float a1);
extern void cObjBase_addNullSpeed(void *a0, float a1);
extern void func_002705D8(void *a0);
extern void func_002A8578(void *a0, int a1, int a2, float f, int a3, int a4, int a5);
extern void func_002A74E0(void *a0, void *a1, int a2);

extern int irand(void);
extern unsigned int D_007476B0;
__attribute__((section(".text.func_002112F0"))) void func_002112F0(void *a0)
{
  char *s2 = (char *) a0;
  int s1v;
  int s0v;
  int gb;
  float d;
  float new_var;
  float ad;
  float f0z;
  float k3;
  char *sp0;
  *((int *) (s2 + 0x16D0)) = (*((int *) (s2 + 0x16D0))) | 0x400;
  switch (*((unsigned char *) (s2 + 0x2F6)))
  {
    case 0:
      gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s2) & 0xFFFF;
      switch (*((int *) (s2 + 0x564)))
    {
      default:
      {
        int b = *((int *) (s2 + 0x304));
        s1v = (*((int *) (b + 0x98))) + b;
        s0v = (*((int *) (b + 0x9C))) + b;
        break;
      }

      case 0x202:

      case 0x203:

      case 0x213:

      case 0x216:

      case 0x217:

      case 0x229:

      case 0x22A:

      case 0x24B:
      {
        int b = *((int *) (s2 + 0x304));
        s1v = (*((int *) (b + 0x648))) + b;
        s0v = (*((int *) (b + 0x64C))) + b;
        break;
      }

      case 0x242:

      case 0x243:

      case 0x244:
      {
        int b = *((int *) (s2 + 0x304));
        s1v = (*((int *) (b + 0x35CC))) + b;
        s0v = (*((int *) (b + 0x35D0))) + b;
        break;
      }

      case 0x256:

      case 0x27E:
      {
        int b = *((int *) (s2 + 0x304));
        s1v = (*((int *) (b + 0x25AC))) + b;
        s0v = (*((int *) (b + 0x25B0))) + b;
        break;
      }

      case 0x214:

      case 0x215:

      case 0x21A:

      case 0x21B:

      case 0x21C:

      case 0x21D:

      case 0x21E:

      case 0x22C:

      case 0x22D:

      case 0x22E:

      case 0x22F:

      case 0x248:

      case 0x249:

      case 0x24C:

      case 0x24E:

      case 0x25A:
      {
        int b = *((int *) (s2 + 0x304));
        s1v = (*((int *) (b + 0x10A8))) + b;
        s0v = (*((int *) (b + 0x10AC))) + b;
        break;
      }

      case 0x225:

      case 0x24D:
      {
        int b = *((int *) (s2 + 0x304));
        s1v = (*((int *) (b + 0x3C88))) + b;
        s0v = (*((int *) (b + 0x3C8C))) + b;
        break;
      }

      case 0x252:
      {
        int b = *((int *) (s2 + 0x304));
        s1v = (*((int *) (b + 0x24EC))) + b;
        s0v = (*((int *) (b + 0x24F0))) + b;
        break;
      }

      case 0x20A:

      case 0x20B:

      case 0x20D:

      case 0x20E:

      case 0x218:

      case 0x245:

      case 0x246:

      case 0x247:
      {
        int b = *((int *) (s2 + 0x304));
        s1v = (*((int *) (b + 0x828))) + b;
        s0v = (*((int *) (b + 0x82C))) + b;
        break;
      }

      case 0x278:

      case 0x279:
      {
        int b = *((int *) (s2 + 0x304));
        s1v = (*((int *) (b + 0x1FB0))) + b;
        s0v = (*((int *) (b + 0x1FB4))) + b;
        break;
      }

      case 0x250:

      case 0x251:
      {
        int b = *((int *) (s2 + 0x304));
        s1v = (*((int *) (b + 0x18F0))) + b;
        s0v = (*((int *) (b + 0x18F4))) + b;
        break;
      }

      case 0x260:
      {
        int b = *((int *) (s2 + 0x304));
        s1v = (*((int *) (b + 0x3038))) + b;
        s0v = (*((int *) (b + 0x303C))) + b;
        break;
      }

      case 0x264:
      {
        int b = *((int *) (s2 + 0x304));
        s1v = (*((int *) (b + 0x326C))) + b;
        s0v = (*((int *) (b + 0x3270))) + b;
        break;
      }

      case 0x265:
      {
        int b = *((int *) (s2 + 0x304));
        int m = *((int *) (s2 + 0x744));
        s1v = (*((int *) (b + 0x3724))) + b;
        s0v = (*((int *) (b + 0x3728))) + b;
        if (m != 0)
        {
          ForwardAnimParamPairByIndex_27EA50(m, 0x0);
        }
        break;
      }

      case 0x26A:
      {
        int b = *((int *) (s2 + 0x304));
        s1v = (*((int *) (b + 0x3D34))) + b;
        s0v = (*((int *) (b + 0x3D38))) + b;
        break;
      }

      case 0x20C:

      case 0x24F:
      {
        int b = *((int *) (s2 + 0x304));
        s1v = (*((int *) (b + 0x1EAC))) + b;
        s0v = (*((int *) (b + 0x1EB0))) + b;
        break;
      }

      case 0x205:

      case 0x206:

      case 0x207:

      case 0x208:

      case 0x224:
      {
        int b = *((int *) (s2 + 0x304));
        s1v = (*((int *) (b + 0x1560))) + b;
        s0v = (*((int *) (b + 0x1564))) + b;
        break;
      }

      case 0x241:
      {
        int b = *((int *) (s2 + 0x304));
        s1v = (*((int *) (b + 0x3A00))) + b;
        s0v = (*((int *) (b + 0x3A04))) + b;
        break;
      }

      case 0x209:

      case 0x21F:
      {
        int b = *((int *) (s2 + 0x304));
        s1v = (*((int *) (b + 0x3418))) + b;
        s0v = (*((int *) (b + 0x341C))) + b;
        break;
      }

      case 0x20F:

      case 0x210:

      case 0x211:

      case 0x226:

      case 0x270:

      case 0x271:

      case 0x272:

      case 0x273:

      case 0x274:
      {
        int b = *((int *) (s2 + 0x304));
        s1v = (*((int *) (b + 0xCF8))) + b;
        s0v = (*((int *) (b + 0xCFC))) + b;
        break;
      }

      case 0x220:

      case 0x221:

      case 0x222:
      {
        int b = *((int *) (s2 + 0x304));
        s1v = (*((int *) (b + 0x1BC0))) + b;
        s0v = (*((int *) (b + 0x1BC4))) + b;
        break;
      }

      case 0x223:
      {
        int b = *((int *) (s2 + 0x304));
        s1v = (*((int *) (b + 0x2D38))) + b;
        s0v = (*((int *) (b + 0x2D3C))) + b;
        break;
      }

      case 0x275:

      case 0x276:
      {
        int b = *((int *) (s2 + 0x304));
        s1v = (*((int *) (b + 0x2274))) + b;
        s0v = (*((int *) (b + 0x2278))) + b;
        break;
      }

    }

      if ((*((int *) (s2 + 0x6EC))) != 0)
    {
      int b = *((int *) (s2 + 0x304));
      s1v = (*((int *) (b + 0x44C))) + b;
      s0v = (*((int *) (b + 0x450))) + b;
    }
      func_002A8578(s2, s1v, s0v, 0.0f, 10, gb, 0);
      *((int *) (s2 + 0x5F0)) = 10;
      *((unsigned char *) (s2 + 0x2F6)) = (*((unsigned char *) (s2 + 0x2F6))) + 1;

    case 1:
      if ((*((int *) (s2 + 0x5F0))) != 0)
    {
      *((int *) (s2 + 0x5F0)) = (*((int *) (s2 + 0x5F0))) - 1;
      moveMotion(s2);
    }
    else
    {
      *((int *) (s2 + 0x16D0)) = (*((int *) (s2 + 0x16D0))) | 0x8000;
      if (0.0f < (*((float *) (s2 + 0x24C))))
      {
        moveMotion(s2);
        cObjBase_addNullSpeed_Rotation(s2, 1.0f);
        cObjBase_addNullSpeed(s2, 1.0f);
      }
    }
      sp0 = *((char **) (s2 + 0xF0));
      d = Turn_dest(sp0, *((void **) (((char *) Getplayer()) + 0xF0)), *((float *) (s2 + 0x104)), 3.14159274f);
      if (d < 0.0f)
    {
      ad = (new_var = -d);
    }
    else
    {
      ad = d;
    }
      if (0.34906584f < ad)
    {
      *((unsigned char *) (s2 + 0x2F6)) = 2;
    }
      break;

    case 2:
      gb = Obj0000_Get_Byte_17C3_NZ_2_276468(s2) & 0xFFFF;
      sp0 = *((char **) (s2 + 0xF0));
      d = Turn_dest(sp0, *((void **) (((char *) Getplayer()) + 0xF0)), *((float *) (s2 + 0x104)), 3.14159274f);
      if (d < 0.0f)
    {
      switch (*((int *) (s2 + 0x564)))
      {
        default:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0xB0))) + b;
          s0v = (*((int *) (b + 0xB4))) + b;
          break;
        }

        case 0x202:

        case 0x203:

        case 0x213:

        case 0x216:

        case 0x217:

        case 0x229:

        case 0x22A:

        case 0x24B:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x650))) + b;
          s0v = (*((int *) (b + 0x654))) + b;
          break;
        }

        case 0x242:

        case 0x243:

        case 0x244:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x35D4))) + b;
          s0v = (*((int *) (b + 0x35D8))) + b;
          break;
        }

        case 0x256:

        case 0x27E:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x25DC))) + b;
          s0v = (*((int *) (b + 0x25E0))) + b;
          break;
        }

        case 0x214:

        case 0x215:

        case 0x21A:

        case 0x21B:

        case 0x21C:

        case 0x21D:

        case 0x21E:

        case 0x22C:

        case 0x22D:

        case 0x22E:

        case 0x22F:

        case 0x248:

        case 0x249:

        case 0x24C:

        case 0x24E:

        case 0x252:

        case 0x25A:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x10B0))) + b;
          s0v = (*((int *) (b + 0x10B4))) + b;
          break;
        }

        case 0x225:

        case 0x24D:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x3C90))) + b;
          s0v = (*((int *) (b + 0x3C94))) + b;
          break;
        }

        case 0x20A:

        case 0x20B:

        case 0x20D:

        case 0x20E:

        case 0x218:

        case 0x245:

        case 0x246:

        case 0x247:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x830))) + b;
          s0v = (*((int *) (b + 0x834))) + b;
          break;
        }

        case 0x278:

        case 0x279:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x1FB8))) + b;
          s0v = (*((int *) (b + 0x1FBC))) + b;
          break;
        }

        case 0x250:

        case 0x251:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x18F8))) + b;
          s0v = (*((int *) (b + 0x18FC))) + b;
          break;
        }

        case 0x260:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x3040))) + b;
          s0v = (*((int *) (b + 0x3044))) + b;
          break;
        }

        case 0x264:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x3274))) + b;
          s0v = (*((int *) (b + 0x3278))) + b;
          break;
        }

        case 0x265:
        {
          int b = *((int *) (s2 + 0x304));
          int m = *((int *) (s2 + 0x744));
          s1v = (*((int *) (b + 0x3734))) + b;
          s0v = (*((int *) (b + 0x3738))) + b;
          if (m != 0)
          {
            ForwardAnimParamPairByIndex_27EA50(m, 0x4);
          }
          break;
        }

        case 0x26A:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x3D34))) + b;
          s0v = (*((int *) (b + 0x3D38))) + b;
          break;
        }

        case 0x20C:

        case 0x24F:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x1EB4))) + b;
          s0v = (*((int *) (b + 0x1EB8))) + b;
          break;
        }

        case 0x205:

        case 0x206:

        case 0x207:

        case 0x208:

        case 0x224:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x1568))) + b;
          s0v = (*((int *) (b + 0x156C))) + b;
          break;
        }

        case 0x241:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x3A08))) + b;
          s0v = (*((int *) (b + 0x3A0C))) + b;
          break;
        }

        case 0x209:

        case 0x21F:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x3420))) + b;
          s0v = (*((int *) (b + 0x3424))) + b;
          break;
        }

        case 0x20F:

        case 0x210:

        case 0x211:

        case 0x226:

        case 0x270:

        case 0x271:

        case 0x272:

        case 0x273:

        case 0x274:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0xD18))) + b;
          s0v = (*((int *) (b + 0xD1C))) + b;
          break;
        }

        case 0x220:

        case 0x221:

        case 0x222:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x1BC8))) + b;
          s0v = (*((int *) (b + 0x1BCC))) + b;
          break;
        }

        case 0x223:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x2D48))) + b;
          s0v = (*((int *) (b + 0x2D4C))) + b;
          break;
        }

        case 0x275:

        case 0x276:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x227C))) + b;
          s0v = (*((int *) (b + 0x2280))) + b;
          break;
        }

      }

    }
    else
    {
      switch (*((int *) (s2 + 0x564)))
      {
        default:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0xB0))) + b;
          s0v = (*((int *) (b + 0xB4))) + b;
          break;
        }

        case 0x202:

        case 0x203:

        case 0x213:

        case 0x216:

        case 0x217:

        case 0x229:

        case 0x22A:

        case 0x24B:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x650))) + b;
          s0v = (*((int *) (b + 0x654))) + b;
          break;
        }

        case 0x242:

        case 0x243:

        case 0x244:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x35D4))) + b;
          s0v = (*((int *) (b + 0x35D8))) + b;
          break;
        }

        case 0x256:

        case 0x27E:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x25DC))) + b;
          s0v = (*((int *) (b + 0x25E0))) + b;
          break;
        }

        case 0x214:

        case 0x215:

        case 0x21A:

        case 0x21B:

        case 0x21C:

        case 0x21D:

        case 0x21E:

        case 0x22C:

        case 0x22D:

        case 0x22E:

        case 0x22F:

        case 0x248:

        case 0x249:

        case 0x24C:

        case 0x24E:

        case 0x252:

        case 0x25A:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x10B0))) + b;
          s0v = (*((int *) (b + 0x10B4))) + b;
          break;
        }

        case 0x225:

        case 0x24D:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x3C90))) + b;
          s0v = (*((int *) (b + 0x3C94))) + b;
          break;
        }

        case 0x20A:

        case 0x20B:

        case 0x20D:

        case 0x20E:

        case 0x218:

        case 0x245:

        case 0x246:

        case 0x247:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x830))) + b;
          s0v = (*((int *) (b + 0x834))) + b;
          break;
        }

        case 0x278:

        case 0x279:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x1FB8))) + b;
          s0v = (*((int *) (b + 0x1FBC))) + b;
          break;
        }

        case 0x250:

        case 0x251:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x18F8))) + b;
          s0v = (*((int *) (b + 0x18FC))) + b;
          break;
        }

        case 0x260:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x3040))) + b;
          s0v = (*((int *) (b + 0x3044))) + b;
          break;
        }

        case 0x264:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x3274))) + b;
          s0v = (*((int *) (b + 0x3278))) + b;
          break;
        }

        case 0x265:
        {
          int b = *((int *) (s2 + 0x304));
          int m = *((int *) (s2 + 0x744));
          s1v = (*((int *) (b + 0x3734))) + b;
          s0v = (*((int *) (b + 0x3738))) + b;
          if (m != 0)
          {
            ForwardAnimParamPairByIndex_27EA50(m, 0x4);
          }
          break;
        }

        case 0x26A:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x3D34))) + b;
          s0v = (*((int *) (b + 0x3D38))) + b;
          break;
        }

        case 0x20C:

        case 0x24F:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x1EB4))) + b;
          s0v = (*((int *) (b + 0x1EB8))) + b;
          break;
        }

        case 0x205:

        case 0x206:

        case 0x207:

        case 0x208:

        case 0x224:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x1568))) + b;
          s0v = (*((int *) (b + 0x156C))) + b;
          break;
        }

        case 0x241:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x3A08))) + b;
          s0v = (*((int *) (b + 0x3A0C))) + b;
          break;
        }

        case 0x209:

        case 0x21F:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x3420))) + b;
          s0v = (*((int *) (b + 0x3424))) + b;
          break;
        }

        case 0x20F:

        case 0x210:

        case 0x211:

        case 0x226:

        case 0x270:

        case 0x271:

        case 0x272:

        case 0x273:

        case 0x274:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0xD20))) + b;
          s0v = (*((int *) (b + 0xD24))) + b;
          break;
        }

        case 0x220:

        case 0x221:

        case 0x222:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x1BC8))) + b;
          s0v = (*((int *) (b + 0x1BCC))) + b;
          break;
        }

        case 0x223:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x2D48))) + b;
          s0v = (*((int *) (b + 0x2D4C))) + b;
          break;
        }

        case 0x275:

        case 0x276:
        {
          int b = *((int *) (s2 + 0x304));
          s1v = (*((int *) (b + 0x227C))) + b;
          s0v = (*((int *) (b + 0x2280))) + b;
          break;
        }

      }

    }
      if ((*((int *) (s2 + 0x6EC))) != 0)
    {
      int b = *((int *) (s2 + 0x304));
      s1v = (*((int *) (b + 0x454))) + b;
      s0v = (*((int *) (b + 0x458))) + b;
    }
      func_002A8578(s2, s1v, s0v, 0.0f, 10, gb, 0);
      *((unsigned char *) (s2 + 0x2F6)) = (*((unsigned char *) (s2 + 0x2F6))) + 1;

    case 3:
      cGameObj_SetTgtTurn(s2, *((int *) (((char *) Getplayer()) + 0xF0)), (*((float *) (s2 + 0x5A8))) * 0.09817477f);
      if (900.0f < (*((float *) (s2 + 0x618))))
    {
      if ((D_007476B0 & 7) == ((*((unsigned int *) (s2 + 0x17D0))) & 7))
      {
        moveMotion(s2);
      }
    }
    else
    {
      moveMotion(s2);
    }
      sp0 = *((char **) (s2 + 0xF0));
      d = Turn_dest(sp0, *((void **) (((char *) Getplayer()) + 0xF0)), *((float *) (s2 + 0x104)), 3.14159274f);
      if (d < 0.0f)
    {
      ad = -d;
    }
    else
    {
      ad = d;
    }
      k3 = 0.08726646f;
      d = k3;
      if (ad < d)
    {
      *((unsigned char *) (s2 + 0x2F6)) = 0;
    }
      break;

  }

  if (((*((float *) (s2 + 0x618))) < 64.0f) || ((*((int *) (s2 + 0x16EC))) != 0))
  {
    if ((D_007476B0 & 7) == ((*((unsigned int *) (s2 + 0x17D0))) & 7))
    {
      *((int *) (s2 + 0x16D4)) = (*((int *) (s2 + 0x16D4))) & 0xF7FFFFFF;
      func_002A74E0(s2, *((void **) (((char *) Getplayer()) + 0xF0)), 1);
      if (func_002A7CA0(s2, s2 + 0x16A0) != 0)
      {
        *((int *) (s2 + 0x16D4)) = (*((int *) (s2 + 0x16D4))) | 0x8000000;
      }
      if (((*((float *) (s2 + 0x510))) < 8.0f) || ((*((int *) (s2 + 0x16EC))) != 0))
      {
        *((int *) (s2 + 0x16D0)) = ((*((int *) (s2 + 0x16D0))) | 2) & 0xFFFF7FFF;
        if ((((irand() & 1) != 0) && ((*((float *) (s2 + 0x16C0))) <= 0.0f)) && ((*((int *) (s2 + 0x16EC))) <= 0))
        {
          *((unsigned char *) (s2 + 0x2F7)) = 0;
          *((unsigned char *) (s2 + 0x2F4)) = 0;
          *((unsigned char *) (s2 + 0x2F6)) = 0;
          *((unsigned char *) (s2 + 0x2F5)) = 0x6B;
        }
        else
        {
          func_002705D8(s2);
        }
        return;
      }
    }
  }
  if (0.0f < (*((float *) (s2 + 0x16C0))))
  {
    func_002705D8(s2);
  }
}
