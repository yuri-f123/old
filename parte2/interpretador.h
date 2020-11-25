#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include <vector>
#include <string>
#include "figurageometrica.h"

class Interpretador{
    int dimx, dimy, dimz;
    float r, g, b, a;
public:
    Interpretador();
    int getDimx();
    int getDimy();
    int getDimz();
    std::vector<FiguraGeometrica *> parse(std::string filename);
};

#endif // INTERPRETADOR_H
