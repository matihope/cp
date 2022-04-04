#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int MOD = 1e9 + 9;

struct vert{
    vector<int> conns;
    int in = 0;
    int count = 0;
};
vector<vert> graph;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, A, B, x, y;
    cin >> n >> m >> A >> B;
    graph.assign(n, {});
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        graph[x - 1].conns.emplace_back(y - 1);
        graph[y - 1].in++;
    }

    queue<int> q;
    for(int i = 0; i < n; ++i)
        if(graph[i].in == 0)
            q.push(i);
    
    graph[A - 1].count = 1;
    while(!q.empty()){
        int v = q.front(); q.pop();

        for(int c: graph[v].conns)
            graph[c].count = (graph[c].count + graph[v].count % MOD) % MOD;

        for(auto c: graph[v].conns)
            if(--graph[c].in == 0)
                q.push(c);
    }
    cout << graph[B - 1].count << endl;
}