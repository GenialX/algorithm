#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], n, s[N], t; // s[1 2 3 ...]
int main() {
    cin >> n;
    s[0] = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        while (t && a[s[t]] >= a[i]) --t;
        s[++t] = i;
        cout << s[t - 1] << " ";
    }
    return 0;
}
