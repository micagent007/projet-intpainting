#include <Imagine/Graphics.h>
#include<cmath>
using namespace Imagine;
#include <iostream>
using namespace std;
#include <vector>
#include "cord.h"
#include "arthur.h"
#include "simon.h"
#include "micka.h"
#include "marius.h"
#include "pixel_bord.h"
#include <Imagine/Images.h>


int main(){
    int W=512,H=512;
    byte* r;
    byte* g;
    byte* b;

    loadColorImage(srcPath("Capture1.png"),r,g,b,W,H);
    openWindow(W,H);
    putColorImage(0,0,r,g,b,W,H);


    std::vector <cord> ListePoint;
    drawclicks(ListePoint);

    click();
    std::vector <cord> ListeBord;
    //ajout_point_bord(ListePoint[0].x,ListePoint[0].y,ListePoint[ListePoint.size()-1].x,ListePoint[ListePoint.size()-1].y,ListeBord);

    pointsbord(ListeBord,ListePoint);
    test_points_bord(ListeBord);


    click();
    Image<bool> TableIn(W,H);

    Espace_blanc_compar_blanc(W,H,ListePoint,r,g,b,TableIn);
    putColorImage(0,0,r,g,b,W,H);

    drawoutline(ListePoint);


    click();




    delete [] r;
    delete [] g;
    delete [] b;

    return 1;
}
