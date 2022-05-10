#include <Imagine/Graphics.h>
#include<cmath>
using namespace Imagine;
#include <iostream>
using namespace std;
#include <vector>
#include "cord.h"

void convertGrey(int W,int H, byte* r, byte* g,byte* b, byte* t ){
    for (int x=0;x<W;x++)
        for (int y=0;y<H;y++){
            t[x+y*W]=0.299*r[x+y*W]+0.587*g[x+y*W]+0.114*b[x+y*W];
        }
}
