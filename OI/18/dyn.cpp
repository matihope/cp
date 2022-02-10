#include <bits/stdc++.h>

using namespace std;

struct vert : vector<int> {
    int depth = -1;
    int parent = - 1;
};

vector<vert> graph;
vector<int> tin, tout;
vector<vector<int>> up;
vector<bool> marked, vis;
vector<pair<int, int>> bombs; // depth, index
int timer, timer2, L;

void dfs(int v, int p){
    vis[v] = true;
    graph[v].depth = graph[p].depth + 1;
    if(marked[v - 1])
        bombs.push_back({graph[v].depth, v});
    up[v][0] = p;
    for(int i = 1; i <= L; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];
    tin[v] = timer++;
    
    for(auto& c: graph[v]){
        if(!vis[c])
            dfs(c, v);
    }

    tout[v] = timer++;
}

void dfs2(int start){
    stack<int> q;
    vis[start] = true;
    graph[start].parent = start;
    q.push(start);
    tin[start] = timer++;
    while(!q.empty()){
        int v = q.top(); q.pop();
        graph[v].depth = graph[graph[v].parent].depth + 1;
        if(marked[v - 1])
            bombs.push_back({graph[v].depth, v});
        up[v][0] = graph[v].parent;
        for(int i = 1; i <= L; ++i)
            up[v][i] = up[up[v][i - 1]][i - 1];
        
        tout[v] = timer++;
        for(auto& c: graph[v]){
            if(!vis[c]){
                vis[c] = true;
                tin[c] = timer++;
                graph[c].parent = v;
                q.push(c);
            }
        }

    }
}

void root(int v, int n){
    tin.assign(n + 1, 0);
    tout.assign(n + 1, 0);
    timer = 0;
    L = ceil(log2(n));
    vis.assign(n + 1, 0);
    up.assign(n + 1, vector<int>(L + 1, 0));
    // dfs(1, 1);
    dfs2(1);
}

bool is_ancestor(int a, int b){
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

int lca(int a, int b){
    if(is_ancestor(a, b)) return a;
    if(is_ancestor(b, a)) return b;

    for(int i = L; i >= 0; i--){
        if(!is_ancestor(up[b][i], a))
            b = up[b][i];
    }

    return up[b][0];
}

int go_up_by_k(int v, int k){
    for(int i = 0; i <= 31; ++i)
        if((1<<i)&k)
            v = up[v][i];
    return v;
}

int dist_to_v(int a, int v){
    int l = lca(a, v);
    return graph[a].depth - graph[l].depth + graph[v].depth - graph[l].depth;
}

bool fits(int d, int m, int n){
    int left = m;
    vector<int> starters;
    for(auto& [_, index]: bombs){
        bool found = false;
        for(auto s: starters){
            if(dist_to_v(index, s) <= d){
                found = true;
                break;
            }
        }
        if(!found){
            if(left-- == 0)
                return false;
            starters.push_back(go_up_by_k(index, d));
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, b;
    cin >> n >> m;
    marked.assign(n, 0);
    for(int i = 0; i < n; ++i){
        cin >> a;
        marked[i] = a;
    }
    
    graph.assign(n + 1, {});
    for(int i = 0; i < n - 1; ++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    root(1, n);
    sort(bombs.begin(), bombs.end(), greater<pair<int, int>>());

    int l = 0, r = n - 1, mid;
    while(l < r){
        mid = (l + r) / 2;
        if(!fits(mid, m, n))
            l = mid + 1;
        else
            r = mid;
    }
    cout << l << endl;

}