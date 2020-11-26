// 找到第 k 小的数，O(nlogk)
#include<bits/stdc++.h>
using namespace std;
vector<int> nums{2,3,1,2,33,44,22,12,2};
vector<int> q;
// 第一个大于等于 t 的索引位置(从0开始计数）
// 1 2 3 5  1:0, 4:3, 6:3
// 0 1 2 3   =    >    <
//
// 插入 1 -> 0 : 1 1 2 3 5
// 插入 4 -> 3 : 1 2 3 4 5
// 追加 6 -> 3 : 1 2 3 5 6
int findP(int t) {
    int l = 0, h = q.size() - 1, m;
    while (l < h) {
        m = l + h >> 1;
        if (q[m] >= t) {
            h = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}
int main() {
    int k = 4;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int t = nums[i];
        int p = findP(t);
        if (q.empty() || q[p] < t) {
            q.push_back(t);
        } else {
            q.insert(q.begin() + p, t);
        }
        if (q.size() > k) q.pop_back();
    }
    if (q.size() == k) {
        cout<<q.back()<<endl;
    } else {
        cout<<"impossible"<<endl;
    }
    return 0;
}
