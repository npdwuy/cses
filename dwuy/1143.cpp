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

using namespace std;

typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef long long ll;

const long long OO=1e18;
const int INF=1e9;
const int MOD=INF+7;

int n, m;
int a[200005];
int b[200005];

struct SMT{ /// just a SegMent Tree
    int n;
    vector<int> tree;

    SMT(int _n=0){
        n=_n;
        tree.assign(n*4+5, 0);
    }

    void build(int l, int r, int id){
        if (l==r){
            tree[id]=a[l];
            return ;
        }
        int mid=(l+r)>>1;
        build(l, mid, id<<1);
        build(mid+1, r, (id<<1)+1);
        tree[id] = max(tree[id<<1], tree[(id<<1)+1]);
    }

    void build(){
        build(1, n, 1);
    }

    void update(int l, int r, int id, int idx, int val){
        if (l==r){
            tree[id] -= val;
            return;
        }
        int mid=(l+r)>>1;
        if (idx<=mid) update(l, mid, id<<1, idx, val);
        else update(mid+1, r, (id<<1)+1, idx, val);
        tree[id] = max(tree[id<<1], tree[(id<<1)+1]);
    }

    void update(int idx, int val){
        update(1, n, 1, idx, val);
    }

    int get(int l, int r, int id, int val){
        if (l==r) return l;
        int mid=(l+r)>>1;
        if (tree[id<<1] >= val) return get(l, mid, id<<1, val);
        else return get(mid+1, r, (id<<1)+1, val);
    }

    int get(int val){
        return get(1, n, 1, val);
    }
};

void nhap(){
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=m; i++) cin >> b[i];
}

void solve(){
    SMT smt(n);
    smt.build();
    for(int i=1; i<=m; i++){
        if (b[i]>smt.tree[1]){
            cout << 0 << " ";
            continue;
        }
        int idx = smt.get(b[i]);
        cout << idx << " ";
        smt.update(idx, b[i]);
    }

}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}





