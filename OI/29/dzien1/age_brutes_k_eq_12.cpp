#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct vert: vector<int>{
    int parent;
    int depth = -1;
    int children = 0;
    int max_depth = 0;
    int WROCI = 0;
    int KONIEC = 0;
    bool has_agent = false;
    int agents = 0;
};
vector<vert> graph;
vector<bool> vis;
vector<int> post_order;

void dfs_old(int v, int p){
    graph[v].max_depth = graph[v].depth = graph[p].depth + 1;
    graph[v].parent = p;
    graph[v].agents = int(graph[v].has_agent);
    for(auto& c: graph[v]){
        if(!vis[c]){
            vis[c] = true;
            graph[c].children = 0;
            dfs(c, v);
            graph[v].children += 1 + graph[c].children;
            graph[v].max_depth = max(graph[v].max_depth, graph[c].max_depth);
            graph[v].agents += graph[c].agents;
        }
    }
    graph[v].WROCI = graph[v].children * 2;
    graph[v].KONIEC = graph[v].WROCI - (graph[v].max_depth - graph[v].depth);
    post_order.push_back(v);
}

void dfs_pre(int v, int p){
    graph[v].max_depth = graph[v].depth = graph[p].depth + 1;
    graph[v].parent = p;
    for(auto& c: graph[v])
        if(c != p)
            dfs(c, v);
        
    post_order.push_back(v);
}

void dfs(int v, int p){
    dfs_pre(v, p);
    reverse(post_order.begin(), post_order.end());
    for(auto& v: post_order){
        graph[p].children += 1 + graph[v].children;
        graph[v].agents = int(graph[v].has_agent);
        graph[p].agents += graph[v].agents;
        graph[p].max_depth = max(graph[p].max_depth, graph[v].max_depth);
        graph[v].WROCI = graph[v].children * 2;
        graph[v].KONIEC = graph[v].WROCI - (graph[v].max_depth - graph[v].depth);
        post_order.push_back(v);
    }
}

int find_split_point(int start){
    stack<int> st;
    st.push(start);
    while(!st.empty()){
        int v = st.top(); st.pop();
        for(auto& c: graph[v])
            if(c != graph[v].parent)
                st.push(c);
        
        if(graph[v].size() > 2 || (graph[v].size() > 1 && graph[v].parent == v)){
            for(auto& c: graph[v])
                if(c != graph[v].parent)
                    if(graph[c].agents == 1)
                        return c;
                    
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, a, b;
    cin >> n >> k;

    graph.assign(n + 1, {});
    vector<int> ks;
    for(int i = 0; i < k; ++i){
        cin >> a;
        graph[a].has_agent = true;
        ks.push_back(a);
    }
    for(int i = 0; i < n - 1; ++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vis.assign(n + 1, 0);

    dfs(87344, 87344);
    if(k == 1){
        dfs(ks[0], ks[0]);
        cout << graph[ks[0]].KONIEC << endl;
    } else if(k == 2){
        dfs(ks[0], ks[0]);
        int v = ks[0];
        int split = find_split_point(v);
        for(int i = 0; i < graph[split].size(); ++i){
            if(graph[split][i] == graph[split].parent){
                graph[split].erase(graph[split].begin() + i);
                break;
            }
        }
        for(int i = 0; i < graph[graph[split].parent].size(); ++i){
            if(graph[graph[split].parent][i] == split){
                graph[graph[split].parent].erase(graph[graph[split].parent].begin() + i);
                break;
            }
        }
        vis.assign(n + 1, 0);
        graph[ks[0]].depth = -1;
        graph[ks[0]].children = 0;
        dfs(ks[0], ks[0]);
        graph[ks[1]].depth = -1;
        graph[ks[1]].children = 0;
        dfs(ks[1], ks[1]);
        cout << graph[ks[0]].KONIEC + graph[ks[1]].KONIEC << endl;
    }
    else
        dfs(1, 1);
}