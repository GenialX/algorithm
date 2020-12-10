#include<bits/stdc++.h>
using namespace std;
// n 代表 0~n-1，输出所有组合情况
int n;
void print_subset(int s) {
    for (int i=0;i<n;++i) {
        if (s&(1<<i)) printf("%d ", i);
    }
    printf("\n");
}
int main() {
    cin>>n;
    for (int i=0;i<=(1<<n)-1;++i) {
        print_subset(i);
    }
    return 0;
}
