/* sn-2.95.3-136 matched TU. */
#include "godhand/cCoreSave.h"
#include "godhand/cModel.h"

/* The mesh node whose name is name (up to 8 chars packed into a long, first
 * char in the low byte), or 0 when the model has none. */
__attribute__((section(".text.cModel_getMeshPtr_14B730")))
cModelNode *cModel_getMeshPtr_14B730(cModel *self, char *name)
{
    long key;
    int i;
    cModelNode *node;

    key = 0;
    i = 0;
    if (*name != 0) {
        do {
            key = key | ((long)*name << (i * 8));
            i = i + 1;
            name = name + 1;
            if (i >= 8) {
                break;
            }
        } while (*name != 0);
    }
    node = self->meshHead;
    while (node != 0) {
        if (node->info->name == key) {
            break;
        }
        node = node->next;
    }
    return node;
}

/* Walks one pointer from the record to the flag word, the way retail forms
 * the address. The empty do-while keeps retail's scheduling. */
__attribute__((section(".text.cCoreSave_SetFightingRingClearFlag")))
void cCoreSave_SetFightingRingClearFlag(cCoreSave *self, unsigned int bit, int set)
{
    char *p;
    unsigned int w;

    p = (char *)self->data;
    if (p == 0) return;
    w = bit >> 5;
    if (w >= 4) return;
    bit = bit & 0x1F;
    w = w * 4;
    if (set) {
        p = p + CORESAVE_OFFSET(fightingRingClear);
        p = p + w;
        do { } while (0);
        *(unsigned int *)p = *(unsigned int *)p | (1 << bit);
    } else {
        p = p + CORESAVE_OFFSET(fightingRingClear);
        p = p + w;
        do { } while (0);
        *(unsigned int *)p = *(unsigned int *)p & ~(1 << bit);
    }
}

__attribute__((section(".text.func_0027DC50")))
void func_0027DC50(char *obj, unsigned int mode)
{
    switch (mode) {
    case 0:
    default:
        obj[0x2F4] = 0;
        obj[0x2F5] = 8;
        obj[0x2F6] = 0;
        obj[0x2F7] = 0;
        break;
    case 1:
        obj[0x2F4] = 0;
        obj[0x2F5] = 8;
        obj[0x2F6] = 2;
        obj[0x2F7] = 0;
        break;
    case 2:
        obj[0x2F4] = 0;
        obj[0x2F5] = 8;
        obj[0x2F6] = 4;
        obj[0x2F7] = 0;
        break;
    case 3:
        obj[0x2F4] = 0;
        obj[0x2F5] = 8;
        obj[0x2F6] = 6;
        obj[0x2F7] = 0;
        break;
    }
}

__attribute__((section(".text.func_002832F8")))
void func_002832F8(char *obj, unsigned int mode)
{
    switch (mode) {
    case 0:
    default:
        obj[0x2F4] = 0;
        obj[0x2F5] = 9;
        obj[0x2F6] = 0;
        obj[0x2F7] = 0;
        break;
    case 1:
        obj[0x2F4] = 0;
        obj[0x2F5] = 9;
        obj[0x2F6] = 2;
        obj[0x2F7] = 0;
        break;
    case 2:
        obj[0x2F4] = 0;
        obj[0x2F5] = 9;
        obj[0x2F6] = 4;
        obj[0x2F7] = 0;
        break;
    case 3:
        obj[0x2F4] = 0;
        obj[0x2F5] = 9;
        obj[0x2F6] = 6;
        obj[0x2F7] = 0;
        break;
    }
}
