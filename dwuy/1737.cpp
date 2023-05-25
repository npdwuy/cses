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

struct Node{
    int sum;
    Node *l, *r;

    Node(){
        sum=0;
        l=r=NULL;
    }

    Node(Node *other){
        l = other->l;
        r = other->r;
        sum = other->sum;
    }
};

/// just a bruh bruh lmao SegMent Tree
int n, q, cnt=1;
int a[200005];
Node *root[200005];

void build(Node *node, int l, int r){
    if (l==r){
        node->sum=a[l];
        node->l = new Node();
        node->r = new Node();
        return;
    }
    int mid=(l+r)>>1;
    node->l = new Node();
    node->r = new Node();
    build(node->l, l, mid);
    build(node->r, mid+1, r);
    node->sum = node->l->sum + node->r->sum;
}

void build(Node *node){
    build(node, 1, n);
}

void update(Node *node, int l, int r, const int &idx, const int &val){
    if (l==r){
        node->sum = val;
        return;
    }
    int mid=(l+r)>>1;
    if (idx<=mid){
        node->l = new Node(node->l);
        update(node->l, l, mid, idx, val);
    }
    else{
        node->r = new Node(node->r);
        update(node->r, mid+1, r, idx, val);
    }
    node->sum = node->l->sum + node->r->sum;
}

void update(Node *node, int idx, int val){
    update(node, 1, n, idx, val);
}

int get(Node *node, int l, int r, const int &u, const int &v){
    if (l>=u && r<=v) return node->sum;
    if (l>v || r<u) return 0;
    int mid=(l+r)>>1;
    return get(node->l, l, mid, u, v) + get(node->r, mid+1, r, u, v);
}

int get(Node *node, int u, int v){
    return get(node, 1, n, u, v);
}

void nhap(){
    cin >> n >> q;
    for(int i=1; i<=n; i++) cin >> a[i];
}

void solve(){
    root[1] = new Node();
    build(root[1]);
    while(q--){
        int type; cin >> type;
        if (type==1){
            int k, x, idx;
            cin >> k >> idx >> x;
            update(root[k], idx, x);
        }
        else if (type==2){
            int k, u, v;
            cin >> k >> u >> v;
            cout << get(root[k], u, v) << endl;
        }
        else{
            int k; cin >> k;
            root[++cnt] = new Node(root[k]);
        }
    }
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}
