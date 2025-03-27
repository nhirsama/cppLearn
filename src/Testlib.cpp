#include<bits/stdc++.h>
using namespace std;

void mul(vector<int> &A, int b) //高精度乘法，每次乘以2，算幂
{
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t += A[i] * b;
        A[i] = t % 10;
        t /= 10;
    }
    if (t != 0) {
        A.push_back(t);
    }
}

int main() {
    int n;
    string d;
    cin >> n >> d;
    vector<int> D;
    int i = 0, dot;
    while (d[i] != 0) {
        if (d[i] == '.') {
            dot == i;
            i++;
            continue;
        }
        D.push_back(d[i] - '0');
        i++;
    }
    cout << dot << endl;
    reverse(D.begin(), D.end()); //把个位放前边，好操作高精
    while (n--) mul(D, 2);

    if (D[dot - 1] >= 5) //进位
    {
        D[dot] += 1;
    }

    reverse(D.begin(), D.end()); //放回来
    for (int i = 0; i < D.size() - dot; i++) {
        cout << D[i];
    }
    cout << endl;
    return 0;
}
