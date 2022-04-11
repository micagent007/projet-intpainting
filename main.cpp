#include <Imagine/Graphics.h>
using namespace Imagine;
#include <iostream>
using namespace std;

int main(){
    openWindow(512,512);
    int x,y,x1=0,y1=0,x2=0,y2=0;
    getMouse(x,y);
    x1=x;
    y1=y;
    while (true){
        if (getMouse(x2,y2)==1){
            drawLine(x1,y1,x2,y2,RED);
            x1=x2;
            y1=y2;
        }
        else
            drawLine(x,y,x2,y2,RED);

    }
    return 1;
}
