/// (⌐■_■): "have you define int long long, dwuy?"
///  dwuy : "already"
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

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

int n, m, k;
vector<ii> G[200005];

void nhap(){
    cin >> n >> m >> k;
    for(int i=1; i<=m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        G[u].push_back({v, c});
    }
}

void solve(){
    priority_queue<ii, vector<ii>, greater<ii>> Q;
    Q.push({0, 1});
    int cnt=0;
    vector<int> vist(n+5, 0);
    while (Q.size()){
        auto [c, u] = Q.top();
        Q.pop();
        vist[u]++;
        if(u==n){
            cout << c << " ";
            if(vist[u]==k) return;
        }
        if(vist[u]>k) continue;
        for(auto [v, _c]: G[u]) Q.push({_c+c, v});
    }
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}
