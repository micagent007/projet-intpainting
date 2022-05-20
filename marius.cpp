#include "marius.h"


std::vector<cord> calc_patch(int type_patch,cord p,int w,int h,int size){
    std::vector<cord> v;
    for(int x=0;x<2*size+1;x++){
        for(int y=0;y<2*size+1;y++){
            cord p_patch;p_patch.x=x-size+p.x;p_patch.y=y-size+p.y;
            if(p_patch.x>0&&p_patch.x<w&&p_patch.y>0&&p_patch.y<h){
                if((type_patch==carre&&norminf(p-p_patch)<=size)||(type_patch==cercle&&norm2(p-p_patch)<=size))
                    v.push_back(p_patch);
            }
        }
    }
    return v;
}

void calcul_conf(cord p,std::vector<cord> patch,Image<double> conf){
    double s=0;
    for(int i=0;i<patch.size();i++){
        if(p.x!=patch[i].x && p.y!=patch[i].y)
            s+=conf(patch[i].x,patch[i].y);
    }
    s/=patch.size();
    conf(p.x,p.y)=s; //diviser par 255 ??
}




FilePriorite prio(std::vector<pixel_bord> pix, Image<double> conf, std::vector<double> grad){
    FilePriorite F;
    for(int i=0;i<pix.size();i++){
        pix[i].priorite=conf(pix[i].P.x,pix[i].P.y)*grad[i];
        F.push(pix[i]);
    }
    return F;
}

double distance(cord p,cord q,Image<double> conf, byte* r, byte* g,byte* b){
    int w=conf.width();int h=conf.height();
    std::vector<cord> patch_p=calc_patch(type_p,p,w,h,siz);
    double d=0;
    for(int i=0;i<patch_p.size();i++){
        int xp=patch_p[i].x;int yp=patch_p[i].y;
        int xq=xp-p.x+q.x;int yq=yp-p.y+q.y;
        if(conf(xq,yq)==0||xp>=w||xp<0||yp<0||yp>h)
            continue;
        double dp=0;
        dp+=pow(r[xp+conf.width()*yp]-r[xq+conf.width()*yq],2);
        dp+=pow(g[xp+conf.width()*yp]-g[xq+conf.width()*yq],2);
        dp+=pow(b[xp+conf.width()*yp]-b[xq+conf.width()*yq],2);
        d+=sqrt(dp);
    }
    return d;
}

