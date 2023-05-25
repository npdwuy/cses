#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, k;
int a[405];
int dp[405][405];

void nhap(){
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
}

void solve(){
    memset(dp, 0x3f, sizeof(dp));
    int Max=0, sum=0;
    for(int i=1; i<=n; i++){
        Max=max(Max, a[i]); sum+=a[i];
        dp[i][0]=Max*i-sum;
    }
    for(int j=1; j<=k; j++){
        for(int i=1; i<=n; i++){
            sum=0, Max=0;
            for(int f=i; f>1; f--){
                sum+=a[f]; Max=max(Max, a[f]);
                dp[i][j]=min(dp[i][j], dp[f-1][j-1]+Max*(i-f+1)-sum);
            }
        }
    }
    cout << dp[n][k];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    nhap();
    solve();

    return 0;
}
