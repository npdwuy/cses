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

int n, m, q;
int a[200005];

struct Node{
    int lo, hi;
    int sum;

    Node(int _lo=0, int _hi=0, int _sum=0){
        lo=_lo;
        hi=_hi;
        sum=_sum;
    }
};

struct SMT{
    int n;
    vector<Node> tree;

    SMT(int _n=0){
        n=_n;
        tree.assign(n*4+5, Node());
    }

    void build(int l, int r, int id){
        if (l==r){
            tree[id].sum=a[l];
            return;
        }
        int mid=(l+r)>>1;
        int _id=id<<1;
        build(l, mid, _id);
        build(mid+1, r, _id|1);
        tree[id].sum=tree[_id].sum+tree[_id|1].sum;
    }

    void build(){
        build(1, n, 1);
    }

    void down(int l, int r, int id){
         cout << "                       " << l << " <-> " << r << " " << tree[id].lo << " " << tree[id].hi << endl;
        if (l==r) tree[id].lo=tree[id].hi=0;
        if (tree[id].hi==0) return;
        int m=(r-l)>>1;
        int mid=(tree[id].hi-tree[id].lo)/(r-l);
        int _mid=(l+r)>>1;
        int _id=id<<1;
        tree[_id].lo+=tree[id].lo;
        tree[_id].hi+=mid;
        tree[_id].sum+=(tree[id].lo+mid)*(_mid-l+1)>>1;
        mid++;
        tree[_id|1].lo+=mid;
        tree[_id|1].hi+=tree[id].hi;
        tree[_id|1].sum+=(tree[id].hi+mid)*(r-_mid)>>1;

        cout << "                       " << (l+r)/2+1 << " " << r << " " << tree[_id|1].sum << " " << tree[_id|1].lo << " " << tree[_id|1].hi << endl;
        tree[id].lo=tree[id].hi=0;
    }

    void update(int l, int r, int id, int u, int v){
        if(l>=u && r<=v){
            int L=l-u+1;
            int R=r-u+1;
            tree[id].lo+=L;
            tree[id].hi+=L;
            tree[id].sum+=(R+L)*(r-l+1)/2;
            cerr << l << " - " << r << " " << tree[id].sum << " " << tree[id].lo << " " << tree[id].hi << endl;
            return;
        }
        if(l>v || r<u) return;
        down(l, r, id);
        int mid=(l+r)>>1;
        int _id=id<<1;
        update(l, mid, _id, u, v);
        update(mid+1, r, _id|1, u, v);
        tree[id].sum=tree[_id].sum+tree[_id|1].sum;
            cerr << l << " - " << r << " " << tree[id].sum << " " << tree[id].lo << " " << tree[id].hi << endl;
    }

    void update(int l, int r){
//        cout <<" --" << endl;
        update(1, n, 1, l, r);
    }

    int get(int l, int r, int id, int u, int v){
//        cout << l << " " << r << " " << tree[id].val << " " << tree[id].sum << endl;
        if (l>=u && r<=v) return tree[id].sum ;
        if (l>v || r<u) return 0;
        down(l, r, id);
        int mid=(l+r)>>1;
        return get(l, mid, id<<1, u, v) + get(mid+1, r, (id<<1)|1, u, v);
    }

    int get(int l, int r){
//         cout << endl;
        return get(1, n, 1, l, r);
    }
};

void nhap(){
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> a[i];
}

void solve(){
    SMT smt(n);
    smt.build();
    while(q--){
        int type, u, v;
        cin >> type >> u >> v;
        cout << "\n-----------------------------------------\n";
        if (type==1) smt.update(u, v);
        else cout << smt.get(u, v) << endl;
//        cout << "''''" << smt.get(5, 5) << endl;

    }
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();


    return 0;
}

/**
10 9
0 0 0 0 0 0 0 0 0 0
1 1 5
1 4 7
1 2 8
1 2 5
1 5 5
1 1 9
1 6 10
1 2 9
2 1 10



0 0 0 0 0 0 0 0 0 0
1 2 3 4 5 0 0 0 0 0
0 0 0 1 2 3 4 0 0 0
0 1 2 3 4 5 6 7 0 0
0 1 2 3 4 0 0 0 0 0
**/
