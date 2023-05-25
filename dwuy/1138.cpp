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

    void down(int id){
        tree[id*2]+=tree[id];
        tree[id*2+1]+=tree[id];
        tree[id]=0;
    }

    void update(int l, int r, int id, int u, int v, int val){
        if (l>=u && r<=v){
            tree[id]+=val;
//        cout << l << " " << r << " " << tree[id] << " " << u << " " << v << endl;
            return;
        }
        if (l>v || r<u) return;
        down(id);
        int mid=(l+r)>>1;
        update(l, mid, id<<1, u, v, val);
        update(mid+1, r, (id<<1)+1, u, v, val);
//        cout << l << " " << r << " " << tree[id] << " " << u << " " << v << endl;    }

    void update(int u, int v, int val){
         update(1, n, 1, u, v, val);
    }

    int get(int pos){
        int l=1, r=n, id=1;
        while (true){
            if (l==r) return tree[id];
            down(id);
            int mid=(l+r)>>1;
            id<<=1;
            if (pos>mid) l=mid+1, id++;
            else r=mid;
        }
        return -1;
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
    for(int v: G[u])
        if (v!=p) dfs(v, u);
    en[u]=cnt;
}

int32_t main(){
    fastIO;
    //file(TASK);
    nhap();
    dfs(1, 0);
    SMT smt(cnt+1);
//    for(int i=1; i<=n; i++) cout << st[i] << " " << en[i] << " "<< i << " " << a[i] << endl;
    for(int i=1; i<=n; i++) smt.update(st[i], en[i], a[i]);
//    for(int i=1; i<=cnt; i++) cout << bit.tree[i] << " "; cout << endl;
    while (q--){
        int type, u, v;
        cin >> type;
        if (type==1){
            cin >> u >> v;
            smt.update(st[u], en[u], v-a[u]);
            a[u]=v;
        }
        else{
            cin >> u;
//            cout << st[u] << " " << en[u] << endl;
            cout << smt.get(st[u]) << endl;
        }
    }
    return 0;
}




