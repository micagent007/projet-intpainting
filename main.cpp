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

    loadColorImage(srcPath("IMG_2317.JPG"),r,g,b,W,H);
    openWindow(W,H);
    putColorImage(0,0,r,g,b,W,H);

    std::vector <cord> ListePoint;


//    //Test sans remplissage
//    Image<double> conf(W,H);
//    conf.fill(1);
//    Espace_blanc_compar_blanc(W,H,ListePoint,r,g,b,conf);
//    putColorImage(0,0,r,g,b,W,H);
//    drawoutline(ListePoint);

//    click();

//    std::vector <pixel_bord> ListepixelBord;

//    ListepixelBord=point_bord_w_omega(W,H,conf);

//    test_points_bord(ListepixelBord);

//    click();
    main_loop(W,H,ListePoint,r,g,b);



    delete [] r;
    delete [] g;
    delete [] b;

    return 1;
}
