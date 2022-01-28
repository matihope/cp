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

vector<VI> graph;
vector<VI> graph_inversed;
vector<LL> weight;
VI path;

vector<bool> visited;
vector<char> color;
int cycle_start = -1;
int n;
vector<LL> distance_to;
LL max_distance = 0;

bool dfs(int v) {
    color[v] = 1;
    for (int u : graph[v]) {
        if (color[u] == 0) {
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
            cycle_start = u;
            return true;
        }
    }
    path.push_back(v);
    color[v] = 2;
    return false;
}

bool find_cycle(){
    for(int i = 1; i < n; ++i){
        if(color[i] == 0){
            if(dfs(i))
                break;
        }
    }
    return (cycle_start != -1);
}

void hehe_sort(){
    reverse(ALL(path));
    // debug(path);
    for(auto v: path){
        for(auto u: graph[v]){
            if(distance_to[v] + weight[u] > distance_to[u]){
                distance_to[u] = distance_to[v] + weight[u];
            }
        }
    }
    reverse(ALL(path));
    for(auto v: path){
        for(auto u: graph_inversed[v]){
            distance_to[u] = max(distance_to[u], distance_to[v]);
        }
        max_distance = max(max_distance, distance_to[v]);
    }
    reverse(ALL(path));
}

bool check_brute(int vertex, int new_weight){
    auto graph1 = graph;
    auto graph2 = graph_inversed;
    auto new_distance_to = weight, weights2 = weight;
    weights2[vertex] += new_weight;
    new_distance_to[vertex] += new_weight;
    LL new_max_distance = 0;
    for(auto v: path){
        for(auto u: graph1[v]){
            if(new_distance_to[v] + weights2[u] > new_distance_to[u]){
                new_distance_to[u] = new_distance_to[v] + weights2[u];
                if(new_distance_to[u] > max_distance) return true;
            }
        }
        if(new_distance_to[v] > max_distance) return true;
    }
    return new_max_distance > max_distance;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, c;
    cin >> n;
    n++;

    graph.assign(n, VI());
    graph_inversed.assign(n, VI());
    weight.assign(n, 0);
    visited.assign(n, false);
    color.assign(n, 0);
    distance_to.assign(n, INF);

    REP(i, n-1){
        cin >> a >> b;
        weight[i + 1] = a;
        distance_to[i + 1] = a;
        REP(j, b){
            cin >> c;
            graph[c].push_back(i + 1);
            graph_inversed[i + 1].push_back(c);
        }
    }

    if(find_cycle()){
        cout << "CYKL" << endl;
    } else {
        hehe_sort();
        cout << max_distance << endl;
        int q, m, d;
        cin >> q;
        REP(i, q){
            cin >> m >> d;
            if(check_brute(m, d)){
                cout << "TAK" << endl;
            } else {
                cout << "NIE" << endl;
            }
        }
    }

    return 0;
}