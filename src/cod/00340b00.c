/* cygnus-2.96 matched TU. */

typedef signed char   Sint8;
typedef unsigned char Uint8;
typedef short         Sint16;
typedef unsigned short Uint16;
typedef int           Sint32;
typedef unsigned int  Uint32;

#define RD32(p) ((p)[0] | ((p)[1] << 8) | ((p)[2] << 16) | ((p)[3] << 24))
#define SWP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | ((x) << 24))

__attribute__((section(".text.func_00341480")))
void *func_00341480(void *hdr, Sint32 hdrlen, Sint32 *sfreq, Sint32 *nch,
                    Sint32 *bps, Sint32 *nsmpl, Sint32 *cdc)
{
    Uint32 magic, hdr_size, data_size, encoding;
    Uint8 *pdw;

    pdw = (Uint8 *)hdr;
    magic = RD32(pdw);
    pdw += 4;
    if ((magic != 0x0064732E) && (magic != 0x646E732E)) {
        return 0;
    }
    hdr_size = RD32(pdw);
    pdw += 4;
    hdr_size = SWP32(hdr_size);
    if (hdrlen < (Sint32)hdr_size) {
        return 0;
    }
    data_size = RD32(pdw);
    pdw += 4;
    data_size = SWP32(data_size);
    encoding = RD32(pdw);
    pdw += 4;
    encoding = SWP32(encoding);
    switch (encoding) {
    case 1:
        *cdc = 2;
        *bps = 8;
        break;
    case 2:
        *cdc = 1;
        *bps = 8;
        break;
    case 3:
        *cdc = 0;
        *bps = 16;
        break;
    default:
        return 0;
    }
    *sfreq = SWP32(RD32(pdw));
    pdw += 4;
    *nch = SWP32(RD32(pdw));
    pdw += 4;
    if (*cdc == 2) {
        *nsmpl = (Sint32)data_size / *nch;
    } else if (*cdc == 1) {
        *nsmpl = (Sint32)data_size / *nch;
    } else if (*cdc == 0) {
        *nsmpl = ((Sint32)data_size / 2) / *nch;
    } else {
        *nsmpl = 0x7FFF0000;
    }
    return (Uint8 *)hdr + hdr_size;
}

typedef signed char   Sint8;
typedef unsigned char Uint8;
typedef short         Sint16;
typedef unsigned short Uint16;
typedef int           Sint32;
typedef unsigned int  Uint32;

#define RD16(p) ((p)[0] | ((p)[1] << 8))
#define RD32(p) ((p)[0] | ((p)[1] << 8) | ((p)[2] << 16) | ((p)[3] << 24))
#define SWP16(x) ((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00))
#define SWP16W(x) ((((x) >> 8) & 0xFF) | (((x) << 8) & ~0xFF))
#define SWP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | ((x) << 24))

__attribute__((section(".text.func_00340B00")))
void *func_00340B00(void *hdr, Sint32 *sfreq, Sint32 *nch, Sint32 *bps, Sint32 *nsmpl)
{
    Uint8 *pdw;
    Uint8 *pdwEnd;
    Sint32 ck_id;
    Sint32 ck_size;
    Sint32 form_type;
    Sint32 comm_ck_flag;
    Sint32 ssnd_ck_flag;
    Uint32 ssnd_ofst;
    Sint32 exp;
    Sint32 mant;
    void *data;

    pdw = (Uint8 *)hdr;
    data = 0;
    ssnd_ck_flag = 0;
    comm_ck_flag = 0;
    ck_id = RD32(pdw);
    pdw += 4;
    ck_size = RD32(pdw);
    pdw += 4;
    ck_size = SWP32(ck_size);
    form_type = RD32(pdw);
    pdw += 4;
    if (ck_id != 0x4D524F46) {
        return 0;
    }
    if (form_type != 0x46464941) {
        return 0;
    }
    pdwEnd = pdw + ck_size - 4;
    while (pdw < pdwEnd) {
        ck_id = RD32(pdw);
        pdw += 4;
        ck_size = RD32(pdw);
        pdw += 4;
        ck_size = SWP32(ck_size);
        switch (ck_id) {
        case 0x4D4D4F43:                     /* COMM */
            if (comm_ck_flag == 0) {
                if (ck_size < 0x12) {
                    return 0;
                }
                comm_ck_flag = 1;
                *nch = SWP16(RD16(pdw));
                pdw += 2;
                *nsmpl = SWP32(RD32(pdw));
                pdw += 4;
                *bps = SWP16(RD16(pdw));
                pdw += 2;
                exp = SWP16W(RD16(pdw));
                pdw += 2;
                mant = RD16(pdw);
                pdw += 8;
                *sfreq = (Uint16)SWP16W(mant) >> (0x400E - exp);
                if (ssnd_ck_flag != 0) {
                    return data;
                }
            }
            break;
        case 0x444E5353:                     /* SSND */
            if (ssnd_ck_flag == 0) {
                ssnd_ck_flag = 1;
                ssnd_ofst = RD32(pdw);
                pdw += 4;
                ssnd_ofst = SWP32(ssnd_ofst);
                data = pdw + ssnd_ofst;
                if (comm_ck_flag != 0) {
                    return data;
                }
            }
            break;
        default:
            pdw += (ck_size + 1) & -2;
            break;
        }
    }
    return data;
}
