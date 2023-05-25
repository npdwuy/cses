#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int> G[200005];
int cnt[200005];
int d[200005];

void nhap(){
    cin >> n;
    for(int i=1; i<n; i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void dfs(int u=1, int pu=0){
    cnt[u]=1;
    for(int v: G[u]){
        if(v==pu) continue;
        dfs(v, u);
        cnt[u]+=cnt[v];
        d[u]+=d[v]+cnt[v];
    }
}

void dwuy(int u=1, int pu=0){
    for(int v: G[u]){
        if(v==pu) continue;
        d[v]=d[u]+n-2*cnt[v];
        dwuy(v, u);
    }
}

void solve(){
    dfs();
    dwuy();
    for(int i=1; i<=n; i++) cout << d[i] << " ";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    nhap();
    solve();

    return 0;
}
