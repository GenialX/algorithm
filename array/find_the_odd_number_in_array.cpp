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

int main() {
    vector<int> num{1,1,4,4,4,4,4,4,66,66,7,8,8};
    int a = find(num);
    cout<<a<<endl;
    return 0;
}
