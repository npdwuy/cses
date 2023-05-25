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

struct BIT{ /// just a blue fenwick tree
    int n;
    vector<int> tree;

    BIT(int _n = 0){
        n=_n;
        tree.assign(n+5, 0);
    }

    void update(int idx, int val){
        if (idx==0) return;
        while (idx<=n){
            tree[idx]^=val;
            idx+=-idx&idx;
        }
    }

    int get(int idx){
        int res=0;
        while (idx){
            res^=tree[idx];
            idx-=-idx&idx;
        }
        return res;
    }

    int get(int l, int r){
        return get(r)^get(l-1);
    }
};

int n, q;
BIT bit(200005);

void nhap(){
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        int x; cin >> x;
        bit.update(i, x);
    }
}

void solve(){
    while (q--){
        int u, v; cin >> u >> v;
        cout << bit.get(u, v) << endl;
    }
}

int32_t main(){
    fastIO;
    //file(TASK);
    nhap();
    solve();
    return 0;
}





