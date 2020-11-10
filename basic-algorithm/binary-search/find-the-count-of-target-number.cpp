// 非严格单调递增整型数组，找到目标值 T 在数组中出现的次数
// 二分 O(logn)
#include<bits/stdc++.h>
using namespace std;
int findl(vector<int>& nums, int t) {
    if (nums.empty()) return -1;
    int l=0, h=nums.size()-1, m=0;
    while(l<h) {
        m=l+h>>1;
        if(nums[m]>=t) {
            h=m;
        } else {
            l=m+1;
        }
    }
    return l;
}
int findu(vector<int>& nums, int t) {
    if (nums.empty()) return -1;
    int l=0, h=nums.size()-1, m=0;
    while(l<h) {
        m=l+h+1>>1;
        if(nums[m]<=t) {
            l=m;
        } else {
            h=m-1;
        }
    }
    return l;
}
int main() {
    vector<int> nums{1,2,3,3,4,5,6,6,8,8,8,8,10};
    int t = 8;
    int l = findl(nums, t), u = findu(nums, t);
    if (l==-1 || nums[l]!=t) {
        cout<<"impossible"<<endl;
    } else {
        cout<<u-l+1<<endl;
    }
    return 0;
}
