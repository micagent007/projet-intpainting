#ifndef PRIORITE_H
#define PRIORITE_H

#include<vector>
#include "pixel_bord.h"


class FilePriorite {
    std::vector<pixel_bord> v;
public:
    FilePriorite(); //
    bool empty(); //
    void push(pixel_bord p); //
    pixel_bord pop(); //
    pixel_bord extract(int empl_fp);
};

#endif // PRIORITE_H
