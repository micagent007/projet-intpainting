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
    conf(p.x,p.y)=s;
}

void calc_prio(std::vector<pixel_bord> pix,Image<double> conf,std::vector<double> grad,FilePriorite F,int i){
    pix[i].priorite=conf(pix[i].P.x,pix[i].P.y)*grad[i];
    F.push(pix[i]);
}

FilePriorite init_prio(std::vector<pixel_bord> pix, Image<double> conf, std::vector<double> grad){
    FilePriorite F;
    for(int i=0;i<pix.size();i++){
        pix[i].priorite=conf(pix[i].P.x,pix[i].P.y)*grad[i];
        F.push(pix[i]);
    }
    return F;
}
