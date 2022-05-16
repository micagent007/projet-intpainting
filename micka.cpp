#include <Imagine/Graphics.h>
#include<Imagine/Images.h>
#include<cmath>
using namespace Imagine;
#include <iostream>
using namespace std;
#include <vector>
#include "cord.h"


void gradient(const Image<float>& I, Image<float>& Vx, Image<float>& Vy) {
    Vx = Image<float>(I.width(), I.height());
    Vy = Image<float>(I.width(), I.height());
    for(int i=0;i<I.width();i++){
        for(int j=0;j<I.height();j++){
            FVector<float,2> Grad = gradient(I,Coords<2>(i,j));
            Vx(i,j)=Grad.x();
            Vy(i,j)=Grad.y();
        }
    }
}

void orthogonal(){

}
