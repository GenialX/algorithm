#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, a[N], s[N], p, b[N];
int main() {
    cin >> n;
    s[0] = -1;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        while (p && a[s[p]] >= a[i]) --p;
        s[++p] = i;
        b[i] = s[p - 1];
    }
    for (int i = 0; i < n; ++i) cout << b[i] << " ";
    return 0;
}
