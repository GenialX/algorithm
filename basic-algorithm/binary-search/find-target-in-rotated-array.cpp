// 严格单调递增(不重复)整型数组，在任意一个位置进行了一次反转，找到目标值 T 所在的位置
// O(logn)
#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int>nums{4,5,6,7,1,2,3};
    int t=7;
    cin>>t;
    int l=0, h=nums.size()-1, m;
    while(l<h) {
        m=l+h>>1;
        if(nums[m]>=nums[0]) {
            if(t<nums[0]) {
                l=m+1;
            } else {
                if(nums[m]>=t) {
                    h=m;
                } else {
                    l=m+1;
                }
            }
        } else {
            if(t>=nums[0]) {
                h=m-1;
            } else {
                if(nums[m]>=t) {
                    h=m;
                } else {
                    l=m+1;
                }
            }
        }
    }
    if(nums[l] == t) cout<<l<<endl;
    else cout<<"impossible"<<endl;
    return 0;
}
