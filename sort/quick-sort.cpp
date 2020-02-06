/**
 * https://www.acwing.com/activity/content/code/content/39784/
 */
#include <iostream>

using namespace std;

const int N = 100010;
int a[N];

void quick_sort(int a[], int s, int e) {
    if (s >= e) return;
    int l = s - 1, r = e + 1, m = a[s + e >> 1];
    while (l < r) {
        while(a[++l] < m);
        while(a[--r] > m);
        if (l < r) swap(a[l], a[r]);
    }
    quick_sort(a, s, r);
    quick_sort(a, r + 1, e);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> a[i];
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    return 0;
}