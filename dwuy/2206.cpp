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

struct Node{
    int val, pos;

    Node(int _val=0,  int _pos=0){
        val=_val;
        pos=_pos;
    }
};

int n, q;
int a[200005];

struct SMTL{ /// just a SegMent Tree
    int n;
    vector<Node> tree;

    SMTL(int _n=0){
        n=_n;
        tree.assign(n*4+5, Node());
    }

    void build(int l, int r, int id){
        if (l==r){
            tree[id]=Node(a[l], l);
            return;
        }
        int mid=(l+r)>>1;
        int _id=id<<1;
        build(l, mid, _id);
        build(mid+1, r, _id|1);
        if (tree[_id].val+abs(tree[_id].pos-tree[_id|1].pos) < tree[_id|1].val) tree[id]=tree[_id];
        else tree[id]=tree[_id|1];
    }

    void build(){
        build(1, n, 1);
    }

    void update(int l, int r, int id, int idx, int val){
        if (l==r){
            tree[id]=Node(val, idx);
            return;
        }
        int mid=(l+r)>>1;
        int _id=id<<1;
        if (idx<=mid) update(l, mid, _id, idx, val);
        else update(mid+1, r, _id|1, idx, val);

        if (tree[_id].val+abs(tree[_id].pos-tree[_id|1].pos) < tree[_id|1].val) tree[id]=tree[_id];
        else tree[id]=tree[_id|1];
    }

    void update(int idx, int val){
        update(1, n, 1, idx, val);
    }

    Node get(int l, int r, int id, int idx){
//        cerr  << l << " " << r << endl;
        if (r<=idx) return tree[id];
        int mid=(l+r)>>1;
        Node A = get(l, mid, id<<1, idx);
        Node B = (mid<idx)? get(mid+1, r, (id<<1)|1, idx):Node(INF, 0);
        if (A.val+abs(A.pos-B.pos)<B.val) return A;
        else return B;
    }

    Node get(int idx){
        return get(1, n, 1, idx);
    }
};


struct SMTR{ /// just a SegMent Tree
    int n;
    vector<Node> tree;

    SMTR(int _n=0){
        n=_n;
        tree.assign(n*4+5, Node());
    }

    void build(int l, int r, int id){
        if (l==r){
            tree[id]=Node(a[l], l);
            return;
        }
        int mid=(l+r)>>1;
        int _id=id<<1;
        build(l, mid, _id);
        build(mid+1, r, _id|1);
        if (tree[_id|1].val+abs(tree[_id].pos-tree[_id|1].pos) < tree[_id].val) tree[id]=tree[_id|1];
        else tree[id]=tree[_id];
    }

    void build(){
        build(1, n, 1);
    }

    void update(int l, int r, int id, int idx, int val){
        if (l==r){
            tree[id]=Node(val, idx);
            return;
        }
        int mid=(l+r)>>1;
        int _id=id<<1;
        if (idx<=mid) update(l, mid, _id, idx, val);
        else update(mid+1, r, _id|1, idx, val);
        if (tree[_id|1].val+abs(tree[_id].pos-tree[_id|1].pos) < tree[_id].val) tree[id]=tree[_id|1];
        else tree[id]=tree[_id];
    }

    void update(int idx, int val){
        update(1, n, 1, idx, val);
    }

    Node get(int l, int r, int id, int idx){
        if (l>=idx) return tree[id];
        int mid=(l+r)>>1;
        Node A = (mid>=idx)? get(l, mid, id<<1, idx):Node(INF, 0);
        Node B = get(mid+1, r, (id<<1)|1, idx);
        if (B.val+abs(A.pos-B.pos)<A.val) return B;
        else return A;
    }

    Node get(int idx){
        return get(1, n, 1, idx);
    }
};

void nhap(){
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> a[i];
}

void solve(){
    SMTL smtl(n);
    SMTR smtr(n);
    smtl.build();
    smtr.build();
    while (q--){
        int type, u, v;
        cin >> type;
        if (type==1){
            cin >> u >> v;
            smtl.update(u, v);
            smtr.update(u, v);
        }
        else{
            cin >> u;
            Node tmp1 = smtl.get(u);
            Node tmp2 = smtr.get(u);
            cout << min(abs(tmp1.pos-u)+tmp1.val, abs(tmp2.pos-u)+tmp2.val) << endl;
        }

    }
}

int32_t main(){
    fastIO;
    //file(TASK);
    nhap();
    solve();
    return 0;
}




