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

const int dx[]={-1, 1, 0, 0};
const int dy[]={0, 0, -1, 1};
int n, m;
string a[2005];
bool vist[2005][2005];

void nhap(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
}

void dfs(int x, int y){
    vist[x][y]=1;
    for(int i=0; i<4; i++){
        int u=x+dx[i];
        int v=y+dy[i];
        if(u>=n || u<0 || v>=m || v<0 || vist[u][v] || a[u][v]=='#') continue;
        dfs(u, v);
    }
}

void solve(){
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vist[i][j] || a[i][j]=='#') continue;
            dfs(i, j); ans++;
        }
    }
    cout << ans << endl;
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}
