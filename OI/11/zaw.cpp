#include <bits/stdc++.h>

using namespace std;
#define INF 1000000001
    
int n, m;

struct edge{
    int target, value;
};

struct dist{
    long long value;
    size_t from;
};

struct vert{
    vector<edge> conns, inverted;
    vector<dist> dists;
};
vector<vert> graph;
vector<bool> vis;

void dji(int v){
    priority_queue<tuple<long long, int, size_t>> q;

    // create initial q with leaving vertexes as parents
    for(int i = 0; i < graph[v].conns.size(); i++)
        q.push({INF - graph[v].inverted[i].value, graph[v].inverted[i].target, graph[v].inverted[i].target});

    while(!q.empty()){
        auto [val, x, parent] = q.top(); q.pop();
        val = INF - val;
        bool good = false;
        if(vis[x]) continue;

        if(graph[x].dists.size() == 0){  // no shortest paths yet
            graph[x].dists.push_back({val, parent});
            good = true;
        }  
        else if(graph[x].dists.size() == 1){  // shortest path exists
            if(graph[x].dists[0].from != parent){  // if found shortest path coming from different parent
                graph[x].dists.push_back({val, parent});
                vis[x] = good = true;
            }
        }        

        if(good){
            for(auto [targ, val2]: graph[x].inverted){
                if(targ == 1) continue;
                if(graph[targ].dists.size() < 2)
                    q.push({INF - (val + val2), targ, parent});
            }
        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int a, b, c, d;
    graph.assign(n + 1, {});
    vis.assign(n + 1, false);
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> c >> d;
        graph[a].conns.push_back({b, c});
        graph[a].inverted.push_back({b, d});
        graph[b].conns.push_back({a, d});
        graph[b].inverted.push_back({a, c});
    }
    dji(1);
    long long min_len = INF;
    for(auto& conn: graph[1].conns){
        vert v = graph[conn.target];
        if(v.dists[0].from != conn.target)
            min_len = min(min_len, conn.value + v.dists[0].value);
        if(v.dists[1].from != conn.target)
            min_len = min(min_len, conn.value + v.dists[1].value);
    }
    cout << min_len << endl;
}