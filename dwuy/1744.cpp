/// (⌐■_■): "have you defined int long long, dwuy?"
///  dwuy : "already"
#include <bits/stdc++.h>

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define file(a) freopen(a".inp","r",stdin); freopen(a".out", "w",stdout)
#define fi first
#define se second
#define endl "\n"
#define len(s) int32_t(s.length())
#define MASK(k)(1LL<<(k))
#define TASK ""
#define int long long

using namespace std;

typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef long long ll;

const long long OO=1e18;
const int INF=1e9;
const int MOD=INF+7;
const int MX = 505;

int n, m;
int dp[MX][MX];

void solve(){
    memset(dp, 0x3f, sizeof(dp));
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==j) { dp[i][j] = 0; continue;}
            for(int k=1; k<i; k++) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
            for(int k=1; k<j; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
        }
    }
    cout << dp[n][m];
}

int32_t main(){
    fastIO;
    //file(TASK);

    solve();

    return 0;
}


