#include <bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
#define len(s) int32_t(s.length())
using namespace std;

int dp[21][10];
string a, b;

bool check(int x){
    while (x>10) if (x%10==x/10%10) return false; else x/=10;
    return true;
}

int cnt(int x){
    int res=0;
    for(int i=0; i<=x; i++) res+=check(i);
    return res;
}

bool check(string a){
    for(int i=0; i<len(a); i++) if (a[i]==a[i+1]) return false;
    return 1;
}

void solve(){
//    cout << a << " " << b << " " << len(a) << " " << len(b) << endl;
    for(int i=0; i<10; i++) dp[1][i]=1;
    for(int i=2; i<=20; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<10; k++){
                if (j!=k) dp[i][j]+=dp[i-1][k];
            }
        }
    }
    int A=1;
    for(int i=1; i<len(a)-2; i++) A+=dp[i+1][0];
    for(int i=0; i<a.back()-'0'; i++) A+=dp[len(a)-1][i];
    for(int i=len(a)-2; i>0; i--){
        for(int j=0; j<a[i]-'0'; j++){
            if (j==a[i+1]-'0') continue;
            A+=dp[i][j];
        }
        if (a[i]==a[i+1]) break;
        if (i==1) A++;
    }
    int B=1;
    for(int i=1; i<len(b)-2; i++) B+=dp[i+1][0];
    for(int i=0; i<b.back()-'0'; i++) B+=dp[len(b)-1][i];
    for(int i=len(b)-2; i>0; i--){
        for(int j=0; j<b[i]-'0'; j++){
            if (j==b[i+1]-'0') continue;
            B+=dp[i][j];
        }
        if (b[i]==b[i+1]) break;
        if (i==1) B++;
    }

//    cout << A << " " << B << endl;
    cout << B-A+check(a) << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;
    a+=' '; b+=' ';
    reverse(all(a));
    reverse(all(b));
    solve();

    return 0;
}
