#include <bits/stdc++.h>

using namespace std;

#define LL long long

int n;

int MAX_JUMP = 1;
vector<vector<int>> up;

struct conn{
    int target, w;
};

struct vert{
    vector<conn> conns;
    LL len = 0;
};

#define debug(x) { cerr << #x << " " << x << endl; }

vector<vert> graph;
vector<bool> visited;
vector<int> tin, tout;
int timer = 0;

void dfs(int v, int p){
    visited[v] = true;
    tin[v] = ++timer;
    // precompute ancestors
    up[v][0] = p;
    for(int i = 1; i <= MAX_JUMP; ++i){
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    
    // iterate over sons
    for(auto c: graph[v].conns){
        if(!visited[c.target]){
            visited[c.target] = true;
            graph[c.target].len = graph[v].len + c.w;
            dfs(c.target, v);
        }
    }
    tout[v] = ++timer;
}

bool is_ancestor(int a, int b){   
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b){
    // @return: lca_vertex_id
    if(is_ancestor(a, b)) return a;
    if(is_ancestor(b, a)) return b;
    for(int i = MAX_JUMP; i >= 0; --i){
        if(!is_ancestor(up[b][i], a)){
            b = up[b][i];
        }
    }
    return up[b][0];
}

LL calc_path(int v, int ancestor){
    return graph[v].len - graph[ancestor].len;
}

void preprocess(int v){
    visited.assign(n + 1, false);
    MAX_JUMP = ceil(log2(n + 1));
    up.assign(n + 1, vector<int>(MAX_JUMP + 1));
    tin.assign(n + 1, 0);
    tout.assign(n + 1, 0);
    for(int i = 0; i <= MAX_JUMP; ++i)
        up[v][i] = v;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    int a, b, c;
    graph.assign(n + 1, vert());
    for(int i = 1; i < n; ++i){
        cin >> a >> b >> c;
        graph[a].conns.push_back({b, c});
        graph[b].conns.push_back({a, c});
    }
    
    preprocess(a);
    dfs(a, a);
    
    cin >> a;
    while(a != -1){
        cin >> b;
        int now_lca = lca(a, b);
        LL len = calc_path(a, now_lca) + calc_path(b, now_lca);
        cout << len << endl;
        cin >> a;
    }
}
