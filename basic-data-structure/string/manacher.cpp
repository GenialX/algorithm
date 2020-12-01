// https://ac.nowcoder.com/acm/problem/14894
// solution https://ac.nowcoder.com/acm/problem/blogs/14894
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
char strA[maxn], strB[maxn], s[maxn];
int n, len, pA[maxn], pB[maxn];
void change(char *str) {
    scanf("%s", s);
    str[0] = '$';
    str[1] = '#';
    int j = 1;
    for(int i = 0; i < n; i++) {
        str[++j] = s[i];
        str[++j] = '#';
    }
    str[++j] = '\0';
}
void mannacher(char *str, int *p) {
    change(str);
    int id = 1, mx = 0;
    for(int i = 1; i <= len; i++) {
        if(mx > i) p[i] = min(p[2 * id - i], mx - i);
        else p[i] = 1;
        while(i - p[i] > 0 && str[i - p[i]] == str[i + p[i]]) p[i]++;
        if(i + p[i] > mx) {
            mx = p[i] + i;
            id = i;
        }
    }
}
int query() {
    int ans = 1;
    for(int i = 2; i <= len; i++) {
        int tmp = max(pA[i], pB[i - 2]);
        while(strA[i - tmp] == strB[i + tmp - 2]) tmp++;
        ans = max(ans, tmp);
    }
    return ans - 1;
}
int main() {
    scanf("%d", &n);
    len = n * 2 + 1;
    mannacher(strA, pA);
    mannacher(strB, pB);
    cout<<"sa:"<<strA<<endl;
    for (int i = 0; i < len; ++i) {
        cout<<"i:"<<i<<" pi:"<<pA[i]<<" ";
    }
    cout<<"sb:"<<strA<<endl;
    for (int i = 0; i < len; ++i) {
        cout<<"i:"<<i<<" pi:"<<pB[i]<<" ";
    }
    printf("%d\n", query());
    return 0;
}
