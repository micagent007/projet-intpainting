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

    Image<byte> Image_in_grey(W,H);
    convertGrey(W,H,r,g,b,Image_in_grey);

    std::vector <cord> ListePoint;
    drawclicks(ListePoint);
    for (int k=0;k<ListePoint.size();k++)
        cout << ListePoint[k].x << "y " << ListePoint[k].y << endl;
    click();
    Image<double> TableIn(W,H);
    TableIn.fill(1);
    Espace_blanc_compar_blanc(W,H,ListePoint,r,g,b,TableIn);
    putColorImage(0,0,r,g,b,W,H);
    //drawoutline(ListePoint);

    click();

    std::vector <cord> ListeBord;

    point_bord_w_omega(W,H,TableIn,ListeBord);
    for(int i = 0; i<ListeBord.size();i++){
        drawPoint(ListeBord[i].x, ListeBord[i].y, BLUE);}
    std::vector <pixel_bord> ListepixelBord;
    /*
    for(int i = 0; i<ListeBord.size();i++){
        pixel_bord P(ListeBord[i].x, ListeBord[i].y);
        ListepixelBord.push_back(P);}*/
    test_points_bord(ListepixelBord);


    click();




    delete [] r;
    delete [] g;
    delete [] b;

    return 1;
}
