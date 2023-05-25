/// (⌐■_■): "have you defined int long long, dwuy?"
///  dwuy : "already"
#include <bits/stdc++.h>

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define file(a) freopen(a".inp","r",stdin); freopen(a".out", "w",stdout)
#define fi first
#define se second
#define endl "\n"
#define len(s) int32_t(s.length())
#define MASK(k)(1LL<<(k))
#define TASK ""
#define int long long

using namespace std;

typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef long long ll;

const long long OO=1e18;
const int INF=1e9;
const int MOD=INF+7;
const int MX = 5e4+1;

int n, m, q, cnt;
int id[MX];
vector<int> topo;
vector<int> G[MX];
vector<int> T[MX];
vector<int> rG[MX];
bitset<MX> vist=0;
bitset<MX> d[MX];

void nhap(){
    cin >> n >> m >> q;
    for(int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        rG[v].push_back(u);
    }
}
void gettopo(int u){
    vist[u]=1;
    for(int v: G[u]) if(!vist[v]) gettopo(v);
    topo.push_back(u);
}

void SCC(int u){
    vist[u]=1;
    for(int v: rG[u]) if (!vist[v]) SCC(v);
    id[u] = cnt;
}

void dfs(int u){
    vist[u]=1;
    d[u][u]=1;
    for(int v: T[u]){
        if(!vist[v]) dfs(v);
        d[u] |= d[v];
    }
}

void solve(){
    for(int i=1; i<=n; i++) if(!vist[i]) gettopo(i);
    reverse(topo.begin(), topo.end());

    vist=0;
    for(int u: topo){
        if(vist[u]) continue;
        cnt++;
        SCC(u);
    }

    for(int i=1; i<=n; i++){
        for(int j: G[i]) if(id[j]!=id[i]) T[id[i]].push_back(id[j]);
    }
    for(int i=1; i<=cnt; i++){
        sort(T[i].begin(), T[i].end());
        T[i].erase(unique(T[i].begin(), T[i].end()), T[i].end());
    }

    vist=0;
    for(int i=1; i<=cnt; i++) if(!vist[i]) dfs(i);
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << (d[id[u]][id[v]]? "YES":"NO") << endl;
    }
}


int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}


