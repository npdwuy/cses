/**   - dwuy -

　　　　　 ／＞　   フ
　　　　　 | 　_　 _|
　 　　　 ／`ミ _x ノ
　　 　 /　　　 　 |
　　　 /　  ヽ　　 ?
　／￣|　　 |　|　|
　| (￣ヽ＿_ヽ_)_)
　＼二つ

**/
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

const int hasMod[]={INF+7, INF+5277};
const int base=307;

int n;
string s;
int val[1000005][2];
int powB[1000005][2];

int get1(int l, int r){
    return (val[r][0]-val[l-1][0]*powB[r-l+1][0]+hasMod[0]*hasMod[0])%hasMod[0];
}

int get2(int l, int r){
    return (val[r][1]-val[l-1][1]*powB[r-l+1][1]+hasMod[1]*hasMod[1])%hasMod[1];
}

bool dif(int l, int r, int u, int v){
    if (r-l!=v-u) return true;
    return (get1(l, r)!=get1(u, v) || get2(l, r)!=get2(u, v));
}

void solve(){
    n=len(s);
    s=' '+s;
    powB[0][0]=powB[0][1]=1;
    for(int i=1; i<=n; i++)
        for(int j=0; j<2; j++)
            powB[i][j]=powB[i-1][j]*base%hasMod[j];
    for(int i=1; i<=n; i++)
        for(int j=0; j<2; j++)
            val[i][j]=(val[i-1][j]*base + s[i])%hasMod[j];
    for(int i=1; i<=n; i++){
        bool flag=true;
        int j=i+i;
        int code1=get1(1, i);
        int code2=get2(1, i);
        for(; j<=n; j+=i){
            if (code1!=get1(j-i+1, j) || code2!=get2(j-i+1, j)){
                flag=false;
                break;
            }
        }
        if (j!=n+i && flag){
            j-=i-1;
            flag=!dif(1, n-j+1, j, n);
        }
        if (flag){
            cout << s.substr(1, i) << endl;
            return;
        }
    }
}

int32_t main(){
    fastIO;
    //file(TASK);

    cin >> s;
    solve();

    return 0;
}





