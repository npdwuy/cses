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

int32_t main(){
    fastIO;
    //file(TASK);

    string s; cin >> s;
    int pf=0, sf=0;
    int base=0307, tmp=1;
    for(int i=0, j=len(s)-1; i+1<len(s); i++, j--){
         pf=(pf*base+s[i])%MOD;
         sf=(sf+s[j]*tmp%MOD)%MOD;
         tmp=tmp*base%MOD;
         if(sf==pf) cout << i+1 << " ";
    }

    return 0;
}
