#include "godhand/cModel.h"
#include "godhand/cCockTutorial.h"

/* SN ProDG ee-gcc 2.95.3 matched TU. */

extern char D_0041DCC8[];
extern void __builtin_delete(void);
extern void cIDBase_trans(void *);

/* Start a tutorial message once the pack is loaded: remember the message
 * number, raise the flag byte and hide entries 5 and 6. */
__attribute__((section(".text.cCockTutorial_TutorialON")))
void cCockTutorial_TutorialON(cCockTutorial *self, unsigned short msg) {
    if (self->data) {
        self->curMsg = msg;
        self->unkB8 = 1;
        self->ent[5]->flags = self->ent[5]->flags | IDENT_FLAG_NO_DRAW;
        self->ent[6]->flags = self->ent[6]->flags | IDENT_FLAG_NO_DRAW;
    }
}

/* Show or hide every mesh on one layer. */
__attribute__((section(".text.cModel_setLayerDisplay")))
void cModel_setLayerDisplay(cModel *self, int layer, int show) {
    cModelNode *node = self->meshHead;
    if (node == 0) return;
    do {
        if (layer == node->layer) {
            unsigned int flags = node->dispFlags;
            if (show != 0)
                flags &= 0xFFFFFFFE;
            else
                flags |= CMODEL_NODE_HIDE;
            node->dispFlags = flags;
        }
        node = node->next;
    } while (node != 0);
}

__attribute__((section(".text.InitPtrField80AndForward_146748")))
void InitPtrField80AndForward_146748(void *a0, int a1) {
    *(char **)((char *)a0 + 0x80) = D_0041DCC8;
    if (a1 & 1) {
        __builtin_delete();
    }
}

__attribute__((section(".text.ForwardTransBySubState_146E20")))
void ForwardTransBySubState_146E20(char *a0) {
    char v1 = a0[0x79];
    if (v1 == 0) return;
    if (v1 == 6) return;
    if (*(unsigned short *)(a0 + 0xF8) == 0) {
        cIDBase_trans(a0);
    } else {
        cIDBase_trans(a0 + 0xA0);
    }
}

__attribute__((section(".text.InitPtrField80AndForward_146E70")))
void InitPtrField80AndForward_146E70(void *a0, int a1) {
    *(char **)((char *)a0 + 0x80) = D_0041DCC8;
    if (a1 & 1) {
        __builtin_delete();
    }
}

__attribute__((section(".text.InitPtrField80AndForward_146F98")))
void InitPtrField80AndForward_146F98(void *a0, int a1) {
    *(char **)((char *)a0 + 0x80) = D_0041DCC8;
    if (a1 & 1) {
        __builtin_delete();
    }
}
