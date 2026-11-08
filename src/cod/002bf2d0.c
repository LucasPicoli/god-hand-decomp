/* sn-2.95.3-136 matched TU. */

extern void func_002BF380(void);
extern int D_00747A88;
extern void Set_bg_mode(int, int, int, int);
extern void ScenarioCursor_runStep(char *);
extern void StepRec_runKindHandler(char *);
extern void func_002BF540(char *);
extern void ScenarioStep_runJumpKind(char *);

__attribute__((section(".text.func_002BF2D0")))
void func_002BF2D0(char *obj)
{
    func_002BF380();
    if (D_00747A88 & 0x40000000) {
        Set_bg_mode(1, 0, 0, 0);
        switch (*obj) {
        case 2:
            ScenarioCursor_runStep(obj);
            break;
        case 3:
            StepRec_runKindHandler(obj);
            break;
        case 4:
            func_002BF540(obj);
            break;
        case 5:
            ScenarioStep_runJumpKind(obj);
            break;
        case 0:
        default:
            break;
        }
    }
}
