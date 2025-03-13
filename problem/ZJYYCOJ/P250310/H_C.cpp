#include <bits/stdc++.h>
using namespace std;
int n, m, cnt ; // 全局变量默认为0
int arr[105][105] ;
int book[105][105] ;
int dx[] = {-1, 0, 1, 0} ; // 利用两个一维数组来表示四个方向
int dy[] = {0, 1, 0, -1} ;
struct node
{
    int x ;
    int y ;
};
queue<node> qu ;  // 建立一个存放结构体的队列
void bfs(int x1, int y1) // 传入起点坐标
{
    node a = {x1, y1} ;
    qu.push(a) ; // 把起点存入队首
    while (!qu.empty()) //队列非空是循环条件
    {
        node b = qu.front() ; // 取出队首
        qu.pop() ; // 去掉队首
        for (int i = 0 ; i < 4 ; i++) { // 利用循环遍历四个方向
            int nx = b.x + dx[i] ;
            int ny = b.y + dy[i] ;
            if (nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue ; // 判断边界
            if (arr[nx][ny] == 0 && book[nx][ny] == 0) {
                book[nx][ny] = 1 ; // 把可拓展的地方标记起来
                node c = {nx, ny} ;
                qu.push(c) ;
            } // 如果四周没有可以拓展的地方，就会不断弹出队首，直到队列为空跳出循环
        }
    }
}
int main(void)
{
    cin >> n >> m ;
    for(int i = 0 ; i < n ; i++) { // 读入二维数组
        for (int j = 0 ; j < m ; j++) {
            cin >> arr[i][j] ;
        }
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (arr[i][j] == 0 && book[i][j] == 0) { // 寻找到可拓展却没被标记的作为起点
                cnt++ ;
                bfs(i, j) ;
            }
        } // 如果有多个样例记得将数组进行重置
    } // 代码为: memset(arr, 0, sizeof(arr)) 在头文件<cstring>中，把数组重置为全为0
    cout << cnt << endl ;
    return 0 ;
}
