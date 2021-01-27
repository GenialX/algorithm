#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Edge {
    int a,b,w;
};
vector<Edge> adj[100010];
int d[100010], vis[100010];
int main() {
    memset(d,0x3f,sizeof d);
    memset(vis,0,sizeof vis);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        int a, b, w;
        cin>>a>>b>>w;
        adj[a].push_back({a,b,w});
    }
    queue<int> q;
    q.push(1);
    vis[1]=1;
    d[1]=0;
    while(!q.empty()) {
        auto u=q.front();
        q.pop();
        vis[u]=0;
        for(auto &e : adj[u]) {
            int v=e.b, w=e.w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                if (vis[v]) continue;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    if (d[n] == 0x3f3f3f3f) cout<<"impossible"<<endl;
    else cout<<d[n]<<endl;
    
    return 0;
}
