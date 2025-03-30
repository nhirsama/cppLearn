//模板
#include <bits/stdc++.h>
using i128 = __int128;
using i64 = long long int;
using i32 = int;
typedef std::pair<i32, i32> pii;
constexpr int N = 5e3 + 10;
constexpr int mod = 1e9+7;
#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define x first
#define y second
#define endl '\n'
#define all(x) (x).begin(), (x).end()
template<typename elemType,typename CMP>
struct MPQueue{
    CMP cmp;
    int Pos[1010];
    elemType Node[1010];
    int head,tail,limit;//limit-滑动窗口长度
    MPQueue():head(1),tail(0),limit(1){}
    MPQueue(int _limit):head(1),tail(0),limit(_limit){}

    bool size(){return tail-head+1;}
    bool empty(){return tail<head;}//是否为空
    elemType front_elem(){return Node[head];}//获取队首的元素
    int front_pos(){return Pos[head];}//获取队首元素在原序列中的位置
    //以上操作使用前应保证先pop_front队首的过时元素

    void set_limit(int _limit){limit=_limit;}//设置滑动窗口长度
    void clear(){head=1,tail=0;}//清空单调队列
    void push(int pos,elemType elem){//插入元素，维护最小值
        //pos-元素在原序列中的位置，elem-要插入的元素，limit-滑动窗口的长度
        while(head<=tail && (!cmp(Node[tail],elem) || pos-Pos[tail]+1>limit)
            --tail;
        ++tail;Node[tail]=elem;Pos[tail]=pos;
    }
    void pop_front(int pos){//处理过时的队首元素
        while(head<=tail && pos-Pos[head]>=limit) ++head;
    }
};

template<typename elemType,typename CMP>
struct MPQueue2D{//二维单调队列
    struct NODE{int posy;elemType Value;};
    struct CMP2{bool operator()(const NODE &A,const NODE &B)const {
        return CMP()(A.Value,B.Value);}
    };
    MPQueue<elemType,CMP> Row[1010];
    MPQueue<NODE,CMP2> Col;
    int x[1010][1010],y[1010][1010];//x[i][j]-以(i,j)为右下角的子矩阵中最值的行号
                                    //y[i][j]-以(i,j)为右下角的子矩阵中最值的列号
    elemType val[1010][1010],Data[1010][1010];
    //val[i][j]-以(i,j)为右下角的子矩阵中的最值
    //Data-二维单调队列的数据源
    int N,M,limitR,limitC;
    //N-行数，M-列数，limitR-滑动的子矩阵的行数，limitC-滑动的子矩阵的列数

    MPQueue2D(int _N=0,int _M=0,int _limitR=0,int _limitC=0):
        N(_N),M(_M),limitR(_limitR),limitC(_limitC) {}
    void setN(int _N){N=_N;}
    void setM(int _M){M=_M;}
    void clear(){
        for(i32 i=1;i<=N;++i)
            Row[i].clear();
        Col.clear();
    }
    void set_limit(int _limitR,int _limitC){//设置滑动子矩阵的行数limitR和列数limitC
        limitR=_limitR;limitC=_limitC;
        for(i32 i=1;i<=N;++i)
            Row[i].set_limit(limitC);
        Col.set_limit(limitR);
    }
    void Query(){//查询二维数组中每个滑动子矩阵的最值及其位置
        for(i32 j=1;j<=M;++j){
            Col.clear();//维护列的单调队列
            for(i32 i=1;i<=N;++i){
                Row[i].push(j,Data[i][j]);
                Row[i].pop_front(j);
                Col.push(i,(NODE){Row[i].front_pos(),Row[i].front_elem()});
                Col.pop_front(i);
                x[i][j]=Col.front_pos();//以(i,j)为右下角的子矩阵中最值的行号
                y[i][j]=Col.front_elem().posy;//以(i,j)为右下角的子矩阵中最值的列号
                val[i][j]=Col.front_elem().Value;//以(i,j)为右下角的子矩阵中的最值
            }
        }
    }
};

void nhir() {

}

signed main() {
    IOS;
    i32 T = 1;
    if (getenv("LOCAL") != nullptr) {
        freopen("Testlib.in", "r", stdin);
        // freopen("Code.out", "w", stdout);
        std::cin >> T;
    }

    while (T--) nhir();
    return 0;
}
