#include "putvoxel.h"
#include "sculptor.h"
#include "figurageometrica.h"

PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b, float a){

    this->x=x; this->y=y; this->z=z; this->r=r; this->g=g; this->b=b; this->a=a;
}

PutVoxel::~PutVoxel(){

}

void PutVoxel::draw(Sculptor &t){

    t.setColor(r, g, b, a);
    t.putVoxel(x, y, z);
}
