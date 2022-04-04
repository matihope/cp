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

#ifdef LOCAL_H
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

bool key(const pair<int, bool> a, const pair<int, bool> b) {
    return a.first < b.first;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, o = 0;
    cin >> n;
    char c;
    int in, mindist = INT32_MAX;
    bool existsC = false;
    pair<int, bool> person[n];
    for(int i = 0; i < n; i++)
    {
        cin >> in >> c;
        person[i] = MP(in, c == 'n'); // n is infected, c is not
        if(c == 'c')
            existsC = true;
    }
    if(!existsC)
    {
        cout << 1;
        return 0;
    }
    sort(person, person + n, key);
    /*for(int i = 0; i < n; i++)
        cerr << person[i].first << ' ' << person[i].second << '\n';
    */
    for(int i = 1; i < n; i++)
    {
        if(person[i].second != person[i - 1].second)
            mindist = min(mindist, person[i].first - person[i - 1].first);
    }
    //cerr << mindist << endl;
    o = person[0].second;
    for(int i = 1; i < n; i++)
    {
        if(person[i].second)
            if(!person[i - 1].second || person[i].first - person[i - 1].first >= mindist)
                o++;
    }
    cout << o;
    return 0;
}
