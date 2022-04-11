#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

struct vert: vector<int> {
    int parent;
    int children = 0;
    long long visit_time = 0;
    long long infected = 0;
    bool has_infected_child = false;
};
vector<vert> graph;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n, a;
        cin >> n;
        graph.assign(n + 1, {});
        vector<int> verts(n);
        verts[0] = 1;
        for(int i = 2; i <= n; ++i){
            cin >> a;
            verts[i - 1] = i;
            graph[a].push_back(i);
            graph[a].children++;
            graph[i].parent = a;
        }
        sort(verts.begin(), verts.end(), [&](const int a, const int b){
            return graph[a].children > graph[b].children;
        });
        int time = 1;
        long long infected_so_far = 1;
        stack<int> prevs;
        prevs.push(-1);
        while(infected_so_far < n){
            for(int i = 0; i < n; ++i){
                bool did_sth = false;
                if(graph[verts[i]].children > 0){
                    int prev = prevs.top();
                    while(prev != -1){
                        if(graph[prev].has_infected_child && graph[prev].infected < graph[prev].children){
                            if(graph[prev].infected + time - graph[prev].visit_time <= graph[prev].children){
                                infected_so_far += time - graph[prev].visit_time;
                                // cout << "Infeted in: " << prev << " : " << time - graph[prev].visit_time << endl;
                            } else {
                                // cout << "Infeted in: " << prev << " : " << graph[prev].children - graph[prev].infected << endl;
                                infected_so_far += graph[prev].children - graph[prev].infected;
                            }
                            graph[prev].infected += time - graph[prev].visit_time;
                            graph[prev].visit_time = time;
                            did_sth = true;
                            break;
                        } else {
                            prevs.pop();
                            prev = prevs.top();
                        }
                    }
                    graph[verts[i]].has_infected_child = true;
                    if(graph[verts[i]].infected < graph[verts[i]].children){
                        graph[verts[i]].infected++;
                        // cout << "Started infection in: " << verts[i] << endl;
                        infected_so_far++;
                        did_sth = true;
                    }
                    if(did_sth)
                        time++;
                    prevs.push(verts[i]);
                }
            }
        }
        cout << time << endl;
    }
}