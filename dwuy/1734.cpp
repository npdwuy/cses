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

struct Query{
    int l, r;
    int id;

    Query(int _l=0, int _r=0, int _id=0){
        l=_l; r=_r;
        id=_id;
    }

    bool operator < (const Query &other){
        return r<other.r;
    }
};

struct BIT{
    int n;
    vector<int> tree;

    BIT(int _n=0){
        n=_n;
        tree.assign(n+5, 0);
    }

    void update(int idx, int val){
        if (idx==0) return;
        while (idx<=n){
            tree[idx]+=val;
            idx+=-idx&idx;
        }
    }

    int  get(int idx){
        int res=0;
        while (idx){
            res+=tree[idx];
            idx-=-idx&idx;
        }
        return res;
    }

    int get(int l, int r){
        return get(r)-get(l-1);
    }
};

int n, q;
int a[200005];
int ans[200005];
unordered_map<int, int> mp;
vector<Query> queries;

void nhap(){
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=q; i++){
        int l, r; cin >> l >> r;
        queries.push_back(Query(l, r, i));
    }
}

void solve(){
    BIT bit(n);
    sort(queries.begin(), queries.end());
    int idx=1;
    for(int i=0; i<q; i++){
        while (idx<=queries[i].r){
            bit.update(mp[a[idx]], -1);
            bit.update(idx, 1);
            mp[a[idx]]=idx;
            idx++;
        }
        ans[queries[i].id]=bit.get(queries[i].l, queries[i].r);
    }
    for(int i=1; i<=q; i++) cout << ans[i] << "\n";
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}





