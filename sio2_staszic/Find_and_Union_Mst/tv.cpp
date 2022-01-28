#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <cmath>
#include <queue>

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
#define INF 2000000001
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

constexpr int MOD = 1e9 + 7;

struct house{
    int x, y;
};

int dist(house& h1, house& h2){
    long double distance_squared = pow(abs(h1.x - h2.x), 2) + pow(abs(h1.y - h2.y), 2);
    return ceill(sqrt(distance_squared));
}

int n;
vector<house> graph;
vector<bool> visited;
LL counter = 0;
int max_length = 0;

void Prim(){
    vector<int> q(n, INF);
    q[0] = 0;
    for(int i = 0; i < n; ++i) {
        int v = -1;
        REP(j, n){
            if(!visited[j] && (v == -1 || q[v] > q[j]))
                v = j;
        }
        visited[v] = true;
        max_length = max(max_length, q[v]);
        for(int i = 0; i < n; ++i){
            if(!visited[i]){
                q[i] = min(dist(graph[v], graph[i]), q[i]);
            }
        }
    }
}

 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> n;
    visited.assign(n, false);
    REP(i, n){
        cin >> a >> b;
        graph.push_back({a, b});
    }
    Prim();
    counter = ( (max_length % MOD) * (n - 1) ) % MOD;
    cout << counter << endl;

    return 0;
}