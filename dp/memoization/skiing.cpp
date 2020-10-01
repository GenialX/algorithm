//
// Created by huxiaoxu on 2020/9/16.
//
// https://www.acwing.com/activity/content/problem/content/1013/1/
#include "bits/stdc++.h"
using namespace std;
const int N = 305;
int mat[N][N], f[N][N];
int R, C;
int d[5] = {1, 0, -1, 0, 1};
int dfs(int r, int c) {
    if (f[r][c] > 0) return f[r][c];
    int ans = 1;

    for (int di = 0; di < 4; ++di) {
        int nr = r + d[di], nc = c + d[di + 1];
        if (nr < 1 || nr > R || nc < 1 || nc > C) continue;
        if (mat[r][c] <= mat[nr][nc]) continue;
        ans = max(ans, 1 + dfs(nr, nc));
    }

    return f[r][c] = ans;
}
int main() {
    cin >> R >> C;
    for (int r = 1; r <= R; ++r) {
        for (int c = 1; c <= C; ++c) {
            scanf("%d", &mat[r][c]);
        }
    }
    int ans = 0;
    for (int r = 1; r <= R; ++r)
        for (int c = 1; c <= C; ++c) {
            ans = max(ans, dfs(r, c));
        }
    cout << ans << endl;
    return 0;
}

