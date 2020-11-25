// https://www.luogu.com.cn/problem/P1177
#include <iostream>

using namespace std;

const int N = 100010;
int a[N];

void quick_sort(int l, int r) {
    if (l >= e) return;
    int i = l - 1, j = r + 1, m = a[l + r >> 1];
    while (i < j) {
        while (a[++i] < m);
        while (a[--j] > m);
        if (i < j) swap(a[i], a[j]);
    }
    quick_sort(l, j);
    quick_sort(j + 1, r);
    // j,j+1,low
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    quick_sort(0, n - 1);
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    return 0;
}
