#include <iostream>
#include <vector>

using namespace std;

struct vert: vector<int>{
    int parent;
    int depth = -1;
    int children = 0;
    int max_depth = 0;
    int WROCI = 0;
    int KONIEC = 0;
    bool has_agent = false;
};
vector<vert> graph;

void dfs(int v, int p){
    graph[v].max_depth = graph[v].depth = graph[p].depth + 1;
    graph[v].parent = p;
    for(auto& c: graph[v]){
        if(c != p){
            dfs(c, v);
            graph[v].children += 1 + graph[c].children;
            graph[v].max_depth = max(graph[v].max_depth, graph[c].max_depth);
        }
    }
    graph[v].WROCI = graph[v].children * 2;
    graph[v].KONIEC = graph[v].WROCI - graph[v].max_depth;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, a, b;
    cin >> n >> k;

    graph.assign(n + 1, {});
    for(int i = 0; i < k; ++i){
        cin >> a;
        graph[a].has_agent = true;
    }
    for(int i = 1; i < n; ++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 1);
    cout << "H";
}