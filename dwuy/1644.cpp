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

int n, lo, hi;
int a[200005];

void nhap(){
    cin >> n >> lo >> hi;
    for(int i=1; i<=n; i++) cin >> a[i];
}

void solve(){
    int ans, sumr=0, suml=0;
    deque<ii> sum; sum.push_back({0, 0});
    for(int i=1; i<=lo; i++) sumr+=a[i]; ans=sumr;
    for(int i=lo+1; i<=n; i++){
        sumr+=a[i];
        if (sum.size() && sum.front().fi < i-hi) sum.pop_front();
        suml+=a[i-lo];
        while (sum.size() && sum.back().se>=suml) sum.pop_back();
        sum.push_back({i-lo, suml});
        ans=max(ans, sumr-sum.front().se);
    }
    cout << ans << endl;
}

int32_t main(){
    fastIO;
    //file(TASK);
    nhap();
    solve();
    return 0;
}




