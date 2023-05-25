#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x; cin >> n >> x;
    if(n<4) cout << "IMPOSSIBLE", exit(0);
    vector<int> a(n+1, 0);
    for(int i=1; i<=n; i++) cin >> a[i];

    unordered_map<int, pair<int, int>> mp;
    for(int i=3; i<=n; i++)
        for(int j=i+1; j<=n; j++) mp[a[i]+a[j]]={i, j};
    if(mp[x-a[1]-a[2]].fi!=0) cout << 1 << " " << 2 << " " << mp[x-a[1]-a[2]].fi << " " << mp[x-a[1]-a[2]].se, exit(0);
    for(int i=3; i<=n-2; i++){
        for(int j=i+1; j<=n; j++)
            if(mp[a[i]+a[j]]==make_pair(i, j)) mp.erase(a[i]+a[j]);
        for(int j=1; j<i; j++){
            if(mp[x-a[i]-a[j]].fi!=0){
                cout << i << " " << j << " " << mp[x-a[i]-a[j]].fi << " " << mp[x-a[i]-a[j]].se;
                return 0;
            }
        }
    }
    cout <<"IMPOSSIBLE";

    return ~(-1);
}
