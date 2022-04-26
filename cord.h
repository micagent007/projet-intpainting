#ifndef cord_H
#define cord_H

#pragma
#include <vector>
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
#endif // cord_H
