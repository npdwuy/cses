/// (⌐■_■): "have you define int long long, dwuy?"
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

int n, q;
int tele[200005][35];

void nhap(){
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        int x; cin >> x;
        tele[i][0]=x;
    }
}

void solve(){
    for(int j=1; j<35; j++)
        for(int i=1; i<=n; i++)
            tele[i][j]=tele[tele[i][j-1]][j-1];
    while(q--){
        int u, k;
        cin >> u >> k;
        while (k){
            int tmp=__lg(k);
            u=tele[u][tmp];
            k^=MASK(tmp);
        }
        cout << u << endl;
    }
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}

