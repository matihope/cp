#include <bits/stdc++.h>

using namespace std;

struct vert{
    vector<int> conns;
    bool marked = false;
    int parent = -1;
    int alive_edges = 0;
};

vector<vert> graph;
vector<bool> vis;

void dfs(int v, int p){
    graph[v].parent = p;
    vis[v] = true;
    for(auto c: graph[v].conns){
        if(!vis[c]){
            dfs(c, v);
            graph[v].alive_edges++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, b;
    cin >> n;

    graph.assign(n + 1, {});
    vis.assign(n + 1, false);
    for(int i = 1; i < n; ++i){
        cin >> a >> b;
        graph[a].conns.push_back(b);
        graph[b].conns.push_back(a);
    }
    graph[0].marked = true;
    dfs(1, 0);
    long long count = 1;
    int m;
    cin >> m;
    while(m--){
        cin >> a;
        if(a > 0){
            count += graph[a].alive_edges;
            count -= graph[graph[a].parent].marked;
            graph[a].marked = true;
            graph[graph[a].parent].alive_edges--;
        } else {
            a *= -1;
            count -= graph[a].alive_edges;
            count += graph[graph[a].parent].marked;
            graph[a].marked = false;
            graph[graph[a].parent].alive_edges++;
        }
        cout << count << endl;
    }
}