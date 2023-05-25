#include <bits/stdc++.h>

using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, x;
    multiset<int> Set;

    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> x, Set.insert(x);
    for(int i=1; i<=m; i++){
        cin >> x;
        if(Set.size()==0) {cout << -1 << endl; continue;}
        auto ptr=Set.upper_bound(x);
        if(ptr==Set.begin()) cout << -1 << endl;
        else ptr--, cout << *ptr << endl, Set.erase(ptr);
    }
    return 0;
}
