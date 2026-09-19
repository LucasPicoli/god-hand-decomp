/* cygnus-2.96 matched TU. */

/* cygnus-2.96, -freorder-blocks dropped. Donor sj_utl.o SJ_SearchTag. */
typedef signed char Sint8;
typedef int Sint32;
typedef struct { Sint8 *data; Sint32 len; } SJCK;
typedef struct { Sint8 *data; Sint32 len; } SJTAG;


extern Sint32 sj_hexstr_to_val(Sint8 *s);
extern void func_0033ADC0(Sint8 *p, SJTAG *out);

__attribute__((section(".text.SJ_SearchTag")))
Sint8 *SJ_SearchTag(SJCK *ck, Sint8 *tag, Sint8 *endtag, SJTAG *tagck)
{
    Sint8 *p;
    Sint8 *end;

    tagck->data = 0;
    tagck->len = 0;
    end = ck->data + ck->len;
    p = ck->data;
    while (p < end) {
        if (func_003A5BD8(p, tag, 7) == 0) {
            func_0033ADC0(p, tagck);
            break;
        }
        if (endtag != 0 && func_003A5BD8(p, endtag, 7) == 0) {
            return 0;
        }
        p = p + sj_hexstr_to_val(p + 8) + 0x10;
    }
    if (p < end) {
        return p;
    }
    return 0;
}
