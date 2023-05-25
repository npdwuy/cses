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

struct Data{
    int l, r, val;

    Data(int _l=0, int _r=0, int _val=0){
        l=_l;
        r=_r;
        val=_val;
    }

    bool operator < (const Data &other){
        return (r!=other.r)? r<other.r : l<other.l;
    }
};

int n;
Data a[200005];
int dp[200005];

void nhap(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i].l >> a[i].r >> a[i].val;
    }
    sort(a+1, a+1+n);
}

void solve(){
    dp[1]=a[1].val;
    for(int i=2; i<=n; i++){
        int pos=0;
        for(int lo=0, hi=i-1, mid=lo+hi>>1; lo<=hi; mid=lo+hi>>1){
            if (a[mid].r<a[i].l) pos=mid, lo=mid+1;
            else hi=mid-1;
        }
        dp[i]=max(dp[i-1], dp[pos]+a[i].val);
    }
    cout << dp[n] << endl;
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}





