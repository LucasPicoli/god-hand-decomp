/* sn-2.95.3-136 matched TU. */

/* Build a transform in place: reset the translation, apply the rotation, then the scale. */
extern void MtxInitTransVec(void *a0);
extern void BuildMatrixAndForward_147BB0(void *a0, void *a1, int a2);
extern void MtxMulScaleVec(void *a0, void *a1, int a2);

__attribute__((section(".text.MtxBuildTransRotScale")))
void MtxBuildTransRotScale(void *a0, int a1, int a2, int a3)
{
    MtxInitTransVec(a0);
    BuildMatrixAndForward_147BB0(a0, a0, a2);
    MtxMulScaleVec(a0, a0, a3);
}
