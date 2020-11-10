#include<bits/stdc++.h>
using namespace std;
// 输出第 n 行
int main() {
    //        1
    //      1   1
    //    1   2   1
    //  1   3   3   1
    //1   4   6   4   1
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 2) {
        cout << "1 1" << endl;
        return 0;
    }
    vector<int> nums(n / 2 + 5, 0);
    nums = {0, 1, 1}; // idx from 1

    for (int i = 3; i <= n; ++i) {
        int limit = i / 2;
        if (i % 2 == 1) {
            nums[limit + 1] = nums[limit] * 2;
        }
        for (int j = limit; j >= 1; --j) {
            nums[j] = nums[j] + nums[j - 1];
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (i <= n / 2) {
            cout << nums[i] << " ";
        } else {
            if (n % 2 == 0) {
                cout << nums[n / 2 + 1 - (i - n / 2)] << " " ;
            } else {
                cout << nums[n / 2 + 2 - (i - n / 2)] << " ";
            }
        }
    }
    return 0;
}


