#include <bits/stdc++.h>

using namespace std;

struct conn{
    int target;
    size_t pos_at_target;
    bool alive = true;
};
struct vert: vector<conn> {
    int alive_conns;
};
vector<vert> graph;
set<int> alive_nodes;

void eulerian_path(vector<int>& ans, int start){
    stack<int> st;
    st.push(start);
    while(!st.empty()){
        int v = st.top();
        if(graph[v].alive_conns == 0){
            alive_nodes.erase(v);
            ans.push_back(v);
            st.pop();
            while(!st.empty()){
                v = st.top();
                if(graph[v].alive_conns == 0)
                    alive_nodes.erase(v);
                ans.push_back(v);
                st.pop();
                
            }
        } else {
            for(int i = graph[v].size() - 1; i >= 0; i--){
                if(!graph[v][i].alive)
                    graph[v].erase(graph[v].begin() + i);
                else{
                    st.push(graph[v][i].target);
                    graph[v][i].alive = false;
                    graph[graph[v][i].target][graph[v][i].pos_at_target].alive = false;
                    graph[v].alive_conns--;
                    graph[graph[v][i].target].alive_conns--;
                    break;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, b;
    cin >> n >> m;
    graph.assign(n + 1, {});
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        graph[a].push_back({b, graph[b].size()});
        graph[b].push_back({a, graph[a].size() - 1});
    }
    for(int i = 1; i <= n; ++i){
        alive_nodes.insert(i);
        graph[i].alive_conns = graph[i].size();
    }
    queue<vector<int>> regular_paths;
    set<vector<int>> cycles;
    while(alive_nodes.size() > 0){
        vector<int> ans;
        eulerian_path(ans, *alive_nodes.begin());
        reverse(ans.begin(), ans.end());
        if(ans.front() == ans.back()){
            cycles.insert(ans);
        } else
            regular_paths.push(ans);
    }
    while(regular_paths.size() || cycles.size()){
        if(regular_paths.size()){
            queue<int> now;
            vector<int>& ptr = regular_paths.front();
            for(int i = 0; i < ptr.size(); i++){
                now.push(ptr[i]);
                auto it = find_if(cycles.begin(), cycles.end(), [&](const vector<int> a){ return a[0] == ptr[i]; });
                if(it != cycles.end()){
                    while(it != cycles.end()){
                        auto new_it = it->begin();
                        new_it++;
                        for(; new_it != it->end(); ++new_it)
                            now.push(*new_it);
                        cycles.erase(it);
                        it = find_if(cycles.begin(), cycles.end(), [&](const vector<int> a){ return a[0] == ptr[i]; });
                    }
                }
            }
            regular_paths.pop();
            cout << now.size() << " ";
            while(!now.empty()){
                cout << now.front() << " ";
                now.pop();
            }
            cout << endl;
        }
        else{
            for(auto it = cycles.begin(); it != cycles.end(); ++it){
                cout << it->size() << " ";
                for(auto new_it = it->begin(); new_it != it->end(); ++new_it)
                    cout << *new_it << " ";
                cout << endl;
            }
            cycles.clear();
        }
    }

}