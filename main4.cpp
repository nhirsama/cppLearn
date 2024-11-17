/*
//模板
#include <bits/stdc++.h>
using namespace std;
int main() {
    return 0;
}
*/
/*
//A - Army
#include <bits/stdc++.h>
using namespace std;
int n;
int arr[120];
int a,b;
int main() {
    cin>>n;
    arr[0] =0;
    for(int i=1;i<n;i++) {
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }

    cin>>a>>b;
    cout << arr[b-1]-arr[a-1];
    return 0;
}
*/
/*
//B - 均分纸牌
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    int arr[110];
    int sum = 0;
    int ans = 0;
    for (int i =1 ; i <= N ; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    int aaa = sum / N;
    for (int i = 1 ; i < N ; i++) {
        if (aaa == arr[i]) {
            continue;
        }
        if (aaa > arr[i]) {
            arr[i+1] -= aaa-arr[i];
            arr[i] = aaa;
            ans++;
        }
        else {
            arr[i+1] += arr[i]-aaa;
            arr[i] = aaa;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
*/
/*
//D - Bar
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int ans = 0;
    string R18[] = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
    for (int i = 1; i <= n; i++) {
        string  line;
        cin >> line;
        if ('A' <= line[0] && line[0] <= 'Z') {
            for (auto s : R18) {
                if (s.compare(line) == 0) {
                    ans++;
                    break;
                }
            }
        }
        else {
            if ((line[1] == '\0')|| (line[0] == '1' && line[1] < '8' && line[2] == '\0') ) {
                ans ++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
*/
//P5734 【深基6.例6】文字处理软件
#include <bits/stdc++.h>
using namespace std;
string input;
int main() {
    int q;
    cin >> q;
    cin >> input;
    for (int i = 0; i < q; i++) {
        int m;
        cin >> m;
        switch (m) {
            case 1: {
                string s;
                cin >> s;
                input +=s;
                cout << input <<endl;
                continue;
            }
            case 2: {
                int a,b;
                cin >> a >> b;
                input = input.substr(a,a+b);
                cout << input << endl;
                continue;
            }
            case 3: {
                int a;
                string s;
                cin >> a>>s;
                input.insert(a,s);
                cout << input <<endl;
                continue;
            }
            case 4: {
                string s;
                cin >> s;
                int a = input.find(s);
                if (0<=  a <= input.size()) cout << a << endl;
                else cout << -1 << endl;
                continue;
            }
            default: ;
        }
    }
    return 0;
}