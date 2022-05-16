#ifndef SIMON_H
#define SIMON_H

#include <Imagine/Graphics.h>
#include<cmath>
using namespace Imagine;
#include <iostream>
using namespace std;
#include <vector>
#include "cord.h"

void ajout_point_bord(int x1, int y1, int x2, int y2, std::vector <cord> & ListePointsBord);
void pointsbords(std::vector <cord> & ListePointsBord,std::vector <cord> ListeSommets);
void test_points_bord(std::vector <cord> & ListePointsBord);
#endif // SIMON_H
