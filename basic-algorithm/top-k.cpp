// 找到第 k 小的数，O(nlogk)
#include<bits/stdc++.h>
using namespace std;
vector<int> q; // 升序
int findp(int x) {
    int l = 0, h = q.size() - 1;
    int m = 0;
    while (l < h) {
        m = (l + h) >> 1;
        if (q[m] >= x) {
            h = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}
void insert(int x) {
    if (q.empty()) {
        q.push_back(x);
        return;
    }
    int p = findp(x);
    if (p == q.size() - 1 && q.back() < p) {
        q.push_back(x);
    } else {
        q.insert(q.begin() + p, x);
    }
}
int main() {
    vector<int> nums{2,3,1,2,33,44,22,12,2};
    int k = 4;
    int n = nums.size();
    for (auto &x : nums) {
        if (q.size() < k || q.back() > x) {
            insert(x);
        }
        if (q.size() > k) {
            q.pop_back();
        }
    }
    if (!q.empty()) cout << q.back() << endl;
    else cout << "impossible" << endl;
    return 0;
}
