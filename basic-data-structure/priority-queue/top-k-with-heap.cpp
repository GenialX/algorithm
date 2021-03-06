#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int h[N], Size;
// 小根堆
void up(int u) {
    while(u/2 > 0 && h[u/2] > h[u]) {
        swap(h[u/2], h[u]);
        u = u>>1;
    }
}
void down(int u) {
    while (u < Size) {
        int v = u;
        if (u * 2 <= Size && h[v] > h[u * 2]) v = u * 2;
        if (u * 2 + 1 <= Size && h[v] > h[u * 2 + 1]) v = u * 2 + 1;
        if (u == v) break;
        swap(h[u], h[v]);
        u = v;
    }
}
void push(int u) {
    h[++Size] = u;
    up(Size);
}
int top() {
    return Size >= 1 ? h[1] : 0;
}
void pop() {
    h[1] = h[Size--];
    down(1);
}
int main() {
    vector<int> a{3,1,2,4,5};
    int n = a.size();
    int k = 2; // 第 K 大
    // codes...
    for (int i = 0; i < n; ++i) {
        int t = a[i];
        if (Size < k || top() < t) {
            push(t);
        }
        if (Size > k) pop();
    }
    if (Size == k) {
        cout<<top()<<endl;
    } else {
        cout<<"impossible"<<endl;
    }
    return 0;
}
