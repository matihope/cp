#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

struct vert: vector<int> {
    long long adder = 0;
    long long carry = 0;
};
vector<vert> graph;

void dfs(int v, int p){
    graph[v].adder += graph[v].carry + graph[p].adder;
    for(auto& c: graph[v]){
        if(c != p){
            graph[c].carry += graph[v].carry;
            dfs(c, v);
        }
    }
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
        int prev = -1;
        int op, x, d;
        while(q--){
            cin >> op >> x;
            if(op == 1){
                cin >> d;
                graph[x].carry += d;
            } else {
                if(prev == 1)
                    dfs(1, 1);
                cout << graph[x].adder << endl;
            }
            prev = op;
        }
    }
}