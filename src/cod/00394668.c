/* sn-2.95.3-136: resolve a symbol by name and id across the registered tables, preferring strong
 * definitions (kinds 2 and 4) over the first weak one (kind 3); otherwise run the fallback pass. */
#include "godhand/regTbl.h"
extern int func_003A5678(int a0, int a1);
extern int func_003943D0(RegEnt *elem);
extern int func_00394348(int tbl, int count, int idx);


__attribute__((section(".text.func_00394668")))
int func_00394668(int name, unsigned short id)
{
    RegTbl *node;
    RegEnt *elem;
    RegEnt *weak;
    int cnt;

    weak = 0;
    node = D_003F852C;
    if (node != 0) {
        do {
            cnt = node->count;
            elem = node->ents;
            if (cnt != 0) {
                do {
                    if (elem->id == id && func_003A5678(elem->name, name) == 0) {
                        switch (elem->kind) {
                        case 2:
                        case 4:
                            return func_003943D0(elem);
                        case 3:
                            if (weak == 0)
                                weak = elem;
                            break;
                        }
                    }
                    elem++;
                } while (--cnt != 0);
            }
            node = node->next;
        } while (node != 0);
    }
    if (weak != 0)
        return func_003943D0(weak);
    node = D_003F852C;
    if (node != 0) {
        do {
            cnt = node->count;
            elem = node->ents;
            if (cnt != 0) {
                do {
                    if (elem->id == id && func_003A5678(elem->name, name) == 0
                        && (elem->kind == 1 || elem->kind == 3)) {
                        if (func_00394348(node->handleA, node->handleB, elem - node->ents) == 0)
                            return 0;
                        break;
                    }
                    elem++;
                } while (--cnt != 0);
            }
            node = node->next;
        } while (node != 0);
    }
    return 1;
}
