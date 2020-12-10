// 《算法竞赛入门经典2》p286
#include<bits/stdc++.h>
using namespace std;
int n;
// 枚举n个元素的子集的子集
void print_subset(int s) {
    printf("\n");
    for (int i=0;i<n;++i) {
        if (s&(1<<i)) printf("%d ", i);
    }
    printf("\n\n");
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<(1<<n);++i) {
        printf("i:%d\n", i);
        print_subset(i);
        for(int j=i;j;j=(j-1)&i) {
            printf("j:%d\n",j);
            print_subset(j);
        }
    }
    return 0;
}
