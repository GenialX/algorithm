#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int Maxn = 100050;
int cnt[Maxn + 5];
int rnk[Maxn + 5], a[Maxn + 5],b[Maxn + 5];
int istr[Maxn + 5];
int sa[Maxn + 5];
char str[Maxn + 5];

inline void radix(int str[], int pos[], int sa[], int n, int m) {
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) cnt[str[pos[i]]]++;
	for (int i = 1; i <= m; i++) cnt[i] += cnt[i-1];
	for (int i = n-1; i >= 0; i--) sa[--cnt[str[pos[i]]]] = pos[i];
}

inline void SA(int str[],int sa[],int n, int m){
	for (int i = 0; i < n; i++) rnk[i] = i;
	radix(str, rnk, sa, n, m);
	rnk[sa[0]] = 0;
	for (int i = 1; i < n; i++)
		rnk[sa[i]] = rnk[sa[i-1]] + (str[sa[i]] != str[sa[i-1]]);

    for (int k = 1; k <=n; k <<= 1) {
        for (int j = 0; j < n; j++) {
            a[j] = rnk[j] + 1;
            b[j] = (j + k >= n ? 0 : rnk[j + k] + 1);
            sa[j] = j;
        }
        radix(b, sa, rnk, n, n);
        radix(a, rnk, sa, n, n);
        rnk[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            rnk[sa[i]] = rnk[sa[i - 1]] + (a[sa[i]] != a[sa[i - 1]] || b[sa[i]] != b[sa[i - 1]]);
    }
}

int main() {
    string s = "banana";
    int len = s.length();
    for (int i = 0; i < len; i++) istr[i] = s[i] - 'a' + 1, str[i] = s[i];
    str[len] = 0;

    SA(istr, sa, len, 26);
    string ans(&str[sa[len-1]]);
    cout<<ans<<endl;
    return 0;
}
