#include "marius.h"




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
