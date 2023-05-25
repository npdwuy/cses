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
vector<int> G[200005];
int Max[200005];

void nhap(){
    cin >> n;
    for(int i=1; i<n; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void dfs(int u=1, int pu=0){
    Max[u]=1;
    for(int v: G[u]){
        if (v==pu) continue;
        dfs(v, u);
        Max[u]=max(Max[u], Max[v]+1);
    }
}

void htphong(int u=1, int pu=0, int pre=0){
    vector<int> pMax(G[u].size()+1, 0), sMax(G[u].size()+1, 0);
    for(int i=0; i<(int)G[u].size(); i++){
        int v=G[u][i];
//        if(v==pu) continue;
        pMax[i]=max((i>0? pMax[i-1]:0), v!=pu? Max[v]:0);
    }
    for(int i=(int)(G[u].size())-1; i>=0; i--){
        int v=G[u][i];
//        if(v==pu) continue;
        sMax[i]=max(sMax[i+1], v!=pu? Max[v]:0);
    }
    for(int i=0; i<(int)G[u].size(); i++){
        int v=G[u][i];
        if(v==pu) continue;
        int tmp=max(max((i!=0? pMax[i-1]:0), sMax[i+1])+1, pre);
        Max[v]=max(Max[v], tmp+1);
        htphong(v, u, tmp+1);
    }
}

void sovle(){
    dfs();
    htphong();
    for(int i=1; i<=n; i++) cout << Max[i]-1 << " ";
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    sovle();

    return 0;
}
