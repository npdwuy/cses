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
int ans[200005];
vector<int> G[200005];
bitset<200005> vist=0;

void nhap(){
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void dfs(int u){
    vist[u]=1;
    for(int v: G[u]){
        if(!vist[v]) ans[v]=!ans[u], dfs(v);
        else if (ans[u]==ans[v]){
            cout <<"IMPOSSIBLE";
            exit(0);
        }
    }
}

void solve(){
    for(int i=1; i<=n; i++){
        if(vist[i]) continue;
        ans[i]=0;
        dfs(i);
    }
    for(int i=1; i<=n; i++) cout << ans[i]+1 << " ";
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}
