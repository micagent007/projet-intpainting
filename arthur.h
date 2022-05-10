#ifndef ARTHUR_H
#define ARTHUR_H

#include <Imagine/Graphics.h>
#include<cmath>
using namespace Imagine;
#include <iostream>
using namespace std;
#include <vector>
#include "cord.h"

void convertGrey(int W,int H,byte* r, byte* g,byte* b, byte* t );
void drawclicks(vector <cord>& ListePoint);
void drawoutline(vector <cord>& ListePoint);


#endif // ARTHUR_H
