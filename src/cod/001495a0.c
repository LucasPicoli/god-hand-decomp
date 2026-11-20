#include "godhand/cModel.h"

extern void *func_0014FF80(void *self);
extern void *cBoundingBox(void *box);
extern int D_0041EA90;

__attribute__((section(".text.func_001495A0")))
cModel *func_001495A0(cModel *self)
{
    unsigned char i;
    cVec *t;
    int j;

    func_0014FF80(self);
    self->vtable = (cVtEnt *)&D_0041EA90;
    t = &self->tint;
    t->x = 1.0f;
    t->y = 1.0f;
    t->z = 1.0f;
    t->w = 1.0f;
    self->objFlags = 0;
    self->meshHead = 0;
    cBoundingBox(&self->box);
    self->drawKind = 0xA;
    self->drawPrio = 3;
    self->meshNum = 0;
    self->partNum = 0;
    self->depthBias = 0;
    self->texFlags = 0;
    self->unk258 = 0;
    self->packet[0] = 0;
    self->packet[1] = 0;
    self->tailPacket[0] = 0;
    self->tailPacket[1] = 0;
    self->partPacket[0] = 0;
    self->partPacket[1] = 0;
    self->alloc = 0;
    self->arena = 0;
    self->unk288 = 0;
    i = 2;
    do {
        self->extraPacket[i - 1][0] = 0;
        self->extraPacket[i - 1][1] = 0;
        self->extraPacketB[i - 1][0] = 0;
        self->extraPacketB[i - 1][1] = 0;
        i--;
    } while (i != 0);
    self->life = 1000;
    self->alphaA = 0xFF;
    self->alphaC = 0xFF;
    self->alphaB = 0xFF;
    self->fadeLen = 200;
    self->lodDist = 180;
    self->layerForce = 0xFE;
    self->unk2BD = 0;
    return self;
}
