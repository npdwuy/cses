/// (⌐■_■): "have you defined int long long, dwuy?"
///  dwuy : "already"
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

const long long OO = 1e18;
const int INF = 1e9;
const int MOD = INF+7;
const int base = 307;

int n, q;
string s, rs;
int bp[200005];

struct BIT{ /// cũng là BIT nhma bủh bủh lmao lmao
    int n;
    vector<int> tree;

    BIT(int n = 0){
        this->n = n;
        this->tree.assign(n+5, 0);
    }

    void update(int idx, int c, int _c){
        int tmp = idx;
        for(; idx<=n; idx += -idx&idx){
            tree[idx] = tree[idx] - _c*bp[idx - tmp]%MOD + c*bp[idx - tmp]%MOD + MOD;
            while(tree[idx] > MOD) tree[idx] -= MOD;
            if(tree[idx] < 0) tree[idx] += MOD;
        }
    }

    int get(int idx){
        int res = 0;
        int tmp = idx;
        for(; idx; idx -= -idx&idx){
            res = (res + tree[idx] * bp[tmp - idx] % MOD)%MOD;
        }
        return res;
    }

    int get(int l, int r){
        return (get(r) - get(l-1)*bp[r-l+1]%MOD + MOD*MOD)%MOD;
    }
};

void solve(){
    cin >> n >> q;
    cin >> s;
    rs = s; reverse(rs.begin(), rs.end());
    s = ' ' + s;
    rs = ' ' + rs;
    bp[0]=1;
    for(int i = 1; i <= n; i++) bp[i] = bp[i-1] * base % MOD;

    BIT pre(n), suf(n);
    for(int i = 1; i <= n; i++){
        pre.update(i, s[i], 0);
        suf.update(i, rs[i], 0);
    }
    for(int i=1; i<=q; i++){
        int type; cin >> type;
        if(type == 2){
            int l, r; cin >> l >> r;
            cout << (pre.get(l, r) == suf.get(n-r+1, n-l+1)? "YES":"NO") << endl;
        }
        else{
            int u; char x;
            cin >> u >> x;
            pre.update(u, x, s[u]); s[u]=x;
            u=n-u+1;
            suf.update(u, x, rs[u]); rs[u]=x;
        }
    }
}

int32_t main(){
    fastIO;
    //file(TASK);

    solve();

    return 0;
}

/**

7 5
aybabtu
2 3 5
1 3 x
2 3 5
1 5 x
2 3 5

**/


