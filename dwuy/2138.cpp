/// (⌐■_■): "have you defined int long long, dwuy?"
///  dwuy : "already"
#include <bits/stdc++.h>

#pragma GCC target("popcnt")

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

int n, m;
bitset<50001> d[50001];
vector<int> G[200005];

void nhap(){
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
}

bitset<50005> vist=0;
void dfs(int u){
    vist[u]=1;
    d[u].set(u);
    for(int v: G[u]){
        if(!vist[v]) dfs(v);
        d[u]|=d[v];
    }
}

void solve(){
    for(int i=1; i<=n; i++) if(!vist[i]) dfs(i);
    for(int i=1; i<=n; i++) cout << d[i].count() << " ";
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}

