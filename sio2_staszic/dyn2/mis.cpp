#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <vector>
#include <tuple>
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

LL max_sum_x_l = 0;
LL n, m;

struct vert{
    LL c, l, max_sum = 0, count = 0;
    vector<int> children;
    priority_queue<int> costs;
    int self_pos = -1;
    int seg_tree_sons_range = -1;
};

vector<int> t;

vector<vert> graph;

struct segtree{
    int size;
    vector<LL> sums;
    vector<PII> ma;
    
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        sums.assign(size * 2, 0);
        ma.assign(size * 2, {0, -1});
    }

    LL query_sum(int l, int r, int x, int tl, int tr){
        if(l > r) return 0;
        if(l == tl && r == tr){
            return sums[x];
        }
        int m = (tl + tr) / 2;
        return query_sum(l, min(m, r), x * 2, tl, m) + query_sum(max(m + 1, l), r, x * 2 + 1, m + 1, tr);
    }

    LL query_sum(int l, int r){
        return query_sum(l, r, 1, 0, size - 1);
    }

    PII query_max_pos(int l, int r, int x, int tl, int tr){
        if(l > r) return {0, -1};
        if(tl == l && tr == r)
            return ma[x];
        
        int m = (tl + tr) / 2;
        PII mx = query_max_pos(l, min(r, m), x * 2, tl, m);
        auto res2 = query_max_pos(max(m + 1, l), r, x * 2 + 1, m + 1, tr);
        if(res2.ND != -1 && res2.ST > mx.ST) mx = res2;
        return mx;
    }

    int query_max_pos(int l, int r){
        return query_max_pos(l, r, 1, 0, size - 1).ND;
    }

    void set(int pos, int val, int x, int tl, int tr){
        if(tl == tr){
            sums[x] = val;
            if(val == 0){
                ma[x] = {0, -1};
                graph[t[tl]].count--;
            }
            else{
                ma[x] = {val, tl};
                graph[t[tl]].count++;
            }
        } else {
            int m = (tl + tr) / 2;
            if(pos <= m)
                set(pos, val, x * 2, tl, m);
            else
                set(pos, val, x * 2 + 1, m + 1, tr);
            sums[x] = sums[x * 2] + sums[x * 2 + 1];
            ma[x] = ma[x * 2];
            if(ma[x * 2 + 1].ND != -1 && ma[x * 2 + 1].ST > ma[x].ST)
                ma[x] = ma[x * 2 + 1];
        }
    }

    void set(int pos, int val){
        set(pos, val, 1, 0, size - 1);
    }
};

segtree st;

void dfs1(int v){
    graph[v].self_pos = SIZE(t);
    t.push_back(v);
    for(auto c: graph[v].children)
        dfs1(c);
    graph[v].seg_tree_sons_range = SIZE(t) - 1;
}

void dfs2(int v){
    for(auto c: graph[v].children)
        dfs2(c);
 
    int vl = graph[v].self_pos, vr = graph[v].seg_tree_sons_range;
    st.set(graph[v].self_pos, graph[v].c);
    for(auto c: graph[v].children)
        graph[v].count += graph[c].count;
    while(st.query_sum(vl, vr) > m){
        int pos = st.query_max_pos(vl, vr);
        st.set(pos, 0);
        if(pos != vl)
            graph[v].count--;
    }
    graph[v].max_sum = st.query_sum(vl, vr);

    
    max_sum_x_l = max(max_sum_x_l, graph[v].l * graph[v].count);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    graph.assign(n + 1, {});
    st.init(n);
    int b;
    REP(i, n){
        cin >> b >> graph[i + 1].c >> graph[i + 1].l;
        if(b != 0)
            graph[b].children.push_back(i + 1);
    }
    dfs1(1);
    dfs2(1);
    cout << max_sum_x_l << endl;

    return 0;
}
