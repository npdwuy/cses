#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> G[200005];
vector<int> rG[200005];

void nhap(){
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        rG[v].push_back(u);
    }
}


bitset<200005> vist=0;
int be=-1, en=-1, cnt;
bool flag=0;
int p[200005];
int sta[200005];
int fin[200005];
void dfs1(int u){
    sta[u]=++cnt;
    for (int v: G[u]){
        if(!vist[v]) p[v]=u, vist[v]=1, dfs1(v);
        else{
            if(fin[v]!=0) continue;
            be=u, en=v;
            flag=1;
            break;
        }
        if(flag) break;
    }
    fin[u]=++cnt;
}

void dfs2(int u){
    sta[u]=++cnt;
    for (int v: rG[u]){
        if(!vist[v]) p[v]=u, vist[v]=1, dfs2(v);
        else{
            if(fin[v]!=0) continue;
            be=u, en=v;
            flag=1;
            break;
        }
        if(flag) break;
    }
    fin[u]=++cnt;
}

void solve(){
    for(int i=1; i<=n; i++) if (!vist[i]) dfs1(i);
    if(be!=-1){
        vector<int> v;
        v.push_back(en);
        while (1){
            v.push_back(be);
            if(be==en) break;
            be=p[be];
        }
        cout << v.size() << endl;
        reverse(v.begin(), v.end());
        for(int x: v) cout << x << " ";
        return;
    }
    cout << "IMPOSSIBLE";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    nhap();
    solve();

    return 0;
}
