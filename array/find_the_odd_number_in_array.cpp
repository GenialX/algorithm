/**
 * Find the odd num in the array.
 */
#include <iostream>
#include <vector>

using namespace std;

int find(vector<int> nums) {
    int l = 0, r = nums.size() - 1, m = 0;
    while (l <= r) {
        m = (l + r) / 2;
        // m == 0
        if (m == 0) {
            if (nums[m] != nums[m + 1]) {
                break;
            } else {
                l = m + 1;
            }
        } else if(m == r) {
            // m == r
            if (nums[m] != nums[m - 1]) {
                break;
            } else {
                r = m - 1;
            }
        } else {
            // 0 < m < r
            if (nums[m] != nums[m - 1] && nums[m] != nums[m + 1]) {
                break;
            } else {
                if ((m + 1) % 2 == 0) {
                    // even
                    if (nums[m] != nums[m - 1]) {
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                } else {
                    // odd
                    if (nums[m] != nums[m + 1]) {
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }
            }
        }
    }
    return nums[m];
}

int find_v2(vector<int>& nums) {
    int a = nums[0];
    for (int i = 1; i < (int)nums.size(); ++i) {
        a ^= nums[i];
    }
    return a;
}

int main() {
    vector<int> num{7,4,1,4,4,66,4,4,4,66,8,8,1};
    int a = find_v2(num);
    cout<<a<<endl;
    return 0;
}
