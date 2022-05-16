#include "pixel_bord.h"
#include "cord.h"
pixel_bord::pixel_bord(int I,int J){
    P.x=I; P.y=J; *emplacement_fp=0; *emplacement_liste=-1; priorite=0;
}
void pixel_bord::operator=(const pixel_bord &p){
    delete emplacement_fp;
    delete emplacement_liste;
    emplacement_fp=p.emplacement_fp;
    emplacement_liste=p.emplacement_liste;
    P=p.P;
    priorite=p.priorite;
}
void pixel_bord::delet(){
    delete emplacement_fp;
    delete emplacement_liste;
}
