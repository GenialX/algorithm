//
// Created by huxiaoxu on 2020/7/17.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int A[N], B[N], x, n, m;

int main() {
    /**10 10 30
    9 13 15 19 20 26 40 43 44 49
    1 5 6 21 22 28 31 32 46 49
    **/
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &A[i]);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &B[i]);
    }
    int i = 1, j = m;
    while (i <= n && j >= 1) {
        cout << i << " " << j << endl;
        if (A[i] + B[j] == x) {
            cout << (i - 1) << " " << (j - 1) << endl;
            break;
        }
        if (A[i] + B[j] < x) {
            ++i;
        } else {
            --j;
        }
    }
    return 0;
}