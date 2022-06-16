#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

struct edge {
    int target, color;
};

struct vert : vector<edge> {
    int tab[5]{};
};

vector<vert> graph;
int n;

void find_path(int x, int y) {
    stack<int> st;
    st.push(x);
    for(int i = 0; i < 5; ++i)
        graph[x].tab[i] = graph[y].tab[i] = 0;
    if(x == y)
        return;

    vector<bool> vis(n + 1, 0);
    while(!st.empty()){
        int v = st.top(); st.pop();
        for(auto& c: graph[v]){
            if(!vis[c.target]) {
                vis[c.target] = true;
                for(int i = 0; i < 5; ++i){
                    graph[c.target].tab[i] = graph[v].tab[i];
                    if(c.color == i + 1)
                        graph[c.target].tab[i]++;
                }
                if(c.target == y)
                    return;
                st.push(c.target);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char op;
    int q, x, y, k;
    cin >> n >> q;
    graph.assign(n + 1, {});
    while(q--){
        cin >> op >> x >> y;
        if(op == 'S'){
            int tab[5]{};
            find_path(x, y);
            for(int i = 0; i < 5; ++i)
                cout << graph[y].tab[i] << ' ';
            cout << '\n';
        } else {
            cin >> k;
            graph[x].push_back({y, k});
            graph[y].push_back({x, k});
        }
    }
}
