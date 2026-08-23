/* sn-2.95.3-136 matched TU. */

/* MIPS relocation applier: patch (where, type, value) */

#define ISBREAK(w) ((*(unsigned int *) (w) & 0xFC00003F) == 0xD)

__attribute__((section(".text.patch")))
int
patch (unsigned char *where, unsigned int type, unsigned int value)
{
  switch (type)
    {
    case 2:
      *(unsigned int *) where = value;
      break;

    case 4:
      if (ISBREAK (where))
	return 0;
      *(unsigned int *) where = (*(unsigned int *) where & 0xFC000000)
			      | ((value >> 2) & 0x03FFFFFF);
      break;

    case 5:
      if (ISBREAK (where))
	return 0;
      *(unsigned short *) where = (value + 0x8000) >> 16;
      break;

    case 6:
      if (ISBREAK (where))
	return 0;
      *(unsigned short *) where = value;
      break;

    case 1:
      *(unsigned short *) where = value;
      break;

    case 0x77:
      *(unsigned int *) where = (*(unsigned int *) where & 0xFFE0003F)
			      | ((value << 3) & 0x001FFFC0);
      break;

    case 0x78:
      *(unsigned int *) where = (*(unsigned int *) where & 0xFFFFF800)
			      | (((value - (unsigned int) where) >> 3) & 0x7FF);
      break;

    case 0x79:
      *(unsigned int *) where = (*(unsigned int *) where & 0x8000000F)
			      | (value & 0x7FFFFFF0);
      break;

    case 0x7A:
      value >>= 4;
      *(unsigned int *) where = (*(unsigned int *) where & 0xFFFFF800)
			      | (value & 0x7FF);
      break;

    case 0x7B:
      value >>= 3;
      *(unsigned int *) where = (*(unsigned int *) where & 0xFE1FF800)
			      | (value & 0x7FF)
			      | ((value & 0x7800) << 10);
      break;

    case 0:
      break;

    default:
      return 0;
    }
  return 1;
}
