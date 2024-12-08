//P1160 队列安排
//记得把文件读写流和define注释掉
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
//vali存储的值，eli存储的为vali的上一个元素，eri为val存储的下一个元素
//er[0]是头节点，el[0]是尾节点
int val[N],el[N],er[N];
int aaa[N];
int a = 2;
int handS = 1;
int endS = 1;
void insert(int x,int k,int z){
    k = aaa[k];
    aaa[x] = a;
    val[a] = x;
    if(z == 0){
        el[a] = el[k];
        er[a] = k;
        if (el[k] != -1) er[el[k]] = a;
        else {
            handS = a;
        }
        el[k] = a;
        a++;
    }
    else{
        el[a] = k;
        er[a] = er[k];
        if (er[k] != -1) el[er[k]] = a;
        else {
            endS = a;
        }
        er[k] = a;
        a++;
    }
}
void del(int x){
    if(aaa[x] == 0){
        return;
    }
    x = aaa[x];
    if (el[x] != -1) {
        er[el[x]] = er[x];
    }
    else {
        handS = er[x];
    }
    if (er[x] != -1) {
        el[er[x]] = el[x];
    }
    else {
        endS = el[x];
    }
    aaa[x] = 0;
}
int main() {
    aaa[1] = 1;
    val[1] = 1;
    er[1] = -1;
    el[1] = -1;
    int n;
    scanf("%d",&n);
    for(int i = 2; i <= n; i++){
        int k,p;
        scanf("%d %d",&k,&p);
        insert(i,k,p);
    }
    int m;
    scanf("%d",&m);
    for(int i = 1; i <= m; i++){
        int x;
        scanf("%d",&x);
        del(x);
    }
    int num = handS;
    for(int i = 1; i<=n;i++){
        printf("%d ",val[num]);
        if(er[num] == -1) break;
        num = er[num];
    }
    return 0;
}