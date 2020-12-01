// manacher 模板，未测试 OJ
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
// s 是原始字符串，s1 是处理后的字符串
char s[maxn], s1[maxn];
// T 代表测试用例个数，len = len(s), len1 = len(s1)，p1 是 s1 的 p 数组
int T, len, len2, p1[maxn];
void change(char *str) {
    str[0] = '$'; str[1] = '#';
    int j = 2;
    for (int i = 0; i < len; ++i) {
        str[j++] = s[i]; str[j++] = '#';
    }
    str[j] = '\0';
}
void manacher(char *str, int *p) {
    int id = 1, mx = 0;
    for (int i = 1; i <= len2; ++i) {
        if (mx > i) p[i] = min(p[2*id - i], mx - i);
        else p[i] = 1;
        while(i > p[i] && str[i-p[i]] == str[i+p[i]]) ++p[i];
        if (i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
    }
}
void print_p(int *p) {
    for(int i = 0; i <= len2; ++i) {
        cout<<"i:"<<i<<" p[i]:"<<p[i]<<" ";
    }
    cout<<endl;
}
int main() {
    cin>>T;
    while(T--) {
        cin>>len;
        len2 = 2 * len + 1;
        scanf("%s", s);
        change(s1);
        manacher(s1, p1);
        print_p(p1);
    }
    return 0;
}
