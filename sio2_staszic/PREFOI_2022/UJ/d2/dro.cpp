#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

struct vert: vector<int> {
    int parent = -1, depth = -1;
    int children = 0;
    int pre_order_pos = 0;
    long long val = 0;
};
int preorder = 0;
vector<vert> graph;

void dfs(int v, int p){
    graph[v].parent = p;
    graph[v].depth = graph[p].depth + 1;
    graph[v].pre_order_pos = preorder++;
    for(auto& conn: graph[v]){
        if(conn != p){
            dfs(conn, v);
            graph[v].children += 1 + graph[conn].children;
        }
    }
}

void dfs_set(int v, int val){
    graph[v].val += val;
    for(auto& conn: graph[v]){
        if(conn != graph[v].parent){
            dfs_set(conn, val);
        }
    }
}

long long dfs_get(int v){
    if(v == 1)
        return graph[v].val;
    return graph[v].val + dfs_get(graph[v].parent);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int z;
    cin >> z;
    while(z--){
        int n, q, a, b;
        cin >> n >> q;
        graph.assign(n + 1, {});
        for(int i = 1; i < n; ++i){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        preorder = 0;
        dfs(1, 1);
        int op, x, d;
        while(q--){
            cin >> op >> x;
            if(op == 1){
                cin >> d;
                dfs_set(x, d);
            } else {
                cout << dfs_get(x) << endl;
            }
        }
    }
}