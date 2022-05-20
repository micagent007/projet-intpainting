#ifndef SIMON_H
#define SIMON_H

#include <Imagine/Graphics.h>
#include <Imagine/Images.h>
#include<cmath>
using namespace Imagine;
#include <iostream>
using namespace std;
#include <vector>
#include "cord.h"
#include "pixel_bord.h"
void points_bord(int W, int H, byte* r, byte* g, byte* b,std::vector <cord> ListeSommets, std::vector <cord> ListePointsBord);
void ajout_point_bord(int x1, int y1, int x2, int y2, std::vector <cord> & ListePointsBord);
void pointsbord(std::vector <pixel_bord> & ListeBord, std::vector <cord> ListeSommets);
void point_bord_w_omega(int W, int H,Image<double> TableIn,std::vector <pixel_bord> & ListepixelBord);
void test_points_bord(std::vector <pixel_bord> & ListePointsBord);

#endif // SIMON_H
