/// (⌐■_■): "have you defined int long long, dwuy?"
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

int n;
vector<int> G[200005];
int cnt[200005];

void nhap(){
    cin >> n;
    for(int i=2; i<=n; i++){
        int u; cin >> u;
        G[u].push_back(i);
    }
}

void dfs(int u=1){
    cnt[u]=1;
    for(int v: G[u]){
        dfs(v);
        cnt[u]+=cnt[v];
    }
}



int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    dfs();
    for(int i=1; i<=n; i++) cout << cnt[i] -1  << ' ';
    return 0;
}
