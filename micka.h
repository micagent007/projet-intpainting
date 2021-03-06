#ifndef MICKA_H
#define MICKA_H

#include <Imagine/Graphics.h>
#include<cmath>
using namespace Imagine;
#include <iostream>
using namespace std;
#include <vector>
#include "cord.h"
#include "pixel_bord.h"

class cord_double{

public:
    double x,y;
    cord_double(double x,double y);

    cord_double operator+(cord_double b) ; // Sum
    cord_double operator-(cord_double b) ; // Difference
    double norm2 () ; // Euclidean norm
    cord_double operator*(double lambda) ; // Mult . scalar
    double operator*(cord_double v);
    cord_double rotation(double angle);
    void normalize();
};

cord_double operator*(double lambda,cord_double b);
std::vector <cord_double> normal(std::vector <pixel_bord> liste_pixel_bord,const Image<byte>& I,const Image<double>& confiance);
cord_double grad(const Image<byte>& I,std::vector <pixel_bord> liste_pixel_bord,int p,const Image<double>& confiance);
std::vector <cord_double> liste_grad(const Image<byte>& I,std::vector <pixel_bord> liste_pixel_bord,const Image<double>& confiance);
double priority_D_pixel(const Image<double>& I,std::vector <pixel_bord> liste_pixel_bord, int numero_pixel,std::vector <cord_double> Grad,std::vector <cord_double> Normale);
std::vector <double> priority_D(const Image<double>& I,std::vector <pixel_bord> liste_pixel_bord,std::vector <cord_double> Grad,std::vector <cord_double> Normale);
std::vector <double> liste_D(const Image<byte>& I,std::vector <pixel_bord> liste_pixel_bord,const Image<double>& confiance);// dans le rapport
void ordre(std::vector <cord> pixels);

#endif // MICKA_H
