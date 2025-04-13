//
// Created by Origami on 25-4-13.
//
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    std::cin>>s;
    int arr[26]{0};
    for(auto c:s){
        if(c == 'i') continue;
        arr[c-'a']++;
    }
    long long ans = 0;
    for(int i = 0;i<26;i++){
        if (arr[i]) ans++;
    }
    std::cout<<ans<<std::endl;
}