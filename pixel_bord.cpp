#include "pixel_bord.h"
#include "cord.h"
pixel_bord::pixel_bord(int I,int J,double Prio){
    P.x=I; P.y=J; priorite=Prio;
}
void pixel_bord::operator=(const pixel_bord &p){
    P=p.P;
    priorite=p.priorite;
}

