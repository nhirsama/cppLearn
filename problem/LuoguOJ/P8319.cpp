//P8319 『JROI-4』分数
//记得把文件重定向注释掉
#include <bits/stdc++.h>
using namespace std;
int isPrime[2001005];
int prime[2001005];
int arr[500010];
int idx = 0;
void Init(int n){
    isPrime[0] = isPrime[1] = 1;
    prime[0] = 1;
    for(int i = 2; i <= n; i++){
        if(!isPrime[i]){
            prime[++idx] = i;
        }
        for(int j = 1; i*prime[j] <= n && j<=idx; j++){
            isPrime[i*prime[j]] = 1;
            if(i%prime[j] == 0){
                break;
            }
        }
    }
}
int main() {
#ifdef LOCAL
    freopen("Testlib.in", "r", stdin);
    freopen("Code.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T;
    cin >> T;
    int max = 0;
    for(int i = 1; i <= T; i++){
        cin >> arr[i];
        if(arr[i] > max)max = arr[i];
    }
    Init(max+500);
    for(int i = 1; i <= T; i++){
        if(!isPrime[arr[i]]) {
            cout << arr[i] << '\n';
        }
        else {
            cout << *(upper_bound(prime, prime+min(arr[i],idx), arr[i])-1) << '\n';
        }
    }
    cout<< endl;
#ifdef LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}