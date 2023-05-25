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
int sf[2000005];
int bp[2000005];

void nhap(){
    cin >> s;
    n=len(s);
    s=' '+s;
    bp[0]=1;
    for(int i=1; i<=n; i++){
        pf[i]=(pf[i-1]*base+s[i])%MOD;
        bp[i]=bp[i-1]*base%MOD;
    }
    for(int i=n; i>0; i--){
        sf[i]=(sf[i+1]*base+s[i])%MOD;
    }
}

int get(int l, int r){
    return ((pf[r]-pf[l-1]*bp[r-l+1]%MOD)%MOD+MOD)%MOD;
}

int get2(int l, int r){
    return ((sf[l]-sf[r+1]*bp[r-l+1]%MOD)%MOD+MOD)%MOD;
}

void solve(){
    pair<int, ii> ans={1, {1, 1}};
    for(int i=1; i<=n; i++){
        int res=1;
        for(int lo=1, hi=min(n-i+1, i); lo<=hi;){
            int mid=(lo+hi)>>1;
            if(get2(i-mid+1, i)==get(i, i+mid-1)) res=mid, lo=mid+1;
            else hi=mid-1;
        }
        ans=max(ans, {res*2-1, {i, res}});
        if(i<n && s[i]==s[i+1]){
            for(int lo=1, hi=min(n-i, i); lo<=hi;){
                int mid=(lo+hi)>>1;
                if(get2(i-mid+1, i)==get(i+1, i+mid)) res=mid, lo=mid+1;
                else hi=mid-1;
            }
            ans=max(ans, {res*2, {-i, res}});
        }
    }
    if(ans.se.fi<0) cout << s.substr(abs(ans.se.fi)-ans.se.se+1, ans.se.se*2);

    else cout << s.substr(ans.se.fi-ans.se.se+1, ans.se.se*2-1);
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();
    return 0;
}
