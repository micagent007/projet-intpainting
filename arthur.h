#ifndef ARTHUR_H
#define ARTHUR_H

#include <Imagine/Graphics.h>
#include<cmath>
using namespace Imagine;
#include <iostream>
using namespace std;
#include <vector>
#include "cord.h"
#include "pixel_bord.h"
#include "micka.h"

void convertGrey(int W,int H, byte* r, byte* g,byte* b, Image<byte> & Image_in_grey );// dans le rapport
void drawclicks(vector <cord>& ListePoint);// dans le rapport
void drawoutline(vector <cord>& ListePoint);
bool in(std::vector <cord> ListePoint,cord P);// dans le rapport
bool autour_blanc(cord P,int W, int H,byte* r, byte* g, byte* b);
void Espace_blanc_compar_blanc(int W, int H,vector <cord> ListePoint ,byte* r, byte* g, byte* b,Image<double> conf);// dans le rapport
cord find_q(int W,int H,pixel_bord p_max,Image<double> conf,byte* r,byte* g,byte* b);// dans le rapport
bool omega_is_empty(int W, int H,Image<double> conf);
void update_conf(cord p,Image<double> conf);
void copy_image_data(cord q, cord p,Image<double> conf,byte* &r,byte* &g,byte* &b);
void copy_image_data_for_gradient_nul(cord p,Image<double> conf,byte* &r,byte* &g,byte* &b);
void main_loop(int W,int H,std::vector <cord> ListePoint,byte* r,byte* g,byte* b);// dans le rapport

#endif // ARTHUR_H
