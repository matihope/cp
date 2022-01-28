#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<bool> vis;

struct vert{
    int scc_id = -1;
    vector<int> con;
    vector<int> inv_con;
};

vector<vert> graph;
vector<int> post;

struct scc{
    int size = 0;
};
vector<scc> sccs;

void dfs(int v){
    vis[v] = true;
    for(auto c: graph[v].con){
        if(!vis[c])
            dfs(c);
    }
    post.push_back(v);
}

void dfs2(int v, int scc_id){
    vis[v] = true;
    graph[v].scc_id = scc_id;
    sccs[scc_id].size++;
    for(auto c: graph[v].inv_con){
        if(!vis[c]){
            dfs2(c, scc_id);
        }
    }
}

void dfs3(int v){
    vis[v] = true;
    for(auto c: graph[v].con){
        if(!vis[c])
            dfs3(c);
        if(graph[v].scc_id != graph[c].scc_id)
            sccs[graph[v].scc_id].size += sccs[graph[c].scc_id].size;
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    int a, b;
    graph.assign(n + 1, {});
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        graph[a].con.push_back(b);
        graph[b].inv_con.push_back(a);
    }
    vis.assign(n + 1, 0);
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            dfs(i);
    reverse(post.begin(), post.end());
    vis.assign(n + 1, 0);
    for(auto v: post){
        if(!vis[v]){
            sccs.push_back({});
            dfs2(v, int(sccs.size()) - 1);
        }
    }
    vis.assign(n + 1, 0);
    for(auto v: post){
        if(!vis[v]){
            dfs3(v);
        }
    }
    for(int i = 1; i <= n; ++i)
        cout << sccs[graph[i].scc_id].size - 1 << endl;
}
