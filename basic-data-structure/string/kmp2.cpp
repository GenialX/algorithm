#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
int Next[maxn];
char t[maxn], p[maxn];
int n,m;

void print_a(int *a, int l) {
    for (int i=0;i<l;++i) printf("a[%d]: %d ", i, a[i]);
}

void getNext(char *p, int *Next) {
    for (int i=0,j=1;j<m;++j) {
        while(i>0 && p[i] != p[j]) i=Next[i-1];
        if(p[i]==p[j])++i;
        Next[j]=i;
    }
}
int kmp(char *t, char *p) {
    getNext(p, Next);
    //print_a(Next, m);
    for (int i=0,j=0;i<n;++i) {
        printf("i:%d j:%d ", i, j);
        while(j > 0 && t[i] != p[j]) j=Next[j-1];
        if (t[i] == p[j]) ++j;
        if (j==m) return i-j+1;
    }
    return -1;
}
int main() {
    scanf("%s%s", t, p);
    n=strlen(t),m=strlen(p);
    cout<<kmp(t, p)<<endl;
    return 0;
}
