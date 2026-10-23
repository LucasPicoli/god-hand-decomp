/* sn-2.95.3-136 */
#include "godhand/cGrid.h"

/* Set the query box and find the range of cells it covers; 0 if none. */
__attribute__((section(".text.func_0012F288")))
int func_0012F288(cGrid *self, cVec *boxMin, cVec *boxMax)
{
    cVec_copy3(&self->boxMin, boxMin);
    cVec_copy3(&self->boxMax, boxMax);
    func_00133948(self, &self->boxMin, &self->boxMax);
    if (!func_00133408(self, &self->min.x, &self->max.x, &self->boxMin.x, &self->boxMax.x)) {
        return 0;
    }
    self->lo[0] = (self->boxMin.x - self->min.x) / self->cell.x;
    self->lo[1] = (self->boxMin.y - self->min.y) / self->cell.y;
    self->lo[2] = (self->boxMin.z - self->min.z) / self->cell.z;
    if (self->lo[0] < 0) {
        self->lo[0] = 0;
    }
    if (self->lo[1] < 0) {
        self->lo[1] = 0;
    }
    if (self->lo[2] < 0) {
        self->lo[2] = 0;
    }
    if (self->lo[0] >= self->num[0] || self->lo[1] >= self->num[1] || self->lo[2] >= self->num[2]) {
        return 0;
    }
    self->hi[0] = (self->boxMax.x - self->min.x) / self->cell.x;
    self->hi[1] = (self->boxMax.y - self->min.y) / self->cell.y;
    self->hi[2] = (self->boxMax.z - self->min.z) / self->cell.z;
    if (self->hi[0] > self->num[0] - 1) {
        self->hi[0] = self->num[0] - 1;
    }
    if (self->hi[1] > self->num[1] - 1) {
        self->hi[1] = self->num[1] - 1;
    }
    if (self->hi[2] > self->num[2] - 1) {
        self->hi[2] = self->num[2] - 1;
    }
    if (self->hi[0] < 0 || self->hi[1] < 0 || self->hi[2] < 0) {
        return 0;
    }
    return 1;
}
