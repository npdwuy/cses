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

void nhap(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
}

void build(){
    lg=__lg(n);
    for(int i=1; i<=n; i++){
        sum[i]=sum[i-1]+a[i];
        Max[i][0]=a[i];
    }
    for(int j=1; j<=lg; j++)
        for(int i=1; i<=n; i++)
            Max[i][j]=max(Max[i][j-1], Max[i+mask(j-1)][j-1]);
    for(int j=1; j<=lg; j++){
        for(int i=1; i<=n; i++){
            calc[i][j]=calc[i][j-1], Max[i+mask(j-1)][j-1]);
        }
    }
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}





