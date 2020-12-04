// 找到第 k 大的数，O(n)
#include<bits/stdc++.h>
using namespace std;
vector<int> nums{3,1,2,4,5};
int quick_sort(int l, int h, int k) {
    if (l == h) return nums[l];
    int i = l - 1, j = h + 1, m = nums[l + h >> 1];
    while (i < j) {
        while(nums[++i] < m);
        while(nums[--j] > m);
        if (i < j) swap(nums[i], nums[j]);
    }
    // l.....j, j+1....h
    int lcnt = j-l+1;
    if (lcnt >= k) return quick_sort(l, j, k);
    else return quick_sort(j+1, h, k-lcnt);
}
int main() {
    int k = 4;
    int n = nums.size();
    k = n - k + 1;
    if (k > n) {
        cout<<"impossible"<<endl;
    } else {
        cout<<quick_sort(0, n - 1, k)<<endl;
    }
    return 0;
}

