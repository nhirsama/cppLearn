#include <bits/stdc++.h>
int main(){
    int T,s,t;
    std::cin>>T>>s>>t;
    if(T>=35 && s == 1 && t>=33){
        std::cout<<"Bu Tie\n"<<T<<std::endl;
    }
    else if(T >= 35 && t>=33 && s== 0){
        std::cout<<"Shi Nei\n"<<T<<std::endl;
    }
    else if(s == 1 && (T<35 || s<33)){
        std::cout<<"Bu Re\n"<<t<<std::endl;
    }
    else if(s==0){
        std::cout<<"Shu Shi\n"<<t<<std::endl;
    }
}