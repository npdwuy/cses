/// (⌐■_■): "have you defined int long long, dwuy?"
///  dwuy : "already"
#include <bits/stdc++.h>

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define file(a) freopen(a".inp","r",stdin); freopen(a".out", "w",stdout)
#define fi first
#define se second
#define endl "\n"
#define len(s) int32_t(s.length())
#define MASK(k)(1LL<<k)
#define TASK ""
#define int long long

using namespace std;

typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef long long ll;

const long long OO=1e18;
const int INF=1e9;
const int MOD=INF+7;

string s;
string t;
int pf[1000005];
int n, m;

void nhap(){
    cin >> s; n=len(s);
    cin >> t; m=len(t);
    for(int r=1, l=0; r<m; r++){
        while(l && t[r]!=t[l]) l=pf[l-1];
        if (t[l]==t[r]) l++;
        pf[r]=l;
    }
}

void solve(){
    int i=0, j=0;
    int ans = 0;
    while(i<n){
        if(s[i]==t[j]){
            i++, j++;
        }
        else if(j!=0) j=pf[j-1];
        else i++;
        if(j==len(t)) j=pf[j-1], ans++;
    }
    cout << ans;
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}
