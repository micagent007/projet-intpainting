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
#include "micka.h"

const int carre = 0;
const int cercle = 1;

const int type_p=0;
const int siz=5;

std::vector<cord> calc_patch(int type_patch,cord p,int w,int h,int size);


double calcul_conf(std::vector<cord> patch,Image<double> conf);

std::vector<double> Listconf(std::vector<pixel_bord> pix,Image<double> conf);// dans le rapport

FilePriorite prio(std::vector<pixel_bord> pix, std::vector<double> Listconf, std::vector<double> ListD);// dans le rapport

double distance(cord p,cord q,Image<double> conf, byte* r, byte* g,byte* b);

cord_double grad_rev(cord p, Image<double> conf, Image<byte> grey);


#endif // MARIUS_H
