#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, B[maxn];
// n 代表 0~n-1，输出所有组合情况
void print_subset(int n, int *B, int cur) {
    // cur 要访问第 cur 个元素（从0开始计数）
    if (cur == n) {
        for(int i = 0; i < n; ++i) if (B[i]) printf("%d ", i);
        printf("\n");
        return;
    }
    // 使用
    B[cur] = 1;
    print_subset(n, B, cur+1);
    B[cur] = 0;
    // 不使用
    print_subset(n, B, cur+1);
}
int main() {
    cin>>n;
    memset(B,0,sizeof B);
    print_subset(n, B, 0);
    return 0;
}
