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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, days, w, maxw = 0, md, nw;
    vector<int> heavies;
    cin >> m >> days;
    vector<pair<int, int> > melons; //weight, sum of wins
    for(int i = 0; i < m; i++)
    {
        cin >> w;
        if(w > maxw)
        {
            maxw = w;
            heavies = vector<int>(1, i);
        } else if(w == maxw) 
        {
            heavies.PB(i);
        }
        melons.PB(MP(w, 0));
    }
    for(int i = 0; i < days; i++)
    {
        cin >> md >> nw;
        melons[md - 1].first += nw;
        if(melons[md - 1].first > maxw)
        {
            heavies = vector<int>(1, md - 1);
            maxw = melons[md - 1].first;
        }
        else if(melons[md - 1].first == maxw)
            heavies.PB(md - 1);
        for(int j : heavies)
            melons[j].second += i + 1;
    }
    int maxsumi = 0;
    for(int i = 1; i < m; i++)
    {
        if(melons[i].second > melons[maxsumi].second)
            maxsumi = i;
    }
    cout << maxsumi + 1;
    return 0;
}
