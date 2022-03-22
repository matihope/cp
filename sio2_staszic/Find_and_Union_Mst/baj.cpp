#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <queue>
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

struct edge{
    int p, k, w, i;
    bool taken = false;
};
auto cmp1 = [](const edge& a, const edge& b){ return a.w < b.w; };
auto cmp2 = [](const edge& a, const edge& b){ return a.i < b.i; };
vector<edge> vec2;

template <typename T>
void print_queue(T q) {
    for(auto x: q){
        cout << "P: " << x.p << ", K: " << x.k << ", W: " << x.w << " T: " << x.taken << endl;
    }
    cout << '\n';
}

int n, m;
constexpr int MAX_N = 1e6 * 2 + 1;
int rep[MAX_N + 1];

int Find(int a){
    if(a == rep[a])
        return a;
    return (rep[a] = Find(rep[a]));
}

void Union(int a, int b){
    rep[Find(a)] = Find(b);
}

void do_the_thing(VPII& to_add){
    for(PII p: to_add){
        Union(p.first, p.second);
    }
    to_add.clear();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    REP(i, n)
        rep[i + 1] = i + 1;
    REP(i, m){
        int a, b, w;
        cin >> a >> b >> w;
        vec2.push_back({a, b, w, i});
    }
    sort(vec2.begin(), vec2.end(), cmp1);
    VPII to_add; 
    int prev_waga = 0;
    for(edge& e: vec2){
        if(prev_waga != e.w){
            do_the_thing(to_add);
        }
        if(Find(e.p) != Find(e.k)){
            e.taken = true;
            to_add.push_back({e.p, e.k});
        }
        prev_waga = e.w;
    }
    do_the_thing(to_add);
    sort(vec2.begin(), vec2.end(), cmp2);
    for(auto& x: vec2){
        if(!x.taken){
            cout << "NIE" << endl;
        } else {
            cout << "TAK" << endl;
        }
    }


    return 0;
}