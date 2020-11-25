#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 +10;
int n, a[N], t[N];
typedef long long LL;
LL merge_sort(int l, int h) {
    if (l >= h) return 0;
    int m = l + h >> 1;
    LL lcnt = merge_sort(l, m), rcnt = merge_sort(m + 1, h), cnt = 0;
    int i = l, j = m + 1, k = -1;
    while (i <= m && j <= h) {
        if (a[i] <= a[j]) {
            t[++k] = a[i++];
        } else {
            cnt += m - i + 1;
            t[++k] = a[j++];
        }
    }
    while (i <= m) t[++k] = a[i++];
    while (j <= h) t[++k] = a[j++];
    for (int i = 0; i <= k; ++i) a[l + i] = t[i];
    return lcnt + rcnt + cnt;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    auto cnt = merge_sort(0, n - 1);
    cout << cnt << endl;
    return 0;
}

// T(n) = 2T(n/2) + n = O(nlogn)

// 1 3 2 11    4 3
// l   m m + 1   h     
// i     j
// ....  .........
// 分解问题 -> 两部分
// 递归求解
// 合并
