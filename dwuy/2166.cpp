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

struct Node{
    int sum, psum;

    Node(int _sum=0, int _psum=0){
        sum=_sum;
        psum=_psum;
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
            tree[id].sum=a[l];
            tree[id].psum=max(a[l], 0LL);
            return;
        }
        int mid=(l+r)>>1;
        int _id=id<<1;
        build(l, mid, _id);
        build(mid+1, r, _id|1);
        tree[id].sum=tree[_id].sum+tree[_id|1].sum;
        tree[id].psum=max(tree[_id].psum, tree[_id].sum+tree[_id|1].psum);
    }

    void build(){
        build(1, n, 1);
    }

    void update(int l, int r, int id, const int &idx, const int &val){
        if (l==r){
            tree[id]=Node(val, max(val, 0LL));
            return;
        }
        int mid=(l+r)>>1;
        int _id=id<<1;
        if (idx<=mid) update(l, mid, _id, idx, val);
        else update(mid+1, r, _id|1, idx, val);
        tree[id].sum=tree[_id].sum+tree[_id|1].sum;
        tree[id].psum=max(tree[_id].psum, tree[_id].sum+tree[_id|1].psum);
    }

    void update(int idx, int val){
        update(1, n, 1, idx, val);
    }

    Node get(int l, int r, int id, const int &u, const int &v){
        if (l>=u && r<=v){
            return tree[id];
        }
        if (l>v || r<u) return Node();
        int mid=(l+r)>>1;
        int _id=id<<1;
        Node A = get(l, mid, _id, u, v);
        Node B = get(mid+1, r, _id|1, u, v);
        return Node(A.sum+B.sum, max(A.psum, A.sum+B.psum));
    }

    Node get(int u, int v){
        return get(1, n, 1, u, v);
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
        int type, u, v;
        cin >> type >> u >> v;
        if (type==1) smt.update(u,v);
        else cout << smt.get(u, v).psum << endl;
    }
}

int32_t main(){
    fastIO;
    //file(TASK);
    nhap();
    solve();
    return 0;
}





