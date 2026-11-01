/* cygnus-2.96 matched TU. */
typedef struct {
    int chromaU;
    int chromaV;
    int luma;
    short chromaPitch;
    short lumaPitch;
} SfdYccPlane;

typedef struct {
    int plane[3];
    int pitch[3];
} MovieYccPlane;

/* Convert the SFD plane description to the movie player's Y/U/V layout. */
__attribute__((section(".text.func_00344E58")))
void func_00344E58(SfdYccPlane *source, volatile MovieYccPlane *destination)
{
    short chromaPitch = source->chromaPitch;
    short lumaPitch;
    int chroma;
    destination->plane[0] = source->luma;
    lumaPitch = source->lumaPitch;
    chroma = source->chromaU;
    destination->pitch[2] = chromaPitch;
    destination->plane[1] = chroma;
    destination->pitch[0] = lumaPitch;
    chroma = source->chromaV;
    destination->pitch[1] = chromaPitch;
    destination->plane[2] = chroma;
}
