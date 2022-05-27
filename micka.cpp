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
        G.x=double(gradient(I,Coords<2>(pixels[i].x,pixels[i].y)).x());
        G.y=double(gradient(I,Coords<2>(pixels[i].x,pixels[i].y)).y());
        if(G.norm2()>grad.norm2())
            grad=G;
    }
    return grad;
}

std::vector <cord_double> liste_grad(const Image<byte>& I,std::vector <pixel_bord> liste_pixel_bord,int type_patch){
    std::vector <cord_double> grad_liste;
    for(int i=0;i<liste_pixel_bord.size();i++){
        grad_liste.push_back(grad(I,liste_pixel_bord,type_patch,i));
    }
    return grad_liste;
}

void ordre(std::vector <cord> pixels){
    swap(pixels[5],pixels[3]);
    swap(pixels[8],pixels[4]);
    swap(pixels[5],pixels[7]);
    return;
}


std::vector <cord_double> normal(std::vector <pixel_bord> liste_pixel_bord,const Image<byte>& I,const Image<double>& confiance){
    int n=liste_pixel_bord.size();
    cord_double p_avant(0,0),p_apres(0,0);
    std::vector <cord_double> N;
    for(int i=0;i<n;i++){
        std::vector <cord> pixels = calc_patch(carre,liste_pixel_bord[i].P,I.width(),I.height(),1);
        ordre(pixels);
        int indice_deb=INFINITY,indice_fin=0;
        std::vector <cord> pixels_interieur;
        for(int k=0;k<pixels.size()-1;k++){
                if(confiance(pixels[k].x,pixels[k].y)==0){
                    if(indice_deb=INFINITY)
                        indice_deb=k;
                    pixels_interieur.push_back(pixels[k]);
                    indice_fin=k;
                }
        }
        if(indice_deb==0){
            p_avant.x=pixels_interieur[7].x,p_avant.y=pixels_interieur[7].y;
            p_apres.x=pixels_interieur[indice_fin+1].x,p_apres.y=pixels_interieur[indice_fin+1].y;
        }
        else if(indice_fin==7){
            p_avant.x=pixels_interieur[indice_deb-1].x,p_avant.y=pixels_interieur[indice_deb-1].y;
            p_apres.x=pixels_interieur[0].x,p_apres.y=pixels_interieur[0].y;
        }
        cord_double tangent=p_apres-p_avant;
        cord_double normale=tangent.rotation(M_PI/2);
        N.push_back(normale);
    }
    return N;
}

double priority_D_pixel(const Image<byte>& I,std::vector <pixel_bord> liste_pixel_bord, int numero_pixel,std::vector <cord_double> Grad,std::vector <cord_double> Normale){
    assert(numero_pixel<liste_pixel_bord.size());
    cord_double V=Grad[numero_pixel];
    V.rotation(M_PI/2);
    return abs(V*Normale[numero_pixel])/255;
}

std::vector <double> priority_D(const Image<byte>& I,std::vector <pixel_bord> liste_pixel_bord,std::vector <cord_double> Grad,std::vector <cord_double> Normale){
    std::vector<double> D;
    for(int i=0;i<liste_pixel_bord.size();i++){
        D.push_back(priority_D_pixel(I,liste_pixel_bord,i,Grad,Normale));
    }
    return D;
}

std::vector <double> liste_D(const Image<byte>& I,std::vector <pixel_bord> liste_pixel_bord,int type_patch,const Image<double>& confiance){
    return priority_D(I,liste_pixel_bord,liste_grad(I,liste_pixel_bord,type_patch),normal(liste_pixel_bord,I,confiance));
}
