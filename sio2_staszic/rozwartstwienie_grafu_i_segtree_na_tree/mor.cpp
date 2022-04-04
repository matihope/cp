#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;

void bfs(int v, vector<long long>& dist, vector<bool>& vis){
    queue<int> s;
    s.push(v);
    dist[v] = 0;
    vis[v] = true;
    while(!s.empty()){
        int v = s.front(); s.pop();
        for(auto c: graph[v]){
            if(!vis[c]){
                s.push(c);
                vis[c] = true;
                dist[c] = dist[v] + 1;
            }
        }
    }
}

int main(){
    #ifndef LOCAL_H
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #endif

    int n, m, k, a, b, c;
    cin >> n >> m >> k;
    graph.assign(n * 2 + 1, {});
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        graph[a].push_back(n + b);
        graph[n + b].push_back(a);

        graph[n + a].push_back(b);
        graph[b].push_back(n + a);
    }
    vector<int> start_v;
    vector<tuple<int, int, int, int>> queries;
    vector<bool> added(n + 1, 0);
    for(int i = 0; i < k; ++i){
        cin >> a >> b >> c;
        queries.push_back({a, b, c, i});
        if(!added[a]){
            start_v.push_back(a);
            added[a] = true;
        }
    }

    sort(start_v.begin(), start_v.end());
    sort(queries.begin(), queries.end());
    int query_pos = 0;
    vector<pair<int, string>> anss;
    for(size_t i = 0; i < start_v.size(); i++) {
        vector<bool> vis(n * 2 + 1, false);
        vector<long long> dists(n * 2 + 1, __LONG_LONG_MAX__);
        bfs(start_v[i], dists, vis);
        while(get<0>(queries[query_pos]) == start_v[i]){
            auto [a, b, c, index] = queries[query_pos];
            string ans;
            if(graph[a].size() == 0){
                ans = "NIE";
            } else {
                if(c % 2 == 0){
                    // parzyste polaczenie
                    if(dists[b] <= c)
                        ans = "TAK";
                    else
                        ans = "NIE";
                } else{
                    // nieparzyste polaczenie
                    if(dists[b + n] <= c)
                        ans = "TAK";
                    else
                        ans = "NIE";
                }
            }
            anss.emplace_back(index, ans);
            query_pos++;
        }
    }
    sort(anss.begin(), anss.end());
    for(auto& ac: anss) cout << ac.second << endl;
}