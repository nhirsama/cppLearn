//P8623 [蓝桥杯 2015 省 B] 移动距离
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int w,m,n;
    cin>>w>>m>>n;
    int mx =m/w;
    int nx = n/w;
    int my,ny;
    if(mx & 1){
        if(m%w == 0){
            my = w;
        }
        else {
            my = w - m%w + 1;
            mx++;
        }
    }
    else {
        if(m%w == 0){
            my = 1;
        }
        else {
            my = m%w;
            mx++;
        }
    }
    if(nx & 1){
        if(n%w == 0){
            ny = w;
        }
        else {
            ny = w - n%w + 1;
            nx++;
        }
    }
    else {
        if(n%w == 0){
            ny = 1;
        }
        else {
            ny = n%w;
            nx++;
        }
    }
    // cout << mx << ' '<< my << endl;
    // cout << nx << ' '<< ny << endl;
    cout << abs(mx-nx)+abs(my-ny);
    return 0;
}