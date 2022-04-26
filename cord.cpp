#include <Imagine/Graphics.h>
using namespace Imagine;

#include <cmath>
#include <cstdlib>
#include <ctime>
#include<iostream>
using namespace std;

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
    if ((2*M_PI-s)<1e-5)
        return(true);

    return(false);
}
