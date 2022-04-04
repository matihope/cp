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

    int n, m;
    cin >> n >> m;    
    vector<LL> dist(n + 1, __LONG_LONG_MAX__);
    vector<bool> lock(n + 1, 0);
    vector<VPII> graph(n + 1);
    vector<VI> parent(n + 1);
    int a, b, w;
    REP(i, m){
        cin >> a >> b >> w;
        graph[a].emplace_back(w, b);
        graph[b].emplace_back(w, a);
    }
    priority_queue<PII, VPII, greater<PII>> q;
    q.push({0, 1});
    dist[1] = 0;
    while(!q.empty()) {
        auto [_, v] = q.top(); q.pop();
        if(lock[v]) continue;
        lock[v] = true;
        for(auto e: graph[v]){
            if(dist[v] + e.ST <= dist[e.ND]){
                if(dist[v] + e.ST < dist[e.ND])
                    parent[e.ND].clear();
                parent[e.ND].push_back(v);
                q.push({dist[e.ND] = dist[v] + e.ST, e.ND});
            }
        }
    }
    vector<int> vs;
    vector<bool> visi2(n + 1, false);
    queue<int> q2;
    q2.push(n);
    while(!q2.empty()) {
        int v = q2.front();
        q2.pop();
        if(visi2[v]) {
            continue;
        }
        visi2[v] = true;
        vs.push_back(v);
        for(auto p: parent[v])
            q2.push(p);
    }
    sort(ALL(vs));
    for(auto i: vs){
        cout << i << "\n";
    }

    return 0;
}
