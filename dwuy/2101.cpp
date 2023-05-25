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
#define TASK "test"

using namespace std;

typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef long long ll;

const long long OO=1e18;
const int INF=1e9;
const int MOD=INF+7;

int n, m, q, lg, cnt;
int d[200005];
int cla[200005];
int vist[200005];
int p[200005][25];
int M[200005][25];
vector<ii> G[200005];
vector<ii> T[200005];

void MST(int u){
    priority_queue<ii, vector<ii>, greater<ii>> Q;;
    cla[u]=1;
    p[u][0]=u;
    d[u]=0;
    vist[u]=cnt;
    Q.push({0, u});
    while (Q.size()){
        int u=Q.top().se;
        int du=Q.top().fi;
        Q.pop(); vist[u]=cnt;
        if (du!=d[u]) continue;
        d[u]=0;
        for(ii tam: G[u]){
            int v=tam.fi;
            int c=tam.se;
            if (c<d[v]){
                d[v]=c;
                p[v][0]=u;
                M[v][0]=c;
                cla[v]=cla[u]+1;
                Q.push({c, v});
            }
        }
    }
}

int LCA(int u, int v){
    int res=0;
    if (cla[u]<cla[v]) swap(u, v);
    for(int i=lg; i>=0; i--)
        if (cla[p[u][i]]>=cla[v])
            res=max(res, M[u][i]),
            u=p[u][i];
    if (u==v) return res;
    for(int i=lg; i>=0; i--)
        if (p[u][i]!=p[v][i])
            res=max(res, max(M[u][i], M[v][i])),
            u=p[u][i], v=p[v][i];
    return max(M[u][0], max(M[v][0], res));
}

void solve(){
    cin >> n >> m >> q;
    for(int i=1; i<=m; i++){
        int u, v; cin >> u >> v;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }
    memset(d, 0x3f, sizeof(d));
    for(int i=1; i<=n; i++){
        if (vist[i]) continue;
        ++cnt;
        MST(i);
    }
    lg=__lg(n)+1;
    for(int j=1; j<=lg; j++)
        for(int i=1; i<=n; i++)
            if (p[i][j-1])
                p[i][j]=p[p[i][j-1]][j-1],
                M[i][j]=max(M[i][j-1], M[p[i][j-1]][j-1]);
    while (q--){
        int u, v;
        cin >> u >> v;
        if (vist[u]!=vist[v]) cout << -1 << endl;
        else cout << LCA(u, v) << endl;

    }
}


int32_t main(){
    fastIO;
//    file(TASK);
    solve();
    return 0;
}





