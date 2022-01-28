#include <bits/stdc++.h>

using namespace std;

struct vert{
    vector<int> conns, inv;
    int p = 0;
    int scc_id = 0;
};
vector<vert> graph;
vector<bool> vis;
vector<int> topo;
int ma = 0;

struct scc{
    int id;
    vector<int> verts;
    int total_sum = 0;
    int best = 0;
};

vector<scc> sccs;

void dfs(int v){
    vis[v] = true;
    for(auto c: graph[v].conns)
        if(!vis[c])
            dfs(c);
    topo.push_back(v);
}

void dfs2(int v, int scc_id){
    if(!vis[v]){
        graph[v].scc_id = scc_id;
        sccs[scc_id].verts.push_back(v);
        sccs[scc_id].total_sum += graph[v].p;
    }
    vis[v] = true;
    for(auto c: graph[v].inv)
        if(!vis[c])
            dfs2(c, scc_id);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, a, b;
    cin >> n >> m;
    graph.assign(n + 1, {});
    for(int i = 1; i <= n; ++i)
        cin >> graph[i].p;
    
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        graph[a].conns.push_back(b);
        graph[b].inv.push_back(a);
    }
    vis.assign(n + 1, 0);
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs(i);
    reverse(topo.begin(), topo.end());
    vis.assign(n + 1, 0);
    for(auto v: topo){
        if(!vis[v]){
            sccs.push_back({int(sccs.size())});
            dfs2(v, int(sccs.size()) - 1);
        }
    }
    for(size_t i = sccs.size(); i > 0; --i){
        scc& s = sccs[i - 1];
        for(auto& v: s.verts){
            for(auto& c: graph[v].conns){
                scc& new_s = sccs[graph[c].scc_id];
                if(new_s.id != s.id) s.best = max(new_s.best, s.best);
            }
        }
        s.best += s.total_sum;
        ma = max(s.best, ma);
    }
    cout << ma << endl;
    
}