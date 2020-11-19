#include <iostream>
#include <sculptor.h>
using namespace std;

int main(){

    Sculptor arq(31,31,31);

    arq.setColor(0, 0, 1, 1); //azul
    arq.putBox(0, 30, 0, 30, 0, 5); //oceano

    arq.setColor(0, 1, 0, 1); //verde
    arq.putBox(10, 30, 10, 30, 5, 5); //grama
    arq.putSphere(15, 15, 21, 5); //folhas

    arq.setColor(1, 0, 0, 1); //vermelho
    arq.putBox(20, 30, 20, 30, 5, 16); //casa
    arq.cutBox(21, 29, 21, 29, 6, 15); //parte de dentro
    arq.cutSphere(25, 25, 16, 3); //buraco no telhado
    arq.cutSphere(20, 25, 10, 3); //buraco na parede
    arq.cutSphere(30, 25, 10, 3); //buraco na parede

    arq.setColor(1, 1, 0, 1); //amarelo
    arq.putEllipsoid(25, 15, 8, 5, 3, 4); //barco
    arq.cutEllipsoid(25, 15, 10, 6, 3, 4);

    arq.setColor(0.6, 0.3, 0, 1); //marrom
    arq.putBox(10, 30, 10, 30, 0, 4); //chão
    arq.putBox(15, 16, 15, 16, 5, 20); //árvore
    arq.putBox(25, 26, 20, 20, 6, 10); //porta

    arq.setColor(0, 0.4, 0.7, 1); //azul claro
    arq.putEllipsoid(10, 5, 4, 10, 4, 4); //baleia

    arq.setColor(0, 0, 0, 1); //preto
    arq.putVoxel(14,3,7); //olho
    arq.putVoxel(14,7,7); //olho
    arq.cutVoxel(11,5,7);

    arq.writeOFF((char*)"teste.off");

    cout << "Done" << endl;

    return 0;
}
