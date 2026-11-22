/* cygnus-2.96 matched TU.
 *
 * The `0.8` double literal is loaded from the split rodata blob at
 * D_00458140 (vaddr 0x458140) via extern_double: cygnus emits a `li.d`
 * whose TU-local .rodata copy is retargeted to the blob symbol so the
 * bytes stay byte-identical to retail. See compile_config
 * compile_units[].extern_double and scripts/ee-cc-wrap.py
 * _externalize_fp_literals.
 */

extern int MWSFD_SetFlowLimit(void *a0, int a1, int a2);

__attribute__((section(".text.MWSFPLY_SetFlowLimit")))
int MWSFPLY_SetFlowLimit(char *a0)
{
    int s1 = *(int *)(a0 + 0x1C8);
    return MWSFD_SetFlowLimit(a0, (int)((double)s1 * 0.8), s1);
}
