/* sn-2.95.3-136 matched TU. */

typedef unsigned int size_t;

typedef struct Rep {
    size_t len;
    size_t res;
    size_t ref;
    int selfish;
} Rep;

typedef struct String {
    char *dat;
    unsigned char flag;
} String;

extern char *func_003BB058(Rep *);   /* basic_string<char>::Rep::clone */

__attribute__((section(".text.func_003BB980")))
String *func_003BB980(String *first, String *last, String *result)
{
    String *cur = result;

    for (; first != last; ++first, ++cur) {
        if (cur != 0) {
            char *dat = first->dat;
            Rep *r = (Rep *)(dat - 16);
            if (r->selfish) {
                dat = func_003BB058(r);
            } else {
                r->ref = r->ref + 1;
            }
            cur->dat = dat;
            cur->flag = first->flag;
        }
    }
    return cur;
}
