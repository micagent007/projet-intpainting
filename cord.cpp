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
