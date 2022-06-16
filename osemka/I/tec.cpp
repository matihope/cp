#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

vector<int> rep;
vector<int> forest_size;
vector<vector<int>> up;

int Find(int a){
    if(rep[a] == a)
        return a;
    return rep[a] = Find(rep[a]);
}

void Union(int a, int b){
    if(forest_size[Find(a)] < forest_size[Find(b)])
        swap(a, b);

    forest_size[Find(a)] += forest_size[Find(b)];
    rep[Find(b)] = Find(a);
}

struct edge {
    int target, color;
};

struct vert : vector<edge> {
    int tab[5]{};
    int parent = -1;
    int depth = 0;
};

vector<vert> graph;
int n, L;

void dfs(int v, int p, int c_color) {
    // initial setup for every vertex
    graph[v].parent = p;
    graph[v].depth = graph[p].depth + 1;

    // calculate values for binary lifting
    up[v][0] = p;
    for(int i = 1; i <= L; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];

    // update color values
    for(int i = 0; i < 5; ++i){
        graph[v].tab[i] = graph[p].tab[i];
        if(i + 1 == c_color)
            graph[v].tab[i]++;
    }

    // perform dfs
    for(auto& c: graph[v]) {
        if(c.target != p){
            dfs(c.target, v, c.color);
        }
    }
}

int lca(int a, int b) {
    // make sure a has larger depth
    if(graph[a].depth < graph[b].depth)
        swap(a, b);


    // 1. get to the same depth
    int d = graph[a].depth - graph[b].depth;
    int count = 0;
    while(d){
        if(d & 1)
            a = up[a][count];
        d /= 2;
        count++;
    }


    // 2. find lca
    if(a == b)
        return a;

    for(int i = L; i >= 0; i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

vector<int> find_path(int x, int y) {
    vector<int> ans(5, 0);

    if(Find(x) == Find(y)){
        // find lca
        int l = lca(x, y);

        // calculate path values
        for(int i = 0; i < 5; i++) {
            ans[i] += graph[x].tab[i] + graph[y].tab[i];
            ans[i] -= 2 * graph[l].tab[i];
        }
    }


    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    char op;
    int q, x, y, k;
    cin >> n >> q;
    graph.assign(n + 1, {});
    rep.assign(n + 1, 0);
    forest_size.assign(n + 1, 1);

    for(int i = 1; i <= n; ++i)
        rep[i] = i;

    L = ceil(log2(n));
    up.assign(n + 1, vector<int>(L + 1, 0));
    for(int i = 1; i <= n; ++i)
        dfs(i, i, 0);

    while(q--){
        cin >> op >> x >> y;
        if(op == 'S'){
            vector<int> ans = find_path(x, y);
            for(const auto& i: ans)
                cout << i << ' ';
            cout << '\n';
        } else {
            cin >> k;
            graph[x].push_back({y, k});
            graph[y].push_back({x, k});

            if(forest_size[Find(x)] > forest_size[Find(y)])
                dfs(y, x, k);
            else
                dfs(x, y, k);

            Union(x, y);
        }
    }
}
