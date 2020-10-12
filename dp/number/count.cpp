//
// Created by huxiaoxu on 2020/9/17.
//
#include<bits/stdc++.h>
using namespace std;
int f[15][15][2]; // f(i, st, op) op = 0 for eq, op = 1 for 2 lt
int a, b;

int* solve(vector<int> nums) {
    int aans[10];
    memset(aans, 0, sizeof aans);
    int l = nums.size();
    if (l == 0) return aans;
    memset(f, 0, sizeof f);
    for (int st = 0; st <= 9; ++st) {
        if (st == nums[0]) f[0][st][0] = 1;
        if (st != 0 && l > 1) f[0][st][1] = 1;
        //cout << "st:" << st << " op=0: " << f[0][st][0] << " op=1: " << f[0][st][1] << endl;
    }
    // cal for a
    for (int i = 1; i < l; ++i) {
        for (int st = 0; st <= 9; ++st) {
            // op == 0, eq
            f[i][st][0] += f[i - 1][st][0] + ((st == nums[i]) ? 1 : 0);
            //cout << "st: " << st << " for op=0: " << f[i][st][0] << endl;

            // op == 1, lt
            // pre op == 0, eq
            if (st < nums[i]) {
                f[i][st][1] += f[i - 1][st][0] + ((st == nums[i]) ? 1 : 0);
            }
            // pre op == 1, lt
            f[i][st][1] += f[i - 1][st][1] + ((st == nums[i]) ? 1 : 0);
        }
    }
    memset(aans, 0, sizeof aans);
    for (int st = 0; st <= 9; ++st) {
        aans[st] += f[l - 1][st][0] + f[l - 1][st][1];
        cout << "{st:" << st << " cnt:" << aans[st] << " eq:" << f[l - 1][st][0] << " lt:" << f[l - 1][st][1] << "} " << endl;
    }
    return aans;
};
int main() {
    cin >> a >> b;
    --a;

    vector<int> av{};
    vector<int> bv{};
    while (a) {
        av.insert(av.begin(), a % 10);
        a /= 10;
    }
    while (b) {
        bv.insert(bv.begin(), b % 10);
        b /= 10;
    }
    int *aans = solve(av);
    int *bans = solve(bv);
    for (int i = 0; i < 10; ++i) {
        cout << bans[i] - aans[i] << " ";
    }
    // a  1 0
    // av 1 0
    return 0;
}

