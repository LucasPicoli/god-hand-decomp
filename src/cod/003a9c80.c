/* sn-2.95.3-136 matched TU. */
#include "godhand/globals.h"

extern int write(int fd, const void *buf, int n);

/* 0x003A9C80 — a line-buffered writer over the `write` syscall stub.
 * a3 == 1 flushes the pending buffer; otherwise it appends `len` bytes and
 * flushes every 0x80 bytes. */


__attribute__((section(".text.func_003A9C80")))
int func_003A9C80(int fd, const char *b, unsigned int len, int flush)
{
    unsigned int i;
    int r;

    if (flush == 1) {
        r = write(fd, D_0077DA88, D_003FA9C0);
        D_003FA9C0 = 0;
        D_003FA9C4 = D_0077DA88;
        return r;
    }
    for (i = 0; i < len; i++) {
        *D_003FA9C4 = b[i];
        D_003FA9C4 = D_003FA9C4 + 1;
        D_003FA9C0 = D_003FA9C0 + 1;
        if (D_003FA9C0 >= 0x80) {
            r = write(fd, D_0077DA88, D_003FA9C0);
            D_003FA9C4 = D_0077DA88;
            D_003FA9C0 = 0;
            if (r == 0) {
                return 0;
            }
        }
    }
    return i;
}

/* add_separators -- thousands-separator insert. Decompiled from the monolith;
 * no upstream name recovered. */

extern void *func_003A5148(void *dst, const void *src, int n);	/* memcpy */

__attribute__((section(".text.add_separators")))
char *add_separators(char *dst, const char *start, const char *end, int *outlen)
{
	int num;
	int len;
	int cnt;
	struct { int state; const char *limit; } w;
	const char *p;
	char *buf;
	char *q;

	num = end - start;
	buf = (char *) __builtin_alloca(num + 10);
	len = num + 10;
	q = buf + len - 1;
	cnt = 0;
	if (dst == 0 || start == 0 || end == 0)
		return 0;
	w.state = 0;
	w.limit = end;
	p = start;
	while (p <= end && w.state != 2) {
		switch (*p) {
		case '.':
			w.limit = p;
			if (w.state == 0)
				w.state = 1;
			break;
		case 'e':
		case 'E':
			w.state = 2;
			break;
		}
		p++;
	}
	if (w.state == 2)
		return (char *) start;
	p = end;
	if (start < p) {
		do {
			*q-- = *p;
			if (p <= w.limit) {
				if (cnt % 3 == 0 && cnt != 0) {
					*q-- = ',';
					len++;
				}
				cnt++;
			}
			p--;
		} while (start < p);
	}
	*q = *p;
	len -= 10;
	func_003A5148(dst, q, len);
	*outlen = len;
	return dst;
}

/* 0x003AB050 — a line-buffered writer over the `write` syscall stub.
 * a3 == 1 flushes the pending buffer; otherwise it appends `len` bytes and
 * flushes every 0x80 bytes. */


__attribute__((section(".text.func_003AB050")))
int func_003AB050(int fd, const char *b, unsigned int len, int flush)
{
    unsigned int i;
    int r;

    if (flush == 1) {
        r = write(fd, D_0077DB08, D_003FA9C8);
        D_003FA9C8 = 0;
        D_003FA9CC = D_0077DB08;
        return r;
    }
    for (i = 0; i < len; i++) {
        *D_003FA9CC = b[i];
        D_003FA9CC = D_003FA9CC + 1;
        D_003FA9C8 = D_003FA9C8 + 1;
        if (D_003FA9C8 >= 0x80) {
            r = write(fd, D_0077DB08, D_003FA9C8);
            D_003FA9CC = D_0077DB08;
            D_003FA9C8 = 0;
            if (r == 0) {
                return 0;
            }
        }
    }
    return i;
}
