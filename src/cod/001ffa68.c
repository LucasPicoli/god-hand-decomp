/* sn-2.95.3-136: func_001FFA68, look a path up in a node table: normalise it to lower-case backslash form, then walk it one strtok component at a time. */
typedef struct PathNode {
    unsigned char type;                 /* 0x0 1 = directory, 2 = file, 3 = end of list, 0 = none */
    char unk1[3];
    char *name;                         /* 0x4 */
    struct PathNode *child;       /* 0x8 */
} PathNode;                       /* 0xC */

typedef struct PathTable {
    PathNode *root;               /* 0x00 */
    char unk04[0x15];
    char alias[1];                      /* 0x19 */
} PathTable;

/* newlib ctype: the class table one past its base; bit 0 is upper case. */
extern unsigned char D_0045F039[];
#define _U 01
#define isupper(c) (D_0045F039[(c)] & _U)

extern char D_0042C750[];
extern char *func_003A57C4(char *d, const char *s);
extern int func_003A5678(const char *a, const char *b);
extern char *func_003A9470(char *s, const char *delim);

__attribute__((section(".text.func_001FFA68")))
PathNode *func_001FFA68(PathTable *self, const char *path)
{
    char buf[0x40];
    char *p;
    char *tok;
    int c;
    int d;
    PathNode *n;

    if (self->root == 0)
        return 0;
    p = buf;
    func_003A57C4(buf, path);
    if (*p != 0) {
        do {
            if (*p == '/')
                *p = '\\';
            c = *p;
            d = c + 0x20;
            if (!isupper(c))
                d = c;
            *p = d;
            p++;
        } while (*p != 0);
    }
    n = self->root;
    tok = func_003A9470(buf, D_0042C750);
    while (tok != 0) {
        while (n->type != 3) {
            if (n->type == 2) {
                if (func_003A5678(n->name, tok) == 0)
                    return n;
            } else if (n->type == 1) {
                if (func_003A5678(n->name, tok) == 0 || func_003A5678(self->alias, tok) == 0) {
                    n = n->child;
                    break;
                }
            }
            n++;
        }
        if (n->type == 0)
            return 0;
        tok = func_003A9470(0, D_0042C750);
    }
    return 0;
}
