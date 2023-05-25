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

int n, k;
int a[200005];
multiset<int, greater<int>> L;
multiset<int, less<int>> R;

void nhap(){
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    if (k==1){
        for(int i=1; i<=n; i++) cout << a[i] << " ";
        exit(0);
    }
}
void solve(){
    for(int i=1; i<=k; i++){
        if (L.size()<(k+1)/2) L.insert(a[i]);
        else{
            if (a[i]<*L.begin()){
                R.insert(*L.begin());
                L.erase(L.begin());
                L.insert(a[i]);
            }
            else R.insert(a[i]);
        }
    }
//    for(auto ptr=L.begin(); ptr!=L.end(); ptr++) cout << *ptr << " - "; for(auto ptr=R.begin(); ptr!=R.end(); ptr++) cout << *ptr << " "; cout << endl;
    cout << *L.begin() << ' ';
    for(int i=k+1; i<=n; i++){
        if (a[i-k]<=*L.begin()){
            L.erase(L.find(a[i-k]));
            L.insert(*R.begin());
            R.erase(R.begin());
        }
        else R.erase(R.find(a[i-k]));

        if (a[i]>=*L.begin()) R.insert(a[i]);
        else{
            R.insert(*L.begin());
            L.erase(L.begin());
            L.insert(a[i]);
        }
//    for(auto ptr=L.begin(); ptr!=L.end(); ptr++) cout << *ptr << " "; for(auto ptr=R.begin(); ptr!=R.end(); ptr++) cout << *ptr << " "; cout << endl;
        cout << *L.begin() << " ";
    }
}


int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}





