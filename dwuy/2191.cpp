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

using namespace std;

typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef long long ll;

const long long OO=1e18;
const int INF=1e9;
const int MOD=INF+7;

int n;
ii a[200005];

void nhap(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i].fi >> a[i].se;
}

void solve(){
//    reverse(a+1, a+1+n);
    int tmp1=0, tmp2=0;
    a[n+1]=a[1];
    for(int i=1; i<=n; i++){
        tmp1+=a[i].fi*a[i+1].se;
        tmp2+=a[i].se*a[i+1].fi;
    }
    cout << abs(tmp1-tmp2);
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}
