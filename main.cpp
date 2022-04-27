#include <Imagine/Graphics.h>
#include<cmath>
using namespace Imagine;
#include <iostream>
using namespace std;
#include <vector>
#include "cord.h"
#include <chrono>
#include <unistd.h>

bool autour_in(vector <cord> ListePoint ,cord P){
    int s=0;
    for (int k=-1;k<2;k++)
        for (int j=-1;j<2;j++){
            if(j!=0 or k!=0){
                cord O={P.x+k,P.y+j};
                if (in(ListePoint,O))
                    s+=1;
            }
        }
    if (s==8)
        return(true);
    return false;
}
void Espace_blanc_compar_in(int W, int H,vector <cord> ListePoint ,byte* r, byte* g, byte* b){
    for (int x=0;x<W;x++)
        for (int y=0;y<H;y++){
            cord P={x,y};
            if (in(ListePoint,P) ){
                r[x+y*W]=255,
                        g[x+y*W]=255,
                        b[x+y*W]=255;

            }
        }
    for (int x=0;x<W;x++)
        for (int y=0;y<H;y++){
            cord P={x,y};
            if (autour_in(ListePoint,P)){
                r[x+y*W]=255,
                        g[x+y*W]=255,
                        b[x+y*W]=255;

            }
        }
};
bool autour_blanc(cord P,int W, int H,byte* r, byte* g, byte* b){
    int s=0;
    for (int k=-1;k<2;k++)
        for (int j=-1;j<2;j++){
            if(j!=0 or k!=0)
                if (r[P.x+k+(P.y+j)*W]==255 and g[P.x+k+(P.y+j)*W]==255 and b[P.x+k+(P.y+j)*W]==255)
                    s+=1;
        }
    if (s==8)
        return(true);
    return false;
}
void Espace_blanc_compar_blanc(int W, int H,vector <cord> ListePoint ,byte* r, byte* g, byte* b){
    for (int x=0;x<W;x++)
        for (int y=0;y<H;y++){
            cord P={x,y};
            if (in(ListePoint,P) ){
                r[x+y*W]=255,
                        g[x+y*W]=255,
                        b[x+y*W]=255;

            }
        }
    for (int x=0;x<W;x++)
        for (int y=0;y<H;y++){
            cord P={x,y};
            if (autour_blanc(P,W,H,r,g,b)){
                r[x+y*W]=255,
                        g[x+y*W]=255,
                        b[x+y*W]=255;

            }
        }
};

int main(){
    int W=512,
            H=512;
    byte* r;
    byte* g;
    byte* b;
    loadColorImage(srcPath("Capture1.PNG"),r,g,b,W,H);
    openWindow(W,H);
    putColorImage(0,0,r,g,b,W,H);
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
    auto start = chrono::steady_clock::now();
    Espace_blanc_compar_blanc(W,H,ListePoint,r,g,b);
    auto end = chrono::steady_clock::now();

    cout << "Elapsed time in nanoseconds: "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
         << " ns" << endl;

    cout << "Elapsed time in microseconds: "
         << chrono::duration_cast<chrono::microseconds>(end - start).count()
         << " µs" << endl;

    cout << "Elapsed time in milliseconds: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;

    cout << "Elapsed time in seconds: "
         << chrono::duration_cast<chrono::seconds>(end - start).count()
         << " sec";

    putColorImage(0,0,r,g,b,W,H);
    for (int k=0;k<ListePoint.size()-1;k++){
        cord O=ListePoint[k];
        cord P=ListePoint[k+1];
        drawLine(P.x,P.y,O.x,O.y,RED);}
    cord O=ListePoint[ListePoint.size()- 1];
    cord P=ListePoint[0];
    drawLine(P.x,P.y,O.x,O.y,RED);
    click();




    delete [] r;
    delete [] g;
    delete [] b;
    return 1;
}
