#include "putsphere.h"
#include "sculptor.h"
#include <cmath>
#include "figurageometrica.h"

PutSphere::PutSphere(int x, int y, int z, int raio, float r, float g, float b, float a){
    this->x=x; this->y=y; this->z=z; this->raio=raio;
    this->r=r; this->g=g; this->b=b; this->a=a;
}

PutSphere::~PutSphere(){

}

void PutSphere::draw(Sculptor &t){

    t.setColor(r, g, b, a);
    for(int i=(x-raio); i<(x+raio); i++){
        for(int j=(y-raio); j<(y+raio); j++){
            for(int k=(z-raio); k<(z+raio); k++){
                if(pow((i-x),2) + pow((j-y),2) + pow((k-z),2) <= pow(raio,2)){
                    t.putVoxel(i,j,k);
                }
            }
        }
    }
}
