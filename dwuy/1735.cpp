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
    int val;
    int lazy;

    Node(int _val=0, int _lazy=0){
        val=_val;
        lazy=_lazy;
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
            tree[id].val=a[l];
            return;
        }
        int mid=(l+r)>>1;
        build(l, mid, id<<1);
        build(mid+1, r, (id<<1)|1);
        tree[id].val=tree[id<<1].val+tree[(id<<1)|1].val;
    }

    void build(){
        build(1, n, 1);
    }

    void down(int l, int r, int id){
        int mid=(l+r)>>1;
        int _id=id<<1;
        if (tree[id].lazy>0){
            tree[_id].lazy+=(tree[_id].lazy<0)? -tree[id].lazy:tree[id].lazy;
            tree[_id|1].lazy+=(tree[_id|1].lazy<0)? -tree[id].lazy:tree[id].lazy;
            tree[_id].val+=tree[id].lazy*(mid-l+1);
            tree[_id|1].val+=tree[id].lazy*(r-mid);
        }
        else if(tree[id].lazy<0){
            tree[_id].lazy=tree[_id|1].lazy=tree[id].lazy;
            tree[_id].val=-tree[id].lazy*(mid-l+1);
            tree[_id|1].val=-tree[id].lazy*(r-mid);
        }
        tree[id].lazy=0;
    }

    void upd1(int l, int r, int id, const int &u, const int &v, const int &val){
        if (l!=r) down(l, r, id);
        if (l>=u && r<=v){
            tree[id].lazy+=val;
            tree[id].val+=val*(r-l+1);
            return;
        }
        if (r<u || l>v) return;
        int mid=(l+r)>>1;
        upd1(l, mid, id<<1, u, v, val);
        upd1(mid+1, r, (id<<1)|1, u, v, val);
        tree[id].val=tree[id<<1].val+tree[(id<<1)|1].val;
    }

    void upd1(int u, int v, int val){
        upd1(1, n, 1, u, v, val);
    }

    void upd2(int l, int r, int id, const int &u, const int &v, const int &val){
//        cout << l << " " << r << " " << tree[id].val << endl;
        if (l!=r) down(l, r, id);
        if (l>=u && r<=v){
            tree[id].lazy=-val;
            tree[id].val=val*(r-l+1);
            return;
        }
        if (r<u || l>v) return;
        int mid=(l+r)>>1;
        upd2(l, mid, id<<1, u, v, val);
        upd2(mid+1, r, (id<<1)|1, u, v, val);
        tree[id].val=tree[id<<1].val+tree[(id<<1)|1].val;
    }

    void upd2(int u, int v, int val){
        upd2(1, n, 1, u, v, val);
    }

    int get(int l, int r, int id, const int &u, const int &v){
//        cout << l << " " << r << " " << tree[id].val << endl;
        if (l>=u && r<=v) return tree[id].val;
        if (r<u || l>v) return 0;
        down(l, r, id);
        int mid=(l+r)>>1;
        return get(l, mid, id<<1, u, v) + get(mid+1, r, (id<<1)|1, u, v);
    }

    int get(int u, int v){
        return get(1, n, 1, u, v);
    }
};

void nhap(){
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
}

void solve(){
    SMT smt(n);
    smt.build();
    while(q--){
        int type, u, v, x;
        cin >> type >> u >> v;
        if (type==1){
            cin >> x;
            smt.upd1(u, v, x);
        }
        else if (type==2){
            cin >> x;
            smt.upd2(u, v, x);
        }
        else cout << smt.get(u, v) << endl;
    }
}

int32_t main(){
    fastIO;
    //file(TASK);
    nhap();
    solve();
    return 0;
}




