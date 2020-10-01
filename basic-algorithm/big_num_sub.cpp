//
// Created by huxiaoxu on 2020/7/17.
//
#include<bits/stdc++.h>
using namespace std;

bool gt(vector<int>& A, vector<int>& B) {
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; --i) {
        if (A[i] == B[i]) continue;
        return A[i] > B[i];
    }
    return true;
};

vector<int> sub(vector<int>& A, vector<int>& B) {
    vector<int> C;
    for (int i = 0, c = 0; i < A.size(); ++i) {
        c = A[i] - c;
        if (i < B.size()) c = c - B[i];
        C.push_back((c + 10) % 10);
        if (c < 0) c = 1;
        else c = 0;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> A, B;
    for (int i = s1.size() - 1; i >= 0; --i) A.push_back(s1[i] - '0');
    for (int i = s2.size() - 1; i >= 0; --i) B.push_back(s2[i] - '0');

    vector<int> C;
    bool neg = false;
    if (gt(A, B)) {
        C = sub(A, B);
    } else {
        C = sub(B, A);
        cout << "-";
    }

    for (int i = C.size() - 1; i >= 0; --i) {
        cout << C[i];
    }

    return 0;
}