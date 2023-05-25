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

const double EPS = 0.0000000000001;
int n, m;
double sum=0;
dd a[2005];
dd b[2005];

double sqr(double x){
    return x*x;
}

double euler(dd a, dd b){
    return sqrt(sqr(a.fi-b.fi)+sqr(a.se-b.se));
}

double dt(dd a, dd b, dd c){
    double ab=euler(a, b);
    double bc=euler(c, b);
    double ac=euler(a, c);
    double p=(ab+bc+ac)/2;
    return sqrt(p*(p-ab)*(p-ac)*(p-bc));
}

bool mid(dd a, dd b, dd c){
    if (abs(b.fi-c.fi)<EPS){
        return a.se>=min(b.se, c.se) && a.se<=max(b.se, c.se);
    }
    if (b.fi>c.fi) swap(b, c);
    return a.fi>=min(b.fi, c.fi) && a.fi<=max(b.fi, c.fi);
}

void nhap(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    for(int i=2; i<n; i++){
        sum+=dt(a[1], a[i], a[i+1]);
    }
}

int check(dd x){
    double tmp=0;
    for (int i=1; i<n; i++){
        double t=dt(x, a[i], a[i+1]);
        if (t<EPS && mid(x, a[i], a[i+1])){
            return -1;
        }
        tmp+=t;
    }
    double t=dt(x, a[1], a[n]);
    if (t<EPS && mid(x, a[1], a[n])) return -1;
    tmp+=t;
    if (abs(tmp-sum)<EPS) return 1;
    else return 0;

}

void solve(){
    while(m--){
        dd tmp;
        cin >> tmp.fi >> tmp.se;
        int st=check(tmp);
        if (st==0) cout << "OUTSIDE\n";
        else if (st==1) cout << "INSIDE\n";
        else cout << "BOUNDARY\n";
    }
}

int32_t main(){
    fastIO;
    //file(TASK);

    nhap();
    solve();

    return 0;
}

/**
4 3
1 1
4 2
3 5
1 4
2 3
3 1
1 3

100 1000
-7 -19
91 77
100 100
64 60
-11 -1
80 87
69 95
5 46
37 46
25 38
-40 14
-11 35
0 33
-28 54
-19 62
25 84
13 87
-4 87
-16 73
-1 96
-44 75
-24 79
-59 18
-75 72
-54 31
-43 97
-100 100
-97 91
-52 -1
-68 15
-49 -14
-2 -9
-36 -24
-62 -9
-25 -53
-48 -21
-20 -59
-61 -12
-41 -65
-56 -52
-77 -17
-62 -73
-84 -25
-77 -15
-83 49
-93 -20
-88 59
-92 42
-100 50
-94 3
-100 -100
-93 -79
-83 -97
-51 -100
-52 -59
-44 -75
-38 -58
-46 -83
-24 -88
7 -43
97 1
61 -23
92 -13
92 -43
81 -40
84 -42
32 -42
19 -54
52 -43
81 -50
79 -85
69 -58
19 -60
-11 -72
9 -66
26 -77
28 -89
40 -71
47 -98
97 -100
97 -21
100 -100
96 37
79 16
98 57
26 -14
41 -6
46 -1
94 0
84 -5
20 -18
80 -6
21 -21
26 -21
-27 -71
28 -2
74 56
25 0
29 16
16 -1
96 -47
-49 -70
-92 -27
16 51
33 -9
13 -27
12 -7
41 -10
-99 66
52 56
20 10
62 -50
28 -55
-2 -84
55 -53
-49 52
-23 24
-56 -84
5 80
74 1
1 -62
-14 -90
40 -5
-38 0
40 98
-67 11
49 98
-56 6
-34 63
91 27
72 26
-19 79
-43 -20
-18 -81
-39 -73
-40 22
-80 -63
63 28
-75 -57
30 42
40 -34
-98 68
12 -89
5 -35
44 48
-81 12
42 -50
-99 -31
68 -37
67 96
-88 -64
100 28
-49 19
54 -3
-82 97
-49 51
79 24
97 13
-84 -13
-7 15
25 48
-44 -77
-59 83
94 -21
-7 57
-4 0
87 -50
50 19
-42 67
-11 4
-37 38
-23 42
-19 86
30 -58
73 -19
68 -7
-36 5
0 68
24 27
86 47
-84 -48
79 -55
-98 35
35 29
39 -3
75 -22
-85 12
-31 94
45 -40
-51 -73
-38 83
-51 42
-16 94
19 15
-63 32
2 71
80 -1
7 76
-77 92
-3 79
-93 53
-2 -77
46 -2
-75 -40
73 -13
-41 -87
-99 -36
95 -30
81 -23
-73 31
-21 67
31 12
-26 -28
5 -59
5 84
-54 88
-27 -50
-70 -47
64 17
64 13
64 9
25 22
-71 98
-35 -89
47 0
-86 88
-47 -88
51 10
-5 91
8 -95
70 -70
-84 22
94 -11
22 89
-74 -32
-81 -8
-45 78
59 93
32 -11
84 -1
22 73
21 58
37 -89
-2 22
48 92
2 -45
31 56
-84 7
-90 -53
-12 -55
8 4
84 47
58 -71
54 -90
49 31
38 71
-50 -83
-49 -84
-26 17
-46 -15
6 55
16 23
64 -40
-71 -39
-42 18
65 -16
-56 95
-10 -11
-30 -34
72 72
57 43
43 95
42 -91
12 -56
72 -42
-44 66
-17 68
20 -34
63 96
57 80
43 28
-42 16
-98 -44
39 65
27 -42
47 44
-25 38
-35 34
-6 -83
47 -1
-61 11
9 -33
-26 -66
-96 -85
64 -4
-56 94
-78 -50
76 -53
-42 -26
-45 2
16 -36
13 2
-66 81
-58 76
-64 71
-65 9
-35 99
-78 -83
-1 41
-82 2
47 90
-24 41
44 42
-77 -95
-59 10
-20 -79
-46 30
-3 -71
48 -30
-38 65
-66 33
25 22
-34 -93
53 -54
88 -67
-87 -74
13 95
87 -30
73 20
-68 77
-71 -7
-61 -41
87 -81
55 93
-20 -34
36 -68
84 34
64 -32
-87 15
59 -45
-18 99
-75 5
-2 57
-54 -88
62 -43
14 37
-10 -54
63 64
-96 98
-64 -29
-25 70
-65 72
59 -16
48 33
18 34
73 96
41 -78
-77 99
80 67
6 80
-44 27
-87 78
8 77
-23 -4
-96 39
1 75
94 -12
63 7
59 53
67 -49
53 47
88 -56
-63 -90
-94 15
-67 31
50 -20
-30 46
28 86
70 75
2 32
-27 -64
21 30
48 14
-5 94
-1 -59
70 -28
35 11
-54 -79
-66 69
68 -9
-59 9
-60 -20
66 23
-34 -4
75 25
-48 -95
96 -42
24 -97
-70 69
76 14
63 5
85 57
29 59
7 47
49 13
27 67
88 86
7 51
-41 -17
-54 -96
-49 98
47 -25
71 61
-44 34
9 52
23 57
65 51
-9 -83
77 13
79 -62
-83 0
58 56
-89 -51
-53 -20
-21 4
8 33
8 13
15 63
78 72
14 -92
83 42
-91 20
-26 -17
25 -32
-13 0
-67 56
-67 2
6 -22
7 -75
-98 -66
-64 -100
94 -65
79 -85
-55 -62
-5 -4
31 -17
7 -48
-24 78
32 -74
-15 96
80 -52
59 -63

**/



