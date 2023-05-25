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
const int MOD=1e9+7;
const int base = 0307;

struct Node{
    bool isEnd;
    Node *child[30];

    Node(){
        this->isEnd=0;
        for(int i=0 ; i<30; i++) this->child[i]=NULL;
    }
};

int n;
string s;
int dp[5005];
Node *root = new Node();

void add(const string &s){
    Node *cur = root;
    for(int i=0; i<len(s); i++){
        int c = s[i] - 'a';
        if(cur->child[c]==NULL) cur->child[c] = new Node();
        cur = cur->child[c];
    }
    cur->isEnd=1;
}

void nhap(){
    cin >> s;
    cin >> n;
    while(n--){
        string x; cin >> x;
        reverse(x.begin(), x.end());
        add(x);
    }
    s=' '+s;
}

void solve(){
    dp[0]=1;
    for(int i=1; i<len(s); i++){
        Node *cur = root;
        for(int j=i; j>0; j--){
            int c = s[j] - 'a';
            if(cur->child[c]!=NULL) cur = cur->child[c];
            else break;
            if(cur->isEnd) dp[i]=(dp[i]+dp[j-1])%MOD;
        }
    }
    cout << dp[len(s)-1];
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}
