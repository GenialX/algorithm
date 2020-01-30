/**
 * https://github.com/lydrainbowcat/tedukuri/tree/master/%E9%85%8D%E5%A5%97%E5%85%89%E7%9B%98/%E4%BE%8B%E9%A2%98/0x50%20%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92/0x56%20%E7%8A%B6%E6%80%81%E5%8E%8B%E7%BC%A9DP/%E7%82%AE%E5%85%B5%E9%98%B5%E5%9C%B0
 */
#include <iostream>

using namespace std;

#define rep(x, y, z) for (int x = y; x < z; ++x)
#define MST(a, b) memset(a, b, sizeof(a));

int board[101];
int s[70]; // 合法摆放的集合
int cnt[70]; // 每一个合法摆放的情况的炮兵的个数（即二进制形式下 1 的个数）
int dp[101][70][70];
int idx, n, m, ans;

bool ok(int x) {
    if (x & (x << 1)) return false;
    if (x & (x << 2)) return false;
    return true;
}

int get_one(int x) {
    int a = 0;
    while (x) x &= (x - 1), ++a;
    return a;
}

bool valid(int i, int x) {
    return (board[i] & x) ? false : true;
}

int main() {
    cin >> n >> m;
    rep(i, 1, n + 1) rep(j, 0, m) {
        char c; cin >> c;
        if (c == 'H') board[i] |= (1 << (m - j - 1));
    }

    idx = 0;
    int end = 1 << m;
    rep(i, 0, end) if (ok(i)) {
        cnt[idx] = get_one(i);
        s[idx++] = i;
        //cout << i << endl;
    }
    //cout << " count:" << idx << endl;

    MST(dp, -1);
    dp[0][0][0] = 0; // ?

    rep(j, 0, idx) if (valid(1, s[j])) {
        dp[1][j][0] = cnt[j];
        ans = max(ans, dp[1][j][0]);
    }

    ans = 0;
    rep (i, 2, n + 1) {
        rep (j, 0, idx) if (valid(i, s[j])) {
            rep (k, 0, idx) if (valid(i - 1, s[k]) && (s[j] & s[k]) == 0) {
                int maxk = 0;
                rep (l, 0, idx) if (dp[i - 1][k][l] != -1 && (s[j] & s[l]) == 0 && valid(i - 2, s[l])) {
                    maxk = max(maxk, dp[i - 1][k][l]);
                }

                dp[i][j][k] = max(dp[i][j][k], maxk + cnt[j]);
                if (i == n) ans = max(ans, dp[i][j][k]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
