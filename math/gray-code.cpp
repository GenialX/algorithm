#include<bits/stdc++.h>
int n=10;
int b[1050];
void print_g() {
    for (int i=0;i<(1<<n);++i) {
        printf("%d ",i^(i>>1));
        b[i]=i^(i>>1);
    }
    printf("\n");
}
void print_b() {
    for (int i=0;i<(1<<n);++i) {
        int mask = b[i];
        int num = b[i];
        while (mask) {
            mask >>= 1;
            num ^= mask;
        }
        printf("%d ", num);
    }
    printf("\n");
}
int main() {
    print_g();
    print_b();
    return 0;
}
