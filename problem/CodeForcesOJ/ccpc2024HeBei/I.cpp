//
// Created by Origami on 25-4-13.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int ba, bb, bc, bd, len;
    scanf("%d.%d.%d.%d/%d", &ba, &bb, &bc, &bd, &len);
    int n;
    std::cin >> n;
    int a = len / 8;
    unsigned int zj = 0;
    zj |= (((unsigned int) ba) << 24);
    zj |= (((unsigned int) bb) << 16);
    zj |= (((unsigned int) bc) << 8);
    zj |= (((unsigned int) bd));
    unsigned int base = 0;

    //std::cout<<1ll*2147483647*2+1<<endl;
    for (int p = 0; p < len; p++) {
        base |= (1ul << 31 - p);
    }
    zj &= base;
    //std::cout<<base<<endl;
    for (int i = 0; i < n; i++) {
        int qa, qb, qc, qd;
        scanf("%d.%d.%d.%d", &qa, &qb, &qc, &qd);
        bool ok = true;
        //std::cout<<qa<< ' '<<qb<< ' '<<qc<< ' '<<qd<<std::endl;
        unsigned int que = 0;
        que |= (((unsigned int) qa) << 24);
        que |= (((unsigned int) qb) << 16);
        que |= (((unsigned int) qc) << 8);
        que |= (((unsigned int) qd));
        //std::cout<<que<<endl;
        // if(a<=1 && (qa != ba)) ok = false;
        // if(a<=2 && (qb != bb)) ok = false;
        // if(a<=3 && (qc != bc)) ok = false;
        if ((que & base) == zj) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}
