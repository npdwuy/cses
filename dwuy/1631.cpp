#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    int Max=0, sum=0;
    while(cin >> n) sum+=n, Max=max(Max, n);
    cout << (Max*2>sum? Max*2: sum);

    return 0;
}
