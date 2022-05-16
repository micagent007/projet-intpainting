#include <Imagine/Graphics.h>
using namespace Imagine;

#include <cmath>
#include <cstdlib>
#include <ctime>
#include<iostream>
using namespace std;
#include <Imagine/Images.h>
#include "cord.h"

cord operator+(cord a , cord b ) {  // Sum
    cord V={a.x+b.x,a.y+b.y};
    return V;
}
cord operator-(cord a , cord b ) { // Difference
    cord V={a.x-b.x,a.y-b.y};
    return V;
}
double norm2 ( cord a ) {   // Euclide an norm
    double N=sqrt(pow(a.x,2)+pow(a.y,2));
    return N;
}
double norminf(cord a){
    return max(abs(a.x),abs(a.y));
}
cord operator*(cord a , int lambda) {  // Mult . scalar
    cord V={lambda*a.x,lambda*a.y};
    return V;
}
cord operator*( double lambda , cord a ) { // Mult . scalar
    return (operator*(a,lambda));
}
double scalar(cord u, cord v){
    return (u.x*v.x+u.y*v.y);
}
double angle(cord v , cord u){
    double S=v.x*u.y-v.y*u.x;
    if (S>=0)
            return(acos(scalar(u,v)*1/(norm2(u)*norm2(v))));
    return(-acos(scalar(u,v)/(norm2(u)*norm2(v))));
}
bool in(std::vector <cord> ListePoint,cord P){
    double s=0;
    for (int k=0;k<ListePoint.size()-1;k++){
        cord O=ListePoint[k];
        cord Q=ListePoint[k+1];
        s+=angle(O-P,Q-P);
    }
    cord O=ListePoint[ListePoint.size()-1];
    cord Q=ListePoint[0];
    s+=angle(O-P,Q-P);
    if ((2*M_PI-s)<1e-10)
        return(true);

    return(false);
}
bool autour_blanc(cord P,int W, int H,byte* r, byte* g, byte* b){
    int s=0;
    for (int k=-1;k<2;k++)
        for (int j=-1;j<2;j++){
            if(j!=0 or k!=0)
                if (r[P.x+k+(P.y+j)*W]==255 and g[P.x+k+(P.y+j)*W]==255 and b[P.x+k+(P.y+j)*W]==255)
                    s+=1;
        }
    if (s==8)
        return(true);
    return false;
}
void Espace_blanc_compar_blanc(int W, int H,vector <cord> ListePoint ,byte* r, byte* g, byte* b,Image<bool> TablIn){
    for (int x=0;x<W;x++)
        for (int y=0;y<H;y++){
            cord P={x,y};
            if (in(ListePoint,P) ){
                r[x+y*W]=255,
                        g[x+y*W]=255,
                        b[x+y*W]=255,
                        TablIn(x,y)=true;

            }
            else{TablIn(x,y)=false;}
        }
    for (int x=0;x<W;x++)
        for (int y=0;y<H;y++){
            cord P={x,y};
            if (autour_blanc(P,W,H,r,g,b)){
                r[x+y*W]=255,
                        g[x+y*W]=255,
                        b[x+y*W]=255,
                        TablIn(x,y)=true;

            }
        }
}
