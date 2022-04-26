#include <Imagine/Graphics.h>
#include<cmath>
using namespace Imagine;
#include <iostream>
using namespace std;
#include <vector>
#include "cord.h"

int main(){
    int W=512,
            H=512;
    byte* r;
    byte* g;
    byte* b;
    byte* t;
    loadColorImage(srcPath("Capture1.JPG"),r,g,b,W,H);
    openWindow(W,H);
    putColorImage(0,0,r,g,b,W,H);
    loadGreyImage(srcPath("Capture1.jpg"),t,W,H);
    int x=0,y=0;
    std::vector <cord> ListePoint;
    getMouse(x,y);
    ListePoint.push_back({x,y});
    bool stop=false;
    while (!stop){
        if (getMouse(x,y)==1){
            cord O=ListePoint[ListePoint.size()- 1];
            drawLine(x,y,O.x,O.y,RED);
            ListePoint.push_back({x,y});
        }
        else {
            cord O=ListePoint[ListePoint.size()- 1];
            cord P=ListePoint[0];
            drawLine(P.x,P.y,O.x,O.y,RED);
            stop=true;
        }

    }

    click();
    putColorImage(0,0,r,g,b,W,H);
    click();
    delete [] r;
    delete [] g;
    delete [] b;
    return 1;
}
