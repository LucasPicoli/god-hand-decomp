/* cygnus-2.96 matched TU. */
#include "godhand/criAix.h"

typedef struct AdxStream {
    signed char used, state, pending, mode;
    SjObj *joint;
    void *file;
    int startSector, totalBytes, totalSectors;
    int requestBytes, threshold;
    int readSectors;
    SjChunk chunk;
    int maxSectors, callbackSector, bytesDone;
    void (*callback)(void *);
    void *callbackArg;
    int capacity;
    signed char pause, opening, closing, reset, resume, active;
    char pad4A[2];
    int retries;
    void *filename;
    int openMode, sectorsDone, sectorLimit;
} AdxStream;

extern int D_003D04C8, D_003D1400, D_003D8498;
extern signed char D_003D849C;
extern int func_00330CF0(void *file);
extern int func_00330BB0(void *file, int sector, int origin);
extern int func_00330C18(void *file, int sectors, void *data);
extern void Obj3290_Tramp_0033E678_9028(void);
extern void Obj3290_Tramp_0033E690_9040(void);
extern void Obj0000_PostInc_D_003D04CC_3284A0(void);

/* Complete a pending stream read and submit the next available chunk. */
__attribute__((section(".text.func_003284B8")))
void func_003284B8(AdxStream *stream) {
    SjChunk head, tail;
    SjObj *joint = stream->joint;
    int status = func_00330CF0(stream->file);
    Obj3290_Tramp_0033E678_9028();
    if (stream->pending == 1) {
        if (status == stream->pending) {
            int count, total, totalSectors;
            stream->pending = 0;
            Obj3290_Tramp_0033E690_9040();
            count = stream->readSectors << 11;
            func_0033ACA0(&stream->chunk, count, &head, &tail);
            joint->vt->putChunk(joint, 1, &head);
            joint->vt->ungetChunk(joint, 0, &tail);
            total = stream->sectorsDone + stream->readSectors;
            stream->bytesDone += count;
            stream->chunk.data = 0;
            stream->sectorsDone = total;
            stream->chunk.len = 0;
            totalSectors = stream->totalSectors;
            if (total == stream->callbackSector) {
                if (stream->callback != 0) {
                    stream->callback(stream->callbackArg);
                }
            }
            if (stream->sectorsDone >= totalSectors ||
                (((unsigned int)stream->bytesDone >> 11) >= (unsigned int)stream->sectorLimit &&
                 (unsigned int)stream->sectorLimit <= 0xFFFFEU)) {
                stream->state = 3;
            }
            stream->retries = 0;
        } else if (status == 3) {
            int retries;
            stream->pending = 0;
            Obj3290_Tramp_0033E690_9040();
            joint->vt->ungetChunk(joint, 0, &stream->chunk);
            stream->chunk.data = 0;
            stream->chunk.len = 0;
            retries = stream->retries;
            if (D_003D04C8 < 0 || retries < D_003D04C8) {
                if (retries <= 0x7FFFFFFE) stream->retries = retries + 1;
            } else {
                stream->state = 4;
            }
        } else {
            Obj3290_Tramp_0033E690_9040();
        }
    }
    if (stream->state != 4 && stream->pending == 0) {
        stream->chunk.data = 0;
        stream->pending = 1;
        stream->chunk.len = 0;
        Obj3290_Tramp_0033E690_9040();
        if (stream->pause == 1) {
            stream->pending = 0;
        } else if (stream->resume == 1) {
            stream->pending = 0;
        } else if (stream->totalSectors == 0) {
            stream->readSectors = 0;
            stream->state = 3;
            stream->pending = 0;
        } else if (joint == 0 || joint->vt == 0) {
            stream->pending = 0;
            Obj0000_PostInc_D_003D04CC_3284A0();
        } else {
            int total, end, count, remaining, limitRemaining, readResult, seekSector, modeFlag;
            if (stream->capacity - joint->vt->getNumData(joint, 0) >= stream->threshold) {
                stream->pending = 0;
                return;
            }
            joint->vt->getChunk(joint, 0, stream->requestBytes, &tail);
            end = stream->callbackSector;
            total = stream->sectorsDone;
            end -= total;
            count = tail.len / 2048;
            remaining = stream->totalSectors - total;
            if (count >= end) count = end;
            if (count >= remaining) count = remaining;
            seekSector = stream->startSector + total;
            if (count >= stream->maxSectors) count = stream->maxSectors;
            func_00330BB0(stream->file, seekSector, 0);
            modeFlag = D_003D1400;
            if (modeFlag == 1) {
                D_003D8498 = modeFlag;
                if (stream->mode == modeFlag) D_003D849C = 0;
                else D_003D849C = modeFlag;
            }
            if (stream->sectorLimit != 0xFFFFF) {
                limitRemaining = stream->sectorLimit - stream->bytesDone / 2048;
                if (count >= limitRemaining) count = limitRemaining;
            }
            readResult = func_00330C18(stream->file, count, tail.data);
            stream->chunk.data = tail.data;
            stream->chunk.len = tail.len;
            stream->readSectors = readResult;
            if (readResult <= 0) {
                joint->vt->ungetChunk(joint, 0, &stream->chunk);
                stream->chunk.data = 0;
                stream->chunk.len = 0;
                stream->pending = 0;
                if (func_00330CF0(stream->file) == 3) {
                    int retries;
                    retries = stream->retries;
                    if (D_003D04C8 >= 0 && retries >= D_003D04C8) {
                        stream->state = 4;
                        return;
                    }
                    if (retries <= 0x7FFFFFFE) stream->retries = retries + 1;
                }
            }
        }
    }
}
