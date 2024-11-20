//B - Waiting for...
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int peoNum = 0;
    for (int i = 0; i < n; i++) {
        char A;
        int b;
        cin >> A >> b;
        switch (A) {
            case 'B': {
                if (b > peoNum) {
                    peoNum = 0;
                    cout << "YES" << endl;
                }
                else {
                    peoNum -= b;
                    cout << "NO" << endl;
                }
                continue;
            }
            case 'P': {
                peoNum += b;
            }
        }
    }
    return 0;
}