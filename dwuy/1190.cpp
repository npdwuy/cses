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
#define TASK "test"
#define int long long

using namespace std;

typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef long long ll;

const long long OO=1e18;
const int INF=1e9;
const int MOD=INF+7;

struct Node{
    int sum, psum, ssum, Max;

    Node(int _sum=0, int _psum=0, int _ssum=0, int _Max=0){
        sum=_sum;
        psum=_psum;
        ssum=_ssum;
        Max=_Max;
    }
};

int n, q;
int a[200005];

struct SMT{ /// just a SegMent Tree
    int n;
    vector<Node> tree;

    SMT(int _n=0){
        n=_n;
        tree.assign(n*4+5, Node());
    }

    void build(int l, int r, int id){
        if (l==r){
            tree[id]=Node(a[l], max(a[l], 0LL), max(a[l], 0LL), max(a[l], 0LL));
            return;
        }
        int mid=(l+r)>>1;
        int _id=id<<1;
        build(l, mid, _id);
        build(mid+1, r, _id|1);
        tree[id].sum=tree[_id].sum+tree[_id|1].sum;
        tree[id].psum=max(0LL, max(tree[_id].psum, tree[_id].sum+tree[_id|1].psum));
        tree[id].ssum=max(0LL, max(tree[_id|1].ssum, tree[_id].ssum+tree[_id|1].sum));
        tree[id].Max=max(max(tree[_id].Max, tree[_id|1].Max), max(max(tree[id].sum, tree[id].ssum), max(tree[id].psum, tree[_id].ssum+tree[_id|1].psum)));
    }

    void build(){
        build(1, n, 1);
    }

    void update(int l, int r, int id, const int &idx, const int &val){
        if (l==r){
            tree[id]=Node(val, max(val, 0LL), max(val, 0LL), max(val, 0LL));
            return;
        }
        int mid=(l+r)>>1;
        int _id=id<<1;
        if (idx<=mid) update(l, mid, _id, idx, val);
        else update(mid+1, r, _id|1, idx, val);
        tree[id].sum=tree[_id].sum+tree[_id|1].sum;
        tree[id].psum=max(0LL, max(tree[_id].psum, tree[_id].sum+tree[_id|1].psum));
        tree[id].ssum=max(0LL, max(tree[_id|1].ssum, tree[_id].ssum+tree[_id|1].sum));
        tree[id].Max=max(max(tree[_id].Max, tree[_id|1].Max), max(max(tree[id].sum, tree[id].ssum), max(tree[id].psum, tree[_id].ssum+tree[_id|1].psum)));
    }

    void update(int idx, int val){
        update(1, n, 1, idx, val);
    }
};

void nhap(){
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> a[i];
}

void solve(){
    SMT smt(n);
    smt.build();
    while (q--){
        int u, v;
        cin >> u >> v;
        smt.update(u,v);
        cout << smt.tree[1].Max << endl;
    }
}

int32_t main(){
    fastIO;
//    file(TASK);
    nhap();
    solve();
    return 0;
}






