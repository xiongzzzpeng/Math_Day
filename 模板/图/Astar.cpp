#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fs first
#define sc second
#define LOCAL
typedef pair<int, int> PII;

// A*算法
// 用于二维网格中
// grid[i][j] == 0 代表障碍
// grid[i][j] == 1 代表道路
// 只能走上、下、左、右，不包括斜线方向
// 返回从(startX, startY)到(targetX, targetY)的最短距离

// 曼哈顿距离,不能走斜线
int f1(int x, int y, int targetX, int targetY) {
    return abs(targetX - x) + abs(targetY - y);
}

// 对角线距离,可以斜线
int f2(int x, int y, int targetX, int targetY) {
    return max(abs(targetX - x), abs(targetY - y));
}

// 欧式距离
double f3(int x, int y, int targetX, int targetY) {
    return sqrt(pow(targetX - x, 2) + pow(targetY - y, 2));
}

int Astar(vector<vector<int>> &grid, int startX, int startY, int targetX,
          int targetY) {
    int n = grid.size(), m = grid[0].size();

    if (grid[startX][startY] == 0 || grid[targetX][targetY] == 0)
        return -1;

    vector<vector<int>> distance(n, vector<int>(m, INT32_MAX));
    distance[startX][startY] = 1;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;
    // f1可换
    heap.push({1 + f1(startX, startY, targetX, targetY), startX, startY});
    int move[] = {-1, 0, 1, -1, 0};

    while (!heap.empty()) {
        auto cur = heap.top();
        heap.pop();

        int dist = cur[0];
        int x = cur[1];
        int y = cur[2];

        if (visited[x][y])
            continue;
        visited[x][y] = true;

        if (x == targetX && y == targetY)
            return distance[x][y];

        for (int i = 0; i < 4; i++) {
            int nx = x + move[i], ny = y + move[i + 1];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && !visited[nx][ny] && distance[x][y] + 1 < distance[nx][ny]) {
                distance[nx][ny] = distance[x][y] + 1;
                // f1可换
                heap.push({distance[nx][ny] + f1(nx, ny, targetX, targetY), nx, ny});
            }
        }
    }
}

void Solve() {}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
    freopen("xzp.in", "r", stdin);
    freopen("xzp.out", "w", stdout);
#endif

    int T = 1;
    cin >> T;
    while (T--) {
        Solve();
    }
    return 0;
}
