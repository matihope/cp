#include <bits/stdc++.h>

using namespace std;

struct conn{
    int target;
    bool extra = false;
};

struct vert: vector<conn> {
    int in = 0, out = 0;
    int alive = 0;
};
vector<vert> graph;

void euler(int start, vector<int>& ans){
    ans.push_back(start);
    for(int i = graph[start].size() - 1; i >= 0; i--){
        conn x = graph[start].back();
        graph[start].pop_back();
        if(graph[start][i].extra)
            ans.push_back(start);
        euler(graph[start][i].target, ans);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin >> n;

    graph.assign(1001, {});

    for(int i = 0; i < n; ++i){
        cin >> a >> b;
        graph[a].push_back({b});
        graph[a].alive++;
        graph[a].out++;
        graph[b].in++;
    }
    queue<pair<int, int>> more_ins, more_outs;
    for(int i = 1; i <= n; i++){
        if(graph[i].in - graph[i].out < 0){
            more_outs.push({i, abs(graph[i].in - graph[i].out)});
        } else if (graph[i].in - graph[i].out > 0){
            more_ins.push({i, abs(graph[i].in - graph[i].out)});
        }
    }
    while(more_ins.size() > 1 || more_ins.front().second > 1){
        int v1 = more_ins.front().first;
        if(--more_ins.front().second == 0)
            more_ins.pop();
        int v2 = more_outs.front().first;
        if(--more_outs.front().second == 0)
            more_outs.pop();
        graph[v1].push_back({v2, true});
    }
    vector<int> ans;
    if(more_ins.size() == 0)
        euler(1, ans);
    else 
        euler(more_ins.front().first, ans);
    cout << ans.size() << endl;
}