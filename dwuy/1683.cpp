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

int n, m;
vector<int> G[200005];
vector<int> rG[200005];
void nhap(){
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        rG[v].push_back(u);
    }
}

int cnt=0;
int ans[200005];
stack<int> topo;
bitset<200005> vist=0;

void dfs1(int u){
    vist[u]=1;
    for(int v: G[u]) if(!vist[v]) dfs1(v);
    topo.push(u);
}

void dfs2(int u){
    ans[u]=cnt;
    for(int v: rG[u]) if(ans[v]==0) dfs2(v);
}

void solve(){
    for(int i=1; i<=n; i++) if(!vist[i]) vist[i]=1, dfs1(i);
    while (topo.size()){
        int u=topo.top(); topo.pop();
        if(ans[u]) continue;
        ++cnt; dfs2(u);
    }
    cout << cnt << endl;
    for(int i=1; i<=n; i++) cout << ans[i] << " ";
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}
