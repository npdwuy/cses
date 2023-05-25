#include <bits/stdc++.h>

using namespace std;

const int N=100005;

struct Edge{
    int u, v;
    bool used;
    Edge(int _u=0, int _v=0){
        u=_u;
        v=_v;
        used=false;
    }
};

int n, m, ans=1e9+7;
vector<int> G[N];
vector<int> T[N];
Edge edges[300005];
int cla[N];
int par[N][22];
bitset<N> visited;


void nhap(){
    cin >> n >> m;
    int u, v;
    for(int i=1; i<=m; i++){
        cin >> u >> v;
        edges[i]=Edge(u, v);
        G[u].push_back(i);
        G[v].push_back(i);
    }
}

void bfs(int u){
    cla[u]=1;
    queue<int> Q;
    Q.push(u);
    visited[u]=1;
    while (Q.size()){
        u=Q.front();
        Q.pop();
        for(int i:G[u]){
            int v=edges[i].u^edges[i].v^u;
            if (visited[v]) continue;
            cla[v]=cla[u]+1;
            visited[v]=1;
            par[v][0]=u;
            Q.push(v);
        }
    }
}

void process(){
    for(int j=1; j<=21; j++){
        for(int  i=1; i<=n; i++){
            if (par[i][j-1]!=0){
                par[i][j]=par[par[i][j-1]][j-1];
            }
        }
    }
}

int lca(int u, int v){
    if (cla[u]<cla[v]) swap(u, v);
    for(int i=21; i>=0; i--)
        if (cla[par[u][i]]>=cla[v]) u=par[u][i];
    if (u==v) return u;
    for(int i=21; i>=0; i--)
        if (par[u][i]!=par[v][i]) u=par[u][i], v=par[v][i];
    return par[u][0];
}

void BFS(int u){
    queue<int> Q;
    Q.push(u);
    visited[u]=1;
    while (Q.size()){
        u=Q.front();
        Q.pop();
        for(int i:G[u]){
            int v=edges[i].u^edges[i].v^u;
            if (!visited[v]){
                visited[v]=1;
                edges[i].used=1;
                Q.push(v);
            }
            else if (!edges[i].used){
                int root=lca(u, v);
                edges[i].used=1;
                ans=min(ans, cla[u]-cla[root]+1+cla[v]-cla[root]);
            }
        }
    }
}

void solve(){
    cla[1]=0;
    for(int i=1; i<=n; i++)
        if (!visited[i]) bfs(i);
    process();
    visited=0;
    for(int i=1; i<=n; i++)
        if (!visited[i]) BFS(i);
    cout << ans << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    nhap();
    solve();
    return 0;
}
