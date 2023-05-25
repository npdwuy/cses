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

using namespace std;

typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef long long ll;

const long long OO=1e18;
const int INF=1e9;
const int MOD=INF+7;

int n, m, q;
string a[2005];
int sum[2005][2005];


int32_t main(){
    fastIO;
    //file(TASK);

    cin >> n >> q; m=n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        a[i]=' '+a[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(a[i][j]=='*');
        }
    }
    while (q--){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        cout << sum[u][v] + sum[x-1][y-1] - sum[x-1][v] - sum[u][y-1] << endl;

    }

    return 0;
}





