#include <bits/stdc++.h>
using namespace std;
pair<bool, int>  helper(string& str, int start) {
    if (start >= str.size()) return {true, 0};
    int i = start, n = str.size();
    if (str.size() - start <= 2 || str[i++] != '(') return {false, -1};
    int close = 0, last = 0; // 0 emtpy, 1 number, 2 operator
    for (; i < n;) {
        char c = str[i];
        if (c == ' ') {
            ++i;
            continue;
        }
        if (c == '(') {
            auto next = helper(str, i);
            if (next.first == false) return {false, -1};
            i += next.second;
            last = 1;
        } else if (c == '+' || c == '-') {
            if (last == 0 || last == 2) return {false, -1};
            last = 2, ++i;
        } else if (c == ')') {
            close = 1;
            break;
        } else {
            last = 1, ++i;
        }
    }
    if (i == n) --i;
    int len = i - start + 1;
    if (last == 2 || close == 0 || len <= 2) return {false, -1};
    return {true, len};
}
void solve() {
    string str;
    cin >> str;
    if (str.size() == 0) {
        cout << "True" << endl;
        return;
    }
    str.insert(str.begin(), '(');
    str.push_back(')');
    auto info = helper(str, 0);
    if (info.first) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
}

int main() {
    int T;
    cin >> T;
    int i = 0;
    while (i < T) {
        solve();
        ++i;
    }
    return 0;
}
