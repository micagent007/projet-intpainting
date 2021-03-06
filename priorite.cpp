#include "priorite.h"

FilePriorite::FilePriorite(){
    pixel_bord p(-1,-1);
    v=std::vector<pixel_bord>(1,p);
}
bool FilePriorite::empty(){
    if (v.size()==1)
        return true;
    return false;
}
// Ajoute un element
void FilePriorite::push(pixel_bord d) {
    // A completer
    v.push_back(d);
    int i=v.size()-1;
    while((v[i/2]<v[i])&&(i>1)){
        std::swap(v[i/2],v[i]);
        i/=2;
    }
}
// Retire un element
pixel_bord FilePriorite::pop() {
    std::swap(v.back(),v[1]);
    pixel_bord p=v.back();
    v.pop_back();
    int i=1;
    while(2*i<v.size()){
        int j=i;
        if(v[j]<v[2*i])
            j=2*i;
        if(2*i+1<v.size()&& v[j]<v[2*i+1])
            j=2*i+1;
        if (j==i)break;
        std::swap(v[i],v[j]);
        i=j;
    }
    return p;
}

