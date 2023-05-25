#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<int> a(n+1, 0);
    for(int i=1; i<=n; i++) cin >> a[i];
    sort(a.begin()+1, a.end());
    int sum=0;
    for(int i=1; i<=n; i++) if(a[i]>sum+1) cout << sum+1, exit(0); else sum+=a[i];
    cout << sum+1;

    return 0;
}
