#ifndef MARIUS_H
#define MARIUS_H

#include <Imagine/Graphics.h>
#include<cmath>
using namespace Imagine;
#include <iostream>
using namespace std;
#include <vector>
#include <Imagine/Images.h>
#include "cord.h"
#include "pixel_bord.h"
#include "priorite.h"


std::vector<cord> calc_patch(int type_patch,cord p,Image<double> I)


void calcul_conf(cord p,std::vector<cord> patch,Image<double> conf);

void calc_prio(std::vector<pixel_bord> pix,Image<double> conf,std::vector<double> grad,FilePriorite F,int i);
FilePriorite init_prio(std::vector<pixel_bord> pix, Image<double> conf, std::vector<double> grad);
#endif // MARIUS_H
