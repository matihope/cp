#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct vert{
    vector<int> conns;
    int in = 0;
};
vector<vert> graph;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, a, b;
    cin >> n >> m;
    graph.assign(n, {});
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        a--, b--;
        graph[a].conns.push_back(b);
        graph[b].in++;
    }
    queue<int> q;
    for(int i = 0; i < n; ++i){
        if(graph[i].in == 0)
            q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        if(q.size() > 1){
            cout << "NIE" << endl;
            return 0;
        }
        int v = q.front(); q.pop();
        topo.push_back(v);
        for(auto c: graph[v].conns)
            if(!--graph[c].in)
                q.push(c);
    }
    if(topo.size() == graph.size()){
        cout << "TAK" << endl;
        for(auto c: topo) cout << c + 1 << " ";
    } else {
        cout << "NIE" << endl;
    }
}