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

int n, m, q;
int d[505][505];

void nhap(){
    cin >> n >> m >> q;
    memset(d, 0x3f, sizeof(d));
    for(int i=1; i<=m; i++){
        int u, v, c; cin >> u >> v >> c;
        d[u][v]=d[v][u]=min(d[u][v], c);
    }
}

void solve(){
    for(int i=1; i<=n; i++) d[i][i]=0;
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << ((d[u][v]==d[0][0])? -1:d[u][v]) << endl;
    }

}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}
