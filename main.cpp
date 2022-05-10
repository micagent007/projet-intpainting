#include <Imagine/Graphics.h>
#include<cmath>
using namespace Imagine;
#include <iostream>
using namespace std;
#include <vector>
#include "cord.h"
#include "arthur.h"




int main(){
    int W=512,
            H=512;
    byte* r;
    byte* g;
    byte* b;

    loadColorImage(srcPath("Capture1.PNG"),r,g,b,W,H);
    openWindow(W,H);
    putColorImage(0,0,r,g,b,W,H);


    std::vector <cord> ListePoint;
    drawclicks(ListePoint);

    click();

    bool* TableIn=new bool[W*H];

    Espace_blanc_compar_blanc(W,H,ListePoint,r,g,b,TableIn);
    putColorImage(0,0,r,g,b,W,H);

    drawoutline(ListePoint);


    click();




    delete [] r;
    delete [] g;
    delete [] b;

    return 1;
}
