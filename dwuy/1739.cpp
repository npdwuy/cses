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

struct BIT{
    int n, m;
    vector<vector<int>> tree;

    BIT(int _n=0, int _m=0){
        n=_n;;
        m=_m;
        tree.assign(n+5, vector<int>(m+5));
    }

    void update(int x, int y, int val){
        if (val*x*y==0) return;
        for(int i=x; i<=n; i+=-i&i){
            for(int j=y; j<=m; j+=-j&j){
                tree[i][j]+=val;
            }
        }
    }

    int get(int x, int y){
        int res=0;
        for(int i=x; i>0; i-=-i&i)
            for(int j=y; j>0; j-=-j&j)
                res+=tree[i][j];
        return res;
    }

    int get(int x, int y, int u, int v){
        return get(u, v)+get(x-1, y-1)-get(x-1, v)-get(u, y-1);
    }

};

int n, m, q;
string a[2005];

int32_t main(){
    fastIO;
    //file(TASK);

    cin >> n >> q; m=n;
    BIT bit(n, m);
    for(int i=1; i<=n; i++){
        cin >> a[i];
        a[i]=' '+a[i];
        for(int j=1; j<=m; j++) bit.update(i, j, a[i][j]=='*');
    }

    while (q--){
        int type;
        cin >> type;
        if (type==1){
            int x, y; cin >> x >> y;
            bit.update(x, y, (a[x][y]=='*'? -1:1));
            a[x][y]='*'^'.'^a[x][y];
        }
        else{
            int x, y, u, v;
            cin >> x >> y >> u >> v;
            cout << bit.get(x, y, u, v) << endl;
        }

    }

    return 0;
}





