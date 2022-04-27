#ifndef PIXEL_BORD_H
#define PIXEL_BORD_H
#include "cord.h"
class pixel_bord{
public:
    double priorite;
    int emplacement_fp;
    cord P;
    int emplacement_liste;

    pixel_bord(int I,int J);

    bool operator<(pixel_bord p) const {
        return (priorite<p.priorite);
    }
    bool operator>(pixel_bord p) const {
        return (priorite>p.priorite);
    }

};



#endif // PIXEL_BORD_H
