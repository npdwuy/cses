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
#define int long long

using namespace std;

typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef long long ll;

const long long OO=1e18;
const int INF=1e9;
const int MOD=INF+7;

int n, q;
ll a[200005];

void nhap(){
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> a[i];
}

struct SMT{
    int n;
    vector<ll> tree;

    SMT(int _n=0){
        n=_n;
        tree.assign(n*4+1, 0);
    }

    ll query(int idx){
        int l=1; int r=n;
        int id=1; ll sum=0;
        while (true){
            sum+=tree[id];
            if (l==r) break;
            int mid=(l+r)>>1;
            id<<=1;
            if (mid<idx) l=mid+1, id++;
            else r=mid;

        }
        return a[idx]+sum;
    }

    void update(int id, int l, int r, int u, int v, ll val){
        if (l>v || r<u) return;
        if (l>=u && r<=v){
            tree[id]+=val;
            return;
        }
        int mid=(l+r)>>1;
        update(id<<1, l, mid, u, v, val);
        update((id<<1)+1, mid+1, r, u, v, val);
    }
    void update(int u, int v, ll val){
        update(1, 1, n, u, v, val);
    }
} smt(200005);

int32_t main(){
    fastIO;
    //file("");
    nhap();
    int type, l, r, val, k;
    while (q--){
        cin >> type;
        if (type&2){
            cin >> k;
            cout << smt.query(k) << endl;
        }
        else{
            cin >> l >> r >> val;
            smt.update(l, r, val);
        }
    }
    return 0;
}





