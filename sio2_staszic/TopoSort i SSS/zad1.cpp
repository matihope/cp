#include <bits/stdc++.h>

using namespace std;

struct vert{
    vector<int> conns;
    int in = 0;
};

vector<vert> graph;
vector<char> state;
vector<bool> visited;

bool check_cycle(int v){
    visited[v] = true;
    state[v] = 1;

    for(auto c: graph[v].conns){
        if(state[c] == 1) return true;
        if(!visited[c]){
            if(check_cycle(c))
                return true;
        }
    }

    state[v] = 2;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, a, b;
    cin >> n >> m;
    graph.assign(n + 1, {});
    visited.assign(n + 1, 0);
    state.assign(n + 1, 0);
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        graph[a].conns.push_back(b);
        graph[b].in++;
    }
    for(int i = 1; i <= n; ++i)
        if(!visited[i])
            if(check_cycle(i)){
                cout << "NIE" << endl;
                return 0;
            }
    cout << "TAK" << endl;
    auto cmp = [&](const int a, const int b){ return a > b; };
    priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
    for(int i = 1; i <= n; ++i){
        if(graph[i].in == 0)
            q.push(i);
    }
    while(!q.empty()){
        int v = q.top(); q.pop();
        cout << v << " ";
        for(auto c: graph[v].conns)
            if(--graph[c].in == 0)
                q.push(c);
    }
}