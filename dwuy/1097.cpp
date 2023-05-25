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

int n;
int a[5005];
int dp[5005][5005][3];

void nhap(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
}

void solve(){
    for(int j=1; j<=n; j++){
        for(int i=1; i<=n-j+1; i++){
            if (j%2){
                if (dp[i][j-1][1]+a[i+j-1] > dp[i+1][j-1][1]+a[i]){
                    dp[i][j][1]=dp[i][j-1][1]+a[i+j-1];
                    dp[i][j][2]=dp[i][j-1][2];
                }
                else{
                    dp[i][j][1]=dp[i+1][j-1][1]+a[i];
                    dp[i][j][2]=dp[i+1][j-1][2];
                }
            }
            else{
                if (dp[i][j-1][2]+a[i+j-1] > dp[i+1][j-1][2]+a[i]){
                    dp[i][j][2]=dp[i][j-1][2]+a[i+j-1];
                    dp[i][j][1]=dp[i][j-1][1];
                }
                else{
                    dp[i][j][2]=dp[i+1][j-1][2]+a[i];
                    dp[i][j][1]=dp[i+1][j-1][1];
                }
            }
//            cout << dp[i][j][1] << " " << dp[i][j][2] << " " << i << " " << j << endl;
        }
    }
    if (n%2) cout << dp[1][n][1];
    else cout << dp[1][n][2];
}

int32_t main(){
    fastIO;
    //file(TASK);
    nhap();
    solve();
    return 0;
}





