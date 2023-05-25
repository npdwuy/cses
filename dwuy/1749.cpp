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
#define int long long

using namespace std;

typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef long long ll;

const long long OO=1e18;
const int INF=1e9;
const int MOD=INF+7;

struct BIT{
    int n;
    vector<int> tree;

    BIT(int _n=0){
        n=_n;
        tree.assign(n+5, 0);
    }

    void build(){
        for(int i=1; i<=n; i++) tree[i]=-i&i;
    }

    void update(int idx, int val){
        while (idx<=n){
            tree[idx]+=val;
            idx+=-idx&idx;
        }
    }

    int lwbound(int x){
        int mask=1;
        while (mask<=n) mask<<=1; mask>>=1;
        int res=n+1, tmp=0;
        while (mask){
//                cout << tmp << " " << x << endl;
            if (tree[tmp|mask]>=x) res=tmp|mask;
            else{
                tmp|=mask;
                x-=tree[tmp];
            }
            mask>>=1;
        }
        return res;
    }
};

int n;
int a[2000005];
BIT bit(2000005);

void nhap(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
}

int32_t main(){
    fastIO;
    //file("");
    nhap();
    for(int i=1; i<=n; i++) bit.update(i, 1);
    for(int i=1; i<=n; i++){
        int v; cin >> v;
        int pos=bit.lwbound(v);
        cout << a[pos] << " ";
        bit.update(pos, -1);
    }
    return 0;
}





