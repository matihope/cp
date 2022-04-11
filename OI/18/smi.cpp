#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef long double LLD;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<pair<int, int>> VPII;

struct edge{
    edge(int x1, int x2) { target = x1; pos_at_target = x2; }
    int target, pos_at_target;
    bool used = false;
};


int v, e;
vector<vector<edge>> graph;
vector<int> degree;

vector<VI> paths;
vector<deque<int>> new_paths;
vector<bool> visited;

void eulerian_path(int start, int entry_deg){
    stack<int> st;
    VI path;
    st.push(start);
    while(!st.empty()){
        int now = st.top();
        
        if(degree[now] == 0){
            path.push_back(now);
            st.pop();
            continue;
        }

        int i = graph[now].size() - 1;
        for(; i >= 0; --i){
            if(graph[now][i].used) graph[now].pop_back();
            else break;
        }

        edge e = graph[now][i];
        graph[now][i].used = true;
        graph[e.target][e.pos_at_target].used = true;
        graph[now].pop_back();
        degree[now]--;
        degree[e.target]--;
        if(visited[e.target]){
            VI new_path;
            new_path.push_back(e.target);
            while(st.top() != e.target) {
                visited[st.top()] = false;
                new_path.push_back(st.top());
                st.pop();
            }
            new_path.push_back(e.target);
            paths.push_back(new_path);
        } else {
            visited[e.target] = true;
            st.push(e.target);
        }
    }
    paths.push_back(path);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, d;
    cin >> v >> e;
    graph.assign((v + 1), vector<edge>());
    visited.assign(v, 0);
    degree.assign(v + 1, 0);
    for(int i = 0; i < e; ++i){
        cin >> a >> b >> c >> d;
        if(c != d){
            graph[a].push_back(edge(b, int(graph[b].size())));
            graph[b].push_back(edge(a, int(graph[a].size()) - 1));
            
            degree[a]++;
            degree[b]++;
        }
    }

    int i = 1;
    while(i < v){
        if(degree[i] % 2 == 1){ cout << "NIE" << endl; return 0; }
        else if (degree[i] == 0) { i++; continue; }
        else {
            eulerian_path(i, degree[i]);
        }
    }

    cout << paths.size() << endl;
    for(auto x: paths){
        cout << x.size() - 1 << " ";
        for(auto l: x)
            cout << l << " ";
        cout << '\n';
    }

    return 0;
}