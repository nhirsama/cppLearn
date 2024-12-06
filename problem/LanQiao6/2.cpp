
#include <iostream>
using namespace std;
bool Func(int i,int j,int k){
    string aa[3];
    aa[0] = to_string(i);
    aa[1] = to_string(j);
    aa[2] = to_string(k);
    if(aa[2].size()<=4)return false;
    for(auto &b:aa){
        for(int mi = 0;mi<b.size();mi++){
            for(int mj = 0;mj<b.size();mj++){
                if(mj==mi)continue;
                if(b[mi] == b[mj])return false;
            }
        }
    }
    if(aa[0][1] == aa[1][3] && aa[1][3] == aa[2][3]){
        if(aa[0][2] == aa[2][2]){
            if(aa[1][0] == aa[2][0]){
                if(aa[1][1] == aa[2][1]){
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    // 请在此输入您的代码
    // for(int i = 8000;i<=9999;i++){
    //     for(int j = 1000;j<=1999;j++){
    //         if(Func(i,j,j+i)){
    //             cout<<i<<' '<<j<<' '<<i+j<<endl;
    //         }
    //     }
    // }
    cout<<"1085";
    return 0;
}