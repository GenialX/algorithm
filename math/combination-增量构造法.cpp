#include<bits/stdc++.h>
int n;
int main() {
    cin>>n;
    vector<string> B{""};
    for(int i=0;i<n;++i) {
        for (int j=B.size();j--;) {
            B.push_back(B[j]+to_string(i));
        }
    }
    for(auto &v:B) {
        printf("%s \n", v.c_str());
    }
    return 0;
}
