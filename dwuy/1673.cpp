/// (⌐■_■): "have you define int long long, dwuy?"
///  dwuy : "already"
#include <bits/stdc++.h>

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define file(a) freopen(a".inp","r",stdin); freopen(a".out", "w",stdout)
#define fi first
#define se second
#define endl "\n"
#define len(s) int32_t(s.length())
#define MASK(k)(1LL<<k)
#define TASK ""
#define int long long

using namespace std;

typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef long long ll;

const long long OO=1e18;
const int INF=1e9;
const int MOD=INF+7;

struct Edge{
    int u,  v;
    int c;

    Edge(int _u=0, int _v=0, int _c=0){
        u=_u, v=_v, c=_c;
    }
};

int n, m;
int d[200005];
bool vis[200005];
bool vis2[200005];
bool check[200005];
Edge edges[200005];
vector<int> G[200005];
vector<int> rG[200005];

void nhap(){
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        G[u].push_back(v);
        rG[v].push_back(u);
        edges[i]=Edge(u, v, c);
    }
}

void dfs(int u){
    for(int v: G[u]) if(!vis[v]) vis[v]=1, dfs(v);
}
void dfs2(int u){
    for(int v: rG[u]) if(!vis2[v]) vis2[v]=1, dfs2(v);
}

void solve(){
//    memset(d, 0x3f, sizeof(d));
    for(int i=1; i<=n; i++) d[i]=-OO;
    d[1]=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int u=edges[j].u;
            int v=edges[j].v;
            int c=edges[j].c;
            if(d[v]<d[u]+c) d[v]=d[u]+c;
        }
    }
    memset(vis, 0, sizeof(vis));
    memset(vis2, 0, sizeof(vis2));
    dfs(1);
    dfs2(n);
    vis[1]=vis2[n]=1;
    for(int i=1; i<=m; i++){
        int u=edges[i].u;
        int v=edges[i].v;
        int c=edges[i].c;
//        cout << u << " " << v << " " << d[v] << " " << d[u] << " " << c << " " << vis[v] << " " << vis2[v] << endl;
        if(d[v]<d[u]+c && vis[v] && vis2[v]){
//                cout << u << " " << v << " " << d[u] << " " << d[v] << endl;
            cout << -1;
            return;
        }
    }
//    d[n]=max(d[n], -1ll);
    cout << d[n];

}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}
