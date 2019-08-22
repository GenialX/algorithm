#include <iostream>

using namespace std;

int main() {
    string s = "abceabcdgg";
    int n = s.length();
    int k = 0, i = 0, j = 1;
    while (k < n && i < n && j < n) {
        if (s[(i + k) % n] == s[(j + k) % n]) {
            k++;
        } else {
            s[(i + k) % n] > s[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
            if (i == j) j++;
            k = 0;
        }
    }
    i = min(i, j);
    cout << s.substr(i) + s.substr(0, i) << endl;
    return 0;
}

