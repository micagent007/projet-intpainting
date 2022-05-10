#ifndef cord_H
#define cord_H

#pragma
#include <Imagine/Graphics.h>
using namespace Imagine;

#include <cmath>
#include <cstdlib>
#include <ctime>
#include<iostream>
using namespace std;

struct cord{
    int x,y;
};

cord operator+(cord a , cord b ) ; // Sum
cord operator-(cord a , cord b ) ; // Difference
double norm2 ( cord a ) ; // Euclide an norm
cord operator*(cord a , int lambda) ; // Mult . scalar
cord operator*( double lambda , cord a ) ;// Mult . scalar
double scalar(cord u, cord v);
double angle(cord v , cord u);// retourne l'angle entre v et u
bool in(std::vector <cord> ListePoint,cord P);
bool autour_blanc(cord P,int W, int H,byte* r, byte* g, byte* b);
void Espace_blanc_compar_blanc(int W, int H,vector <cord> ListePoint ,byte* r, byte* g, byte* b,bool* TablIn);
#endif // cord_H
