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
const int base=1e6;

struct Node{
    int val;
    int sum;

    Node(int _val=0, int _sum=0){
        val=_val;
        sum=_sum;
    }
};

struct SMT{ /// just a SegMent Tree
    int n;
    vector<Node> tree;

    SMT(int _n=0): n(_n) {
        tree.assign(n*4+5, Node());
    }

    void update(int l, int r, int id, int u, int v, int val){
        if (l>v || r<u) return;
        if (l>=u && r<=v){
            int _id= id<<1;
            tree[id].val+=val;
            if (tree[id].val==0){
                if (l!=r) tree[id].sum = tree[_id].sum + tree[_id|1].sum;
                else tree[id].sum=0;
            }
            else tree[id].sum = r-l+1;
            return;
        }
        int mid = (l+r)>>1;
        int _id = id<<1;
        update(l, mid, _id, u, v, val);
        update(mid+1, r, _id|1, u, v, val);
        if (tree[id].val==0) tree[id].sum = tree[_id].sum+tree[_id|1].sum;
    }

    void update(int u, int v, int val){
        update(1, n, 1, u, v, val);
    }
};

struct Line{
    int x, top, bot;
    int mode;

    Line(int _x=0, int _bot=0, int _top=0, int _mode=1){
        x = _x;
        bot = _bot;
        top = _top;
        mode = _mode;
    }

    bool operator < (const Line &other){
        return (x != other.x)? x < other.x:mode<other.mode;
    }
};

int n;
vector<Line> v;

void nhap(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        x+=base; y+=base; a+=base; b+=base;
        v.push_back(Line(x, y+1, b, 1));
        v.push_back(Line(a, y+1, b,-1));
    }
}

void solve(){
    sort(v.begin(), v.end());
    SMT smt(2*base+10);
    smt.update(v[0].bot, v[0].top, v[0].mode);
    int ans=0;
    for(int i=1; i<(int)v.size(); i++){
        ans+=smt.tree[1].sum*(v[i].x-v[i-1].x);
        smt.update(v[i].bot, v[i].top, v[i].mode);
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





