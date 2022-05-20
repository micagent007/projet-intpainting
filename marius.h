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

const int carre = 0;
const int cercle = 1;

const int type_p=0;
const int siz=4;

std::vector<cord> calc_patch(int type_patch,cord p,int w,int h,int size);


void calcul_conf(cord p,std::vector<cord> patch,Image<double> conf);

FilePriorite prio(std::vector<pixel_bord> pix, Image<double> conf, std::vector<double> grad);

double distance(cord p,cord q,Image<double> conf, byte* r, byte* g,byte* b);




#endif // MARIUS_H
