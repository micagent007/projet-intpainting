#include "marius.h"


std::vector<cord> calc_patch(cord p,int w,int h,int size){
    std::vector<cord> v;
    for(int x=0;x<2*size+1;x++){
        for(int y=0;y<2*size+1;y++){
            cord p_patch;p_patch.x=x-size+p.x;p_patch.y=y-size+p.y;
            if(p_patch.x>0&&p_patch.x<w&&p_patch.y>0&&p_patch.y<h){
                if((type_p==carre&&norminf(p-p_patch)<=size)||(type_p==cercle&&norm2(p-p_patch)<=size))
                    v.push_back(p_patch);
            }
        }
    }
    return v;
}

double calcul_conf(std::vector<cord> patch,Image<double> conf){
    double s=0;
    for(int i=0;i<patch.size();i++){
        s+=conf(patch[i].x,patch[i].y);
    }
    s/=patch.size();
    return(s);
}

std::vector<double> Listconf(std::vector<pixel_bord> pix,Image<double> conf){
    std::vector<double> Listconf;
    for(int i=0;i<pix.size();i++){
       std::vector<cord> patch =calc_patch(pix[i].P,conf.width(),conf.height(),siz);
       Listconf.push_back(calcul_conf(patch,conf));
    }
    return(Listconf);
}




FilePriorite prio(std::vector<pixel_bord> pix, std::vector<double> Listconf, std::vector<double> ListD){
    FilePriorite F;
    for(int i=0;i<pix.size();i++){
        pix[i].priorite=Listconf[i]*ListD[i];
        F.push(pix[i]);
    }
    return F;
}

double distance(cord p,cord q,Image<double> conf, byte* r, byte* g,byte* b){
    int w=conf.width();int h=conf.height();
    std::vector<cord> patch_p=calc_patch(p,w,h,siz);
    double d=0;
    for(int i=0;i<patch_p.size();i++){
        int xp=patch_p[i].x;int yp=patch_p[i].y;
        int xq=xp-p.x+q.x;int yq=yp-p.y+q.y;
        if(xp>=w||xp<0||yp<0||yp>h)
            continue;
        if (conf(xq,yq)!=1)
            return(100000000000.);
        if(conf(xp,yp)==0)
            continue;
        double dp=0;
        dp+=pow(r[xp+conf.width()*yp]-r[xq+conf.width()*yq],2);
        dp+=pow(g[xp+conf.width()*yp]-g[xq+conf.width()*yq],2);
        dp+=pow(b[xp+conf.width()*yp]-b[xq+conf.width()*yq],2);
        d+=sqrt(dp);

    }
    return d;
}

cord_double grad_rev(cord p, Image<double> conf, Image<byte> grey){
    cord_double g(0,0);
    int x=p.x; int y=p.y;
    if(conf(x+1,y)!=0){
        g.x=grey(x+1,y)-grey(x,y);
    }else if(conf(x-1,y)!=0){
        g.x=grey(x,y)-grey(x-1,y);
    }else {g.x=0;}
    if(conf(x,y+1)!=0){
        g.y=grey(x,y+1)-grey(x,y);
    }else if(conf(x,y-1)!=0){
        g.y=grey(x,y)-grey(x,y-1);
    }else {g.y=0;}
    return g;
}


cord find_q_bis(int W,int H,pixel_bord p_max,Image<double> conf,byte* r,byte* g,byte* b,cord_double grad){
    cord q={W/2,H/2};
    double d=distance(p_max.P,q,conf,r,g,b)+1000000;

    grad.normalize();


    for (int x=siz;x<W-siz;x++){
        for (int y=siz;y<H-siz;y++){
            cord P={x,y};

            cord_double p={double(x)-p_max.P.x,double(y)-p_max.P.y};
            p.normalize();
            double s=abs(grad*p);

            if (conf(x,y)==1 && s<tol){
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
cord find_q_ter(pixel_bord p_max,Image<double> conf,byte* r,byte* g,byte* b,cord_double grad){
    cord q={conf.width()/2,conf.height()/2};
    double d=distance(p_max.P,q,conf,r,g,b)+1000000;
    if(grad.y<0) grad=-1*grad;
    grad.normalize();
    double ecart=(conf.width()+conf.height())/ecart_div;

    cord_double P_sup={double(p_max.P.x)+ecart*grad.x,double(p_max.P.y)+ecart*grad.y};
    cord_double P_inf={double(p_max.P.x)-ecart*grad.x,double(p_max.P.y)-ecart*grad.y};
    bool vert=(P_sup.y==P_inf.y);

    for (int x=siz;x<conf.width()-siz;x++){
        for (int y=siz;y<conf.height()-siz;y++){
            cord P={x,y};


            if (conf(x,y)==1 &&((vert&&P.x<p_max.P.x+ecart&&P.x>p_max.P.x-ecart)
                                ||
                                (P.y<P_sup.y-(grad.x/grad.y)*(double(P.x)-P_sup.x)
                                &&P.y>P_inf.y-(grad.x/grad.y)*(double(P.x)-P_inf.x)))){


                double d_prov=distance(p_max.P,P,conf,r,g,b);
                if (d>d_prov){
                    d=d_prov;
                    q=P;
                }

            }
        }
    }
    return q;
}

