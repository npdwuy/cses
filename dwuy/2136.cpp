#include <bits/stdc++.h>
#define MASK(x) (1LL<<(x))
#pragma GCC target("popcnt")

using namespace std;

int a[100005];

void solve(){
    int n, k;
    cin >> n >> k;
    string s; cin >> s; reverse(s.begin(), s.end());
    for(int i=0; i<k; i++) a[1] |= s[i]=='1'? MASK(i):0;
    int ans=31;
    for(int i=2; i<=n; i++){
        string s; cin >> s; reverse(s.begin(), s.end());
        for(int j=0; j<k; j++) a[i] |= s[j]=='1'? MASK(j):0;
        for(int j=1; j<i; j++){
            ans = min(ans, __builtin_popcount(a[i]^a[j]));
        }
    }
    cout << ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}

