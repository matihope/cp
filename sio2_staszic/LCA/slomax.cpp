#include <bits/stdc++.h>

using namespace std;

int n, L, timer = 1;

struct vert{
    vector<pair<int, int>> conns;
    int depth = 0;
};

vector<bool> visited;
vector<vert> graph;
vector<vector<int>> up;
vector<vector<int>> up_max;
vector<int> tin, tout;

void dfs(int v, int p){
    tin[v] = timer++;
    visited[v] = true;
    up[v][0] = p;
    for(int i = 1; i <= L; ++i){
        up[v][i] = up[up[v][i - 1]][i - 1];
        up_max[v][i] = max(up_max[up[v][i - 1]][i - 1], up_max[v][i - 1]);
    }
    for(auto conn: graph[v].conns){
        if(!visited[conn.first]){
            visited[conn.first] = true;
            graph[conn.first].depth = graph[v].depth + 1;
            up_max[conn.first][0] = conn.second;
            dfs(conn.first, v);
        }
    }
    
    tout[v] = timer++;
}

bool is_ancestor(int a, int b){   
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b){
    if(is_ancestor(a, b)) return a;
    if(is_ancestor(b, a)) return b;
    for(int i = L; i >= 0; --i){
        if(!is_ancestor(up[b][i], a)){
            b = up[b][i];
        }
    }
    return up[b][0];
}

int max_to_v(int a, int v){
    if(graph[a].depth - graph[v].depth == 1) return up_max[a][0];
    int max_len = up_max[a][0];
    for(int i = L; i >= 0; --i){
        if(graph[up[a][i]].depth >= graph[v].depth){
            max_len = max(max_len, up_max[a][i]);
            a = up[a][i];
        }
    }
    return max_len;
}

void preprocess(int v){
    L = ceil(log2(n));
    up.assign(n + 1, vector<int>(L + 1));
    up_max.assign(n + 1, vector<int>(L + 1, -1e9 - 1));
    visited.assign(n + 1, false);
    tin.assign(n + 1, 0);
    tout.assign(n + 1, 0);
}

int main(){
    if(){
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    int a, b, c;
    graph.assign(n + 1, {});
    for(int i = 1; i < n; ++i){
        cin >> a >> b >> c;
        graph[a].conns.emplace_back(b, c);
        graph[b].conns.emplace_back(a, c);
    }
    preprocess(1);
    dfs(1, 1);
    cin >> a;
    while(a != -1){
        cin >> b;
        int res1, res2;
        if(a == b) res1 = 0, res2 = 0;
        else{
            int l = lca(a, b);
            if(a == l) res1 = -1e9 - 1;
            else{
                res1 = max_to_v(a, l);
            }
            if(b == l) res2 = -1e9 - 1; 
            else{
                res2 = max_to_v(b, l);
            }
        }
        cout << max(res1, res2) << endl;
        cin >> a;
    }
}
