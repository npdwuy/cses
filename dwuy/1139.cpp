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

int n, cnt;
vector<int> a(200005);
int st[200005];
int en[200005];
int ans[200005];
int mark[500005];
int color[500005];
vector<int> G[200005];

struct BIT{
    int n;
    vector<int> tree;

    BIT(int _n=0){
        n=_n;
        tree.assign(n+5, 0);
    }

    void update(int idx, int val){
        while (idx<=n){
            tree[idx]+=val;
            idx+=-idx&idx;
        }
    }

    int get(int idx){
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

void nhap(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    vector<int> v=a;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i=1; i<=n; i++) a[i]=lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    for(int i=1; i<n; i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void dfs(int u, int p){
    st[u]=++cnt;
    mark[cnt]=u;
    for(int v: G[u])
        if (v!=p) dfs(v, u);
    en[u]=++cnt;
    mark[cnt]=-u;
}

void solve(){
    dfs(1, 0);
    BIT bit(cnt);
    for(int i=1; i<=cnt; i++){
        if (mark[i]>0){
            int u=mark[i];
            if (color[a[u]]!=0) bit.update(color[a[u]], -1);
            color[a[u]]=i;
            bit.update(i, 1);
        }
        else{
            int u=-mark[i];
            ans[u]=bit.get(st[u], en[u]);
        }
    }
    for(int i=1; i<=n; i++) cout << ans[i] << " ";
}

int32_t main(){
    fastIO;
    //file(TASK);
    nhap();
    solve();
    return 0;
}





