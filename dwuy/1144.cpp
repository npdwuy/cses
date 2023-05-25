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

using namespace std;

typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef long long ll;

const long long OO=1e18;
const int INF=1e9;
const int MOD=INF+7;
const int MAX=6e5+5;

int n, q;
int a[200005];
int nv[200005];
int pu[200005];
int bit[MAX];
char type[200005];
vector<int> V;

void nhap(){
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> a[i], V.push_back(a[i]);
    for(int i=1; i<=q; i++){
        cin >> type[i] >> nv[i] >> pu[i];
        if (type[i]=='?') V.push_back(nv[i]);
        V.push_back(pu[i]);
    }
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    for(int i=1; i<=n; i++) a[i]=lower_bound(V.begin(), V.end(), a[i])-V.begin()+1;
    for(int i=1; i<=q; i++){
        if (type[i]=='?') nv[i]=lower_bound(V.begin(), V.end(), nv[i])-V.begin()+1;
        pu[i]=lower_bound(V.begin(), V.end(), pu[i])-V.begin()+1;
    }
}

void update(int idx, int val){
    while (idx<MAX) {
        bit[idx]+=val;
        idx+=-idx&idx;
    }
}

int get(int idx){
    int res=0;
    while (idx) res+=bit[idx], idx-=-idx&idx;
    return res;
}

int get(int l, int r){ return get(r)-get(l-1);}

void solve(){
    for(int i=1; i<=n; i++) update(a[i], 1);
    for(int i=1; i<=q; i++){
        if (type[i]=='?') cout << get(nv[i], pu[i]) << endl;
        else{
            update(a[nv[i]], -1);
            a[nv[i]]=pu[i];
            update(pu[i], 1);
        }
    }
}

int32_t main(){
    fastIO;
    //file("");
    nhap();
    solve();
    return 0;
}

