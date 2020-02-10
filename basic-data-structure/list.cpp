#include <iostream>

using namespace std;

// 邻接表：https://github.com/lydrainbowcat/tedukuri/blob/master/%E9%85%8D%E5%A5%97%E5%85%89%E7%9B%98/%E6%AD%A3%E6%96%87%E5%8C%85%E5%90%AB%E7%9A%84%E7%A8%8B%E5%BA%8F%E7%89%87%E6%AE%B5/0x13%20list.cpp
int tot = 1, n = 100010;
int head[n], next[n], ver[n], edge[n];

// 邻接表：加入有向边(x, y)，权值为z
void add(int x, int y, int z) {
    ver[++tot] = y, edge[tot] = z;
    next[tot] = head[x], head[x] = tot; // 在表头x处插入
}

// 邻接表：访问从x出发的所有边
for (int i = head[x]; i; i = next[x]) {
    int y = ver[i], z = edge[i];
    // 找到了一条有向边(x, y)，权值为z
}


int main() {
    
    return 0;
}
