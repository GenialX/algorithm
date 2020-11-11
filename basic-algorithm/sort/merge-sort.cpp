#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 +10;
int n, a[N], t[N];
void merge_sort(int l, int h) {
    if (l >= h) return;
    int m = l + h >> 1;
    merge_sort(l, m);
    merge_sort(m + 1, h);
    int i = l, j = m + 1, k = -1;
    while (i <= m && j <= h) t[++k] = a[i] < a[j] ? a[i++] : a[j++];
    while (i <= m) t[++k] = a[i++];
    while (j <= h) t[++k] = a[j++];
    for (int i = 0; i <= k; ++i) a[l + i] = t[i];
}
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    merge_sort(0, n - 1);
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
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
