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
vector<ii> G[200005];

void nhap(){
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        G[u].push_back({v, c});
    }
}

int d[2][200005];

void solve(){
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    memset(d, 0x3f, sizeof(d));
    Q.push({0, 1});
    d[0][1]=d[1][1]=0;
    while (Q.size()){
        int du=Q.top().fi;
        int u=abs(Q.top().se);
        bool mode = Q.top().se<0;
        Q.pop();
//        cerr << "    " << u << " " << du << " " << mode << endl;
        if(du!=d[mode][u]) continue;
        for(ii tmp: G[u]){
            int v=tmp.fi;
            int c=tmp.se+du;
            if (c<d[mode][v]){
                d[mode][v]=c;
                Q.push({c, v*(mode? -1:1)});
            }
            if(mode) continue;
            c=du+(tmp.se>>1);
            if(c<d[1][v]){
                d[1][v]=c;
                Q.push({c, -v});
            }
        }
    }
//    for(int i=1; i<=n; i++) cout << d[1][i] << " " << i << endl;
    cout << d[1][n];
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}
