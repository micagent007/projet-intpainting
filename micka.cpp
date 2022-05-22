#include <Imagine/Graphics.h>
#include<Imagine/Images.h>
#include<cmath>
using namespace Imagine;
#include <iostream>
using namespace std;
#include <vector>
#include "micka.h"
#include "marius.h"
#include "pixel_bord.h"

cord_double::cord_double(double x,double y){
    this->x=x;
    this->y=y;
}

cord_double cord_double::operator*(double lambda) {  // Mult . scalar
    cord_double V(x*lambda,y*lambda);
    return V;
}
cord_double cord_double::operator+(cord_double b ) {  // Sum
    cord_double V={x+b.x,y+b.y};
    return V;
}
cord_double cord_double::operator-(cord_double b ) { // Difference
    cord_double V={x-b.x,y-b.y};
    return V;
}
double cord_double::norm2 () {   // Euclidean norm
    double N=sqrt(pow(x,2)+pow(y,2));
    return N;
}
cord_double operator*( double lambda , cord_double a ) { // Mult . scalar
    return a*lambda;
}
double cord_double::operator*(cord_double v){
    return (x*v.x+y*v.y);
}

cord_double cord_double::rotation(double angle){
    cord_double V(x*cos(angle)-y*sin(angle),x*sin(angle)+y*cos(angle));
    return V;
}


cord_double grad(const Image<byte>& I,std::vector <pixel_bord> liste_pixel_bord,int type_patch, int p) {
    cord_double grad(0,0),G(0,0);
    std::vector <cord> pixels=calc_patch(type_patch,liste_pixel_bord[p].P,I.width(),I.height(),4);
    for(int i=0;i<pixels.size();i++){
        G.x=gradient(I,Coords<2>(pixels[i].x,pixels[i].y)).x();
        G.y=gradient(I,Coords<2>(pixels[i].x,pixels[i].y)).y();
        if(G.norm2()>grad.norm2())
            grad=G;
    }
    return grad;
}

std::vector <cord_double> liste_grad(const Image<byte>& I,std::vector <pixel_bord> liste_pixel_bord,int type_patch){
    std::vector <cord_double> grad_liste;
    for(int i=0;i<liste_pixel_bord.size();i++){
        grad_liste[i]=grad(I,liste_pixel_bord,type_patch,i);
    }
    return grad_liste;
}

std::vector <cord_double> normal(std::vector <pixel_bord> liste_pixel_bord){
    int n=liste_pixel_bord.size();
    std::vector <cord_double> N;

    return N;
}
double priority_D_pixel(const Image<byte>& I,std::vector <pixel_bord> liste_pixel_bord, int numero_pixel,std::vector <cord_double> Grad,std::vector <cord_double> Normale){
    assert(numero_pixel<liste_pixel_bord.size());
    cord_double V=Grad[numero_pixel];

    V.rotation(M_PI/2);
    return V*Normale[numero_pixel]/255;
}


std::vector <double> priority_D(const Image<byte>& I,std::vector <pixel_bord> liste_pixel_bord,std::vector <cord_double> Grad,std::vector <cord_double> Normale){
    std::vector<double> D;
    for(int i=0;i<liste_pixel_bord.size();i++){
        D[i]=priority_D_pixel(I,liste_pixel_bord,i,Grad,Normale);
    }
    return D;
}

std::vector <double> liste_D(const Image<byte>& I,std::vector <pixel_bord> liste_pixel_bord,int type_patch){
    return priority_D(I,liste_pixel_bord,liste_grad(I,liste_pixel_bord,type_patch),normal(liste_pixel_bord));
}
