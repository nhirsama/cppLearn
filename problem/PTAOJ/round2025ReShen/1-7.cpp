#include<bits/stdc++.h>
using namespace std;
int main() {
	vector<int> num;
	int n,a1,a2;
	std::cin>>a1>>a2>>n;
	num.push_back(a1);
    num.push_back(a2);
    int p = 0;
    while(num.size()<n){
        int t = num[p]*num[p+1];
        p++;
        stack<int> ss;
        if(t == 0){
            num.push_back(0);
        }
        else while(t){
            ss.push(t%10);
            t/=10;
        }
        while(!ss.empty()){
            num.push_back(ss.top());
            ss.pop();
        }
    }
    for(int i = 0;i<n;i++){
        std::cout<<num[i]<< " \n"[i==n-1];
    }
}
