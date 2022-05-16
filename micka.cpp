#include <Imagine/Graphics.h>
#include<Imagine/Images.h>
#include<cmath>
using namespace Imagine;
#include <iostream>
using namespace std;
#include <vector>
#include "micka.h"
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

std::vector <cord_double> grad(const Image<double>& I,std::vector <pixel_bord> liste_pixel_bord) {
    std::vector <cord_double> grad;
    for(int i=0;i<liste_pixel_bord.size() ;i++){
        grad[i].x=gradient(I,Coords<2>(liste_pixel_bord[i].P.x,liste_pixel_bord[i].P.y)).x();
        grad[i].y=gradient(I,Coords<2>(liste_pixel_bord[i].P.x,liste_pixel_bord[i].P.y)).y();
        }
    return grad;
}

std::vector <cord_double> normal(std::vector <pixel_bord> liste_pixel_bord){
    //à modifier, il faut prendre en compte le cas où l'intèrieur n'est pas connexe
    int n=liste_pixel_bord.size();
    std::vector <cord_double> N;
    cord_double A(0,0),B(0,0);
    for(int i=1;i<=n;i++){
        A.x=liste_pixel_bord[(i-1)%n].P.x;
        A.y=liste_pixel_bord[(i-1)%n].P.y;
        B.x=liste_pixel_bord[(i+1)%n].P.x;
        B.y=liste_pixel_bord[(i+1)%n].P.y;
        N[i%liste_pixel_bord.size()];
    }
}

double priority_grad(const Image<double>& I,std::vector <pixel_bord> liste_pixel_bord, int n,std::vector <cord_double> Grad){
    assert(n<liste_pixel_bord.size());
    cord_double V=Grad[n];
    V.rotation(M_PI/2);
    cord_double N=normal(liste_pixel_bord,n);
    return V*N;
}
