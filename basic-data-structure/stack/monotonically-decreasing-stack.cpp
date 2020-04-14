//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

#define N 400

int main() {
    int a[N], l[N], r[N];
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    stack<pair<int, int>> st; // value, index
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.top().first < a[i]) {
            r[st.top().second] = i;
            st.pop();
        }
        st.push({a[i], i});
    }
    st.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && st.top().first < a[i]) {
            l[st.top().second] = i;
            st.pop();
        }
        st.push({a[i], i});
    }

    cout << "L" << endl;
    for (int  i = 0; i < n; ++i ) cout << l[i] << " ";
    cout << endl;
    cout << "R" << endl;
    for (int  i = 0; i < n; ++i ) cout << r[i] << " ";
    cout << endl;

    return 0;
}
