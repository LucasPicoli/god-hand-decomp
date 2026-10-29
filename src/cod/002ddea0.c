/* sn-2.95.3-136 */

/* The character slot (0-7) an em00 actor uses for an enemy number, -1 if it has none. */
__attribute__((section(".text.GetEm00CharIndex")))
int GetEm00CharIndex(int actorId, int emNo)
{
    int idx;

    idx = -1;
    switch (actorId) {
    case 0x200: /* listed in retail: the table starts at 0x200 */
        break;
    case 0x201:
        switch (emNo) {
        case 0x200:
            idx = 0;
            break;
        case 0x201:
            idx = 1;
            break;
        case 0x20C:
            idx = 2;
            break;
        case 0x21A:
            idx = 3;
            break;
        case 0x202:
            idx = 4;
            break;
        }
        break;
    case 0x202:
        switch (emNo) {
        case 0x200:
            idx = 0;
            break;
        case 0x203:
            idx = 1;
            break;
        case 0x20A:
            idx = 2;
            break;
        case 0x20F:
            idx = 3;
            break;
        case 0x202:
            idx = 4;
            break;
        }
        break;
    case 0x203:
        switch (emNo) {
        case 0x250:
            idx = 0;
            break;
        case 0x251:
            idx = 1;
            break;
        case 0x205:
            idx = 2;
            break;
        }
        break;
    case 0x204:
        switch (emNo) {
        case 0x200:
            idx = 0;
            break;
        case 0x203:
            idx = 1;
            break;
        case 0x20A:
            idx = 2;
            break;
        case 0x214:
            idx = 3;
            break;
        case 0x215:
            idx = 4;
            break;
        }
        break;
    case 0x205:
        switch (emNo) {
        case 0x200:
            idx = 0;
            break;
        case 0x21A:
            idx = 1;
            break;
        case 0x20A:
            idx = 2;
            break;
        case 0x20C:
            idx = 3;
            break;
        case 0x202:
            idx = 4;
            break;
        }
        break;
    case 0x206:
        switch (emNo) {
        case 0x21C:
            idx = 0;
            break;
        case 0x208:
            idx = 1;
            break;
        case 0x20B:
            idx = 2;
            break;
        }
        break;
    case 0x207:
        switch (emNo) {
        case 0x205:
            idx = 0;
            break;
        case 0x21B:
            idx = 1;
            break;
        case 0x216:
            idx = 2;
            break;
        case 0x242:
            idx = 3;
            break;
        }
        break;
    case 0x208:
        switch (emNo) {
        case 0x200:
            idx = 0;
            break;
        case 0x202:
            idx = 1;
            break;
        case 0x205:
            idx = 2;
            break;
        case 0x20F:
            idx = 3;
            break;
        case 0x206:
            idx = 4;
            break;
        }
        break;
    case 0x209:
        switch (emNo) {
        case 0x209:
            idx = 0;
            break;
        }
        break;
    case 0x20A:
        switch (emNo) {
        case 0x240:
            idx = 0;
            break;
        case 0x207:
            idx = 1;
            break;
        case 0x248:
            idx = 2;
            break;
        case 0x21D:
            idx = 3;
            break;
        case 0x249:
            idx = 4;
            break;
        }
        break;
    case 0x20B:
        switch (emNo) {
        case 0x200:
            idx = 0;
            break;
        case 0x205:
            idx = 1;
            break;
        case 0x245:
            idx = 2;
            break;
        case 0x21E:
            idx = 3;
            break;
        case 0x204:
            idx = 4;
            break;
        }
        break;
    case 0x20C:
        switch (emNo) {
        case 0x204:
            idx = 0;
            break;
        case 0x205:
            idx = 1;
            break;
        case 0x20C:
            idx = 2;
            break;
        case 0x21A:
            idx = 3;
            break;
        case 0x201:
            idx = 4;
            break;
        }
        break;
    case 0x20D:
        switch (emNo) {
        case 0x201:
            idx = 0;
            break;
        case 0x206:
            idx = 1;
            break;
        case 0x210:
            idx = 2;
            break;
        case 0x225:
            idx = 3;
            break;
        case 0x21A:
            idx = 4;
            break;
        }
        break;
    case 0x20E:
        switch (emNo) {
        case 0x245:
            idx = 0;
            break;
        case 0x216:
            idx = 1;
            break;
        case 0x20A:
            idx = 2;
            break;
        case 0x21B:
            idx = 3;
            break;
        case 0x203:
            idx = 4;
            break;
        }
        break;
    case 0x20F:
        switch (emNo) {
        case 0x21A:
            idx = 0;
            break;
        case 0x249:
            idx = 1;
            break;
        case 0x246:
            idx = 2;
            break;
        case 0x207:
            idx = 3;
            break;
        case 0x241:
            idx = 4;
            break;
        }
        break;
    case 0x210:
        switch (emNo) {
        case 0x21A:
            idx = 0;
            break;
        case 0x248:
            idx = 1;
            break;
        case 0x21D:
            idx = 2;
            break;
        case 0x249:
            idx = 3;
            break;
        }
        break;
    case 0x211:
        switch (emNo) {
        case 0x211:
            idx = 0;
            break;
        case 0x200:
            idx = 1;
            break;
        case 0x203:
            idx = 2;
            break;
        }
        break;
    case 0x213:
        switch (emNo) {
        case 0x214: /* retail's tree has a third slot-0 number above 0x213 */
        default:
            idx = 0;
            break;
        case 0x20E:
            idx = 1;
            break;
        case 0x213:
            idx = 2;
            break;
        }
        break;
    case 0x214:
        switch (emNo) {
        case 0x20A:
            idx = 0;
            break;
        case 0x20C:
            idx = 1;
            break;
        case 0x20D:
            idx = 2;
            break;
        case 0x247:
            idx = 3;
            break;
        }
        break;
    case 0x215:
        switch (emNo) {
        case 0x200:
            idx = 0;
            break;
        case 0x202:
            idx = 1;
            break;
        case 0x205:
            idx = 2;
            break;
        case 0x21A:
            idx = 3;
            break;
        case 0x206:
            idx = 4;
            break;
        }
        break;
    case 0x216:
        switch (emNo) {
        case 0x21D:
            idx = 0;
            break;
        case 0x20D:
            idx = 1;
            break;
        case 0x249:
            idx = 2;
            break;
        case 0x207:
            idx = 3;
            break;
        case 0x21A:
            idx = 4;
            break;
        }
        break;
    case 0x217:
        switch (emNo) {
        case 0x217:
        default:
            idx = 0;
            break;
        case 0x20E:
            idx = 1;
            break;
        case 0x202:
            idx = 2;
            break;
        case 0x203:
            idx = 3;
            break;
        case 0x216:
            idx = 4;
            break;
        }
        break;
    case 0x218:
        switch (emNo) {
        case 0x218:
        default:
            idx = 0;
            break;
        case 0x23A:
            idx = 1;
            break;
        case 0x244:
            idx = 2;
            break;
        }
        break;
    case 0x21A:
        switch (emNo) {
        case 0x242:
            idx = 0;
            break;
        case 0x205:
            idx = 1;
            break;
        case 0x246:
            idx = 2;
            break;
        case 0x21B:
            idx = 3;
            break;
        case 0x216:
            idx = 4;
            break;
        }
        break;
    case 0x21B:
        switch (emNo) {
        case 0x201:
            idx = 0;
            break;
        case 0x245:
            idx = 1;
            break;
        case 0x21B:
            idx = 2;
            break;
        case 0x216:
            idx = 3;
            break;
        }
        break;
    case 0x21C:
        switch (emNo) {
        case 0x201:
            idx = 0;
            break;
        case 0x202:
            idx = 1;
            break;
        case 0x203:
            idx = 2;
            break;
        case 0x248:
            idx = 3;
            break;
        case 0x216:
            idx = 4;
            break;
        }
        break;
    case 0x21D:
        switch (emNo) {
        case 0x203:
            idx = 0;
            break;
        case 0x225:
            idx = 1;
            break;
        case 0x226:
            idx = 2;
            break;
        case 0x224:
            idx = 3;
            break;
        case 0x216:
            idx = 4;
            break;
        }
        break;
    case 0x21E:
        switch (emNo) {
        case 0x24F:
            idx = 0;
            break;
        case 0x225:
            idx = 1;
            break;
        case 0x201:
            idx = 2;
            break;
        case 0x224:
            idx = 3;
            break;
        case 0x20D:
            idx = 4;
            break;
        }
        break;
    case 0x21F:
        switch (emNo) {
        case 0x21F:
            idx = 0;
            break;
        }
        break;
    case 0x220:
        switch (emNo) {
        case 0x220:
            idx = 0;
            break;
        case 0x221:
            idx = 1;
            break;
        case 0x222:
            idx = 2;
            break;
        }
        break;
    case 0x223:
        switch (emNo) {
        case 0x223:
            idx = 0;
            break;
        }
        break;
    case 0x224:
        switch (emNo) {
        case 0x200:
            idx = 0;
            break;
        case 0x210:
            idx = 1;
            break;
        case 0x245:
            idx = 2;
            break;
        case 0x21E:
            idx = 3;
            break;
        case 0x204:
            idx = 4;
            break;
        }
        break;
    case 0x225:
        switch (emNo) {
        case 0x201:
            idx = 0;
            break;
        case 0x206:
            idx = 1;
            break;
        case 0x204:
            idx = 2;
            break;
        case 0x225:
            idx = 3;
            break;
        case 0x21A:
            idx = 4;
            break;
        }
        break;
    case 0x23A:
        switch (emNo) {
        case 0x23A:
        default:
            idx = 0;
            break;
        case 0x242:
            idx = 1;
            break;
        case 0x225:
            idx = 2;
            break;
        case 0x204:
            idx = 3;
            break;
        case 0x247:
            idx = 4;
            break;
        }
        break;
    case 0x23B:
        idx = 0;
        break;
    case 0x240:
        switch (emNo) {
        case 0x240:
            idx = 0;
            break;
        case 0x249:
            idx = 1;
            break;
        case 0x21E:
            idx = 2;
            break;
        case 0x245:
            idx = 3;
            break;
        }
        break;
    case 0x241:
        switch (emNo) {
        case 0x200:
            idx = 0;
            break;
        case 0x201:
            idx = 1;
            break;
        case 0x204:
            idx = 2;
            break;
        case 0x225:
            idx = 3;
            break;
        case 0x247:
            idx = 4;
            break;
        }
        break;
    case 0x242:
        switch (emNo) {
        case 0x201:
            idx = 0;
            break;
        case 0x206:
            idx = 1;
            break;
        case 0x242:
            idx = 2;
            break;
        case 0x225:
            idx = 3;
            break;
        case 0x21A:
            idx = 4;
            break;
        }
        break;
    case 0x243:
        switch (emNo) {
        case 0x247:
            idx = 0;
            break;
        case 0x205:
            idx = 1;
            break;
        case 0x242:
            idx = 2;
            break;
        case 0x21A:
            idx = 3;
            break;
        case 0x20C:
            idx = 4;
            break;
        }
        break;
    case 0x244:
        switch (emNo) {
        case 0x244:
            idx = 0;
            break;
        case 0x23A:
            idx = 1;
            break;
        case 0x21A:
            idx = 2;
            break;
        case 0x21C:
            idx = 3;
            break;
        case 0x24F:
            idx = 4;
            break;
        }
        break;
    case 0x246:
        switch (emNo) {
        case 0x216:
            idx = 0;
            break;
        case 0x205:
            idx = 1;
            break;
        case 0x246:
            idx = 2;
            break;
        case 0x21B:
            idx = 3;
            break;
        }
        break;
    case 0x247:
        switch (emNo) {
        case 0x247:
            idx = 0;
            break;
        case 0x24F:
            idx = 1;
            break;
        }
        break;
    case 0x24F:
        switch (emNo) {
        case 0x20C:
            idx = 0;
            break;
        case 0x24F:
            idx = 1;
            break;
        case 0x240:
            idx = 2;
            break;
        case 0x246:
            idx = 3;
            break;
        case 0x249:
            idx = 4;
            break;
        }
        break;
    case 0x252:
        switch (emNo) {
        case 0x252:
            idx = 0;
            break;
        case 0x204:
            idx = 1;
            break;
        case 0x21E:
            idx = 2;
            break;
        }
        break;
    case 0x256:
        switch (emNo) {
        case 0x256:
            idx = 0;
            break;
        }
        break;
    case 0x258:
        switch (emNo) {
        case 0x256:
            idx = 0;
            break;
        case 0x200:
            idx = 1;
            break;
        }
        break;
    case 0x25A:
        switch (emNo) {
        case 0x25A:
            idx = 0;
            break;
        case 0x25B:
            idx = 1;
            break;
        }
        break;
    case 0x260:
        switch (emNo) {
        case 0x260:
            idx = 0;
            break;
        case 0x250:
            idx = 1;
            break;
        }
        break;
    case 0x264:
        switch (emNo) {
        case 0x264:
            idx = 0;
            break;
        }
        break;
    case 0x265:
        switch (emNo) {
        case 0x265:
            idx = 0;
            break;
        }
        break;
    case 0x26A:
        switch (emNo) {
        case 0x26A:
            idx = 0;
            break;
        }
        break;
    case 0x270:
        switch (emNo) {
        case 0x270:
            idx = 0;
            break;
        case 0x274:
            idx = 1;
            break;
        case 0x20C:
            idx = 2;
            break;
        case 0x202:
            idx = 3;
            break;
        case 0x210:
            idx = 4;
            break;
        }
        break;
    case 0x275:
        switch (emNo) {
        case 0x275:
            idx = 0;
            break;
        }
        break;
    case 0x276:
        switch (emNo) {
        case 0x276:
            idx = 0;
            break;
        case 0x224:
            idx = 1;
            break;
        case 0x226:
            idx = 2;
            break;
        case 0x20F:
            idx = 3;
            break;
        case 0x20D:
            idx = 4;
            break;
        }
        break;
    case 0x278:
        switch (emNo) {
        case 0x278:
            idx = 0;
            break;
        case 0x20F:
            idx = 1;
            break;
        }
        break;
    case 0x279:
        switch (emNo) {
        case 0x279:
            idx = 0;
            break;
        case 0x20F:
            idx = 1;
            break;
        }
        break;
    case 0x27E:
        switch (emNo) {
        case 0x27E:
            idx = 0;
            break;
        }
        break;
    case 0x2A2:
        switch (emNo) {
        case 0x2A2:
            idx = 0;
            break;
        case 0x2A3:
            idx = 1;
            break;
        case 0x2A4:
            idx = 2;
            break;
        }
        break;
    case 0x2A3:
        switch (emNo) {
        case 0x2A7:
            idx = 0;
            break;
        }
        break;
    case 0x2A4:
        switch (emNo) {
        case 0x2A2:
            idx = 0;
            break;
        }
        break;
    case 0x2A5:
        switch (emNo) {
        case 0x2A2:
            idx = 0;
            break;
        case 0x2A3:
            idx = 1;
            break;
        case 0x2A4:
            idx = 2;
            break;
        case 0x2A5:
            idx = 3;
            break;
        case 0x2A6:
            idx = 4;
            break;
        case 0x2A7:
            idx = 5;
            break;
        case 0x2A9:
            idx = 6;
            break;
        case 0x2AB:
            idx = 7;
            break;
        }
        break;
    case 0x2A7:
        switch (emNo) {
        case 0x2A2:
            idx = 0;
            break;
        case 0x2A3:
            idx = 1;
            break;
        case 0x2A5:
            idx = 2;
            break;
        }
        break;
    case 0x2A8:
        switch (emNo) {
        case 0x2A2:
            idx = 0;
            break;
        case 0x2A3:
            idx = 1;
            break;
        case 0x2A6:
            idx = 2;
            break;
        }
        break;
    case 0x2A9:
        switch (emNo) {
        case 0x2A9:
            idx = 0;
            break;
        }
        break;
    }
    return idx;
}
