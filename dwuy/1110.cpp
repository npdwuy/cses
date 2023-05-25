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

const long long OO = 1e18;
const int INF = 1e9;
const int MOD = INF+7;
const int base = 307;

string s;
int n;
int pf[2000005];
int bp[2000005];

void nhap(){
    cin >> s;
    n=len(s); s=' '+s+s;
    bp[0]=1;
    for(int i=1; i<=2*n; i++){
        pf[i]=(pf[i-1]*base+s[i])%MOD;
        bp[i]=bp[i-1]*base%MOD;
    }
}

int get(int l, int r){
    return ((pf[r]-pf[l-1]*bp[r-l+1]%MOD)%MOD+MOD)%MOD;
}

bool compare(int i, int j){
    if(s[i]!=s[j]) return s[i]>s[j];
    int res=0;
    for(int lo=0, hi=n-1; lo<=hi;){
        int mid=(lo+hi)>>1;
        if(get(i, i+mid)==get(j, j+mid)) res=mid, lo=mid+1;
        else hi=mid-1;
    }
    if(res==n-1) return 0;
    return s[i+res+1]>s[j+res+1];
}

void solve(){
    int mn=1;
    for(int i=2; i<=n; i++){
        if(compare(mn, i)) mn=i;
    }
    cout << s.substr(mn, n);
}

/// bcbcbcaabbaaaaa
int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();
    return 0;
}
