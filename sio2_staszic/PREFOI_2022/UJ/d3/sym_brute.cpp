#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

struct vert: vector<int> {
    int parent;
    char letter;
    set<string> children;
    int ans = 0;
};
vector<vert> graph;

void dfs(int v, int p){
    graph[v].parent = p;
    graph[v].children.insert({graph[v].letter});
    for(auto& c: graph[v]){
        if(c != p){
            dfs(c, v);
            for(auto it = graph[c].children.begin(); it != graph[c].children.end(); ++it){
                graph[v].children.insert(graph[v].letter + (*it));
            }
            graph[c].children.clear();
        }
    }
    graph[v].ans = graph[v].children.size();
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int z;
    cin >> z;
    while(z--){ 
        int n, a, b;
        cin >> n;
        char c;
        graph.assign(n + 1, {});
        for(int i = 1; i <= n; ++i)
            cin >> graph[i].letter;
        for(int i = 1; i < n; ++i){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs(1, 1);
        for(int i = 1; i <= n; ++i){
            cout << graph[i].ans << ' ';
        }
        cout << '\n';
    }
}