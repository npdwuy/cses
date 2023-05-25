#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, q, cnt, cntChain;
vector<int> G[200005];
int spt[200005][25];
int p[200005];
int pos[200005];
int cla[200005];
int numC[200005];
int head[200005];
int mark[200005];
int heavy[200005];
int chainID[200005];

void nhap(){
    cin >> n >> q;
    for(int i=1; i<n; i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void dfs(int u){
    numC[u]=1;
    for(int v: G[u]){
        if(v==p[u]) continue;
        p[v]=u; cla[v]=cla[u]+1;
        dfs(v);
        numC[u]+=numC[v];
        if (heavy[u]==-1 || numC[heavy[u]]<numC[v])
            heavy[u]=v;
    }
}

void decompose(int u){
    if(head[cntChain]==0) head[cntChain]=u;
    chainID[u]=cntChain;
    pos[u]=++cnt;
    if(heavy[u]!=-1) decompose(heavy[u]);
    for(int v: G[u]){
        if(v==p[u] || v==heavy[u]) continue;
        cntChain++;
        decompose(v);
    }
}

int LCA(int u, int v){
    if(cla[u]<cla[v]) swap(u, v);
    for(int i=__lg(n); i>=0; i--){
        if(cla[spt[u][i]]>=cla[v]) u=spt[u][i];
    }
    if(u==v) return u;
    for(int i=__lg(n); i>=0; i--){
        if(spt[u][i]!=spt[v][i]) {
            u=spt[u][i];
            v=spt[v][i];
        }
    }
    return spt[u][0];
}

void update(int u, int v){
    int puv=LCA(u, v);
    int uChain=chainID[u];
    int vChain=chainID[v];
    while (uChain!=vChain){
        if(uChain!=chainID[puv]){
            mark[pos[head[uChain]]]++;
            mark[pos[u]+1]--;
            u=p[head[uChain]];
            uChain=chainID[u];
        }
        if(vChain!=chainID[puv]){
            mark[pos[head[vChain]]]++;
            mark[pos[v]+1]--;
            v=p[head[vChain]];
            vChain=chainID[v];
        }
    }
    if(pos[u]>pos[v]) swap(u, v);
    mark[pos[u]]++;
    mark[pos[v]+1]--;
}

void solve(){
    memset(heavy, -1, sizeof(heavy));
    dfs(1);
    decompose(1);
    for(int j=1; j<=__lg(n); j++){
        for(int i=1; i<=n; i++){
            spt[i][j]=spt[spt[i][j-1]][j-1];
        }
    }
//    for(int i=1; i<=n; i++) cout  << head[chainID[i]] << " " << chainID[i] << " " << pos[i] << " " << heavy[i] << " " << i << endl;
    while (q--){
        int u, v;
        cin >> u >> v;
        update(u, v);
    }
    int sum=0;
    for(int i=1; i<=n; i++) sum+=mark[i], mark[i]=sum;
    for(int i=1; i<=n; i++) cout << mark[pos[i]] << " ";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

//    freopen("test.inp","r",stdin);
//    freopen("test.out","w",stdout);

    nhap();
    solve();

    return 0;
}

