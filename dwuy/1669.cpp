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

struct Edge{
    int u, v;
    bool used;

    Edge(int U=0, int V=0){
        u=U; v=V;
        used=0;
    }
};

int n, m, ans;
int p[200005];
bool vist[200005];
vector<int> tmp;
vector<int> G[200005];
Edge edges[200005];

void nhap(){
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u, v; cin >> u >> v;
        edges[i]=Edge(u, v);
        G[u].push_back(i);
        G[v].push_back(i);
    }
}

void dfs(int u){
    if (ans) return;
    vist[u]=1;
    for(int i: G[u]){
        if(edges[i].used) continue;
        int v=edges[i].u^edges[i].v^u;
        if(vist[v]){
            ans=u;
            tmp.push_back(v);
            p[v]=-1;
            return;
        }
        else p[v]=u, edges[i].used=1, dfs(v);
        if(ans)return;
    }
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    for(int i=1; i<=n; i++){
        dfs(i);
        if(ans) break;
    }
    if (ans){
        while (ans!=-1) tmp.push_back(ans), ans=p[ans];
        cout << tmp.size() << endl;
        for(int x: tmp) cout << x << " ";
    }
    else cout <<"IMPOSSIBLE";
    return 0;
}


