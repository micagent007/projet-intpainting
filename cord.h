#ifndef cord_H
#define cord_H

#pragma
struct cord{
    int x,y;
};

cord operator+(cord a , cord b ) ; // Sum
cord operator-(cord a , cord b ) ; // Difference
double norm2 ( cord a ) ; // Euclide an norm
cord operator*(cord a , int lambda) ; // Mult . scalar
cord operator*( double lambda , cord a ) ;// Mult . scalar
#endif // cord_H
