#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.out","w",stdout);
    cout << "#include <bits/stdc++.h>\nusing namespace std;\nint32_t main(){\n";
    for(int n=1; n<=20; n++){
        cout << "    ans["<<n<<"]=\"";
        for(int mask=0; mask<(1<<n); mask++){
            int tmp=mask; string ans="";
            while(tmp) ans+=char((tmp&1)+'0'), tmp>>=1;
            while(ans.length()<n) ans+='0';
            reverse(ans.begin(), ans.end());
            cout << ans << "\\n";
        }
        cout << "\";\n";
    }
    cout << "    int n; cin >> n; cout << ans[n];\n    return 0;\n}";
    return 0;
}

