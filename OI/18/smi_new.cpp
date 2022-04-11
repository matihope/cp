#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

typedef vector<int> VI;

struct edge{
    int targ;
    size_t pos;
    bool alive = true;
};

vector<vector<edge>> graph;

VI degree;
vector<VI> paths;
void gen_paths(int vert){
    VI curr_path;
    stack<int> st;
    st.push(vert);
    vector<bool> vis(graph.size(), 0);
    while(!st.empty()){
        int t = st.top();
        if(degree[t] == 0){
            st.pop();
            curr_path.push_back(t);
            continue;
        }

        int i = graph[t].size();
        while(!graph[t][i-- - 1].alive)  // xd
            graph[t].pop_back();

        edge& e = graph[t][i];
        if(vis[e.targ]){
            VI new_path = { e.targ };
            while(vis[e.targ]){
                new_path.push_back(st.top());
                vis[st.top()] = false;
                st.pop();
            }
            paths.push_back(new_path);
        }
        
        graph[e.targ][e.pos].alive = false;
        degree[t]--;
        degree[e.targ]--;
        st.push(e.targ);
        vis[e.targ] = true;
        graph[t].pop_back();
    }
    paths.push_back(curr_path);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, a, b, c, d;
    cin >> n >> m;
    graph.assign(n + 1, {});
    degree.assign(n + 1, 0);
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> c >> d;
        if(c != d){
            degree[a]++;
            degree[b]++;
            graph[a].push_back({b, graph[b].size()});
            graph[b].push_back({a, graph[a].size() - 1});
        }
    }

    for(int i = 1; i <= n; ++i){
        if(degree[i] % 2){
            cout << "NIE" << endl;
            return 0;
        }

        if(degree[i])
            gen_paths(i);

    }

    cout << paths.size() << endl;
    for(auto& path : paths){
        cout << path.size() - 1 << ' ';
        for(auto& i: path)
            cout << i << ' ';
        cout << '\n';
    }
}