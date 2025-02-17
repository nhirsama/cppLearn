//P11451 [USACO24DEC] It's Mooin' Time B
#include <bits/stdc++.h>
using namespace std;
char trie[27][27][27];
int main(){
    string s;
    int n,k;
    cin>>n>>k;
    cin>>s;
    set<string >ans;
    for(int i = 0;i<n-2;i++){
        trie[s[i]-'a'][s[i+1]-'a'][s[i+2]-'a']++;
    }
    for(int i = 0;i<26;i++){
        for(int j = 0;j<26;j++){
            if(trie[i][j][j]>=k && i!= j){
                string aaa;
                aaa.push_back('a'+i);
                aaa.push_back('a'+j);
                aaa.push_back('a'+j);
                ans.insert(aaa);
            }
            for(int m = 0;m<26;m++) {
                if(trie[i][j][m] == k-1){
                    for(int l = 0;l<26;l++){
                        if(trie[l][j][m]>=1 && l !=i && j == m){
                            string aaa;
                            aaa.push_back('a'+i);
                            aaa.push_back('a'+j);
                            aaa.push_back('a'+j);
                            ans.insert(aaa);
                        }
                        if(trie[i][l][m]>=1 && l !=i && l == m){
                            string aaa;
                            aaa.push_back('a'+i);
                            aaa.push_back('a'+j);
                            aaa.push_back('a'+j);
                            ans.insert(aaa);
                        }
                        if(trie[i][j][l]>=1 && l !=i && l == j){
                            string aaa;
                            aaa.push_back('a'+i);
                            aaa.push_back('a'+j);
                            aaa.push_back('a'+j);
                            ans.insert(aaa);
                        }
                    }
                }
            }
        }
    }
    //sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto i:ans){
        cout<<i<<'\n';
    }
    return 0;
}