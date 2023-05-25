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
#define int unsigned long long

using namespace std;

typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef long long ll;

const long long OO=1e18;
const int INF=1e9;
const int MOD=INF+7;

int power[20];
int d[20];

void solve(){
    int pos=0; cin >> pos;
    int cnt=0, res=-1, dem=0;
    for(int lo=1, hi=1e18; lo<=hi;){
        int mid=(lo+hi)>>1;
        stringstream ss; ss << mid; string s; ss >> s;
        cnt=d[len(s)-1]+len(s)*(mid-power[len(s)-1]+1);
        if(cnt>=pos) dem=cnt, res=mid, hi=mid-1;
        else lo=mid+1;
    }
    cnt=dem;
    string tmp; stringstream ss; ss << res; ss >> tmp;
    pos=pos-(cnt-len(tmp));
    cout << tmp[pos-1] << endl;
}

int32_t main(){
    fastIO;
    //file(TASK);
    int q; cin >> q;
    power[0]=1;
    for(int i=1; i<=18; i++) power[i]=power[i-1]*10;
    for(int i=1; i<18; i++) d[i]=d[i-1]+i*(power[i]-power[i-1]);
//    for(int i=1; i<=18; i++) cout << power[i] << " " << d[i] << endl;
//    int cnt=0;
//    for(int i=1; i<10000; i++) cnt+=i<10? 1: i<100? 2: i<1000? 3:4;
//    cout << cnt << endl;

    while(q--){
        solve();
    }
    return 0;
}

/// 1234567891011121314

