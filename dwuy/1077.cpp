/// (⌐■_■): "have you defined int long long, dwuy?"
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

struct BIT{
    int n;
    vector<int> tree;

    BIT(int n=0){
        this->n=n;
        this->tree.assign(n+5, 0);
    }

    void update(int idx, int val){
        for(; idx<=n; idx+=-idx&idx) tree[idx]+=val;
    }

    int get(int idx){
        int res=0;
        for(; idx; idx-=-idx&idx) res+=tree[idx];
        return res;
    }
};

int n, k;
int a[200005];
int id[200005];
vector<int> v;

void nhap(){
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i], v.push_back(a[i]);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i=1; i<=n; i++) id[i]=lower_bound(v.begin(), v.end(), a[i])-v.begin()+1;
}

void solve(){
    BIT bit(n); BIT cnt(n);
    int sum=0;
    for(int i=1; i<=k; i++){
        sum+=a[i];
        bit.update(id[i], a[i]);
        cnt.update(id[i], 1);
    }
//    int everage=sum/k+(sum%k+1>k/2);
//    int idx = lower_bound(v.begin(), v.end(), everage) - v.begin()+1;
//    int tmp1 = bit.get(idx), tmp2=cnt.get(idx);
//    int cost = everage*cnt.get(idx) - tmp1 + (sum - tmp1) - everage*(k - tmp2) ;
//    cout << cost <<  " ";
    for(int i=k; i<=n; i++){
        if(i>k){
            sum+=a[i]-a[i-k];
            bit.update(id[i-k], -a[i-k]);
            cnt.update(id[i-k], -1);
            bit.update(id[i], a[i]);
            cnt.update(id[i], 1);
        }
        int everage=sum/k;
        int idx = lower_bound(v.begin(), v.end(), everage) - v.begin();
        int tmp1 = bit.get(idx), tmp2=cnt.get(idx);
        int cost = everage*cnt.get(idx) - tmp1 + (sum - tmp1) - everage*(k - tmp2) ;
//        cerr << "costttt: " << cost << endl;
//        cerr << "eve: " << everage << endl;
//        cerr << "idx: " << idx << endl;
        everage--;
        idx = lower_bound(v.begin(), v.end(), everage) - v.begin();
        if(idx!=v.size()+1){
            tmp1 = bit.get(idx), tmp2=cnt.get(idx);
            cost = min(cost, everage*cnt.get(idx) - tmp1 + (sum - tmp1) - everage*(k - tmp2)) ;
        }
//        cerr << "costttt: " << everage*cnt.get(idx) - tmp1 + (sum - tmp1) - everage*(k - tmp2) << endl;
//        cerr << "eve: " << everage << endl;
//        cerr << "idx: " << idx << endl;
        everage--;
        idx = lower_bound(v.begin(), v.end(), everage) - v.begin();
        if(idx!=v.size()+1){
            tmp1 = bit.get(idx), tmp2=cnt.get(idx);
            cost = min(cost, everage*cnt.get(idx) - tmp1 + (sum - tmp1) - everage*(k - tmp2)) ;
        }
//        cerr << "costttt: " << everage*cnt.get(idx) - tmp1 + (sum - tmp1) - everage*(k - tmp2) << endl;
//        cerr << "eve: " << everage << endl;
//        cerr << "idx: " << idx << endl;
        everage--;
        idx = lower_bound(v.begin(), v.end(), everage) - v.begin();
        if(idx!=v.size()+1){
            tmp1 = bit.get(idx), tmp2=cnt.get(idx);
            cost = min(cost, everage*cnt.get(idx) - tmp1 + (sum - tmp1) - everage*(k - tmp2)) ;
        }
//        cerr << "costttt: " << everage*cnt.get(idx) - tmp1 + (sum - tmp1) - everage*(k - tmp2) << endl;
//        cerr << "eve: " << everage << endl;
//        cerr << "idx: " << idx << endl;
        everage+=4;
        idx = lower_bound(v.begin(), v.end(), everage) - v.begin();
        if(idx!=v.size()+1){
            tmp1 = bit.get(idx), tmp2=cnt.get(idx);
            cost = min(cost, everage*cnt.get(idx) - tmp1 + (sum - tmp1) - everage*(k - tmp2)) ;
        }
//        cerr << "costttt: " << everage*cnt.get(idx) - tmp1 + (sum - tmp1) - everage*(k - tmp2) << endl;
//        cerr << "eve: " << everage << endl;
//        cerr << "idx: " << idx << endl;
        everage++;
        idx = lower_bound(v.begin(), v.end(), everage) - v.begin();
        if(idx!=v.size()+1){
            tmp1 = bit.get(idx), tmp2=cnt.get(idx);
            cost = min(cost, everage*cnt.get(idx) - tmp1 + (sum - tmp1) - everage*(k - tmp2)) ;
        }
//        cerr << "costttt: " << everage*cnt.get(idx) - tmp1 + (sum - tmp1) - everage*(k - tmp2) << endl;
//        cerr << "eve: " << everage << endl;
//        cerr << "idx: " << idx << endl;
        everage++;
        idx = lower_bound(v.begin(), v.end(), everage) - v.begin();
        if(idx!=v.size()+1){
            tmp1 = bit.get(idx), tmp2=cnt.get(idx);
            cost = min(cost, everage*cnt.get(idx) - tmp1 + (sum - tmp1) - everage*(k - tmp2)) ;
        }
//        cerr << "costttt: " << everage*cnt.get(idx) - tmp1 + (sum - tmp1) - everage*(k - tmp2) << endl;
//        cerr << "eve: " << everage << endl;
//        cerr << "idx: " << idx << endl;
        cout << cost << " ";
    }

}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}
