/**   - dwuy -

　　　　　 ／＞　   フ
　　　　　 | 　_　 _|
　 　　　 ／`ミ _x ノ
　　 　 /　　　 　 |
　　　 /　  ヽ　　 ?
　／￣|　　 |　|　|
　| (￣ヽ＿_ヽ_)_)
　＼二つ

**/
#include <bits/stdc++.h>

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define file(a) freopen(a".inp","r",stdin); freopen(a".out", "w",stdout)
#define fi first
#define se second
#define endl "\n"
#define len(s) int32_t(s.length())
#define MASK(k)(1LL<<k)
#define TASK ""

using namespace std;

typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef long long ll;

const long long OO=1e18;
const int INF=1e9;
const int MOD=INF+7;

int n, q;
int cla[200005];
int par[200005][25];
vector<int> G[200005];

void nhap(){
    cin >> n >> q;
    for(int i=1; i<n; i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void dfs(int u, int p){
    par[u][0]=p;
    cla[u]=cla[p]+1;
    for(int v: G[u]){
        if (v!=p) dfs(v, u);
    }
}

int lca(int a, int b){
    if (cla[a]<cla[b]) swap(a, b);
    for(int i=21; i>=0; i--)
        if (cla[par[a][i]]>=cla[b])
            a=par[a][i];
    if (a==b) return a;
    for(int i=21; i>=0; i--)
        if (par[a][i]!=par[b][i])
            a=par[a][i], b=par[b][i];
    return par[a][0];
}

void solve(){
    dfs(1, 1);
    for(int j=1; j<=21; j++)
        for(int i=1; i<=n; i++)
            if (par[i][j-1]!=0)
                par[i][j]=par[par[i][j-1]][j-1];
    while (q--){
        int u, v; cin >> u >> v;
        int ac=lca(u, v);
        cout << cla[u]+cla[v]-2*cla[ac] << endl;
    }
}

int32_t main(){
    fastIO;
    //file(TASK);
    nhap();
    solve();
    return 0;
}




