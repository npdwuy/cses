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

int n;
int half;
vector<int> G[200005];

void nhap(){
    cin >> n;
    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    half=n>>1;
}

int cnt[200005];
void dfs(int u, int p){
    cnt[u]=1;
    for(int v: G[u]){
        if(v!=p) dfs(v, u), cnt[u]+=cnt[v];
    }
    for(int v: G[u]) if (v!=p && cnt[v]>half) return;
    if(n-cnt[u]>half) return;
    cout << u;
    exit(0);
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    dfs(1, 0);

    return 0;
}
