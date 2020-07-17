//
// Created by huxiaoxu on 2020/7/17.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
ll b[N];
int n, m;


void update(ll x, ll y) {
    for (; x <= N; x += x & -x) {
        //    cout << x << endl;
        b[x] += y;
    }
}

int query(ll x) {
    int sum = 0;
    for (; x; x -= x & -x) {
        sum += b[x];
    }
    return sum;
}

int findIdx(vector<int>& ns, int x) {
    int l = 0, r = ns.size() - 1;
    while (l < r) {
        int m = l + ((r - l) >> 1);
        if (ns[m] >= x) {
            r = m;
        } else {
            l = m + 1;
        }
        //    cout << l << " " << r << endl;
    }
    return l + 1;
}

int main() {
    int l, r, x, c;
    vector<int> nums;
    unordered_map<int, int> hm;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> x >> c;
        hm[x] += c;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for (auto x : nums) {
        int idx = findIdx(nums, x);
        int value = hm[x];
        //    cout << "x:" << x << " idx:" << idx << " v:" << value << endl;
        update(idx, value);
    }

    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        int lidx = findIdx(nums, l), ridx = findIdx(nums, r);
        if (nums[lidx - 1] < l) ++lidx;
        if (nums[ridx - 1] > r) --ridx;
        //   cout << l << " " << lidx << " " << r << " " << ridx << endl;
        cout << query(ridx) - query(lidx - 1) << endl;
    }
    return 0;
}