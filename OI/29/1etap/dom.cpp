#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <vector>
#include <tuple>

using namespace std;

typedef long long LL;
typedef long double LLD;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<pair<int, int>> VPII;
typedef pair<int, int> PII;

#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define ST first
#define ND second
#define INF 1000000001
#define MP make_pair

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(LL t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(LLD t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ULL t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ST); cerr << ","; _print(p.ND); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ULL fib[] = {
    1,
    1,
    2,
    3,
    5,
    8,
    13,
    21,
    34,
    55,
    89,
    144,
    233,
    377,
    610,
    987,
    1597,
    2584,
    4181,
    6765,
    10946,
    17711,
    28657,
    46368,
    75025,
    121393,
    196418,
    317811,
    514229,
    832040,
    1346269,
    2178309,
    3524578,
    5702887,
    9227465,
    14930352,
    24157817,
    39088169,
    63245986,
    102334155,
    165580141,
    267914296,
    433494437,
    701408733,
    1134903170,
    1836311903,
    2971215073,
    4807526976,
    7778742049,
    12586269025,
    20365011074,
    32951280099,
    53316291173,
    86267571272,
    139583862445,
    225851433717,
    365435296162,
    591286729879,
    956722026041,
    1548008755920,
    2504730781961,
    4052739537881,
    6557470319842,
    10610209857723,
    17167680177565,
    27777890035288,
    44945570212853,
    72723460248141,
    117669030460994,
    190392490709135,
    308061521170129,
    498454011879264,
    806515533049393,
    1304969544928657,
    2111485077978050,
    3416454622906707,
    5527939700884757,
    8944394323791464,
    14472334024676221,
    23416728348467685,
    37889062373143906,
    61305790721611591,
    99194853094755497,
    160500643816367088,
    259695496911122585,
    420196140727489673,
    679891637638612258,
    1100087778366101931,
    1779979416004714189,
    2880067194370816120,
    4660046610375530309,
    7540113804746346429,
};
int fib_len = 92;

int bin_search_fib(ULL* m){
    int l = 0, r = fib_len;
    int mid;
    while(l < r){
        mid = (l + r) / 2;
        if(fib[mid] < *m)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

vector<ULL> find_divisors(ULL n){
    vector<ULL> d;
    for(int i = fib_len-1; i >= 2; --i){
        if(n % fib[i] == 0){
            d.push_back(fib[i]);
        }
    }
    return d;
}

vector<ULL> h;

bool find_history(vector<ULL>& divs, ULL n){
    if(n == 1)
        return true;
    for(int i = 0; i < divs.size(); ++i){
        if(n % divs[i] == 0 && find_history(divs, n / divs[i])){
            h.push_back(divs[i]);
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ULL m;
    cin >> m;
    ULL n = 0;

    if(m == 1){
        cout << 1 << '\n';
        return 0;
    }

    vector<ULL> divisors = find_divisors(m);
    // debug(divisors);
    if(find_history(divisors, m)){   
        REP(i, h.size())
            n += bin_search_fib(&h[i]) + 1;
        cout << n - 1 << '\n';
    } else {
        cout << "NIE" << '\n';
    }

    return 0;
}

/*
0 1
1 1
2 2
3 3
4 5
5 8
6 13
7 21
8 34
9 55
10 89
11 144
12 233
13 377
14 610
15 987
16 1597
17 2584
18 4181
19 6765
20 10946
21 17711
22 28657
23 46368
24 75025
25 121393
26 196418
27 317811
28 514229
29 832040
30 1346269
31 2178309
32 3524578
33 5702887
34 9227465
35 14930352
36 24157817
37 39088169
38 63245986
39 102334155
40 165580141
41 267914296
42 433494437
43 701408733
44 1134903170
45 1836311903
46 2971215073
47 4807526976
48 7778742049
49 12586269025
50 20365011074
51 32951280099
52 53316291173
53 86267571272
54 139583862445
55 225851433717
56 365435296162
57 591286729879
58 956722026041
59 1548008755920
60 2504730781961
61 4052739537881
62 6557470319842
63 10610209857723
64 17167680177565
65 27777890035288
66 44945570212853
67 72723460248141
68 117669030460994
69 190392490709135
70 308061521170129
71 498454011879264
72 806515533049393
73 1304969544928657
74 2111485077978050
75 3416454622906707
76 5527939700884757
77 8944394323791464
78 14472334024676221
79 23416728348467685
80 37889062373143906
81 61305790721611591
82 99194853094755497
83 160500643816367088
84 259695496911122585
85 420196140727489673
86 679891637638612258
87 1100087778366101931
88 1779979416004714189
89 2880067194370816120
90 4660046610375530309
91 7540113804746346429
92 12200160415121876738
*/
