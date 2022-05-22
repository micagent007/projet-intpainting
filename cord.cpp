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
