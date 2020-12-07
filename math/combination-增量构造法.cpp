#include<bits/stdc++.h>
using namespace std;
// n 代表 0~n-1，输出所有组合情况
int main() {
    int n;
    cin>>n;
    vector<string> B{""};
    // i from 0 -> n-1
    for(int i = 0; i < n; ++i) {
        for (int j = B.size();j--;) B.push_back(B[j]+to_string(i));
    }
    for(auto &v:B) cout<<v<<endl;
    return 0;
}
