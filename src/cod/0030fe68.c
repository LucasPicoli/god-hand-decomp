/* sn-2.95.3-136 matched TU. */
#include "godhand/heapArena.h"
#include "godhand/cDataManager.h"
#include "godhand/FileLoadRec.h"
#include "godhand/objFactory.h"

/* Build the actor for id, stamp its serial and id, then bind its data pack:
 * the id's own file when it has one, else dataId's (none for 0xFFFF; id 0x500
 * only gets the D_00754240 arena), the cached copy or a fresh load, with
 * dataId's load as the fallback. 0 when there is no actor or the load fails. */
__attribute__((section(".text.func_0030FE68")))
cObj *func_0030FE68(int id, int dataId)
{
    cObj *obj;
    void *d;
    void *r;

    switch (id) {
    case 0xFFFF:
        obj = 0;
        break;
    case 0x0:
        obj = &func_00312E88()->base;
        break;
    case 0x100:
        obj = AllocAndInitSystem_312F00();
        break;
    case 0x101:
        obj = ObjFactory_create101();
        break;
    case 0x103:
        obj = ObjFactory_create103();
        break;
    case 0x27A:
        obj = ObjFactory_create27A();
        break;
    case 0x212:
        obj = ObjFactory_create212();
        break;
    case 0x253:
        obj = ObjFactory_create253();
        break;
    case 0x257:
        obj = ObjFactory_create257();
        break;
    case 0x259:
        obj = ObjFactory_create257();
        break;
    case 0x200:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x201:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x202:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x203:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x204:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x205:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x206:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x207:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x208:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x209:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x20A:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x20B:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x20C:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x20D:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x20E:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x20F:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x210:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x211:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x213:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x214:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x215:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x216:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x217:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x218:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x21A:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x21B:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x21C:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x21D:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x21E:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x21F:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x220:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x223:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x224:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x225:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x23A:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x23B:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x240:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x241:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x242:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x243:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x244:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x246:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x247:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x24F:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x252:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x256:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x258:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x25A:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x260:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x264:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x265:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x26A:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x270:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x275:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x276:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x278:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x279:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x27E:
        obj = AllocZeroedAndInit_3130E0();
        break;
    case 0x27F:
        obj = ObjFactory_create27F();
        break;
    case 0x230:
        obj = AllocAndInitObjVtable_313510();
        break;
    case 0x231:
        obj = AllocAndSetupObj_313580();
        break;
    case 0x232:
        obj = AllocAndSetupObj_313580();
        break;
    case 0x263:
        obj = AllocZeroedAndInitVtable_3135F0();
        break;
    case 0x266:
        obj = AllocZeroedAndSetupObj_313660();
        break;
    case 0x26B:
        obj = AllocAndInitObjVtableFull_3136D0();
        break;
    case 0x26C:
        obj = ForwardInitBuffer_313740();
        break;
    case 0x23F:
        obj = ForwardInitVtable214Buffer_3137B0();
        break;
    case 0x2A5:
        obj = ForwardInitBuffer_313890();
        break;
    case 0x2A6:
        obj = ForwardInitObj28B0Buffer_313900();
        break;
    case 0x2A2:
        obj = ForwardInitBuffer_313820();
        break;
    case 0x2A3:
        obj = ForwardInitBuffer_313820();
        break;
    case 0x2A4:
        obj = ForwardInitBuffer_313820();
        break;
    case 0x2A7:
        obj = ForwardInitBuffer_313820();
        break;
    case 0x2A8:
        obj = ForwardInitBuffer_313820();
        break;
    case 0x2A9:
        obj = ForwardInitBuffer_313820();
        break;
    case 0x2AD:
        obj = ForwardSetupBuffer_28E018_313970();
        break;
    case 0x300:
        obj = ForwardInitBuffer_313A60();
        break;
    case 0x301:
        obj = ForwardInitBuffer_313AD0();
        break;
    case 0x302:
        obj = ForwardInitBuffer_313B40();
        break;
    case 0x303:
        obj = ForwardInitBuffer_313BB0();
        break;
    case 0x304:
        obj = ForwardInitBuffer_313C20();
        break;
    case 0x305:
        obj = ForwardInitBuffer_313C90();
        break;
    case 0x306:
        obj = ForwardInitBuffer_313D00();
        break;
    case 0x307:
        obj = ForwardInitBuffer_313D70();
        break;
    case 0x308:
        obj = ForwardInitBuffer_313DE0();
        break;
    case 0x309:
        obj = AllocZeroedBlock_313E50();
        break;
    case 0x30A:
        obj = ForwardInitBuffer_313EC0();
        break;
    case 0x30B:
        obj = ForwardInitBuffer_313F30();
        break;
    case 0x30C:
        obj = ForwardInitBuffer_313FA0();
        break;
    case 0x30D:
        obj = ForwardInitBuffer_314010();
        break;
    case 0x30E:
        obj = ForwardInitBuffer_314080();
        break;
    case 0x30F:
        obj = ForwardInitBuffer_3140F0();
        break;
    case 0x310:
        obj = ForwardInitBuffer_314160();
        break;
    case 0x311:
        obj = ForwardInitBuffer_3141D0();
        break;
    case 0x312:
        obj = ForwardInitBuffer_314240();
        break;
    case 0x313:
        obj = ForwardInitBuffer_3142B0();
        break;
    case 0x314:
        obj = ForwardInitBuffer_314320();
        break;
    case 0x317:
        obj = ForwardInitBuffer_314400();
        break;
    case 0x318:
        obj = ForwardInitBuffer_314470();
        break;
    case 0x319:
        obj = ForwardInitBuffer_3144E0();
        break;
    case 0x31A:
        obj = ForwardInitBuffer_314550();
        break;
    case 0x31B:
        obj = ForwardInitBuffer_3145C0();
        break;
    case 0x31C:
        obj = ForwardInitBuffer_314630();
        break;
    case 0x31D:
        obj = ForwardInitBuffer_3146A0();
        break;
    case 0x31E:
        obj = ForwardInitBuffer_314710();
        break;
    case 0x31F:
        obj = ForwardInitBuffer_314780();
        break;
    case 0x320:
        obj = ForwardInitBuffer_3147F0();
        break;
    case 0x322:
        obj = AllocZeroAndInit_9E0_314860();
        break;
    case 0x323:
        obj = ForwardInitBuffer_3148D0();
        break;
    case 0x324:
        obj = ForwardInitBuffer_314940();
        break;
    case 0x325:
        obj = ForwardInitBuffer_3149B0();
        break;
    case 0x326:
        obj = ForwardInitBuffer_314A20();
        break;
    case 0x327:
        obj = ForwardInitBuffer_314A90();
        break;
    case 0x328:
        obj = ForwardInitBuffer_314B00();
        break;
    case 0x329:
        obj = ForwardInitBuffer_314B70();
        break;
    case 0x32A:
        obj = ForwardInitBuffer_314BE0();
        break;
    case 0x32B:
        obj = ForwardInitBuffer_314C50();
        break;
    case 0x32C:
        obj = ForwardInitBuffer_314CC0();
        break;
    case 0x32D:
        obj = ForwardInitBuffer_314D30();
        break;
    case 0x32E:
        obj = ForwardInitBuffer_314DA0();
        break;
    case 0x32F:
        obj = ForwardInitBuffer_314E10();
        break;
    case 0x330:
        obj = ForwardInitBuffer_314E80();
        break;
    case 0x331:
        obj = ForwardInitBuffer_314EF0();
        break;
    case 0x332:
        obj = ForwardInitBuffer_314F60();
        break;
    case 0x333:
        obj = ForwardInitBuffer_314FD0();
        break;
    case 0x334:
        obj = ForwardInitObjVtableBuffer_315040();
        break;
    case 0x335:
        obj = ForwardSetObjVtableBuffer_3150B0();
        break;
    case 0x336:
        obj = ForwardInitObjVu0Block_315120();
        break;
    case 0x337:
        obj = ForwardInitVu0ObjBlock_315190();
        break;
    case 0x338:
        obj = ForwardInitVu0ObjData_315200();
        break;
    case 0x339:
        obj = ForwardInitObjVu0Array_315270();
        break;
    case 0x33A:
        obj = AllocZeroedAndInitObjSlots_3152E0();
        break;
    case 0x33B:
        obj = AllocZeroedAndInitObjSlots_315350();
        break;
    case 0x33C:
        obj = AllocZeroedAndInitObjSlots_3153C0();
        break;
    case 0x33D:
        obj = AllocZeroedAndInitObjSlots_315430();
        break;
    case 0x33E:
        obj = AllocZeroedAndInitObjSlots_3154A0();
        break;
    case 0x33F:
        obj = AllocZeroedAndInitObjSlots_315510();
        break;
    case 0x340:
        obj = AllocZeroedAndSetupFields214And620_315580();
        break;
    case 0x341:
        obj = AllocZeroedAndInitVu0SlotArray4_3155F0();
        break;
    case 0x342:
        obj = AllocZeroedAndInitVu0SlotArray5_315660();
        break;
    case 0x343:
        obj = AllocZeroedAndInitVu0SlotArray5B_3156D0();
        break;
    case 0x344:
        obj = AllocZeroedAndInitVu0SlotArray4B_315740();
        break;
    case 0x345:
        obj = AllocZeroedAndInitObjSlots_3157B0();
        break;
    case 0x346:
        obj = AllocZeroedAndInitObjSlotsB_315820();
        break;
    case 0x347:
        obj = AllocZeroedAndForwardInit1A25A0_315890();
        break;
    case 0x348:
        obj = ForwardInit1A3A98_315900();
        break;
    case 0x349:
        obj = ForwardInit1A3D10_315970();
        break;
    case 0x34F:
        obj = ForwardInit1A42E8_3159E0();
        break;
    case 0x350:
        obj = ForwardInit1A5100_315A50();
        break;
    case 0x351:
        obj = ForwardInit1A5FD8_315AC0();
        break;
    case 0x353:
        obj = ForwardInit1A7788_315BA0();
        break;
    case 0x354:
        obj = ForwardInit1A8150_315C10();
        break;
    case 0x355:
        obj = ForwardInit1A8348_315C80();
        break;
    case 0x356:
        obj = ForwardInit1A86F8_315CF0();
        break;
    case 0x357:
        obj = ForwardInit1A88B0_315D60();
        break;
    case 0x358:
        obj = ForwardInit1A9688_315DD0();
        break;
    case 0x359:
        obj = ForwardInit1A9858_315E40();
        break;
    case 0x35A:
        obj = ForwardInit1ABD40_315EB0();
        break;
    case 0x35C:
        obj = ForwardInit1ADB88_315F20();
        break;
    case 0x35D:
        obj = ForwardInit1AE798_315F90();
        break;
    case 0x35E:
        obj = ForwardInit1B0290_316000();
        break;
    case 0x35F:
        obj = ForwardInit1B0B70_316070();
        break;
    case 0x360:
        obj = ForwardInit1B0CE8_3160E0();
        break;
    case 0x364:
        obj = ForwardInit1B0CE8_3160E0();
        break;
    case 0x371:
        obj = ForwardInitObject_3161C0();
        break;
    case 0x381:
        obj = ForwardInitObject_316230();
        break;
    case 0x390:
        dataId = 0x37B;
        obj = ForwardInit1C9140_316150();
        break;
    case 0x352:
        obj = ForwardInit1A6D68_315B30();
        break;
    case 0x3A6:
        obj = ForwardInit1A6D68_315B30();
        break;
    case 0x3A7:
        obj = ForwardInit1A6D68_315B30();
        break;
    case 0x3B0:
        obj = ForwardInitObject_3162A0();
        break;
    case 0x3B2:
        obj = ForwardInitObject_316310();
        break;
    case 0x3B3:
        obj = ForwardInitObject_316380();
        break;
    case 0x3B5:
        obj = ForwardInitObject_3163F0();
        break;
    case 0x3B6:
        obj = ForwardInitObject_316460();
        break;
    case 0x3BB:
        obj = ForwardInitObject_3164D0();
        break;
    case 0x3BD:
        obj = ForwardInitObject_3165B0();
        break;
    case 0x3BE:
        obj = ForwardInitObject_316620();
        break;
    case 0x3BF:
        obj = ForwardInitObject_316690();
        break;
    case 0x3E4:
        obj = ForwardInitObject_316700();
        break;
    case 0x3E5:
        obj = ForwardInitObject_316700();
        break;
    case 0x3E6:
        obj = ForwardInitObject_316700();
        break;
    case 0x3E7:
        obj = ForwardInitObject_316700();
        break;
    case 0x3E8:
        obj = ForwardInitObject_316700();
        break;
    case 0x3E9:
        obj = ForwardInitObject_316770();
        break;
    case 0x3EA:
        obj = ForwardInitObject_3167E0();
        break;
    case 0x3EB:
        obj = ForwardInitObject_316850();
        break;
    case 0x3BC:
        obj = ForwardInitObject_316540();
        break;
    case 0x3C0:
        obj = ForwardInitObject_316540();
        break;
    case 0x3C1:
        obj = ForwardInitObject_316540();
        break;
    case 0x3C2:
        obj = ForwardInitObject_316540();
        break;
    case 0x3C3:
        obj = ForwardInitObject_316540();
        break;
    case 0x3C4:
        obj = ForwardInitObject_316540();
        break;
    case 0x3C5:
        obj = ForwardInitObject_316540();
        break;
    case 0x3C8:
        obj = ForwardInitObject_316540();
        break;
    case 0x3C9:
        obj = ForwardInitObject_316540();
        break;
    case 0x3CA:
        obj = ForwardInitObject_316540();
        break;
    case 0x3CB:
        obj = ForwardInitObject_316540();
        break;
    case 0x3CC:
        obj = ForwardInitObject_316540();
        break;
    case 0x3CD:
        obj = ForwardInitObject_316540();
        break;
    case 0x3CE:
        obj = ForwardInitObject_316540();
        break;
    case 0x3CF:
        obj = ForwardInitObject_316540();
        break;
    case 0x3D0:
        obj = ForwardInitObject_316540();
        break;
    case 0x3D1:
        obj = ForwardInitObject_316540();
        break;
    case 0x3D2:
        obj = ForwardInitObject_316540();
        break;
    case 0x3D3:
        obj = ForwardInitObject_316540();
        break;
    case 0x3D4:
        obj = ForwardInitObject_316540();
        break;
    case 0x3D5:
        obj = ForwardInitObject_316540();
        break;
    case 0x3D6:
        obj = ForwardInitObject_316540();
        break;
    case 0x3D7:
        obj = ForwardInitObject_316540();
        break;
    case 0x3D8:
        obj = ForwardInitObject_316540();
        break;
    case 0x3D9:
        obj = ForwardInitObject_316540();
        break;
    case 0x3DA:
        obj = ForwardInitObject_316540();
        break;
    case 0x3DB:
        obj = ForwardInitObject_316540();
        break;
    case 0x3DC:
        obj = ForwardInitObject_316540();
        break;
    case 0x3DD:
        obj = ForwardInitObject_316540();
        break;
    case 0x3DE:
        obj = ForwardInitObject_316540();
        break;
    case 0x3DF:
        obj = ForwardInitObject_316540();
        break;
    case 0x3E0:
        obj = ForwardInitObject_316540();
        break;
    case 0x3E1:
        obj = ForwardInitObject_316540();
        break;
    case 0x3E2:
        obj = ForwardInitObject_316540();
        break;
    case 0x3E3:
        obj = ForwardInitObject_316540();
        break;
    case 0x3EC:
        obj = ForwardInitObject_316540();
        break;
    case 0x3ED:
        obj = ForwardInitObject_316540();
        break;
    case 0x3EE:
        obj = ForwardInitObject_316540();
        break;
    case 0x3EF:
        obj = ForwardInitObject_316540();
        break;
    case 0x3F0:
        obj = ForwardInitObject_316540();
        break;
    case 0x3F1:
        obj = ForwardInitObject_316540();
        break;
    case 0x3F2:
        obj = ForwardInitObject_316540();
        break;
    case 0x3F3:
        obj = ForwardInitObject_316540();
        break;
    case 0x3F4:
        obj = ForwardInitObject_316540();
        break;
    case 0x3F5:
        obj = ForwardInitObject_316540();
        break;
    case 0x3F6:
        obj = ForwardInitObject_316540();
        break;
    case 0x3F7:
        obj = ForwardInitObject_316540();
        break;
    case 0x3F8:
        obj = ForwardInitObject_316540();
        break;
    case 0x3F9:
        obj = ForwardInitObject_316540();
        break;
    case 0x3FA:
        obj = ForwardInitObject_316540();
        break;
    case 0x3FB:
        obj = ForwardInitObject_316540();
        break;
    case 0x3FC:
        obj = ForwardInitObject_316540();
        break;
    case 0x3FD:
        obj = ForwardInitObject_316540();
        break;
    case 0x3FE:
        obj = ForwardInitObject_316540();
        break;
    case 0x3FF:
        obj = ForwardInitObject_316540();
        break;
    case 0x400:
        obj = ForwardInitObject_3168C0();
        break;
    case 0x401:
        obj = ForwardInitObject_316930();
        break;
    case 0x402:
        obj = ForwardInitObject_3169A0();
        break;
    case 0x403:
        obj = ForwardInitObject_316A10();
        break;
    case 0x404:
        obj = AllocZeroedAndForward_316A80();
        break;
    case 0x405:
        obj = AllocZeroedAndForward_316AF0();
        break;
    case 0x406:
        obj = AllocZeroedAndForward_316B60();
        break;
    case 0x407:
        obj = AllocZeroedAndForward_316BD0();
        break;
    case 0x408:
        obj = AllocZeroedAndForward_316C40();
        break;
    case 0x409:
        obj = AllocZeroedAndForward_316CB0();
        break;
    case 0x40A:
        obj = AllocZeroedAndForward_316D20();
        break;
    case 0x40C:
        obj = AllocZeroedAndForward_316D90();
        break;
    case 0x40D:
        obj = AllocZeroedAndForward_316E00();
        break;
    case 0x40E:
        obj = AllocZeroedAndForward_316E70();
        break;
    case 0x410:
        obj = AllocZeroedAndForward_316EE0();
        break;
    case 0x411:
        obj = AllocZeroedAndForward_316F50();
        break;
    case 0x412:
        obj = AllocZeroedAndForward_316FC0();
        break;
    case 0x413:
        obj = AllocZeroedAndForward_317030();
        break;
    case 0x414:
        obj = AllocZeroedAndForward_3170A0();
        break;
    case 0x415:
        obj = AllocZeroedAndForward_317110();
        break;
    case 0x416:
        obj = AllocZeroedAndForward_317180();
        break;
    case 0x417:
        obj = AllocZeroedAndForward_3171F0();
        break;
    case 0x418:
        obj = AllocZeroedAndForward_317260();
        break;
    case 0x419:
        obj = AllocZeroedAndForward_3172D0();
        break;
    case 0x41A:
        obj = AllocZeroedAndForwardInit179D58_317340();
        break;
    case 0x41B:
        obj = AllocAndInit8E0_3173B0();
        break;
    case 0x41C:
        obj = AllocAndInit1DB0_317420();
        break;
    case 0x41D:
        obj = Setup_0x780_17C4A8_317490();
        break;
    case 0x41F:
        obj = AllocAndInit8A0_317500();
        break;
    case 0x420:
        obj = AllocAndInit6B0_317570();
        break;
    case 0x421:
        obj = AllocAndInit680_3175E0();
        break;
    case 0x422:
        obj = AllocInitObj17E0F8_317650();
        break;
    case 0x423:
        obj = AllocInitObj17E828_3176C0();
        break;
    case 0x424:
        obj = AllocInitObj17EA98_317730();
        break;
    case 0x425:
        obj = AllocInitObj17EC08_3177A0();
        break;
    case 0x426:
        obj = AllocInitObj17EE40_317810();
        break;
    case 0x428:
        obj = AllocInitObj17F270_317880();
        break;
    case 0x429:
        obj = AllocInitObj17F4E0_3178F0();
        break;
    case 0x361:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x362:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x363:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x365:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x366:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x367:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x368:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x369:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x36A:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x36B:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x36C:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x36D:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x36E:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x36F:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x370:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x372:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x373:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x374:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x375:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x376:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x377:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x378:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x379:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x37A:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x37B:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x37C:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x37D:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x37E:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x37F:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x380:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x382:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x3A8:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x3A9:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x3AA:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x3AB:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x3AD:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x3AE:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x3AF:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x3B1:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x3B4:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x3B7:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x3B8:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x3B9:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x3BA:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x42A:
        obj = ForwardInit1C9140_316150();
        break;
    case 0x42B:
        obj = AllocInitObj17FB48_317960();
        break;
    case 0x42C:
        obj = AllocInitObj1808E8_3179D0();
        break;
    case 0x42D:
        obj = AllocInitObj181638_317A40();
        break;
    case 0x42E:
        obj = AllocInitObj181838_317AB0();
        break;
    case 0x42F:
        obj = AllocInitObj1825E0_317B20();
        break;
    case 0x430:
        obj = AllocInitObj182888_317B90();
        break;
    case 0x431:
        obj = AllocInitObj183348_317C00();
        break;
    case 0x432:
        obj = AllocInitObj1835A0_317C70();
        break;
    case 0x440:
        obj = AllocInitObj183848_317CE0();
        break;
    case 0x315:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x316:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x321:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x34A:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x34B:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x34C:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x34D:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x34E:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x35B:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x383:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x384:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x385:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x386:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x387:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x388:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x389:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x38A:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x38B:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x38C:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x38D:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x38E:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x38F:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x391:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x392:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x393:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x394:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x395:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x396:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x397:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x398:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x399:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x39A:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x39B:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x39C:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x39D:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x39E:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x39F:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x3A0:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x3A1:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x3A2:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x3A3:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x3A4:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x3A5:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x3AC:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x3C6:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x3C7:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x40B:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x40F:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x41E:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x427:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x433:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x434:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x435:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x436:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x437:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x438:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x439:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x43A:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x43B:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x43C:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x43D:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x43E:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x43F:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x441:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x442:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x443:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x444:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x445:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x446:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x447:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x448:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x449:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x44A:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x44B:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x44C:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x44D:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x44E:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x44F:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x450:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x451:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x452:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x453:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x454:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x455:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x456:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x457:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x458:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x459:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x45A:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x45B:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x45C:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x45D:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x45E:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x45F:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x460:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x461:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x462:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x463:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x464:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x465:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x466:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x467:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x468:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x469:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x46A:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x46B:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x46C:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x46D:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x46E:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x46F:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x470:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x471:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x472:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x473:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x474:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x475:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x476:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x477:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x478:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x479:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x47A:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x47B:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x47C:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x47D:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x47E:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x47F:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x480:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x481:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x482:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x483:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x484:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x485:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x486:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x487:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x488:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x489:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x48A:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x48B:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x48C:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x48D:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x48E:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x48F:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x490:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x491:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x492:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x493:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x494:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x495:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x496:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x497:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x498:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x499:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x49A:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x49B:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x49C:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x49D:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x49E:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x49F:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4A0:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4A1:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4A2:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4A3:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4A4:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4A5:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4A6:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4A7:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4A8:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4A9:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4AA:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4AB:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4AC:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4AD:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4AE:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4AF:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4B0:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4B1:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4B2:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4B3:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4B4:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4B5:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4B6:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4B7:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4B8:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4B9:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4BA:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4BB:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4BC:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4BD:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4BE:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4BF:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4C0:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4C1:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4C2:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4C3:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4C4:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4C5:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4C6:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4C7:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4C8:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4C9:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4CA:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4CB:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4CC:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4CD:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4CE:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4CF:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4D0:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4D1:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4D2:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4D3:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4D4:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4D5:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4D6:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4D7:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4D8:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4D9:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4DA:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4DB:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4DC:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4DD:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4DE:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4DF:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4E0:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4E1:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4E2:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4E3:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4E4:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4E5:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4E6:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4E7:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4E8:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4E9:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4EA:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4EB:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4EC:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4ED:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4EE:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4EF:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4F0:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4F1:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4F2:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4F3:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4F4:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4F5:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4F6:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4F7:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4F8:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4F9:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4FA:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4FB:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4FC:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4FD:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4FE:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x4FF:
        obj = ForwardInitBuffer_314390();
        break;
    case 0x600:
        obj = func_00317D50();
        break;
    case 0x1100:
        obj = CreateObjectWithVtableB();
        break;
    case 0x1200:
        obj = AllocInitObj3184E0_317F00();
        break;
    case 0xFF02:
        obj = CreateObjectWithVtableC();
        break;
    case 0x500:
        obj = CreateObjectWithVtableA();
        break;
    case 0xFF01:
        obj = CreateObjectWithVtableA();
        break;
    default:
        obj = 0;
        break;
    }
    if (obj == 0) {
        return 0;
    }
    obj->unk2FC = D_003C3D18;
    D_003C3D18++;
    cObj_setId(obj, id);
    obj->createId = id;
    if (func_003078E0(id) != -1) {
        d = cDataManager_useDataAddress(&D_005864E0, id);
        if (d != 0) {
            obj->pack = d;
            obj->arena = &D_00754220;
            goto done;
        }
        r = cDataManager_loadWait(&D_00580D20, obj->actorId, &D_00754220, 1);
        obj->arena = &D_00754220;
        obj->pack = r;
        obj->objFlags |= COBJ_F_PACK_LOADED;
        if (r != 0) {
            return obj;
        }
    } else {
        if (id == 0x500) {
            obj->arena = &D_00754240;
            goto done;
        }
        if (!validId(dataId)) {
            return obj;
        }
        d = cDataManager_useDataAddress(&D_005864E0, dataId);
        if (d != 0) {
            obj->pack = d;
            obj->arena = &D_00754220;
            return obj;
        }
    }
    r = cDataManager_loadWait(&D_00580D20, dataId, &D_00754220, 1);
    obj->arena = &D_00754220;
    obj->pack = r;
    obj->objFlags |= COBJ_F_PACK_LOADED;
    if (r == 0) {
        delObj(obj);
        obj = 0;
    }
done: /* returning obj at the two gotos instead is 2 words longer and 70 words off */
    return obj;
}
