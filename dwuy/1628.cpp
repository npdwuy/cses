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

int n, x;
int a[100];
int sum1[MASK(20)+5];
int sum2[MASK(20)+5];
unordered_map<int, int> mp, mp3;

void nhap(){
    cin >> n >> x;
    for(int i=0; i<n; i++) cin >> a[i];
}

void solve(){
    int ans=0;
    int middle=n/2;
    for(int mask=1; mask<MASK(middle); mask++){
        int lg=__lg(mask);
        int _mask=mask^MASK(lg);
        sum1[mask]=sum1[_mask]+a[lg];
        if (sum1[_mask]>=x) continue;
        mp[sum1[mask]]++;
//        cout << sum1[mask] << " " << lg << " " << bitset<10>(mask) << " " << bitset<10>(_mask) << " [] " <<endl;
    }
    int tam=middle;
    middle=n-middle;
    for(int mask=1; mask<MASK(middle); mask++){
        int lg=__lg(mask);
        int _mask=mask^MASK(lg);
        sum2[mask]=sum2[_mask]+a[lg+tam];
        if (sum2[mask]==x) ans++;
        if (sum2[mask]>=x) continue;
        ans+=mp[x-sum2[mask]];
    }

    cout << ans+mp[x] << endl;
}

int32_t main(){
    fastIO;
    //file(TASK);
    nhap();
    solve();
    return 0;
}





