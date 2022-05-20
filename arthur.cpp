#include <Imagine/Graphics.h>
#include<cmath>
using namespace Imagine;
#include <iostream>
using namespace std;
#include <vector>
#include "cord.h"

void convertGrey(int W,int H, byte* r, byte* g,byte* b, Image<byte> Image_in_grey ){
    for (int x=0;x<W;x++)
        for (int y=0;y<H;y++){
            Image_in_grey(x,y)=0.299*r[x+y*W]+0.587*g[x+y*W]+0.114*b[x+y*W];
        }
}

void drawclicks(vector <cord>& ListePoint){
    int x=0,y=0;

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

}

void drawoutline(vector <cord>& ListePoint){

    for (int k=0;k<ListePoint.size()-1;k++){
        cord O=ListePoint[k];
        cord P=ListePoint[k+1];
        drawLine(P.x,P.y,O.x,O.y,RED);}
    cord O=ListePoint[ListePoint.size()- 1];
    cord P=ListePoint[0];
    drawLine(P.x,P.y,O.x,O.y,RED);
}
