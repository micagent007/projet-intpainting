#ifndef ARTHUR_H
#define ARTHUR_H

#include <Imagine/Graphics.h>
#include<cmath>
using namespace Imagine;
#include <iostream>
using namespace std;
#include <vector>
#include "cord.h"

void convertGrey(int W,int H, byte* r, byte* g,byte* b, Image<byte> Image_in_grey );
void drawclicks(vector <cord>& ListePoint);
void drawoutline(vector <cord>& ListePoint);
bool in(std::vector <cord> ListePoint,cord P);
bool autour_blanc(cord P,int W, int H,byte* r, byte* g, byte* b);
void Espace_blanc_compar_blanc(int W, int H,vector <cord> ListePoint ,byte* r, byte* g, byte* b,Image<double> conf);
pixel_bord find_q(int W,int H,pixel_bord p_max,Image<double> conf,byte* r,byte* g,byte* b);
bool omega_is_empty(int W, int H,Image<double> conf);
void main_loop(int W,int H,std::vector <cord> ListePoint,byte* r,byte* g,byte* b);

#endif // ARTHUR_H
