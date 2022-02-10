#include <bits/stdc++.h>

using namespace std;
#define INF 1000000000000001LL
    
int n, m;

struct edge{
    int target, value;
};

struct vert{
    vector<edge> conns;
    long long even = INF, odd = INF;
};
vector<vert> graph;
vector<bool> vis;

void dji(int v, int v1){
    typedef tuple<long long, size_t, int> PII; // length, target, num_routes
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.emplace(0, v, 0);

    while(!q.empty()){
        auto [val, x, num_routes] = q.top(); q.pop();
        bool good = false;
        if(vis[x]) continue;

        if(num_routes % 2 == 0 && graph[x].even == INF){  // no shortest paths yet
            graph[x].even = val;
            good = true;
        }  
        else if(num_routes % 2 == 1 && graph[x].odd == INF){  // shortest path exists
            graph[x].odd = val;
            good = true;
        }
        if(graph[x].even != INF && graph[x].odd != INF){
            vis[x] = true;
            if(x == v1) return;
        }

        if(good){
            for(auto [targ, val2]: graph[x].conns){
                if(graph[targ].even == INF || graph[targ].odd ==  INF)
                    q.emplace(val + val2, targ, num_routes + 1);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int a, b, c;
    int z, d;
    graph.assign(n + 1, {});
    vis.assign(n + 1, false);
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> c;
        graph[a].conns.push_back({b, c});
        graph[b].conns.push_back({a, c});
    }
    cin >> z >> d;
    dji(z, d);
    if (graph[d].even != INF)
        cout << graph[d].even << " ";
    else
        cout << -1 << " ";
    if (graph[d].odd != INF)
        cout << graph[d].odd << endl;
    else
        cout << -1 << " ";
}