#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    int Min=0, sum=0, ans=-1e18;
    while(cin >> n){
        sum+=n;
        ans=max(ans, sum-Min);
        Min=min(Min, sum);
    }
    cout << ans;

    return 0;
}
