#include "sculptor.h"
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iostream>
using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx; ny = _ny; nz = _nz;

    v = new Voxel **[nx];
    for(int i=0; i<nx; i++){
        v[i] = new Voxel *[ny];
        for(int j=0; j<ny; j++){
            v[i][j] = new Voxel [nz];
            for(int k=0; k<nz; k++){
                v[i][j][k].isOn = false;
            }
        }
    }

}

Sculptor::~Sculptor(){
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            delete [] v[i][j];
        }
    }
    for(int i=0; i<nx; i++){
        delete [] v[i];
    }
    //delete [] **v;
    //delete [] *v;
    delete [] v;
}

void Sculptor::setColor(float r, float g, float b, float alpha){
    this->r = r; this->g = g; this->b = b; a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].isOn = true;
    v[x][y][z].r = r; v[x][y][z].g = g; v[x][y][z].b = b; v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}

void Sculptor::writeOFF(char *filename){

    int Nvoxels = 0; //contador para o número de voxels

    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(v[i][j][k].isOn == true){
                    Nvoxels++;
                }
            }
        }
    }

    ofstream arquivo;
    arquivo.open(filename);
    if(!arquivo.is_open()){
        cout << "fail" << endl;
        exit(0);
    }

    arquivo << "OFF\n";
    arquivo << 8*Nvoxels << " " << 6*Nvoxels << " 0\n";

    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(v[i][j][k].isOn == true){
                    arquivo << i-0.5 << " " << j+0.5 << " " << k-0.5 << "\n";
                    arquivo << i-0.5 << " " << j-0.5 << " " << k-0.5 << "\n";
                    arquivo << i+0.5 << " " << j-0.5 << " " << k-0.5 << "\n";
                    arquivo << i+0.5 << " " << j+0.5 << " " << k-0.5 << "\n";
                    arquivo << i-0.5 << " " << j+0.5 << " " << k+0.5 << "\n";
                    arquivo << i-0.5 << " " << j-0.5 << " " << k+0.5 << "\n";
                    arquivo << i+0.5 << " " << j-0.5 << " " << k+0.5 << "\n";
                    arquivo << i+0.5 << " " << j+0.5 << " " << k+0.5 << "\n";
                }
            }
        }
    }

    Nvoxels = 0;
    arquivo.precision(2);
    arquivo << fixed;

    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                if(v[i][j][k].isOn == true){

                    arquivo << "4 " << 8*Nvoxels << " " << 3 + 8*Nvoxels << " " << 2 + 8*Nvoxels
                    << " " << 1 + 8*Nvoxels << " " << v[i][j][k].r << " " << v[i][j][k].g << " " <<
                    v[i][j][k].b << " " << v[i][j][k].a << "\n";

                    arquivo << "4 " << 4 + 8*Nvoxels << " " << 5 + 8*Nvoxels << " " << 6 + 8*Nvoxels
                    << " " << 7 + 8*Nvoxels << " " << v[i][j][k].r << " " << v[i][j][k].g << " " <<
                    v[i][j][k].b << " " << v[i][j][k].a << "\n";

                    arquivo << "4 " << 8*Nvoxels << " " << 1 + 8*Nvoxels << " " << 5 + 8*Nvoxels
                    << " " << 4 + 8*Nvoxels << " " << v[i][j][k].r << " " << v[i][j][k].g << " " <<
                    v[i][j][k].b << " " << v[i][j][k].a << "\n";

                    arquivo << "4 " << 8*Nvoxels << " " << 4 + 8*Nvoxels << " " << 7 + 8*Nvoxels
                    << " " << 3 + 8*Nvoxels << " " << v[i][j][k].r << " " << v[i][j][k].g << " " <<
                    v[i][j][k].b << " " << v[i][j][k].a << "\n";

                    arquivo << "4 " << 3 + 8*Nvoxels << " " << 7 + 8*Nvoxels << " " << 6 + 8*Nvoxels
                    << " " << 2 + 8*Nvoxels << " " << v[i][j][k].r << " " << v[i][j][k].g << " " <<
                    v[i][j][k].b << " " << v[i][j][k].a << "\n";

                    arquivo << "4 " << 1 + 8*Nvoxels << " " << 2 + 8*Nvoxels << " " << 6 + 8*Nvoxels
                    << " " << 5 + 8*Nvoxels << " " << v[i][j][k].r << " " << v[i][j][k].g << " " <<
                    v[i][j][k].b << " " << v[i][j][k].a << "\n";

                    Nvoxels++;
                }
            }
        }
    }

    arquivo.close();
}
