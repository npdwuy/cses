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

const long long OO=1e18;
const int INF=1e9;
const int MOD=INF+7;

int n, k, Mn=0;
int a[200005];

void nhap(){
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i], Mn=max(Mn, a[i]);
}

void solve(){
    int res=0;
    for(int lo=Mn, hi=1e18; lo<=hi;){
        int mid=(lo+hi)>>1;
        int cnt=1, sum=0;
        for(int i=1; i<=n; i++){
            if(sum+a[i]>mid) sum=a[i], cnt++;
            else sum+=a[i];
        }
        if(cnt<=k) res=mid, hi=mid-1;
        else lo=mid+1;
    }
    cout << res;
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}
