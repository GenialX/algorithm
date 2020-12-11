// aw843
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int N = 1e5 + 5;
ULL h[N], p[N];
char str[N];
int n, m, P = 131;
int getHash(int l, int r) {
   return h[r] - h[l - 1] * p[r - l + 1];
}
int main() {
    scanf("%d%d%s", &n, &m, str + 1);
    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }
    while (m--) {
        int l1, l2, r1, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (getHash(l1, r1) == getHash(l2, r2)) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}
