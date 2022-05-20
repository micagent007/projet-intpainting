#include "pixel_bord.h"
#include "cord.h"
pixel_bord::pixel_bord(int I,int J){
    P.x=I; P.y=J; priorite=0;
}
void pixel_bord::operator=(const pixel_bord &p){
    P=p.P;
    priorite=p.priorite;
}

