#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    map<int, int> mp;
    int n, x, ans=0, sum=0;
    cin >> n >> x;
    mp[0]=1;
    while(n--){
        int tmp; cin >> tmp;
        sum+=tmp;
        ans+=mp[sum-x];
        mp[sum]++;
    }
    cout << ans;

    return 0;
}
