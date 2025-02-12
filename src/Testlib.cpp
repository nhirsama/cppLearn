#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
    }

    int sx = -1, sy = -1, gx = -1, gy = -1;
    vector<vector<pair<int, int>>> tele(26);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            char c = grid[i][j];
            if (c == 'S') {
                sx = i;
                sy = j;
            } else if (c == 'G') {
                gx = i;
                gy = j;
            } else if (c >= 'a' && c <= 'z') {
                tele[c - 'a'].emplace_back(i, j);
            }
        }
    }

    vector<vector<int>> dist(H, vector<int>(W, INF));
    dist[sx][sy] = 0;
    queue<pair<int, int>> q;
    q.emplace(sx, sy);

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == gx && y == gy) {
            cout << dist[x][y] << '\n';
            return 0;
        }

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (grid[nx][ny] == '#') continue;
            if (dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.emplace(nx, ny);
            }
        }

        char c = grid[x][y];
        if (c >= 'a' && c <= 'z') {
            auto& points = tele[c - 'a'];
            for (auto [nx, ny] : points) {
                if (nx == x && ny == y) continue;
                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
            points.clear(); // 关键优化，防止重复处理
        }
    }

    cout << -1 << '\n';
    return 0;
}