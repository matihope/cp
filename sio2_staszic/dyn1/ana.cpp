#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <algorithm>

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
void _print(const string& t) {cerr << t;}
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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    VPII s1, s2;
    string s;
    cin >> s;
    for(int i = 0; i < SIZE(s); ++i)
        s1.emplace_back(s[i], i);
    cin >> s;
    for(int i = 0; i < SIZE(s); ++i)
        s2.emplace_back(s[i], i);
    sort(ALL(s1));
    sort(ALL(s2));
    int i = 0, j = 0;
    int counter = 0;
    while(i < SIZE(s1) && j < SIZE(s2)){
        if(s1[i].ST == s2[j].ST){
            i++;
            j++;
            counter++;
        } else if(s1[i].ST < s2[j].ST){
            s1[i++].ND = INF;
        } else {
            s2[j++].ND = INF;
        }
    }
    while(i < SIZE(s1)) s1[i++].ND = INF;
    while(j < SIZE(s2)) s2[j++].ND = INF;
    sort(ALL(s1), [](const PII& a, const PII& b) { return a.ND < b.ND; });
    sort(ALL(s2), [](const PII& a, const PII& b) { return a.ND < b.ND; });
    if(counter){
        printf("%d\n", counter);
        i = 0;
        while(i < SIZE(s1) && s1[i].ND != INF){
            printf("%c", s1[i++]);
        }
        printf("\n%d\n", counter);
        i = 0;
        while(i < SIZE(s2) && s2[i].ND != INF){
            printf("%c", s2[i++]);
        }
    } else {
        printf("BRAK\n");
    }

    return 0;
}
