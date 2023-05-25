#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    map<int, int> mp;
    int n, x, ans=0, sum=0;
    cin >> n; x=n;
    mp[0]=1;
    while(n--){
        int tmp; cin >> tmp;
        sum=sum+tmp;
        ans+=mp[sum%x];
        if((sum%x-x)%x!=sum%x) ans+=mp[(sum%x-x)%x];
        if((sum%x+x)%x!=sum%x && (sum%x+x)%x!=(sum%x-x)%x) ans+=mp[(sum%x+x)%x];
        mp[sum%x]++;
    }
    cout << ans;

    return 0;
}

