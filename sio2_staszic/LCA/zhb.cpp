#include <bits/stdc++.h>

using namespace std;

struct vert{
    vector<int> conns;
    int depth = 0;
};

int n, m, k, timer, L;
vector<bool> visited;
vector<vector<int>> up;
vector<int> tin, tout;
vector<vert> graph;

void dfs(int v, int p){
    visited[v] = true;
    tin[v] = timer++;
    up[v][0] = p;
    for(int i = 1; i <= L; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];
    
    for(int c: graph[v].conns){
        if(!visited[c]){
            graph[c].depth = graph[v].depth + 1;
            dfs(c, v);
        }
    }
    tout[v] = timer++;
}

void init(int v){
    timer = 0;
    L = ceil(log2(n));
    up.assign(n + 1, vector<int>(L + 1, 0));
    tin.assign(n + 1, 0);
    tout.assign(n + 1, 0);
    visited.assign(n + 1, 0);
    dfs(v, v);
}

bool is_ancestor(int a, int b){
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b){
    if(is_ancestor(a, b)) return a;
    if(is_ancestor(b, a)) return b;
    for(int i = L; i >= 0; --i)
        if(!is_ancestor(up[b][i], a))
            b = up[b][i];
    return up[b][0];
}

int dist(int a, int b, int l){
    if(a == l) return graph[b].depth - graph[a].depth;
    if(b == l) return graph[a].depth - graph[b].depth;
    return graph[a].depth + graph[b].depth - 2 * graph[l].depth;
}

int jump_x_up(int from, int jumps){
    for(int i = 0; i <= L; ++i)
        if((1<<i) & jumps)
            from = up[from][i];
    return from;
}

int main(){
    #ifndef LOCAL_H
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #endif

    cin >> n >> m >> k;
    int a, b;
    graph.assign(n + 1, {});
    for(int i = 1; i < n; ++i){
        cin >> a >> b;
        graph[a].conns.push_back(b);
        graph[b].conns.push_back(a);
    }
    init(1);
    while(k--){
        cin >> a >> b; // target, max_time
        int l = lca(a, m);
        if(dist(m, a, l) <= b)
            m = a;
        else {
            int dist_to_l = dist(m, l, l);
            if(dist_to_l == b) m = l;
            else if(dist_to_l > b) m = jump_x_up(m, b);
            else if(dist_to_l < b){
                b -= dist_to_l;
                int dist_to_l_from_a = dist(a, l, l);
                m = jump_x_up(a, dist_to_l_from_a - b);
            }
            
        }
        cout << m << " ";
    }
}
