/* sn-2.95.3-136 matched TU. */

extern int PTR_DAT_003c2f84;
extern unsigned char D_00747A50[];
extern unsigned char D_00747A57;

/* sn-2.95.3-136 matched TU. */





__attribute__((section(".text.func_001633A0")))
void func_001633A0(void *a0) {
    unsigned char sel;
    if (*(unsigned char *)(PTR_DAT_003c2f84 + 0x14) != 0)
        sel = D_00747A57;
    else
        sel = D_00747A50[1];
    switch (sel) {
    case 0:
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x38) = 254.0f;
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x3C) = 289.0f;
        break;
    case 1:
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x38) = 102.0f;
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x3C) = 266.0f;
        break;
    case 2:
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x38) = 167.0f;
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x3C) = 195.0f;
        break;
    case 3:
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x38) = 134.0f;
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x3C) = 92.0f;
        break;
    case 4:
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x38) = 235.0f;
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x3C) = 126.0f;
        break;
    case 5:
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x38) = 320.0f;
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x3C) = 190.0f;
        break;
    case 6:
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x38) = 320.0f;
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x3C) = 88.0f;
        break;
    case 7:
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x38) = 408.0f;
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x3C) = 88.0f;
        break;
    case 8:
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x38) = 455.0f;
        *(float *)(*(int *)((char *)a0 + 0x80) + 0x3C) = 47.0f;
        break;
    }
}
