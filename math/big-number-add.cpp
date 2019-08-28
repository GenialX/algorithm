/**
 * 《程序设计导引及在线实践》 第七章 高精度计算
 * 7.1 例题：大整数加法
 */
#include <bits/stdc++.h>

using namespace std;

#define MAX_LEN 200

void printNumber(vector<int>& nums) {
    bool b = false;
    for (int i = MAX_LEN; i >= 0; --i) {
        if (b) {
            cout << nums[i];
        } else if (nums[i]) {
            cout << nums[i];
            b = true;
        }
    }
}

vector<int> add(string& line1, string& line2) {
    int i, j;

    vector<int> an1 = vector<int>(MAX_LEN + 10, 0);
    vector<int> an2 = vector<int>(MAX_LEN + 10, 0);

    j = 0;
    for (i = line1.size() - 1; i >= 0; --i) {
        an1[j++] = line1[i] - '0';
    }

    j = 0;
    for (i = line2.size() - 1; i >= 0; --i) {
        an2[j++] = line2[i] - '0';
    }

    for (int i = 0; i < MAX_LEN; ++i) {
        an1[i] += an2[i];
        if (an1[i] >= 10) {
            an1[i] -= 10;
            ++an1[i + 1];
        }
    }

    return an1;
}

int main() {
    string line1, line2;
    cin >> line1 >> line2;
    vector<int> ans = add(line1, line2);
    printNumber(ans);
    return 0;
}
