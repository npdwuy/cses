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
int d[200005];
vector<ii> G[200005];

void nhap(){
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u, v, c; cin >> u >> v >> c;
        G[u].push_back({v, c});
    }
}

void solve(){
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    memset(d, 0x3f, sizeof(d));
    d[1]=0;
    Q.push({0, 1});
    while (Q.size()){
        int u=Q.top().se;
        int du=Q.top().fi;
        Q.pop();
        if(du!=d[u]) continue;
        for(ii tmp: G[u]){
            int v=tmp.fi;
            int c=tmp.se+du;
            if(c<d[v]){
                d[v]=c;
                Q.push({c, v});
            }
        }
    }
    for(int i=1; i<=n; i++) cout << d[i] << " ";
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}
