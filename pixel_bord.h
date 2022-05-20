#ifndef PIXEL_BORD_H
#define PIXEL_BORD_H
#include "cord.h"
class pixel_bord{
public:
    double priorite;
    cord P;

    pixel_bord(int I,int J);

    bool operator<(pixel_bord p) const {
        return (priorite<p.priorite);
    }
    bool operator>(pixel_bord p) const {
        return (priorite>p.priorite);
    }
    void operator=(const pixel_bord &p);
};



#endif // PIXEL_BORD_H
