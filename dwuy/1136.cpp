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
        p[v]=spt[v][0]=u; cla[v]=cla[u]+1;
        dfs(v);
        numC[u]+=numC[v];
        if (heavy[u]==-1 || numC[heavy[u]]<numC[v])
            heavy[u]=v;
    }
}

void decompose(int u, int h){
    head[u]=h;
    pos[u]=++cnt;
    if(heavy[u]!=-1) decompose(heavy[u], h);
    for(int v: G[u]){
        if(v==p[u] || v==heavy[u]) continue;
        decompose(v, v);
    }
}

int LCA(int u, int v){
    if(cla[u]<cla[v]) swap(u, v);
    for(int i=20; i>=0; i--){
        if(cla[spt[u][i]]>=cla[v]) u=spt[u][i];
    }
//    cerr << u << " " << v << endl;
    if(u==v) return u;
    for(int i=20; i>=0; i--){
        if(spt[u][i]!=spt[v][i]) {
            u=spt[u][i];
            v=spt[v][i];
        }
    }
    return spt[u][0];
}

void update(int u, int v){
    int puv=LCA(u, v);
    while (head[u]!=head[v]){
        if(head[u]!=head[puv]){
            mark[pos[head[u]]]++;
            mark[pos[u]+1]--;
            u=p[head[u]];
        }
        if(head[v]!=head[puv]){
            mark[pos[head[v]]]++;
            mark[pos[v]+1]--;
            v=p[head[v]];
        }
    }
    if(pos[u]>pos[v]) swap(u, v);
    mark[pos[u]]++;
    mark[pos[v]+1]--;
}

void solve(){
    memset(heavy, -1, sizeof(heavy));
    cla[1]=1; dfs(1);
    decompose(1, 1);
    for(int j=1; j<=20; j++){
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
