#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    std::cin>>n; 
    if(n<=100){
        std::cout<<"Gong xi nin! Nin de ti zhong yue wei: ";
        std::cout<<n-(n%10 == 0 ? 10: n%10)<<" duo jin"<<std::endl;
    }
    else {
        std::cout<<"Gong xi nin! Nin de ti zhong yue wei: 100 duo jin"<<std::endl;
    }
}
