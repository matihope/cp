#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <stack>
#include <queue>
#include <bitset>

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

constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 1e3;
#define VC vector<int>

vector<LL> areas;
struct vertex {
    int val;
    VC edges;
    int parent = -1;
    int depth = 0;
};

int rep[MAX_N];
LL size_of_colony[MAX_N];
LL count_of_areas = 0;

int Find(int a){
    if(rep[a] == a)
        return a;
    return rep[a] = Find(rep[a]);
}

void Union(int a, int b){
    size_of_colony[Find(a)] += size_of_colony[Find(b)];
    size_of_colony[Find(a)] %= MOD;
    size_of_colony[Find(b)] = 0;
    count_of_areas--;
    rep[Find(b)] = Find(a);
}

vector<vertex> graph;
int vertex_num = 0;
int m;
LL pos = 0;

void construct_graph(string& inpt, int parent){
    int me = vertex_num++;
    graph.push_back({inpt[pos] - '0', VC()});
    if(parent != -1){
        // graph[me].edges.push_back(parent);
        graph[me].parent = parent;
        graph[parent].edges.push_back(me);
        graph[me].depth = graph[parent].depth + 1;
        if(graph[me].val == 1){
            count_of_areas++;
            size_of_colony[me] = areas[graph[me].depth];
        }
    }

    if(inpt[pos++] == '4'){
        for(int i = 0; i < 4; ++i){
            construct_graph(inpt, me);
        }
    }
}

stack<int> st;
void bfs(int v){
    queue<int>q; 
    q.push(v);
    while(!q.empty()){
        int t = q.front(); q.pop();
        if(graph[t].val == 4) st.push(t);
        for(auto c: graph[t].edges)
            q.push(c);
    }
}

enum SIDES {
    TOP = 0b1100,
    RIGHT = 0b0101,
    LEFT = 0b1010,
    BOTTOM = 0b0011
};

bool is_this_side_on(int v, SIDES side){
    if(graph[v].val == 1)
        return true;
    return false;
}

void get_r(int& r, int v, SIDES side){
    for(int i = 0; i < 4; ++i){
        if((1<<i)&side){
            if(is_this_side_on(graph[v].edges[3 - i], side)){
                r |= (1<<i)&side;
            }
        }
    }
}

void cmp(int v1, int v2, SIDES v1_side, SIDES v2_side){
    int rv1 = 0, rv2 = 0;
    if(graph[v1].val == 1)
        rv1 = 15;
    else if(graph[v1].val == 4)
        get_r(rv1, v1, v1_side);
    
    if(graph[v2].val == 1)
        rv2 = 15;
    else if(graph[v2].val == 4)
        get_r(rv2, v2, v2_side);
    if(v1_side == SIDES::LEFT)
        rv1 <<= 1;
    if(v1_side == SIDES::TOP)
        rv1 <<= 2;
    if(rv1&rv2){
        Union(v1, v2);
    } 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string inpt;
    cin >> m >> inpt;
    areas.assign(m + 1, 0);
    areas[m] = 1;
    for(int i = m - 1; i >= 0; --i){
        areas[i] = areas[i + 1] * 4; // quick potegowanie
        areas[i] %= MOD;
    }
    for(int i = 0; i < inpt.size(); ++i) rep[i] = i;
    
    construct_graph(inpt, -1);

    bfs(0);
    while(!st.empty()){
        int v = st.top(); st.pop();
        for(int i = 0; i < 3; ++i){
            int curr_v = graph[v].edges[i];
            switch(i){
                case 0:
                    cmp(graph[v].edges[0], graph[v].edges[1], SIDES::LEFT, SIDES::RIGHT);
                    cmp(graph[v].edges[0], graph[v].edges[2], SIDES::TOP, SIDES::BOTTOM);
                    break;
                case 1:
                    cmp(graph[v].edges[1], graph[v].edges[3], SIDES::TOP, SIDES::BOTTOM);
                    break;
                case 2:
                    cmp(graph[v].edges[2], graph[v].edges[3], SIDES::LEFT, SIDES::RIGHT);
                    break;
            }
        }
        int p = graph[v].parent;
        int pos = 0;
        for(; pos < 4; ++pos)
            if(graph[p].edges[pos] == v) break;
        switch(pos){
            case 0:
                cmp(v, graph[p].edges[1], SIDES::LEFT, SIDES::RIGHT);
                cmp(v, graph[p].edges[2], SIDES::TOP, SIDES::BOTTOM);
                break;
            case 1:
                cmp(graph[p].edges[0], v, SIDES::LEFT, SIDES::RIGHT);
                cmp(v, graph[p].edges[3], SIDES::TOP, SIDES::BOTTOM);
                break;
            case 2:
                cmp(graph[p].edges[0], v, SIDES::TOP, SIDES::BOTTOM);
                cmp(v, graph[p].edges[3], SIDES::LEFT, SIDES::RIGHT);
                break;
            case 3:
                cmp(graph[p].edges[1], v, SIDES::TOP, SIDES::BOTTOM);
                cmp(graph[p].edges[2], v, SIDES::LEFT, SIDES::RIGHT);
                break;
        }
    }

    cout << count_of_areas << endl;
    return 0;
}