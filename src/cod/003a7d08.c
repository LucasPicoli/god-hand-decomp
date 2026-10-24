/* sn-2.95.3-136 */

/* newlib libc/stdlib/mbtowc_r.c -- transcribed. */

/* The part of newlib's struct _reent this function reads. */
typedef struct ReentLocale {
    char pad00[0x34];
    char *_current_locale;      /* 0x34 */
} ReentLocale;

typedef enum { ESCAPE, DOLLAR, BRACKET, AT, B, J, NUL, JIS_CHAR, OTHER, JIS_C_NUM } JIS_CHAR_TYPE;
typedef enum { ASCII, A_ESC, A_ESC_DL, JIS, J_ESC, J_ESC_BR, J2_ESC, J2_ESC_BR, DUMMY } JIS_STATE;
typedef enum { COPY_A, COPY_J1, COPY_J2, MAKE_A, MAKE_J, NOOP, EMPTY, ERROR } JIS_ACTION;

#define ESC_CHAR 0x1B

#define _issjis1(c) (((c) >= 0x81 && (c) <= 0x9f) || ((c) >= 0xe0 && (c) <= 0xef))
#define _issjis2(c) (((c) >= 0x40 && (c) <= 0x7e) || ((c) >= 0x80 && (c) <= 0xfc))
#define _iseucjp(c) ((c) >= 0xa1 && (c) <= 0xfe)
#define _isjis(c)   ((c) >= 0x21 && (c) <= 0x7e)

extern unsigned int strlen(const char *s);
extern int func_003A5678(const char *a, const char *b);    /* strcmp */

extern JIS_STATE D_003FA630[][JIS_C_NUM];    /* JIS_state_table */
extern JIS_ACTION D_003FA7E0[][JIS_C_NUM];   /* JIS_action_table */
extern char D_0045F5F0[];   /* "C-SJIS" */
extern char D_0045F5F8[];   /* "C-EUCJP" */
extern char D_0045F600[];   /* "C-JIS" */

/* Convert the multibyte character at s (at most n bytes) to a wide character in the current locale. */
__attribute__((section(".text.func_003A7D08")))
int func_003A7D08(ReentLocale *r, int *pwc, const char *s, unsigned int n, int *state)
{
    int dummy;
    unsigned char *t = (unsigned char *)s;

    if (pwc == 0)
        pwc = &dummy;

    if (s != 0 && n == 0)
        return -1;

    if (r->_current_locale == 0 || strlen(r->_current_locale) <= 1) {
        /* fall-through */
    } else if (!func_003A5678(r->_current_locale, D_0045F5F0)) {
        int char1 = *t;
        if (s == 0)
            return 0;
        if (_issjis1(char1)) {
            int char2 = t[1];
            if (n <= 1)
                return -1;
            if (_issjis2(char2)) {
                *pwc = (((int)*t) << 8) + (int)(*(t + 1));
                return 2;
            } else
                return -1;
        }
    } else if (!func_003A5678(r->_current_locale, D_0045F5F8)) {
        int char1 = *t;
        if (s == 0)
            return 0;
        if (_iseucjp(char1)) {
            int char2 = t[1];
            if (n <= 1)
                return -1;
            if (_iseucjp(char2)) {
                *pwc = (((int)*t) << 8) + (int)(*(t + 1));
                return 2;
            } else
                return -1;
        }
    } else if (!func_003A5678(r->_current_locale, D_0045F600)) {
        JIS_STATE curr_state;
        JIS_ACTION action;
        JIS_CHAR_TYPE ch;
        unsigned char *ptr;
        unsigned int i;
        int curr_ch;

        if (s == 0) {
            *state = 0;
            return 1;
        }

        curr_state = (*state == 0 ? ASCII : JIS);
        ptr = t;

        for (i = 0; i < n; ++i) {
            curr_ch = t[i];
            switch (curr_ch) {
            case ESC_CHAR:
                ch = ESCAPE;
                break;
            case '$':
                ch = DOLLAR;
                break;
            case '@':
                ch = AT;
                break;
            case '(':
                ch = BRACKET;
                break;
            case 'B':
                ch = B;
                break;
            case 'J':
                ch = J;
                break;
            case '\0':
                ch = NUL;
                break;
            default:
                if (_isjis(curr_ch))
                    ch = JIS_CHAR;
                else
                    ch = OTHER;
            }

            action = D_003FA7E0[curr_state][ch];
            curr_state = D_003FA630[curr_state][ch];

            switch (action) {
            case NOOP:
                break;
            case EMPTY:
                *state = 0;
                *pwc = 0;
                return i;
            case COPY_A:
                *state = 0;
                *pwc = (int)*ptr;
                return i + 1;
            case COPY_J1:
                *state = 0;
                *pwc = (((int)*ptr) << 8) + (int)(*(ptr + 1));
                return i + 1;
            case COPY_J2:
                *state = 1;
                *pwc = (((int)*ptr) << 8) + (int)(*(ptr + 1));
                return (ptr - t) + 2;
            case MAKE_A:
            case MAKE_J:
                ptr = (unsigned char *)(t + i + 1);
                break;
            case ERROR:
            default:
                return -1;
            }
        }

        return -1;
    }

    if (s == 0)
        return 0;

    *pwc = (int)*t;

    if (*t == '\0')
        return 0;

    return 1;
}
