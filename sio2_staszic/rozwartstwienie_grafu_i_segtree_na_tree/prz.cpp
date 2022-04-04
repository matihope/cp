#include <bits/stdc++.h>

using namespace std;

typedef pair<int64_t, size_t> PII;
vector<int64_t> d;
vector<bool> vis;
vector<vector<PII>> graph;

void dji(){
    priority_queue<PII, vector<PII>, greater<PII>> q;
    d[1] = 0;
    q.emplace(0, 1);
    while(!q.empty()) {
        auto [_, u] = q.top(); q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto [w, v]: graph[u])
            if(d[u] + w < d[v])
                q.emplace(d[v] = d[u] + w, v);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, a, b, c;
    cin >> n;
    graph.assign(n * 2 + 1, {});
    d.assign(2 * n + 1, INT64_MAX);
    vis.assign(2 * n + 1, 0);
    for(int i = 1; i <= n; ++i){
        cin >> a;
        graph[i].emplace_back(a / 2, i + n);
    }
    cin >> m;
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> c;
        graph[a].emplace_back(c, b);
        graph[a + n].emplace_back(c, b + n);
    }
    dji();
    cout << d[n + 1] << endl;
}