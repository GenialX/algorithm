#include<bits/stdc++.h>
using namespace std;
int main() {
    int t; 
    cin >> t;
    while(t--) {
        int x, cnt = 0;
        cin >> x;
        while (x) {
            x -= x & (-x);
            ++cnt;
        }
        cout << cnt << " ";
    }
    return 0;
}
