/**
 * 二分图的最大匹配.
 *
 * 匈牙利算法（增光路算法）
 *
 * 棋盘覆盖 https://github.com/lydrainbowcat/tedukuri/tree/master/%E9%85%8D%E5%A5%97%E5%85%89%E7%9B%98/%E4%BE%8B%E9%A2%98/0x60%20%E5%9B%BE%E8%AE%BA/0x68%20%E4%BA%8C%E5%88%86%E5%9B%BE%E7%9A%84%E5%8C%B9%E9%85%8D/%E6%A3%8B%E7%9B%98%E8%A6%86%E7%9B%96
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 106;
const int dx[4] = {0, 0, 1 , -1};
const int dy[4] = {1, -1, 0, 0};
int n, m, ans, f[N*N];
bool b[N][N], v[N*N];
vector<int> e[N*N];

bool dfs(int x) {
    for (unsigned int i = 0; i < e[x].size(); ++i) {
        int y = e[x][i];
        if (v[y]) continue;
        v[y] = 1;
        if (f[y] == -1 || dfs(f[y])) {
            f[y] = x;
            return 1;
        }
    }
    return 0;
}

int main() {
    cin >> n >> m;
    while (m--) {
        int x, y;
        scanf("%d %d", &x, &y);
        b[x - 1][y - 1] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!b[i][j]) {
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < n && !b[x][y]) {
                        e[i * n + j].push_back(x * n + y);
                        e[x * n + y].push_back(i * n + j);
                    }
                }
            }
        }
    }
    memset(f, -1, sizeof(f));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i ^ j) & 1) continue; // i + j 为奇数时跳过
            memset(v, 0, sizeof(v));
            ans += dfs(i * n + j);
        }
    }
    cout << ans << endl;
    return 0;
}
