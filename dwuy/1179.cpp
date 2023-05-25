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
    int u, v, c;
    Edge(int _u=0, int _v=0, int _c=0){
        u=_u; v=_v;
        c=_c;
    }

    int other(int x){
        return u^v^x;
    }
};

int n, m;
int d[2505], rd[2505];
int p[2505], rp[2505];
Edge edges[5005];
Edge redges[5005];

void nhap(){
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u, v, c; cin >> u >> v >> c;
        edges[i]=Edge(u, v, c);
        redges[i]=Edge(v, u, c);
    }
}

void solve(){
    memset(d, 0x3f, sizeof(d));
    memset(rd, 0x3f, sizeof(rd));

    d[1]=rd[1]=0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int u=edges[j].u;
            int v=edges[j].v;
            int c=edges[j].c;
            if(d[v]>d[u]+c) d[v]=d[u]+c, p[v]=u;
        }
    }
    int st=-1;
    for(int i=1; i<=m; i++){
        int u=edges[i].u;
        int v=edges[i].v;
        int c=edges[i].c;
        if(d[v]>d[u]+c){ p[v]=u; st=v; break;}
    }
    if(st!=-1){
        cout <<"YES" << endl;
        for(int i=1; i<=n; i++) st=p[st];
        vector<int> v;
        v.push_back(st); st=p[st];
        while(1){
            v.push_back(st);
            if(st==v[0]) break;
            st=p[st];
        }
        reverse(v.begin(), v.end());
        for(int x: v) cout << x << " ";
        return;
    }
    cout << "NO";
}



int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}
