#include <bits/stdc++.h>

using namespace std;

struct vert{
    vector<int> conns, inv;
    size_t scc_id = -1;
};

struct scc{
    size_t id;
    vector<int> verts;
    set<int> entering, leaving;
};

vector<vert> graph;
vector<scc> sccs;
vector<bool> vis;
vector<int> topo;
int additional = 0;

void dfs1(int v){
    vis[v] = true;
    for(auto c: graph[v].conns)
        if(!vis[c])
            dfs1(c);
    topo.push_back(v);
}

void dfs2(int v, size_t scc_id){
    vis[v] = true;
    graph[v].scc_id = scc_id;
    sccs[scc_id].verts.push_back(v);
    for(auto c: graph[v].inv)
        if(!vis[c])
            dfs2(c, scc_id);
}

void dfs3(size_t scc_id){
    for(auto v: sccs[scc_id].verts){
        for(auto c: graph[v].conns){
            if(graph[c].scc_id != scc_id){
                sccs[graph[c].scc_id].entering.insert(scc_id);
                sccs[scc_id].leaving.insert(graph[c].scc_id);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, a, b;
    cin >> n >> m;
    graph.assign(n + 1, {});
    vis.assign(n + 1, 0);
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        graph[a].conns.push_back(b);
        graph[b].inv.push_back(a);
    }
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs1(i);
    reverse(topo.begin(), topo.end());
    vis.assign(n + 1, 0);
    for(auto v: topo){
        if(!vis[v]){
            sccs.push_back({sccs.size()});
            dfs2(v, sccs.back().id);
        }
    }
    for(auto& s: sccs)
        dfs3(s.id);
    
    vis.assign(sccs.size() + 1, 0);
    int entering = 0, leaving = 0;
    for(size_t i = 0; i < sccs.size(); ++i){
        scc& s = sccs[i];
        //find all entering and leaving verts
        if(!vis[s.id]){
            stack<int> st;
            st.push(s.id);
            while(!st.empty()){

                int S = st.top(); st.pop();
                vis[S] = true;

                if(sccs[S].entering.size() == 0) entering++;
                if(sccs[S].leaving.size() == 0) leaving++;

                for(auto le = sccs[S].leaving.begin(); le != sccs[S].leaving.end(); ++le)
                    if(!vis[*le])
                        st.push(*le);
            }
        }
    }
    if(sccs.size() == 1)
        cout << 0 << endl;
    else
        cout << max(leaving, entering) << endl;
}
