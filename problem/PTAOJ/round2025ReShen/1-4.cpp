#include<bits/stdc++.h>
using namespace std;
int main(){
    int a = 0,b = 0;
    int in;
    while(std::cin>>in){
        if(in == 0){
            std::cout<<a<< '\n';
        }
        else if (in == 1){
            a++;
        }
        else {
            break;
        }
    }
    //std::cout<<b<< ' '<<a<<std::endl;
    
}
