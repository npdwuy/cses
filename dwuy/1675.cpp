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
tuple<int, int, int> edges[200005];

void nhap(){
    cin >> n >> m;
    for(int  i=1; i<=m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        edges[i]={c, u, v};
    }
}

int p[100005];
int sz[100005];

int fp(int u){
    return (u==p[u])? u:p[u]=fp(p[u]);
}

bool unon(int u, int v){
    u=fp(u); v=fp(v);
    if(u==v) return 0;
    if(sz[u]>sz[v]) swap(u, v);
    sz[v]+=sz[u];
    p[u]=p[v];
    return 1;
}

void solve(){
    for(int i=1; i<=n; i++) p[i]=i, sz[i]=1;
    int ans=0;
    sort(edges+1, edges+1+m);
    for(int i=1; i<=m; i++){
        int u=get<1>(edges[i]);
        int v=get<2>(edges[i]);
        int c=get<0>(edges[i]);
        if(unon(u, v)) ans+=c;
    }
    int p=fp(1);
    for(int i=1; i<=n; i++){
        if(fp(i)!=p){
            cout << "IMPOSSIBLE";
            return;
        }
    }
    cout << ans;
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}

