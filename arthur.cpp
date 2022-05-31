#include <Imagine/Graphics.h>
#include<cmath>
using namespace Imagine;
#include <iostream>
using namespace std;
#include <vector>
#include "cord.h"
#include "pixel_bord.h"
#include "simon.h"
#include "marius.h"
#include "micka.h"


void convertGrey(int W,int H, byte* r, byte* g,byte* b, Image<byte> & Image_in_grey ){
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

bool in(std::vector <cord> ListePoint,cord P){
    double s=0;
    for (int k=0;k<ListePoint.size()-1;k++){
        cord O=ListePoint[k];
        cord Q=ListePoint[k+1];
        s+=angle(O-P,Q-P);
    }
    cord O=ListePoint[ListePoint.size()-1];
    cord Q=ListePoint[0];
    s+=angle(O-P,Q-P);
    //if ((2*M_PI-s)<1e-10)
    if (2*M_PI-abs(s)<0.1)
        return(true);

    return(false);
}
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
void Espace_blanc_compar_blanc(int W, int H,vector <cord> ListePoint ,byte* r, byte* g, byte* b,Image<double> conf){
    for (int x=0;x<W;x++)
        for (int y=0;y<H;y++){
            cord P={x,y};
            if (in(ListePoint,P) ){
                r[x+y*W]=255,
                        g[x+y*W]=255,
                        b[x+y*W]=255,
                        conf(x,y)=0;


            }
            else{conf(x,y)=1;}
        }
    for (int x=0;x<W;x++)
        for (int y=0;y<H;y++){
            cord P={x,y};
            if (autour_blanc(P,W,H,r,g,b)){

                r[x+y*W]=255,
                        g[x+y*W]=255,
                        b[x+y*W]=255,
                        conf(x,y)=0;


            }
        }
}

bool omega_is_empty(int W, int H,Image<double> conf){
    for (int x=0;x<W;x++)
        for (int y=0;y<H;y++)
            if (conf(x,y)==0)
                return(false);
    return(true);
}

cord find_q(int W,int H,pixel_bord p_max,Image<double> conf,byte* r,byte* g,byte* b){
    double d=1000000.;
    cord q={0,0};
    for (int x=siz;x<W-siz;x++){
        for (int y=siz;y<H-siz;y++){
            cord P={x,y};
            if (conf(x,y)==1){
                double d_prov=distance(p_max.P,P,conf,r,g,b);
                if (d>d_prov){
                    d=d_prov;
                    q=P;
                }

            }
        }
    }
    return(q);
}

void update_conf(cord p,Image<double> conf){
    std::vector<cord> patch=calc_patch(p,conf.width(),conf.height(),siz);
    double c=calcul_conf(patch,conf);
    for (int k=0;k<patch.size();k++){
        if (conf(patch[k].x,patch[k].y)==0)
            conf(patch[k].x,patch[k].y)=c;
    }
}
void copy_image_data(cord q, cord p,Image<double> conf,byte* &r,byte* &g,byte* &b){
    std::vector<cord> patch_p=calc_patch(p,conf.width(),conf.height(),siz);
    for (int k=0;k<patch_p.size();k++){
        if (conf(patch_p[k].x,patch_p[k].y)==0){
            int x_p=patch_p[k].x,
                    y_p=patch_p[k].y;
            int x_q=x_p-p.x+q.x;int y_q=y_p-p.y+q.y;
            r[x_p+y_p*conf.width()]=r[x_q+y_q*conf.width()],
                    g[x_p+y_p*conf.width()]=g[x_q+y_q*conf.width()],
                    b[x_p+y_p*conf.width()]=b[x_q+y_q*conf.width()];


        }
    }

}

void copy_image_data_for_gradient_nul(cord p,Image<double> conf,byte* &r,byte* &g,byte* &b){
    std::vector<cord> patch_p=calc_patch(p,conf.width(),conf.height(),siz);
    for (int k=0;k<patch_p.size();k++){
        if (conf(patch_p[k].x,patch_p[k].y)==0){
            int x_p=patch_p[k].x,
                    y_p=patch_p[k].y;
            int xpix=p.x;int ypix=p.y;
            r[x_p+y_p*conf.width()]=r[xpix+ypix*conf.width()],
                    g[x_p+y_p*conf.width()]=g[xpix+ypix*conf.width()],
                    b[x_p+y_p*conf.width()]=b[xpix+ypix*conf.width()];


        }
    }

}


void main_loop(int W, int H,std::vector <cord> ListePoint,byte* r,byte* g,byte* b){
    Image<double> conf(W,H);// list of confidence
    conf.fill(1);
    std::vector <pixel_bord> ListepixelBord;//list pixel who compose the surface
    Image<byte> Image_in_grey(W,H); // our image in grey
    std::vector <double> D; // this will be our list of "data term"
    std::vector <double> C; // this will be our list of confidence for pixel_bord
    FilePriorite F; // our file of Priority

    drawclicks(ListePoint);
    Espace_blanc_compar_blanc(W,H,ListePoint,r,g,b,conf);// initialize the conf (1)


    while(!omega_is_empty(W,H,conf)){//(1a)


        putColorImage(0,0,r,g,b,W,H);

        ListepixelBord=point_bord_w_omega(W,H,conf);//(1a) we compute the new list pixel who compose the surface

        convertGrey(W,H,r,g,b,Image_in_grey);//in order to compute our gradient and so the data term

        D=liste_D(Image_in_grey,ListepixelBord,conf);// we commpute all the data term of the pixel_bord in the surface
        C=Listconf(ListepixelBord,conf);

        F=prio(ListepixelBord,C,D);//(1b)

        pixel_bord p_max=F.pop();//(2a)
        //fillCircle(p_max.P.x,p_max.P.y,2,PURPLE);
        cord_double grad=grad_rev(p_max.P,conf,Image_in_grey);
        if (grad.norm2()<=3){
            copy_image_data_for_gradient_nul(p_max.P,conf,r,g,b);
        }

        else{
            //cord q=find_q(W,H,p_max,conf,r,g,b);//(2b)


            //Marius;
            cord_double grb={grad.x,grad.y};
            grb.normalize();
            drawLine(p_max.P.x,p_max.P.y,p_max.P.x+10*grb.x,p_max.P.y+10*grb.y,RED);
            //cord q=find_q_bis(W,H,p_max,conf,r,g,b,grad);
            cord q=find_q_ter(p_max,conf,r,g,b,grad);
            //


            copy_image_data(q,p_max.P,conf,r,g,b);// (2c)}
        }
        update_conf(p_max.P,conf); //(3)

    }
    cout<<"fin"<<endl;
    putColorImage(0,0,r,g,b,W,H);
    click();
}
