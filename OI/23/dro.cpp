#include <bits/stdc++.h>

using namespace std;

struct vert{
    int in_o = 0, in_e = 0;
    int scc_id = -1;
    vector<int> conns_o, conns_e; 
    bool good = true;
};

struct scc{
    vector<int> verts;
    int min_conn = __INT32_MAX__;
};

vector<vert> graph;
vector<scc> sccs;
vector<bool> vis;
vector<int> topo;

void dfs1(int v){
    vis[v] = true;
    for(auto& c: graph[v].conns_o)
        if(!vis[c])
            dfs1(c);
    topo.push_back(v);
}

void dfs2(int v, int scc_id){
    vis[v] = true;
    graph[v].scc_id = scc_id;
    sccs[scc_id].verts.push_back(v);
    for(auto c: graph[v].conns_e)
        if(!vis[c])
            dfs2(c, scc_id);
}

void dfs3(int v, int scc_id){
    vis[v] = true;
    graph[v].scc_id = scc_id;
    sccs[scc_id].verts.push_back(v);
    for(auto c: graph[v].conns_o)
        if(!vis[c])
            dfs3(c, scc_id);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b;
    cin >> n >> m;
    graph.assign(n + 1, {});
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        graph[a].conns_o.push_back(b);
        graph[b].in_o++;
        graph[b].conns_e.push_back(a);
        graph[a].in_e++;
    }
    vis.assign(n + 1, 0);
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs1(i);
    vis.assign(n + 1, 0);
    reverse(topo.begin(), topo.end());
    for(auto i: topo){
        if(!vis[i]){
            sccs.push_back({});
            dfs2(i, sccs.size() - 1);
        }
    }
    for(scc& s: sccs){
        s.min_conn = sccs.size();
        for(auto& v: s.verts){
            for(auto& c: graph[v].conns_o){
                if(graph[c].scc_id != graph[v].scc_id)
                    s.min_conn = min(s.min_conn, graph[c].scc_id);
            }
        }
    }
    int carry = sccs[graph[topo[0]].scc_id].min_conn;
    for(int i = 1; i < topo.size(); i++){
        if(carry > graph[topo[i]].scc_id && graph[topo[i - 1]].scc_id != graph[topo[i]].scc_id)
            graph[topo[i]].good = false;
        carry = max(sccs[graph[topo[i]].scc_id].min_conn, carry);
    }
    reverse(topo.begin(), topo.end());
    vis.assign(n + 1, 0);
    sccs.clear();
    for(auto i: topo){
        if(!vis[i]){
            sccs.push_back({});
            dfs3(i, sccs.size() - 1);
        }
    }
    for(scc& s: sccs){
        s.min_conn = sccs.size();
        for(auto& v: s.verts){
            for(auto& c: graph[v].conns_e){
                if(graph[c].scc_id != graph[v].scc_id)
                    s.min_conn = min(s.min_conn, graph[c].scc_id);
            }
        }
    }
    carry = sccs[graph[topo[0]].scc_id].min_conn;
    for(int i = 1; i < topo.size(); i++){
        if(carry > graph[topo[i]].scc_id && graph[topo[i - 1]].scc_id != graph[topo[i]].scc_id)
            graph[topo[i]].good = false;
        carry = max(sccs[graph[topo[i]].scc_id].min_conn, carry);
    }
    vector<int> verts;
    for(int i = 1; i <= n; ++i){
        if(graph[i].good){
            verts.push_back(i);
        }
    }
    cout << verts.size() << endl;
    for(auto v: verts)
        cout << v << " ";
    
}