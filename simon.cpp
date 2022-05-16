#include <Imagine/Graphics.h>
#include<cmath>
using namespace Imagine;
#include <iostream>
using namespace std;
#include <vector>
#include "cord.h"
#include "simon.h"


void ajout_point_bord(int x1, int y1, int x2, int y2, std::vector <pixel_bord> & ListePointsBord){
    int dx = x2 - x1;
    int dy;

    if(dx != 0){
        if(dx > 0){
            dy = y2 - y1;
            if(dy != 0){
                if(dy > 0){
                    // vecteur oblique dans le 1er quadran
                    if(dx >= dy){
                        // vecteur diagonal ou oblique proche de l’horizontale, dans le 1er octant
                        int e = dx;
                        dx = e * 2;
                        dy = dy * 2;
                        // e est positif
                        for(;;){
                            pixel_bord P(x1,y1);
                            ListePointsBord.push_back(P);

                            ++x1;
                            if(x1 == x2){
                                break;
                            }
                            e -= dy;
                            if(e < 0){
                                ++y1; // déplacement diagonal
                                e += dx;
                            }
                        }
                    }else{
                        // vecteur oblique proche de la verticale, dans le 2d octant
                        int e = dy;
                        dy = e * 2 ;
                        dx = dx * 2 ;
                        // e est positif
                        for(;;){  // déplacements verticaux
                            pixel_bord P(x1,y1);
                            ListePointsBord.push_back(P);
                            ++y1;
                            if(y1 == y2){
                                break;
                            }
                            e -= dx;
                            if(e < 0){
                                ++x1;  // déplacement diagonal
                                e += dy;
                            }
                        }
                    }
                }else{// dy < 0 (et dx > 0)

                    // vecteur oblique dans le 4e cadran
                    if( dx >= -dy){
                        // vecteur diagonal ou oblique proche de l’horizontale, dans le 8e octant
                        int e = dx;
                        dx = e * 2 ;
                        dy = dy * 2 ;
                        // e est positif
                        for(;;){  // déplacements horizontaux
                            pixel_bord P(x1,y1);
                            ListePointsBord.push_back(P);
                            ++x1;
                            if(x1 == x2){
                                break;
                            }
                            int e = e + dy;

                            if(e < 0){
                                --y1;  // déplacement diagonal
                                e = e + dx ;
                            }
                        }
                    }else{
                        // vecteur oblique proche de la verticale, dans le 7e octant
                        int e = dy;
                        dy = e * 2 ;
                        dx = dx * 2 ;  // e est négatif
                        for(;;){  // déplacements verticaux
                            pixel_bord P(x1,y1);
                            ListePointsBord.push_back(P);
                            --y1;
                            if(y1 == y2){
                                break;
                            }
                            e += dx;
                            if(e > 0){
                                ++x1;  // déplacement diagonal
                                e += dy ;
                            }
                        }
                    }
                }
            }else{  // dy = 0 (et dx > 0)
                // vecteur horizontal vers la droite
                do{
                    pixel_bord P(x1,y1);
                    ListePointsBord.push_back(P);
                    ++x1;
                }while(x1 != x2);
            }
        }else{ // dx < 0
            dy = y2 - y1;
            if(dy != 0){
                if(dy > 0){
                    // vecteur oblique dans le 2d quadran
                    if(-dx >= dy){
                        // vecteur diagonal ou oblique proche de l’horizontale, dans le 4e octant
                        int e = dx;
                        dx = e * 2;
                        dy = dy * 2;
                        // e est négatif
                        for(;;){ // déplacements horizontaux
                            pixel_bord P(x1,y1);
                            ListePointsBord.push_back(P);
                            --x1;
                            if(x1 == x2){
                                break;
                            }
                            e += dy;
                            if(e >= 0){
                                ++y1;  // déplacement diagonal
                                e += dx;
                            }
                        }
                    }else{
                        // vecteur oblique proche de la verticale, dans le 3e octant
                        int e = dy;
                        dy = e * 2 ;
                        dx = dx * 2 ;
                        // e est positif
                        for(;;){  // déplacements verticaux
                            pixel_bord P(x1,y1);
                            ListePointsBord.push_back(P);
                            ++y1;
                            if(y1 == y2){
                                break;
                            }
                            e += dx;
                            if(e <= 0) {
                                --x1;  // déplacement diagonal
                                e += dy ;
                            }
                        }
                    }
                }else{  // dy < 0 (et dx < 0)
                    // vecteur oblique dans le 3e cadran
                    if(dx <= dy){
                        // vecteur diagonal ou oblique proche de l’horizontale, dans le 5e octant
                        int e = dx;
                        dx = e * 2;
                        dy = dy * 2;
                        // e est négatif
                        for(;;){  // déplacements horizontaux
                            pixel_bord P(x1,y1);
                            ListePointsBord.push_back(P);
                            --x1;
                            if(x1 == x2){
                                break;
                            }
                            e -= dy;
                            if(e >= 0){
                                --y1;  // déplacement diagonal
                                e += dx ;
                            }
                        }
                    }else{  // vecteur oblique proche de la verticale, dans le 6e octant
                        int e = dy;
                        dy = e * 2;
                        dx = dx * 2;
                        // e est négatif
                        for(;;){ // déplacements verticaux
                            pixel_bord P(x1,y1);
                            ListePointsBord.push_back(P);
                            --y1;
                            if(y1==y2){
                                break;
                            }
                            e -= dx;
                            if(e >= 0){
                                --x1;  // déplacement diagonal
                                e += dy ;
                            }
                        }
                    }
                }
            }else{  // dy = 0 (et dx < 0)
                // vecteur horizontal vers la gauche
                do{
                    pixel_bord P(x1,y1);
                    ListePointsBord.push_back(P);
                    --x1;
                }while(x1 != x2);
            }
        }
    }else{
        // dx = 0
        dy = y2 - y1;
        if(dy != 0){
            if(dy > 0){
                // vecteur vertical croissant
                do{
                    pixel_bord P(x1,y1);
                    ListePointsBord.push_back(P);
                    ++y1;
                }while(y1 != y2);
            }else{ // dy < 0 (et dx = 0)
                do{
                    pixel_bord P(x1,y1);
                    ListePointsBord.push_back(P);
                    --y1;
                }while(y1 != y2);
            }
        }
    }
    //On trace le dernier point du segment:
    pixel_bord P(x1,y1);
    ListePointsBord.push_back(P);
}

void pointsbords(std::vector <pixel_bord> & ListePointsBord,std::vector <cord> ListeSommets){
    for(int i = 0; i<ListeSommets.size()-1;i++){
        ajout_point_bord(ListeSommets[i].x,ListeSommets[i].y,ListeSommets[i+1].x,ListeSommets[i+1].y,ListePointsBord);
    }
    ajout_point_bord(ListeSommets[0].x,ListeSommets[0].y,ListeSommets[ListeSommets.size()].x,ListeSommets[ListeSommets.size()].y,ListePointsBord);

}

void test_points_bord(std::vector <pixel_bord> ListePointsBord){
    for(int i = 0;i<ListePointsBord.size();i++){
        drawPoint(ListePointsBord[i].P.x, ListePointsBord[i].P.y, BLUE );
    }
}
