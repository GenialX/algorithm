// 找到第 k 小的数，O(n)
#include<bits/stdc++.h>
using namespace std;
vector<int> nums{2,3,1,2,33,44,22,12,2};
int quick_sort(int l, int h, int k) {
    if (l >= h) return nums[l];
    int s = l - 1, e = h + 1, m = nums[l + h >> 1];
    // h h-1 l
    while(s < e) {
        while(nums[++s]<m);
        while(nums[--e]>m);
        if (s<e) swap(nums[s], nums[e]);
    }
    // l...m...h
    // l...e, e+1...h
    if (e - l + 1 >= k) {
        return quick_sort(l, e, k);
    } else {
        return quick_sort(e + 1, h, k - (e - l + 1));
    }
}
int main() {
    int k = 5;
    int n = nums.size();
    k = n - k + 1;
    if (k > n) {
        cout<<"impossible"<<endl;
    } else {
        cout<<quick_sort(0, n - 1, k)<<endl;
    }
    return 0;
}

