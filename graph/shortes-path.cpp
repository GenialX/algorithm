// Dijkstra 算法，O(n^2)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int a[3010][3010], d[3010];
bool v[3010];
// n for the size of vertices
// m for the size of edges
int n, m;

void dijktra() {

}

int main() {
    cin >> n >> m;
    // 构建邻接矩阵
    cout << 0x3f << endl;
    memset(a, 0x3f, sizeof(a));
    for (int i = 0; i < n; ++i) {
        //cout << a[1][i] << endl;
    }
    return 0;
}