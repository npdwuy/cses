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

void nhap(){
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
//        G[v].push_back(u);
    }
}

bool vist[200005];
stack<int> topo;

void dfs(int u){
    for(int v: G[u]) if(!vist[v]) vist[v]=1, dfs(v);
    topo.push(u);
}

int dp[200005];
void solve(){
    dfs(1);
    dp[1]=1;
    while(topo.size()){
        int u=topo.top();
        topo.pop();
        for(int v: G[u]) dp[v]=(dp[v]+dp[u])%MOD;
    }
    cout << dp[n];
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}
