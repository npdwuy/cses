/// (⌐■_■): "have you define int long long, dwuy?"
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
#define double long double

using namespace std;

typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef long long ll;

const long long OO=1e18;
const int INF=1e9;
const int MOD=INF+7;
const double EPS = 1e-10;

istream & operator >> (istream &is, ii &x){
    is >> x.fi >> x.se;
    return is;
}

int ori(ii a, ii b, ii c){
    int val=(b.se-a.se)*(c.fi-b.fi)-(b.fi-a.fi)*(c.se-b.se);
    if(val==0) return 0;
    return val>0? 1:2;
}


template<class T> T sqr(T x){return x*x;}

double euler(dd a, dd b){
    return sqrt(sqr(a.fi-b.fi)+sqr(a.se-b.se));
}

bool colline(dd a, dd b, dd mid){
    return abs(euler(mid, a)+euler(mid, b)-euler(a, b))<=EPS;
}

bool intersect(ii a, ii b, ii c, ii d){
    if(colline(a, b, c) || colline(a, b, d) || colline(c, d, a) || colline(c, d, b)) return 1;
    int o1=ori(a, b, c);
    int o2=ori(a, b, d);
    int o3=ori(c, d, a);
    int o4=ori(c, d, b);
    if(o1!=o2 && o3!=o4) return 1;
    return 0;
}

void solve(){
    int q; cin >> q;
    while (q--){
        ii a, b, c, d;
        cin >> a >> b >> c >> d;
        if(intersect(a, b, c, d)) cout <<"YES" << endl;
        else cout <<"NO" << endl;
    }
}

int32_t main(){
    fastIO;
    //file(TASK);

    solve();

    return 0;
}
