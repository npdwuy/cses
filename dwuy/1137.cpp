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
#define TASK ""
#define int long long

using namespace std;

typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef long long ll;

const long long OO=1e18;
const int INF=1e9;
const int MOD=INF+7;

int n, q, cnt;
int a[200005];
int st[200005];
int en[200005];
vector<int> G[200005];

struct SMT{ /// just a SegMent Tree
    int n;
    vector<int> tree;

    SMT(int _n=0){
        n=_n;
        tree.assign(n*4+5, 0);
    }

    void update(int pos, int v, int t){
        int l=1, r=n, id=1;
        while (true){
            tree[id]+=v-t;
            if (l==r) break;
            id<<=1;
            int mid=(l+r)>>1;
            if (pos>mid) l=mid+1, id++;
            else r=mid;
        }
    }

    int get(int l, int r, int id, const int &u, const int &v){
        if (l>v || r<u) return 0;
        if (l>=u && r<=v) return tree[id];
        int mid=(l+r)>>1;
        id<<=1;
        return get(l, mid, id, u, v)+get(mid+1, r, id+1, u, v);
    }
    int get(int u, int v){
        return get(1, n, 1, u, v);
    }
};

void nhap(){
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<n; i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void dfs(int u, int p){
    st[u]=++cnt;
    for(int v: G[u]){
        if (v!=p) dfs(v, u);
    }
    en[u]=cnt;
}

int32_t main(){
    fastIO;
    //file(TASK);
    nhap();
    dfs(1, 0);
    SMT smt(cnt+5);

    for(int i=1; i<=n; i++)smt.update(st[i], a[i], 0);
    while (q--){
        int type, u, v;
        cin >> type;
        if(type==2) cin >> u, cout << smt.get(st[u], en[u]) << endl;
        else cin >> u >> v, smt.update(st[u], v, a[u]), a[u]=v;
    }
    return 0;
}





