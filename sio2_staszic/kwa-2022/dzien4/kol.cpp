#include <bits/stdc++.h>

using namespace std;

constexpr int MAX_N = 1e5 * 2 + 1;
int n;
int L;
struct edge{ int target, value; };
struct vert: vector<edge> {
    int parent = -1;
    int depth = -1;
    int dist_to_root = 0;
};
vector<vert> graph;
int REP[MAX_N];
int DEG[MAX_N];
vector<vector<int>> up;
vector<bool> vis;

void dfs(int v, int p){
    graph[v].parent = p;
    graph[v].depth = graph[p].depth + 1;
    up[v][0] = p;
    for(int i = 1; i <= L; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];
    
    for(auto c: graph[v])
        if(c.target != p){
            graph[c.target].dist_to_root = graph[v].dist_to_root + c.value;
            dfs(c.target, v);
        }
}

int Find(int a){
    if(REP[a] == a)
        return a;
    return REP[a] = Find(REP[a]);
}

void build(int a, int b, int edge_val){
    if(DEG[Find(a)] < DEG[Find(b)])
        swap(a, b);
        
    // DEG[a] >= DEG[b] => add B to A
    DEG[Find(a)] += DEG[Find(b)];
    REP[Find(b)] = Find(a);
    graph[a].push_back({b, edge_val});
    graph[b].push_back({a, edge_val});
    graph[b].dist_to_root = graph[a].dist_to_root + edge_val;
    dfs(b, a);
}

void init(int new_n, int s){
    n = new_n;
    L = ceil(log2(n));
    up.assign(n + 1, vector<int>(L + 1, 0));
    graph.assign(n + 1, {});
    vis.assign(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        REP[i] = i;    
        DEG[i] = 1;    
        dfs(i, i);
    }
}

int dist(int a, int b){
    if(graph[a].depth < graph[b].depth)
        swap(a, b);

    // graph[b].depth >= graph[a].depth
    return graph[a].dist_to_root - graph[b].dist_to_root;
}

int path(int x, int y){
    if(graph[x].depth > graph[y].depth)
        swap(x, y);

    long long d = 0;
    // graph[x].depth <= graph[y].depth
    if(graph[x].depth < graph[y].depth){
        // jump y to level of x
        int to_jump = graph[y].depth - graph[x].depth;
        int v = y;
        for(int i = 0; i < 32; i++)
            if((1<<i)&to_jump)
                v = up[v][i];
        
        d += dist(v, y);
        y = v;
    }
    // jump to the same level
    int x1 = x, y1 = y;
    if(x1 == y1) return d;
    for(int i = L; i >= 0; i--){
        if(up[x1][i] != up[y1][i]){
            x1 = up[x1][i];
            y1 = up[y1][i];
        }
    }
    int lca = up[x1][0];
    return d + graph[x].dist_to_root + graph[y].dist_to_root - 2 * graph[lca].dist_to_root;
}

#ifdef LOCAL_H
int main()
{
    int N, Q;
    cin >> N >> Q;
    init(N, 0);
    for(int q=0; q<Q; q++)
    {
        string command;
        int x, y, t;
        cin >> command >> x >> y;
        if (command=="B")
        {
            cin >> t;
            build(x,y,t);
        }
        else
            cout << path(x,y) << endl;
    }
}
#endif