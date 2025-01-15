// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     char A = 'A', B = 'B', C = 'C';
//     char in;
//         cin >> in;
//         if (in == '<') {
//             if (A>B) swap(A, B);
//         }
//     else if (A<B) swap(A, B);
//     cin >> in;
//     if (in == '<') {
//         if (A>C) swap(A, C);
//     }
//     else if (A<C) swap(A, C);
//     cin >> in;
//     if (in == '<') {
//         if (B>C) swap(B, C);
//     }
//     else if (B<C) swap(B, C);
//     cout << B << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main() {
    char arr[3],a;
    cin>>a;
    arr[0]+=a == '>';
    arr[1]+=a == '<';

    cin>>a;
    arr[0]+=a == '>';
    arr[2]+=a == '<';

    cin>>a;
    arr[1]+=a == '>';
    arr[2]+=a == '<';
    for(int i = 0;i<3;i++){
        if(arr[i]==1)cout << (char)(i+'A')<<endl;
    }
    return 0;
}